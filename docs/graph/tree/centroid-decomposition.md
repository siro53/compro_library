---
title: 重心分解
documentation_of: //graph/tree/centroid-decomposition.hpp
---

## 概要

`CentroidDecomposition` は無向木を重心で再帰分割し、重心木の親を parent に記録する。`G` は参照として保持、subtree_size は作業用サイズ、removed は処理済み印。

空間 O(N)。重心木の深さは O(log N) だが、サイズ計算の再帰は O(N) に達する。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `CentroidDecomposition(g)` | Graph<int> への参照と作業配列を用意。 | O(N) |
| `get_subtree_size(u, p)` | removed を除く u の連結部分の部分木サイズを計算。 | O(K)、K は訪問頂点数 |
| `decomp(u, p)` | u を含む残りの木を分解。最初は decomp(0,-1)。 | O(N log N)（木全体） |

## 前提・注意点

非空・連結な無向木。g は分解器より長く生存させる。コンストラクタは分解を実行しない。終了時は removed が全て true、parent が重心木を表し、根だけ -1。subtree_size は最後の作業状態であり元の木のサイズ表ではない。同じオブジェクトで最初から再実行しない。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/tree/centroid-decomposition.hpp"

int main() {
    Graph<> g(3);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    CentroidDecomposition cd(g);
    cd.decomp(0, -1);
    assert(cd.parent[1] == -1);
}
```
