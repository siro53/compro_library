---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/centroid-decomposition.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    #line 4 \"graph/tree/centroid-decomposition.hpp\"\n\n// TODO: \u826F\u3044\u30A4\
    \u30F3\u30BF\u30FC\u30D5\u30A7\u30A4\u30B9\u3092\u6A21\u7D22\u3059\u308B\nstruct\
    \ CentroidDecomposition {\n    const Graph<int>& G;\n    std::vector<int> subtree_size,\
    \ parent;\n    std::vector<bool> removed;\n\n    explicit CentroidDecomposition(const\
    \ Graph<int>& g): G(g), subtree_size(g.size(), 0), parent(g.size(), -1), removed(g.size(),\
    \ false) {}\n\n    void get_subtree_size(int u, int p) {\n        subtree_size[u]\
    \ = 1;\n        for(int v : G[u]) {\n            if(v == p or removed[v]) continue;\n\
    \            get_subtree_size(v, u);\n            subtree_size[u] += subtree_size[v];\n\
    \        }\n    }\n\n    void decomp(int u, int p) {\n        get_subtree_size(u,\
    \ -1);\n        int sz = subtree_size[u];\n        int pre = -1;\n        while(1)\
    \ {\n            int mx = -1, mx_v = -1;\n            for(int v : G[u]) {\n  \
    \              if(v == pre or removed[v]) continue;\n                if(mx < subtree_size[v])\
    \ {\n                    mx = subtree_size[v];\n                    mx_v = v;\n\
    \                }\n            }\n            if(mx * 2 <= sz) break;\n     \
    \       pre = u;\n            u = mx_v;\n        }\n        removed[u] = true;\n\
    \        parent[u] = p;\n        for(int v : G[u]) {\n            if(removed[v])\
    \ continue;\n            decomp(v, u);\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../graph_template.hpp\"\n\n// TODO: \u826F\u3044\
    \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30A4\u30B9\u3092\u6A21\u7D22\u3059\u308B\
    \nstruct CentroidDecomposition {\n    const Graph<int>& G;\n    std::vector<int>\
    \ subtree_size, parent;\n    std::vector<bool> removed;\n\n    explicit CentroidDecomposition(const\
    \ Graph<int>& g): G(g), subtree_size(g.size(), 0), parent(g.size(), -1), removed(g.size(),\
    \ false) {}\n\n    void get_subtree_size(int u, int p) {\n        subtree_size[u]\
    \ = 1;\n        for(int v : G[u]) {\n            if(v == p or removed[v]) continue;\n\
    \            get_subtree_size(v, u);\n            subtree_size[u] += subtree_size[v];\n\
    \        }\n    }\n\n    void decomp(int u, int p) {\n        get_subtree_size(u,\
    \ -1);\n        int sz = subtree_size[u];\n        int pre = -1;\n        while(1)\
    \ {\n            int mx = -1, mx_v = -1;\n            for(int v : G[u]) {\n  \
    \              if(v == pre or removed[v]) continue;\n                if(mx < subtree_size[v])\
    \ {\n                    mx = subtree_size[v];\n                    mx_v = v;\n\
    \                }\n            }\n            if(mx * 2 <= sz) break;\n     \
    \       pre = u;\n            u = mx_v;\n        }\n        removed[u] = true;\n\
    \        parent[u] = p;\n        for(int v : G[u]) {\n            if(removed[v])\
    \ continue;\n            decomp(v, u);\n        }\n    }\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/centroid-decomposition.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:06:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid-decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3"
---

## このライブラリでできること

`CentroidDecomposition` は、木を重心で切り分けて再帰的に分解します。重心とは、その頂点を取り除いてできる各連結成分の大きさが、元の木の半分以下になる頂点です。重心を介してパスを数える問題や、木上の距離クエリを整理する際の土台になります。

各段で残る木のサイズが半分以下になるため、分解でできる木の高さは $O(\log N)$ です。ただし各段では部分木サイズを計算する必要があり、頂点数 $N$ の木全体の分解時間は $O(N\log N)$ になります。

## 使い方

`Graph<int>` を渡して構築しただけでは分解は実行されません。`decomp(0,-1)` を呼ぶと、`parent[v]` に重心木での親が入り、重心木の根だけは $-1$ になります。

例の3頂点の鎖では中央の $1$ が重心です。そのため `parent[1]` は $-1$ になります。`get_subtree_size` は分解途中のサイズ計算用で、通常は `decomp` から呼ばれます。

```cpp
#include "template/template.cpp"
#include "graph/tree/centroid-decomposition.hpp"

int main() {
    Graph<> g(3);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    CentroidDecomposition cd(g);
    cd.decomp(0, -1);
    assert(cd.parent[1] == -1);
}
```

## API・計算量

必要な空間は $O(N)$ です。重心木の高さは $O(\log N)$ ですが、部分木サイズを求める探索の再帰深さは最悪 $O(N)$ になります。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `CentroidDecomposition(g)` | Graph<int> への参照と作業配列を用意。 | O(N) |
| `get_subtree_size(u, p)` | removed を除く u の連結部分の部分木サイズを計算。 | O(K)、K は訪問頂点数 |
| `decomp(u, p)` | u を含む残りの木を分解。最初は decomp(0,-1)。 | O(N log N)（木全体） |

## 利用条件と実装上の注意

非空・連結な無向木を渡してください。元のグラフ `G` はコピーではなく参照として保持されるため、分解器より長く生存している必要があります。

`removed` はすでに重心として処理した頂点を示す作業用配列で、分解終了時には全要素が真になります。`subtree_size` も最後の処理時点の作業結果であり、元の根付き木の部分木サイズ表ではありません。同じ状態のまま分解を最初から繰り返すことはできません。サイズ計算の再帰深さは、重心木の高さとは異なり最悪 $O(N)$ です。
