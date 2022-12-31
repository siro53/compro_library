---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ1330.test.cpp
    title: test/AOJ1330.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/weighted_dsu.hpp\"\ntemplate<class S, S (*op)(S, S),\
    \ S (*e)(), S (*inv)(S)>\nstruct WeightedUnionFind {\n    vector<int> par;\n \
    \   vector<S> weight;\n\n    WeightedUnionFind(int n): par(n, -1), weight(n, e())\
    \ {}\n    int root(int u) {\n        if(par[u] < 0) return u;\n        int r =\
    \ root(par[u]);\n        weight[u] = op(weight[u], weight[par[u]]);\n        return\
    \ (par[u] = r);\n    }\n    bool same(int u, int v) { return (root(u) == root(v));\
    \ }\n    int size(int u) { return (-par[root(u)]); }\n    S get_weight(int u)\
    \ {\n        root(u);\n        return weight[u];\n    }\n    // weight[v] = weight[u]\
    \ + w\n    bool merge(int u, int v, S w) {\n        w = op(get_weight(u), w);\n\
    \        w = op(inv(get_weight(v)), w);\n        u = root(u);\n        v = root(v);\n\
    \        if(u == v) return false;\n        if(par[u] > par[v]) {\n           \
    \ swap(u, v);\n            w = inv(w);\n        }\n        par[u] += par[v];\n\
    \        par[v] = u;\n        weight[v] = w;\n        return true;\n    }\n  \
    \  // weight[v] - weight[u]\n    S get_diff(int u, int v) {\n        assert(same(u,\
    \ v));\n        return (op(inv(get_weight(u)), get_weight(v)));\n    }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), S (*inv)(S)>\nstruct WeightedUnionFind\
    \ {\n    vector<int> par;\n    vector<S> weight;\n\n    WeightedUnionFind(int\
    \ n): par(n, -1), weight(n, e()) {}\n    int root(int u) {\n        if(par[u]\
    \ < 0) return u;\n        int r = root(par[u]);\n        weight[u] = op(weight[u],\
    \ weight[par[u]]);\n        return (par[u] = r);\n    }\n    bool same(int u,\
    \ int v) { return (root(u) == root(v)); }\n    int size(int u) { return (-par[root(u)]);\
    \ }\n    S get_weight(int u) {\n        root(u);\n        return weight[u];\n\
    \    }\n    // weight[v] = weight[u] + w\n    bool merge(int u, int v, S w) {\n\
    \        w = op(get_weight(u), w);\n        w = op(inv(get_weight(v)), w);\n \
    \       u = root(u);\n        v = root(v);\n        if(u == v) return false;\n\
    \        if(par[u] > par[v]) {\n            swap(u, v);\n            w = inv(w);\n\
    \        }\n        par[u] += par[v];\n        par[v] = u;\n        weight[v]\
    \ = w;\n        return true;\n    }\n    // weight[v] - weight[u]\n    S get_diff(int\
    \ u, int v) {\n        assert(same(u, v));\n        return (op(inv(get_weight(u)),\
    \ get_weight(v)));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/weighted_dsu.hpp
  requiredBy: []
  timestamp: '2022-12-31 12:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ1330.test.cpp
documentation_of: graph/weighted_dsu.hpp
layout: document
redirect_from:
- /library/graph/weighted_dsu.hpp
- /library/graph/weighted_dsu.hpp.html
title: graph/weighted_dsu.hpp
---
