---
title: Segment Tree
documentation_of: //data-structure/segtree/segtree.hpp
---

## このライブラリでできること

`Segtree<Monoid>` は、配列の要素を更新しながら区間の集約値を求めるデータ構造です。和・最小値・最大値だけでなく、関数の合成などにも同じ実装を使えます。配列長を $N$ とすると、点更新と区間の集約は $O(\log N)$ 時間です。

扱う演算を $\circ$、単位元を $e$ とします。必要なのは結合律 $(a\circ b)\circ c=a\circ(b\circ c)$ と、単位元の条件 $e\circ a=a\circ e=a$ です。この組をモノイドと呼びます。演算の順番を交換できる必要はなく、`prod(l,r)` は $A_l\circ A_{l+1}\circ\cdots\circ A_{r-1}$ の順序を保ちます。

## 使い方

集約したい演算を `value_type`、`op(l,r)`、`e()` を持つ型にまとめ、それをテンプレート引数として渡します。和なら既存の `MonoidAdd<T>` を使えます。例では $[1,2,3]$ の2番目を $5$ に上書きするため、全体の和は $9$ です。

`max_right(l,f)` は、区間を右へ伸ばしたときに条件 `f` を満たせる境界を探します。例の非負の配列では「和が6以下」は単調な条件なので、$[0,2)$ までは条件を満たし、$[0,3)$ では満たさないことを1回の探索で調べられます。

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

## API・計算量

必要な空間は $O(N+1)$ です。

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

## 利用条件と実装上の注意

添字は0始まり、区間は $0\le l\le r\le N$ の半開区間です。空区間の集約値は `e()` です。`set(p,x)` は代入、`apply(p,x)` は $A_p\leftarrow\operatorname{op}(A_p,x)$ なので、両者を使い分けてください。

境界探索では `f(e())` が真であること、同じ値に対して毎回同じ判定を返すことが必要です。「最大の右端」「最小の左端」と解釈するには、区間を伸ばしたときに真から偽へ一度しか変化しないという単調性も必要です。

表の計算量は `op/e` と値のコピーを定数時間としたものです。文字列そのものの連結など、演算に長さに比例する時間がかかる場合は、そのコストも含めて評価してください。

## 参考資料

[ACL の Segtree ドキュメント](https://atcoder.github.io/ac-library/production/document_ja/segtree.html)に、モノイドと境界探索の条件が整理されています。このライブラリでは演算と型を `Monoid` 構造体にまとめて指定します。

設計の参考: [代数的構造を乗せるデータ構造の設計について](https://noshi91.hatenablog.com/entry/2020/04/22/212649)。
