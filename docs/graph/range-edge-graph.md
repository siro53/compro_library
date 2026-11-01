---
title: 区間に辺を張るグラフ
documentation_of: //graph/range-edge-graph.hpp
---

## 概要

`RangeEdgeGraph<Cost=int>` は区間の全頂点から別の区間の全頂点へ同じコストの辺を張るための補助グラフを意図した実装。N は元の頂点数、m は追加予定回数。

意図上の空間 O(N+m log N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RangeEdgeGraph(n, m)` | 補助グラフを確保して初期辺を張る。現状は添字の不整合がある。 | 意図上 O(N+m) |
| `add_edge(from_l, from_r, to_l, to_r, cost)` | [from_l,from_r) から [to_l,to_r) へ辺を追加する意図。 | 意図上 O(log N)、現状は保証なし |
| `operator Graph<Cost>()` | 内部グラフのコピーを取得。 | O(V+E)、V,E は内部グラフの頂点・辺数 |

## 前提・注意点

現実装は頂点配列サイズと `+2*N` した添字の対応が不整合で、初期化でも範囲外の頂点に触れ得る。区間分解で右シフトすべき箇所も左シフトになっている。元頂点と上下の補助木の接続も整備されていないため、そのままでは利用不可。表の意図上の計算量は動作保証ではない。

## 使用例

以下は API の呼び出し形を示す例です。上記の実装上の問題があるため、そのままの利用は推奨しません。

```cpp
#include "template/template.cpp"
#include "graph/range-edge-graph.hpp"

int main() {
    RangeEdgeGraph<int> rg(4, 1);
    rg.add_edge(0, 2, 2, 4, 5);
    Graph<int> g = rg;
}
```
