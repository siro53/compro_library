---
title: 交点
documentation_of: //geometry/cross-point.hpp
---

## 概要

直線・線分・円の交点を計算する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `crossPoint(Line s,Line t)` | 直線の交点 1 点。同一直線なら t.a。 | O(1) |
| `crossPoint(Segment s,Segment t)` | 線分を含む直線の交点。 | O(1) |
| `crossPoint(Circle c1,Circle c2)` | 交点を vector<Point> で返す（0,1,2 点）。 | O(1) |
| `crossPoint(Circle c,Line l)` | 円と直線の交点（0,1,2 点）。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

直線は非零方向。平行で異なる 2 直線は不可。線分版は線分内の交差を検査しないので、事前に交差確認する。円は正半径とし、同一円の無限個の交点には対応しない。返り値の順序には依存せず、必要なら呼び出し側でソートする。接する付近では浮動小数点誤差に注意。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/cross-point.hpp"

int main() {
    using namespace geometry;
    auto ps = crossPoint(Circle(Point(0, 0), 1), Line(Point(-2, 0), Point(2, 0)));
    assert(ps.size() == 2);
}
```
