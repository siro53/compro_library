---
title: 交差判定
documentation_of: //geometry/is-intersect.hpp
---

## 概要

線分の交差と、2 円の位置関係を判定するオーバーロード。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isIntersect(s,t,bound)` | 線分同士の交差判定。bound=true は端点・重なりを含む。 | O(1) |
| `isIntersect(c1,c2)` | 円の位置関係を 0..4 で返す。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

円の返り値は、4=離れている、3=外接、2=2 点で交差、1=内接、0=一方が他方の内部。相異なる通常の円では共通接線数と一致するが、同一円にはこの意味を適用できない。線分は非零長を前提とする。bound=false は交差積が厳密に負の場合のみで、同一直線上の重なりも除く。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-intersect.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(2, 2));
    Segment t(Point(0, 2), Point(2, 0));
    assert(isIntersect(s, t, true));
    assert(isIntersect(Circle(Point(0, 0), 1), Circle(Point(3, 0), 1)) == 4);
}
```
