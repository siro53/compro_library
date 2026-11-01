---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "\"\"\"Compile public headers independently and check non-template linkage.\"\
    \"\"\n\nimport concurrent.futures\nfrom pathlib import Path\nimport subprocess\n\
    import tempfile\nimport unittest\n\n\nROOT = Path(__file__).resolve().parents[3]\n\
    TOPICS = (\"data-structure\", \"geometry\", \"graph\", \"math\", \"misc\", \"\
    modint\", \"random\", \"string\")\nFLAGS = [\"g++\", \"-std=c++17\", \"-O2\",\
    \ \"-Wall\", \"-Wextra\", \"-I\", str(ROOT)]\n\n\nclass HeaderTests(unittest.TestCase):\n\
    \    def test_standalone_headers(self):\n        headers = sorted(p for topic\
    \ in TOPICS for p in (ROOT / topic).rglob(\"*.hpp\"))\n\n        def compile_header(path):\n\
    \            source = f'#include \"{path.relative_to(ROOT)}\"\\nint main() {{}}\\\
    n'\n            result = subprocess.run(\n                FLAGS + [\"-x\", \"\
    c++\", \"-fsyntax-only\", \"-\"],\n                input=source, text=True, capture_output=True,\
    \ check=False,\n            )\n            return path, result\n\n        with\
    \ concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:\n            for\
    \ path, result in pool.map(compile_header, headers):\n                with self.subTest(header=path.relative_to(ROOT)):\n\
    \                    self.assertEqual(result.returncode, 0, result.stderr)\n\n\
    \    def test_public_template_methods(self):\n        source = '''\n#include \"\
    data-structure/slope-trick.hpp\"\n#include \"data-structure/utils/sum_count_manager.hpp\"\
    \n#include \"math/F2.hpp\"\n#include \"math/matrix.hpp\"\nint main() {\n    SlopeTrick<int>\
    \ slope;\n    slope.get_min_lr();\n    slope.eval(0);\n    SumCountManager<int>\
    \ manager(std::vector<int>{1});\n    manager.add(1);\n    BitMatrix<2> mat(2,\
    \ 2);\n    mat.row_reduction();\n    Matrix<int> a(2);\n    a.pow(2);\n}\n'''\n\
    \        result = subprocess.run(\n            FLAGS + [\"-x\", \"c++\", \"-fsyntax-only\"\
    , \"-\"],\n            input=source, text=True, capture_output=True, check=False,\n\
    \        )\n        self.assertEqual(result.returncode, 0, result.stderr)\n\n\
    \    def test_multiple_translation_units(self):\n        with tempfile.TemporaryDirectory()\
    \ as directory:\n            tmp = Path(directory)\n            for header in\
    \ (\"string/z-algo.hpp\", \"misc/rle.hpp\"):\n                with self.subTest(header=header):\n\
    \                    a, b = tmp / \"a.cpp\", tmp / \"b.cpp\"\n               \
    \     a.write_text(f'#include \"{header}\"\\nint main() {{}}\\n')\n          \
    \          b.write_text(f'#include \"{header}\"\\n')\n                    result\
    \ = subprocess.run(\n                        FLAGS + [str(a), str(b), \"-o\",\
    \ str(tmp / \"linked\")],\n                        text=True, capture_output=True,\
    \ check=False,\n                    )\n                    self.assertEqual(result.returncode,\
    \ 0, result.stderr)\n\n\nif __name__ == \"__main__\":\n    unittest.main()\n"
  dependsOn: []
  isVerificationFile: false
  path: test/mytest/headers/test_headers.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/mytest/headers/test_headers.py
layout: document
redirect_from:
- /library/test/mytest/headers/test_headers.py
- /library/test/mytest/headers/test_headers.py.html
title: test/mytest/headers/test_headers.py
---
