---
title: 点・ベクトルの回転
documentation_of: //geometry/rotate.hpp
---

## 概要

原点を中心に点を回転する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `rotate(p,theta)` | theta ラジアンだけ反時計回りに回転した Point。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

角度は度ではなくラジアン。点 c の周りなら `c+rotate(p-c,theta)`。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/rotate.hpp"

int main() {
    using namespace geometry;
    Point q = rotate(Point(1, 0), PI / 2);
    assert(equal(q.real(), 0) && equal(q.imag(), 1));
}
```
