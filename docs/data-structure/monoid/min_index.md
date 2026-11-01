---
title: 添字付き最小値モノイド
documentation_of: //data-structure/monoid/min_index.hpp
---

## このライブラリでできること

`MonoidMinWithIndex<T,INF>` は、区間の最小値とその位置を一緒に取得するためのモノイドです。集約値は `(値,添字)` の pair で、辞書順に小さい方を選びます。値が同じなら添字が小さい方が残ります。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

葉には `{a[i],i}` を入れます。例では値が同じ $4$ なので、添字 $2$ と $5$ のうち $2$ が選ばれます。「最小値を達成する最初の位置」が必要な場合に適しています。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/min_index.hpp"

int main() {
    using M = MonoidMinWithIndex<int>;
    auto x = M::op({4, 2}, {4, 5});
    assert(x.second == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | pair の辞書順最小 を返す。 | O(1) |
| `e()` | 単位元 (INF,-1) を返す。 | O(1) |

## 利用条件と実装上の注意

単位元は `(INF,-1)` です。実データの値は `INF` より厳密に小さくしてください。実データも `INF` だと、添字 $-1$ の単位元が先に選ばれてしまいます。添字は通常の0始まりの非負整数を使います。
