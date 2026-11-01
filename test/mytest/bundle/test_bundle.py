"""Snapshot tests using the installed oj-bundle (and its C++ compiler)."""

from pathlib import Path
import subprocess
import sys
import unittest


TEST_DIR = Path(__file__).resolve().parent
BUNDLE_SCRIPT = TEST_DIR.parents[2] / "scripts" / "bundle.py"


class BundleSnapshotTest(unittest.TestCase):
    maxDiff = None

    def run_bundle(self, *args):
        return subprocess.run(
            [sys.executable, str(BUNDLE_SCRIPT), *args],
            cwd=TEST_DIR / "fixtures",
            capture_output=True,
            timeout=30,
        )

    def assert_snapshot(self, name, *args):
        result = self.run_bundle(*args)
        self.assertEqual(result.returncode, 0, result.stderr.decode())
        expected = (TEST_DIR / "snapshots" / name).read_bytes()
        self.assertEqual(result.stdout.decode(), expected.decode())

    def test_plain(self):
        self.assert_snapshot("plain.cpp", "plain.cpp")

    def test_nested_and_duplicate_includes(self):
        self.assert_snapshot("includes.cpp", "includes.cpp", "-I", "include")

    def test_failure_has_no_output(self):
        result = self.run_bundle("missing.cpp")
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(result.stdout, b"")


if __name__ == "__main__":
    unittest.main()
