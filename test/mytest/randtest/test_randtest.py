"""Behavior tests for scripts/randtest.py."""

import importlib.util
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import textwrap
import time
import unittest


ROOT = Path(__file__).resolve().parents[3]
SCRIPT = ROOT / "scripts" / "randtest.py"

GEN = """\
#include <iostream>
#include "random/gen/random.hpp"
int main(int argc, char **argv) {
    Random rng(argc, argv);
    int n = rng.randint(1, 6);
    std::cout << n << '\\n';
    for(int i = 0; i < n; i++) std::cout << rng.randint(-5, 6) << " \\n"[i + 1 == n];
}
"""

# max of the input values
NAIVE = """\
#include <iostream>
int main() {
    int n; std::cin >> n;
    long long best = -1e18;
    for(int i = 0; i < n; i++) { long long x; std::cin >> x; if(x > best) best = x; }
    std::cout << best << '\\n';
}
"""


def solution(body):
    return textwrap.dedent("""\
        #include <iostream>
        #include <vector>
        int main() {
            int n; std::cin >> n;
            std::vector<long long> a(n);
            for(auto &x : a) std::cin >> x;
            %s
        }
        """) % body


class RandTestTests(unittest.TestCase):
    def setUp(self):
        self._tmp = tempfile.TemporaryDirectory()
        self.dir = Path(self._tmp.name)
        self.write("gen.cpp", GEN)
        self.write("naive.cpp", NAIVE)

    def tearDown(self):
        self._tmp.cleanup()

    def write(self, name, text):
        path = self.dir / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        return path

    def randtest(self, *args, env=None):
        base = {k: v for k, v in os.environ.items()
                if k not in ("RANDTEST_LANG", "LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG")}
        return subprocess.run(
            [sys.executable, str(SCRIPT), *args], cwd=self.dir,
            capture_output=True, text=True, timeout=120,
            env={**base, "LANG": "C.UTF-8", **(env or {})},
        )

    def test_help_in_both_languages(self):
        english = self.randtest("--help-en")
        japanese = self.randtest("--help-ja")
        self.assertEqual(english.returncode, 0)
        self.assertEqual(japanese.returncode, 0)
        for heading in ("usage: randtest -m MAIN -n NAIVE -g GEN", "files:", "running:",
                        "specifying files:", "generator:", "counterexample:",
                        "exit status:", "examples:", "help language:"):
            self.assertIn(heading, english.stdout)
        for heading in ("使い方: randtest -m MAIN -n NAIVE -g GEN", "ファイル:", "実行:",
                        "ファイルの指定:", "生成器:", "反例:", "終了コード:", "使用例:",
                        "ヘルプの言語:"):
            self.assertIn(heading, japanese.stdout)
        for option in ("--main", "--naive", "--gen", "--count", "--start", "--time",
                       "--timeout", "--replay", "--exact", "--out", "--cxx", "--cxxflags",
                       "-I DIR", "--init", "--help-ja", "--help-en"):
            self.assertIn(option, english.stdout)
            self.assertIn(option, japanese.stdout)

    def test_help_language_selection(self):
        for env, prefix in (
            ({}, "usage:"),
            ({"RANDTEST_LANG": "ja"}, "使い方:"),
            ({"LANG": "ja_JP.UTF-8"}, "使い方:"),
            ({"LANG": "ja_JP.UTF-8", "RANDTEST_LANG": "en"}, "usage:"),
            ({"LANGUAGE": "ja:en", "LANG": "C.UTF-8"}, "使い方:"),
        ):
            with self.subTest(env=env):
                result = self.randtest("-h", env=env)
                self.assertEqual(result.returncode, 0)
                self.assertTrue(result.stdout.startswith(prefix), result.stdout[:40])
        self.assertTrue(self.randtest("--help-en", env={"RANDTEST_LANG": "ja"})
                        .stdout.startswith("usage:"))

    def test_help_texts_cover_the_same_options(self):
        spec = importlib.util.spec_from_file_location("randtest", SCRIPT)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        en, ja = module.HELP["en"], module.HELP["ja"]
        self.assertEqual(en.keys(), ja.keys())
        self.assertEqual(en["args"].keys(), ja["args"].keys())
        self.assertEqual(en["groups"].keys(), ja["groups"].keys())

    def test_all_cases_pass(self):
        self.write("main.cpp", solution(
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b << '\\n';"))
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp", "-c", "30", "--start", "5")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("all 30 cases passed (seeds 5..34", result.stdout)
        self.assertFalse((self.dir / "randtest_fail").exists())

    def test_files_by_options_in_any_order(self):
        self.write("main.cpp", solution(
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b << '\\n';"))
        for args in (
            ["-g", "gen.cpp", "-c", "5", "-n", "naive.cpp", "-m", "main.cpp"],
            ["--naive", "naive.cpp", "--gen", "gen.cpp", "--main", "main.cpp", "-c", "5"],
            ["-g", "gen.cpp", "main.cpp", "-c", "5", "naive.cpp"],  # positionals fill MAIN, NAIVE
            ["main.cpp", "-c", "5", "naive.cpp", "gen.cpp"],
        ):
            with self.subTest(args=args):
                result = self.randtest(*args)
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertIn("all 5 cases passed", result.stdout)

    def test_file_argument_errors(self):
        for args, message in (
            (["-m", "main.cpp", "-n", "naive.cpp"], "missing GEN"),
            (["main.cpp"], "missing NAIVE, GEN"),
            ([], "missing MAIN, NAIVE, GEN"),
            (["-g", "gen.cpp", "a.cpp", "b.cpp", "c.cpp"], "too many files: c.cpp"),
        ):
            with self.subTest(args=args):
                result = self.randtest(*args)
                self.assertEqual(result.returncode, 2)
                self.assertIn(message, result.stderr)

    def test_counterexample_is_saved_and_replayable(self):
        # wrong when every value is negative
        self.write("main.cpp", solution(
            "long long b = 0; for(auto x : a) if(x > b) b = x; std::cout << b << '\\n';"))
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        fail = self.dir / "randtest_fail"
        info = (fail / "info.txt").read_text()
        seed = int(info.split()[1])
        self.assertIn(f"found a counterexample (seed {seed})", result.stdout)
        self.assertTrue(all(int(x) < 0 for x in (fail / "in.txt").read_text().split()[1:]))
        self.assertEqual((fail / "out_main.txt").read_text(), "0\n")
        # the input depends only on the seed
        gen = next(p for p in (self.dir / ".randtest" / "build").glob("gen-*") if p.suffix != ".d")
        regenerated = subprocess.run([str(gen), str(seed)], capture_output=True, text=True).stdout
        self.assertEqual(regenerated, (fail / "in.txt").read_text())
        self.assertIn(f"replay: randtest -m main.cpp -n naive.cpp -g gen.cpp --replay {seed}", info)
        replay = self.randtest("--replay", str(seed), "-g", "gen.cpp", "-n", "naive.cpp", "-m", "main.cpp")
        self.assertEqual(replay.returncode, 1)
        self.assertIn(regenerated.strip(), replay.stdout)
        self.assertIn("--- diff (naive -> main) ---", replay.stdout)

    def test_stderr_of_both_programs_is_shown(self):
        # wrong when every value is negative; prints debug output to stderr
        self.write("main.cpp", solution(
            "long long b = 0; for(auto x : a) if(x > b) b = x; "
            "std::cerr << \"debug-main n=\" << n << '\\n'; std::cout << b << '\\n';"))
        self.write("noisy.cpp", "#include <iostream>\n" + NAIVE.replace(
            "int main() {", "int main() {\n    std::cerr << \"debug-naive\\n\";"))
        result = self.randtest("-m", "main.cpp", "-n", "noisy.cpp", "-g", "gen.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        out = result.stdout
        self.assertIn("main: OK\nnaive: OK\n", out)
        self.assertIn("--- stderr of main ---\ndebug-main n=", out)
        self.assertIn("--- stderr of naive ---\ndebug-naive\n", out)
        self.assertLess(out.index("--- diff"), out.index("--- stderr of main ---"))
        seed = (self.dir / "randtest_fail" / "info.txt").read_text().split()[1]
        replay = self.randtest("-m", "main.cpp", "-n", "naive.cpp", "-g", "gen.cpp",
                               "--replay", seed)
        self.assertIn("--- stderr of main ---\ndebug-main n=", replay.stdout)
        self.assertIn("--- stderr of naive ---\n(empty)\n", replay.stdout)

    def test_long_stderr_is_truncated_with_a_pointer(self):
        self.write("main.cpp", solution(
            "for(int i = 0; i < 1000; i++) std::cerr << \"0123456789\\n\"; return 1;"))
        result = self.randtest("-m", "main.cpp", "-n", "naive.cpp", "-g", "gen.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("... (truncated, full text in randtest_fail/err_main.txt)", result.stdout)
        self.assertEqual(len((self.dir / "randtest_fail" / "err_main.txt").read_text()), 11000)

    def test_runtime_error_and_timeout_are_counterexamples(self):
        self.write("re.cpp", solution(
            "if(n == 3) return 7; "
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b << '\\n';"))
        result = self.randtest("re.cpp", "naive.cpp", "gen.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("RE (exit code 7)", result.stdout)

        self.write("tle.cpp", solution(
            "if(n == 3) for(volatile int i = 0;; i++); "
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b << '\\n';"))
        started = time.monotonic()
        result = self.randtest("tle.cpp", "naive.cpp", "gen.cpp", "--timeout", "0.3")
        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("TLE (> 0.3s)", result.stdout)
        self.assertLess(time.monotonic() - started, 60)

    def test_token_and_exact_comparison(self):
        self.write("spaces.cpp", solution(
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b << \"  \\n\\n\";"))
        result = self.randtest("spaces.cpp", "naive.cpp", "gen.cpp", "-c", "20")
        self.assertEqual(result.returncode, 0, result.stderr)
        result = self.randtest("spaces.cpp", "naive.cpp", "gen.cpp", "-c", "20", "--exact")
        self.assertEqual(result.returncode, 1, result.stderr)

    def test_setup_errors(self):
        self.write("main.cpp", "int main( {")
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp")
        self.assertEqual(result.returncode, 2)
        self.assertIn("failed to compile main.cpp", result.stderr)

        self.write("badgen.cpp", "int main() { return 3; }")
        result = self.randtest("naive.cpp", "naive.cpp", "badgen.cpp")
        self.assertEqual(result.returncode, 2)
        self.assertIn("generator failed for seed 0: RE (exit code 3)", result.stderr)

        result = self.randtest("naive.cpp", "naive.cpp", "missing.cpp")
        self.assertEqual(result.returncode, 2)
        self.assertIn("missing.cpp: no such file", result.stderr)

    def test_header_change_triggers_rebuild(self):
        self.write("inc/answer.hpp", "#pragma once\nconstexpr int OFFSET = 0;\n")
        self.write("main.cpp", '#include "answer.hpp"\n' + solution(
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b + OFFSET << '\\n';"))
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp", "-c", "5", "-I", "inc")
        self.assertEqual(result.returncode, 0, result.stderr)
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp", "-c", "5", "-I", "inc")
        self.assertNotIn("compiling", result.stderr)
        time.sleep(0.01)
        self.write("inc/answer.hpp", "#pragma once\nconstexpr int OFFSET = 1;\n")
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp", "-c", "5", "-I", "inc")
        self.assertIn("compiling main.cpp", result.stderr)
        self.assertEqual(result.returncode, 1, result.stderr)

    def test_init_template_and_python_programs(self):
        (self.dir / "gen.cpp").unlink()
        result = self.randtest("--init")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn('#include "random/gen/all.hpp"', (self.dir / "gen.cpp").read_text())
        result = self.randtest("--init")
        self.assertEqual(result.returncode, 2)
        self.assertIn("gen.cpp already exists", result.stderr)

        self.write("echo.py", "import sys\nsys.stdout.write(sys.stdin.read())\n")
        result = self.randtest("echo.py", "echo.py", "gen.cpp", "-c", "3")
        self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == "__main__":
    unittest.main()
