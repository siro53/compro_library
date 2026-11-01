---
title: 直線と点の距離
documentation_of: //geometry/distance-between-line-and-point.hpp
---

## このライブラリでできること

`distanceBetweenLineAndPoint(l,p)` は、点 $p$ から無限直線 $l$ までの最短距離を返します。直線上の点を $a,b$ とすると、距離は $|(b-a)\times(p-a)|/|b-a|$ です。平行四辺形の面積を底辺の長さで割り、高さを求めています。

## 使い方

例の直線は $x$ 軸なので、点 $(2,3)$ までの距離は $3$ です。点の射影が `a,b` の間にあるかは関係なく、直線全体への距離を計算します。

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-line-and-point.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    assert(equal(distanceBetweenLineAndPoint(l, Point(2, 3)), 3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenLineAndPoint(l,p)` | 非負の距離 D。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線は異なる2点で指定してください。2点が一致すると0で割ることになります。線分への距離が欲しい場合は、端点の外側も考慮する `distanceBetweenSegmentAndPoint` を使います。
