---
title: 点が線分上にあるか
documentation_of: //geometry/is-point-on-segment.hpp
---

## このライブラリでできること

`isPointOnSegment(a,b,c)` は、点 $c$ が端点を含む線分 $ab$ 上にあるかを調べます。数学的には、三角不等式が等号になる条件 $|a-c|+|c-b|=|a-b|$ を利用しています。

## 使い方

例では $(1,0)$ が $(0,0)$ と $(2,0)$ の間にあるため真を返します。同じ直線上でも端点の外側にある点は、2つの距離の和が線分長より大きくなるので偽になります。

```cpp
#include "template/template.cpp"
#include "geometry/is-point-on-segment.hpp"

int main() {
    using namespace geometry;
    assert(isPointOnSegment(Point(0, 0), Point(2, 0), Point(1, 0)));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isPointOnSegment(a,b,c)` | abs(a-c)+abs(c-b)<abs(a-b)+EPS。端点を含む。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

実装は等号の代わりに $|a-c|+|c-b|<|a-b|+\mathrm{EPS}$ を用います。これは距離の和の差に対する許容誤差であり、点から線分への距離がEPS以下かを判定するものではありません。
