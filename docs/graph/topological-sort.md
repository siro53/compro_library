---
title: トポロジカルソート
documentation_of: //graph/topological-sort.hpp
---

## 概要

入次数 0 の頂点から有向グラフを並べる。`N` は頂点数、`M` は辺数。

追加空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `topological_sort(G)` | 辺の向きに沿った頂点順序の vector<int>。 | O(N+M) |

## 前提・注意点

返り値の長さが N 未満なら閉路が存在する。辞書順最小ではない。閉路を含む場合も処理できた頂点の列を返す。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/topological-sort.hpp"

int main() {
    Graph<> g(3);
    g.add_directed_edge(0, 1);
    g.add_directed_edge(1, 2);
    auto order = topological_sort(g);
    assert((order == vector<int>{0, 1, 2}));
}
```
