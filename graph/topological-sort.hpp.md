---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-GRL-4-A.test.cpp
    title: test/aoj/aoj-GRL-4-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/bfs-topological-sort.test.cpp
    title: test/mytest/graph/bfs-topological-sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological-sort.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 4 \"graph/topological-sort.hpp\"\
    \n\ntemplate<typename Cost = int>\nstd::vector<int> topological_sort(const Graph<Cost>&\
    \ G) {\n    int N = (int)G.size();\n    std::vector<int> indeg(N, 0);\n    for(int\
    \ i = 0; i < N; i++) {\n        for(const auto& e : G[i]) {\n            indeg[e.to]++;\n\
    \        }\n    }\n    std::vector<int> st, ret;\n    for(int i = 0; i < N; i++)\
    \ {\n        if(indeg[i] == 0) st.push_back(i);\n    }\n    while(!st.empty())\
    \ {\n        int u = st.back();\n        st.pop_back();\n        ret.push_back(u);\n\
    \        for(const auto& e : G[u]) {\n            indeg[e.to]--;\n           \
    \ if(indeg[e.to] == 0) st.push_back(e.to);\n        }\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include \"graph_template.hpp\"\n\ntemplate<typename Cost\
    \ = int>\nstd::vector<int> topological_sort(const Graph<Cost>& G) {\n    int N\
    \ = (int)G.size();\n    std::vector<int> indeg(N, 0);\n    for(int i = 0; i <\
    \ N; i++) {\n        for(const auto& e : G[i]) {\n            indeg[e.to]++;\n\
    \        }\n    }\n    std::vector<int> st, ret;\n    for(int i = 0; i < N; i++)\
    \ {\n        if(indeg[i] == 0) st.push_back(i);\n    }\n    while(!st.empty())\
    \ {\n        int u = st.back();\n        st.pop_back();\n        ret.push_back(u);\n\
    \        for(const auto& e : G[u]) {\n            indeg[e.to]--;\n           \
    \ if(indeg[e.to] == 0) st.push_back(e.to);\n        }\n    }\n    return ret;\n\
    }"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-GRL-4-A.test.cpp
  - test/mytest/graph/bfs-topological-sort.test.cpp
documentation_of: graph/topological-sort.hpp
layout: document
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---

## このライブラリでできること

`topological_sort(G)` は、有向辺 $u\to v$ に対して $u$ が $v$ より前に来るように頂点を並べます。依存関係のある作業を実行する順序や、DAG上の動的計画法の処理順を決めるために使えます。

入次数が0の頂点を取り出し、その頂点から出る辺を除く処理を繰り返します。頂点数 $N$、辺数 $M$ に対して $O(N+M)$ 時間です。

## 使い方

返り値は頂点番号の配列です。例の辺は $0\to1\to2$ なので、順序は $[0,1,2]$ になります。処理後は、返り値の長さが元の頂点数と等しいかも確認してください。等しければ全頂点を並べられています。

```cpp
#include "template/template.cpp"
#include "graph/topological-sort.hpp"

int main() {
    Graph<> g(3);
    g.add_directed_edge(0, 1);
    g.add_directed_edge(1, 2);
    auto order = topological_sort(g);
    assert((order == vector<int>{0, 1, 2}));
}
```

## API・計算量

入力とは別に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `topological_sort(G)` | 辺の向きに沿った頂点順序の vector<int>。 | O(N+M) |

## 利用条件と実装上の注意

閉路がある場合、トポロジカル順序は存在しません。この関数は例外ではなく、取り出せた頂点だけの配列を返すため、長さが $N$ 未満なら閉路ありと判断します。

複数の正しい順序があるとき、辞書順最小になる保証はありません。辺の重みは並べ替えに使いません。
