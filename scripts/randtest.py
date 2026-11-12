#!/usr/bin/env python3
"""Random testing: compare a solution with a naive one on generated inputs.

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
        f"replay: randtest {args.main} {args.naive} {args.gen} --replay {seed}\n"
    )


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

def parse_args(argv):
    parser = argparse.ArgumentParser(
        prog="randtest",
        description="Compare MAIN with NAIVE on inputs printed by `GEN <seed>`. "
                    "C++ sources are compiled with the library root on the include path.",
    )
    parser.add_argument("main", nargs="?", help="solution to test")
    parser.add_argument("naive", nargs="?", help="trusted (slow) solution")
    parser.add_argument("gen", nargs="?", help="generator, called as `gen <seed>`")
    parser.add_argument("-n", "--count", type=int, default=1000,
                        help="number of cases, 0 for unlimited (default: 1000)")
    parser.add_argument("--start", type=int, default=0, help="first seed (default: 0)")
    parser.add_argument("--time", type=float, help="stop after this many seconds")
    parser.add_argument("--timeout", type=float, default=2.0,
                        help="time limit per run in seconds (default: 2)")
    parser.add_argument("--exact", action="store_true",
                        help="compare outputs byte by byte instead of token by token")
    parser.add_argument("--replay", type=int, metavar="SEED",
                        help="run only SEED and show the input and both outputs")
    parser.add_argument("-o", "--out", default="randtest_fail",
                        help="directory for a counterexample (default: randtest_fail)")
    parser.add_argument("--cxx", default="g++", help="C++ compiler (default: g++)")
    parser.add_argument("--cxxflags", default="-std=c++17 -O2",
                        help="compiler flags (default: '-std=c++17 -O2')")
    parser.add_argument("-I", dest="include", action="append", default=[],
                        help="additional include directory")
    parser.add_argument("--init", nargs="?", const="gen.cpp", metavar="PATH",
                        help="write a generator template to PATH (default: gen.cpp)")
    args = parser.parse_args(argv)
    if args.init is None and args.gen is None:
        parser.error("MAIN, NAIVE and GEN are required")
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
