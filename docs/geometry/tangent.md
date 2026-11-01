---
title: 2 円の共通接線
documentation_of: //geometry/tangent.hpp
---

## 概要

相異なる 2 円の共通接線を列挙する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `tangent(a,b)` | vector<Line>。位置関係に応じ 0..4 本。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

円は正半径。同心円は空を返す。同一円の無限本の接線を表すことはできない。出力順は保証しない。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/tangent.hpp"

int main() {
    using namespace geometry;
    auto lines = tangent(Circle(Point(0, 0), 1), Circle(Point(4, 0), 1));
    assert(lines.size() == 4);
}
```
