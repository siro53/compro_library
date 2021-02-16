---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ2821.test.cpp
    title: test/AOJ2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree_hash.hpp\"\nclass TreeHash {\n  private:\n  \
    \  using ull = unsigned long long;\n    using ui128 = __uint128_t;\n    static\
    \ const ull mod = (1ULL << 61) - 1;\n    static vector<ull> rnd;\n    int N;\n\
    \    vector<vector<int>> G;\n    inline ull add(ull a, ull b) {\n        if((a\
    \ += b) >= mod) {\n            a -= mod;\n        }\n        return a;\n    }\n\
    \    inline ull mul(ull a, ull b) {\n        ui128 t = (ui128)a * b;\n       \
    \ ull na = t >> 61;\n        ull nb = t & mod;\n        if((na += nb) >= mod)\
    \ {\n            na -= mod;\n        }\n        return na;\n    }\n    ull hash_dfs(int\
    \ v, int p, int d, vector<ull> &res) {\n        for(const int &u : G[v]) {\n \
    \           if(u != p) {\n                res[v] = mul(res[v], hash_dfs(u, v,\
    \ d + 1, res));\n            }\n        }\n        return res[v] = add(res[v],\
    \ rnd[d]);\n    }\n    vector<int> get_diameter_path() {\n        vector<int>\
    \ depth(N), par(N);\n\n        auto dfs = [&](auto &&dfs, int v, int p, int d)\
    \ -> void {\n            depth[v] = d;\n            par[v] = p;\n            for(const\
    \ int &u : G[v]) {\n                if(u != p) {\n                    dfs(dfs,\
    \ u, v, d + 1);\n                }\n            }\n        };\n\n        dfs(dfs,\
    \ 0, -1, 0);\n        int from = max_element(ALL(depth)) - depth.begin();\n  \
    \      dfs(dfs, from, -1, 0);\n        int to = max_element(ALL(depth)) - depth.begin();\n\
    \n        vector<int> res;\n        int now = to;\n        while(now != from)\
    \ {\n            res.emplace_back(now);\n            now = par[now];\n       \
    \ }\n        res.emplace_back(now);\n\n        return res;\n    }\n\n  public:\n\
    \    TreeHash(int n) : N(n), G(n) {\n        random_device seed_gen;\n       \
    \ mt19937_64 engine(seed_gen());\n        uniform_int_distribution<ull> rand(1,\
    \ mod - 1);\n        while((int)rnd.size() < N) {\n            rnd.emplace_back(rand(engine));\n\
    \        }\n    }\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    ull get_hash() {\n        auto dpath\
    \ = get_diameter_path();\n        int len = (int)dpath.size();\n        vector<int>\
    \ cent;\n        if(len & 1) {\n            cent = {dpath[len / 2]};\n       \
    \ } else {\n            cent = {dpath[len / 2], dpath[len / 2 - 1]};\n       \
    \ }\n        ull res = UINT64_MAX;\n        for(const int &root : cent) {\n  \
    \          vector<ull> hashed(N, 1);\n            hash_dfs(root, -1, 0, hashed);\n\
    \            chmin(res, hashed[root]);\n        }\n        return res;\n    }\n\
    };\n\nvector<TreeHash::ull> TreeHash::rnd;\n"
  code: "class TreeHash {\n  private:\n    using ull = unsigned long long;\n    using\
    \ ui128 = __uint128_t;\n    static const ull mod = (1ULL << 61) - 1;\n    static\
    \ vector<ull> rnd;\n    int N;\n    vector<vector<int>> G;\n    inline ull add(ull\
    \ a, ull b) {\n        if((a += b) >= mod) {\n            a -= mod;\n        }\n\
    \        return a;\n    }\n    inline ull mul(ull a, ull b) {\n        ui128 t\
    \ = (ui128)a * b;\n        ull na = t >> 61;\n        ull nb = t & mod;\n    \
    \    if((na += nb) >= mod) {\n            na -= mod;\n        }\n        return\
    \ na;\n    }\n    ull hash_dfs(int v, int p, int d, vector<ull> &res) {\n    \
    \    for(const int &u : G[v]) {\n            if(u != p) {\n                res[v]\
    \ = mul(res[v], hash_dfs(u, v, d + 1, res));\n            }\n        }\n     \
    \   return res[v] = add(res[v], rnd[d]);\n    }\n    vector<int> get_diameter_path()\
    \ {\n        vector<int> depth(N), par(N);\n\n        auto dfs = [&](auto &&dfs,\
    \ int v, int p, int d) -> void {\n            depth[v] = d;\n            par[v]\
    \ = p;\n            for(const int &u : G[v]) {\n                if(u != p) {\n\
    \                    dfs(dfs, u, v, d + 1);\n                }\n            }\n\
    \        };\n\n        dfs(dfs, 0, -1, 0);\n        int from = max_element(ALL(depth))\
    \ - depth.begin();\n        dfs(dfs, from, -1, 0);\n        int to = max_element(ALL(depth))\
    \ - depth.begin();\n\n        vector<int> res;\n        int now = to;\n      \
    \  while(now != from) {\n            res.emplace_back(now);\n            now =\
    \ par[now];\n        }\n        res.emplace_back(now);\n\n        return res;\n\
    \    }\n\n  public:\n    TreeHash(int n) : N(n), G(n) {\n        random_device\
    \ seed_gen;\n        mt19937_64 engine(seed_gen());\n        uniform_int_distribution<ull>\
    \ rand(1, mod - 1);\n        while((int)rnd.size() < N) {\n            rnd.emplace_back(rand(engine));\n\
    \        }\n    }\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    ull get_hash() {\n        auto dpath\
    \ = get_diameter_path();\n        int len = (int)dpath.size();\n        vector<int>\
    \ cent;\n        if(len & 1) {\n            cent = {dpath[len / 2]};\n       \
    \ } else {\n            cent = {dpath[len / 2], dpath[len / 2 - 1]};\n       \
    \ }\n        ull res = UINT64_MAX;\n        for(const int &root : cent) {\n  \
    \          vector<ull> hashed(N, 1);\n            hash_dfs(root, -1, 0, hashed);\n\
    \            chmin(res, hashed[root]);\n        }\n        return res;\n    }\n\
    };\n\nvector<TreeHash::ull> TreeHash::rnd;"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_hash.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ2821.test.cpp
documentation_of: graph/tree_hash.hpp
layout: document
redirect_from:
- /library/graph/tree_hash.hpp
- /library/graph/tree_hash.hpp.html
title: graph/tree_hash.hpp
---
