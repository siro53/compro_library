---
title: 交点
documentation_of: //geometry/cross-point.hpp
---

## このライブラリでできること

`crossPoint` は、直線・線分・円の境界が交わる位置を返します。直線同士と線分同士の版は1点、円を含む版は交点の配列を返します。円の交点がない場合は空、接する場合は1点、2点で交わる場合は2点です。

交差の有無を調べる関数とは別であり、特に直線・線分版では入力に前提があります。交点が存在するかを先に判定してから計算する使い方が基本です。

## 使い方

例は原点中心・半径1の円と $x$ 軸の交点を求めており、$(-1,0),(1,0)$ の2点が返ります。返り値の順序を決めたい場合は、呼び出し側で座標などによって並べ替えてください。

直線が一致する場合には、代表として2本目の直線の点 `t.a` を返します。これは「唯一の交点」を求めた結果ではありません。

```cpp
#include "template/template.cpp"
#include "geometry/cross-point.hpp"

int main() {
    using namespace geometry;
    auto ps = crossPoint(Circle(Point(0, 0), 1), Line(Point(-2, 0), Point(2, 0)));
    assert(ps.size() == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `crossPoint(Line s,Line t)` | 直線の交点 1 点。同一直線なら t.a。 | O(1) |
| `crossPoint(Segment s,Segment t)` | 線分を含む直線の交点。 | O(1) |
| `crossPoint(Circle c1,Circle c2)` | 交点を vector<Point> で返す（0,1,2 点）。 | O(1) |
| `crossPoint(Circle c,Line l)` | 円と直線の交点（0,1,2 点）。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線は異なる2点で表し、平行で異なる2直線を直線版へ渡さないでください。線分版は線分を含む直線の交点を計算するだけなので、結果が線分内にあるかは検査しません。重なりの代表点を返すAPIでもありません。

円は正半径とし、同一円は対象外です。接する直前・直後などの退化に近い配置では、判定と平方根計算の丸め誤差に注意してください。
