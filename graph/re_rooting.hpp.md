---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki1333.test.cpp
    title: test/yuki1333.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/re_rooting.hpp\"\ntemplate<class S, S (*op)(S, int),\
    \ S (*merge)(S, S), S (*op2)(S, int), S (*e)()>\nclass re_rooting {\nprivate:\n\
    \    int N;\n    vector<vector<int>> G;\n    vector<vector<S>> dp;\n\n    S dfs1(int\
    \ u, int p) {\n        S res = e();\n        for(int i = 0; i < (int)G[u].size();\
    \ i++) {\n            if(G[u][i] == p) continue;\n            int v = G[u][i];\n\
    \            dp[u][i] = dfs1(v, u);\n            res = merge(res, op(dp[u][i],\
    \ v));\n        }\n        return op2(res, u);\n    }\n\n    void dfs2(int u,\
    \ int p, S from_par) {\n        int sz = (int)G[u].size();\n        for(int i\
    \ = 0; i < sz; i++) {\n            if(G[u][i] == p) {\n                dp[u][i]\
    \ = from_par;\n                break;\n            }\n        }\n        vector<S>\
    \ rsum(sz + 1);\n        rsum[sz] = e();\n        for(int i = sz-1; i >= 0; i--)\
    \ {\n            rsum[i] = merge(rsum[i+1], op(dp[u][i], G[u][i]));\n        }\n\
    \        S lsum = e();\n        for(int i = 0; i < sz; i++) {\n            int\
    \ v = G[u][i];\n            if(v != p) {\n                S val = merge(lsum,\
    \ rsum[i+1]);\n                dfs2(v, u, op2(val, u));\n            }\n     \
    \       lsum = merge(lsum, op(dp[u][i], v));\n        }\n    }\n\n    void build(int\
    \ root) {\n        for(int i = 0; i < N; i++) dp[i].resize(G[i].size());\n   \
    \     dfs1(root, -1);\n        dfs2(root, -1, e());\n    }\n    \npublic:\n  \
    \  re_rooting(int N): N(N), G(N), dp(N) {}\n    re_rooting(const vector<vector<int>>&\
    \ G): N(G.size()), G(G), dp(G.size()) {}\n\n    void add_edge(int u, int v) {\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n    vector<S>\
    \ solve(int root = 0) {\n        build(root);\n        vector<S> ans(N);\n   \
    \     for(int u = 0; u < N; u++) {\n            S res = e();\n            for(int\
    \ i = 0; i < (int)G[u].size(); i++) {\n                res = merge(res, op(dp[u][i],\
    \ G[u][i]));\n            }\n            ans[u] = op2(res, u);\n        }\n  \
    \      return ans;\n    }\n};\n\ntemplate<class T>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    Edge() = default;\n    Edge(int from, int to, T cost):\
    \ from(from), to(to), cost(cost) {}\n    operator int() const { return to; }\n\
    };\n\ntemplate<class S, class Cost, S (*op)(S, Edge<Cost>), S (*merge)(S, S),\
    \ S (*op2)(S, int), S (*e)()>\nclass re_rooting_edge {\nprivate:\n    int N;\n\
    \    vector<vector<Edge<Cost>>> G;\n    vector<vector<S>> dp;\n\n    S dfs1(int\
    \ u, int p) {\n        S res = e();\n        for(int i = 0; i < (int)G[u].size();\
    \ i++) {\n            int v = G[u][i];\n            if(v == p) continue;\n   \
    \         dp[u][i] = dfs1(v, u);\n            res = merge(res, op(dp[u][i], G[u][i]));\n\
    \        }\n        return op2(res, u);\n    }\n\n    void dfs2(int u, int p,\
    \ S from_par) {\n        int sz = (int)G[u].size();\n        for(int i = 0; i\
    \ < sz; i++) {\n            if(G[u][i] == p) {\n                dp[u][i] = from_par;\n\
    \                break;\n            }\n        }\n        vector<S> rsum(sz +\
    \ 1);\n        rsum[sz] = e();\n        for(int i = sz-1; i >= 0; i--) {\n   \
    \         rsum[i] = merge(rsum[i+1], op(dp[u][i], G[u][i]));\n        }\n    \
    \    S lsum = e();\n        for(int i = 0; i < sz; i++) {\n            int v =\
    \ G[u][i];\n            if(v != p) {\n                S val = merge(lsum, rsum[i+1]);\n\
    \                dfs2(v, u, op2(val, u));\n            }\n            lsum = merge(lsum,\
    \ op(dp[u][i], G[u][i]));\n        }\n    }\n\n    void build(int root) {\n  \
    \      for(int i = 0; i < N; i++) dp[i].resize(G[i].size());\n        dfs1(root,\
    \ -1);\n        dfs2(root, -1, e());\n    }\n\npublic:\n    re_rooting_edge(int\
    \ N): N(N), G(N), dp(N) {}\n    re_rooting_edge(const vector<vector<Edge<Cost>>>&\
    \ G): N(G.size()), G(G), dp(G.size()) {}\n\n    void add_edge(int u, int v, Cost\
    \ cost) {\n        G[u].emplace_back(u, v, cost);\n        G[v].emplace_back(v,\
    \ u, cost);\n    }\n\n    vector<S> solve(int root = 0) {\n        build(root);\n\
    \        vector<S> ans(N);\n        for(int u = 0; u < N; u++) {\n           \
    \ S res = e();\n            for(int i = 0; i < (int)G[u].size(); i++) {\n    \
    \            res = merge(res, op(dp[u][i], G[u][i]));\n            }\n       \
    \     ans[u] = op2(res, u);\n        }\n        return ans;\n    }\n};\n"
  code: "template<class S, S (*op)(S, int), S (*merge)(S, S), S (*op2)(S, int), S\
    \ (*e)()>\nclass re_rooting {\nprivate:\n    int N;\n    vector<vector<int>> G;\n\
    \    vector<vector<S>> dp;\n\n    S dfs1(int u, int p) {\n        S res = e();\n\
    \        for(int i = 0; i < (int)G[u].size(); i++) {\n            if(G[u][i] ==\
    \ p) continue;\n            int v = G[u][i];\n            dp[u][i] = dfs1(v, u);\n\
    \            res = merge(res, op(dp[u][i], v));\n        }\n        return op2(res,\
    \ u);\n    }\n\n    void dfs2(int u, int p, S from_par) {\n        int sz = (int)G[u].size();\n\
    \        for(int i = 0; i < sz; i++) {\n            if(G[u][i] == p) {\n     \
    \           dp[u][i] = from_par;\n                break;\n            }\n    \
    \    }\n        vector<S> rsum(sz + 1);\n        rsum[sz] = e();\n        for(int\
    \ i = sz-1; i >= 0; i--) {\n            rsum[i] = merge(rsum[i+1], op(dp[u][i],\
    \ G[u][i]));\n        }\n        S lsum = e();\n        for(int i = 0; i < sz;\
    \ i++) {\n            int v = G[u][i];\n            if(v != p) {\n           \
    \     S val = merge(lsum, rsum[i+1]);\n                dfs2(v, u, op2(val, u));\n\
    \            }\n            lsum = merge(lsum, op(dp[u][i], v));\n        }\n\
    \    }\n\n    void build(int root) {\n        for(int i = 0; i < N; i++) dp[i].resize(G[i].size());\n\
    \        dfs1(root, -1);\n        dfs2(root, -1, e());\n    }\n    \npublic:\n\
    \    re_rooting(int N): N(N), G(N), dp(N) {}\n    re_rooting(const vector<vector<int>>&\
    \ G): N(G.size()), G(G), dp(G.size()) {}\n\n    void add_edge(int u, int v) {\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n    vector<S>\
    \ solve(int root = 0) {\n        build(root);\n        vector<S> ans(N);\n   \
    \     for(int u = 0; u < N; u++) {\n            S res = e();\n            for(int\
    \ i = 0; i < (int)G[u].size(); i++) {\n                res = merge(res, op(dp[u][i],\
    \ G[u][i]));\n            }\n            ans[u] = op2(res, u);\n        }\n  \
    \      return ans;\n    }\n};\n\ntemplate<class T>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    Edge() = default;\n    Edge(int from, int to, T cost):\
    \ from(from), to(to), cost(cost) {}\n    operator int() const { return to; }\n\
    };\n\ntemplate<class S, class Cost, S (*op)(S, Edge<Cost>), S (*merge)(S, S),\
    \ S (*op2)(S, int), S (*e)()>\nclass re_rooting_edge {\nprivate:\n    int N;\n\
    \    vector<vector<Edge<Cost>>> G;\n    vector<vector<S>> dp;\n\n    S dfs1(int\
    \ u, int p) {\n        S res = e();\n        for(int i = 0; i < (int)G[u].size();\
    \ i++) {\n            int v = G[u][i];\n            if(v == p) continue;\n   \
    \         dp[u][i] = dfs1(v, u);\n            res = merge(res, op(dp[u][i], G[u][i]));\n\
    \        }\n        return op2(res, u);\n    }\n\n    void dfs2(int u, int p,\
    \ S from_par) {\n        int sz = (int)G[u].size();\n        for(int i = 0; i\
    \ < sz; i++) {\n            if(G[u][i] == p) {\n                dp[u][i] = from_par;\n\
    \                break;\n            }\n        }\n        vector<S> rsum(sz +\
    \ 1);\n        rsum[sz] = e();\n        for(int i = sz-1; i >= 0; i--) {\n   \
    \         rsum[i] = merge(rsum[i+1], op(dp[u][i], G[u][i]));\n        }\n    \
    \    S lsum = e();\n        for(int i = 0; i < sz; i++) {\n            int v =\
    \ G[u][i];\n            if(v != p) {\n                S val = merge(lsum, rsum[i+1]);\n\
    \                dfs2(v, u, op2(val, u));\n            }\n            lsum = merge(lsum,\
    \ op(dp[u][i], G[u][i]));\n        }\n    }\n\n    void build(int root) {\n  \
    \      for(int i = 0; i < N; i++) dp[i].resize(G[i].size());\n        dfs1(root,\
    \ -1);\n        dfs2(root, -1, e());\n    }\n\npublic:\n    re_rooting_edge(int\
    \ N): N(N), G(N), dp(N) {}\n    re_rooting_edge(const vector<vector<Edge<Cost>>>&\
    \ G): N(G.size()), G(G), dp(G.size()) {}\n\n    void add_edge(int u, int v, Cost\
    \ cost) {\n        G[u].emplace_back(u, v, cost);\n        G[v].emplace_back(v,\
    \ u, cost);\n    }\n\n    vector<S> solve(int root = 0) {\n        build(root);\n\
    \        vector<S> ans(N);\n        for(int u = 0; u < N; u++) {\n           \
    \ S res = e();\n            for(int i = 0; i < (int)G[u].size(); i++) {\n    \
    \            res = merge(res, op(dp[u][i], G[u][i]));\n            }\n       \
    \     ans[u] = op2(res, u);\n        }\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/re_rooting.hpp
  requiredBy: []
  timestamp: '2021-10-19 16:40:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki1333.test.cpp
documentation_of: graph/re_rooting.hpp
layout: document
title: "rerooting(\u5168\u65B9\u4F4D\u6728DP)"
---

## 内容
- 全方位木DPを抽象化したもの。
- 頂点属性の場合は`re_rooting`、辺属性の場合は`re_rooting_edge`を使う

## 使い方
- `add_edge(u, v)` : 無向辺(u, v)を追加
- `solve()` : 全方位木DPした後の結果を返す(vector)

### マージ関数について
頂点$u$を根とする部分木のdpの値を$dp[u]$とする。

頂点$u$の子を$v_1, v_2, ... ,v_k$とおく。

木DPの漸化式が

$dp[u] = op2(merge(op(dp[v_1], v_1), ... , op(dp[v_k], v_k)), u)$

と表せるとき、マージ関数を適切に実装することでこのライブラリが使える。

## 計算量
$O(N)$

## 資料
- [stoqさんのブログ](https://null-mn.hatenablog.com/entry/2020/04/14/124151)