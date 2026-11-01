---
title: 線分と点の距離
documentation_of: //geometry/distance-between-segment-and-point.hpp
---

## このライブラリでできること

`distanceBetweenSegmentAndPoint(l,p)` は、線分上の点 $q$ のうち $\lvert p-q\rvert$ が最小になる距離を返します。垂線の足が線分の中にあれば直線への距離を使い、外にあれば近い方の端点までの距離を使います。

## 使い方

例では点 $(2,0)$ が線分 $(0,0)$–$(1,0)$ の延長上にあります。直線への距離は0ですが、線分の最近点は端点 $(1,0)$ なので、返り値は $1$ です。

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-segment-and-point.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(1, 0));
    assert(equal(distanceBetweenSegmentAndPoint(s, Point(2, 0)), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenSegmentAndPoint(l,p)` | 線分上の点までの最短距離。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

この実装では零長線分も端点までの距離として処理されます。垂線の足が端点の内側かを調べる際には内積とEPSを比較しているため、端点付近の分岐は近似的です。
