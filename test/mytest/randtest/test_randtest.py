"""Behavior tests for scripts/randtest.py."""

import importlib.util
import json
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
                        "specifying files:", "comparison:", "generator:", "counterexample:",
                        "exit status:", "examples:", "help language:"):
            self.assertIn(heading, english.stdout)
        for heading in ("使い方: randtest -m MAIN -n NAIVE -g GEN", "ファイル:", "実行:",
                        "ファイルの指定:", "比較方法:", "生成器:", "反例:", "終了コード:", "使用例:",
                        "ヘルプの言語:"):
            self.assertIn(heading, japanese.stdout)
        for option in ("--main", "--naive", "--gen", "--count", "--start", "--time",
                       "--timeout", "--replay", "--exact", "--out", "--cxx", "--cxxflags",
                       "-I DIR", "--init", "--help-ja", "--help-en", "--float EPS",
                       "--checker CHECKER", "--no-exact"):
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

    MAX_SOLUTION = ("long long b = a[0]; for(auto x : a) if(x > b) b = x; "
                    "std::cout << b << '\\n';")

    def write_config(self, data):
        text = data if isinstance(data, str) else json.dumps(data)
        self.write("randtest.json", text)

    def test_config_supplies_defaults(self):
        self.write("main.cpp", solution(self.MAX_SOLUTION))
        self.write_config({"main": "main.cpp", "naive": "naive.cpp", "gen": "gen.cpp",
                           "count": 7, "start": 3, "timeout": 5, "time": None})
        result = self.randtest()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("all 7 cases passed (seeds 3..9", result.stdout)
        self.assertIn("randtest: using settings in randtest.json", result.stderr)

        # command-line options and positional files take precedence
        result = self.randtest("-c", "2", "--start", "0")
        self.assertIn("all 2 cases passed (seeds 0..1", result.stdout)
        self.write_config({"main": "missing.cpp", "naive": "missing.cpp", "gen": "gen.cpp",
                           "count": 2})
        result = self.randtest("main.cpp", "naive.cpp")
        self.assertEqual(result.returncode, 0, result.stderr)
        result = self.randtest("-n", "naive.cpp", "main.cpp")  # FILE fills MAIN
        self.assertEqual(result.returncode, 0, result.stderr)
        result = self.randtest("-m", "main.cpp")
        self.assertEqual(result.returncode, 2)
        self.assertIn("missing.cpp: no such file", result.stderr)

    def test_config_exact_include_and_time(self):
        self.write("spaces.cpp", solution(
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b << \"  \\n\";"))
        self.write("inc/a.hpp", "#pragma once\nconstexpr int A = 0;\n")
        self.write("inc2/b.hpp", "#pragma once\nconstexpr int B = 0;\n")
        self.write("both.cpp", '#include "a.hpp"\n#include "b.hpp"\n' + solution(
            "long long b = a[0]; for(auto x : a) if(x > b) b = x; std::cout << b + A + B << '\\n';"))
        self.write_config({"naive": "naive.cpp", "gen": "gen.cpp", "count": 5,
                           "exact": True, "include": ["inc"], "time": 0})
        self.assertEqual(self.randtest("-m", "spaces.cpp").returncode, 1)
        self.assertEqual(self.randtest("-m", "spaces.cpp", "--no-exact").returncode, 0)
        # -I adds to "include"
        result = self.randtest("-m", "both.cpp", "-I", "inc2")
        self.assertEqual(result.returncode, 0, result.stderr)
        result = self.randtest("-m", "both.cpp")
        self.assertEqual(result.returncode, 2)
        self.assertIn("b.hpp", result.stderr)

    def test_config_errors(self):
        for text, message in (
            ("{", "randtest.json: invalid JSON"),
            ("[]", "randtest.json: the top level must be an object"),
            ('{"cout": 5}', 'randtest.json: unknown key "cout"'),
            ('{"count": "5"}', 'randtest.json: "count" must be an integer'),
            ('{"count": true}', 'randtest.json: "count" must be an integer'),
            ('{"exact": 1}', 'randtest.json: "exact" must be true or false'),
            ('{"include": "inc"}', 'randtest.json: "include" must be a list of strings'),
            ('{"timeout": 0}', "--timeout must be positive"),
        ):
            with self.subTest(text=text):
                self.write_config(text)
                result = self.randtest("main.cpp", "naive.cpp", "gen.cpp")
                self.assertEqual(result.returncode, 2)
                self.assertIn(message, result.stderr)
        # help is still available with a broken settings file
        self.write_config("{")
        self.assertEqual(self.randtest("-h").returncode, 0)

    def test_init_ignores_files_in_config(self):
        self.write_config({"main": "main.cpp", "naive": "naive.cpp", "gen": "gen.cpp"})
        result = self.randtest("--init", "gen2.cpp")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout, "wrote gen2.cpp\n")
        self.assertFalse((self.dir / ".randtest").exists())

    def load_module(self):
        spec = importlib.util.spec_from_file_location("randtest", SCRIPT)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        return module

    def test_tokens_match_with_tolerance(self):
        match = self.load_module().tokens_match
        for x, y, eps, expected in (
            (b"1.0000001", b"1", 1e-6, True),     # absolute error
            (b"1000000.5", b"1000000", 1e-6, True),  # relative error
            (b"1.01", b"1", 1e-6, False),
            (b"1", b"1.0", 1e-6, True),           # integer vs real
            (b"1000001", b"1000000", 1e-6, False),  # both integers: exact
            (b"-0.0000000", b"0", 1e-6, True),
            (b"1e-7", b"0", 1e-6, True),
            (b"inf", b"inf", 1e-6, True),
            (b"nan", b"nan", 1e-6, True),          # same token
            (b"nan", b"0", 1e-6, False),
            (b"Yes", b"yes", 1e-6, False),
            (b"1.0000001", b"1", None, False),     # no tolerance
            (b"1.0", b"1.0", 0.0, True),
            (b"1.00", b"1.0", 0.0, True),
        ):
            with self.subTest(x=x, y=y, eps=eps):
                self.assertEqual(match(x, y, eps), expected)

    def test_float_option(self):
        self.write("avg_naive.cpp", solution(
            "long double s = 0; for(auto x : a) s += x; printf(\"%.12Lf\\n\", s / n);"))
        self.write("avg_close.cpp", solution(
            "double s = 0; for(auto x : a) s += x; printf(\"%.9f\\n\", s / n * (1 + 1e-8));"))
        self.write("avg_floor.cpp", solution(
            "long long s = 0; for(auto x : a) s += x; printf(\"%lld\\n\", s / n);"))
        # average of [-5, 6) values is often not an integer
        result = self.randtest("-m", "avg_close.cpp", "-n", "avg_naive.cpp", "-g", "gen.cpp",
                               "-c", "50", "--float", "1e-6")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        result = self.randtest("-m", "avg_close.cpp", "-n", "avg_naive.cpp", "-g", "gen.cpp",
                               "-c", "50")
        self.assertEqual(result.returncode, 1)
        result = self.randtest("-m", "avg_floor.cpp", "-n", "avg_naive.cpp", "-g", "gen.cpp",
                               "--float", "1e-6")
        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("first difference: token 1: main ", result.stdout)
        info = (self.dir / "randtest_fail" / "info.txt").read_text()
        self.assertIn("--float 1e-06 --replay", info)
        self.assertIn("first difference: token 1", info)

    def checker_setup(self):
        # output any index of a maximum element; the checker uses the naive answer if any
        self.write("gen.cpp", GEN.replace("rng.randint(-5, 6)", "rng.randint(0, 3)"))
        self.write("argmax_naive.cpp", solution(
            "int k = 0; for(int i = 0; i < n; i++) if(a[i] > a[k]) k = i; "
            "std::cout << k + 1 << '\\n';"))
        self.write("argmax_last.cpp", solution(
            "int k = 0; for(int i = 0; i < n; i++) if(a[i] >= a[k]) k = i; "
            "std::cout << k + 1 << '\\n';"))
        self.write("argmax_bad.cpp", solution("std::cout << n << '\\n';"))
        self.write("check.cpp", textwrap.dedent("""\
            #include <fstream>
            #include <iostream>
            #include <vector>
            int main(int argc, char **argv) {
                if(argc != 4) return 3;
                std::ifstream in(argv[1]), out(argv[2]), ans(argv[3]);
                int n; in >> n;
                std::vector<long long> a(n);
                for(auto &x : a) in >> x;
                long long best = a[0];
                for(auto x : a) if(x > best) best = x;
                int expected;
                if(ans >> expected && a[expected - 1] != best) return 3;
                int k;
                if(!(out >> k) || k < 1 || k > n) { std::cout << "invalid index\\n"; return 1; }
                if(a[k - 1] != best) { std::cout << "not maximum: " << k << "\\n"; return 1; }
                std::cerr << "checked\\n";
            }
            """))

    def test_checker_accepts_any_correct_answer(self):
        self.checker_setup()
        result = self.randtest("-m", "argmax_last.cpp", "-n", "argmax_naive.cpp", "-g", "gen.cpp")
        self.assertEqual(result.returncode, 1)  # plain comparison rejects other answers
        for args in (
            ["-m", "argmax_last.cpp", "-n", "argmax_naive.cpp", "-g", "gen.cpp",
             "--checker", "check.cpp"],
            ["-m", "argmax_last.cpp", "-g", "gen.cpp", "--checker", "check.cpp"],
            ["argmax_last.cpp", "gen.cpp", "--checker", "check.cpp"],  # FILEs: MAIN, GEN
            ["argmax_last.cpp", "argmax_naive.cpp", "gen.cpp", "--checker", "check.cpp"],
        ):
            with self.subTest(args=args):
                result = self.randtest(*args, "-c", "50")
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertIn("all 50 cases passed", result.stdout)

    def test_checker_rejection_is_reported(self):
        self.checker_setup()
        result = self.randtest("-m", "argmax_bad.cpp", "-g", "gen.cpp", "--checker", "check.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("--- output of main ---", result.stdout)
        self.assertRegex(result.stdout, r"checker: rejected \(exit code 1\)\n"
                                        r"--- checker message ---\n(not maximum|invalid index)")
        self.assertIn("(logs: stderr_main.log, checker.log)", result.stdout)
        fail = self.dir / "randtest_fail"
        self.assertFalse((fail / "out_naive.txt").exists())
        self.assertIn("not maximum", (fail / "checker.log").read_text())
        info = (fail / "info.txt").read_text()
        self.assertIn("checker: check.cpp rejected (exit code 1)", info)
        self.assertIn("--checker check.cpp --replay", info)
        seed = info.split()[1]
        replay = self.randtest("-m", "argmax_bad.cpp", "-g", "gen.cpp", "--checker", "check.cpp",
                               "--replay", seed)
        self.assertEqual(replay.returncode, 1)
        self.assertIn("checker: rejected", replay.stdout)
        replay = self.randtest("-m", "argmax_naive.cpp", "-g", "gen.cpp", "--checker",
                               "check.cpp", "--replay", seed)
        self.assertEqual(replay.returncode, 0)
        self.assertIn("checker: accepted\n--- checker message ---\nchecked", replay.stdout)

        # a crashing or slow checker rejects too
        self.write("crash.py", "import os\nos.abort()\n")
        result = self.randtest("-m", "argmax_naive.cpp", "-g", "gen.cpp", "--checker", "crash.py")
        self.assertIn("checker: crashed (signal 6)", result.stdout)
        self.write("slow.py", "while True:\n    pass\n")
        result = self.randtest("-m", "argmax_naive.cpp", "-g", "gen.cpp", "--checker", "slow.py",
                               "--timeout", "0.5")
        self.assertIn("checker: TLE (> 0.5s)", result.stdout)
        # MAIN failing to run is reported without calling the checker
        self.write("re.cpp", solution("return 4;"))
        result = self.randtest("-m", "re.cpp", "-g", "gen.cpp", "--checker", "crash.py")
        self.assertIn("main: RE (exit code 4)", result.stdout)
        self.assertNotIn("checker:", result.stdout)

    def test_init_writes_a_working_checker_template(self):
        (self.dir / "gen.cpp").unlink()
        result = self.randtest("--init", "--checker", "check.cpp")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout, "wrote gen.cpp\nwrote check.cpp\n")
        self.assertIn("exit(1)", (self.dir / "check.cpp").read_text())
        # the two templates work together: print the index of a maximum
        self.write("first_max.cpp", solution(
            "int k = 0; for(int i = 0; i < n; i++) if(a[i] > a[k]) k = i; "
            "std::cout << k + 1 << '\\n';"))
        self.write("last_max.cpp", solution(
            "int k = 0; for(int i = 0; i < n; i++) if(a[i] >= a[k]) k = i; "
            "std::cout << k + 1 << '\\n';"))
        self.write("skip_last.cpp", solution(
            "int k = 0; for(int i = 0; i + 1 < n; i++) if(a[i] > a[k]) k = i; "
            "std::cout << k + 1 << '\\n';"))
        self.write("extra.cpp", solution(
            "int k = 0; for(int i = 0; i < n; i++) if(a[i] > a[k]) k = i; "
            "std::cout << k + 1 << \" 0\\n\";"))
        result = self.randtest("last_max.cpp", "gen.cpp", "--checker", "check.cpp", "-c", "100")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        result = self.randtest("-m", "last_max.cpp", "-n", "first_max.cpp", "-g", "gen.cpp",
                               "--checker", "check.cpp", "-c", "100")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        result = self.randtest("skip_last.cpp", "gen.cpp", "--checker", "check.cpp")
        self.assertEqual(result.returncode, 1)
        self.assertRegex(result.stdout, r"checker: rejected \(exit code 1\)\n"
                                        r"--- checker message ---\na\[\d+\] = \d+ is not the maximum")
        result = self.randtest("extra.cpp", "gen.cpp", "--checker", "check.cpp")
        self.assertEqual(result.returncode, 1)
        self.assertIn("extra output: 0", result.stdout)

    def test_init_keeps_existing_files(self):
        self.write("check.cpp", "// mine\n")
        result = self.randtest("--init", "--checker", "check.cpp")  # gen.cpp exists too
        self.assertEqual(result.returncode, 2)
        self.assertIn("gen.cpp already exists, kept it", result.stderr)
        self.assertIn("check.cpp already exists, kept it", result.stderr)
        self.assertIn("nothing was written", result.stderr)
        result = self.randtest("--init", "gen2.cpp", "--checker", "check.cpp")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout, "wrote gen2.cpp\n")
        self.assertEqual((self.dir / "check.cpp").read_text(), "// mine\n")
        result = self.randtest("--init", "gen3.cpp", "--checker", "check.py")
        self.assertEqual(result.returncode, 2)
        self.assertIn("check.py is not a C++ file", result.stderr)
        self.assertFalse((self.dir / "gen3.cpp").exists())
        # "checker" in the settings file is used as well
        self.write_config({"checker": "c2.cpp"})
        result = self.randtest("--init", "gen4.cpp")
        self.assertEqual(result.stdout, "wrote gen4.cpp\nwrote c2.cpp\n")

    def test_comparison_mode_errors(self):
        for args, message in (
            (["--exact", "--float", "1e-6"], "--exact and --float cannot be combined"),
            (["--exact", "--checker", "c.cpp"], "--exact and --checker cannot be combined"),
            (["--float", "1e-6", "--checker", "c.cpp"], "--float and --checker cannot be combined"),
            (["--float", "-1"], "--float must be a non-negative number"),
            (["--float", "nan"], "--float must be a non-negative number"),
        ):
            with self.subTest(args=args):
                result = self.randtest("main.cpp", "naive.cpp", "gen.cpp", *args)
                self.assertEqual(result.returncode, 2)
                self.assertIn(message, result.stderr)
        result = self.randtest("-m", "main.cpp", "--checker", "c.cpp")
        self.assertIn("missing GEN", result.stderr)
        self.assertNotIn("NAIVE", result.stderr.splitlines()[-1])

    def test_config_float_and_checker(self):
        self.checker_setup()
        self.write_config({"main": "argmax_last.cpp", "gen": "gen.cpp", "checker": "check.cpp",
                           "count": 20})
        result = self.randtest()
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.write_config({"float": "1e-6"})
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp")
        self.assertIn('"float" must be a number or null', result.stderr)
        self.write_config({"float": 1e-6})
        result = self.randtest("main.cpp", "naive.cpp", "gen.cpp", "--exact")
        self.assertIn("--exact and --float cannot be combined (check randtest.json)",
                      result.stderr)

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

    def test_stderr_is_saved_to_log_files_not_printed(self):
        # wrong when every value is negative; prints debug output to stderr
        self.write("main.cpp", solution(
            "long long b = 0; for(auto x : a) if(x > b) b = x; "
            "std::cerr << \"debug-main n=\" << n << '\\n'; std::cout << b << '\\n';"))
        self.write("noisy.cpp", "#include <iostream>\n" + NAIVE.replace(
            "int main() {", "int main() {\n    std::cerr << \"debug-naive\\n\";"))
        fail = self.dir / "randtest_fail"
        self.write("randtest_fail/err_main.txt", "stale file of an older version\n")
        result = self.randtest("-m", "main.cpp", "-n", "noisy.cpp", "-g", "gen.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        for stream in (result.stdout, result.stderr):
            self.assertNotIn("debug-main", stream)
            self.assertNotIn("debug-naive", stream)
        self.assertIn("main: OK\nnaive: OK\n", result.stdout)
        self.assertIn("saved to randtest_fail/ (logs: stderr_main.log, stderr_naive.log)",
                      result.stdout)
        self.assertTrue((fail / "stderr_main.log").read_text().startswith("debug-main n="))
        self.assertEqual((fail / "stderr_naive.log").read_text(), "debug-naive\n")
        self.assertFalse((fail / "err_main.txt").exists())

        # --replay saves the case too; an empty stderr gives an empty log
        seed = (fail / "info.txt").read_text().split()[1]
        replay = self.randtest("-m", "main.cpp", "-n", "naive.cpp", "-g", "gen.cpp",
                               "--replay", seed)
        self.assertEqual(replay.returncode, 1)
        self.assertNotIn("debug-main", replay.stdout)
        self.assertIn("saved to randtest_fail/", replay.stdout)
        self.assertTrue((fail / "stderr_main.log").read_text().startswith("debug-main n="))
        self.assertEqual((fail / "stderr_naive.log").read_bytes(), b"")

    def test_long_stderr_is_saved_in_full(self):
        self.write("main.cpp", solution(
            "for(int i = 0; i < 1000; i++) std::cerr << \"0123456789\\n\"; return 1;"))
        result = self.randtest("-m", "main.cpp", "-n", "naive.cpp", "-g", "gen.cpp")
        self.assertEqual(result.returncode, 1, result.stderr)
        self.assertIn("main: RE (exit code 1)", result.stdout)
        self.assertNotIn("0123456789", result.stdout)
        log = (self.dir / "randtest_fail" / "stderr_main.log").read_text()
        self.assertEqual(log, "0123456789\n" * 1000)

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
