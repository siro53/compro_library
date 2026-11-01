---
title: 木の直径
documentation_of: //graph/tree/diameter.hpp
---

## 概要

木を 2 回探索して、最長路の長さとその頂点列を返す。`N` は頂点数。

追加空間・再帰スタック O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `get_diameter(G)` | (直径の重みの和, 端点から端点への頂点列)。 | O(N) |

## 前提・注意点

非空・連結な無向木、非負重みが前提。負辺・閉路には対応しない。頂点列の方向や同長の場合の選び方は固定の意味を持たない。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/tree/diameter.hpp"

int main() {
    Graph<long long> g(3);
    g.add_undirected_edge(0, 1, 2);
    g.add_undirected_edge(1, 2, 3);
    auto [length, path] = get_diameter(g);
    assert(length == 5 && path.size() == 3);
}
```
