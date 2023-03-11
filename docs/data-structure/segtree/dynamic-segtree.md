---
title: Dynamic Segment Tree
documentation_of: //data-structure/segtree/dynamic-segtree.hpp
link: https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
---

必要なノードだけ作るセグメント木。

基本機能は`data-structure/segtree/segtree.hpp`と同じ。

テンプレート引数`id_min, id_max` に添字として取りうる最小値と最大値を入れて使う。