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
  bundledCode: "#line 2 \"graph/tree/centroid-decomposition.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    #line 4 \"graph/tree/centroid-decomposition.hpp\"\n\n// TODO: \u826F\u3044\u30A4\
    \u30F3\u30BF\u30FC\u30D5\u30A7\u30A4\u30B9\u3092\u6A21\u7D22\u3059\u308B\nstruct\
    \ CentroidDecomposition {\n    const Graph<int>& G;\n    std::vector<int> subtree_size,\
    \ parent;\n    std::vector<bool> removed;\n\n    explicit CentroidDecomposition(const\
    \ Graph<int>& g): G(g), subtree_size(g.size(), 0), parent(g.size(), -1), removed(g.size(),\
    \ false) {}\n\n    void get_subtree_size(int u, int p) {\n        subtree_size[u]\
    \ = 1;\n        for(int v : G[u]) {\n            if(v == p or removed[v]) continue;\n\
    \            get_subtree_size(v, u);\n            subtree_size[u] += subtree_size[v];\n\
    \        }\n    }\n\n    void decomp(int u, int p) {\n        get_subtree_size(u,\
    \ -1);\n        int sz = subtree_size[u];\n        int pre = -1;\n        while(1)\
    \ {\n            int mx = -1, mx_v = -1;\n            for(int v : G[u]) {\n  \
    \              if(v == pre or removed[v]) continue;\n                if(mx < subtree_size[v])\
    \ {\n                    mx = subtree_size[v];\n                    mx_v = v;\n\
    \                }\n            }\n            if(mx * 2 <= sz) break;\n     \
    \       pre = u;\n            u = mx_v;\n        }\n        removed[u] = true;\n\
    \        parent[u] = p;\n        for(int v : G[u]) {\n            if(removed[v])\
    \ continue;\n            decomp(v, u);\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../graph_template.hpp\"\n\n// TODO: \u826F\u3044\
    \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30A4\u30B9\u3092\u6A21\u7D22\u3059\u308B\
    \nstruct CentroidDecomposition {\n    const Graph<int>& G;\n    std::vector<int>\
    \ subtree_size, parent;\n    std::vector<bool> removed;\n\n    explicit CentroidDecomposition(const\
    \ Graph<int>& g): G(g), subtree_size(g.size(), 0), parent(g.size(), -1), removed(g.size(),\
    \ false) {}\n\n    void get_subtree_size(int u, int p) {\n        subtree_size[u]\
    \ = 1;\n        for(int v : G[u]) {\n            if(v == p or removed[v]) continue;\n\
    \            get_subtree_size(v, u);\n            subtree_size[u] += subtree_size[v];\n\
    \        }\n    }\n\n    void decomp(int u, int p) {\n        get_subtree_size(u,\
    \ -1);\n        int sz = subtree_size[u];\n        int pre = -1;\n        while(1)\
    \ {\n            int mx = -1, mx_v = -1;\n            for(int v : G[u]) {\n  \
    \              if(v == pre or removed[v]) continue;\n                if(mx < subtree_size[v])\
    \ {\n                    mx = subtree_size[v];\n                    mx_v = v;\n\
    \                }\n            }\n            if(mx * 2 <= sz) break;\n     \
    \       pre = u;\n            u = mx_v;\n        }\n        removed[u] = true;\n\
    \        parent[u] = p;\n        for(int v : G[u]) {\n            if(removed[v])\
    \ continue;\n            decomp(v, u);\n        }\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/centroid-decomposition.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid-decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3"
---
