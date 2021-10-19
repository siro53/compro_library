---
title: rerooting(全方位木DP)
documentation_of: ../../graph/re_rooting.hpp
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