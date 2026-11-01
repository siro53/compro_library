---
title: 射影
documentation_of: //geometry/projection.hpp
---

## 概要

点から直線に下ろした垂線の足を求める。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `projection(Line l,p)` | 無限直線 l への射影。 | O(1) |
| `projection(Segment l,p)` | 線分を含む無限直線への射影。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

l.a!=l.b。Segment 版も端点へ丸めないので、返る点は線分外に出ることがある。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/projection.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(2, 0));
    Point q = projection(l, Point(1, 3));
    assert(equal(q.real(), 1) && equal(q.imag(), 0));
}
```
