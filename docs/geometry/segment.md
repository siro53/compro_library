---
title: 線分
documentation_of: //geometry/segment.hpp
---

## 概要

`Segment` は Line を継承し、端点 a,b の間の線分を表す。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Segment(), Segment(a,b)` | デフォルトまたは端点指定で構築。 | O(1) |
| `get_dist()` | 線分の長さ。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

端点は公開メンバ。Line への変換はこの線分を含む無限直線として扱う。零長線分を受け付けるかは各関数の前提に従う。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/segment.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(3, 4));
    assert(equal(s.get_dist(), 5));
}
```
