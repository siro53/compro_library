---
title: 点から円への接線
documentation_of: //geometry/tangent-to-circle.hpp
---

## このライブラリでできること

`tangentToCircle(p,c)` は、円の外部の点 $p$ から円へ引いた2本の接線について、その接点を返します。返り値は直線ではなく `vector<Point>` です。各接点と $p$ を結べば接線になります。

接点 $t$ では半径と接線が直交するので、$\lvert p-t\rvert=\sqrt{\lvert p-c.p\rvert^2-c.r^2}$ です。この長さを半径とする補助円と元の円の交点を使って、接点を求めます。

## 使い方

例では原点中心・半径1の円に、外部の点 $(3,0)$ から接線を引いています。上下に1つずつ、合計2つの接点が得られます。必要なら各点 `t` について `Line(p,t)` を作ってください。

```cpp
#include "template/template.cpp"
#include "geometry/tangent-to-circle.hpp"

int main() {
    using namespace geometry;
    auto ps = tangentToCircle(Point(3, 0), Circle(Point(0, 0), 1));
    assert(ps.size() == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `tangentToCircle(p,c)` | 接点の vector<Point>。通常は 2 点。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

円は正半径とし、点は円の厳密な外側に置いてください。内部の点では平方根の中が負になります。円周上の点も退化ケースになるため、別処理を推奨します。外側でも境界に非常に近い場合は丸め誤差に注意が必要です。
