---
title: 多角形の符号付き面積
documentation_of: //geometry/polygon-area.hpp
---

## 概要

外積の和（靴紐公式）で面積を計算する。N は頂点数。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PolygonArea(p)` | 反時計回りなら正、時計回りなら負の面積。 | O(N) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

入力は非空で周回順。幾何的な面積が必要なら abs を取る。自己交差の場合は符号付きの代数的面積になる。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/polygon-area.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(equal(PolygonArea(p), 4));
}
```
