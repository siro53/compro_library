---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/graph/range-edge-graph.test.cpp
    title: test/mytest/graph/range-edge-graph.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/range-edge-graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <cstddef>\n#include <vector>\n\ntemplate <typename\
    \ Cost = int> struct Edge {\n    int from, to;\n    Cost cost;\n    int id;\n\
    \    Edge() = default;\n    explicit Edge(int from, int to, Cost cost = 1, int\
    \ id = -1)\n        : from(from), to(to), cost(cost), id(id) {}\n    operator\
    \ int() const { return to; }\n};\n\ntemplate <typename Cost = int> class Graph\
    \ {\n  public:\n    Graph() = default;\n    explicit Graph(int N) : N(N), M(0),\
    \ G(N) {}\n\n    inline void add_directed_edge(int from, int to, Cost cost = 1)\
    \ {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n\
    \        G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void\
    \ add_undirected_edge(int from, int to, Cost cost = 1) {\n        assert(0 <=\
    \ from && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n \
    \   inline std::size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  protected:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 4 \"graph/range-edge-graph.hpp\"\
    \n\ntemplate <typename Cost = int> class RangeEdgeGraph {\n  public:\n    explicit\
    \ RangeEdgeGraph(int n, int m) : N(n), M(0), G(3 * N + m) {\n        assert(n\
    \ > 0 && m >= 0);\n        for(int i = 1; i < N; i++) {\n            for(int child\
    \ : {i * 2, i * 2 + 1}) {\n                G.add_directed_edge(down(i), down(child),\
    \ 0);\n                G.add_directed_edge(up(child), up(i), 0);\n           \
    \ }\n        }\n    }\n    void add_edge(int from_l, int from_r, int to_l, int\
    \ to_r, Cost cost) {\n        assert(0 <= from_l and from_l < from_r and from_r\
    \ <= N);\n        assert(0 <= to_l and to_l < to_r and to_r <= N);\n        assert(3\
    \ * N + M < (int)G.size());\n        int id = 3 * N + M;\n        M++;\n     \
    \   from_l += N;\n        from_r += N;\n        while(from_l < from_r) {\n   \
    \         if(from_l & 1) G.add_directed_edge(up(from_l++), id, 0);\n         \
    \   if(from_r & 1) G.add_directed_edge(up(--from_r), id, 0);\n            from_l\
    \ >>= 1;\n            from_r >>= 1;\n        }\n        to_l += N;\n        to_r\
    \ += N;\n        while(to_l < to_r) {\n            if(to_l & 1) G.add_directed_edge(id,\
    \ down(to_l++), cost);\n            if(to_r & 1) G.add_directed_edge(id, down(--to_r),\
    \ cost);\n            to_l >>= 1;\n            to_r >>= 1;\n        }\n    }\n\
    \    operator Graph<Cost>() const { return G; }\n\n  private:\n    int N, M;\n\
    \    Graph<Cost> G;\n    int down(int i) const { return i < N ? N + i : i - N;\
    \ }\n    int up(int i) const { return i < N ? 2 * N + i : i - N; }\n};\n"
  code: "#pragma once\n\n#include \"graph_template.hpp\"\n\ntemplate <typename Cost\
    \ = int> class RangeEdgeGraph {\n  public:\n    explicit RangeEdgeGraph(int n,\
    \ int m) : N(n), M(0), G(3 * N + m) {\n        assert(n > 0 && m >= 0);\n    \
    \    for(int i = 1; i < N; i++) {\n            for(int child : {i * 2, i * 2 +\
    \ 1}) {\n                G.add_directed_edge(down(i), down(child), 0);\n     \
    \           G.add_directed_edge(up(child), up(i), 0);\n            }\n       \
    \ }\n    }\n    void add_edge(int from_l, int from_r, int to_l, int to_r, Cost\
    \ cost) {\n        assert(0 <= from_l and from_l < from_r and from_r <= N);\n\
    \        assert(0 <= to_l and to_l < to_r and to_r <= N);\n        assert(3 *\
    \ N + M < (int)G.size());\n        int id = 3 * N + M;\n        M++;\n       \
    \ from_l += N;\n        from_r += N;\n        while(from_l < from_r) {\n     \
    \       if(from_l & 1) G.add_directed_edge(up(from_l++), id, 0);\n           \
    \ if(from_r & 1) G.add_directed_edge(up(--from_r), id, 0);\n            from_l\
    \ >>= 1;\n            from_r >>= 1;\n        }\n        to_l += N;\n        to_r\
    \ += N;\n        while(to_l < to_r) {\n            if(to_l & 1) G.add_directed_edge(id,\
    \ down(to_l++), cost);\n            if(to_r & 1) G.add_directed_edge(id, down(--to_r),\
    \ cost);\n            to_l >>= 1;\n            to_r >>= 1;\n        }\n    }\n\
    \    operator Graph<Cost>() const { return G; }\n\n  private:\n    int N, M;\n\
    \    Graph<Cost> G;\n    int down(int i) const { return i < N ? N + i : i - N;\
    \ }\n    int up(int i) const { return i < N ? 2 * N + i : i - N; }\n};\n"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/range-edge-graph.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/graph/range-edge-graph.test.cpp
documentation_of: graph/range-edge-graph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5"
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
