---
title: 外積
documentation_of: //geometry/cross.hpp
---

## 概要

2 次元ベクトルの外積の z 成分を計算する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `cross(a,b)` | ax*by-ay*bx。正なら a から b が反時計回り。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。



## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/cross.hpp"

int main() {
    using namespace geometry;
    assert(equal(cross(Point(1, 0), Point(0, 1)), 1));
}
```
