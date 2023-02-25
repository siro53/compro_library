---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/unionfind.test.cpp
    title: test/library-checker/data-structure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <vector>\n\nclass UnionFind {\n \
    \ public:\n    UnionFind() = default;\n    explicit UnionFind(int n) : N(n), parent_or_size(n,\
    \ -1) {}\n    int leader(int u) {\n        assert(0 <= u && u < N);\n        if(parent_or_size[u]\
    \ < 0) return u;\n        return (parent_or_size[u] = leader(parent_or_size[u]));\n\
    \    }\n    bool same(int u, int v) { return (leader(u) == leader(v)); }\n   \
    \ bool merge(int u, int v) {\n        u = leader(u);\n        v = leader(v);\n\
    \        if(u == v) return false;\n        if(-parent_or_size[u] < -parent_or_size[v])\
    \ std::swap(u, v);\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        return true;\n    }\n    int size(int u) { return (-parent_or_size[leader(u)]);\
    \ }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int> leaders(N),\
    \ group_size(N, 0);\n        for(int i = 0; i < N; i++) {\n            leaders[i]\
    \ = leader(i);\n            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ g(N);\n        for(int i = 0; i < N; i++) g[i].reserve(group_size[i]);\n   \
    \     for(int i = 0; i < N; i++) g[leaders[i]].push_back(i);\n        g.erase(std::remove_if(\n\
    \                    g.begin(), g.end(),\n                    [&](const std::vector<int>\
    \ &v) { return v.empty(); }),\n                g.end());\n        return g;\n\
    \    }\n    std::map<int, std::vector<int>> groups_with_map() {\n        std::map<int,\
    \ std::vector<int>> g;\n        for(int i = 0; i < N; i++) {\n            int\
    \ l = leader(i);\n            if(!g.count(l)) g[l].push_back(i);\n        }\n\
    \        return g;\n    }\n\n  private:\n    int N;\n    std::vector<int> parent_or_size;\n\
    };\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <vector>\n\nclass UnionFind {\n  public:\n    UnionFind() = default;\n\
    \    explicit UnionFind(int n) : N(n), parent_or_size(n, -1) {}\n    int leader(int\
    \ u) {\n        assert(0 <= u && u < N);\n        if(parent_or_size[u] < 0) return\
    \ u;\n        return (parent_or_size[u] = leader(parent_or_size[u]));\n    }\n\
    \    bool same(int u, int v) { return (leader(u) == leader(v)); }\n    bool merge(int\
    \ u, int v) {\n        u = leader(u);\n        v = leader(v);\n        if(u ==\
    \ v) return false;\n        if(-parent_or_size[u] < -parent_or_size[v]) std::swap(u,\
    \ v);\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        return true;\n    }\n    int size(int u) { return (-parent_or_size[leader(u)]);\
    \ }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int> leaders(N),\
    \ group_size(N, 0);\n        for(int i = 0; i < N; i++) {\n            leaders[i]\
    \ = leader(i);\n            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ g(N);\n        for(int i = 0; i < N; i++) g[i].reserve(group_size[i]);\n   \
    \     for(int i = 0; i < N; i++) g[leaders[i]].push_back(i);\n        g.erase(std::remove_if(\n\
    \                    g.begin(), g.end(),\n                    [&](const std::vector<int>\
    \ &v) { return v.empty(); }),\n                g.end());\n        return g;\n\
    \    }\n    std::map<int, std::vector<int>> groups_with_map() {\n        std::map<int,\
    \ std::vector<int>> g;\n        for(int i = 0; i < N; i++) {\n            int\
    \ l = leader(i);\n            if(!g.count(l)) g[l].push_back(i);\n        }\n\
    \        return g;\n    }\n\n  private:\n    int N;\n    std::vector<int> parent_or_size;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/unionfind.test.cpp
documentation_of: data-structure/unionfind.hpp
layout: document
redirect_from:
- /library/data-structure/unionfind.hpp
- /library/data-structure/unionfind.hpp.html
title: data-structure/unionfind.hpp
---
