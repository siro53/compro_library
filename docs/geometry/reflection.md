---
title: 直線に対する反射
documentation_of: //geometry/reflection.hpp
---

## このライブラリでできること

`reflection(l,p)` は、直線 $l$ を鏡として点 $p$ を反対側へ移した点を返します。垂線の足を $h$ とすると、反射後の点は $2h-p$ です。鏡面反射や、対称な位置への変換に使えます。

## 使い方

例では $x$ 軸を表す直線に対して $(2,3)$ を反射するので、結果は $(2,-3)$ になります。直線上の点を渡した場合、数学的には元と同じ点が返ります。

```cpp
#include "template/template.cpp"
#include "geometry/reflection.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    Point q = reflection(l, Point(2, 3));
    assert(equal(q.real(), 2) && equal(q.imag(), -3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `reflection(l,p)` | l に関して p と線対称な点。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線は異なる2点で表してください。内部で射影を計算するため、零長の方向ベクトルは使えません。浮動小数点演算なので、対称な点を再び反射しても元の座標とbit単位で一致するとは限りません。
