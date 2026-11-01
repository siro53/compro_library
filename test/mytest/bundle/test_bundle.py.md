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
  code: "\"\"\"Snapshot tests using the installed oj-bundle (and its C++ compiler).\"\
    \"\"\n\nfrom pathlib import Path\nimport subprocess\nimport sys\nimport unittest\n\
    \n\nTEST_DIR = Path(__file__).resolve().parent\nBUNDLE_SCRIPT = TEST_DIR.parents[2]\
    \ / \"scripts\" / \"bundle.py\"\n\n\nclass BundleSnapshotTest(unittest.TestCase):\n\
    \    maxDiff = None\n\n    def run_bundle(self, *args):\n        return subprocess.run(\n\
    \            [sys.executable, str(BUNDLE_SCRIPT), *args],\n            cwd=TEST_DIR\
    \ / \"fixtures\",\n            capture_output=True,\n            timeout=30,\n\
    \        )\n\n    def assert_snapshot(self, name, *args):\n        result = self.run_bundle(*args)\n\
    \        self.assertEqual(result.returncode, 0, result.stderr.decode())\n    \
    \    expected = (TEST_DIR / \"snapshots\" / name).read_bytes()\n        self.assertEqual(result.stdout.decode(),\
    \ expected.decode())\n\n    def test_plain(self):\n        self.assert_snapshot(\"\
    plain.cpp\", \"plain.cpp\")\n\n    def test_nested_and_duplicate_includes(self):\n\
    \        self.assert_snapshot(\"includes.cpp\", \"includes.cpp\", \"-I\", \"include\"\
    )\n\n    def test_failure_has_no_output(self):\n        result = self.run_bundle(\"\
    missing.cpp\")\n        self.assertNotEqual(result.returncode, 0)\n        self.assertEqual(result.stdout,\
    \ b\"\")\n\n\nif __name__ == \"__main__\":\n    unittest.main()\n"
  dependsOn: []
  isVerificationFile: false
  path: test/mytest/bundle/test_bundle.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/mytest/bundle/test_bundle.py
layout: document
redirect_from:
- /library/test/mytest/bundle/test_bundle.py
- /library/test/mytest/bundle/test_bundle.py.html
title: test/mytest/bundle/test_bundle.py
---
