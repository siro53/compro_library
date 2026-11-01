---
title: Lazy Segment Tree
documentation_of: //data-structure/segtree/lazy-segtree.hpp
---

## このライブラリでできること

`LazySegtree<MonoidAct>` は、区間内の要素をまとめて更新し、その区間の集約値も求めるデータ構造です。たとえば「区間の全要素に5を加える」「区間の和を求める」という操作を、長さ $N$ の配列に対してそれぞれ $O(\log N)$ 時間で処理できます。

更新をすぐに各要素へ配らず、区間を表すノードに保留します。そのノードの中を詳しく調べるときに子へ更新を伝えるため、遅延伝播と呼ばれます。区間の集約値を表す型を $S$、更新を表す型を $F$ とすると、`mapping(f,x)` が更新の適用、`composition(f,g)` が $g$ の後に $f$ を行う合成です。

## 使い方

区間和への加算では、集約値に「和」と「要素数」を持たせます。和を $s$、要素数を $n$ とすると、各要素への $d$ の加算は $(s,n)\mapsto(s+dn,n)$ としてまとめて計算できます。単に和だけを保存すると、加算後の和を求めるための長さが足りません。

例の `RangeAddSum` はこの対応を実装しています。各葉を `{値,1}` として構築し、最初の2要素に $5$ を加えるので、全体の和は $1+2+3+5\times2=16$ になります。

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
    LazySegtree<RangeAddSum> seg(vector<RangeAddSum::S>{ {1, 1}, {2, 1}, {3, 1}});
    seg.apply(0, 2, 5);
    assert(seg.prod(0, 3).sum == 16);
}
```

## API・計算量

必要な空間は $O(N+1)$ です。

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

## 利用条件と実装上の注意

`MonoidAct` には、集約用の `value_type_S,op,e` と、更新用の `value_type_F,mapping,composition,id` を用意します。集約の `op/e` はモノイドの条件を満たす必要があります。また、更新は恒等写像を含み、合成について閉じていて、$f(x\circ y)=f(x)\circ f(y)$ を満たす必要があります。表では、これらの演算とコピーを定数時間としています。

サイズだけを指定すると各葉は `e()` で初期化されます。例のように `e()` の長さが0である場合、実要素を表す長さ1の葉は配列で渡してください。添字・区間の範囲は通常のセグメント木と同じです。

境界探索には、単位元で真となり、区間を伸ばすと真から偽へ一度だけ変化する述語を使います。ただし、現実装の `min_left` には上方移動時の偶奇条件に不備があり、使用を避ける必要があります。

## 参考資料

[ACL の Lazy Segtree ドキュメント](https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html)を、作用の条件と合成順序の参考にしています。
