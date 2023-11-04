---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/shortest-path.test.cpp
    title: test/library-checker/graph/shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/dijkstra.hpp\"\n\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n\n#line 2 \"graph/graph_template.hpp\"\
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
    #line 9 \"graph/shortest-path/dijkstra.hpp\"\n\ntemplate <typename Cost = int>\n\
    std::pair<std::vector<Cost>, std::vector<int>>\ndijkstra(const Graph<Cost> &G,\
    \ int start, Cost iv = 0,\n         Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> que;\n \
    \   que.emplace(iv, start);\n    while(!que.empty()) {\n        auto [d, u] =\
    \ que.top();\n        que.pop();\n        if(d > dist[u]) continue;\n        for(const\
    \ auto &e : G[u]) {\n            if(dist[e.to] > d + e.cost) {\n             \
    \   dist[e.to] = d + e.cost;\n                prev[e.to] = u;\n              \
    \  que.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n    return\
    \ std::make_pair(dist, prev);\n}\n"
  code: "#pragma once\n\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n\n#include \"../graph_template.hpp\"\n\ntemplate <typename\
    \ Cost = int>\nstd::pair<std::vector<Cost>, std::vector<int>>\ndijkstra(const\
    \ Graph<Cost> &G, int start, Cost iv = 0,\n         Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> que;\n \
    \   que.emplace(iv, start);\n    while(!que.empty()) {\n        auto [d, u] =\
    \ que.top();\n        que.pop();\n        if(d > dist[u]) continue;\n        for(const\
    \ auto &e : G[u]) {\n            if(dist[e.to] > d + e.cost) {\n             \
    \   dist[e.to] = d + e.cost;\n                prev[e.to] = u;\n              \
    \  que.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n    return\
    \ std::make_pair(dist, prev);\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/shortest-path/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/graph/shortest-path.test.cpp
documentation_of: graph/shortest-path/dijkstra.hpp
layout: document
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
