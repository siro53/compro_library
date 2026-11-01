---
title: 点が線分上にあるか
documentation_of: //geometry/is-point-on-segment.hpp
---

## 概要

距離の和を用いて線分上の点を判定する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isPointOnSegment(a,b,c)` | abs(a-c)+abs(c-b)<abs(a-b)+EPS。端点を含む。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

EPS 以内の距離差を許容する。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-point-on-segment.hpp"

int main() {
    using namespace geometry;
    assert(isPointOnSegment(Point(0, 0), Point(2, 0), Point(1, 0)));
}
```
