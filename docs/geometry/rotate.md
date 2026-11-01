---
title: 点・ベクトルの回転
documentation_of: //geometry/rotate.hpp
---

## このライブラリでできること

`rotate(p,theta)` は、原点を中心に点 $p$ を反時計回りへ $\theta$ ラジアン回転します。ベクトルの向きを変える操作としても使え、理論上は長さを保ちます。

座標 $(x,y)$ は $(x\cos\theta-y\sin\theta,\ x\sin\theta+y\cos\theta)$ に移ります。

## 使い方

例では $(1,0)$ を $\pi/2$ ラジアン、すなわち90度回転して $(0,1)$ に移しています。原点以外の点 $c$ の周りに回転したい場合は、`c+rotate(p-c,theta)` として一度中心を原点へ移してください。

```cpp
#include "template/template.cpp"
#include "geometry/rotate.hpp"

int main() {
    using namespace geometry;
    Point q = rotate(Point(1, 0), PI / 2);
    assert(equal(q.real(), 0) && equal(q.imag(), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `rotate(p,theta)` | theta ラジアンだけ反時計回りに回転した Point。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

角度の単位は度ではなくラジアンです。負の角度なら時計回りの回転になります。計算には三角関数を使うため、座標や長さには浮動小数点の誤差が入ります。
