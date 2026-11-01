---
title: 最小共通祖先（ダブリング）
documentation_of: //graph/tree/lca.hpp
---

## 概要

`LCA<Cost=int>` は親のダブリング表で LCA と辺数距離を計算する。`N` は頂点数。

空間 O(N log N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LCA(G, root=0)` | 根を決めて親・深さを構築。 | O(N log N) |
| `get_lca(u, v)` | 最小共通祖先を意図するが、現状は深さ合わせに不備。 | 意図上 O(log N) |
| `get_dist(u, v)` | u,v 間の辺数。get_lca に依存。 | 意図上 O(log N) |

## 前提・注意点

非空・連結な無向木を想定。重みは無視する。現実装は深さ合わせに負の差 `depth[u]-depth[v]` を使っており、深さが異なる頂点で誤答・範囲外参照を起こす。修正までは [HL 分解](https://github.com/siro53/compro_library/blob/main/docs/graph/tree/hld.md) の `lca/dist` を使う。デフォルトコンストラクタも const メンバ未初期化のため利用できない。

## 使用例

以下は API の呼び出し形を示す例です。上記の実装上の問題があるため、そのままの利用は推奨しません。

```cpp
#include "template/template.cpp"
#include "graph/tree/lca.hpp"

int main() {
    Graph<> g(3);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    LCA<> lca(g);
    auto ancestor = lca.get_lca(0, 2);
}
```
