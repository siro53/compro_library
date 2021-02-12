---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/doubling_tree.hpp
    title: graph/doubling_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lca.test.cpp
    title: test/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lca.hpp\"\nstruct LCA {\n    const int n = 0;\n  \
    \  const int log2_n = 0;\n    vector<vector<int>> par;\n    vector<int> depth;\n\
    \n    LCA(const vector<vector<int>> &g, int root)\n        : n(g.size()), log2_n(log2(n)\
    \ + 1), par(log2_n, vector<int>(n)),\n          depth(n) {\n        dfs(g, root,\
    \ -1, 0);\n        for(int k = 0; k + 1 < log2_n; k++) {\n            for(int\
    \ v = 0; v < n; v++) {\n                if(par[k][v] < 0) {\n                \
    \    par[k + 1][v] = -1;\n                } else {\n                    par[k\
    \ + 1][v] = par[k][par[k][v]];\n                }\n            }\n        }\n\
    \    }\n\n    void dfs(const vector<vector<int>> &g, int v, int p, int d) {\n\
    \        par[0][v] = p;\n        depth[v] = d;\n        for(auto &u : g[v]) {\n\
    \            if(u != p) {\n                dfs(g, u, v, d + 1);\n            }\n\
    \        }\n    }\n\n    int get_lca(int u, int v) {\n        // u\u3068v\u306E\
    \u6DF1\u3055\u304C\u540C\u3058\u306B\u306A\u308B\u307E\u3067\u8FBF\u308B\n   \
    \     if(depth[u] > depth[v]) {\n            swap(u, v);\n        }\n        for(int\
    \ k = 0; k < log2_n; k++) {\n            if(((depth[v] - depth[u]) >> k) & 1)\
    \ {\n                v = par[k][v];\n            }\n        }\n\n        if(u\
    \ == v) {\n            return u;\n        }\n\n        for(int k = log2_n - 1;\
    \ k >= 0; k--) {\n            if(par[k][u] != par[k][v]) {\n                u\
    \ = par[k][u];\n                v = par[k][v];\n            }\n        }\n   \
    \     return par[0][u];\n    }\n};\n"
  code: "struct LCA {\n    const int n = 0;\n    const int log2_n = 0;\n    vector<vector<int>>\
    \ par;\n    vector<int> depth;\n\n    LCA(const vector<vector<int>> &g, int root)\n\
    \        : n(g.size()), log2_n(log2(n) + 1), par(log2_n, vector<int>(n)),\n  \
    \        depth(n) {\n        dfs(g, root, -1, 0);\n        for(int k = 0; k +\
    \ 1 < log2_n; k++) {\n            for(int v = 0; v < n; v++) {\n             \
    \   if(par[k][v] < 0) {\n                    par[k + 1][v] = -1;\n           \
    \     } else {\n                    par[k + 1][v] = par[k][par[k][v]];\n     \
    \           }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<int>>\
    \ &g, int v, int p, int d) {\n        par[0][v] = p;\n        depth[v] = d;\n\
    \        for(auto &u : g[v]) {\n            if(u != p) {\n                dfs(g,\
    \ u, v, d + 1);\n            }\n        }\n    }\n\n    int get_lca(int u, int\
    \ v) {\n        // u\u3068v\u306E\u6DF1\u3055\u304C\u540C\u3058\u306B\u306A\u308B\
    \u307E\u3067\u8FBF\u308B\n        if(depth[u] > depth[v]) {\n            swap(u,\
    \ v);\n        }\n        for(int k = 0; k < log2_n; k++) {\n            if(((depth[v]\
    \ - depth[u]) >> k) & 1) {\n                v = par[k][v];\n            }\n  \
    \      }\n\n        if(u == v) {\n            return u;\n        }\n\n       \
    \ for(int k = log2_n - 1; k >= 0; k--) {\n            if(par[k][u] != par[k][v])\
    \ {\n                u = par[k][u];\n                v = par[k][v];\n        \
    \    }\n        }\n        return par[0][u];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy:
  - graph/doubling_tree.hpp
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lca.test.cpp
documentation_of: graph/lca.hpp
layout: document
redirect_from:
- /library/graph/lca.hpp
- /library/graph/lca.hpp.html
title: graph/lca.hpp
---
