---
title: 最小公倍数モノイド
documentation_of: //data-structure/monoid/lcm.hpp
---

## このライブラリでできること

`MonoidLCM<T>` は区間内の非負整数の最小公倍数を集約します。$\operatorname{lcm}(a,1)=a$ なので単位元は $1$ です。周期が異なる複数の事象について、共通の周期を求める場面などで使えます。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では $4$ と $6$ の最小公倍数 $12$ を求めています。区間を結合する際は、その左右の最小公倍数をもう一度 lcm に渡せばよいため、セグメント木の集約として利用できます。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/lcm.hpp"

int main() {
    using M = MonoidLCM<long long>;
    assert(M::op(4, 6) == 12);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | lcm(l,r) を返す。 | O(log M)、M=max(abs(l),abs(r))+1 |
| `e()` | 単位元 1 を返す。 | O(1) |

## 利用条件と実装上の注意

非負整数を扱い、結果が `T` に収まることを確認してください。最小公倍数は入力より急速に大きくなり得ます。表の $M$ は2入力の絶対値の最大値+1です。lcm は gcd の計算を含むため $O(\log M)$ 時間であり、一般の整数演算と同じ定数時間とは限りません。
