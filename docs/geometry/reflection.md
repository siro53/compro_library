---
title: 直線に対する反射
documentation_of: //geometry/reflection.hpp
---

## 概要

直線を対称軸に点を反転する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `reflection(l,p)` | l に関して p と線対称な点。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

l.a!=l.b。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/reflection.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    Point q = reflection(l, Point(2, 3));
    assert(equal(q.real(), 2) && equal(q.imag(), -3));
}
```
