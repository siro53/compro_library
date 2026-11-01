---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: test/library-checker/tree/lowest-common-ancestor2.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/tree-api.test.cpp
    title: test/mytest/graph/tree-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/hld.hpp\"\n\n#include <utility>\n\n#line 2 \"\
    graph/graph_template.hpp\"\n\n#include <cassert>\n#include <cstddef>\n#include\
    \ <vector>\n\ntemplate <typename Cost = int> struct Edge {\n    int from, to;\n\
    \    Cost cost;\n    int id;\n    Edge() = default;\n    explicit Edge(int from,\
    \ int to, Cost cost = 1, int id = -1)\n        : from(from), to(to), cost(cost),\
    \ id(id) {}\n    operator int() const { return to; }\n};\n\ntemplate <typename\
    \ Cost = int> class Graph {\n  public:\n    Graph() = default;\n    explicit Graph(int\
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
    #line 6 \"graph/tree/hld.hpp\"\n\ntemplate <typename Cost = int> class HeavyLightDecomposition\
    \ {\n  public:\n    explicit HeavyLightDecomposition(int N)\n        : G(N), in(N),\
    \ out(N), sz(N), head(N), par(N), dep(N), rev(N),\n          isBuilt(false) {}\n\
    \    explicit HeavyLightDecomposition(const Graph<Cost> &g)\n        : G(g), in(g.size()),\
    \ out(g.size()), sz(g.size()), head(g.size()),\n          par(g.size()), dep(g.size()),\
    \ rev(g.size()), isBuilt(false) {\n        build();\n    }\n    void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    void build(int root = 0) {\n        dfs1(root, -1, 0);\n        head[root]\
    \ = root;\n        int idx = 0;\n        dfs2(root, -1, idx);\n        isBuilt\
    \ = true;\n    }\n\tint lca(int u, int v) const {\n\t\tassert(isBuilt);\n\t\t\
    assert(0 <= u && u < (int)G.size());\n\t\tassert(0 <= v && v < (int)G.size());\n\
    \t\twhile(1) {\n\t\t\tif(in[u] > in[v]) std::swap(u, v);\n\t\t\tif(head[u] ==\
    \ head[v]) return u;\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\tint dist(int u, int\
    \ v) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\treturn (dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)]);\n\t}\n\tint la(int u, int k) const {\n\t\tassert(isBuilt);\n\t\tassert(0\
    \ <= u && u < (int)G.size());\n\t\tif(dep[u] < k) return -1;\n\t\twhile(1) {\n\
    \t\t\tif(in[u] - k >= in[head[u]]) {\n\t\t\t\treturn rev[in[u] - k];\n\t\t\t}\n\
    \t\t\tk -= (in[u] - in[head[u]] + 1);\n\t\t\tu = par[head[u]];\n\t\t}\n\t}\n\t\
    template<class F>\n\tvoid path_query(int u, int v, const F& f, bool edge = false)\
    \ const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\t\t\
    assert(0 <= v && v < (int)G.size());\n\t\twhile(1) {\n\t\t\tif(in[u] > in[v])\
    \ std::swap(u, v);\n\t\t\tif(head[u] == head[v]) {\n\t\t\t\tf(in[u] + (int)(edge),\
    \ in[v] + 1);\n\t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tf(in[head[v]], in[v] +\
    \ 1);\n\t\t\t}\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate<class F, class\
    \ F_rev>\n\tvoid path_query(int u, int v, const F& f, const F_rev& f_rev, bool\
    \ edge = false) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\tint L = lca(u, v);\n\t\tpath_query<F>(u,\
    \ L, f, edge);\n\t\tpath_query<F_rev>(L, v, f_rev, true);\n\t}\n\ttemplate<class\
    \ F>\n\tvoid subtree_query(int u, const F& f) const {\n\t\tassert(isBuilt);\n\t\
    \tassert(0 <= u && u < (int)G.size());\n\t\tf(in[u], out[u]);\n\t}\n\tint operator[](int\
    \ u) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\treturn in[u];\n\t}\n\n  private:\n    Graph<Cost> G;\n    std::vector<int>\
    \ in, out, sz, head, par, dep, rev;\n    bool isBuilt;\n\n    void dfs1(int u,\
    \ int p, int d) {\n        dep[u] = d;\n        sz[u] = 1;\n        if(!G[u].empty()\
    \ && G[u].front().to == p) {\n            std::swap(G[u].front(), G[u].back());\n\
    \        }\n        for(auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            dfs1(e.to, u, d + 1);\n            sz[u] += sz[e.to];\n         \
    \   if(sz[e.to] > sz[G[u].front().to]) { std::swap(G[u].front(), e); }\n     \
    \   }\n    }\n\n    void dfs2(int u, int p, int &idx) {\n        par[u] = p;\n\
    \        in[u] = idx++;\n        rev[in[u]] = u;\n        for(const auto &e :\
    \ G[u]) {\n            if(e.to == p) continue;\n            head[e.to] = (e.to\
    \ == G[u].front().to ? head[u] : e.to);\n            dfs2(e.to, u, idx);\n   \
    \     }\n        out[u] = idx;\n    }\n};\n"
  code: "#pragma once\n\n#include <utility>\n\n#include \"../graph_template.hpp\"\n\
    \ntemplate <typename Cost = int> class HeavyLightDecomposition {\n  public:\n\
    \    explicit HeavyLightDecomposition(int N)\n        : G(N), in(N), out(N), sz(N),\
    \ head(N), par(N), dep(N), rev(N),\n          isBuilt(false) {}\n    explicit\
    \ HeavyLightDecomposition(const Graph<Cost> &g)\n        : G(g), in(g.size()),\
    \ out(g.size()), sz(g.size()), head(g.size()),\n          par(g.size()), dep(g.size()),\
    \ rev(g.size()), isBuilt(false) {\n        build();\n    }\n    void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    void build(int root = 0) {\n        dfs1(root, -1, 0);\n        head[root]\
    \ = root;\n        int idx = 0;\n        dfs2(root, -1, idx);\n        isBuilt\
    \ = true;\n    }\n\tint lca(int u, int v) const {\n\t\tassert(isBuilt);\n\t\t\
    assert(0 <= u && u < (int)G.size());\n\t\tassert(0 <= v && v < (int)G.size());\n\
    \t\twhile(1) {\n\t\t\tif(in[u] > in[v]) std::swap(u, v);\n\t\t\tif(head[u] ==\
    \ head[v]) return u;\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\tint dist(int u, int\
    \ v) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\treturn (dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)]);\n\t}\n\tint la(int u, int k) const {\n\t\tassert(isBuilt);\n\t\tassert(0\
    \ <= u && u < (int)G.size());\n\t\tif(dep[u] < k) return -1;\n\t\twhile(1) {\n\
    \t\t\tif(in[u] - k >= in[head[u]]) {\n\t\t\t\treturn rev[in[u] - k];\n\t\t\t}\n\
    \t\t\tk -= (in[u] - in[head[u]] + 1);\n\t\t\tu = par[head[u]];\n\t\t}\n\t}\n\t\
    template<class F>\n\tvoid path_query(int u, int v, const F& f, bool edge = false)\
    \ const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\t\t\
    assert(0 <= v && v < (int)G.size());\n\t\twhile(1) {\n\t\t\tif(in[u] > in[v])\
    \ std::swap(u, v);\n\t\t\tif(head[u] == head[v]) {\n\t\t\t\tf(in[u] + (int)(edge),\
    \ in[v] + 1);\n\t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tf(in[head[v]], in[v] +\
    \ 1);\n\t\t\t}\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate<class F, class\
    \ F_rev>\n\tvoid path_query(int u, int v, const F& f, const F_rev& f_rev, bool\
    \ edge = false) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\tint L = lca(u, v);\n\t\tpath_query<F>(u,\
    \ L, f, edge);\n\t\tpath_query<F_rev>(L, v, f_rev, true);\n\t}\n\ttemplate<class\
    \ F>\n\tvoid subtree_query(int u, const F& f) const {\n\t\tassert(isBuilt);\n\t\
    \tassert(0 <= u && u < (int)G.size());\n\t\tf(in[u], out[u]);\n\t}\n\tint operator[](int\
    \ u) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\treturn in[u];\n\t}\n\n  private:\n    Graph<Cost> G;\n    std::vector<int>\
    \ in, out, sz, head, par, dep, rev;\n    bool isBuilt;\n\n    void dfs1(int u,\
    \ int p, int d) {\n        dep[u] = d;\n        sz[u] = 1;\n        if(!G[u].empty()\
    \ && G[u].front().to == p) {\n            std::swap(G[u].front(), G[u].back());\n\
    \        }\n        for(auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            dfs1(e.to, u, d + 1);\n            sz[u] += sz[e.to];\n         \
    \   if(sz[e.to] > sz[G[u].front().to]) { std::swap(G[u].front(), e); }\n     \
    \   }\n    }\n\n    void dfs2(int u, int p, int &idx) {\n        par[u] = p;\n\
    \        in[u] = idx++;\n        rev[in[u]] = u;\n        for(const auto &e :\
    \ G[u]) {\n            if(e.to == p) continue;\n            head[e.to] = (e.to\
    \ == G[u].front().to ? head[u] : e.to);\n            dfs2(e.to, u, idx);\n   \
    \     }\n        out[u] = idx;\n    }\n};\n"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/hld.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/mytest/graph/tree-api.test.cpp
documentation_of: graph/tree/hld.hpp
layout: document
title: Heavy Light Decomposition
---

## このライブラリでできること

`HeavyLightDecomposition<Cost>` は、木の頂点を配列上に並べ直し、木の上の問い合わせを配列の区間問い合わせへ変換します。たとえば「頂点 $u$ から $v$ までのパス上の値の和」を、セグメント木の区間和へ分解できます。頂点数を $N$ とします。

各頂点で最も大きい部分木へ向かう辺を優先してたどり、長い鎖を連続した添字に並べます。優先しなかった辺を下るたびに部分木の大きさが少なくとも半分になるため、1本のパスは $O(\log N)$ 個の区間に分かれます。また、各部分木は1つの連続区間になります。

## 使い方

辺を追加して `build()` した後、頂点 $v$ の値をセグメント木などの位置 `hld[v]` に置きます。`path_query(u,v,f)` はパスを区間 $[l,r)$ に分解し、各区間について `f(l,r)` を呼びます。区間和なら、その中で `seg.prod(l,r)` を足し合わせる使い方になります。

以下の例は、各区間の長さを足してパス上の頂点数を数えています。$2\to1\to3$ のパスには3頂点あり、最小共通祖先は $1$ です。辺の値を扱う場合は、辺の深い側の頂点に値を置き、`edge=true` で LCA の位置を除きます。

```cpp
#include "template/template.cpp"
#include "graph/tree/hld.hpp"

int main() {
    HeavyLightDecomposition<> hld(4);
    hld.add_edge(0, 1);
    hld.add_edge(1, 2);
    hld.add_edge(1, 3);
    hld.build();
    int count = 0;
    hld.path_query(2, 3, [&](int l, int r) { count += r - l; });
    assert(count == 3 && hld.lca(2, 3) == 1);
}
```

## API・計算量

必要な空間と最大の再帰深さは、どちらも $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `HeavyLightDecomposition(N)` | N 頂点で初期化。 | O(N) |
| `HeavyLightDecomposition(G)` | 木をコピーして根 0 で構築。 | O(N) |
| `add_edge(u, v, cost=1)` | 無向辺追加。 | 償却 O(1) |
| `build(root=0)` | 重い子を選び DFS 順に番号を付ける。 | O(N) |
| `operator[](u)` | 頂点 u の配列上の位置。 | O(1) |
| `lca(u, v)` | 最小共通祖先。 | O(log N) |
| `dist(u, v)` | パスの辺数。重みは無視。 | O(log N) |
| `la(u, k)` | k 個上の祖先。存在しなければ -1。 | O(log N) |
| `path_query(u, v, f, edge=false)` | 分解した [l,r) ごとに f(l,r) を呼ぶ。 | O(log N) 回のコールバック |
| `path_query(u, v, f, f_rev, edge=false)` | u→LCA 側を f、LCA→v 側を f_rev で処理。 | O(log N) 回のコールバック |
| `subtree_query(u, f)` | 部分木の [l,r) に対して f を 1 回呼ぶ。 | O(1) + コールバック |

## 利用条件と実装上の注意

非空・連結な無向木に対して構築してください。辺を追加するコンストラクタでは全辺追加後に `build` が必要ですが、`Graph` を渡すコンストラクタは根0で構築まで行います。`la(u,k)` の $k$ は非負で、根より上なら $-1$ を返します。`dist` は重みではなく辺数です。

通知される区間は、$u$ から $v$ へ歩く順序に並ぶとは限りません。特に関数合成などの非可換な集約では、区間内の向きと区間同士の連結順を呼び出し側で管理してください。2つのコールバックを渡す版も、$v$ 側の区間は終点側から通知されます。

1区間の処理に $O(\log N)$ かかる場合、パス全体は $O(\log^2 N)$ 時間です。部分木の問い合わせは根頂点自身も含み、コールバックは1回だけ呼ばれます。
