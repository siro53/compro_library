---
title: ラジアンから度
documentation_of: //geometry/radian-to-degree.hpp
---

## 概要

弧度法の角度を度数法へ変換する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `radianToDegree(radian)` | radian*180/PI。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。



## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/radian-to-degree.hpp"

int main() {
    using namespace geometry;
    assert(equal(radianToDegree(PI), 180));
}
```
