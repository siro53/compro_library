"""Regression tests for the pinned verifier's compatibility fixes."""
import importlib.util
import json
import sys
from pathlib import Path
import subprocess
import tempfile
import time
import unittest
from unittest.mock import patch

from onlinejudge.service.library_checker import LibraryCheckerProblem, LibraryCheckerService
from onlinejudge_command import update_checking
from onlinejudge_verify.documentation import configure
from onlinejudge_verify.documentation.main import load_render_config
from onlinejudge_verify.documentation.build import load_static_files

ROOT = Path(__file__).resolve().parents[3]


class VerifierTests(unittest.TestCase):
    def test_patches_are_idempotent(self):
        spec = importlib.util.spec_from_file_location('patch_dependencies', ROOT / '.verify-helper/patch_dependencies.py')
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        paths = {Path(module.distribution(name).locate_file(path))
                 for name, path, _, _ in module.PATCHES}
        before = {p: p.read_bytes() for p in paths}
        subprocess.run([sys.executable, str(ROOT / '.verify-helper/patch_dependencies.py')], check=True)
        self.assertEqual(before, {p: p.read_bytes() for p in paths})

    def test_excluded_tools_are_not_analyzed(self):
        paths = {p.relative_to(ROOT) for p in configure._find_source_code_paths(basedir=ROOT)}
        self.assertIn(Path('data-structure/monoid/rolling_hash.hpp'), paths)
        self.assertIn(Path('test/mytest/data-structure/monoids.test.cpp'), paths)
        for prefix in ('scripts', 'test/mytest/bundle', 'test/mytest/headers', 'test/mytest/ci'):
            self.assertFalse(any(p == Path(prefix) or Path(prefix) in p.parents for p in paths))

    def test_packaged_resources(self):
        config = load_render_config(basedir=ROOT)
        resources = load_static_files(site_render_config=config)
        self.assertIn(config.destination_dir / '_config.yml', resources)
        self.assertTrue(any(p.name == 'Gemfile' for p in resources))

    def test_missing_package_in_update_cache(self):
        with tempfile.TemporaryDirectory() as directory:
            cache = Path(directory)
            (cache / 'pypi.json').write_text(json.dumps({'other': {'time': time.time(), 'version': '1.0.0'}}))
            with patch.object(update_checking, 'user_cache_dir', cache), \
                 patch.object(update_checking, 'request') as request, \
                 patch.object(update_checking.logger, 'warning') as warning:
                request.return_value.content = b'{"info": {"version": "2.0.0"}}'
                self.assertEqual(update_checking.get_latest_version_from_pypi('new'), '2.0.0')
                self.assertEqual(update_checking.get_latest_version_from_pypi('new'), '2.0.0')
                request.assert_called_once()
                warning.assert_not_called()

    def test_checker_uses_current_cli(self):
        problem = LibraryCheckerProblem(problem_id='aplusb')
        with patch.object(LibraryCheckerService, '_update_cloned_repository'), \
             patch.object(LibraryCheckerService, '_get_cloned_repository_path', return_value=Path('/tmp/checker')), \
             patch.object(LibraryCheckerProblem, '_get_problem_directory_path', return_value=Path('/tmp/checker/aplusb')), \
             patch('onlinejudge.service.library_checker.subprocess.check_call') as call:
            problem._generate_test_cases_in_cloned_repository(compile_checker=True)
            self.assertNotIn('--compile-checker', call.call_args.args[0])

    def test_bundle_preprocessing_is_quiet_and_errors_survive(self):
        for source in ('template/template.cpp', 'data-structure/monoid/rolling_hash.hpp'):
            result = subprocess.run(['oj-bundle', source], cwd=ROOT, capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr.decode())
            self.assertNotIn(b'warning:', result.stderr)
        result = subprocess.run(['oj-bundle', 'missing-file.cpp'], cwd=ROOT, capture_output=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertTrue(result.stderr)


if __name__ == '__main__':
    unittest.main()
