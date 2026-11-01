---
title: 多角形への包含判定
documentation_of: //geometry/is-contained.hpp
---

## 概要

点と単純多角形の位置関係を判定する。N は頂点数。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isContained(g,p)` | 内部 2、辺上 1、外部 0。 | O(N) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

頂点は周回順に並べ、末尾に先頭を重ねない。凹多角形も可。境界の外積判定には ==0 を使うため、浮動小数点誤差を持つ点が境界 1 にならない場合がある。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-contained.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(isContained(p, Point(1, 1)) == 2);
}
```
