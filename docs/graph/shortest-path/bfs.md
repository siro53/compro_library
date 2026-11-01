---
title: 幅優先探索
documentation_of: //graph/shortest-path/bfs.hpp
---

## 概要

辺数による最短距離を幅優先探索で求める。辺の cost は無視する。`N` は頂点数、`M` は格納辺数。

追加空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `bfs(G, start, iv=0, inf=numeric_limits<Cost>::max())` | (距離配列 dist, 直前の頂点配列 prev) を返す。 | O(N+M) |

## 前提・注意点

`start` は有効な頂点。始点距離は iv、到達不能は inf。prev は始点・到達不能で -1。経路は終点から prev をたどって反転する。距離の加算がオーバーフローせず、すべての有限距離が inf より小さいこと。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/shortest-path/bfs.hpp"

int main() {
    Graph<int> g(3);
    g.add_directed_edge(0, 1, 1);
    auto [dist, prev] = bfs(g, 0);
    assert(dist[1] == 1);
    assert(prev[1] == 0 && prev[2] == -1);
}
```
