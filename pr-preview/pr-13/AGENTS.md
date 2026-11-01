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

## Documentation Requirements

Every new library file MUST include its documentation in the same change. Do not consider a new library complete until its documentation is written and checked. This applies to small helpers, monoids, and aggregate headers as well as standalone algorithms. Update the corresponding documentation whenever an existing API, behavior, complexity, or precondition changes.

Create one Markdown page at the matching path under `docs/`, replacing the source extension with `.md`. For example, `data-structure/example.hpp` must have `docs/data-structure/example.md`. Set `documentation_of` to the exact source path prefixed with `//`, and add the page to `docs/index.md` (create the index if it does not exist).

Write natural Japanese prose, prioritizing both readability and mathematical precision. Use the following sections in this order; the API table supplements the explanation rather than replacing it:

````markdown
---
title: ライブラリ名
documentation_of: //data-structure/example.hpp
---

## このライブラリでできること

用途、解決できる問題、構造体・クラスの役割、基本的な考え方を説明します。

## 使い方

初期化から操作・結果の取得までの流れと、使用例で何が起きるかを説明します。

```cpp
// 必要な include と main を含む、実際の API を使った実行可能な C++17 の例
```

## API・計算量

計算量に用いる変数と、必要な空間・追加領域を説明します。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `実際のシグネチャ` | 引数・操作・返り値の意味 | 前提を明示した計算量 |

## 利用条件と実装上の注意

入力範囲、添字・区間の規約、数学的な成立条件、実装上の制約を説明します。
````

- Explain constructors, public methods and overloads, and user-facing types and members. State initialization and call-order requirements, mutation or consumption of state, return values, and behavior for empty inputs or missing results where applicable.
- Define symbols before using formulas. State algebraic requirements, such as associativity, identity elements, and composition order, when relevant. Distinguish mathematical definitions from finite-integer arithmetic, floating-point tolerances, and the current implementation's limitations.
- Derive complexity from the actual implementation. Separate preprocessing from queries, worst-case from amortized or expected bounds, and operation costs from user-supplied callback or type-operation costs. Document space usage, including persistent allocations and recursion when relevant.
- Explain examples in prose and show expected results using assertions or output. Compile and run new or changed executable examples with the repository's C++17 flags. Do not present pseudocode or code affected by a known defect as a verified working example; label it explicitly and explain the limitation.
- Keep code examples compatible with Jekyll's Liquid processing, which runs even inside Markdown code fences. Separate adjacent opening braces in nested C++ initializer lists with whitespace so they are not interpreted as Liquid expressions. Check both compilation and documentation rendering when changing such examples; compiling C++ alone does not validate the published page.
- Keep these four main sections even for small utilities, scaling their length to the topic. Add proofs or further explanations after them when useful. If external articles or implementations inform the explanation, cite them in a final `参考資料` section and distinguish their interfaces or assumptions from this library's. Do not copy their prose verbatim.
- Before completing the change, check source-to-document coverage, front matter, links, formulas, API consistency, and example behavior. An API table or a list of signatures alone is not sufficient documentation.

## Testing Guidelines

Every new algorithm or bug fix should have a focused `*.test.cpp` verifier. Begin judge-backed tests with `#define PROBLEM "https://..."`, include `template/template.cpp` and the target header through relative paths, and keep the program limited to adapting the library API to the judge input/output. Add custom regression cases under `test/mytest/` when no suitable online judge problem exists. There is no stated coverage percentage; passing `oj-verify all` is the acceptance baseline.

## Commit & Pull Request Guidelines

Use a concise imperative subject, preferably with the history's prefixes: `feat:`, `fix:`, or `docs:`. Do not imitate `[auto-verifier]` commits; automation creates those. Pull requests should explain the algorithm or defect, identify complexity or behavioral changes, link relevant problems/issues, and list verification performed. Include updated documentation and tests with API changes; screenshots are unnecessary unless rendered documentation is affected.
