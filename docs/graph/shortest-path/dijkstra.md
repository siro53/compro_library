---
title: Dijkstra 法
documentation_of: //graph/shortest-path/dijkstra.hpp
---

## このライブラリでできること

`dijkstra` は、非負の辺重みを持つグラフで、始点から各頂点への最小コストを求めます。距離の小さい候補を優先度付きキューから取り出し、隣接頂点への距離を改善していきます。有向グラフ・無向グラフの両方に使えます。

頂点数を $N$、隣接リストに格納された辺数を $M$ とします。この実装は改善のたびにキューへ候補を追加するため、多重辺も含めた上界は $O(N+(N+M)\log(M+2))$ です。単純グラフなら通常の $O((N+M)\log N)$ と表せます。

## 使い方

`auto [dist,prev]=dijkstra(g,start)` で距離と直前の頂点を受け取ります。例では辺 $0\to1$ の重みが $5$ なので、`dist[1]` は $5$ です。辺数を数える BFS とはここが異なります。

到達可能な頂点への経路は、終点から `prev` をたどって反転すると復元できます。`iv` を指定した場合は、通常の最短距離にその初期値を加えた値を返します。

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

## API・計算量

入力とは別に $O(N+M)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `dijkstra(G, start, iv=0, inf=numeric_limits<Cost>::max())` | (距離配列 dist, 直前の頂点配列 prev) を返す。 | O(N+(N+M) log(M+2)) |

## 利用条件と実装上の注意

すべての辺重みが非負であることが前提です。負の辺があるグラフには、この計算量や正しさを適用できません。

到達できない頂点の距離は `inf`、`prev` は $-1$ です。始点の `prev` も $-1$ になります。有限距離は `inf` より小さくし、緩和時の `d+cost` がオーバーフローしない型と値域を選んでください。
