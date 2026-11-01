---
title: 線分間の距離
documentation_of: //geometry/distance-between-segments.hpp
---

## 概要

交差するなら 0、しなければ各端点と他方の線分の距離の最小値を返す。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenSegments(s,t)` | 線分間の非負の最短距離。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

通常の非零長線分で使う。端点の接触も距離 0。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-segments.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(2, 0));
    Segment t(Point(0, 3), Point(2, 3));
    assert(equal(distanceBetweenSegments(s, t), 3));
}
```
