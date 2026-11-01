---
title: 円
documentation_of: //geometry/circle.hpp
---

## 概要

`Circle` は中心 p と半径 r を持つ構造体。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Circle()` | デフォルト構築。r は未初期化。 | O(1) |
| `Circle(p,r)` | 中心・半径を設定。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

半径は非負とする。交点・接線の関数は通常、正の半径を前提とする。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/circle.hpp"

int main() {
    using namespace geometry;
    Circle c(Point(1, 2), 3);
    assert(equal(c.r, 3));
}
```
