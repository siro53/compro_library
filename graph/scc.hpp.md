---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.hpp\"\nstruct SCC {\n    vector<vector<int>> &G;\n\
    \    vector<vector<int>> revG;\n    vector<int> vs, comp;\n    vector<bool> seen;\n\
    \    int cnt;\n\n    SCC(vector<vector<int>> &g)\n        : G(g), revG(g.size()),\
    \ comp(g.size(), -1), seen(g.size(), false) {\n        int n = (int)g.size();\n\
    \        for(int i = 0; i < n; i++) {\n            for(const auto &u : g[i]) {\n\
    \                revG[u].emplace_back(i);\n            }\n        }\n        build();\n\
    \    }\n    void dfs(int v) {\n        seen[v] = true;\n        for(const int\
    \ &u : G[v]) {\n            if(!seen[u]) {\n                dfs(u);\n        \
    \    }\n        }\n        vs.emplace_back(v);\n    }\n    void rev_dfs(int v,\
    \ int id) {\n        seen[v] = true;\n        comp[v] = id;\n        for(const\
    \ int &u : revG[v]) {\n            if(comp[u] == -1) {\n                rev_dfs(u,\
    \ id);\n            }\n        }\n    }\n    void build() {\n        int n = (int)G.size();\n\
    \        for(int i = 0; i < n; i++) {\n            if(!seen[i]) {\n          \
    \      dfs(i);\n            }\n        }\n        reverse(ALL(vs));\n        cnt\
    \ = 0;\n        for(const int &v : vs) {\n            if(comp[v] == -1) {\n  \
    \              rev_dfs(v, cnt);\n                cnt++;\n            }\n     \
    \   }\n    }\n    int operator[](int k) const { return comp[k]; }\n};\n"
  code: "struct SCC {\n    vector<vector<int>> &G;\n    vector<vector<int>> revG;\n\
    \    vector<int> vs, comp;\n    vector<bool> seen;\n    int cnt;\n\n    SCC(vector<vector<int>>\
    \ &g)\n        : G(g), revG(g.size()), comp(g.size(), -1), seen(g.size(), false)\
    \ {\n        int n = (int)g.size();\n        for(int i = 0; i < n; i++) {\n  \
    \          for(const auto &u : g[i]) {\n                revG[u].emplace_back(i);\n\
    \            }\n        }\n        build();\n    }\n    void dfs(int v) {\n  \
    \      seen[v] = true;\n        for(const int &u : G[v]) {\n            if(!seen[u])\
    \ {\n                dfs(u);\n            }\n        }\n        vs.emplace_back(v);\n\
    \    }\n    void rev_dfs(int v, int id) {\n        seen[v] = true;\n        comp[v]\
    \ = id;\n        for(const int &u : revG[v]) {\n            if(comp[u] == -1)\
    \ {\n                rev_dfs(u, id);\n            }\n        }\n    }\n    void\
    \ build() {\n        int n = (int)G.size();\n        for(int i = 0; i < n; i++)\
    \ {\n            if(!seen[i]) {\n                dfs(i);\n            }\n    \
    \    }\n        reverse(ALL(vs));\n        cnt = 0;\n        for(const int &v\
    \ : vs) {\n            if(comp[v] == -1) {\n                rev_dfs(v, cnt);\n\
    \                cnt++;\n            }\n        }\n    }\n    int operator[](int\
    \ k) const { return comp[k]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
