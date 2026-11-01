---
title: 加算モノイド
documentation_of: //data-structure/monoid/add.hpp
---

## このライブラリでできること

`MonoidAdd<T>` は区間の和を求めるためのモノイドです。演算は $a+b$、単位元は $0$ なので、左右の区間和を加えるだけで連結した区間の和になります。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では2つの値 $2,3$ を結合して $5$ を得ています。セグメント木に載せる場合は `Segtree<MonoidAdd<long long>>` のように指定すると、点更新と区間和の問い合わせができます。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/add.hpp"

int main() {
    using M = MonoidAdd<long long>;
    auto x = M::op(2, 3);
    assert(x == 5);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l+r を返す。 | O(1) |
| `e()` | 単位元 0 を返す。 | O(1) |

## 利用条件と実装上の注意

`T` は加算と $0$ の構築に対応する型を使ってください。符号付き整数では合計値のオーバーフローを避ける必要があります。浮動小数点の加算は丸めによって厳密には結合的でないため、集約順による誤差を許容する必要があります。
