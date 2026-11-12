#!/usr/bin/env python3
"""Random testing: compare a solution with a naive one on generated inputs.

    randtest -m main.cpp -n naive.cpp -g gen.cpp [options]
    randtest main.cpp naive.cpp gen.cpp [options]

The generator is called as ``gen <seed>`` and must write one input to stdout.
"""

import argparse
import difflib
import hashlib
import os
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
SHOW_LIMIT = 2000  # bytes of input/output printed on failure

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


def same_output(a, b, exact):
    return a == b if exact else a.split() == b.split()


def generate(gen, seed, timeout):
    result = run([*gen, str(seed)], b"", timeout)
    if not result.ok:
        raise Abort((
            f"generator failed for seed {seed}: {result.status(timeout)}\n"
            + result.stderr.decode(errors="replace")
        ).rstrip())
    return result.stdout


# ---------------------------------------------------------------- report

def show(label, data):
    text = data.decode(errors="replace")
    if len(data) > SHOW_LIMIT:
        text = text[:SHOW_LIMIT] + "\n... (truncated)"
    print(f"--- {label} ---")
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


def save_case(out_dir, seed, args, stdin, main, naive):
    out_dir.mkdir(parents=True, exist_ok=True)
    for name in ("in.txt", "out_main.txt", "out_naive.txt",
                 "err_main.txt", "err_naive.txt", "info.txt"):
        (out_dir / name).unlink(missing_ok=True)
    (out_dir / "in.txt").write_bytes(stdin)
    for role, result in (("main", main), ("naive", naive)):
        (out_dir / f"out_{role}.txt").write_bytes(result.stdout)
        if result.stderr:
            (out_dir / f"err_{role}.txt").write_bytes(result.stderr)
    (out_dir / "info.txt").write_text(
        f"seed: {seed}\n"
        f"main: {args.main} {main.status(args.timeout)}\n"
        f"naive: {args.naive} {naive.status(args.timeout)}\n"
        f"replay: {replay_command(args, seed)}\n"
    )


def replay_command(args, seed):
    files = " ".join(f"-{flag} {shlex.quote(path)}" for flag, path in
                     (("m", args.main), ("n", args.naive), ("g", args.gen)))
    return f"randtest {files} --replay {seed}"


def report(seed, args, stdin, main, naive):
    print(f"\nfound a counterexample (seed {seed})")
    show("input", stdin)
    for role, result in (("main", main), ("naive", naive)):
        status = result.status(args.timeout)
        if status != "OK":
            print(f"{role}: {status}")
            if result.stderr:
                show(f"stderr of {role}", result.stderr)
    if main.ok and naive.ok:
        show_diff(main.stdout, naive.stdout)
    out_dir = Path(args.out)
    save_case(out_dir, seed, args, stdin, main, naive)
    print(f"saved to {out_dir}/ (replay with --replay {seed})")


# ---------------------------------------------------------------- main

HELP = {
    "en": {
        "usage_prefix": "usage: ",
        "usage": "%(prog)s -m MAIN -n NAIVE -g GEN [options]\n"
                 "       %(prog)s MAIN NAIVE GEN [options]\n"
                 "       %(prog)s --init [PATH]",
        "description": """\
Random testing: run a solution and a naive solution on many generated
inputs and stop at the first input (a counterexample) where they disagree.

For each seed S = START, START+1, ..., randtest
  1. runs `GEN S` and takes its stdout as the input,
  2. feeds the input to MAIN and NAIVE,
  3. compares their outputs token by token (whitespace is ignored).
A different output, a runtime error (non-zero exit status) or a timeout
of either program is reported as a counterexample.""",
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

generator:
  GEN is called as `GEN <seed>` and must print one input to stdout.
  The same seed must always give the same input. With this library:
    #include "random/gen/all.hpp"
    Random rng(argc, argv);  // reads argv[1] as the seed
  Ranges are half-open [l, r) and vertices are 0-indexed.
  Small inputs (e.g. N <= 8) give counterexamples that are easy to trace.
  `randtest --init` writes a template to gen.cpp.

counterexample:
  The first counterexample is printed and saved to OUT (randtest_fail/):
    in.txt                      the input
    out_main.txt out_naive.txt  the outputs
    err_main.txt err_naive.txt  stderr (only when it is not empty)
    info.txt                    the seed, the results and a replay command
  --replay SEED runs only that seed and shows the input and both outputs.
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
  randtest -m main.cpp -n naive.cpp -g gen.cpp
      try seeds 0..999
  randtest -m main.cpp -n naive.py -g gen.cpp -c 0 --time 60
      search for 60 seconds with a naive solution in Python
  randtest -m main.cpp -n naive.cpp -g gen.cpp --replay 42
      show the input and outputs for seed 42
  randtest -m main.cpp -n naive.cpp -g gen.cpp \\
           --cxxflags "-std=c++17 -O2 -g -fsanitize=address,undefined"
      also report out-of-range accesses as runtime errors

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
            "time": "stop after SEC seconds (default: no limit)",
            "timeout": "time limit of each run of GEN, MAIN and NAIVE\n(default: 2)",
            "replay": "run only SEED and show the input and both outputs",
            "exact": "compare outputs byte by byte instead of token by token",
            "out": "directory to save a counterexample\n(default: randtest_fail)",
            "cxx": "C++ compiler (default: g++)",
            "cxxflags": "compiler flags, replacing the default\n(default: \"-std=c++17 -O2\")",
            "include": "additional include directory (repeatable)",
            "init": "write a generator template to PATH (default: gen.cpp)\n"
                    "and exit; run the test as well if all files are given",
            "help": "show the help in the language of the environment",
            "help_ja": "show the help in Japanese",
            "help_en": "show the help in English",
        },
    },
    "ja": {
        "usage_prefix": "使い方: ",
        "usage": "%(prog)s -m MAIN -n NAIVE -g GEN [オプション]\n"
                 "       %(prog)s MAIN NAIVE GEN [オプション]\n"
                 "       %(prog)s --init [PATH]",
        "description": """\
ランダムテスト: 提出する解 (MAIN) と愚直解 (NAIVE) に、生成器 (GEN) が
作った入力を次々に与え、結果が食い違う入力 (反例) を探します。

seed S = START, START+1, ... の順に、次の処理を繰り返します。
  1. `GEN S` を実行し、標準出力を入力とする
  2. その入力を MAIN と NAIVE に与える
  3. 2 つの出力をトークン単位で比較する (空白・改行の違いは無視)
出力の食い違い、実行時エラー (終了コードが 0 以外)、時間切れのいずれかが
起きた入力を反例として報告し、そこで終了します。""",
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
  最初に見つかった反例を表示し、OUT (randtest_fail/) に保存します。
    in.txt                      入力
    out_main.txt out_naive.txt  出力
    err_main.txt err_naive.txt  標準エラー出力 (空でない場合だけ)
    info.txt                    seed、各解の結果、再現用のコマンド
  --replay SEED でその seed だけを実行し、入力と両方の出力を表示します。
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
  randtest -m main.cpp -n naive.cpp -g gen.cpp
      seed 0 から 999 までを試す
  randtest -m main.cpp -n naive.py -g gen.cpp -c 0 --time 60
      Python の愚直解と比べながら 60 秒間探し続ける
  randtest -m main.cpp -n naive.cpp -g gen.cpp --replay 42
      seed 42 の入力と両方の出力を表示する
  randtest -m main.cpp -n naive.cpp -g gen.cpp \\
           --cxxflags "-std=c++17 -O2 -g -fsanitize=address,undefined"
      配列外アクセスなども実行時エラーとして検出する

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
            "time": "SEC 秒経過したら終了する (既定値: 制限なし)",
            "timeout": "GEN, MAIN, NAIVE の 1 回の実行の制限時間 (秒)\n(既定値: 2)",
            "replay": "SEED だけを実行し、入力と両方の出力を表示する",
            "exact": "トークン単位ではなくバイト列の完全一致で比較する",
            "out": "反例の保存先 (既定値: randtest_fail)",
            "cxx": "C++ コンパイラ (既定値: g++)",
            "cxxflags": "コンパイルオプション。既定値を置き換える\n(既定値: \"-std=c++17 -O2\")",
            "include": "追加の include ディレクトリ (複数回指定できる)",
            "init": "生成器の雛形を PATH に書き出す (既定値: gen.cpp)。\n"
                    "ファイルも 3 つ指定すれば、続けてテストを実行する",
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


def parse_args(argv):
    parser = build_parser(help_language())
    args = parser.parse_intermixed_args(argv)
    roles = ("main", "naive", "gen")
    files = list(args.files)
    for role in roles:
        if getattr(args, role) is None and files:
            setattr(args, role, files.pop(0))
    if files:
        parser.error(f"too many files: {' '.join(files)}")
    missing = [role.upper() for role in roles if getattr(args, role) is None]
    if missing and not (args.init is not None and len(missing) == len(roles)):
        parser.error(f"missing {', '.join(missing)} (use -m, -n, -g or positional FILEs)")
    if args.count < 0:
        parser.error("--count must be non-negative")
    if args.start < 0 or (args.replay is not None and args.replay < 0):
        parser.error("seeds must be non-negative")
    return args


def init(path):
    target = Path(path)
    if target.exists():
        raise Abort(f"{path} already exists")
    target.write_text(GEN_TEMPLATE)
    print(f"wrote {path}")


def replay(args, main, naive, gen):
    seed = args.replay
    stdin = generate(gen, seed, args.timeout)
    m = run(main, stdin, args.timeout)
    n = run(naive, stdin, args.timeout)
    show(f"input (seed {seed})", stdin)
    for role, result in (("main", m), ("naive", n)):
        show(f"{role}: {result.status(args.timeout)}", result.stdout)
    if m.ok and n.ok and same_output(m.stdout, n.stdout, args.exact):
        print("outputs match")
        return 0
    if m.ok and n.ok:
        show_diff(m.stdout, n.stdout)
    return 1


def search(args, main, naive, gen):
    tty = sys.stderr.isatty()
    started = time.monotonic()
    last_print = 0.0
    done = 0
    seed = args.start
    try:
        while args.count == 0 or done < args.count:
            elapsed = time.monotonic() - started
            if args.time is not None and elapsed >= args.time:
                break
            if tty and elapsed - last_print >= 0.1:
                last_print = elapsed
                total = "" if args.count == 0 else f"/{args.count}"
                rate = done / elapsed if elapsed > 0 else 0.0
                print(f"\r{done}{total} passed ({rate:.0f} cases/s)",
                      end="", file=sys.stderr, flush=True)
            stdin = generate(gen, seed, args.timeout)
            m = run(main, stdin, args.timeout)
            n = run(naive, stdin, args.timeout)
            if not (m.ok and n.ok and same_output(m.stdout, n.stdout, args.exact)):
                if tty:
                    print(file=sys.stderr)
                report(seed, args, stdin, m, n)
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
            init(args.init)
            if args.gen is None:
                return 0
        commands = [prepare(s, args) for s in (args.main, args.naive, args.gen)]
        if args.replay is not None:
            return replay(args, *commands)
        return search(args, *commands)
    except Abort as e:
        print(f"randtest: {e}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
