# Repository Guidelines

## Project Structure & Module Organization

This repository is a header-oriented C++17 library for competitive programming. Algorithms are grouped by topic at the repository root: `data-structure/`, `graph/`, `math/`, `string/`, `geometry/`, `misc/`, `modint/`, and `random/`. Shared contest boilerplate lives in `template/template.cpp`.

Place user-facing documentation under the matching path in `docs/`; for example, `data-structure/segtree/lazy-segtree.hpp` is documented by `docs/data-structure/segtree/lazy-segtree.md`. Verification programs live in `test/`, organized by judge (`library-checker/`, `aoj/`, `yukicoder/`) and then by topic where useful.

## Build, Test, and Development Commands

The project has no separate build step. Install the verifier once:

```sh
pip3 install -U online-judge-verify-helper
```

Run the same full verification suite used by CI:

```sh
oj-verify all
```

The verifier compiles tests with `g++ -std=c++17 -O2 -Wall -Wextra`, as configured in `.verify-helper/config.toml`, and obtains judge cases from each test's `PROBLEM` URL. Run `oj-verify run test/path/to/example.test.cpp` while iterating on one implementation.

## Coding Style & Naming Conventions

Use C++17, four-space indentation, and `#pragma once` in library headers. Keep implementations self-contained and include standard headers explicitly. Follow existing naming: kebab-case filenames such as `rolling-hash.hpp`, lowercase function names, and type names matching nearby APIs (for example, `UnionFind`). Preserve each module's established interface style instead of introducing broad formatting changes. Documentation files should include `title` and `documentation_of` front matter.

## Testing Guidelines

Every new algorithm or bug fix should have a focused `*.test.cpp` verifier. Begin judge-backed tests with `#define PROBLEM "https://..."`, include `template/template.cpp` and the target header through relative paths, and keep the program limited to adapting the library API to the judge input/output. Add custom regression cases under `test/mytest/` when no suitable online judge problem exists. There is no stated coverage percentage; passing `oj-verify all` is the acceptance baseline.

## Commit & Pull Request Guidelines

Use a concise imperative subject, preferably with the history's prefixes: `feat:`, `fix:`, or `docs:`. Do not imitate `[auto-verifier]` commits; automation creates those. Pull requests should explain the algorithm or defect, identify complexity or behavioral changes, link relevant problems/issues, and list verification performed. Include updated documentation and tests with API changes; screenshots are unnecessary unless rendered documentation is affected.
