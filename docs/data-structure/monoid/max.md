---
title: 最大値モノイド
documentation_of: //data-structure/monoid/max.hpp
---

## このライブラリでできること

`MonoidMax<T,MINUS_INF>` は区間の最大値を求めるモノイドです。単位元には、すべての値以下の `MINUS_INF` を使い、空区間が最大値の選択に影響しないようにします。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では $4,6$ の大きい方である $6$ を返します。最小値用のモノイドと同じ要領で、`Segtree<MonoidMax<int>>` に載せられます。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/max.hpp"

int main() {
    using M = MonoidMax<int>;
    assert(M::op(4, 6) == 6);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | max(l,r) を返す。 | O(1) |
| `e()` | 単位元 MINUS_INF を返す。 | O(1) |

## 利用条件と実装上の注意

`MINUS_INF` の既定値は `numeric_limits<T>::min()` です。これは整数型では最小値ですが、浮動小数点型の最も小さい負数を表すものではありません。また、このテンプレートはC++17では浮動小数点型を非型引数に使えないため、整数型を対象にしてください。
