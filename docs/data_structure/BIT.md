---
title: Binary Indexed Tree
documentation_of: ../../data_structure/BIT.hpp
---

## 内容
- 1点更新区間sum取得が出来るデータ構造
- segtree より定数倍が良い
## 使い方
- `sum(k)`: $[0, k)$の和を求める
- `sum(l, r)`: $[l, r)$の和を求める。$l \geq r$の時は0を返す
- `add(k, x)`: index $k$ に$x$を足す
- `lower_bound(x)`: $[0, r)$のsumが$x$以上になるような最小の$r$を返す
## 計算量
- `add`,`sum`,`lower_bound`は全て$O(\log{N})$