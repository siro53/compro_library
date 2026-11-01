"""Apply small, version-checked compatibility fixes to the CI virtual environment.

Keep these replacements scoped to the pinned tools; do not filter compiler output.
A dependency update must review these patches instead of silently skipping them.
"""

from importlib.metadata import distribution
from pathlib import Path


VERSIONS = {
    "online-judge-verify-helper": "5.6.0",
    "online-judge-tools": "11.5.1",
    "online-judge-api-client": "10.10.1",
}

# (distribution, installed path, old source, replacement)
PATCHES = []
for filename, argument in [("main.py", "_CONFIG_YML_PATH"), ("build.py", "path")]:
    path = "onlinejudge_verify/documentation/" + filename
    PATCHES.extend([
        ("online-judge-verify-helper", path,
         "import pkg_resources", "from importlib.resources import files as resource_files"),
        ("online-judge-verify-helper", path,
         f"pkg_resources.resource_string(_RESOURCE_PACKAGE, {argument})",
         f"resource_files(_RESOURCE_PACKAGE).joinpath({argument}).read_bytes()"),
    ])
PATCHES.extend([
    ("online-judge-verify-helper", "onlinejudge_verify/documentation/configure.py",
     "    return _find_matched_file_paths(pred, basedir=basedir)",
     """    # Apply documentation exclusions before dependency analysis, not only rendering.
    from onlinejudge_verify.documentation.main import load_render_config
    config = load_render_config(basedir=basedir)
    excluded = list(map(pathlib.Path, config.config_yml.get('exclude', [])))
    return [path for path in _find_matched_file_paths(pred, basedir=basedir)
            if not is_excluded(path.relative_to(basedir), excluded_paths=excluded)]"""),
    ("online-judge-verify-helper", "onlinejudge_verify/main.py",
     "subprocess.run(['git', 'ls-files', '--error-unmatch', str(gitignore_path)], check=False).returncode == 0",
     "bool(subprocess.check_output(['git', 'ls-files', '--', str(gitignore_path)]).strip())"),
    # This invocation only strips comments, with preprocessor directives deliberately
    # left unevaluated. Its macro/pragma warnings are artifacts of -fpreprocessed.
    # -w is limited to this invocation; real compilation retains -Wall/-Wextra.
    ("online-judge-verify-helper", "onlinejudge_verify/languages/cplusplus_bundle.py",
     "'-fpreprocessed', '-dD', '-E'", "'-fpreprocessed', '-dD', '-E', '-w'"),
    ("online-judge-api-client", "onlinejudge/service/library_checker.py",
     "        if compile_checker:\n            command.append('--compile-checker')",
     "        # Current Library Checker generate.py always compiles its checker."),
    ("online-judge-tools", "onlinejudge_command/update_checking.py",
     "if time.time() < cache[package_name]['time'] + update_interval:",
     "if package_name in cache and time.time() < cache[package_name]['time'] + update_interval:"),
])


def main():
    packages = {name: distribution(name) for name in VERSIONS}
    for name, package in packages.items():
        if package.version != VERSIONS[name]:
            raise RuntimeError(f"Review patches for {name} {package.version}")
    pending = {}
    for name, relative_path, old, new in PATCHES:
        path = Path(packages[name].locate_file(relative_path))
        source = pending.get(path, path.read_text())
        # configure.py has two identical returns (source and Markdown discovery).
        expected = 2 if relative_path.endswith('/configure.py') else 1
        if source.count(new) == expected:
            pending[path] = source  # safe to rerun after installation
        elif source.count(old) == expected:
            pending[path] = source.replace(old, new)
        else:
            raise RuntimeError(f"Unexpected source in {path}: {old!r}")
    # Validate every patch before writing anything.
    for path, source in pending.items():
        compile(source, str(path), 'exec')
    for path, source in pending.items():
        path.write_text(source)
    print(f"Applied verifier compatibility fixes to {len(pending)} files")


if __name__ == '__main__':
    main()
