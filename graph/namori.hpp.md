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
  bundledCode: "#line 2 \"graph/namori.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
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
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 4 \"graph/namori.hpp\"\
    \n\ntemplate <typename Cost> class Namori : public Graph<Cost> {\n  public:\n\
    \    using Graph<Cost>::Graph;\n    using Graph<Cost>::G;\n\n    void build()\
    \ {\n        int N = (int)G.size();\n        std::vector<int> deg(N), st;\n  \
    \      std::vector<bool> seen(N);\n        for(int i = 0; i < N; i++) {\n    \
    \        deg[i] = (int)G[i].size();\n            if(deg[i] == 1) {\n         \
    \       st.emplace_back(i);\n                seen[i] = true;\n            }\n\
    \        }\n        while(!st.empty()) {\n            int u = st.back();\n   \
    \         st.pop_back();\n            for(int v : G[u]) {\n                if(seen[v])\
    \ continue;\n                deg[v]--;\n                if(deg[v] == 1) {\n  \
    \                  st.emplace_back(v);\n                    seen[v] = true;\n\
    \                }\n            }\n        }\n        loop_id.resize(N, -1);\n\
    \        std::vector<int> loop;\n        for(int i = 0; i < N; i++) {\n      \
    \      if(seen[i]) continue;\n            auto dfs = [&](auto &&self, int u) ->\
    \ void {\n                loop_id[u] = (int)loop.size();\n                loop.push_back(u);\n\
    \                seen[u] = true;\n                for(int v : G[u]) {\n      \
    \              if(seen[v]) continue;\n                    self(self, v);\n   \
    \             }\n            };\n            dfs(dfs, i);\n            break;\n\
    \        }\n        for(int i = 0; i < (int)loop.size(); i++) {\n            auto\
    \ dfs = [&](auto&& self, int u) -> void {\n                for(int v : G[u]) {\n\
    \                    if(loop_id[v] != -1) continue;\n                    loop_id[v]\
    \ = loop_id[u];\n                    self(self, v);\n                }\n     \
    \       };\n            dfs(dfs, loop[i]);\n        }\n    }\n    int operator[](int\
    \ i) const { return loop_id[i]; }\n\n  private:\n    std::vector<int> loop_id;\n\
    };\n"
  code: "#pragma once\n\n#include \"graph_template.hpp\"\n\ntemplate <typename Cost>\
    \ class Namori : public Graph<Cost> {\n  public:\n    using Graph<Cost>::Graph;\n\
    \    using Graph<Cost>::G;\n\n    void build() {\n        int N = (int)G.size();\n\
    \        std::vector<int> deg(N), st;\n        std::vector<bool> seen(N);\n  \
    \      for(int i = 0; i < N; i++) {\n            deg[i] = (int)G[i].size();\n\
    \            if(deg[i] == 1) {\n                st.emplace_back(i);\n        \
    \        seen[i] = true;\n            }\n        }\n        while(!st.empty())\
    \ {\n            int u = st.back();\n            st.pop_back();\n            for(int\
    \ v : G[u]) {\n                if(seen[v]) continue;\n                deg[v]--;\n\
    \                if(deg[v] == 1) {\n                    st.emplace_back(v);\n\
    \                    seen[v] = true;\n                }\n            }\n     \
    \   }\n        loop_id.resize(N, -1);\n        std::vector<int> loop;\n      \
    \  for(int i = 0; i < N; i++) {\n            if(seen[i]) continue;\n         \
    \   auto dfs = [&](auto &&self, int u) -> void {\n                loop_id[u] =\
    \ (int)loop.size();\n                loop.push_back(u);\n                seen[u]\
    \ = true;\n                for(int v : G[u]) {\n                    if(seen[v])\
    \ continue;\n                    self(self, v);\n                }\n         \
    \   };\n            dfs(dfs, i);\n            break;\n        }\n        for(int\
    \ i = 0; i < (int)loop.size(); i++) {\n            auto dfs = [&](auto&& self,\
    \ int u) -> void {\n                for(int v : G[u]) {\n                    if(loop_id[v]\
    \ != -1) continue;\n                    loop_id[v] = loop_id[u];\n           \
    \         self(self, v);\n                }\n            };\n            dfs(dfs,\
    \ loop[i]);\n        }\n    }\n    int operator[](int i) const { return loop_id[i];\
    \ }\n\n  private:\n    std::vector<int> loop_id;\n};"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/namori.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/namori.hpp
layout: document
title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\u89E3"
---

## このライブラリでできること

`Namori<Cost>` は、連結な無向グラフに閉路がちょうど1つある「なもりグラフ」を、閉路とそこから伸びる木に分けます。閉路の辺を除くと、各頂点は閉路上のちょうど1頂点を根とする木に属します。その根の識別番号を各頂点に付けるクラスです。

次数1の頂点を繰り返し取り除くと閉路だけが残ります。そこから各木へ番号を伝えるので、頂点数 $N$、辺数 $M$ に対して構築時間は $O(N+M)$ です。

## 使い方

`Graph` と同じように無向辺を追加し、最後に `build()` を呼びます。構築後の `g[v]` は隣接リストではなく、頂点 $v$ に対応する閉路頂点の番号を返します。

例では $0,1,2$ が閉路を作り、$3$ は $1$ から伸びる枝にあります。したがって $1,3$ には同じ番号が付きます。同じ枝の木に属するかどうかは、この番号の一致で判定できます。

```cpp
#include "template/template.cpp"
#include "graph/namori.hpp"

int main() {
    Namori<int> g(4);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    g.add_undirected_edge(2, 0);
    g.add_undirected_edge(1, 3);
    g.build();
    assert(g[1] == g[3]);
}
```

## API・計算量

保持するグラフと作業配列に $O(N+M)$、再帰スタックに最大 $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Namori(N)` | N 頂点を作る。 | O(N) |
| `add_undirected_edge(u, v, cost=1)` | 辺追加（Graph から継承）。 | 償却 O(1) |
| `size()` | 頂点数（継承）。 | O(1) |
| `build()` | 葉を除去して閉路を抽出し、枝の頂点に閉路 ID を付ける。 | O(N+M) |
| `operator[](v)` | v が属する閉路頂点の ID。 | O(1) |

## 利用条件と実装上の注意

単純・連結な無向なもりグラフを渡し、全辺の追加後に一度だけ `build()` してください。辺重みは分解に使いません。結果の番号は閉路を探索した順序であり、元の頂点番号ではありません。

`operator[]` は親クラス `Graph` の同名メソッドを隠します。その他の継承された辺追加や頂点数取得の API は、`Graph` の説明に従います。深い木では再帰の深さが $O(N)$ になります。
