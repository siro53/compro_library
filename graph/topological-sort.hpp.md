---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological-sort.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <typename Cost = int> struct\
    \ Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n\
    \    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n};\n\ntemplate <typename Cost = int> class Graph\
    \ {\n  public:\n    Graph() = default;\n    explicit Graph(int N) : N(N), M(0),\
    \ G(N) {}\n\n    inline void add_directed_edge(int from, int to, Cost cost = 1)\
    \ {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n\
    \        G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void\
    \ add_undirected_edge(int from, int to, Cost cost = 1) {\n        assert(0 <=\
    \ from && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n \
    \   inline size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  private:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 4 \"graph/topological-sort.hpp\"\
    \n\ntemplate<typename Cost = int>\nstd::vector<int> topological_sort(const Graph<Cost>&\
    \ G) {\n    int N = (int)G.size();\n    std::vector<int> indeg(N, 0);\n    for(int\
    \ i = 0; i < N; i++) {\n        for(const auto& e : G[i]) {\n            indeg[e.to]++;\n\
    \        }\n    }\n    std::vector<int> st, ret;\n    for(int i = 0; i < N; i++)\
    \ {\n        if(indeg[i] == 0) st.push_back(i);\n    }\n    while(!st.empty())\
    \ {\n        int u = st.back();\n        st.pop_back();\n        ret.push_back(u);\n\
    \        for(const auto& e : G[u]) {\n            indeg[e.to]--;\n           \
    \ if(indeg[e.to] == 0) st.push_back(e.to);\n        }\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include \"graph_template.hpp\"\n\ntemplate<typename Cost\
    \ = int>\nstd::vector<int> topological_sort(const Graph<Cost>& G) {\n    int N\
    \ = (int)G.size();\n    std::vector<int> indeg(N, 0);\n    for(int i = 0; i <\
    \ N; i++) {\n        for(const auto& e : G[i]) {\n            indeg[e.to]++;\n\
    \        }\n    }\n    std::vector<int> st, ret;\n    for(int i = 0; i < N; i++)\
    \ {\n        if(indeg[i] == 0) st.push_back(i);\n    }\n    while(!st.empty())\
    \ {\n        int u = st.back();\n        st.pop_back();\n        ret.push_back(u);\n\
    \        for(const auto& e : G[u]) {\n            indeg[e.to]--;\n           \
    \ if(indeg[e.to] == 0) st.push_back(e.to);\n        }\n    }\n    return ret;\n\
    }"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy: []
  timestamp: '2023-02-27 01:03:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological-sort.hpp
layout: document
redirect_from:
- /library/graph/topological-sort.hpp
- /library/graph/topological-sort.hpp.html
title: graph/topological-sort.hpp
---
