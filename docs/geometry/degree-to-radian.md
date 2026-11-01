---
title: 度からラジアン
documentation_of: //geometry/degree-to-radian.hpp
---

## このライブラリでできること

`degreeToRadian` は、度数法の角度をラジアンへ変換します。$180$ 度が $\pi$ ラジアンなので、角度 $d$ に対して $d\pi/180$ を計算します。三角関数や回転関数へ、度で与えられた角度を渡す前に使えます。

## 使い方

例では $180$ 度を変換して `PI` と比較しています。$90$ 度なら $\pi/2$ です。角度の範囲を一周分へ丸める処理はないので、負の角度や $360$ 度以上の角度もそのまま比例変換します。

```cpp
#include "template/template.cpp"
#include "geometry/degree-to-radian.hpp"

int main() {
    using namespace geometry;
    assert(equal(degreeToRadian(180), PI));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `degreeToRadian(degree)` | degree*PI/180。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

返り値は浮動小数点値なので、厳密な等号で比較せず必要な許容誤差を使ってください。変換後の値を、度を受け取る関数へ再び渡さないよう単位をそろえます。
