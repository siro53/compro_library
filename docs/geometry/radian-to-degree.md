---
title: ラジアンから度
documentation_of: //geometry/radian-to-degree.hpp
---

## このライブラリでできること

`radianToDegree` は、ラジアンの角度を度数法へ変換します。角度 $\theta$ に対して $180\theta/\pi$ を計算します。三角関数などで得た角度を度で表示したい場合に使えます。

## 使い方

例の $\pi$ ラジアンは $180$ 度になります。$2\pi$ を渡せば $360$ が返り、0に正規化されるわけではありません。負の角度も符号を保って変換します。

```cpp
#include "template/template.cpp"
#include "geometry/radian-to-degree.hpp"

int main() {
    using namespace geometry;
    assert(equal(radianToDegree(PI), 180));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `radianToDegree(radian)` | radian*180/PI。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

浮動小数点演算のため、理論上整数の度数になる場合でも小さな誤差が生じ得ます。必要に応じて許容誤差で比較したり、表示時に丸めたりしてください。
