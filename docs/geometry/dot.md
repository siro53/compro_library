---
title: 内積
documentation_of: //geometry/dot.hpp
---

## このライブラリでできること

`dot(a,b)` は2つのベクトルの内積 $a_xb_x+a_yb_y$ を返します。長さと角度を使うと $a\cdot b=|a||b|\cos\theta$ と表せるので、向きの近さや直交を調べるために使えます。

非零ベクトル同士なら、内積が正のときはなす角が鋭角、0なら直角、負なら鈍角です。射影や、点からの垂線の足が線分内にあるかの判定にも使います。

## 使い方

例の $(1,2)$ と $(3,4)$ の内積は $1\cdot3+2\cdot4=11$ です。2点間の方向を調べたい場合は、点そのものではなく `b-a` のような差を渡してください。

```cpp
#include "template/template.cpp"
#include "geometry/dot.hpp"

int main() {
    using namespace geometry;
    assert(equal(dot(Point(1, 2), Point(3, 4)), 11));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `dot(a,b)` | ax*bx+ay*by。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

関数は内積をそのまま計算し、0への丸めは行いません。直交判定では `equal(dot(a,b),0)` などの許容誤差を使う必要がありますが、内積の値はベクトルの長さにも依存するため、同じEPSでも角度としての許容幅は一定ではありません。
