---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(SCC)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/two-sat.test.cpp
    title: test/library-checker/math/two-sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/two_sat.hpp\"\n\n#line 2 \"graph/scc.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct\
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
    #line 8 \"graph/scc.hpp\"\n\ntemplate <typename Cost = int> class SCC {\n  public:\n\
    \    explicit SCC(int N)\n        : G(N), G_rev(N), comp(N, -1), seen(N, false),\
    \ isBuilt(false) {}\n    explicit SCC(const Graph<Cost> &g)\n        : G(g), G_rev(g.size()),\
    \ comp(g.size(), -1), seen(g.size(), false) {\n        for(int i = 0; i < (int)g.size();\
    \ i++) {\n            for(const auto &e : g[i]) G_rev.add_directed_edge(e.to,\
    \ i);\n        }\n        build();\n    }\n    inline void add_directed_edge(int\
    \ from, int to) {\n        assert(!isBuilt &&\n               \"This scc_graph\
    \ is already built, but you tried to add edge.\");\n        G.add_directed_edge(from,\
    \ to);\n        G_rev.add_directed_edge(to, from);\n    }\n    void build() {\n\
    \        assert(!isBuilt && \"This scc_graph is already built.\");\n        for(int\
    \ i = 0; i < (int)G.size(); i++) {\n            if(!seen[i]) dfs(i);\n       \
    \ }\n        std::reverse(vs.begin(), vs.end());\n        count = 0;\n       \
    \ for(const int v : vs) {\n            if(comp[v] == -1) {\n                dfs_rev(v,\
    \ count);\n                count++;\n            }\n        }\n        isBuilt\
    \ = true;\n    }\n    Graph<Cost> get_contracted_graph() {\n        assert(isBuilt\
    \ && \"This scc_graph is not yet built.\");\n        Graph<Cost> new_g(count);\n\
    \        for(int i = 0; i < (int)G.size(); i++) {\n            for(const auto\
    \ &e : G[i]) {\n                int from = comp[i];\n                int to =\
    \ comp[e.to];\n                if(from != to) new_g.add_directed_edge(from, to,\
    \ e.cost);\n            }\n        }\n        return new_g;\n    }\n    int operator[](const\
    \ int &k) const {\n        assert(isBuilt && \"This scc_graph is not yet built.\"\
    );\n        return comp[k];\n    }\n    size_t size() { return (size_t)count;\
    \ }\n\n  private:\n    Graph<Cost> G, G_rev;\n    std::vector<int> vs, comp;\n\
    \    std::vector<bool> seen;\n    int count;\n    bool isBuilt;\n\n    void dfs(int\
    \ u) {\n        seen[u] = true;\n        for(const auto &e : G[u]) {\n       \
    \     if(!seen[e.to]) dfs(e.to);\n        }\n        vs.push_back(u);\n    }\n\
    \    void dfs_rev(int u, int idx) {\n        comp[u] = idx;\n        for(const\
    \ auto &e : G_rev[u]) {\n            if(comp[e.to] == -1) dfs_rev(e.to, idx);\n\
    \        }\n    }\n};\n#line 4 \"math/two_sat.hpp\"\n\ntemplate<class Cost = int>\n\
    class TwoSat {\npublic:\n    TwoSat() = default;\n    explicit TwoSat(int N):\
    \ N(N), scc(N * 2), ans(N), called_satisfiable(false) {}\n\n    void add_clause(int\
    \ i, bool f_i, int j, bool f_j) {\n        if(!f_i) i = NOT(i);\n        if(!f_j)\
    \ j = NOT(j);\n        scc.add_directed_edge(i, NOT(j));\n        scc.add_directed_edge(j,\
    \ NOT(i));\n    }\n    bool satisfiable() {\n        scc.build();\n        for(int\
    \ i = 0; i < N; i++) {\n            if(scc[i] == scc[NOT(i)]) return false;\n\
    \            ans[i] = (scc[i] < scc[NOT(i)]);\n        }\n        called_satisfiable\
    \ = true;\n        return true;\n    }\n    std::vector<bool> get_answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int N;\n    SCC<Cost> scc;\n    std::vector<bool> ans;\n    bool called_satisfiable;\n\
    \n    inline int NOT(int i) { return i + (i < N ? N : -N); }\n};\n"
  code: "#pragma once\n\n#include \"../graph/scc.hpp\"\n\ntemplate<class Cost = int>\n\
    class TwoSat {\npublic:\n    TwoSat() = default;\n    explicit TwoSat(int N):\
    \ N(N), scc(N * 2), ans(N), called_satisfiable(false) {}\n\n    void add_clause(int\
    \ i, bool f_i, int j, bool f_j) {\n        if(!f_i) i = NOT(i);\n        if(!f_j)\
    \ j = NOT(j);\n        scc.add_directed_edge(i, NOT(j));\n        scc.add_directed_edge(j,\
    \ NOT(i));\n    }\n    bool satisfiable() {\n        scc.build();\n        for(int\
    \ i = 0; i < N; i++) {\n            if(scc[i] == scc[NOT(i)]) return false;\n\
    \            ans[i] = (scc[i] < scc[NOT(i)]);\n        }\n        called_satisfiable\
    \ = true;\n        return true;\n    }\n    std::vector<bool> get_answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int N;\n    SCC<Cost> scc;\n    std::vector<bool> ans;\n    bool called_satisfiable;\n\
    \n    inline int NOT(int i) { return i + (i < N ? N : -N); }\n};"
  dependsOn:
  - graph/scc.hpp
  - graph/graph_template.hpp
  isVerificationFile: false
  path: math/two_sat.hpp
  requiredBy: []
  timestamp: '2023-02-28 22:24:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/math/two-sat.test.cpp
documentation_of: math/two_sat.hpp
layout: document
title: 2-SAT
---
