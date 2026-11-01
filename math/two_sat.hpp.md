---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/two-sat.test.cpp
    title: test/library-checker/math/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/graph-scc-two-sat.test.cpp
    title: test/mytest/graph/graph-scc-two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/lca-and-empty-two-sat.test.cpp
    title: test/mytest/graph/lca-and-empty-two-sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/two_sat.hpp\"\n\n#line 2 \"graph/scc.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 4 \"graph/graph_template.hpp\"\n#include <cstddef>\n#line 6 \"graph/graph_template.hpp\"\
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
    #line 8 \"graph/scc.hpp\"\n\ntemplate <typename Cost = int> class SCC {\n  public:\n\
    \    explicit SCC(int N)\n        : G(N), G_rev(N), comp(N, -1), seen(N, false),\
    \ isBuilt(false) {}\n    explicit SCC(const Graph<Cost> &g)\n        : G(g), G_rev(g.size()),\
    \ comp(g.size(), -1), seen(g.size(), false), isBuilt(false) {\n        for(int\
    \ i = 0; i < (int)g.size(); i++) {\n            for(const auto &e : g[i]) G_rev.add_directed_edge(e.to,\
    \ i);\n        }\n        build();\n    }\n    inline void add_directed_edge(int\
    \ from, int to) {\n        assert(!isBuilt &&\n               \"This scc_graph\
    \ is already built, but you tried to add edge.\");\n        G.add_directed_edge(from,\
    \ to);\n        G_rev.add_directed_edge(to, from);\n    }\n    void build() {\n\
    \        assert(!isBuilt && \"This scc_graph is already built.\");\n        for(int\
    \ i = 0; i < (int)G.size(); i++) {\n            if(!seen[i]) dfs(i);\n       \
    \ }\n        std::reverse(vs.begin(), vs.end());\n        count = 0;\n       \
    \ for(const int v : vs) {\n            if(comp[v] == -1) {\n                dfs_rev(v,\
    \ count);\n                count++;\n            }\n        }\n        isBuilt\
    \ = true;\n    }\n    Graph<Cost> get_contracted_graph() {\n        assert(isBuilt\
    \ && \"This scc_graph is not yet built.\");\n        Graph<Cost> new_g(count);\n\
    \        for(int i = 0; i < (int)G.size(); i++) {\n            for(const auto\
    \ &e : G[i]) {\n                int from = comp[i];\n                int to =\
    \ comp[e.to];\n                if(from != to) new_g.add_directed_edge(from, to,\
    \ e.cost);\n            }\n        }\n        return new_g;\n    }\n    int operator[](const\
    \ int &k) const {\n        assert(isBuilt && \"This scc_graph is not yet built.\"\
    );\n        return comp[k];\n    }\n    size_t size() { return (size_t)count;\
    \ }\n\n  private:\n    Graph<Cost> G, G_rev;\n    std::vector<int> vs, comp;\n\
    \    std::vector<bool> seen;\n    int count;\n    bool isBuilt;\n\n    void dfs(int\
    \ u) {\n        seen[u] = true;\n        for(const auto &e : G[u]) {\n       \
    \     if(!seen[e.to]) dfs(e.to);\n        }\n        vs.push_back(u);\n    }\n\
    \    void dfs_rev(int u, int idx) {\n        comp[u] = idx;\n        for(const\
    \ auto &e : G_rev[u]) {\n            if(comp[e.to] == -1) dfs_rev(e.to, idx);\n\
    \        }\n    }\n};\n#line 4 \"math/two_sat.hpp\"\n\ntemplate<class Cost = int>\n\
    class TwoSat {\npublic:\n    TwoSat(): TwoSat(0) {}\n    explicit TwoSat(int N):\
    \ N(N), scc(N * 2), ans(N), called_satisfiable(false) {}\n\n    void add_clause(int\
    \ i, bool f_i, int j, bool f_j) {\n        if(!f_i) i = NOT(i);\n        if(!f_j)\
    \ j = NOT(j);\n        scc.add_directed_edge(i, NOT(j));\n        scc.add_directed_edge(j,\
    \ NOT(i));\n    }\n    bool satisfiable() {\n        scc.build();\n        for(int\
    \ i = 0; i < N; i++) {\n            if(scc[i] == scc[NOT(i)]) return false;\n\
    \            ans[i] = (scc[i] < scc[NOT(i)]);\n        }\n        called_satisfiable\
    \ = true;\n        return true;\n    }\n    std::vector<bool> get_answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int N;\n    SCC<Cost> scc;\n    std::vector<bool> ans;\n    bool called_satisfiable;\n\
    \n    inline int NOT(int i) { return i + (i < N ? N : -N); }\n};\n"
  code: "#pragma once\n\n#include \"../graph/scc.hpp\"\n\ntemplate<class Cost = int>\n\
    class TwoSat {\npublic:\n    TwoSat(): TwoSat(0) {}\n    explicit TwoSat(int N):\
    \ N(N), scc(N * 2), ans(N), called_satisfiable(false) {}\n\n    void add_clause(int\
    \ i, bool f_i, int j, bool f_j) {\n        if(!f_i) i = NOT(i);\n        if(!f_j)\
    \ j = NOT(j);\n        scc.add_directed_edge(i, NOT(j));\n        scc.add_directed_edge(j,\
    \ NOT(i));\n    }\n    bool satisfiable() {\n        scc.build();\n        for(int\
    \ i = 0; i < N; i++) {\n            if(scc[i] == scc[NOT(i)]) return false;\n\
    \            ans[i] = (scc[i] < scc[NOT(i)]);\n        }\n        called_satisfiable\
    \ = true;\n        return true;\n    }\n    std::vector<bool> get_answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int N;\n    SCC<Cost> scc;\n    std::vector<bool> ans;\n    bool called_satisfiable;\n\
    \n    inline int NOT(int i) { return i + (i < N ? N : -N); }\n};"
  dependsOn:
  - graph/scc.hpp
  - graph/graph_template.hpp
  isVerificationFile: false
  path: math/two_sat.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/math/two-sat.test.cpp
  - test/mytest/graph/lca-and-empty-two-sat.test.cpp
  - test/mytest/graph/graph-scc-two-sat.test.cpp
documentation_of: math/two_sat.hpp
layout: document
title: 2-SAT
---

## このライブラリでできること

`TwoSat` は、bool変数に対する「2つの条件の少なくとも一方が成り立つ」という制約を集め、すべて同時に満たせるかを判定します。変数数を $N$、節の数を $Q$ とすると、判定は $O(N+Q)$ 時間です。

節 $(a\lor b)$ は、含意 $\lnot a\Rightarrow b$ と $\lnot b\Rightarrow a$ に言い換えられます。変数とその否定の含意関係をグラフにし、同じ変数の真偽が同じ強連結成分へ入ってしまうかを調べることで、矛盾を検出します。

## 使い方

`add_clause(i,fi,j,fj)` は $(x_i=fi)\lor(x_j=fj)$ を追加します。真に固定したい変数には、同じリテラルを2回渡せます。

例の最初の節は $x_0$ を真に固定し、次の節 $(\lnot x_0)\lor x_1$ は、その場合に $x_1$ も真であることを要求します。`satisfiable()` が真を返した後、`get_answer()` で条件を満たす割当を取得します。

```cpp
#include "template/template.cpp"
#include "math/two_sat.hpp"

int main() {
    TwoSat<> sat(2);
    sat.add_clause(0, true, 0, true);
    sat.add_clause(0, false, 1, true);
    assert(sat.satisfiable());
    auto ans = sat.get_answer();
    assert(ans[0] && ans[1]);
}
```

## API・計算量

必要な空間は $O(N+Q)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `TwoSat(), TwoSat(N)` | 変数0個、または N 個で初期化。 | O(N+1) |
| `add_clause(i, fi, j, fj)` | (x[i]==fi) OR (x[j]==fj) を追加。 | 償却 O(1) |
| `satisfiable()` | 充足可能なら true、割当を保存。 | O(N+Q) |
| `get_answer()` | 成功時の割当 vector<bool> をコピーして返す。 | O(N) |

## 利用条件と実装上の注意

変数番号は $[0,N)$ です。すべての節を追加してから判定を一度だけ実行してください。内部のSCCを構築するため、判定後の追加や再判定には対応していません。

`get_answer()` は充足可能と判定された後にだけ呼べます。割当が複数ある場合は、そのうち1つを返します。デフォルト構築は変数数0です。空の問題は充足可能で、答えは空の配列になります。
