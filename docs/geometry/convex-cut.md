---
title: 凸多角形の切断
documentation_of: //geometry/convex-cut.hpp
---

## 概要

有向直線 l.a→l.b の左側に残る凸多角形を求める。N は頂点数。

入力コピー・返り値 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ConvexCut(p,l)` | 左側（境界込み）の頂点列。全て外なら空。 | O(N) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

反時計回りの凸多角形と非零方向の直線を使う。現実装は ccw の ±2（一直線上の前後）も交差判定の積に使うため、切断直線と辺が同一直線になる退化ケースでは不要な交点を挿入し得る。境界上の頂点や共線辺を含む結果は必要に応じて重複除去する。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/convex-cut.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    auto cut = ConvexCut(p, Line(Point(1, -1), Point(1, 3)));
    assert(cut.size() == 4);
}
```
