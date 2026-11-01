---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/namori.hpp
    title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/range-edge-graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/bfs.hpp
    title: "\u5E45\u512A\u5148\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  - icon: ':heavy_check_mark:'
    path: graph/topological-sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/tree/centroid-decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/tree/diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':heavy_check_mark:'
    path: graph/tree/hld.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148\uFF08\u30C0\u30D6\u30EA\u30F3\u30B0\
      \uFF09"
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: "\u6728\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-11-C.test.cpp
    title: test/aoj/aoj-ALDS1-11-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-GRL-4-A.test.cpp
    title: test/aoj/aoj-GRL-4-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/scc.test.cpp
    title: test/library-checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/shortest-path.test.cpp
    title: test/library-checker/graph/shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/two-sat.test.cpp
    title: test/library-checker/math/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor2.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/tree-diameter.test.cpp
    title: test/library-checker/tree/tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/bfs-topological-sort.test.cpp
    title: test/mytest/graph/bfs-topological-sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/graph-scc-two-sat.test.cpp
    title: test/mytest/graph/graph-scc-two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/lca-and-empty-two-sat.test.cpp
    title: test/mytest/graph/lca-and-empty-two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/range-edge-graph.test.cpp
    title: test/mytest/graph/range-edge-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/tree-api.test.cpp
    title: test/mytest/graph/tree-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n\n#include <cassert>\n#include\
    \ <cstddef>\n#include <vector>\n\ntemplate <typename Cost = int> struct Edge {\n\
    \    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n    explicit\
    \ Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from), to(to),\
    \ cost(cost), id(id) {}\n    operator int() const { return to; }\n};\n\ntemplate\
    \ <typename Cost = int> class Graph {\n  public:\n    Graph() = default;\n   \
    \ explicit Graph(int N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M++);\n    }\n\n    inline void add_undirected_edge(int from, int to, Cost cost\
    \ = 1) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline std::size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstddef>\n#include <vector>\n\
    \ntemplate <typename Cost = int> struct Edge {\n    int from, to;\n    Cost cost;\n\
    \    int id;\n    Edge() = default;\n    explicit Edge(int from, int to, Cost\
    \ cost = 1, int id = -1)\n        : from(from), to(to), cost(cost), id(id) {}\n\
    \    operator int() const { return to; }\n};\n\ntemplate <typename Cost = int>\
    \ class Graph {\n  public:\n    Graph() = default;\n    explicit Graph(int N)\
    \ : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int from, int to,\
    \ Cost cost = 1) {\n        assert(0 <= from && from < N);\n        assert(0 <=\
    \ to && to < N);\n        G[from].emplace_back(from, to, cost, M++);\n    }\n\n\
    \    inline void add_undirected_edge(int from, int to, Cost cost = 1) {\n    \
    \    assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n    \
    \    G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline std::size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - graph/topological-sort.hpp
  - graph/tree/hld.hpp
  - graph/tree/lca.hpp
  - graph/tree/diameter.hpp
  - graph/tree/tree-hash.hpp
  - graph/tree/centroid-decomposition.hpp
  - graph/scc.hpp
  - graph/shortest-path/dijkstra.hpp
  - graph/shortest-path/bfs.hpp
  - graph/range-edge-graph.hpp
  - graph/namori.hpp
  - math/two_sat.hpp
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/graph/scc.test.cpp
  - test/library-checker/graph/shortest-path.test.cpp
  - test/library-checker/math/two-sat.test.cpp
  - test/library-checker/tree/tree-diameter.test.cpp
  - test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - test/library-checker/tree/lowest-common-ancestor.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/mytest/graph/lca-and-empty-two-sat.test.cpp
  - test/mytest/graph/range-edge-graph.test.cpp
  - test/mytest/graph/graph-scc-two-sat.test.cpp
  - test/mytest/graph/bfs-topological-sort.test.cpp
  - test/mytest/graph/tree-api.test.cpp
  - test/aoj/aoj-ALDS1-11-C.test.cpp
  - test/aoj/aoj2821.test.cpp
  - test/aoj/aoj-GRL-4-A.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
---

## このライブラリでできること

`Graph<Cost>` は、各頂点から出る辺を隣接リストで保持するグラフです。頂点数を $N$、辺の追加回数を $M$ とすると、必要な空間は $O(N+M)$ です。有向辺と無向辺の両方を追加でき、辺の重みの型を `Cost` で指定します。

1本の辺を表す `Edge<Cost>` は、始点 `from`、終点 `to`、重み `cost`、辺番号 `id` を持ちます。無向辺は同じ辺番号を持つ2本の有向辺として保存するため、どちら側から見ても元の辺を識別できます。

## 使い方

頂点数を指定して構築し、`add_directed_edge` または `add_undirected_edge` で辺を追加します。例では $0$ と $1$ の間に重み $5$ の無向辺、$1$ から $2$ へ重み $7$ の有向辺を追加しています。

頂点 `u` の隣接辺は `g[u]` で取得します。`for (const auto& e : g[u])` とすれば重みや辺番号も参照でき、`for (int v : g[u])` とすれば `Edge` の整数変換によって行き先だけを取り出せます。

```cpp
#include "template/template.cpp"
#include "graph/graph_template.hpp"

int main() {
    Graph<long long> g(3);
    g.add_undirected_edge(0, 1, 5);
    g.add_directed_edge(1, 2, 7);
    assert(g[0][0].to == 1 && g[0][0].cost == 5);
}
```

## API・計算量

グラフと作業領域を合わせて $O(N+M)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Graph(N)` | N 頂点・辺なしで初期化。 | O(N) |
| `Edge(from, to, cost=1, id=-1)` | 辺を作る。デフォルト構築の整数メンバは未初期化。 | O(1) |
| `Edge::operator int()` | 行き先 to に変換。 | O(1) |
| `add_directed_edge(from, to, cost=1)` | 有向辺を 1 本追加。 | 償却 O(1) |
| `add_undirected_edge(from, to, cost=1)` | 同じ id の辺を両方向に追加。 | 償却 O(1) |
| `size()` | 頂点数。 | O(1) |
| `operator[](i)` | i の出辺リストへの参照（const 版もある）。 | O(1) |

## 利用条件と実装上の注意

頂点番号は $[0,N)$ です。辺番号は追加順に0から付き、無向辺も1回の追加で番号を1つだけ消費します。`Edges<Cost>` は `vector<Edge<Cost>>` の別名であり、グラフ全体とは別の辺のリストです。

`Graph()` のデフォルト構築では頂点数などが初期化されません。サイズ付きのグラフを代入してから利用してください。`Edge()` の数値メンバも未初期化なので、辺を直接作る場合は端点などを明示します。
