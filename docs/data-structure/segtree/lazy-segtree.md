---
title: Lazy Segment Tree
documentation_of: //data-structure/segtree/lazy-segtree.hpp
---

## 概要

`LazySegtree<MonoidAct>` は区間作用と区間積を遅延伝播で処理する。`N` は列の長さ。各モノイド・作用の演算を O(1) とする。

空間 O(N+1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LazySegtree(), LazySegtree(n), LazySegtree(v)` | 空、n 個の e()、列 v から構築。 | O(N+1) |
| `set(pos, val)` | 点を上書き。 | O(log N) |
| `get(pos)` | 遅延作用を反映した点の値。 | O(log N) |
| `prod(l, r)` | [l,r) の積。 | O(log N) |
| `all_prod()` | 全体の積。 | O(1) |
| `apply(pos, f)` | 点に作用 f を適用。 | O(log N) |
| `apply(l, r, f)` | [l,r) に作用 f を適用。 | O(log N) |
| `max_right(l, g)` | g(prod(l,r)) が true となる最大 r。 | O(log N) |
| `min_left(r, g)` | g(prod(l,r)) が true となる最小 l。 | O(log N) |

## 前提・注意点

`MonoidAct` に `value_type_S`（集約値）、`value_type_F`（作用）、`op/e`（集約の演算・単位元）、`mapping(f,x)`（作用の適用）、`composition(f,g)`（g の後に f を適用）、`id()`（恒等作用）を定義する。`mapping` は区間の結合と整合し、作用の合成は結合的であること。区間和への加算では集約値に長さも保持する。`n` だけで構築すると全葉が e() なので、長さ 1 の葉が必要なら配列から構築する。

添字は 0-indexed、`0 <= l <= r <= N`。境界探索には `g(e())=true` と区間を伸ばした際の単調性が必要。

現実装の `min_left` は上方へ移動する際の偶奇条件が通常の探索と逆で、誤答・範囲外参照の可能性があるため使用を避ける。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/lazy-segtree.hpp"
struct RangeAddSum {
    struct S { long long sum; int len; };
    using value_type_S = S;
    using value_type_F = long long;
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {0, 0}; }
    static S mapping(long long f, S x) { return {x.sum + f * x.len, x.len}; }
    static long long composition(long long f, long long g) { return f + g; }
    static long long id() { return 0; }
};

int main() {
    LazySegtree<RangeAddSum> seg(vector<RangeAddSum::S>{{1, 1}, {2, 1}, {3, 1}});
    seg.apply(0, 2, 5);
    assert(seg.prod(0, 3).sum == 16);
}
```
