---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/scc.test.cpp
    title: test/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.hpp\"\nclass SCC {\n  private:\n    vector<vector<int>>\
    \ G;\n    vector<vector<int>> revG;\n    vector<int> vs, comp;\n    vector<bool>\
    \ seen;\n    int cnt;\n    void dfs(int v) {\n        seen[v] = true;\n      \
    \  for(const int &u : G[v]) {\n            if(!seen[u]) { dfs(u); }\n        }\n\
    \        vs.emplace_back(v);\n    }\n    void rev_dfs(int v, int id) {\n     \
    \   seen[v] = true;\n        comp[v] = id;\n        for(const int &u : revG[v])\
    \ {\n            if(comp[u] == -1) { rev_dfs(u, id); }\n        }\n    }\n\n \
    \ public:\n    SCC(int N) : G(N), revG(N), comp(N, -1), seen(N, false) {}\n  \
    \  SCC(vector<vector<int>> g)\n        : G(g), revG(g.size()), comp(g.size(),\
    \ -1), seen(g.size(), false) {\n        int n = (int)g.size();\n        for(int\
    \ i = 0; i < n; i++) {\n            for(const auto &u : g[i]) { revG[u].emplace_back(i);\
    \ }\n        }\n    }\n    void add_edge(int i, int j) {\n        G[i].emplace_back(j);\n\
    \        revG[j].emplace_back(i);\n    }\n    void build() {\n        int n =\
    \ (int)G.size();\n        for(int i = 0; i < n; i++) {\n            if(!seen[i])\
    \ { dfs(i); }\n        }\n        reverse(ALL(vs));\n        cnt = 0;\n      \
    \  for(const int &v : vs) {\n            if(comp[v] == -1) {\n               \
    \ rev_dfs(v, cnt);\n                cnt++;\n            }\n        }\n    }\n\
    \    int operator[](int k) const { return comp[k]; }\n    int size() const { return\
    \ cnt; }\n};\n"
  code: "class SCC {\n  private:\n    vector<vector<int>> G;\n    vector<vector<int>>\
    \ revG;\n    vector<int> vs, comp;\n    vector<bool> seen;\n    int cnt;\n   \
    \ void dfs(int v) {\n        seen[v] = true;\n        for(const int &u : G[v])\
    \ {\n            if(!seen[u]) { dfs(u); }\n        }\n        vs.emplace_back(v);\n\
    \    }\n    void rev_dfs(int v, int id) {\n        seen[v] = true;\n        comp[v]\
    \ = id;\n        for(const int &u : revG[v]) {\n            if(comp[u] == -1)\
    \ { rev_dfs(u, id); }\n        }\n    }\n\n  public:\n    SCC(int N) : G(N), revG(N),\
    \ comp(N, -1), seen(N, false) {}\n    SCC(vector<vector<int>> g)\n        : G(g),\
    \ revG(g.size()), comp(g.size(), -1), seen(g.size(), false) {\n        int n =\
    \ (int)g.size();\n        for(int i = 0; i < n; i++) {\n            for(const\
    \ auto &u : g[i]) { revG[u].emplace_back(i); }\n        }\n    }\n    void add_edge(int\
    \ i, int j) {\n        G[i].emplace_back(j);\n        revG[j].emplace_back(i);\n\
    \    }\n    void build() {\n        int n = (int)G.size();\n        for(int i\
    \ = 0; i < n; i++) {\n            if(!seen[i]) { dfs(i); }\n        }\n      \
    \  reverse(ALL(vs));\n        cnt = 0;\n        for(const int &v : vs) {\n   \
    \         if(comp[v] == -1) {\n                rev_dfs(v, cnt);\n            \
    \    cnt++;\n            }\n        }\n    }\n    int operator[](int k) const\
    \ { return comp[k]; }\n    int size() const { return cnt; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-02-22 10:22:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
