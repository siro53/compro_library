---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/range_edge_graph.hpp\"\ntemplate<typename Cost>\n\
    class range_edge_graph {\nprivate:\n    struct E {\n        int to;\n        Cost\
    \ cost;\n        E() {}\n        E(int to, Cost cost): to(to), cost(cost) {}\n\
    \    };\n    int N;\n    vector<vector<E>> G;\n \n    // map [3n, 4n) -> [n, 2n)\n\
    \    void add_edge(int from, int to, Cost cost) {\n        if(3*N <= from) from\
    \ -= 2*N;\n        G[from].emplace_back(to, cost);\n    }\n \npublic:\n    range_edge_graph(int\
    \ N): N(N) {\n        G.resize(3*N);\n        for(int i = 1; i < N; i++) {\n \
    \           int chl = (i << 1) | 0, chr = (i << 1) | 1;\n            // \u4E0A\
    \u5074, \u6839 -> \u8449\n            add_edge(i, chl, 0);\n            add_edge(i,\
    \ chr, 0);\n            // \u4E0B\u5074, \u8449 -> \u6839\n            add_edge(chl+2*N,\
    \ i+2*N, 0);\n            add_edge(chr+2*N, i+2*N, 0);\n        }\n    }\n   \
    \ \n    void add_edge(int l1, int r1, int l2, int r2, Cost cost) {\n        int\
    \ id = (int)G.size();\n        // \u4E0B\u5074\u306E[l1, r1) -> id\n        for(l1\
    \ += N, r1 += N; l1 < r1; l1 >>= 1, r1 >>= 1) {\n            if(l1 & 1) add_edge(l1+2*N,\
    \ id, 0), l1++;\n            if(r1 & 1) r1--, add_edge(r1+2*N, id, 0);\n     \
    \   }\n        vector<E> ad;\n        // id -> \u4E0A\u5074\u306E[l2, r2)\n  \
    \      for(l2 += N, r2 += N; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if(l2\
    \ & 1) ad.emplace_back(l2++, cost);\n            if(r2 & 1) ad.emplace_back(--r2,\
    \ cost);\n        }\n        G.emplace_back(ad);\n    }\n \n    vector<Cost> dijkstra(int\
    \ s) {\n        s += N;\n        vector<Cost> dist(G.size(), numeric_limits<Cost>::max());\n\
    \        dist[s] = 0;\n        using P = pair<Cost, int>;\n        priority_queue<P,\
    \ vector<P>, greater<P>> que;\n        que.emplace(0, s);\n        while(!que.empty())\
    \ {\n            auto [d, u] = que.top();\n            que.pop();\n          \
    \  if(d > dist[u]) continue;\n            for(const auto& [to, cost] : G[u]) {\n\
    \                if(dist[to] > d + cost) {\n                    dist[to] = d +\
    \ cost;\n                    que.emplace(dist[to], to);\n                }\n \
    \           }\n        }\n        vector<Cost> ret(dist.begin() + N, dist.begin()\
    \ + 2*N);\n        return ret;\n    }\n\n    pair<vector<Cost>, vector<int>> restore(int\
    \ s, int g) {\n        s += N;\n        vector<Cost> dist(G.size(), numeric_limits<Cost>::max());\n\
    \        vector<int> pre(G.size(), -1);\n        dist[s] = 0;\n        using P\
    \ = pair<Cost, int>;\n        priority_queue<P, vector<P>, greater<P>> que;\n\
    \        que.emplace(0, s);\n        while(!que.empty()) {\n            auto [d,\
    \ u] = que.top();\n            que.pop();\n            if(d > dist[u]) continue;\n\
    \            for(const auto& [to, cost] : G[u]) {\n                if(dist[to]\
    \ > d + cost) {\n                    dist[to] = d + cost;\n                  \
    \  pre[to] = u; \n                    que.emplace(dist[to], to);\n           \
    \     }\n            }\n        }\n        vector<int> path;\n        {\n    \
    \        int now = g + N;\n            while(now != -1) {\n                if(N\
    \ <= now and now < 2*N) path.emplace_back(now - N);\n                now = pre[now];\n\
    \            }\n            reverse(ALL(path));\n        }\n        vector<Cost>\
    \ dist_ret(dist.begin() + N, dist.begin() + 2*N);\n        return {dist_ret, path};\n\
    \    }\n};\n"
  code: "template<typename Cost>\nclass range_edge_graph {\nprivate:\n    struct E\
    \ {\n        int to;\n        Cost cost;\n        E() {}\n        E(int to, Cost\
    \ cost): to(to), cost(cost) {}\n    };\n    int N;\n    vector<vector<E>> G;\n\
    \ \n    // map [3n, 4n) -> [n, 2n)\n    void add_edge(int from, int to, Cost cost)\
    \ {\n        if(3*N <= from) from -= 2*N;\n        G[from].emplace_back(to, cost);\n\
    \    }\n \npublic:\n    range_edge_graph(int N): N(N) {\n        G.resize(3*N);\n\
    \        for(int i = 1; i < N; i++) {\n            int chl = (i << 1) | 0, chr\
    \ = (i << 1) | 1;\n            // \u4E0A\u5074, \u6839 -> \u8449\n           \
    \ add_edge(i, chl, 0);\n            add_edge(i, chr, 0);\n            // \u4E0B\
    \u5074, \u8449 -> \u6839\n            add_edge(chl+2*N, i+2*N, 0);\n         \
    \   add_edge(chr+2*N, i+2*N, 0);\n        }\n    }\n    \n    void add_edge(int\
    \ l1, int r1, int l2, int r2, Cost cost) {\n        int id = (int)G.size();\n\
    \        // \u4E0B\u5074\u306E[l1, r1) -> id\n        for(l1 += N, r1 += N; l1\
    \ < r1; l1 >>= 1, r1 >>= 1) {\n            if(l1 & 1) add_edge(l1+2*N, id, 0),\
    \ l1++;\n            if(r1 & 1) r1--, add_edge(r1+2*N, id, 0);\n        }\n  \
    \      vector<E> ad;\n        // id -> \u4E0A\u5074\u306E[l2, r2)\n        for(l2\
    \ += N, r2 += N; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if(l2 & 1) ad.emplace_back(l2++,\
    \ cost);\n            if(r2 & 1) ad.emplace_back(--r2, cost);\n        }\n   \
    \     G.emplace_back(ad);\n    }\n \n    vector<Cost> dijkstra(int s) {\n    \
    \    s += N;\n        vector<Cost> dist(G.size(), numeric_limits<Cost>::max());\n\
    \        dist[s] = 0;\n        using P = pair<Cost, int>;\n        priority_queue<P,\
    \ vector<P>, greater<P>> que;\n        que.emplace(0, s);\n        while(!que.empty())\
    \ {\n            auto [d, u] = que.top();\n            que.pop();\n          \
    \  if(d > dist[u]) continue;\n            for(const auto& [to, cost] : G[u]) {\n\
    \                if(dist[to] > d + cost) {\n                    dist[to] = d +\
    \ cost;\n                    que.emplace(dist[to], to);\n                }\n \
    \           }\n        }\n        vector<Cost> ret(dist.begin() + N, dist.begin()\
    \ + 2*N);\n        return ret;\n    }\n\n    pair<vector<Cost>, vector<int>> restore(int\
    \ s, int g) {\n        s += N;\n        vector<Cost> dist(G.size(), numeric_limits<Cost>::max());\n\
    \        vector<int> pre(G.size(), -1);\n        dist[s] = 0;\n        using P\
    \ = pair<Cost, int>;\n        priority_queue<P, vector<P>, greater<P>> que;\n\
    \        que.emplace(0, s);\n        while(!que.empty()) {\n            auto [d,\
    \ u] = que.top();\n            que.pop();\n            if(d > dist[u]) continue;\n\
    \            for(const auto& [to, cost] : G[u]) {\n                if(dist[to]\
    \ > d + cost) {\n                    dist[to] = d + cost;\n                  \
    \  pre[to] = u; \n                    que.emplace(dist[to], to);\n           \
    \     }\n            }\n        }\n        vector<int> path;\n        {\n    \
    \        int now = g + N;\n            while(now != -1) {\n                if(N\
    \ <= now and now < 2*N) path.emplace_back(now - N);\n                now = pre[now];\n\
    \            }\n            reverse(ALL(path));\n        }\n        vector<Cost>\
    \ dist_ret(dist.begin() + N, dist.begin() + 2*N);\n        return {dist_ret, path};\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/range_edge_graph.hpp
  requiredBy: []
  timestamp: '2021-10-27 00:26:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/range_edge_graph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF"
---

## 内容
- [Lorentさんの記事を参考に実装](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
    - というかほぼパクっています...
- セグ木の形にしてノードを追加することで、区間から区間に辺を張る、という操作が高速に行えるようになる。
- 参考にしている記事の追記の箇所を参考に、頂点数を$3N$個にする実装(上側の葉と下側の葉をくっつけてしまう)をしている。

## 使い方
- `range_edge_graph<Cost>(int N)` : 頂点数$N$のグラフを作成、辺のコストの型が`Cost`
- `add_edge(int l1, int r1, int l2, int r2, Cost cost)` : $[l1, r1)$から$[l2, r2)$にコスト`cost`の辺を張る
- `dijkstra(int s)` : 頂点`s`を始点としてダイクストラする
- `restore(int s, int g)` : ダイクストラしたあと、頂点s -> gの経路も復元する

## 計算量
頂点数を $N$ 、辺の追加回数を $Q$ とする。
- グラフの初期化：$Θ(N)$
- 辺の追加：$O(log(N))$
- dijkstra：多重辺がない場合、$O((N+Qlog(N))log(N))$

## 出題例
- [有名](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d)
- [復元も要る](https://codeforces.com/contest/1602/problem/D)
    - `restore(int s, int g)`はここでverifyした