"""Compile public headers independently and check non-template linkage."""

import concurrent.futures
from pathlib import Path
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[3]
TOPICS = ("data-structure", "geometry", "graph", "math", "misc", "modint", "random", "string")
FLAGS = ["g++", "-std=c++17", "-O2", "-Wall", "-Wextra", "-Werror", "-I", str(ROOT)]


class HeaderTests(unittest.TestCase):
    def test_standalone_headers(self):
        headers = sorted(p for topic in TOPICS for p in (ROOT / topic).rglob("*.hpp"))

        def compile_header(path):
            source = f'#include "{path.relative_to(ROOT)}"\nint main() {{}}\n'
            result = subprocess.run(
                FLAGS + ["-x", "c++", "-fsyntax-only", "-"],
                input=source, text=True, capture_output=True, check=False,
            )
            return path, result

        with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
            for path, result in pool.map(compile_header, headers):
                with self.subTest(header=path.relative_to(ROOT)):
                    self.assertEqual(result.returncode, 0, result.stderr)

    def test_public_template_methods(self):
        source = '''
#include "data-structure/slope-trick.hpp"
#include "data-structure/utils/sum_count_manager.hpp"
#include "math/F2.hpp"
#include "math/matrix.hpp"
int main() {
    SlopeTrick<int> slope;
    slope.get_min_lr();
    slope.eval(0);
    SumCountManager<int> manager(std::vector<int>{1});
    manager.add(1);
    BitMatrix<2> mat(2, 2);
    mat.row_reduction();
    Matrix<int> a(2);
    a.pow(2);
}
'''
        result = subprocess.run(
            FLAGS + ["-x", "c++", "-fsyntax-only", "-"],
            input=source, text=True, capture_output=True, check=False,
        )
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_multiple_translation_units(self):
        with tempfile.TemporaryDirectory() as directory:
            tmp = Path(directory)
            for header in ("string/z-algo.hpp", "misc/rle.hpp"):
                with self.subTest(header=header):
                    a, b = tmp / "a.cpp", tmp / "b.cpp"
                    a.write_text(f'#include "{header}"\nint main() {{}}\n')
                    b.write_text(f'#include "{header}"\n')
                    result = subprocess.run(
                        FLAGS + [str(a), str(b), "-o", str(tmp / "linked")],
                        text=True, capture_output=True, check=False,
                    )
                    self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == "__main__":
    unittest.main()
