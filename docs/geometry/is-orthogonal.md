---
title: 直線の直交判定
documentation_of: //geometry/is-orthogonal.hpp
---

## このライブラリでできること

`isOrthogonal(a,b)` は、2直線の方向ベクトルの内積を使って直交を判定します。非零ベクトル $u,v$ に対し、直交の条件は $u\cdot v=0$ です。実装では内積がEPS未満で0に近いかを調べます。

## 使い方

例では水平方向と垂直方向の直線を渡しているため、真を返します。直線上のどの2点で表しても数学的には同じ直交関係ですが、数値計算では方向ベクトルの尺度にも注意が必要です。

```cpp
#include "template/template.cpp"
#include "geometry/is-orthogonal.hpp"

int main() {
    using namespace geometry;
    Line a(Point(0, 0), Point(1, 0));
    Line b(Point(0, 0), Point(0, 1));
    assert(isOrthogonal(a, b));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isOrthogonal(a,b)` | 2 直線が直交するか。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線の2点は異なる点にしてください。零方向ベクトルの内積は常に0なので、その場合の返り値には直交という幾何的な意味がありません。また、判定は角度そのものの誤差ではなく、内積の絶対誤差に基づきます。
