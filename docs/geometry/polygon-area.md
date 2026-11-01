---
title: 多角形の符号付き面積
documentation_of: //geometry/polygon-area.hpp
---

## このライブラリでできること

`PolygonArea(p)` は、周回順に並んだ多角形の符号付き面積を返します。頂点を $p_0,\ldots,p_{N-1}$ とすると、$\frac12\sum_{i=0}^{N-1}(p_i\times p_{(i+1)\bmod N})$ を計算します。これは靴紐公式です。

反時計回りなら正、時計回りなら負になります。通常の面積だけが必要なら、返り値の絶対値を取ってください。

## 使い方

例の一辺2の正方形は反時計回りに並んでいるので、面積は $4$ です。頂点の順序を逆にすると $-4$ になります。点集合を適当に並べただけでは、その集合の凸包の面積にはならないことに注意してください。

```cpp
#include "template/template.cpp"
#include "geometry/polygon-area.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(equal(PolygonArea(p), 4));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PolygonArea(p)` | 反時計回りなら正、時計回りなら負の面積。 | O(N) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

入力は非空にしてください。空配列では末尾の頂点へのアクセスが範囲外になります。単純多角形では通常の符号付き面積ですが、自己交差する点列では重なりの符号を含む代数的面積になります。
