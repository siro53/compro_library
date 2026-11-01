---
title: 点から円への接線
documentation_of: //geometry/tangent-to-circle.hpp
---

## 概要

円の外部の点 p から引ける接線の接点を返す。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `tangentToCircle(p,c)` | 接点の vector<Point>。通常は 2 点。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

円は正半径、p は円の外側に置く。円内では平方根が不正になる。円周上は退化ケースなので別処理を推奨。返り値は Line ではなく接点であり、p と各接点を結ぶと接線になる。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/tangent-to-circle.hpp"

int main() {
    using namespace geometry;
    auto ps = tangentToCircle(Point(3, 0), Circle(Point(0, 0), 1));
    assert(ps.size() == 2);
}
```
