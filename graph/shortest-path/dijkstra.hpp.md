---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/shortest-path.test.cpp
    title: test/library-checker/graph/shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/dijkstra.hpp\"\n\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <typename Cost = int> struct\
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
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 9 \"graph/shortest-path/dijkstra.hpp\"\n\ntemplate <typename Cost = int>\n\
    std::pair<std::vector<Cost>, std::vector<int>>\ndijkstra(const Graph<Cost> &G,\
    \ int start, Cost iv = 0,\n         Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> que;\n \
    \   que.emplace(iv, start);\n    while(!que.empty()) {\n        auto [d, u] =\
    \ que.top();\n        que.pop();\n        if(d > dist[u]) continue;\n        for(const\
    \ auto &e : G[u]) {\n            if(dist[e.to] > d + e.cost) {\n             \
    \   dist[e.to] = d + e.cost;\n                prev[e.to] = u;\n              \
    \  que.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n    return\
    \ std::make_pair(dist, prev);\n}\n"
  code: "#pragma once\n\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n\n#include \"../graph_template.hpp\"\n\ntemplate <typename\
    \ Cost = int>\nstd::pair<std::vector<Cost>, std::vector<int>>\ndijkstra(const\
    \ Graph<Cost> &G, int start, Cost iv = 0,\n         Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> que;\n \
    \   que.emplace(iv, start);\n    while(!que.empty()) {\n        auto [d, u] =\
    \ que.top();\n        que.pop();\n        if(d > dist[u]) continue;\n        for(const\
    \ auto &e : G[u]) {\n            if(dist[e.to] > d + e.cost) {\n             \
    \   dist[e.to] = d + e.cost;\n                prev[e.to] = u;\n              \
    \  que.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n    return\
    \ std::make_pair(dist, prev);\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/shortest-path/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/graph/shortest-path.test.cpp
documentation_of: graph/shortest-path/dijkstra.hpp
layout: document
title: "Dijkstra \u6CD5"
---

## このライブラリでできること

`dijkstra` は、非負の辺重みを持つグラフで、始点から各頂点への最小コストを求めます。距離の小さい候補を優先度付きキューから取り出し、隣接頂点への距離を改善していきます。有向グラフ・無向グラフの両方に使えます。

頂点数を $N$、隣接リストに格納された辺数を $M$ とします。この実装は改善のたびにキューへ候補を追加するため、多重辺も含めた上界は $O(N+(N+M)\log(M+2))$ です。単純グラフなら通常の $O((N+M)\log N)$ と表せます。

## 使い方

`auto [dist,prev]=dijkstra(g,start)` で距離と直前の頂点を受け取ります。例では辺 $0\to1$ の重みが $5$ なので、`dist[1]` は $5$ です。辺数を数える BFS とはここが異なります。

到達可能な頂点への経路は、終点から `prev` をたどって反転すると復元できます。`iv` を指定した場合は、通常の最短距離にその初期値を加えた値を返します。

```cpp
#include "template/template.cpp"
#include "graph/shortest-path/dijkstra.hpp"

int main() {
    Graph<int> g(3);
    g.add_directed_edge(0, 1, 5);
    auto [dist, prev] = dijkstra(g, 0);
    assert(dist[1] == 5);
    assert(prev[1] == 0 && prev[2] == -1);
}
```

## API・計算量

入力とは別に $O(N+M)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `dijkstra(G, start, iv=0, inf=numeric_limits<Cost>::max())` | (距離配列 dist, 直前の頂点配列 prev) を返す。 | O(N+(N+M) log(M+2)) |

## 利用条件と実装上の注意

すべての辺重みが非負であることが前提です。負の辺があるグラフには、この計算量や正しさを適用できません。

到達できない頂点の距離は `inf`、`prev` は $-1$ です。始点の `prev` も $-1$ になります。有限距離は `inf` より小さくし、緩和時の `d+cost` がオーバーフローしない型と値域を選んでください。
