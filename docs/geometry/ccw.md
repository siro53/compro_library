---
title: 3 点の位置関係
documentation_of: //geometry/ccw.hpp
---

## 概要

a を基準に b,c の回転方向と一直線上の位置関係を分類する。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ccw(a,b,c)` | 反時計回り 1、時計回り -1、c-a-b の順 2、a-b-c の順 -2、c が線分 ab 上なら 0。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

a!=b とする。回転判定は EPS を使うが、同一直線上の前後判定は dot と norm の厳密比較を使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/ccw.hpp"

int main() {
    using namespace geometry;
    assert(ccw(Point(0, 0), Point(1, 0), Point(0, 1)) == 1);
    assert(ccw(Point(0, 0), Point(2, 0), Point(1, 0)) == 0);
}
```
