---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/lca-and-empty-two-sat.test.cpp
    title: test/mytest/graph/lca-and-empty-two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/tree-api.test.cpp
    title: test/mytest/graph/tree-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/lca.hpp\"\n\n#include <cmath>\n#include <vector>\n\
    \n#line 2 \"graph/graph_template.hpp\"\n\n#include <cassert>\n#include <cstddef>\n\
    #line 6 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct\
    \ Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n\
    \    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n    operator int() const { return to; }\n};\n\
    \ntemplate <typename Cost = int> class Graph {\n  public:\n    Graph() = default;\n\
    \    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M++);\n    }\n\n    inline void add_undirected_edge(int from, int to, Cost cost\
    \ = 1) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline std::size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 7 \"graph/tree/lca.hpp\"\n\ntemplate <typename Cost = int> class LCA {\n\
    \  public:\n    LCA(): G(0), root(0), LOG(0) {}\n    explicit LCA(const Graph<Cost>\
    \ &G, int root = 0)\n        : G(G), root(root), LOG((int)log2(G.size()) + 1),\
    \ depth(G.size()),\n          parent(LOG, std::vector<int>(G.size())) {\n    \
    \    dfs(root, -1, 0);\n        for(int k = 0; k + 1 < LOG; k++) {\n         \
    \   for(int i = 0; i < (int)G.size(); i++) {\n                if(parent[k][i]\
    \ < 0) {\n                    parent[k + 1][i] = -1;\n                } else {\n\
    \                    parent[k + 1][i] = parent[k][parent[k][i]];\n           \
    \     }\n            }\n        }\n    }\n    int get_lca(int u, int v) {\n  \
    \      assert(0 <= u && u < (int)G.size());\n        assert(0 <= v && v < (int)G.size());\n\
    \        if(depth[u] > depth[v]) std::swap(u, v);\n        for(int k = 0; k <\
    \ LOG; k++) {\n            if((depth[v] - depth[u]) >> k & 1) v = parent[k][v];\n\
    \        }\n        if(u == v) return u;\n        for(int k = LOG - 1; k >= 0;\
    \ k--) {\n            if(parent[k][u] != parent[k][v]) {\n                u =\
    \ parent[k][u];\n                v = parent[k][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n    int get_dist(int u, int v) {\n     \
    \   return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);\n    }\n\n  private:\n\
    \    Graph<Cost> G;\n    const int root;\n    const int LOG;\n    std::vector<int>\
    \ depth;\n    std::vector<std::vector<int>> parent;\n\n    void dfs(int u, int\
    \ p, int d) {\n        depth[u] = d;\n        parent[0][u] = p;\n        for(int\
    \ v : G[u]) {\n            if(v == p) continue;\n            dfs(v, u, d + 1);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n\n#include <cmath>\n#include <vector>\n\n#include \"../graph_template.hpp\"\
    \n\ntemplate <typename Cost = int> class LCA {\n  public:\n    LCA(): G(0), root(0),\
    \ LOG(0) {}\n    explicit LCA(const Graph<Cost> &G, int root = 0)\n        : G(G),\
    \ root(root), LOG((int)log2(G.size()) + 1), depth(G.size()),\n          parent(LOG,\
    \ std::vector<int>(G.size())) {\n        dfs(root, -1, 0);\n        for(int k\
    \ = 0; k + 1 < LOG; k++) {\n            for(int i = 0; i < (int)G.size(); i++)\
    \ {\n                if(parent[k][i] < 0) {\n                    parent[k + 1][i]\
    \ = -1;\n                } else {\n                    parent[k + 1][i] = parent[k][parent[k][i]];\n\
    \                }\n            }\n        }\n    }\n    int get_lca(int u, int\
    \ v) {\n        assert(0 <= u && u < (int)G.size());\n        assert(0 <= v &&\
    \ v < (int)G.size());\n        if(depth[u] > depth[v]) std::swap(u, v);\n    \
    \    for(int k = 0; k < LOG; k++) {\n            if((depth[v] - depth[u]) >> k\
    \ & 1) v = parent[k][v];\n        }\n        if(u == v) return u;\n        for(int\
    \ k = LOG - 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v]) {\n\
    \                u = parent[k][u];\n                v = parent[k][v];\n      \
    \      }\n        }\n        return parent[0][u];\n    }\n    int get_dist(int\
    \ u, int v) {\n        return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);\n\
    \    }\n\n  private:\n    Graph<Cost> G;\n    const int root;\n    const int LOG;\n\
    \    std::vector<int> depth;\n    std::vector<std::vector<int>> parent;\n\n  \
    \  void dfs(int u, int p, int d) {\n        depth[u] = d;\n        parent[0][u]\
    \ = p;\n        for(int v : G[u]) {\n            if(v == p) continue;\n      \
    \      dfs(v, u, d + 1);\n        }\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/lca.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/tree/lowest-common-ancestor.test.cpp
  - test/mytest/graph/lca-and-empty-two-sat.test.cpp
  - test/mytest/graph/tree-api.test.cpp
documentation_of: graph/tree/lca.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148\uFF08\u30C0\u30D6\u30EA\u30F3\u30B0\uFF09"
---

## このライブラリでできること

根付き木の2頂点 u,v に対し、両方の祖先である頂点のうち最も深いものを最小共通祖先（LCA）と呼びます。`LCA<Cost>` は、各頂点の $2^k$ 個上の祖先を前計算するダブリング法でLCAを求めます。

頂点数を N とすると、前処理は $O(N\log(N+1))$、1回の問い合わせは $O(\log(N+1))$ です。

## 使い方

構築時に木と根を渡します。`get_lca(u,v)` が共通祖先、`get_dist(u,v)` が2頂点を結ぶパスの辺数を返します。根からの深さを d、LCAを w とすると、距離は $d(u)+d(v)-2d(w)$ です。

例は鎖 $0-1-2$ を0で根付けています。0と2のLCAは0で、距離は2です。

```cpp
#include <cassert>
#include "graph/tree/lca.hpp"

int main() {
    Graph<> g(3);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    LCA<> lca(g);
    assert(lca.get_lca(0, 2) == 0);
    assert(lca.get_dist(0, 2) == 2);
}
```

## API・計算量

親のダブリング表などの保持に $O(N\log(N+1))$、構築中の再帰スタックに最大 $O(N)$ 空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LCA()` | 問い合わせ対象のない空のオブジェクトを構築。 | O(1) |
| `LCA(const Graph<Cost>& G, int root=0)` | 根を決めて親・深さを構築。 | O(N log(N+1)) |
| `int get_lca(int u, int v)` | 最小共通祖先。 | O(log(N+1)) |
| `int get_dist(int u, int v)` | u,v 間の辺数。 | O(log(N+1)) |

## 利用条件と実装上の注意

Graph を渡す場合は非空・連結な無向木とし、根と問い合わせ頂点は $[0,N)$ に収めます。辺重みは使わず、距離は辺数です。デフォルト構築した空のオブジェクトには問い合わせできません。根と表の段数が const メンバなので、オブジェクトへの代入もできません。通常は木を渡して直接構築します。

深い頂点を持ち上げるときは非負の深さの差をシフトします。負の整数の右シフトの処理系依存性に頼りません。前処理の再帰は、細長い木では深くなる点に注意してください。
