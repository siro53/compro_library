---
title: Wavelet Matrix
documentation_of: //data-structure/wavelet-matrix.hpp
---

## 概要

非負整数列 $A$ に対して以下の操作を行うデータ構造。

以下、$A$ の要素数を $N$、$A$ の最大値を $M$ とする。 

- `access(i)` : $A_i$ を返す。$O(\log(M))$
- `rank(i, x)` : 値 $x$ が区間 $[0, i)$ に何個あるかを求める。$O(\log(M))$
- `select(i, x)` : 左から $i$ 個目の値 $x$ の位置を返す。$O(\log(N)\log(M))$
- `quantile(l, r, i)` : 区間 $[l, r)$ に含まれる要素の中で、$i$ 番目に小さい値を返す。$O(\log(M))$
- `rangefreq(l, r, x)` : 区間 $[l, r)$ に含まれる要素の中で、$x$ 未満の値を返す。$O(\log(M))$
- `prev_value(l, r, x)` : $\max_{l \leq i < r, A_i < x} A_i$ を返す。$O(\log(M))$
- `next_value(l, r, x)` : $\min_{l \leq i < r, A_i \geq x} A_i$ を返す。$O(\log(M))$

## メモ
- $A$ に負の値が入ってるとバグるので、その場合は適切に座圧して使うこと。
- 最下段の完備辞書に対して元の列$A$でのindexを保持しておくと、 `select` 操作を $O(\log(M))$ にすることが出来る。しかし、そもそも競プロで `select` を使う機会があまりないことからその工夫は行っていない。
- また、完備辞書において `select` を定数時間で行えるようにすることでも $O(\log(M))$ にすることが出来るが、定数が重すぎるため実用的ではない(らしい)。
- 完備辞書は succinct なものではなく compact なものを使っている（競プロの範囲なら compact でも問題ないため）。どちらが早いかは未検証。