---
title: 直線
documentation_of: //geometry/line.hpp
---

## 概要

`Line` は直線上の 2 点 a,b で無限直線を表す。向きが必要な関数では a→b の向きを使う。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Line()` | デフォルト構築。使用前に異なる 2 点を設定する。 | O(1) |
| `Line(a,b)` | 2 点から直線を作る。 | O(1) |
| `Line(A,B,C)` | Ax+By=C を表す 2 点を計算。 | O(1) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

2 点は異なること。係数指定では A,B が同時に 0（EPS 内も含む）であってはいけない。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/line.hpp"

int main() {
    using namespace geometry;
    Line l(1, 1, 2);
    assert(equal(l.a.real() + l.a.imag(), 2));
}
```
