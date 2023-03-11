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
    \ {\n        return G[i];\n    }\n\n  private:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
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
  timestamp: '2023-02-28 22:24:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/range-edge-graph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---
