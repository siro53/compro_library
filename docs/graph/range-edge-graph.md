---
title: 区間に辺を張るグラフ
documentation_of: //graph/range-edge-graph.hpp
---

## このライブラリでできること

`RangeEdgeGraph<Cost>` は、「区間内の全頂点から、別の区間内の全頂点へ同じ重みの辺を張る」ための補助グラフを作ります。両区間の長さの積だけ辺を作る代わりに、上向き・下向きのセグメント木状の補助頂点を通して接続を共有します。

元の頂点は、取り出したグラフでも番号 $0,1,\ldots,N-1$ に対応します。上向きの木で始点区間をまとめ、追加ごとの中継頂点を経て下向きの木から終点区間へ進みます。指定した重みは、この経路で1回だけ加算されます。

## 使い方

構築時には元の頂点数 $N$ と、区間間の辺を追加する回数の上限 $m$ を渡します。`add_edge(a,b,c,d,w)` は、すべての $a\le u<b$、$c\le v<d$ について重み $w$ の辺 $u\to v$ を表します。

例では区間 $[0,2)$ から $[2,4)$ へ重み5の辺を張ります。頂点0から2と3への最短距離は5ですが、1へは到達できません。

```cpp
#include <cassert>
#include "graph/range-edge-graph.hpp"
#include "graph/shortest-path/dijkstra.hpp"

int main() {
    RangeEdgeGraph<int> rg(4, 1);
    rg.add_edge(0, 2, 2, 4, 5);
    Graph<int> g = rg;
    auto dist = dijkstra(g, 0, 0, 1000000).first;
    assert(dist[2] == 5 && dist[3] == 5);
    assert(dist[1] == 1000000);
}
```

## API・計算量

追加済みの操作数を $Q\le m$ とします。グラフの頂点数は $V=3N+m$、辺数は $E=O(N+Q\log(N+1))$ です。空間は $O(N+m+Q\log(N+1))$ です。Cost のコピーを定数時間とします。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RangeEdgeGraph(int n, int m)` | 補助グラフを確保して初期辺を張る。 | O(N+m) |
| `void add_edge(int from_l, int from_r, int to_l, int to_r, Cost cost)` | [from_l,from_r) から [to_l,to_r) へ辺を追加。 | 償却 O(log(N+1)) |
| `operator Graph<Cost>() const` | 内部グラフのコピーを取得。 | O(V+E) |

## 利用条件と実装上の注意

$N\ge1$、$m\ge0$ とし、追加回数は m 以下にします。各区間は $0\le l<r\le N$ の非空な半開区間です。頂点数 $3N+m$ は int とメモリの範囲に収めてください。

補助辺の重みは0です。Dijkstra法を使う場合は追加する重みも非負にします。取り出した Graph はコピーなので、その後の add_edge は取得済みのグラフへ反映されません。元の頂点の答えは、距離配列の先頭 N 要素から読み取ります。
