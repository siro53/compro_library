---
title: Dijkstra 法
documentation_of: //graph/shortest-path/dijkstra.hpp
---

## 概要

非負重みの有向・無向グラフの最短距離を二分ヒープで求める。`N` は頂点数、`M` は格納辺数。

追加空間 O(N+M)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `dijkstra(G, start, iv=0, inf=numeric_limits<Cost>::max())` | (距離配列 dist, 直前の頂点配列 prev) を返す。 | O(N+(N+M) log(M+2)) |

## 前提・注意点

`start` は有効な頂点。始点距離は iv、到達不能は inf。prev は始点・到達不能で -1。経路は終点から prev をたどって反転する。距離の加算がオーバーフローせず、すべての有限距離が inf より小さいこと。負辺には対応しない。多重辺も許すため計算量の対数を M で記した。単純グラフでは O((N+M) log N)。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/shortest-path/dijkstra.hpp"

int main() {
    Graph<int> g(3);
    g.add_directed_edge(0, 1, 5);
    auto [dist, prev] = dijkstra(g, 0);
    assert(dist[1] == 5);
    assert(prev[1] == 0 && prev[2] == -1);
}
```
