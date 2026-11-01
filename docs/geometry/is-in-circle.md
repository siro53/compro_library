---
title: 円への包含判定
documentation_of: //geometry/is-in-circle.hpp
---

## 概要

点が円の内部または円周上にあるかを調べる。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isInCircle(c,p)` | 内部・境界なら true。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

半径は非負。境界は EPS による許容誤差を含む。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-in-circle.hpp"

int main() {
    using namespace geometry;
    Circle c(Point(0, 0), 2);
    assert(isInCircle(c, Point(1, 0)));
}
```
