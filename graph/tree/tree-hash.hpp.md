---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':question:'
    path: graph/tree/diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':question:'
    path: random/rng.hpp
    title: "\u4E71\u6570\u751F\u6210"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':x:'
    path: test/mytest/graph/tree-api.test.cpp
    title: test/mytest/graph/tree-api.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \    std::mt19937_64 mt;\n};\n\nclass RNG_0_1 {\n  public:\n    RNG_0_1() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    // [0.0, 1.0)\n    double rand() {\n      auto bits = mt() >> 11;\n\
    \      return (double)bits / denomitor;\n    }\n\n    auto operator()() { return\
    \ rand(); }\n\n  private:\n    std::mt19937_64 mt;\n    const double denomitor\
    \ = 1LL << 53;\n};\n#line 2 \"graph/tree/diameter.hpp\"\n\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"graph/graph_template.hpp\"\n\
    \n#include <cassert>\n#include <cstddef>\n#line 6 \"graph/graph_template.hpp\"\
    \n\ntemplate <typename Cost = int> struct Edge {\n    int from, to;\n    Cost\
    \ cost;\n    int id;\n    Edge() = default;\n    explicit Edge(int from, int to,\
    \ Cost cost = 1, int id = -1)\n        : from(from), to(to), cost(cost), id(id)\
    \ {}\n    operator int() const { return to; }\n};\n\ntemplate <typename Cost =\
    \ int> class Graph {\n  public:\n    Graph() = default;\n    explicit Graph(int\
    \ N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int from, int\
    \ to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        G[from].emplace_back(from, to, cost, M++);\n    }\n\
    \n    inline void add_undirected_edge(int from, int to, Cost cost = 1) {\n   \
    \     assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n   \
    \     G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline std::size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 8 \"graph/tree/diameter.hpp\"\n\ntemplate <typename Cost = int>\nstd::pair<Cost,\
    \ std::vector<int>> get_diameter(const Graph<Cost> &G) {\n    std::vector<Cost>\
    \ depth(G.size());\n    std::vector<int> par(G.size(), -1);\n    auto dfs = [&](auto\
    \ &&self, int u, int p, Cost d) -> void {\n        depth[u] = d;\n        par[u]\
    \ = p;\n        for(const auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            self(self, e.to, u, d + e.cost);\n        }\n    };\n    dfs(dfs,\
    \ 0, -1, 0);\n    int from = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    dfs(dfs, from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<int> path = {to};\n    while(1) {\n      \
    \  int nxt = par[path.back()];\n        if(nxt == -1) break;\n        path.push_back(nxt);\n\
    \    }\n    return std::make_pair(depth[to], path);\n}\n#line 5 \"graph/tree/tree-hash.hpp\"\
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
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/graph/tree-api.test.cpp
  - test/aoj/aoj2821.test.cpp
documentation_of: graph/tree/tree-hash.hpp
layout: document
link: https://snuke.hatenablog.com/entry/2017/02/03/054210
title: "\u6728\u30CF\u30C3\u30B7\u30E5"
---

## このライブラリでできること

`TreeHash<Cost>` は、頂点番号によらない木の形をハッシュ値で表します。2つの木が同じ形かを高速に比較したい場合に使えます。ただしハッシュには衝突があるため、同じ値になったことは同型であることの証明ではありません。

直径の中央の1頂点または2頂点を根の候補とし、子のハッシュを積でまとめて深さごとの乱数を加えます。積を使うことで子の順番に依存しない値を作り、根の候補から得た最小値を木全体のハッシュとします。頂点数 $N$ に対する計算時間は $O(N)$ です。

## 使い方

木を渡すか、頂点数から構築して辺を追加した後、`get_hash()` を呼びます。例の2つの木は辺の端点番号が異なりますが、どちらも3頂点の鎖なので同じハッシュになります。

ハッシュは同じ実行中の同じ `Cost` 型で比較してください。乱数表が共有されるため、別々に構築した木でも同じ基準で計算できます。

```cpp
#include "template/template.cpp"
#include "graph/tree/tree-hash.hpp"

int main() {
    TreeHash<> a(3), b(3);
    a.add_edge(0, 1); a.add_edge(1, 2);
    b.add_edge(0, 2); b.add_edge(2, 1);
    assert(a.get_hash() == b.get_hash());
}
```

## API・計算量

木と作業領域は1オブジェクトあたり $O(N)$、再帰スタックも最大 $O(N)$ です。共有の乱数表は構築ごとに $N$ 個追記され、構築した全オブジェクトの頂点数の総和だけ増えます。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `TreeHash(N)` | N 頂点と深さごとの乱数を用意。 | O(N) |
| `TreeHash(G)` | Graph をコピーし乱数を用意。 | O(N) |
| `add_edge(u, v, cost=1)` | 無向辺を追加。 | 償却 O(1) |
| `get_hash()` | 根なし木のハッシュ値（unsigned long long）。 | O(N) |

## 利用条件と実装上の注意

非空・連結な無向木を使い、辺重みはすべて1にしてください。直径の中心を木の中心として使うための条件です。頂点ラベルや辺重みはハッシュには含まれません。

プロセスを起動し直すと乱数が変わるため、保存した値を別の実行で比較する用途には向きません。また静的な乱数表は構築ごとに $N$ 個追記され、構築した木の頂点数の総和だけ増えます。再帰スタックも最悪 $O(N)$ 必要です。
