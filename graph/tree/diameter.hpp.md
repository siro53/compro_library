---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: graph/tree/tree-hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/tree-diameter.test.cpp
    title: test/library-checker/tree/tree-diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/diameter.hpp\"\n\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"graph/graph_template.hpp\"\n\n#include\
    \ <cassert>\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost =\
    \ int> struct Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge()\
    \ = default;\n    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n\
    \        : from(from), to(to), cost(cost), id(id) {}\n    operator int() const\
    \ { return to; }\n};\n\ntemplate <typename Cost = int> class Graph {\n  public:\n\
    \    Graph() = default;\n    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n \
    \   inline void add_directed_edge(int from, int to, Cost cost = 1) {\n       \
    \ assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n       \
    \ G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void add_undirected_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n    inline size_t\
    \ size() const { return G.size(); }\n    inline std::vector<Edge<Cost>> &operator[](const\
    \ int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>> &operator[](const\
    \ int &i) const {\n        return G[i];\n    }\n\n  private:\n    int N, M;\n\
    \    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class Cost = int>\
    \ using Edges = std::vector<Edge<Cost>>;\n#line 8 \"graph/tree/diameter.hpp\"\n\
    \ntemplate <typename Cost = int>\nstd::pair<Cost, std::vector<int>> get_diameter(const\
    \ Graph<Cost> &G) {\n    std::vector<Cost> depth(G.size());\n    std::vector<int>\
    \ par(G.size(), -1);\n    auto dfs = [&](auto &&self, int u, int p, Cost d) ->\
    \ void {\n        depth[u] = d;\n        par[u] = p;\n        for(const auto &e\
    \ : G[u]) {\n            if(e.to == p) continue;\n            self(self, e.to,\
    \ u, d + e.cost);\n        }\n    };\n    dfs(dfs, 0, -1, 0);\n    int from =\
    \ std::max_element(depth.begin(), depth.end()) - depth.begin();\n    dfs(dfs,\
    \ from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    std::vector<int> path = {to};\n    while(1) {\n        int nxt = par[path.back()];\n\
    \        if(nxt == -1) break;\n        path.push_back(nxt);\n    }\n    return\
    \ std::make_pair(depth[to], path);\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n#include \"../graph_template.hpp\"\n\ntemplate <typename Cost = int>\nstd::pair<Cost,\
    \ std::vector<int>> get_diameter(const Graph<Cost> &G) {\n    std::vector<Cost>\
    \ depth(G.size());\n    std::vector<int> par(G.size(), -1);\n    auto dfs = [&](auto\
    \ &&self, int u, int p, Cost d) -> void {\n        depth[u] = d;\n        par[u]\
    \ = p;\n        for(const auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            self(self, e.to, u, d + e.cost);\n        }\n    };\n    dfs(dfs,\
    \ 0, -1, 0);\n    int from = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    dfs(dfs, from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<int> path = {to};\n    while(1) {\n      \
    \  int nxt = par[path.back()];\n        if(nxt == -1) break;\n        path.push_back(nxt);\n\
    \    }\n    return std::make_pair(depth[to], path);\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/diameter.hpp
  requiredBy:
  - graph/tree/tree-hash.hpp
  timestamp: '2023-02-28 22:24:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/tree/tree-diameter.test.cpp
  - test/aoj/aoj2821.test.cpp
documentation_of: graph/tree/diameter.hpp
layout: document
redirect_from:
- /library/graph/tree/diameter.hpp
- /library/graph/tree/diameter.hpp.html
title: graph/tree/diameter.hpp
---
