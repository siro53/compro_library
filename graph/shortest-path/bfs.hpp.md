---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-11-C.test.cpp
    title: test/aoj/aoj-ALDS1-11-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/bfs-topological-sort.test.cpp
    title: test/mytest/graph/bfs-topological-sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/bfs.hpp\"\n\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#include <cassert>\n#include <cstddef>\n#include <vector>\n\ntemplate <typename\
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
    \   inline std::size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  protected:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 9 \"graph/shortest-path/bfs.hpp\"\
    \n\ntemplate <typename Cost = int>\nstd::pair<std::vector<Cost>, std::vector<int>>\n\
    bfs(const Graph<Cost> &G, int start, Cost iv = 0,\n    Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::queue<int> que;\n    que.emplace(start);\n    while(!que.empty()) {\n\
    \        int u = que.front();\n        que.pop();\n        for(const auto &e :\
    \ G[u]) {\n            if(dist[e.to] > dist[u] + 1) {\n                dist[e.to]\
    \ = dist[u] + 1;\n                prev[e.to] = u;\n                que.emplace(e.to);\n\
    \            }\n        }\n    }\n\n    return std::make_pair(dist, prev);\n}\n"
  code: "#pragma once\n\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n\n#include \"../graph_template.hpp\"\n\ntemplate <typename\
    \ Cost = int>\nstd::pair<std::vector<Cost>, std::vector<int>>\nbfs(const Graph<Cost>\
    \ &G, int start, Cost iv = 0,\n    Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::queue<int> que;\n    que.emplace(start);\n    while(!que.empty()) {\n\
    \        int u = que.front();\n        que.pop();\n        for(const auto &e :\
    \ G[u]) {\n            if(dist[e.to] > dist[u] + 1) {\n                dist[e.to]\
    \ = dist[u] + 1;\n                prev[e.to] = u;\n                que.emplace(e.to);\n\
    \            }\n        }\n    }\n\n    return std::make_pair(dist, prev);\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/shortest-path/bfs.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/graph/bfs-topological-sort.test.cpp
  - test/aoj/aoj-ALDS1-11-C.test.cpp
documentation_of: graph/shortest-path/bfs.hpp
layout: document
title: "\u5E45\u512A\u5148\u63A2\u7D22"
---

## このライブラリでできること

`bfs` は、始点から各頂点までに必要な辺数の最小値を求めます。すべての移動を同じ1ステップとして数える問題、たとえばマス目上の最小移動回数に適しています。辺に `cost` が設定されていても、この関数では無視します。

始点に近い頂点からキューで順に処理するので、頂点数 $N$、辺数 $M$ に対して $O(N+M)$ 時間です。距離だけでなく、最短路上の直前の頂点も記録します。

## 使い方

`auto [dist,prev]=bfs(g,start)` のように受け取ります。例では $0\to1$ の辺があるため、$1$ の距離は $1$、直前の頂点は $0$ です。辺のない $2$ には到達できません。

経路を復元するには、到達可能な終点から `prev` を $-1$ になるまでたどり、得られた頂点列を反転します。始点の距離を $0$ 以外にしたい場合は `iv` を指定できます。この場合、返る距離は辺数に `iv` を加えた値です。

```cpp
#include "template/template.cpp"
#include "graph/shortest-path/bfs.hpp"

int main() {
    Graph<int> g(3);
    g.add_directed_edge(0, 1, 1);
    auto [dist, prev] = bfs(g, 0);
    assert(dist[1] == 1);
    assert(prev[1] == 0 && prev[2] == -1);
}
```

## API・計算量

入力とは別に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `bfs(G, start, iv=0, inf=numeric_limits<Cost>::max())` | (距離配列 dist, 直前の頂点配列 prev) を返す。 | O(N+M) |

## 利用条件と実装上の注意

始点はグラフ内の有効な頂点にしてください。到達できない頂点の距離は `inf`、直前の頂点は $-1$ です。始点自身の `prev` も $-1$ なので、到達可能性は距離で区別してください。

有限の距離はすべて `inf` 未満とし、距離に1を加える計算が型の範囲に収まるようにします。辺ごとに異なる非負コストを考えたい場合は `dijkstra` を使ってください。
