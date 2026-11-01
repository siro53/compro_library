---
title: 点が直線上にあるか
documentation_of: //geometry/is-point-on-line.hpp
---

## 概要

無限直線 ab 上に c があるかを調べる。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isPointOnLine(a,b,c)` | 直線上なら true。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

a!=b。線分の外側でも同一直線上なら true。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-point-on-line.hpp"

int main() {
    using namespace geometry;
    assert(isPointOnLine(Point(0, 0), Point(1, 0), Point(3, 0)));
}
```
