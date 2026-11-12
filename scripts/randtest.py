#!/usr/bin/env python3
"""Random testing: compare a solution with a naive one on generated inputs.

    randtest -m main.cpp -n naive.cpp -g gen.cpp [options]
    randtest main.cpp naive.cpp gen.cpp [options]

The generator is called as ``gen <seed>`` and must write one input to stdout.
"""

import argparse
import difflib
import hashlib
import json
import math
import os
import re
import resource
import shlex
import shutil
import subprocess
import sys
import time
from pathlib import Path


LIBRARY_ROOT = Path(__file__).resolve().parents[1]
CPP_SUFFIXES = {".cpp", ".cc", ".cxx"}
BUILD_DIR = Path(".randtest") / "build"
CASE_DIR = Path(".randtest") / "case"  # files passed to the checker
SHOW_LIMIT = 2000  # bytes of input/output printed on failure
CONFIG_FILE = "randtest.json"
ROLES = ("main", "naive", "gen")

GEN_TEMPLATE = """\
#include "template/template.cpp"
#include "random/gen/all.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);  // argv[1] is the seed
    int n = rng.size(1, 9);  // small inputs give counterexamples that are easy to trace
    auto a = random_vector(rng, n, 1, 11);  // each value in [1, 11)
    print(n);
    print(a);
}
"""

CHECKER_TEMPLATE = """\
// randtest checker, called as: check <input> <output of MAIN> <output of NAIVE>
// The third file is empty when NAIVE is not given.
// Exit status: 0 = accepted, 1 = wrong answer (print the reason to stdout).
// This sample checks "print the 1-indexed position of a maximum of a".
#include "template/template.cpp"

ifstream input_file, output_file, answer_file;

[[noreturn]] void wrong(const string &reason) {
    cout << reason << '\\n';
    exit(1);
}

// Read one value of the output of MAIN; rejects missing or malformed tokens.
template <class T> T read_output() {
    T x;
    if(!(output_file >> x)) wrong("cannot read the output");
    return x;
}

int main(int argc, char **argv) {
    if(argc != 4) {
        cerr << "usage: " << argv[0] << " <input> <output> <answer>\\n";
        return 3;
    }
    input_file.open(argv[1]);
    output_file.open(argv[2]);
    answer_file.open(argv[3]);

    // 1. read the input
    int n;
    input_file >> n;
    vector<ll> a(n);
    for(auto &x : a) input_file >> x;

    // 2. read and validate the output of MAIN
    int k = read_output<int>();
    if(k < 1 || k > n) wrong("index out of range: " + to_string(k));

    // 3. check optimality; the answer of NAIVE (if any) can be used here
    ll best = *max_element(a.begin(), a.end());
    int expected;
    if(answer_file >> expected) {
        if(a[expected - 1] != best) {
            cerr << "the naive answer is not a maximum\\n";
            return 3;
        }
    }
    if(a[k - 1] != best) {
        wrong("a[" + to_string(k) + "] = " + to_string(a[k - 1]) +
              " is not the maximum " + to_string(best));
    }

    // 4. reject extra output
    string extra;
    if(output_file >> extra) wrong("extra output: " + extra);
}
"""


class Abort(Exception):
    """A setup error (compile error, broken generator, ...)."""


# ---------------------------------------------------------------- build

def read_depfile(path):
    """Return the prerequisites listed in a Makefile-style .d file."""
    text = path.read_text().replace("\\\n", " ")
    _, _, deps = text.partition(": ")
    result, current = [], ""
    i = 0
    while i < len(deps):
        c = deps[i]
        if c == "\\" and i + 1 < len(deps) and deps[i + 1] == " ":
            current += " "
            i += 2
            continue
        if c.isspace():
            if current:
                result.append(current)
            current = ""
        else:
            current += c
        i += 1
    if current:
        result.append(current)
    return [Path(p) for p in result]


def is_up_to_date(binary, depfile):
    if not binary.exists() or not depfile.exists():
        return False
    built = binary.stat().st_mtime
    try:
        return all(dep.stat().st_mtime <= built for dep in read_depfile(depfile))
    except OSError:
        return False


def prepare(source, args):
    """Return the command that runs ``source``, compiling it if needed."""
    path = Path(source)
    if not path.exists():
        raise Abort(f"{source}: no such file")
    suffix = path.suffix.lower()
    if suffix == ".py":
        return [sys.executable, str(path)]
    if suffix not in CPP_SUFFIXES:
        return [str(path.resolve())]

    if shutil.which(args.cxx) is None:
        raise Abort(f"compiler not found: {args.cxx}")
    flags = [*shlex.split(args.cxxflags), "-I", str(LIBRARY_ROOT)]
    for include in args.include:
        flags += ["-I", include]
    key = hashlib.sha256(
        "\0".join([str(path.resolve()), args.cxx, *flags]).encode()
    ).hexdigest()[:12]
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    binary = (BUILD_DIR / f"{path.stem}-{key}").resolve()
    depfile = binary.with_suffix(".d")
    if not is_up_to_date(binary, depfile):
        print(f"compiling {source} ...", file=sys.stderr, flush=True)
        result = subprocess.run(
            [args.cxx, *flags, "-MD", "-MF", str(depfile),
             str(path), "-o", str(binary)],
            stderr=subprocess.PIPE, text=True,
        )
        if result.returncode != 0:
            raise Abort(f"failed to compile {source}\n{result.stderr}")
    return [str(binary)]


# ---------------------------------------------------------------- run

def raise_stack_limit():
    soft, hard = resource.getrlimit(resource.RLIMIT_STACK)
    if soft != hard:
        try:
            resource.setrlimit(resource.RLIMIT_STACK, (hard, hard))
        except (ValueError, OSError):
            pass


class Result:
    def __init__(self, stdout=b"", stderr=b"", returncode=0, timed_out=False):
        self.stdout = stdout
        self.stderr = stderr
        self.returncode = returncode
        self.timed_out = timed_out

    @property
    def ok(self):
        return not self.timed_out and self.returncode == 0

    def status(self, timeout):
        if self.timed_out:
            return f"TLE (> {timeout}s)"
        if self.returncode < 0:
            return f"RE (signal {-self.returncode})"
        if self.returncode != 0:
            return f"RE (exit code {self.returncode})"
        return "OK"


def run(command, stdin, timeout):
    try:
        p = subprocess.run(
            command, input=stdin, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
            timeout=timeout, preexec_fn=raise_stack_limit,
        )
    except subprocess.TimeoutExpired as e:
        return Result(e.stdout or b"", e.stderr or b"", timed_out=True)
    return Result(p.stdout, p.stderr, p.returncode)


INTEGER = re.compile(rb"[+-]?[0-9]+\Z")


def tokens_match(x, y, eps):
    """Compare two tokens; with eps, real numbers may differ by eps.

    The error is accepted when it is at most eps either absolutely or relative
    to y (the naive answer). Two integer tokens must be equal."""
    if x == y:
        return True
    if eps is None or (INTEGER.match(x) and INTEGER.match(y)):
        return False
    try:
        a, b = float(x), float(y)
    except ValueError:
        return False
    if not (math.isfinite(a) and math.isfinite(b)):
        return a == b
    diff = abs(a - b)
    return diff <= eps or diff <= eps * abs(b)


def first_mismatch(main_out, naive_out, args):
    """Return None if the outputs match, otherwise a description."""
    if args.exact:
        return None if main_out == naive_out else "outputs differ byte by byte"
    a, b = main_out.split(), naive_out.split()
    for i, (x, y) in enumerate(zip(a, b)):
        if not tokens_match(x, y, args.float):
            return (f"token {i + 1}: main {x.decode(errors='replace')!r}, "
                    f"naive {y.decode(errors='replace')!r}")
    if len(a) != len(b):
        return f"main printed {len(a)} tokens, naive printed {len(b)}"
    return None


def checker_status(result, timeout):
    if result.ok:
        return "accepted"
    if result.timed_out:
        return f"TLE (> {timeout}s)"
    if result.returncode < 0:
        return f"crashed (signal {-result.returncode})"
    return f"rejected (exit code {result.returncode})"


class Case:
    """One input with the results of running every program on it."""

    def __init__(self, seed, stdin, main, naive, checker, mismatch):
        self.seed = seed
        self.stdin = stdin
        self.main = main          # Result
        self.naive = naive        # Result, or None without NAIVE
        self.checker = checker    # Result, or None without CHECKER
        self.mismatch = mismatch  # description of differing outputs, or None

    @property
    def runs_ok(self):
        return self.main.ok and (self.naive is None or self.naive.ok)

    @property
    def passed(self):
        if not self.runs_ok:
            return False
        if self.checker is not None:
            return self.checker.ok
        return self.mismatch is None


def evaluate(seed, args, programs):
    stdin = generate(programs["gen"], seed, args.timeout)
    main = run(programs["main"], stdin, args.timeout)
    naive = run(programs["naive"], stdin, args.timeout) if programs["naive"] else None
    checker = mismatch = None
    if main.ok and (naive is None or naive.ok):
        if programs["checker"]:
            CASE_DIR.mkdir(parents=True, exist_ok=True)
            files = []
            for name, data in (("in.txt", stdin), ("out.txt", main.stdout),
                               ("ans.txt", naive.stdout if naive else b"")):
                path = (CASE_DIR / name).resolve()
                path.write_bytes(data)
                files.append(str(path))
            checker = run([*programs["checker"], *files], b"", args.timeout)
        else:
            mismatch = first_mismatch(main.stdout, naive.stdout, args)
    return Case(seed, stdin, main, naive, checker, mismatch)


def generate(gen, seed, timeout):
    result = run([*gen, str(seed)], b"", timeout)
    if not result.ok:
        raise Abort((
            f"generator failed for seed {seed}: {result.status(timeout)}\n"
            + result.stderr.decode(errors="replace")
        ).rstrip())
    return result.stdout


# ---------------------------------------------------------------- report

def show(label, data, saved=None):
    text = data.decode(errors="replace")
    if len(data) > SHOW_LIMIT:
        text = text[:SHOW_LIMIT] + "\n... (truncated"
        text += f", full text in {saved})" if saved else ")"
    print(f"--- {label} ---")
    if not data:
        print("(empty)")
        return
    print(text, end="" if text.endswith("\n") else "\n")


def show_diff(main_out, naive_out):
    a = main_out.decode(errors="replace").splitlines()
    b = naive_out.decode(errors="replace").splitlines()
    diff = list(difflib.unified_diff(b, a, "naive", "main", lineterm="", n=1))
    print("--- diff (naive -> main) ---")
    for line in diff[:40]:
        print(line)
    if len(diff) > 40:
        print("... (truncated)")


def roles_of(case):
    return [("main", case.main)] + ([("naive", case.naive)] if case.naive else [])


def show_verdict(case, args, out_dir=None):
    """Print why the case passed or failed (the statuses are printed before)."""
    if not case.runs_ok:
        return
    if case.checker is not None:
        print(f"checker: {checker_status(case.checker, args.timeout)}")
        message = case.checker.stdout + case.checker.stderr
        if message:
            show("checker message", message, out_dir / "checker.log" if out_dir else None)
    elif case.mismatch is None:
        print("outputs match")
    else:
        print(f"first difference: {case.mismatch}")
        show_diff(case.main.stdout, case.naive.stdout)


def save_case(out_dir, args, case):
    out_dir.mkdir(parents=True, exist_ok=True)
    for name in ("in.txt", "out_main.txt", "out_naive.txt", "stderr_main.log",
                 "stderr_naive.log", "checker.log", "err_main.txt", "err_naive.txt",
                 "info.txt"):
        (out_dir / name).unlink(missing_ok=True)
    (out_dir / "in.txt").write_bytes(case.stdin)
    for role, result in roles_of(case):
        (out_dir / f"out_{role}.txt").write_bytes(result.stdout)
        (out_dir / f"stderr_{role}.log").write_bytes(result.stderr)
    info = [f"seed: {case.seed}", f"main: {args.main} {case.main.status(args.timeout)}"]
    if case.naive:
        info.append(f"naive: {args.naive} {case.naive.status(args.timeout)}")
    if case.checker is not None:
        (out_dir / "checker.log").write_bytes(case.checker.stdout + case.checker.stderr)
        info.append(f"checker: {args.checker} {checker_status(case.checker, args.timeout)}")
    elif case.mismatch:
        info.append(f"first difference: {case.mismatch}")
    info.append(f"replay: {replay_command(args, case.seed)}")
    (out_dir / "info.txt").write_text("\n".join(info) + "\n")


def replay_command(args, seed):
    words = ["randtest", "-m", args.main]
    if args.naive:
        words += ["-n", args.naive]
    words += ["-g", args.gen]
    if args.checker:
        words += ["--checker", args.checker]
    if args.float is not None:
        words += ["--float", repr(args.float)]
    if args.exact:
        words.append("--exact")
    return " ".join(shlex.quote(w) for w in words) + f" --replay {seed}"


def print_saved(out_dir, case):
    logs = [f"stderr_{role}.log" for role, _ in roles_of(case)]
    if case.checker is not None:
        logs.append("checker.log")
    print(f"saved to {out_dir}/ (logs: {', '.join(logs)})")


def report(args, case):
    out_dir = Path(args.out)
    save_case(out_dir, args, case)
    print(f"\nfound a counterexample (seed {case.seed})")
    show("input", case.stdin, out_dir / "in.txt")
    for role, result in roles_of(case):
        print(f"{role}: {result.status(args.timeout)}")
    if case.checker is not None and case.runs_ok:
        show("output of main", case.main.stdout, out_dir / "out_main.txt")
    show_verdict(case, args, out_dir)
    print_saved(out_dir, case)
    print(f"replay with --replay {case.seed}")


# ---------------------------------------------------------------- main

HELP = {
    "en": {
        "usage_prefix": "usage: ",
        "usage": "%(prog)s -m MAIN -n NAIVE -g GEN [options]\n"
                 "       %(prog)s MAIN NAIVE GEN [options]\n"
                 "       %(prog)s -m MAIN -g GEN --checker CHECKER [-n NAIVE] [options]\n"
                 "       %(prog)s --init [PATH]",
        "description": """\
Random testing: run a solution and a naive solution on many generated
inputs and stop at the first input (a counterexample) where they disagree.

For each seed S = START, START+1, ..., randtest
  1. runs `GEN S` and takes its stdout as the input,
  2. feeds the input to MAIN and NAIVE,
  3. compares their outputs token by token (whitespace is ignored), with
     an error tolerance (--float), or judges MAIN with a checker (--checker).
A different output (or rejection by the checker), a runtime error
(non-zero exit status) or a timeout of a program is reported as a
counterexample.""",
        "epilog": """\
specifying files:
  The three files can be given with -m, -n and -g in any order.
  Positional FILEs fill the roles not given by options, in the order
  MAIN, NAIVE, GEN. The following commands are equivalent:
    randtest -m main.cpp -n naive.cpp -g gen.cpp
    randtest -g gen.cpp -m main.cpp -n naive.cpp
    randtest main.cpp naive.cpp gen.cpp

  How each file is run:
    .cpp .cc .cxx  compiled with CXX CXXFLAGS -I <library root> and cached
                   in ./.randtest/build/ (rebuilt only when the source or
                   an included header has changed)
    .py            run with the Python interpreter that runs randtest
    others         executed as they are (e.g. ./a.out)

comparison:
  By default the outputs are split at whitespace and the tokens must be
  equal. --exact compares the bytes instead.
  --float EPS accepts two real-number tokens x (MAIN) and y (NAIVE) when
    |x - y| <= EPS  or  |x - y| <= EPS * |y|.
  Tokens that are both integers (e.g. 1000000 and 1000001) must still be
  equal, and other tokens such as words must match exactly.
  --checker CHECKER runs, for every input,
    CHECKER <input file> <output of MAIN> <output of NAIVE>
  (the argument order of testlib checkers). Exit status 0 accepts the
  output, and any other status, a crash or a timeout rejects it. Without
  NAIVE the third file is empty. Use it for problems with several correct
  answers. The checker's stdout and stderr are printed as the reason and
  saved to checker.log. With --checker, NAIVE is optional; when FILEs are
  one fewer than the roles left, they fill MAIN and GEN.
  `randtest --init --checker check.cpp` writes a checker template with
  the generator template (also when "checker" is in randtest.json).
  --exact, --float and --checker cannot be combined.

generator:
  GEN is called as `GEN <seed>` and must print one input to stdout.
  The same seed must always give the same input. With this library:
    #include "random/gen/all.hpp"
    Random rng(argc, argv);  // reads argv[1] as the seed
  Ranges are half-open [l, r) and vertices are 0-indexed.
  Small inputs (e.g. N <= 8) give counterexamples that are easy to trace.
  `randtest --init` writes a template to gen.cpp.

counterexample:
  The first counterexample is printed with the input, the results and
  the diff of the outputs, and saved to OUT (randtest_fail/):
    in.txt                            the input
    out_main.txt out_naive.txt        the outputs
    stderr_main.log stderr_naive.log  stderr (always written, maybe empty)
    checker.log                       output of CHECKER (with --checker)
    info.txt                          the seed, the results and a replay
                                      command
  Stderr is not printed nor compared, so debug output is fine; read it
  in the .log files. --replay SEED runs only that seed, shows the input
  and both outputs, and saves the same files to OUT.
  Seeds start from 0 on every run, so rerunning after a fix checks the
  same inputs again. Use --start to try other seeds.

exit status:
  0    all cases passed (or only --init was run)
  1    a counterexample was found (--replay: the outputs differ)
  2    setup error: invalid arguments, compile error, generator failure
  130  interrupted with Ctrl-C

examples:
  randtest --init
      write a generator template to gen.cpp
  randtest --init --checker check.cpp
      also write a checker template to check.cpp
  randtest -m main.cpp -n naive.cpp -g gen.cpp
      try seeds 0..999
  randtest -m main.cpp -n naive.py -g gen.cpp -c 0 --time 60
      search for 60 seconds with a naive solution in Python
  randtest -m main.cpp -n naive.cpp -g gen.cpp --replay 42
      show the input and outputs for seed 42
  randtest -m main.cpp -n naive.cpp -g gen.cpp \\
           --cxxflags "-std=c++17 -O2 -g -fsanitize=address,undefined"
      also report out-of-range accesses as runtime errors
  randtest -m main.cpp -n naive.cpp -g gen.cpp --float 1e-6
      accept an absolute or relative error of at most 1e-6
  randtest -m main.cpp -n naive.cpp -g gen.cpp --checker check.cpp
      judge with check.cpp, which can read the naive answer

settings file:
  If ./randtest.json exists, its values are used as the defaults of the
  options. Options on the command line take precedence over it, and so do
  positional FILEs over "main", "naive" and "gen". -I directories are
  added to "include". All keys are optional:
    "main", "naive", "gen"     files (strings)
    "count", "start"           integers
    "time", "timeout"          seconds ("time": 0 or null for no limit)
    "exact"                    true or false (--no-exact turns it off)
    "float"                    a number or null
    "checker"                  a file (string)
    "out", "cxx", "cxxflags"   strings
    "include"                  list of directories
  Unknown keys and values of a wrong type are errors. Example:
    {
      "main": "main.cpp", "naive": "naive.cpp", "gen": "gen.cpp",
      "count": 5000, "timeout": 5,
      "cxxflags": "-std=c++17 -O2 -g -fsanitize=address,undefined"
    }
  With this file, `randtest` alone runs the test. `randtest --init` only
  writes the template and does not use the files in the settings.

help language:
  -h follows RANDTEST_LANG (ja or en), and otherwise the locale
  (LANGUAGE, LC_ALL, LC_MESSAGES, LANG). --help-ja and --help-en
  always show the Japanese and English help.""",
        "groups": {
            "files": "files",
            "run": "running",
            "compare": "comparison and output",
            "build": "compilation",
            "other": "others",
        },
        "args": {
            "files": "MAIN, NAIVE and GEN for the roles not given by options",
            "main": "solution to test",
            "naive": "trusted (slow) solution to compare with",
            "gen": "generator, called as `GEN <seed>`",
            "count": "number of cases, 0 for unlimited (default: 1000)",
            "start": "first seed (default: 0)",
            "time": "stop after SEC seconds, 0 for no limit\n(default: no limit)",
            "timeout": "time limit of each run of GEN, MAIN and NAIVE\n(default: 2)",
            "replay": "run only SEED, show the input and outputs and\nsave them with stderr to OUT",
            "exact": "compare outputs byte by byte instead of token by token",
            "no_exact": "compare token by token (overrides \"exact\": true)",
            "float": "accept real numbers with an absolute or relative\nerror of at most EPS",
            "checker": "judge the output of MAIN with CHECKER instead of\ncomparing; NAIVE becomes optional",
            "out": "directory to save a counterexample\n(default: randtest_fail)",
            "cxx": "C++ compiler (default: g++)",
            "cxxflags": "compiler flags, replacing the default\n(default: \"-std=c++17 -O2\")",
            "include": "additional include directory (repeatable)",
            "init": "write a generator template to PATH (default: gen.cpp),\n"
                    "and a checker template too with --checker CHECKER;\n"
                    "run the test as well if all files are given",
            "help": "show the help in the language of the environment",
            "help_ja": "show the help in Japanese",
            "help_en": "show the help in English",
        },
    },
    "ja": {
        "usage_prefix": "使い方: ",
        "usage": "%(prog)s -m MAIN -n NAIVE -g GEN [オプション]\n"
                 "       %(prog)s MAIN NAIVE GEN [オプション]\n"
                 "       %(prog)s -m MAIN -g GEN --checker CHECKER [-n NAIVE] [オプション]\n"
                 "       %(prog)s --init [PATH]",
        "description": """\
ランダムテスト: 提出する解 (MAIN) と愚直解 (NAIVE) に、生成器 (GEN) が
作った入力を次々に与え、結果が食い違う入力 (反例) を探します。

seed S = START, START+1, ... の順に、次の処理を繰り返します。
  1. `GEN S` を実行し、標準出力を入力とする
  2. その入力を MAIN と NAIVE に与える
  3. 2 つの出力をトークン単位で比較する (空白・改行の違いは無視)。
     誤差を許して比較する (--float) か、チェッカーで判定する (--checker)
     こともできる
出力の食い違い (チェッカーの不合格)、実行時エラー (終了コードが 0 以外)、
時間切れのいずれかが起きた入力を反例として報告し、そこで終了します。""",
        "epilog": """\
ファイルの指定:
  3 つのファイルは -m, -n, -g で順不同に指定できます。オプションを付けずに
  並べたファイル (FILE) は、オプションで指定しなかった役割を MAIN, NAIVE,
  GEN の順に埋めます。次のコマンドはどれも同じ意味です。
    randtest -m main.cpp -n naive.cpp -g gen.cpp
    randtest -g gen.cpp -m main.cpp -n naive.cpp
    randtest main.cpp naive.cpp gen.cpp

  ファイルの実行方法:
    .cpp .cc .cxx  CXX CXXFLAGS -I <ライブラリのルート> でコンパイルし、
                   ./.randtest/build/ にキャッシュする (ソースか include
                   したヘッダが変わったときだけ再コンパイルする)
    .py            randtest を動かしている Python で実行する
    それ以外       実行ファイルとしてそのまま実行する (例: ./a.out)

比較方法:
  既定では、出力を空白・改行で区切ったトークンがすべて等しいかを調べます。
  --exact を付けるとバイト列の完全一致で比較します。
  --float EPS は、実数のトークン x (MAIN) と y (NAIVE) が
    |x - y| <= EPS  または  |x - y| <= EPS * |y|
  を満たせば一致とみなします。ただし、両方が整数の形のトークン (例えば
  1000000 と 1000001) と、単語などの数でないトークンは完全一致で比べます。
  --checker CHECKER は、入力ごとに
    CHECKER <入力ファイル> <MAIN の出力> <NAIVE の出力>
  を実行します (testlib のチェッカーと同じ引数の順)。終了コード 0 なら
  合格、それ以外の終了コード・異常終了・時間切れは不合格です。NAIVE が
  なければ 3 番目のファイルは空になります。正解が複数ある問題に使います。
  チェッカーの標準出力と標準エラー出力は、不合格の理由として表示し、
  checker.log に保存します。--checker を使うときは NAIVE を省略でき、
  FILE が残りの役割より 1 つ少なければ MAIN と GEN に割り当てます。
  `randtest --init --checker check.cpp` で、生成器の雛形と一緒にチェッカー
  の雛形も書き出します (randtest.json に "checker" がある場合も同様)。
  --exact, --float, --checker は同時に指定できません。

生成器:
  GEN は `GEN <seed>` の形で呼ばれ、入力を 1 つ標準出力に書きます。同じ
  seed からは常に同じ入力を出してください。このライブラリでは次のように
  書けます。
    #include "random/gen/all.hpp"
    Random rng(argc, argv);  // argv[1] を seed として読む
  区間は半開区間 [l, r)、頂点番号は 0 始まりです。N <= 8 程度の小さい入力
  にすると、手で追える反例が見つかりやすくなります。
  `randtest --init` で雛形を gen.cpp に書き出せます。

反例:
  最初に見つかった反例について、入力、各解の結果、出力の差分を表示し、
  OUT (randtest_fail/) に保存します。
    in.txt                            入力
    out_main.txt out_naive.txt        出力
    stderr_main.log stderr_naive.log  標準エラー出力 (空でも必ず書き出す)
    checker.log                       CHECKER の出力 (--checker のとき)
    info.txt                          seed、各解の結果、再現用のコマンド
  標準エラー出力は画面に表示せず、比較もしないので、デバッグ出力が残って
  いても構いません。内容は .log ファイルで確認してください。
  --replay SEED でその seed だけを実行し、入力と両方の出力を表示して、
  同じファイルを OUT に保存します。
  seed は毎回 0 から始まるので、修正後に再実行すると同じ入力で確認できます。
  別の入力を試すには --start で開始位置をずらします。

終了コード:
  0    すべて一致した (または --init だけを実行した)
  1    反例が見つかった (--replay では出力が食い違った)
  2    準備の段階で失敗した (引数の誤り、コンパイルエラー、生成器の異常終了)
  130  Ctrl-C で中断した

使用例:
  randtest --init
      生成器の雛形を gen.cpp に書き出す
  randtest --init --checker check.cpp
      チェッカーの雛形も check.cpp に書き出す
  randtest -m main.cpp -n naive.cpp -g gen.cpp
      seed 0 から 999 までを試す
  randtest -m main.cpp -n naive.py -g gen.cpp -c 0 --time 60
      Python の愚直解と比べながら 60 秒間探し続ける
  randtest -m main.cpp -n naive.cpp -g gen.cpp --replay 42
      seed 42 の入力と両方の出力を表示する
  randtest -m main.cpp -n naive.cpp -g gen.cpp \\
           --cxxflags "-std=c++17 -O2 -g -fsanitize=address,undefined"
      配列外アクセスなども実行時エラーとして検出する
  randtest -m main.cpp -n naive.cpp -g gen.cpp --float 1e-6
      絶対誤差または相対誤差 1e-6 までを許して比較する
  randtest -m main.cpp -n naive.cpp -g gen.cpp --checker check.cpp
      check.cpp で判定する (愚直解の答えも参照できる)

設定ファイル:
  実行したディレクトリに randtest.json があれば、その値をオプションの既定値
  として使います。コマンドラインのオプションはこれより優先し、位置引数の
  FILE も "main", "naive", "gen" より優先します。-I で指定したディレクトリは
  "include" に追加されます。キーはすべて省略できます。
    "main", "naive", "gen"     ファイル (文字列)
    "count", "start"           整数
    "time", "timeout"          秒数 ("time" は 0 か null で制限なし)
    "exact"                    true か false (--no-exact で打ち消せる)
    "float"                    数値か null
    "checker"                  ファイル (文字列)
    "out", "cxx", "cxxflags"   文字列
    "include"                  ディレクトリのリスト
  未知のキーや型の誤りはエラーになります。例:
    {
      "main": "main.cpp", "naive": "naive.cpp", "gen": "gen.cpp",
      "count": 5000, "timeout": 5,
      "cxxflags": "-std=c++17 -O2 -g -fsanitize=address,undefined"
    }
  このファイルがあれば `randtest` だけでテストを実行できます。
  `randtest --init` は雛形を書き出すだけで、設定のファイルは使いません。

ヘルプの言語:
  -h の言語は環境変数 RANDTEST_LANG (ja または en) で決まり、未設定なら
  ロケール (LANGUAGE, LC_ALL, LC_MESSAGES, LANG) に従います。
  --help-ja と --help-en は、常に日本語・英語のヘルプを表示します。
  普段から日本語にするには、シェルの設定に export RANDTEST_LANG=ja を
  追加してください。""",
        "groups": {
            "files": "ファイル",
            "run": "実行",
            "compare": "比較と出力",
            "build": "コンパイル",
            "other": "その他",
        },
        "args": {
            "files": "オプションで指定しなかった MAIN, NAIVE, GEN",
            "main": "テストする解 (提出する解)",
            "naive": "比較に使う、確実に正しい解 (遅くてよい)",
            "gen": "生成器。`GEN <seed>` の形で呼ばれる",
            "count": "試すケース数。0 なら無制限 (既定値: 1000)",
            "start": "最初の seed (既定値: 0)",
            "time": "SEC 秒経過したら終了する。0 なら制限なし\n(既定値: 制限なし)",
            "timeout": "GEN, MAIN, NAIVE の 1 回の実行の制限時間 (秒)\n(既定値: 2)",
            "replay": "SEED だけを実行して入力と出力を表示し、\n標準エラー出力とともに OUT に保存する",
            "exact": "トークン単位ではなくバイト列の完全一致で比較する",
            "no_exact": "トークン単位で比較する (\"exact\": true を打ち消す)",
            "float": "実数のトークンは絶対誤差か相対誤差が EPS 以下なら\n一致とみなす",
            "checker": "比較の代わりに CHECKER で MAIN の出力を判定する。\nNAIVE は省略できる",
            "out": "反例の保存先 (既定値: randtest_fail)",
            "cxx": "C++ コンパイラ (既定値: g++)",
            "cxxflags": "コンパイルオプション。既定値を置き換える\n(既定値: \"-std=c++17 -O2\")",
            "include": "追加の include ディレクトリ (複数回指定できる)",
            "init": "生成器の雛形を PATH に書き出す (既定値: gen.cpp)。\n"
                    "--checker CHECKER も指定すればチェッカーの雛形も作る。\n"
                    "ファイルも指定すれば、続けてテストを実行する",
            "help": "環境に合わせた言語でヘルプを表示する",
            "help_ja": "日本語でヘルプを表示する",
            "help_en": "英語でヘルプを表示する",
        },
    },
}


def help_language():
    """Return "ja" or "en" from RANDTEST_LANG or the locale variables."""
    for name in ("RANDTEST_LANG", "LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG"):
        value = os.environ.get(name, "")
        if value:
            return "ja" if value.split(":")[0].lower().startswith("ja") else "en"
    return "en"


class HelpAction(argparse.Action):
    def __init__(self, option_strings, dest, lang=None, **kwargs):
        super().__init__(option_strings, dest=argparse.SUPPRESS,
                         default=argparse.SUPPRESS, nargs=0, **kwargs)
        self.lang = lang

    def __call__(self, parser, namespace, values, option_string=None):
        build_parser(self.lang or help_language()).print_help()
        parser.exit()


def build_parser(lang):
    text = HELP[lang]

    class Formatter(argparse.RawTextHelpFormatter):
        def __init__(self, prog):
            super().__init__(prog, max_help_position=26)

        def add_usage(self, usage, actions, groups, prefix=None):
            super().add_usage(usage, actions, groups, text["usage_prefix"])

    parser = argparse.ArgumentParser(
        prog="randtest", usage=text["usage"], description=text["description"],
        epilog=text["epilog"], formatter_class=Formatter, add_help=False,
    )
    h, g = text["args"], {key: parser.add_argument_group(title)
                          for key, title in text["groups"].items()}
    g["files"].add_argument("-m", "--main", metavar="MAIN", help=h["main"])
    g["files"].add_argument("-n", "--naive", metavar="NAIVE", help=h["naive"])
    g["files"].add_argument("-g", "--gen", metavar="GEN", help=h["gen"])
    g["files"].add_argument("files", nargs="*", metavar="FILE", help=h["files"])
    g["run"].add_argument("-c", "--count", type=int, default=1000, metavar="N",
                          help=h["count"])
    g["run"].add_argument("--start", type=int, default=0, metavar="SEED", help=h["start"])
    g["run"].add_argument("--time", type=float, metavar="SEC", help=h["time"])
    g["run"].add_argument("--timeout", type=float, default=2.0, metavar="SEC",
                          help=h["timeout"])
    g["run"].add_argument("--replay", type=int, metavar="SEED", help=h["replay"])
    g["compare"].add_argument("--exact", action="store_true", help=h["exact"])
    g["compare"].add_argument("--no-exact", dest="exact", action="store_false",
                              help=h["no_exact"])
    g["compare"].add_argument("--float", type=float, metavar="EPS", help=h["float"])
    g["compare"].add_argument("--checker", metavar="CHECKER", help=h["checker"])
    g["compare"].add_argument("-o", "--out", default="randtest_fail", metavar="DIR",
                              help=h["out"])
    g["build"].add_argument("--cxx", default="g++", metavar="CXX", help=h["cxx"])
    g["build"].add_argument("--cxxflags", default="-std=c++17 -O2", metavar="FLAGS",
                            help=h["cxxflags"])
    g["build"].add_argument("-I", dest="include", action="append", default=[],
                            metavar="DIR", help=h["include"])
    g["other"].add_argument("--init", nargs="?", const="gen.cpp", metavar="PATH",
                            help=h["init"])
    g["other"].add_argument("-h", "--help", action=HelpAction, help=h["help"])
    g["other"].add_argument("--help-ja", action=HelpAction, lang="ja", help=h["help_ja"])
    g["other"].add_argument("--help-en", action=HelpAction, lang="en", help=h["help_en"])
    return parser


class ConfigError(Exception):
    pass


def _is_number(value):
    return isinstance(value, (int, float)) and not isinstance(value, bool)


CONFIG_TYPES = {
    "main": ("a string", lambda v: isinstance(v, str)),
    "naive": ("a string", lambda v: isinstance(v, str)),
    "gen": ("a string", lambda v: isinstance(v, str)),
    "count": ("an integer", lambda v: isinstance(v, int) and not isinstance(v, bool)),
    "start": ("an integer", lambda v: isinstance(v, int) and not isinstance(v, bool)),
    "time": ("a number or null", lambda v: v is None or _is_number(v)),
    "timeout": ("a number", _is_number),
    "exact": ("true or false", lambda v: isinstance(v, bool)),
    "float": ("a number or null", lambda v: v is None or _is_number(v)),
    "checker": ("a string", lambda v: isinstance(v, str)),
    "out": ("a string", lambda v: isinstance(v, str)),
    "cxx": ("a string", lambda v: isinstance(v, str)),
    "cxxflags": ("a string", lambda v: isinstance(v, str)),
    "include": ("a list of strings",
                lambda v: isinstance(v, list) and all(isinstance(x, str) for x in v)),
}


def load_config(path):
    """Return the settings in ``path``, or {} when the file does not exist."""
    try:
        text = path.read_text()
    except FileNotFoundError:
        return {}
    except OSError as e:
        raise ConfigError(f"{path}: {e.strerror}")
    try:
        data = json.loads(text)
    except json.JSONDecodeError as e:
        raise ConfigError(f"{path}: invalid JSON: {e}")
    if not isinstance(data, dict):
        raise ConfigError(f"{path}: the top level must be an object")
    for key, value in data.items():
        if key not in CONFIG_TYPES:
            raise ConfigError(f"{path}: unknown key \"{key}\" "
                              f"(allowed: {', '.join(CONFIG_TYPES)})")
        expected, valid = CONFIG_TYPES[key]
        if not valid(value):
            raise ConfigError(f"{path}: \"{key}\" must be {expected}")
    return data


def parse_args(argv):
    parser = build_parser(help_language())
    path = Path(CONFIG_FILE)
    try:
        config, config_error = load_config(path), None
    except ConfigError as e:
        config, config_error = {}, str(e)
    defaults = {k: v for k, v in config.items() if k not in ROLES}
    if "include" in defaults:
        defaults["include"] = list(defaults["include"])  # -I appends to it
    parser.set_defaults(**defaults)
    args = parser.parse_intermixed_args(argv)  # exits here for --help
    if config_error:
        parser.error(config_error)

    files = list(args.files)
    files_on_command_line = bool(files) or any(getattr(args, r) for r in ROLES)
    unset = [role for role in ROLES if getattr(args, role) is None]
    # with a checker NAIVE is optional: one FILE fewer means MAIN and GEN
    if args.checker and "naive" in unset and len(files) == len(unset) - 1:
        unset.remove("naive")
    for role, path in zip(unset, files):
        setattr(args, role, path)
    if len(files) > len(unset):
        parser.error(f"too many files: {' '.join(files[len(unset):])}")
    if args.init is None or files_on_command_line:
        for role in ROLES:
            if getattr(args, role) is None and role in config:
                setattr(args, role, config[role])
    required = [r for r in ROLES if not (r == "naive" and args.checker)]
    missing = [role.upper() for role in required if getattr(args, role) is None]
    nothing = all(getattr(args, role) is None for role in ROLES)
    if missing and not (args.init is not None and nothing):
        parser.error(f"missing {', '.join(missing)} "
                     f"(use -m, -n, -g, positional FILEs or {CONFIG_FILE})")
    modes = [name for name, on in (("--exact", args.exact),
                                   ("--float", args.float is not None),
                                   ("--checker", args.checker is not None)) if on]
    if len(modes) > 1:
        parser.error(f"{' and '.join(modes)} cannot be combined"
                     + (f" (check {CONFIG_FILE})" if config else ""))
    if args.float is not None and not (args.float >= 0 and math.isfinite(args.float)):
        parser.error("--float must be a non-negative number")
    if args.count < 0:
        parser.error("--count must be non-negative")
    if args.start < 0 or (args.replay is not None and args.replay < 0):
        parser.error("seeds must be non-negative")
    if args.time is not None and args.time < 0:
        parser.error("--time must be non-negative")
    if args.timeout <= 0:
        parser.error("--timeout must be positive")
    if config:
        print(f"randtest: using settings in {CONFIG_FILE}", file=sys.stderr)
    return args


def init(args):
    """Write the generator template, and the checker template with --checker.

    Existing files are kept; it fails only when nothing could be written."""
    targets = [(args.init, GEN_TEMPLATE)]
    if args.checker:
        if Path(args.checker).suffix.lower() not in CPP_SUFFIXES:
            raise Abort(f"--init writes a C++ checker; {args.checker} is not a C++ file")
        targets.append((args.checker, CHECKER_TEMPLATE))
    kept = []
    for path, text in targets:
        target = Path(path)
        if target.exists():
            kept.append(path)
            print(f"{path} already exists, kept it", file=sys.stderr)
            continue
        target.write_text(text)
        print(f"wrote {path}")
    if len(kept) == len(targets):
        raise Abort("nothing was written")


def replay(args, programs):
    case = evaluate(args.replay, args, programs)
    out_dir = Path(args.out)
    save_case(out_dir, args, case)
    show(f"input (seed {case.seed})", case.stdin)
    for role, result in roles_of(case):
        show(f"{role}: {result.status(args.timeout)}", result.stdout)
    show_verdict(case, args, out_dir)
    print_saved(out_dir, case)
    return 0 if case.passed else 1


def search(args, programs):
    tty = sys.stderr.isatty()
    started = time.monotonic()
    last_print = 0.0
    done = 0
    seed = args.start
    try:
        while args.count == 0 or done < args.count:
            elapsed = time.monotonic() - started
            if args.time and elapsed >= args.time:
                break
            if tty and elapsed - last_print >= 0.1:
                last_print = elapsed
                total = "" if args.count == 0 else f"/{args.count}"
                rate = done / elapsed if elapsed > 0 else 0.0
                print(f"\r{done}{total} passed ({rate:.0f} cases/s)",
                      end="", file=sys.stderr, flush=True)
            case = evaluate(seed, args, programs)
            if not case.passed:
                if tty:
                    print(file=sys.stderr)
                report(args, case)
                return 1
            done += 1
            seed += 1
    except KeyboardInterrupt:
        if tty:
            print(file=sys.stderr)
        print(f"interrupted: {done} cases passed (seeds {args.start}..{seed - 1})")
        return 130
    if tty:
        print("\r", end="", file=sys.stderr)
    elapsed = time.monotonic() - started
    print(f"all {done} cases passed (seeds {args.start}..{seed - 1}, {elapsed:.1f}s)")
    return 0


def main(argv=None):
    args = parse_args(sys.argv[1:] if argv is None else argv)
    try:
        if args.init is not None:
            init(args)
            if args.gen is None:
                return 0
        programs = {
            role: prepare(getattr(args, role), args) if getattr(args, role) else None
            for role in ("main", "naive", "gen", "checker")
        }
        if args.replay is not None:
            return replay(args, programs)
        return search(args, programs)
    except Abort as e:
        print(f"randtest: {e}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
