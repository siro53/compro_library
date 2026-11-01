---
title: 単位ベクトル
documentation_of: //geometry/unit-vector.hpp
---

## 概要

向きを保って長さを 1 にする。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `unitVector(a)` | a/abs(a)。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

零ベクトルは不可。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/unit-vector.hpp"

int main() {
    using namespace geometry;
    assert(equal(abs(unitVector(Point(3, 4))), 1));
}
```
