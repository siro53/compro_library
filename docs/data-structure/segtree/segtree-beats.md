---
title: Segment Tree Beats
documentation_of: //data-structure/segtree/segtree-beats.hpp
---

## 概要

`SegtreeBeats<MonoidAct>` は集約値だけでは作用を適用できない場合に子へ降りる汎用の区間更新木。`N` は長さ、`V` はその操作中に失敗処理で追加訪問するノード数。

空間 O(N+1)。各演算は O(1) と仮定。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegtreeBeats(), SegtreeBeats(n), SegtreeBeats(v)` | 空、n 個の e()、列 v から構築。 | O(N+1) |
| `set(pos, val)` | 点を上書き。 | O(log N + V) |
| `get(pos)` | 遅延作用を反映した点の値。 | O(log N + V) |
| `prod(l, r)` | [l,r) の積。 | O(log N + V) |
| `all_prod()` | 全体の積。 | O(1) |
| `apply(pos, f)` | 点に作用 f を適用。 | O(log N + V) |
| `apply(l, r, f)` | [l,r) に作用 f を適用。 | O(log N + V) |
| `max_right(l, g)` | g(prod(l,r)) が true となる最大 r。 | O(log N + V) |
| `min_left(r, g)` | g(prod(l,r)) が true となる最小 l。 | O(log N + V) |

## 前提・注意点

`MonoidAct` に `value_type_S`（集約値）、`value_type_F`（作用）、`op/e`（集約の演算・単位元）、`mapping(f,x)`（作用の適用）、`composition(f,g)`（g の後に f を適用）、`id()`（恒等作用）を定義する。`mapping` は区間の結合と整合し、作用の合成は結合的であること。区間和への加算では集約値に長さも保持する。`n` だけで構築すると全葉が e() なので、長さ 1 の葉が必要なら配列から構築する。

添字は 0-indexed、`0 <= l <= r <= N`。境界探索には `g(e())=true` と区間を伸ばした際の単調性が必要。

集約型 S に `bool fail` が必要。`mapping` が集約値だけで更新できない場合は fail=true を返す。葉では必ず成功させ、`op/e` も正しい fail 状態を返す。失敗時にも元の作用は子へ伝播できるようにする。汎用クラスだけでは高速な償却計算量は保証されず、作用ごとの証明が必要。失敗が多い 1 操作は O(N) になり得る。

現実装は `max_right` の外側ループに `l++` がなく、`min_left` の上方移動の偶奇条件にも不備がある。これらの境界探索は使用を避ける。例は必ず mapping が成功する区間加算。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/segtree-beats.hpp"
struct RangeAddSum {
    struct S { long long sum; int len; bool fail = false; };
    using value_type_S = S;
    using value_type_F = long long;
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {0, 0}; }
    static S mapping(long long f, S x) { return {x.sum + f * x.len, x.len}; }
    static long long composition(long long f, long long g) { return f + g; }
    static long long id() { return 0; }
};

int main() {
    SegtreeBeats<RangeAddSum> seg(vector<RangeAddSum::S>{{1, 1}, {2, 1}, {3, 1}});
    seg.apply(0, 2, 5);
    assert(seg.prod(0, 3).sum == 16);
}
```
