---
title: 2-SAT
documentation_of: //math/two_sat.hpp
---

## 概要

`TwoSat<Cost=int>` は N 個の bool 変数について 2 リテラル節の充足可能性を SCC で判定する。Q は節数。

空間 O(N+Q)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `TwoSat(N)` | 変数 N 個で初期化。 | O(N) |
| `add_clause(i, fi, j, fj)` | (x[i]==fi) OR (x[j]==fj) を追加。 | 償却 O(1) |
| `satisfiable()` | 充足可能なら true、割当を保存。 | O(N+Q) |
| `get_answer()` | 成功時の割当 vector<bool> をコピーして返す。 | O(N) |

## 前提・注意点

変数番号は `[0,N)`。節を全て追加後、satisfiable は一度だけ呼ぶ。判定後の節追加・再判定は不可。get_answer は satisfiable が true を返した後だけ使う。デフォルト構築は内部 SCC を構築できないため利用不可。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/two_sat.hpp"

int main() {
    TwoSat<> sat(2);
    sat.add_clause(0, true, 0, true);
    sat.add_clause(0, false, 1, true);
    assert(sat.satisfiable());
    auto ans = sat.get_answer();
    assert(ans[0] && ans[1]);
}
```
