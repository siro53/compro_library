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
  bundledCode: "#line 2 \"graph/namori.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    #line 4 \"graph/namori.hpp\"\n\ntemplate <typename Cost> class Namori : public\
    \ Graph<Cost> {\n  public:\n    using Graph<Cost>::Graph;\n    using Graph<Cost>::G;\n\
    \n    void build() {\n        int N = (int)G.size();\n        std::vector<int>\
    \ deg(N), st;\n        std::vector<bool> seen(N);\n        for(int i = 0; i <\
    \ N; i++) {\n            deg[i] = (int)G[i].size();\n            if(deg[i] ==\
    \ 1) {\n                st.emplace_back(i);\n                seen[i] = true;\n\
    \            }\n        }\n        while(!st.empty()) {\n            int u = st.back();\n\
    \            st.pop_back();\n            for(int v : G[u]) {\n               \
    \ if(seen[v]) continue;\n                deg[v]--;\n                if(deg[v]\
    \ == 1) {\n                    st.emplace_back(v);\n                    seen[v]\
    \ = true;\n                }\n            }\n        }\n        loop_id.resize(N,\
    \ -1);\n        std::vector<int> loop;\n        for(int i = 0; i < N; i++) {\n\
    \            if(seen[i]) continue;\n            auto dfs = [&](auto &&self, int\
    \ u) -> void {\n                loop_id[u] = (int)loop.size();\n             \
    \   loop.push_back(u);\n                seen[u] = true;\n                for(int\
    \ v : G[u]) {\n                    if(seen[v]) continue;\n                   \
    \ self(self, v);\n                }\n            };\n            dfs(dfs, i);\n\
    \            break;\n        }\n        for(int i = 0; i < (int)loop.size(); i++)\
    \ {\n            auto dfs = [&](auto&& self, int u) -> void {\n              \
    \  for(int v : G[u]) {\n                    if(loop_id[v] != -1) continue;\n \
    \                   loop_id[v] = loop_id[u];\n                    self(self, v);\n\
    \                }\n            };\n            dfs(dfs, loop[i]);\n        }\n\
    \    }\n    int operator[](int i) const { return loop_id[i]; }\n\n  private:\n\
    \    std::vector<int> loop_id;\n};\n"
  code: "#pragma once\n\n#include \"graph_template.hpp\"\n\ntemplate <typename Cost>\
    \ class Namori : public Graph<Cost> {\n  public:\n    using Graph<Cost>::Graph;\n\
    \    using Graph<Cost>::G;\n\n    void build() {\n        int N = (int)G.size();\n\
    \        std::vector<int> deg(N), st;\n        std::vector<bool> seen(N);\n  \
    \      for(int i = 0; i < N; i++) {\n            deg[i] = (int)G[i].size();\n\
    \            if(deg[i] == 1) {\n                st.emplace_back(i);\n        \
    \        seen[i] = true;\n            }\n        }\n        while(!st.empty())\
    \ {\n            int u = st.back();\n            st.pop_back();\n            for(int\
    \ v : G[u]) {\n                if(seen[v]) continue;\n                deg[v]--;\n\
    \                if(deg[v] == 1) {\n                    st.emplace_back(v);\n\
    \                    seen[v] = true;\n                }\n            }\n     \
    \   }\n        loop_id.resize(N, -1);\n        std::vector<int> loop;\n      \
    \  for(int i = 0; i < N; i++) {\n            if(seen[i]) continue;\n         \
    \   auto dfs = [&](auto &&self, int u) -> void {\n                loop_id[u] =\
    \ (int)loop.size();\n                loop.push_back(u);\n                seen[u]\
    \ = true;\n                for(int v : G[u]) {\n                    if(seen[v])\
    \ continue;\n                    self(self, v);\n                }\n         \
    \   };\n            dfs(dfs, i);\n            break;\n        }\n        for(int\
    \ i = 0; i < (int)loop.size(); i++) {\n            auto dfs = [&](auto&& self,\
    \ int u) -> void {\n                for(int v : G[u]) {\n                    if(loop_id[v]\
    \ != -1) continue;\n                    loop_id[v] = loop_id[u];\n           \
    \         self(self, v);\n                }\n            };\n            dfs(dfs,\
    \ loop[i]);\n        }\n    }\n    int operator[](int i) const { return loop_id[i];\
    \ }\n\n  private:\n    std::vector<int> loop_id;\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/namori.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/namori.hpp
layout: document
redirect_from:
- /library/graph/namori.hpp
- /library/graph/namori.hpp.html
title: graph/namori.hpp
---
