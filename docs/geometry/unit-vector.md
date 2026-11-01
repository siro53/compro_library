---
title: 単位ベクトル
documentation_of: //geometry/unit-vector.hpp
---

## このライブラリでできること

`unitVector(a)` は、非零ベクトルの向きを保ちながら長さを1にします。式では $a/|a|$ です。向きだけを使って点を一定距離だけ動かしたい場合などに使えます。

## 使い方

例の $(3,4)$ は長さ $5$ なので、結果は $(3/5,4/5)$ となり、その長さは1です。点 $p$ から方向 $a$ に距離 $d$ 進む点は `p+unitVector(a)*d` と表せます。

```cpp
#include "template/template.cpp"
#include "geometry/unit-vector.hpp"

int main() {
    using namespace geometry;
    assert(equal(abs(unitVector(Point(3, 4))), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `unitVector(a)` | a/abs(a)。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

零ベクトルは長さで割れないため渡せません。非常に短いベクトルを正規化すると、元の座標誤差が方向の大きな誤差になる場合もあります。入力が有効な方向を表していることを確認してください。
