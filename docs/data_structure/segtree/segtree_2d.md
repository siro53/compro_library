---
title: 2次元セグメント木
documentation_of: ../../../data_structure/segtree/segtree_2d.hpp
---

## 内容
- 2次元セグメント木

## 使い方
- `S`: モノイドの型
- `op(S, S)`: モノイドの演算
- `e()`: モノイドの単位元
- `set(i, j, val)`: $(i, j)$に`val`をプロット(代入)する
- `get(i, j, val)`: $(i, j)$にプロットされている値を取得する
- `prod(li, lj, ri, rj)`: $[li, ri) × [lj, rj)$の矩形範囲のモノイドの総積を取得する。

## 計算量
$H × W$ の大きさの2次元セグメント木を作ると仮定する。

また、`op, e`が定数時間で計算できると仮定する。

- 空間 $O(HW)$
- `set, prod`: $O((\log{H})(\log{W}))$
- `get`: $O(1)$

## verify
- https://atcoder.jp/contests/abc228/submissions/27417534