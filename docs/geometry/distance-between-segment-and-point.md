---
title: 線分と点の距離
documentation_of: //geometry/distance-between-segment-and-point.hpp
---

## 概要

垂線の足が線分外なら近い端点までの距離を使う。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenSegmentAndPoint(l,p)` | 線分上の点までの最短距離。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

零長線分は端点までの距離になる。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-segment-and-point.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(1, 0));
    assert(equal(distanceBetweenSegmentAndPoint(s, Point(2, 0)), 1));
}
```
