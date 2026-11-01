---
title: Segment Tree
documentation_of: //data-structure/segtree/segtree.hpp
---

## 概要

`Segtree<Monoid>` はモノイドの区間積と点更新を扱う。非可換な演算でも左から右の順序を保つ。`N` は列の長さ。

空間 O(N+1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Segtree(), Segtree(n), Segtree(v)` | 空、n 個の単位元、配列 v から構築。 | O(N+1) |
| `set(pos, val)` | 1 点を上書き。 | O(log N) |
| `get(pos)` | 1 点の値。 | O(1) |
| `apply(pos, val)` | A[pos] を op(A[pos],val) にする。 | O(log N) |
| `prod(l, r)` | [l,r) の積。空区間は e()。 | O(log N) |
| `all_prod()` | 全体の積。 | O(1) |
| `max_right(l, f)` | f(prod(l,r)) が true となる最大の r。 | O(log N) |
| `min_left(r, f)` | f(prod(l,r)) が true となる最小の l。 | O(log N) |

## 前提・注意点

`Monoid` は `value_type`、結合的な `op(l,r)`、単位元 `e()` を提供する型。演算・コピーが O(1) であるとして計算量を記す。添字は 0-indexed、区間は半開区間。

境界探索の述語は副作用がなく、`f(e())=true` で、区間を伸ばすと true から false に一度だけ変化する必要がある。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/segtree.hpp"
#include "data-structure/monoid/add.hpp"

int main() {
    Segtree<MonoidAdd<long long>> seg(vector<long long>{1, 2, 3});
    seg.set(1, 5);
    assert(seg.prod(0, 3) == 9);
    assert(seg.max_right(0, [](long long x) { return x <= 6; }) == 2);
}
```

設計の参考: [代数的構造を乗せるデータ構造の設計について](https://noshi91.hatenablog.com/entry/2020/04/22/212649)。
