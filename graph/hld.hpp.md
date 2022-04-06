---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/hld.hpp\"\nclass HeavyLightDecomposition {\n    int\
    \ N;\n    vector<vector<int>> G;\n    vector<int> in, out, sz, head, par, dep,\
    \ rev;\n    bool isBuilt;\n\n    void dfs_sz(int u, int p, int d) {\n        dep[u]\
    \ = d;\n        if(!G[u].empty() and G[u].front() == p) swap(G[u].front(), G[u].back());\n\
    \        for(int& v : G[u]) {\n            if(v == p) continue;\n            dfs_sz(v,\
    \ u, d+1);\n            sz[u] += sz[v];\n            if(sz[v] > sz[G[u].front()])\
    \ swap(v, G[u].front());\n        }\n    }\n\n    void dfs_hld(int u, int p, int\
    \ &k) {\n        par[u] = p;\n        in[u] = k++;\n        rev[in[u]] = u;\n\
    \        for(const int& v : G[u]) {\n            if(v == p) continue;\n      \
    \      head[v] = (v == G[u].front() ? head[u] : v);\n            dfs_hld(v, u,\
    \ k);\n        }\n        out[u] = k;\n    }\n\n  public:\n    HeavyLightDecomposition(int\
    \ N)\n        : N(N), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N), par(N, -1),\
    \ dep(N), rev(N), isBuilt(false) {}\n\n    HeavyLightDecomposition(const vector<vector<int>>\
    \ &g)\n        : N((int)g.size()), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N),\n\
    \          par(N, -1), dep(N), rev(N), isBuilt(false) {}\n\n    inline void add_edge(int\
    \ u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(int root = 0) {\n        dfs_sz(root, -1, 0);\n     \
    \   head[root] = root;\n        int k = 0;\n        dfs_hld(root, -1, k);\n  \
    \      isBuilt = true;\n        // debug(in, head);\n    }\n\n    int operator[](int\
    \ u) {\n        assert(isBuilt and 0 <= u and u < N);\n        return in[u];\n\
    \    }\n\n    int lca(int u, int v) {\n        assert(isBuilt and 0 <= u and u\
    \ < N and 0 <= v and v < N);\n        while(true) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            if(head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    int dist(int u, int v) {\n        assert(isBuilt and\
    \ 0 <= u and u < N and 0 <= v and v < N);\n        return dep[u] + dep[v] - 2\
    \ * dep[lca(u, v)];\n    }\n\n    // \u9802\u70B9u\u304B\u3089\u89AA\u65B9\u5411\
    \u306B\u8DDD\u96E2k\u767B\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int la(int\
    \ u, int k) {\n        assert(isBuilt and 0 <= u and u < N);\n        if(dep[u]\
    \ < k) return -1; \n        while(true) {\n            if(in[u] - k >= in[head[u]])\
    \ return rev[in[u] - k];\n            k -= (in[u] - in[head[u]] + 1);\n      \
    \      u = par[head[u]];\n        }\n    }   \n\n    // \u9802\u70B9\u5C5E\u6027\
    \n    vector<pair<int, int>> path(int u, int v) {\n        assert(isBuilt and\
    \ 0 <= u and u < N and 0 <= v and v < N);\n        // u -> v\u306E\u5411\u304D\
    \u306B\u306A\u308B\u3088\u3046\u306B\u8FD4\u3059\n        vector<pair<int, int>>\
    \ ret;\n        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n   \
    \         if(head[u] == head[v]) {\n                ret.emplace_back(in[u], in[v]\
    \ + 1);\n                break;\n            } else {\n                ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       return ret;\n    }\n\n    // \u8FBA\u5C5E\u6027\n    vector<pair<int,\
    \ int>> path_edge(int u, int v) {\n        assert(isBuilt and 0 <= u and u < N\
    \ and 0 <= v and v < N);\n        vector<pair<int, int>> ret;\n        while(true)\
    \ {\n            if(in[u] > in[v]) swap(u, v);\n            if(head[u] == head[v])\
    \ {\n                if(u != v) ret.emplace_back(in[u] + 1, in[v] + 1);\n    \
    \            break;\n            } else {\n                ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       return ret;\n    }\n\n    pair<int, int> subtree(int u) { \n        assert(isBuilt\
    \ and 0 <= u and u < N);\n        return {in[u], out[u]};\n    }\n};\n"
  code: "class HeavyLightDecomposition {\n    int N;\n    vector<vector<int>> G;\n\
    \    vector<int> in, out, sz, head, par, dep, rev;\n    bool isBuilt;\n\n    void\
    \ dfs_sz(int u, int p, int d) {\n        dep[u] = d;\n        if(!G[u].empty()\
    \ and G[u].front() == p) swap(G[u].front(), G[u].back());\n        for(int& v\
    \ : G[u]) {\n            if(v == p) continue;\n            dfs_sz(v, u, d+1);\n\
    \            sz[u] += sz[v];\n            if(sz[v] > sz[G[u].front()]) swap(v,\
    \ G[u].front());\n        }\n    }\n\n    void dfs_hld(int u, int p, int &k) {\n\
    \        par[u] = p;\n        in[u] = k++;\n        rev[in[u]] = u;\n        for(const\
    \ int& v : G[u]) {\n            if(v == p) continue;\n            head[v] = (v\
    \ == G[u].front() ? head[u] : v);\n            dfs_hld(v, u, k);\n        }\n\
    \        out[u] = k;\n    }\n\n  public:\n    HeavyLightDecomposition(int N)\n\
    \        : N(N), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N), par(N, -1), dep(N),\
    \ rev(N), isBuilt(false) {}\n\n    HeavyLightDecomposition(const vector<vector<int>>\
    \ &g)\n        : N((int)g.size()), G(N), in(N, -1), out(N, -1), sz(N, 1), head(N),\n\
    \          par(N, -1), dep(N), rev(N), isBuilt(false) {}\n\n    inline void add_edge(int\
    \ u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(int root = 0) {\n        dfs_sz(root, -1, 0);\n     \
    \   head[root] = root;\n        int k = 0;\n        dfs_hld(root, -1, k);\n  \
    \      isBuilt = true;\n        // debug(in, head);\n    }\n\n    int operator[](int\
    \ u) {\n        assert(isBuilt and 0 <= u and u < N);\n        return in[u];\n\
    \    }\n\n    int lca(int u, int v) {\n        assert(isBuilt and 0 <= u and u\
    \ < N and 0 <= v and v < N);\n        while(true) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            if(head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    int dist(int u, int v) {\n        assert(isBuilt and\
    \ 0 <= u and u < N and 0 <= v and v < N);\n        return dep[u] + dep[v] - 2\
    \ * dep[lca(u, v)];\n    }\n\n    // \u9802\u70B9u\u304B\u3089\u89AA\u65B9\u5411\
    \u306B\u8DDD\u96E2k\u767B\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int la(int\
    \ u, int k) {\n        assert(isBuilt and 0 <= u and u < N);\n        if(dep[u]\
    \ < k) return -1; \n        while(true) {\n            if(in[u] - k >= in[head[u]])\
    \ return rev[in[u] - k];\n            k -= (in[u] - in[head[u]] + 1);\n      \
    \      u = par[head[u]];\n        }\n    }   \n\n    // \u9802\u70B9\u5C5E\u6027\
    \n    vector<pair<int, int>> path(int u, int v) {\n        assert(isBuilt and\
    \ 0 <= u and u < N and 0 <= v and v < N);\n        // u -> v\u306E\u5411\u304D\
    \u306B\u306A\u308B\u3088\u3046\u306B\u8FD4\u3059\n        vector<pair<int, int>>\
    \ ret;\n        while(true) {\n            if(in[u] > in[v]) swap(u, v);\n   \
    \         if(head[u] == head[v]) {\n                ret.emplace_back(in[u], in[v]\
    \ + 1);\n                break;\n            } else {\n                ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       return ret;\n    }\n\n    // \u8FBA\u5C5E\u6027\n    vector<pair<int,\
    \ int>> path_edge(int u, int v) {\n        assert(isBuilt and 0 <= u and u < N\
    \ and 0 <= v and v < N);\n        vector<pair<int, int>> ret;\n        while(true)\
    \ {\n            if(in[u] > in[v]) swap(u, v);\n            if(head[u] == head[v])\
    \ {\n                if(u != v) ret.emplace_back(in[u] + 1, in[v] + 1);\n    \
    \            break;\n            } else {\n                ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n                v = par[head[v]];\n            }\n        }\n \
    \       return ret;\n    }\n\n    pair<int, int> subtree(int u) { \n        assert(isBuilt\
    \ and 0 <= u and u < N);\n        return {in[u], out[u]};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/hld.hpp
  requiredBy: []
  timestamp: '2022-04-06 16:19:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_subtree_sum.test.cpp
  - test/vertex_set_path_composite.test.cpp
documentation_of: graph/hld.hpp
layout: document
title: "Heavy Light Decomposition (HL\u5206\u89E3)"
---

## 内容
木をHL分解する。

HL分解とは、木を $O(\log{N})$ 本のパスに分解することである。

各頂点の**重み**を、その頂点を根とする部分木のsizeと定義する。

各頂点について根から再帰的に、**子の中で最も重みの大きい頂点**への辺(heavy edge)のみを残し、それ以外の子への辺(light edge)を切る。
これを再帰的に行う。

- [詳しい証明](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [図があって分かりやすい](https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3)

実装の際には、まず1回目のDFSで部分木のsizeを求めつつ、各頂点の隣接リストの先頭に、自分の子かつ最も重みの大きい子を持ってくる。

2回目のDFSでは、各頂点の番号をpre-order（いわゆるオイラーツアーをする）で訪れた順に振り直す。こうすることで、HL分解後の各パスについて頂点番号が連続するため、各パスを区間として扱える。また、オイラーツアーをして番号を振り直したことで部分木クエリにも対応出来る。

- [ferinさんのブログ](https://ferin-tech.hatenablog.com/entry/2019/11/21/HL%E5%88%86%E8%A7%A3%E3%81%AE%E5%AE%9F%E8%A3%85)
- [kazuma8128さんのブログ](https://kazuma8128.hatenablog.com/entry/2018/07/16/010500)

## 使い方
- `add_edge(u, v)`
    - 無向辺 $(u, v)$ を追加
- `build(root)`
    - 根を $root$ とした根付き木に対してHL分解する。これを呼び忘れると`assert()`に引っかかるようになっている。
- `operator[](u)`
    - オイラーツアーして頂点番号を振り直した後の頂点 $u$ の頂点番号を返す。
- `lca(u, v)`
    - 頂点 $u$ と頂点 $v$ のLCAを返す。
- `dist(u, v)`
    - 頂点 $u$ と頂点 $v$ の距離を返す。
- `la(u, k)`
    - 頂点 $u$ から親方向に距離 $k$ だけ遡った先の頂点を返す。$depth(u) < k$ の場合は`-1`を返す。
    - [Level Ancestor Problem](https://suisen-kyopro.hatenablog.com/entry/2022/04/04/043452)
- `path(u, v)`
    - 頂点 $u$ から頂点 $v$ へのパスを $O(\log{N})$ 本の区間として返す。帰ってくる区間は、オイラーツアーをして頂点番号を振り直した後のものが返る。
- `path_edge(u, v)`
    - `path(u, v)`の辺属性 ver.
    - $(u, v)$ という辺があったとしたら、子になる方の頂点が辺に対応した値を持つように実装すればOK（根に対応する値はないものとする。）
    - [使用例1](https://atcoder.jp/contests/past202004-open/submissions/30753354)
    - [使用例2](https://atcoder.jp/contests/abc133/submissions/30753644)
- `subtree(u)`
    - 頂点 $u$ を根とする部分木に対応する区間が返る。

## 注意点

[この問題](https://judge.yosupo.jp/problem/vertex_set_path_composite)のように非可換なクエリが飛んでくる時は注意が必要。

左右の累積を保持する必要があり、載せるデータ構造(セグ木、BITなど)も順方向と逆方向の 2 本必要になる。

```cpp
Monoid resL = e();
Monoid resR = e();
int lca = hld.lca(u, v);
for(const auto& [l, r] : hld.path(u, lca)) {
    resL = op(seg.prod(l, r), resL);
}
for(const auto& [l, r] : hld.path_edge(lca, v)) {
    resR = op(resR, seg_rev.prod(l, r));
}
Monoid res = op(resL, resR);
```
