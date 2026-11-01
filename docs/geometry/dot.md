---
title: 内積
documentation_of: //geometry/dot.hpp
---

## 概要

2 ベクトルの内積を計算する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `dot(a,b)` | ax*bx+ay*by。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。



## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/dot.hpp"

int main() {
    using namespace geometry;
    assert(equal(dot(Point(1, 2), Point(3, 4)), 11));
}
```
