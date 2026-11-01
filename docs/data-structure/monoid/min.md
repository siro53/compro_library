---
title: 最小値モノイド
documentation_of: //data-structure/monoid/min.hpp
---

## このライブラリでできること

`MonoidMin<T,INF>` は区間の最小値を求めるモノイドです。左右の最小値の小さい方を取れば、連結した区間の最小値になります。単位元には、すべての値以上の `INF` を使います。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では $4,6$ の小さい方である $4$ を返します。`Segtree<MonoidMin<int>>` とすれば、各要素の更新と区間最小値の取得ができます。未設定の葉は `INF` になるため、最小値の候補には影響しません。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/min.hpp"

int main() {
    using M = MonoidMin<int>;
    assert(M::op(4, 6) == 4);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | min(l,r) を返す。 | O(1) |
| `e()` | 単位元 INF を返す。 | O(1) |

## 利用条件と実装上の注意

`INF` の既定値は `numeric_limits<T>::max()` です。独自の値を指定する場合も、すべての実データ以上になるようにしてください。C++17ではこの非型テンプレート引数に浮動小数点型を使えないため、整数型で利用します。
