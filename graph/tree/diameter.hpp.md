---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: "\u6728\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/tree-diameter.test.cpp
    title: test/library-checker/tree/tree-diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/diameter.hpp\"\n\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"graph/graph_template.hpp\"\n\n#include\
    \ <cassert>\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost =\
    \ int> struct Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge()\
    \ = default;\n    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n\
    \        : from(from), to(to), cost(cost), id(id) {}\n    operator int() const\
    \ { return to; }\n};\n\ntemplate <typename Cost = int> class Graph {\n  public:\n\
    \    Graph() = default;\n    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n \
    \   inline void add_directed_edge(int from, int to, Cost cost = 1) {\n       \
    \ assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n       \
    \ G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void add_undirected_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n    inline size_t\
    \ size() const { return G.size(); }\n    inline std::vector<Edge<Cost>> &operator[](const\
    \ int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>> &operator[](const\
    \ int &i) const {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n\
    \    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class Cost = int>\
    \ using Edges = std::vector<Edge<Cost>>;\n#line 8 \"graph/tree/diameter.hpp\"\n\
    \ntemplate <typename Cost = int>\nstd::pair<Cost, std::vector<int>> get_diameter(const\
    \ Graph<Cost> &G) {\n    std::vector<Cost> depth(G.size());\n    std::vector<int>\
    \ par(G.size(), -1);\n    auto dfs = [&](auto &&self, int u, int p, Cost d) ->\
    \ void {\n        depth[u] = d;\n        par[u] = p;\n        for(const auto &e\
    \ : G[u]) {\n            if(e.to == p) continue;\n            self(self, e.to,\
    \ u, d + e.cost);\n        }\n    };\n    dfs(dfs, 0, -1, 0);\n    int from =\
    \ std::max_element(depth.begin(), depth.end()) - depth.begin();\n    dfs(dfs,\
    \ from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    std::vector<int> path = {to};\n    while(1) {\n        int nxt = par[path.back()];\n\
    \        if(nxt == -1) break;\n        path.push_back(nxt);\n    }\n    return\
    \ std::make_pair(depth[to], path);\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n#include \"../graph_template.hpp\"\n\ntemplate <typename Cost = int>\nstd::pair<Cost,\
    \ std::vector<int>> get_diameter(const Graph<Cost> &G) {\n    std::vector<Cost>\
    \ depth(G.size());\n    std::vector<int> par(G.size(), -1);\n    auto dfs = [&](auto\
    \ &&self, int u, int p, Cost d) -> void {\n        depth[u] = d;\n        par[u]\
    \ = p;\n        for(const auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            self(self, e.to, u, d + e.cost);\n        }\n    };\n    dfs(dfs,\
    \ 0, -1, 0);\n    int from = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    dfs(dfs, from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<int> path = {to};\n    while(1) {\n      \
    \  int nxt = par[path.back()];\n        if(nxt == -1) break;\n        path.push_back(nxt);\n\
    \    }\n    return std::make_pair(depth[to], path);\n}"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/diameter.hpp
  requiredBy:
  - graph/tree/tree-hash.hpp
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/tree/tree-diameter.test.cpp
  - test/aoj/aoj2821.test.cpp
documentation_of: graph/tree/diameter.hpp
layout: document
title: "\u6728\u306E\u76F4\u5F84"
---

## このライブラリでできること

`get_diameter(G)` は、木の中で最も長い単純パスの長さと、そのパス上の頂点列を返します。ここで長さは辺重みの和です。辺重みがすべて1なら、最も多くの辺を通るパスになります。

非負重みの木では、任意の頂点から最遠の頂点を探し、そこからもう一度最遠の頂点を探すと直径の両端が得られます。この実装も2回の探索を行うので、頂点数 $N$ に対して $O(N)$ 時間です。

## 使い方

非空の無向木を作り、`auto [length,path]=get_diameter(g)` として受け取ります。例は重み $2,3$ の辺が一直線につながっているため、直径の長さは $5$、パスには3頂点が含まれます。

返される `path` は端点から反対側の端点までの順序ですが、どちらの端点が先になるかに意味を持たせないでください。

```cpp
#include "template/template.cpp"
#include "graph/tree/diameter.hpp"

int main() {
    Graph<long long> g(3);
    g.add_undirected_edge(0, 1, 2);
    g.add_undirected_edge(1, 2, 3);
    auto [length, path] = get_diameter(g);
    assert(length == 5 && path.size() == 3);
}
```

## API・計算量

入力とは別の作業配列と再帰スタックに $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `get_diameter(G)` | (直径の重みの和, 端点から端点への頂点列)。 | O(N) |

## 利用条件と実装上の注意

入力は連結な無向木で、重みは非負としてください。閉路のあるグラフや負辺を含む木には、この2回の探索の性質をそのまま使えません。

同じ長さの直径が複数あるときは、そのうち1つを返します。空のグラフには対応していません。再帰による探索なので、細長い木ではスタックの深さが $O(N)$ になります。
