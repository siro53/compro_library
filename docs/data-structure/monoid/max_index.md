---
title: 添字付き最大値モノイド
documentation_of: //data-structure/monoid/max_index.hpp
---

## このライブラリでできること

`MonoidMaxWithIndex<T,MINUS_INF>` は、区間の最大値とその位置を同時に集約します。集約値は `(値,添字)` の pair で、辞書順に大きい方を選びます。値が同じなら添字が大きい方が残ります。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

葉には `{a[i],i}` を入れます。例では値が同じ $4$ なので添字 $5$ が選ばれます。最小値版とは同値時の選び方が逆で、「最大値を達成する最後の位置」を返すことに注意してください。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/max_index.hpp"

int main() {
    using M = MonoidMaxWithIndex<int>;
    auto x = M::op({4, 2}, {4, 5});
    assert(x.second == 5);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | pair の辞書順最大 を返す。 | O(1) |
| `e()` | 単位元 (MINUS_INF,-1) を返す。 | O(1) |

## 利用条件と実装上の注意

単位元は `(MINUS_INF,-1)` です。値は `MINUS_INF` 以上、添字は非負としてください。この条件なら、実データの値が `MINUS_INF` と等しくても実データ側が選ばれます。
