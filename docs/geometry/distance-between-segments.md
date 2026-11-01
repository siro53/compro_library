---
title: 線分間の距離
documentation_of: //geometry/distance-between-segments.hpp
---

## このライブラリでできること

`distanceBetweenSegments(s,t)` は、2本の線分にそれぞれ点を選んだときの最短距離を返します。交差や接触があれば0です。交差しない場合は、どちらかの線分の端点と、もう一方の線分との距離の最小値になります。

## 使い方

例の2本の線分は平行で、$y$ 座標が $0$ と $3$ なので距離は $3$ です。端点同士だけで距離を比べると最短距離を見落とす場合があるため、関数内では端点から線分への距離を4通り調べます。

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-segments.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(2, 0));
    Segment t(Point(0, 3), Point(2, 3));
    assert(equal(distanceBetweenSegments(s, t), 3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenSegments(s,t)` | 線分間の非負の最短距離。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

通常の非零長線分を渡してください。内部の交差判定も使用するため、零長の図形や退化した配置を含めて扱いたい場合は別途処理が必要です。端点での接触も距離0として扱います。
