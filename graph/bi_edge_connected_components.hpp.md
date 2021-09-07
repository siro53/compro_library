---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/two_edge_connected_components.test.cpp
    title: test/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bi_edge_connected_components.hpp\"\nclass BECC {\n\
    private:\n    int N, sz;\n    vector<vector<int>> G;\n    vector<int> seen, imos,\
    \ comp;\n\n    void dfs1(int u, int p) {\n        seen[u] = 1;\n        bool is_skipped_par\
    \ = false;\n        for(int v : G[u]) {\n            if(v == p and !is_skipped_par)\
    \ {\n                is_skipped_par = true;\n                continue;\n     \
    \       }\n            if(seen[v] == 0) {\n                dfs1(v, u);\n     \
    \           imos[u] += imos[v];\n            } else if(seen[v] == 1) {\n     \
    \           imos[u]++;\n                imos[v]--;\n            }\n        }\n\
    \        seen[u] = 2;\n    }\n\n    void dfs2(int u) {\n        for(int v : G[u])\
    \ {\n            if(comp[v] != -1) continue;\n            comp[v] = (imos[v] ==\
    \ 0 ? sz++ : comp[u]);\n            dfs2(v);\n        }\n    }\n\npublic:\n  \
    \  BECC(int N): N(N), G(N), seen(N, 0), imos(N, 0), sz(0), comp(N, -1) {}\n  \
    \  BECC(vector<vector<int>> g) : N(g.size()), G(g), seen(N, 0), imos(N, 0), sz(0),\
    \ comp(N, -1) {}\n    \n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    } \n\n    void build() {\n        for(int\
    \ i = 0; i < N; i++) {\n            if(seen[i] != 0) continue;\n            dfs1(i,\
    \ -1);\n        }\n        for(int i = 0; i < N; i++) {\n            if(comp[i]\
    \ != -1) continue;\n            comp[i] = sz++;\n            dfs2(i);\n      \
    \  }\n    }\n    \n    // \u5FC5\u305Abuild()\u3057\u305F\u5F8C\u306B\u547C\u3073\
    \u51FA\u3059\u3053\u3068!!!\n    vector<vector<int>> get_contract_graph() {\n\
    \        vector<vector<int>> h(sz);\n        for(int u = 0; u < N; u++) {\n  \
    \          for(const int& v : G[u]) {\n                int x = comp[u], y = comp[v];\n\
    \                if(x == y) continue;\n                h[x].push_back(y);\n  \
    \              h[y].push_back(x);\n            }\n        }\n        return h;\n\
    \    }\n\n    int operator[](int k) const { return comp[k]; }\n    int size()\
    \ const { return sz; }\n};\n"
  code: "class BECC {\nprivate:\n    int N, sz;\n    vector<vector<int>> G;\n    vector<int>\
    \ seen, imos, comp;\n\n    void dfs1(int u, int p) {\n        seen[u] = 1;\n \
    \       bool is_skipped_par = false;\n        for(int v : G[u]) {\n          \
    \  if(v == p and !is_skipped_par) {\n                is_skipped_par = true;\n\
    \                continue;\n            }\n            if(seen[v] == 0) {\n  \
    \              dfs1(v, u);\n                imos[u] += imos[v];\n            }\
    \ else if(seen[v] == 1) {\n                imos[u]++;\n                imos[v]--;\n\
    \            }\n        }\n        seen[u] = 2;\n    }\n\n    void dfs2(int u)\
    \ {\n        for(int v : G[u]) {\n            if(comp[v] != -1) continue;\n  \
    \          comp[v] = (imos[v] == 0 ? sz++ : comp[u]);\n            dfs2(v);\n\
    \        }\n    }\n\npublic:\n    BECC(int N): N(N), G(N), seen(N, 0), imos(N,\
    \ 0), sz(0), comp(N, -1) {}\n    BECC(vector<vector<int>> g) : N(g.size()), G(g),\
    \ seen(N, 0), imos(N, 0), sz(0), comp(N, -1) {}\n    \n    void add_edge(int u,\
    \ int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n   \
    \ } \n\n    void build() {\n        for(int i = 0; i < N; i++) {\n           \
    \ if(seen[i] != 0) continue;\n            dfs1(i, -1);\n        }\n        for(int\
    \ i = 0; i < N; i++) {\n            if(comp[i] != -1) continue;\n            comp[i]\
    \ = sz++;\n            dfs2(i);\n        }\n    }\n    \n    // \u5FC5\u305Abuild()\u3057\
    \u305F\u5F8C\u306B\u547C\u3073\u51FA\u3059\u3053\u3068!!!\n    vector<vector<int>>\
    \ get_contract_graph() {\n        vector<vector<int>> h(sz);\n        for(int\
    \ u = 0; u < N; u++) {\n            for(const int& v : G[u]) {\n             \
    \   int x = comp[u], y = comp[v];\n                if(x == y) continue;\n    \
    \            h[x].push_back(y);\n                h[y].push_back(x);\n        \
    \    }\n        }\n        return h;\n    }\n\n    int operator[](int k) const\
    \ { return comp[k]; }\n    int size() const { return sz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bi_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2021-09-07 12:05:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/two_edge_connected_components.test.cpp
documentation_of: graph/bi_edge_connected_components.hpp
layout: document
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3(BECC)"
---

## 内容
- imos法による実装
- 単純でないグラフや、非連結なグラフにも対応
- [参考文献1](https://www.slideshare.net/chokudai/arc039)

## 使い方
- `add_edge(u, v)` : 無向辺(u, v)を追加
- `build()` : 二重辺連結成分分解する(かならず辺を追加した後行うこと！)
- `get_contract_graph()` : 二重辺連結成分分解した後、連結成分ごとに頂点とみなした(縮約した)グラフを返す。このグラフは必ず木になっている。(必ず`build()`を呼んだ後に呼び出すこと！)
- `operator[k]` : 頂点kがどの連結成分に属しているかのidを返す
- `size()` : 二重辺連結成分分解後の連結成分の個数を返す

## 計算量
- 二重辺連結成分分解は$O(N+M)$で実行できる。