---
title: ビット ORモノイド
documentation_of: //data-structure/monoid/or.hpp
---

## このライブラリでできること

`MonoidOR<T>` は、区間内に現れる bit をまとめるモノイドです。演算は bit ごとの OR、単位元は $0$ です。各要素を属性の集合を表す bit マスクとみなすと、集約は集合の和に対応します。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例の $1$ は下位の bit、$2$ は次の bit だけが立っています。それらを OR すると両方の bit が立った $3$ になります。区間内のいずれかの要素が持つ属性をまとめたい場合に使えます。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/or.hpp"

int main() {
    using M = MonoidOR<unsigned int>;
    assert(M::op(1, 2) == 3);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l &#124; r を返す。 | O(1) |
| `e()` | 単位元 0 を返す。 | O(1) |

## 利用条件と実装上の注意

`T` は bit 演算を行える整数型を使ってください。マスクとして扱う場合は、符号なし整数にすると最上位 bit の意味が明確になります。
