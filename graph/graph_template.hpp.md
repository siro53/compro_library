---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/namori.hpp
    title: graph/namori.hpp
  - icon: ':warning:'
    path: graph/range-edge-graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(SCC)"
  - icon: ':warning:'
    path: graph/shortest-path/bfs.hpp
    title: BFS
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
  - icon: ':warning:'
    path: graph/topological-sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  - icon: ':warning:'
    path: graph/tree/centroid-decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/tree/diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':heavy_check_mark:'
    path: graph/tree/hld.hpp
    title: "HL\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: "\u6728\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/scc.test.cpp
    title: test/library-checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/shortest-path.test.cpp
    title: test/library-checker/graph/shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/two-sat.test.cpp
    title: test/library-checker/math/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor2.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/tree-diameter.test.cpp
    title: test/library-checker/tree/tree-diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename Cost = int> struct Edge {\n    int from, to;\n\
    \    Cost cost;\n    int id;\n    Edge() = default;\n    explicit Edge(int from,\
    \ int to, Cost cost = 1, int id = -1)\n        : from(from), to(to), cost(cost),\
    \ id(id) {}\n    operator int() const { return to; }\n};\n\ntemplate <typename\
    \ Cost = int> class Graph {\n  public:\n    Graph() = default;\n    explicit Graph(int\
    \ N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int from, int\
    \ to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        G[from].emplace_back(from, to, cost, M++);\n    }\n\
    \n    inline void add_undirected_edge(int from, int to, Cost cost = 1) {\n   \
    \     assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n   \
    \     G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
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
    \   inline size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  protected:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - math/two_sat.hpp
  - graph/scc.hpp
  - graph/shortest-path/bfs.hpp
  - graph/shortest-path/dijkstra.hpp
  - graph/range-edge-graph.hpp
  - graph/topological-sort.hpp
  - graph/tree/tree-hash.hpp
  - graph/tree/hld.hpp
  - graph/tree/lca.hpp
  - graph/tree/centroid-decomposition.hpp
  - graph/tree/diameter.hpp
  - graph/namori.hpp
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/math/two-sat.test.cpp
  - test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - test/library-checker/tree/lowest-common-ancestor.test.cpp
  - test/library-checker/tree/tree-diameter.test.cpp
  - test/library-checker/graph/scc.test.cpp
  - test/library-checker/graph/shortest-path.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/aoj/aoj2821.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
---
