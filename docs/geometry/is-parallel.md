---
title: 直線の平行判定
documentation_of: //geometry/is-parallel.hpp
---

## このライブラリでできること

`isParallel(a,b)` は、2直線の方向ベクトルが平行かを調べます。方向ベクトル $u,v$ が平行である条件は $u_xv_y-u_yv_x=0$ です。実装では外積がEPS未満で0に近いかを判定します。

## 使い方

例の直線はどちらも方向ベクトル $(1,1)$ を持つため、平行と判定されます。同一直線も平行として真を返します。「交点がないか」を判定する関数とは異なります。

```cpp
#include "template/template.cpp"
#include "geometry/is-parallel.hpp"

int main() {
    using namespace geometry;
    Line a(Point(0, 0), Point(1, 1));
    Line b(Point(0, 1), Point(1, 2));
    assert(isParallel(a, b));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isParallel(a,b)` | 2 直線が平行か（同一直線も true）。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

それぞれの直線は異なる2点で指定してください。零方向ベクトルでは外積が常に0になり、有効な平行判定になりません。外積の絶対値で比較するため、判定の許容角度は方向ベクトルの長さにも依存します。
