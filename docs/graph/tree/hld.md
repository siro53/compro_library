---
title: Heavy Light Decomposition
documentation_of: //graph/tree/hld.hpp
---

## 概要

`HeavyLightDecomposition<Cost=int>` は木の頂点を配列へ並べ、パスを O(log N) 個の区間、部分木を 1 区間に分解する。`N` は頂点数。

空間・最大再帰深さ O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `HeavyLightDecomposition(N)` | N 頂点で初期化。 | O(N) |
| `HeavyLightDecomposition(G)` | 木をコピーして根 0 で構築。 | O(N) |
| `add_edge(u, v, cost=1)` | 無向辺追加。 | 償却 O(1) |
| `build(root=0)` | 重い子を選び DFS 順に番号を付ける。 | O(N) |
| `operator[](u)` | 頂点 u の配列上の位置。 | O(1) |
| `lca(u, v)` | 最小共通祖先。 | O(log N) |
| `dist(u, v)` | パスの辺数。重みは無視。 | O(log N) |
| `la(u, k)` | k 個上の祖先。存在しなければ -1。 | O(log N) |
| `path_query(u, v, f, edge=false)` | 分解した [l,r) ごとに f(l,r) を呼ぶ。 | O(log N) 回のコールバック |
| `path_query(u, v, f, f_rev, edge=false)` | u→LCA 側を f、LCA→v 側を f_rev で処理。 | O(log N) 回のコールバック |
| `subtree_query(u, f)` | 部分木の [l,r) に対して f を 1 回呼ぶ。 | O(1) + コールバック |

## 前提・注意点

非空・連結な無向木で、辺追加後に build する。`la` の k は非負。`edge=true` は LCA の位置を除き、各辺の値を深い側の頂点に置く。部分木クエリは根頂点も含む。

区間の通知順は u→v の走査順を保証しない。2 コールバック版も v 側では終点側の区間から呼ぶため、非可換な積では区間内の向きと区間を連結する順序を呼び出し側で管理する。コールバックが O(log N) ならパスクエリ全体は O(log² N)。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/tree/hld.hpp"

int main() {
    HeavyLightDecomposition<> hld(4);
    hld.add_edge(0, 1);
    hld.add_edge(1, 2);
    hld.add_edge(1, 3);
    hld.build();
    int count = 0;
    hld.path_query(2, 3, [&](int l, int r) { count += r - l; });
    assert(count == 3 && hld.lca(2, 3) == 1);
}
```
