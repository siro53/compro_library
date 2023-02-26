---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/range-edge-graph.hpp
    title: graph/range-edge-graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':warning:'
    path: graph/shortest-path/bfs.hpp
    title: graph/shortest-path/bfs.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/dijkstra.hpp
    title: graph/shortest-path/dijkstra.hpp
  - icon: ':warning:'
    path: graph/topological-sort.hpp
    title: graph/topological-sort.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/diameter.hpp
    title: graph/tree/diameter.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/hld.hpp
    title: graph/tree/hld.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: graph/tree/lca.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: graph/tree/tree-hash.hpp
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: math/two_sat.hpp
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
    \ id(id) {}\n};\n\ntemplate <typename Cost = int> class Graph {\n  public:\n \
    \   Graph() = default;\n    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n  \
    \  inline void add_directed_edge(int from, int to, Cost cost = 1) {\n        assert(0\
    \ <= from && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M++);\n    }\n\n    inline void add_undirected_edge(int from, int\
    \ to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        G[from].emplace_back(from, to, cost, M);\n      \
    \  G[to].emplace_back(to, from, cost, M++);\n    }\n\n    inline size_t size()\
    \ const { return G.size(); }\n    inline std::vector<Edge<Cost>> &operator[](const\
    \ int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>> &operator[](const\
    \ int &i) const {\n        return G[i];\n    }\n\n  private:\n    int N, M;\n\
    \    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class Cost = int>\
    \ using Edges = std::vector<Edge<Cost>>;\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ Cost = int> struct Edge {\n    int from, to;\n    Cost cost;\n    int id;\n\
    \    Edge() = default;\n    explicit Edge(int from, int to, Cost cost = 1, int\
    \ id = -1)\n        : from(from), to(to), cost(cost), id(id) {}\n};\n\ntemplate\
    \ <typename Cost = int> class Graph {\n  public:\n    Graph() = default;\n   \
    \ explicit Graph(int N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M++);\n    }\n\n    inline void add_undirected_edge(int from, int to, Cost cost\
    \ = 1) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  private:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - math/two_sat.hpp
  - graph/shortest-path/bfs.hpp
  - graph/shortest-path/dijkstra.hpp
  - graph/tree/lca.hpp
  - graph/tree/diameter.hpp
  - graph/tree/hld.hpp
  - graph/tree/tree-hash.hpp
  - graph/range-edge-graph.hpp
  - graph/scc.hpp
  - graph/topological-sort.hpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/math/two-sat.test.cpp
  - test/library-checker/graph/scc.test.cpp
  - test/library-checker/graph/shortest-path.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/tree/tree-diameter.test.cpp
  - test/library-checker/tree/lowest-common-ancestor.test.cpp
  - test/aoj/aoj2821.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: graph/graph_template.hpp
---
