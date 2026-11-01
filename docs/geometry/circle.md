---
title: 円
documentation_of: //geometry/circle.hpp
---

## このライブラリでできること

`Circle` は、中心 `p` と半径 `r` を持つ円を表す構造体です。円周は $\{x\mid|x-p|=r\}$、円の内部と境界を合わせた領域は $\{x\mid|x-p|\le r\}$ です。交点の関数は円周、包含の関数は内部も含む領域を扱います。

## 使い方

例の `Circle(Point(1,2),3)` は中心 $(1,2)$、半径 $3$ の円を作ります。中心や半径を保持するだけで、この構造体自体が交差判定や面積計算を行うわけではありません。必要な幾何関数へ渡して使います。

```cpp
#include "template/template.cpp"
#include "geometry/circle.hpp"

int main() {
    using namespace geometry;
    Circle c(Point(1, 2), 3);
    assert(equal(c.r, 3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Circle()` | デフォルト構築。r は未初期化。 | O(1) |
| `Circle(p,r)` | 中心・半径を設定。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

半径は非負で指定してください。交点・接線の計算では、さらに正の半径が必要な場合があります。デフォルト構築では半径が初期化されないので、使用前に中心と半径を設定してください。
