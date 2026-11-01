---
title: グラフ構造体
documentation_of: //graph/graph_template.hpp
---

## 概要

`Graph<Cost=int>` は隣接リスト。`Edge<Cost>` は from/to（端点）、cost（重み）、id（追加順の辺番号）を保持する。`Edges<Cost>` は辺の vector。`N` は頂点数、`M` は辺追加回数。

空間 O(N+M)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Graph(N)` | N 頂点・辺なしで初期化。 | O(N) |
| `Edge(from, to, cost=1, id=-1)` | 辺を作る。デフォルト構築の整数メンバは未初期化。 | O(1) |
| `Edge::operator int()` | 行き先 to に変換。 | O(1) |
| `add_directed_edge(from, to, cost=1)` | 有向辺を 1 本追加。 | 償却 O(1) |
| `add_undirected_edge(from, to, cost=1)` | 同じ id の辺を両方向に追加。 | 償却 O(1) |
| `size()` | 頂点数。 | O(1) |
| `operator[](i)` | i の出辺リストへの参照（const 版もある）。 | O(1) |

## 前提・注意点

頂点番号は `[0,N)`。無向辺は追加 1 回で id が 1 増える。デフォルト構築では頂点数等が未初期化なので、サイズ付きオブジェクトを代入してから使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/graph_template.hpp"

int main() {
    Graph<long long> g(3);
    g.add_undirected_edge(0, 1, 5);
    g.add_directed_edge(1, 2, 7);
    assert(g[0][0].to == 1 && g[0][0].cost == 5);
}
```
