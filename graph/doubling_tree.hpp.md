---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: "LCA(\u30C0\u30D6\u30EA\u30F3\u30B0)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \     return par[0][u];\n    }\n\n    int get_dist(int u, int v) {\n        return\
    \ depth[u] + depth[v] - 2 * depth[get_lca(u, v)];\n    }\n};\n#line 2 \"graph/doubling_tree.hpp\"\
    \n\ntemplate <class T> struct doubling_tree : LCA {\n    vector<vector<T>> db;\n\
    \    bool edge;\n    function<T(T, T)> f;\n    T E;\n    doubling_tree(const vector<vector<int>>\
    \ &g, int root, function<T(T, T)> f,\n                  T E)\n        : LCA::LCA(g,\
    \ root), f(f), E(E), db(log2_n, vector<T>(n, E)) {}\n    void build(const vector<T>\
    \ &init, bool is_edge) {\n        edge = is_edge;\n        for(int i = 0; i <\
    \ n; i++) db[0][i] = init[i];\n        for(int k = 0; k < log2_n - 1; k++) {\n\
    \            for(int i = 0; i < n; i++) {\n                if(par[k][i] < 0) {\n\
    \                    db[k + 1][i] = db[k][i];\n                } else {\n    \
    \                db[k + 1][i] = f(db[k][i], db[k][par[k][i]]);\n             \
    \   }\n            }\n        }\n    }\n    T query(int u, int v) {\n        if(depth[u]\
    \ > depth[v]) swap(u, v);\n        T res = E;\n        for(int k = 0; k < log2_n;\
    \ k++) {\n            if((depth[v] - depth[u]) >> k & 1) {\n                res\
    \ = f(res, db[k][v]), v = par[k][v];\n            }\n        }\n        if(u ==\
    \ v) return res;\n        for(int k = log2_n - 1; k >= 0; k--) {\n           \
    \ if(par[k][u] != par[k][v]) {\n                res = f(res, f(db[k][u], db[k][v]));\n\
    \                v = par[k][v], u = par[k][u];\n            }\n        }\n   \
    \     res = f(res, f(db[0][u], db[0][v]));\n        if(!edge) res = f(res, db[0][par[0][u]]);\n\
    \        return res;\n    }\n};\n"
  code: "#include \"lca.hpp\"\n\ntemplate <class T> struct doubling_tree : LCA {\n\
    \    vector<vector<T>> db;\n    bool edge;\n    function<T(T, T)> f;\n    T E;\n\
    \    doubling_tree(const vector<vector<int>> &g, int root, function<T(T, T)> f,\n\
    \                  T E)\n        : LCA::LCA(g, root), f(f), E(E), db(log2_n, vector<T>(n,\
    \ E)) {}\n    void build(const vector<T> &init, bool is_edge) {\n        edge\
    \ = is_edge;\n        for(int i = 0; i < n; i++) db[0][i] = init[i];\n       \
    \ for(int k = 0; k < log2_n - 1; k++) {\n            for(int i = 0; i < n; i++)\
    \ {\n                if(par[k][i] < 0) {\n                    db[k + 1][i] = db[k][i];\n\
    \                } else {\n                    db[k + 1][i] = f(db[k][i], db[k][par[k][i]]);\n\
    \                }\n            }\n        }\n    }\n    T query(int u, int v)\
    \ {\n        if(depth[u] > depth[v]) swap(u, v);\n        T res = E;\n       \
    \ for(int k = 0; k < log2_n; k++) {\n            if((depth[v] - depth[u]) >> k\
    \ & 1) {\n                res = f(res, db[k][v]), v = par[k][v];\n           \
    \ }\n        }\n        if(u == v) return res;\n        for(int k = log2_n - 1;\
    \ k >= 0; k--) {\n            if(par[k][u] != par[k][v]) {\n                res\
    \ = f(res, f(db[k][u], db[k][v]));\n                v = par[k][v], u = par[k][u];\n\
    \            }\n        }\n        res = f(res, f(db[0][u], db[0][v]));\n    \
    \    if(!edge) res = f(res, db[0][par[0][u]]);\n        return res;\n    }\n};"
  dependsOn:
  - graph/lca.hpp
  isVerificationFile: false
  path: graph/doubling_tree.hpp
  requiredBy: []
  timestamp: '2021-05-08 11:12:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/doubling_tree.hpp
layout: document
title: "\u6728\u4E0A\u306E\u30C0\u30D6\u30EA\u30F3\u30B0"
---
