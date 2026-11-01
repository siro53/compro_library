---
title: 直線の直交判定
documentation_of: //geometry/is-orthogonal.hpp
---

## 概要

方向ベクトルの内積が 0 に近いかを調べる。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isOrthogonal(a,b)` | 2 直線が直交するか。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

両直線は異なる 2 点で表す。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-orthogonal.hpp"

int main() {
    using namespace geometry;
    Line a(Point(0, 0), Point(1, 0));
    Line b(Point(0, 0), Point(0, 1));
    assert(isOrthogonal(a, b));
}
```
