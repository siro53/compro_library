---
title: 凸多角形判定
documentation_of: //geometry/is-convex.hpp
---

## 概要

周回する頂点の曲がる向きを調べる。N は頂点数。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isConvex(p)` | 時計回りの曲がりがなければ true。 | O(N) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

反時計回りの単純多角形を渡す。時計回りの凸多角形は false になり得る。一直線上の頂点を許す。自己交差や頂点数不足を検査する関数ではないので N>=3 とする。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/is-convex.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(isConvex(p));
}
```
