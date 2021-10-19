---
title: 二重辺連結成分分解(BECC)
documentation_of: ../../graph/bi_edge_connected_components.hpp
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

## 出題例
- [2020-2021 Winter Petrozavodsk Camp, UPC contest K問題](https://codeforces.com/gym/103098/problem/K)