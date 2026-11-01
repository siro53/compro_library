---
title: 法線ベクトル
documentation_of: //geometry/normal-vector.hpp
---

## 概要

ベクトルを 90 度反時計回りに回転する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `normalVector(a)` | a に垂直で同じ長さのベクトル。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

単位ベクトルには正規化しない。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/normal-vector.hpp"

int main() {
    using namespace geometry;
    Point n = normalVector(Point(2, 0));
    assert(equal(n.real(), 0) && equal(n.imag(), 2));
}
```
