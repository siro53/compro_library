---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/range-edge-graph.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <typename Cost = int> struct\
    \ Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n\
    \    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n    operator int() const { return to; }\n};\n\
    \ntemplate <typename Cost = int> class Graph {\n  public:\n    Graph() = default;\n\
    \    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M++);\n    }\n\n    inline void add_undirected_edge(int from, int to, Cost cost\
    \ = 1) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 4 \"graph/range-edge-graph.hpp\"\n\ntemplate <typename Cost = int> class\
    \ RangeEdgeGraph {\n  public:\n    explicit RangeEdgeGraph(int n, int m) : N(n),\
    \ M(0), G(3 * N + m) {\n        for(int i = 1; i < N; i++) {\n            G.add_directed_edge(i,\
    \ (i << 1 | 0), 0);\n            G.add_directed_edge(i, (i << 1 | 1), 0);\n  \
    \          G.add_directed_edge((i << 1 | 0) + N * 2, i + N * 2, 0);\n        \
    \    G.add_directed_edge((i << 1 | 1) + N * 2, i + N * 2, 0);\n        }\n   \
    \ }\n    void add_edge(int from_l, int from_r, int to_l, int to_r, Cost cost)\
    \ {\n        assert(0 <= from_l and from_l < from_r and from_r <= N);\n      \
    \  assert(0 <= to_l and to_l < to_r and to_r <= N);\n        assert(3 * N + M\
    \ < (int)G.size());\n        int id = 3 * N + M;\n        M++;\n        from_l\
    \ += N;\n        from_r += N;\n        while(from_l < from_r) {\n            if(from_l\
    \ & 1) G.add_directed_edge(from_l + 2*N, id, 0), from_l++;\n            if(from_r\
    \ & 1) from_r--, G.add_directed_edge(from_r + 2*N, id, 0);\n            from_l\
    \ <<= 1;\n            from_r <<= 1;\n        }\n        to_l += N;\n        to_r\
    \ += N;\n        while(to_l < to_r) {\n            if(to_l & 1) G.add_directed_edge(id,\
    \ to_l, cost), to_l++;\n            if(to_r & 1) to_r--, G.add_directed_edge(id,\
    \ to_r, cost);\n            to_l <<= 1;\n            to_r <<= 1;\n        }\n\
    \    }\n    operator Graph<Cost>() const { return G; }\n\n  private:\n    int\
    \ N, M;\n    Graph<Cost> G;\n};\n"
  code: "#pragma once\n\n#include \"graph_template.hpp\"\n\ntemplate <typename Cost\
    \ = int> class RangeEdgeGraph {\n  public:\n    explicit RangeEdgeGraph(int n,\
    \ int m) : N(n), M(0), G(3 * N + m) {\n        for(int i = 1; i < N; i++) {\n\
    \            G.add_directed_edge(i, (i << 1 | 0), 0);\n            G.add_directed_edge(i,\
    \ (i << 1 | 1), 0);\n            G.add_directed_edge((i << 1 | 0) + N * 2, i +\
    \ N * 2, 0);\n            G.add_directed_edge((i << 1 | 1) + N * 2, i + N * 2,\
    \ 0);\n        }\n    }\n    void add_edge(int from_l, int from_r, int to_l, int\
    \ to_r, Cost cost) {\n        assert(0 <= from_l and from_l < from_r and from_r\
    \ <= N);\n        assert(0 <= to_l and to_l < to_r and to_r <= N);\n        assert(3\
    \ * N + M < (int)G.size());\n        int id = 3 * N + M;\n        M++;\n     \
    \   from_l += N;\n        from_r += N;\n        while(from_l < from_r) {\n   \
    \         if(from_l & 1) G.add_directed_edge(from_l + 2*N, id, 0), from_l++;\n\
    \            if(from_r & 1) from_r--, G.add_directed_edge(from_r + 2*N, id, 0);\n\
    \            from_l <<= 1;\n            from_r <<= 1;\n        }\n        to_l\
    \ += N;\n        to_r += N;\n        while(to_l < to_r) {\n            if(to_l\
    \ & 1) G.add_directed_edge(id, to_l, cost), to_l++;\n            if(to_r & 1)\
    \ to_r--, G.add_directed_edge(id, to_r, cost);\n            to_l <<= 1;\n    \
    \        to_r <<= 1;\n        }\n    }\n    operator Graph<Cost>() const { return\
    \ G; }\n\n  private:\n    int N, M;\n    Graph<Cost> G;\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/range-edge-graph.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/range-edge-graph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5"
---

## このライブラリでできること

`RangeEdgeGraph<Cost>` は、頂点を番号順に並べたときに「区間内の全頂点から、別の区間内の全頂点へ同じ重みの辺を張る」ための補助グラフを作ることを意図したクラスです。両区間の長さの積だけ辺を作る代わりに、セグメント木状の補助頂点で接続を共有する方法です。

ただし、このヘッダーには補助頂点の添字と区間分解の実装に不備があり、現状では利用できません。以下の説明と例は、実装が目指しているインターフェースを示します。

## 使い方

構築時には元の頂点数 $N$ と、区間間の辺を追加する回数の上限 $m$ を渡します。`add_edge(a,b,c,d,w)` は、すべての $a\le u<b$、$c\le v<d$ について重み $w$ の辺 $u\to v$ を追加することを意図しています。

例は区間 $[0,2)$ から $[2,4)$ へ重み $5$ の辺を張る呼び出し形です。正しく実装された場合には、取り出した補助グラフ上で最短路などを計算する流れになります。

以下のコードは呼び出し形を示すものです。現実装の不備があるため、動作確認済みの使用例ではありません。

```cpp
#include "template/template.cpp"
#include "graph/range-edge-graph.hpp"

int main() {
    RangeEdgeGraph<int> rg(4, 1);
    rg.add_edge(0, 2, 2, 4, 5);
    Graph<int> g = rg;
}
```

## API・計算量

この構成で意図している空間計算量は $O(N+m\log N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RangeEdgeGraph(n, m)` | 補助グラフを確保して初期辺を張る。現状は添字の不整合がある。 | 意図上 O(N+m) |
| `add_edge(from_l, from_r, to_l, to_r, cost)` | [from_l,from_r) から [to_l,to_r) へ辺を追加する意図。 | 意図上 O(log N)、現状は保証なし |
| `operator Graph<Cost>()` | 内部グラフのコピーを取得。 | O(V+E)、V,E は内部グラフの頂点・辺数 |

## 利用条件と実装上の注意

現実装では、確保した頂点数と `+2*N` した頂点番号が整合していません。また、区間分解で上の段へ進むべき箇所が左シフトになっており、元の頂点と上下の補助木の接続にも不備があります。

表の「意図上」の時間・空間計算量は、これらを修正した一般的な構成に対する説明です。現状のコードがその時間で終了することや、正しいグラフを返すことを保証するものではありません。変換操作の $V,E$ は補助グラフの頂点数・辺数です。
