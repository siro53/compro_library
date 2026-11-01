---
title: 射影
documentation_of: //geometry/projection.hpp
---

## このライブラリでできること

`projection(l,p)` は、点 $p$ から直線 $l$ に下ろした垂線の足を返します。直線の方向を $d=b-a$ とすると、足は $a+d\,((p-a)\cdot d)/(d\cdot d)$ です。点を直線方向と垂直方向に分解する際に使えます。

## 使い方

例では水平な直線に点 $(1,3)$ を射影するので、足は $(1,0)$ になります。`Line` と `Segment` の両方を受け取れますが、Segment版も同じ無限直線への射影を行います。

```cpp
#include "template/template.cpp"
#include "geometry/projection.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(2, 0));
    Point q = projection(l, Point(1, 3));
    assert(equal(q.real(), 1) && equal(q.imag(), 0));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `projection(Line l,p)` | 無限直線 l への射影。 | O(1) |
| `projection(Segment l,p)` | 線分を含む無限直線への射影。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

2端点は異なる点にしてください。零方向では分母が0になります。Segment版の結果は線分の外に出ることがあり、端点へ切り詰める処理はありません。線分上の最近点を求めたい場合は、射影位置が端点の間にあるかも判定する必要があります。
