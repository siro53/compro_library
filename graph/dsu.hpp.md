---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union-find.test.cpp
    title: test/union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dsu.hpp\"\nstruct UnionFind {\n    vector<int> par;\n\
    \n    UnionFind(int n) : par(n, -1) {}\n    void init(int n) { par.assign(n, -1);\
    \ }\n\n    int root(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = root(par[x]);\n    }\n\n    bool issame(int\
    \ x, int y) { return root(x) == root(y); }\n\n    bool merge(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if(x == y)\n            return\
    \ false;\n        if(par[x] > par[y])\n            swap(x, y); // merge technique\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \n    int size(int x) { return -par[root(x)]; }\n};\n"
  code: "struct UnionFind {\n    vector<int> par;\n\n    UnionFind(int n) : par(n,\
    \ -1) {}\n    void init(int n) { par.assign(n, -1); }\n\n    int root(int x) {\n\
    \        if(par[x] < 0)\n            return x;\n        else\n            return\
    \ par[x] = root(par[x]);\n    }\n\n    bool issame(int x, int y) { return root(x)\
    \ == root(y); }\n\n    bool merge(int x, int y) {\n        x = root(x);\n    \
    \    y = root(y);\n        if(x == y)\n            return false;\n        if(par[x]\
    \ > par[y])\n            swap(x, y); // merge technique\n        par[x] += par[y];\n\
    \        par[y] = x;\n        return true;\n    }\n\n    int size(int x) { return\
    \ -par[root(x)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dsu.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union-find.test.cpp
documentation_of: graph/dsu.hpp
layout: document
title: UnionFind
---
