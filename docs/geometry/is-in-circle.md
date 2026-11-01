---
title: 円への包含判定
documentation_of: //geometry/is-in-circle.hpp
---

## このライブラリでできること

`isInCircle(c,p)` は、点 $p$ が円の内部または円周上にあるかを判定します。数学的な条件は、中心を $c.p$、半径を $r$ として $|p-c.p|\le r$ です。円周だけを調べる関数ではありません。

## 使い方

例の点 $(1,0)$ は、原点中心・半径2の円の内部にあるため真になります。内部と境界を区別して返すAPIではないので、境界だけを扱う場合は中心距離と半径を別途比較してください。

```cpp
#include "template/template.cpp"
#include "geometry/is-in-circle.hpp"

int main() {
    using namespace geometry;
    Circle c(Point(0, 0), 2);
    assert(isInCircle(c, Point(1, 0)));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isInCircle(c,p)` | 内部・境界なら true。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

半径は非負としてください。実装は中心距離と半径の差にEPSを用いるため、円の外側にわずかにはみ出た点も境界相当として真になる場合があります。境界の数値的な意味は厳密な集合包含とは異なります。
