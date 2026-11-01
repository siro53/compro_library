---
title: 法線ベクトル
documentation_of: //geometry/normal-vector.hpp
---

## このライブラリでできること

`normalVector(a)` は、ベクトル $a=(x,y)$ を90度反時計回りに回した $(-y,x)$ を返します。元のベクトルに垂直で長さが等しいため、直線の法線方向を求めるのに使えます。

## 使い方

例では $(2,0)$ が $(0,2)$ になります。直線 `l` の左側へ向く法線なら `normalVector(l.b-l.a)` とします。長さ1の法線が必要な場合は、非零ベクトルであることを確認してから単位ベクトルへ正規化してください。

```cpp
#include "template/template.cpp"
#include "geometry/normal-vector.hpp"

int main() {
    using namespace geometry;
    Point n = normalVector(Point(2, 0));
    assert(equal(n.real(), 0) && equal(n.imag(), 2));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `normalVector(a)` | a に垂直で同じ長さのベクトル。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

名前にnormalとありますが、長さを1にする関数ではありません。零ベクトルを渡すと零ベクトルが返り、その場合は特定の法線方向を表しません。
