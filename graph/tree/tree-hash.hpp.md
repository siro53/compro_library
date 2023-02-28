---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/diameter.hpp
    title: graph/tree/diameter.hpp
  - icon: ':heavy_check_mark:'
    path: random/rng.hpp
    title: random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/tree-hash.hpp\"\n\n#line 2 \"random/rng.hpp\"\
    \n\n#include <chrono>\n#include <random>\n\nclass RNG32 {\n  public:\n    RNG32()\
    \ : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n    //\
    \ [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n#line 2 \"graph/tree/diameter.hpp\"\n\n#include\
    \ <algorithm>\n#include <utility>\n#include <vector>\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename\
    \ Cost = int> struct Edge {\n    int from, to;\n    Cost cost;\n    int id;\n\
    \    Edge() = default;\n    explicit Edge(int from, int to, Cost cost = 1, int\
    \ id = -1)\n        : from(from), to(to), cost(cost), id(id) {}\n    operator\
    \ int() const { return to; }\n};\n\ntemplate <typename Cost = int> class Graph\
    \ {\n  public:\n    Graph() = default;\n    explicit Graph(int N) : N(N), M(0),\
    \ G(N) {}\n\n    inline void add_directed_edge(int from, int to, Cost cost = 1)\
    \ {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n\
    \        G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void\
    \ add_undirected_edge(int from, int to, Cost cost = 1) {\n        assert(0 <=\
    \ from && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n \
    \   inline size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  private:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 8 \"graph/tree/diameter.hpp\"\
    \n\ntemplate <typename Cost = int>\nstd::pair<Cost, std::vector<int>> get_diameter(const\
    \ Graph<Cost> &G) {\n    std::vector<Cost> depth(G.size());\n    std::vector<int>\
    \ par(G.size(), -1);\n    auto dfs = [&](auto &&self, int u, int p, Cost d) ->\
    \ void {\n        depth[u] = d;\n        par[u] = p;\n        for(const auto &e\
    \ : G[u]) {\n            if(e.to == p) continue;\n            self(self, e.to,\
    \ u, d + e.cost);\n        }\n    };\n    dfs(dfs, 0, -1, 0);\n    int from =\
    \ std::max_element(depth.begin(), depth.end()) - depth.begin();\n    dfs(dfs,\
    \ from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    std::vector<int> path = {to};\n    while(1) {\n        int nxt = par[path.back()];\n\
    \        if(nxt == -1) break;\n        path.push_back(nxt);\n    }\n    return\
    \ std::make_pair(depth[to], path);\n}\n#line 5 \"graph/tree/tree-hash.hpp\"\n\n\
    template <typename Cost = int> class TreeHash {\n  public:\n    explicit TreeHash(int\
    \ n) : G(n) {\n        RNG64 rng;\n        for(int i = 0; i < n; i++) rnd.push_back(rng.randint(1,\
    \ mod - 1));\n    }\n    explicit TreeHash(const Graph<Cost> &g) : G(g) {\n  \
    \      RNG64 rng;\n        for(int i = 0; i < (int)G.size(); i++)\n          \
    \  rnd.push_back(rng.randint(1, mod - 1));\n    }\n    inline void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    unsigned long long get_hash() {\n        auto [_, path] = get_diameter(G);\n\
    \        int len = (int)path.size();\n        std::vector<int> cent;\n       \
    \ if(len & 1) {\n            cent = {path[len / 2]};\n        } else {\n     \
    \       cent = {path[len / 2], path[len / 2 - 1]};\n        }\n        unsigned\
    \ long long res = std::numeric_limits<unsigned long long>::max();\n        for(const\
    \ int &root : cent) {\n            std::vector<unsigned long long> hashed(G.size(),\
    \ 1);\n            hash_dfs(root, -1, 0, hashed);\n            res = std::min(res,\
    \ hashed[root]);\n        }\n        return res;\n    }\n\n  private:\n    Graph<Cost>\
    \ G;\n    static constexpr unsigned long long mod = (1ULL << 61) - 1;\n    static\
    \ inline std::vector<unsigned long long> rnd;\n\n    inline unsigned long long\
    \ add(unsigned long long a, unsigned long long b) {\n        if((a += b) >= mod)\
    \ a -= mod;\n        return a;\n    }\n    inline unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n        __uint128_t t = a;\n        t\
    \ *= b;\n        unsigned long long na = t >> 61;\n        unsigned long long\
    \ nb = t & mod;\n        if((na += nb) >= mod) na -= mod;\n        return na;\n\
    \    }\n    unsigned long long hash_dfs(int v, int p, int d,\n               \
    \                 std::vector<unsigned long long> &res) {\n        for(const auto\
    \ &e : G[v]) {\n            if(e.to != p) {\n                res[v] = mul(res[v],\
    \ hash_dfs(e.to, v, d + 1, res));\n            }\n        }\n        return res[v]\
    \ = add(res[v], rnd[d]);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../../random/rng.hpp\"\n#include \"diameter.hpp\"\
    \n\ntemplate <typename Cost = int> class TreeHash {\n  public:\n    explicit TreeHash(int\
    \ n) : G(n) {\n        RNG64 rng;\n        for(int i = 0; i < n; i++) rnd.push_back(rng.randint(1,\
    \ mod - 1));\n    }\n    explicit TreeHash(const Graph<Cost> &g) : G(g) {\n  \
    \      RNG64 rng;\n        for(int i = 0; i < (int)G.size(); i++)\n          \
    \  rnd.push_back(rng.randint(1, mod - 1));\n    }\n    inline void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    unsigned long long get_hash() {\n        auto [_, path] = get_diameter(G);\n\
    \        int len = (int)path.size();\n        std::vector<int> cent;\n       \
    \ if(len & 1) {\n            cent = {path[len / 2]};\n        } else {\n     \
    \       cent = {path[len / 2], path[len / 2 - 1]};\n        }\n        unsigned\
    \ long long res = std::numeric_limits<unsigned long long>::max();\n        for(const\
    \ int &root : cent) {\n            std::vector<unsigned long long> hashed(G.size(),\
    \ 1);\n            hash_dfs(root, -1, 0, hashed);\n            res = std::min(res,\
    \ hashed[root]);\n        }\n        return res;\n    }\n\n  private:\n    Graph<Cost>\
    \ G;\n    static constexpr unsigned long long mod = (1ULL << 61) - 1;\n    static\
    \ inline std::vector<unsigned long long> rnd;\n\n    inline unsigned long long\
    \ add(unsigned long long a, unsigned long long b) {\n        if((a += b) >= mod)\
    \ a -= mod;\n        return a;\n    }\n    inline unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n        __uint128_t t = a;\n        t\
    \ *= b;\n        unsigned long long na = t >> 61;\n        unsigned long long\
    \ nb = t & mod;\n        if((na += nb) >= mod) na -= mod;\n        return na;\n\
    \    }\n    unsigned long long hash_dfs(int v, int p, int d,\n               \
    \                 std::vector<unsigned long long> &res) {\n        for(const auto\
    \ &e : G[v]) {\n            if(e.to != p) {\n                res[v] = mul(res[v],\
    \ hash_dfs(e.to, v, d + 1, res));\n            }\n        }\n        return res[v]\
    \ = add(res[v], rnd[d]);\n    }\n};"
  dependsOn:
  - random/rng.hpp
  - graph/tree/diameter.hpp
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/tree-hash.hpp
  requiredBy: []
  timestamp: '2023-02-28 22:24:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj2821.test.cpp
documentation_of: graph/tree/tree-hash.hpp
layout: document
redirect_from:
- /library/graph/tree/tree-hash.hpp
- /library/graph/tree/tree-hash.hpp.html
title: graph/tree/tree-hash.hpp
---
