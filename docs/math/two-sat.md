---
title: 2-SAT
documentation_of: //math/two_sat.hpp
---

## このライブラリでできること

`TwoSat` は、bool変数に対する「2つの条件の少なくとも一方が成り立つ」という制約を集め、すべて同時に満たせるかを判定します。変数数を $N$、節の数を $Q$ とすると、判定は $O(N+Q)$ 時間です。

節 $(a\lor b)$ は、含意 $\lnot a\Rightarrow b$ と $\lnot b\Rightarrow a$ に言い換えられます。変数とその否定の含意関係をグラフにし、同じ変数の真偽が同じ強連結成分へ入ってしまうかを調べることで、矛盾を検出します。

## 使い方

`add_clause(i,fi,j,fj)` は $(x_i=fi)\lor(x_j=fj)$ を追加します。真に固定したい変数には、同じリテラルを2回渡せます。

例の最初の節は $x_0$ を真に固定し、次の節 $(\lnot x_0)\lor x_1$ は、その場合に $x_1$ も真であることを要求します。`satisfiable()` が真を返した後、`get_answer()` で条件を満たす割当を取得します。

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

## API・計算量

必要な空間は $O(N+Q)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `TwoSat(N)` | 変数 N 個で初期化。 | O(N) |
| `add_clause(i, fi, j, fj)` | (x[i]==fi) OR (x[j]==fj) を追加。 | 償却 O(1) |
| `satisfiable()` | 充足可能なら true、割当を保存。 | O(N+Q) |
| `get_answer()` | 成功時の割当 vector<bool> をコピーして返す。 | O(N) |

## 利用条件と実装上の注意

変数番号は $[0,N)$ です。すべての節を追加してから判定を一度だけ実行してください。内部のSCCを構築するため、判定後の追加や再判定には対応していません。

`get_answer()` は充足可能と判定された後にだけ呼べます。割当が複数ある場合は、そのうち1つを返します。デフォルトコンストラクタは内部SCCを構築できないため、変数数を指定してください。
