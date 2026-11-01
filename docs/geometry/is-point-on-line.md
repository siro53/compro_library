---
title: 点が直線上にあるか
documentation_of: //geometry/is-point-on-line.hpp
---

## このライブラリでできること

`isPointOnLine(a,b,c)` は、点 $c$ が2点 $a,b$ を通る無限直線上にあるかを調べます。ベクトル $b-a$ と $c-a$ の外積が0に近いことを、平行判定によって確認します。

## 使い方

例の $(3,0)$ は、$(0,0)$ と $(1,0)$ の間にはありませんが、同じ水平直線上にあるので真を返します。端点の間にあることも必要なら、`isPointOnSegment` を使ってください。

```cpp
#include "template/template.cpp"
#include "geometry/is-point-on-line.hpp"

int main() {
    using namespace geometry;
    assert(isPointOnLine(Point(0, 0), Point(1, 0), Point(3, 0)));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isPointOnLine(a,b,c)` | 直線上なら true。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

$a,b$ は異なる点にしてください。判定にはEPSを使いますが、点と直線の距離を直接EPSと比較しているわけではありません。方向ベクトルの長さによって、同じ距離の点でも判定が変わり得ます。
