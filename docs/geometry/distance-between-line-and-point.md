---
title: 直線と点の距離
documentation_of: //geometry/distance-between-line-and-point.hpp
---

## 概要

点と無限直線の最短距離を求める。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenLineAndPoint(l,p)` | 非負の距離 D。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

l.a!=l.b。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-line-and-point.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    assert(equal(distanceBetweenLineAndPoint(l, Point(2, 3)), 3));
}
```
