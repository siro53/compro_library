---
title: 2 円の共通接線
documentation_of: //geometry/tangent.hpp
---

## このライブラリでできること

`tangent(a,b)` は、2つの円の両方に接する直線を列挙します。通常の相異なる円では、離れていると4本、外接で3本、2点で交差すると2本、内接で1本、一方が他方の内部に入ると0本です。

返り値は `vector<Line>` で、中心を結ぶ方向とその法線方向から各接線を構成します。接点ではなく直線を返す点が、`tangentToCircle` との違いです。

## 使い方

例の円はどちらも半径1で、中心間距離が4なので、共通接線が4本あります。必要な向きや順序で処理したい場合は、返された直線を呼び出し側で整理してください。

```cpp
#include "template/template.cpp"
#include "geometry/tangent.hpp"

int main() {
    using namespace geometry;
    auto lines = tangent(Circle(Point(0, 0), 1), Circle(Point(4, 0), 1));
    assert(lines.size() == 4);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `tangent(a,b)` | vector<Line>。位置関係に応じ 0..4 本。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

半径は正とし、同一円は通常の列挙対象から除いてください。同一円には無限本の接線がありますが、この実装は中心がEPS内で一致する場合に空の配列を返します。接する付近の判定はEPSを使うため、非常に近い退化配置では本数や座標に数値誤差の影響があります。
