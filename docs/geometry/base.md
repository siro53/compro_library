---
title: 幾何の基本型
documentation_of: //geometry/base.hpp
---

## 概要

点・座標型と定数を定義する共通ヘッダー。`Point(x,y)` の real() が x 座標、imag() が y 座標。`PI` は円周率。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `equal(a,b)` | abs(a-b)<EPS かを返す（絶対誤差）。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

Point の加減算でベクトル演算、abs で長さ、norm で長さの二乗を得る。定数 EPS は座標の尺度に自動適応しない。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/base.hpp"

int main() {
    using namespace geometry;
    Point p(3, 4);
    assert(equal(abs(p), 5));
}
```
