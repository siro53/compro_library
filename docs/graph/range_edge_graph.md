---
title: 区間に辺を貼るテク
documentation_of: ../../graph/range_edge_graph.hpp
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