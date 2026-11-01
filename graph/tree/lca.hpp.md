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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/lca.hpp\"\n\n#include <cmath>\n#include <vector>\n\
    \n#line 2 \"graph/graph_template.hpp\"\n\n#include <cassert>\n#line 5 \"graph/graph_template.hpp\"\
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
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 7 \"graph/tree/lca.hpp\"\n\ntemplate <typename Cost = int> class LCA {\n\
    \  public:\n    LCA() = default;\n    explicit LCA(const Graph<Cost> &G, int root\
    \ = 0)\n        : G(G), root(root), LOG((int)log2(G.size()) + 1), depth(G.size()),\n\
    \          parent(LOG, std::vector<int>(G.size())) {\n        dfs(root, -1, 0);\n\
    \        for(int k = 0; k + 1 < LOG; k++) {\n            for(int i = 0; i < (int)G.size();\
    \ i++) {\n                if(parent[k][i] < 0) {\n                    parent[k\
    \ + 1][i] = -1;\n                } else {\n                    parent[k + 1][i]\
    \ = parent[k][parent[k][i]];\n                }\n            }\n        }\n  \
    \  }\n    int get_lca(int u, int v) {\n        if(depth[u] > depth[v]) std::swap(u,\
    \ v);\n        for(int k = 0; k < LOG; k++) {\n            if((depth[u] - depth[v])\
    \ >> k & 1) v = parent[k][v];\n        }\n        if(u == v) return u;\n     \
    \   for(int k = LOG - 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v])\
    \ {\n                u = parent[k][u];\n                v = parent[k][v];\n  \
    \          }\n        }\n        return parent[0][u];\n    }\n    int get_dist(int\
    \ u, int v) {\n        return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);\n\
    \    }\n\n  private:\n    Graph<Cost> G;\n    const int root;\n    const int LOG;\n\
    \    std::vector<int> depth;\n    std::vector<std::vector<int>> parent;\n\n  \
    \  void dfs(int u, int p, int d) {\n        depth[u] = d;\n        parent[0][u]\
    \ = p;\n        for(int v : G[u]) {\n            if(v == p) continue;\n      \
    \      dfs(v, u, d + 1);\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <cmath>\n#include <vector>\n\n#include \"../graph_template.hpp\"\
    \n\ntemplate <typename Cost = int> class LCA {\n  public:\n    LCA() = default;\n\
    \    explicit LCA(const Graph<Cost> &G, int root = 0)\n        : G(G), root(root),\
    \ LOG((int)log2(G.size()) + 1), depth(G.size()),\n          parent(LOG, std::vector<int>(G.size()))\
    \ {\n        dfs(root, -1, 0);\n        for(int k = 0; k + 1 < LOG; k++) {\n \
    \           for(int i = 0; i < (int)G.size(); i++) {\n                if(parent[k][i]\
    \ < 0) {\n                    parent[k + 1][i] = -1;\n                } else {\n\
    \                    parent[k + 1][i] = parent[k][parent[k][i]];\n           \
    \     }\n            }\n        }\n    }\n    int get_lca(int u, int v) {\n  \
    \      if(depth[u] > depth[v]) std::swap(u, v);\n        for(int k = 0; k < LOG;\
    \ k++) {\n            if((depth[u] - depth[v]) >> k & 1) v = parent[k][v];\n \
    \       }\n        if(u == v) return u;\n        for(int k = LOG - 1; k >= 0;\
    \ k--) {\n            if(parent[k][u] != parent[k][v]) {\n                u =\
    \ parent[k][u];\n                v = parent[k][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n    int get_dist(int u, int v) {\n     \
    \   return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);\n    }\n\n  private:\n\
    \    Graph<Cost> G;\n    const int root;\n    const int LOG;\n    std::vector<int>\
    \ depth;\n    std::vector<std::vector<int>> parent;\n\n    void dfs(int u, int\
    \ p, int d) {\n        depth[u] = d;\n        parent[0][u] = p;\n        for(int\
    \ v : G[u]) {\n            if(v == p) continue;\n            dfs(v, u, d + 1);\n\
    \        }\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/lca.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/tree/lowest-common-ancestor.test.cpp
documentation_of: graph/tree/lca.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148\uFF08\u30C0\u30D6\u30EA\u30F3\u30B0\uFF09"
---

## このライブラリでできること

根付き木の2頂点 $u,v$ に対し、両方の祖先である頂点のうち最も深いものを最小共通祖先（LCA）と呼びます。`LCA<Cost>` は、各頂点の $2^k$ 個上の祖先を前計算するダブリング法で、これを求めることを意図したクラスです。

頂点数を $N$ とすると、ダブリング法の前処理は $O(N\log N)$、1回の問い合わせは $O(\log N)$ です。ただし、現実装には2頂点の深さをそろえる処理に不備があるため、修正前の利用は避けてください。

## 使い方

構築時に木と根を渡します。`get_lca(u,v)` が共通祖先、`get_dist(u,v)` が2頂点を結ぶパスの辺数を返す設計です。

辺数距離は、根からの深さを $d$、LCAを $w$ とすると $d(u)+d(v)-2d(w)$ で求められます。例の鎖 $0-1-2$ を $0$ で根付けた場合、$0,2$ の LCA は $0$ になるはずですが、現在のコードでこの結果は保証されません。

以下のコードは呼び出し形を示すものです。現実装の不備があるため、動作確認済みの使用例ではありません。

```cpp
#include "template/template.cpp"
#include "graph/tree/lca.hpp"

int main() {
    Graph<> g(3);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    LCA<> lca(g);
    auto ancestor = lca.get_lca(0, 2);
}
```

## API・計算量

親のダブリング表などの保持に $O(N\log N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LCA(G, root=0)` | 根を決めて親・深さを構築。 | O(N log N) |
| `get_lca(u, v)` | 最小共通祖先を意図するが、現状は深さ合わせに不備。 | 意図上 O(log N) |
| `get_dist(u, v)` | u,v 間の辺数。get_lca に依存。 | 意図上 O(log N) |

## 利用条件と実装上の注意

入力は非空・連結な無向木を想定しています。辺重みは使わず、距離は辺数として数えます。

現実装は深い側を持ち上げるための差として、負になる `depth[u]-depth[v]` を使っています。このため深さの異なる頂点への問い合わせで誤答や配列外参照が起こり得ます。修正するまでは、`HeavyLightDecomposition` の `lca/dist` を利用してください。引数なしのコンストラクタも const メンバが初期化されないため利用できません。
