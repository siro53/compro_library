---
title: 線分
documentation_of: //geometry/segment.hpp
---

## このライブラリでできること

`Segment` は、端点 `a,b` の間の線分を表します。数学的には $\{a+t(b-a)\mid0\le t\le1\}$ です。`Line` を継承して同じ端点を持ちますが、距離や交差判定では端点の外へ伸びない図形として扱います。

## 使い方

2端点を渡して構築し、`get_dist()` で長さを取得します。例では $(0,0)$ と $(3,4)$ の距離が $5$ であることを確認しています。`a,b` は公開メンバなので、端点の参照にも使えます。

```cpp
#include "template/template.cpp"
#include "geometry/segment.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(3, 4));
    assert(equal(s.get_dist(), 5));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Segment(), Segment(a,b)` | デフォルトまたは端点指定で構築。 | O(1) |
| `get_dist()` | 線分の長さ。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

`Line` に変換すると、この線分を含む無限直線として扱われます。関数によって線分版の意味が異なる場合があり、たとえば `projection(Segment,Point)` は線分内への丸めを行いません。

2端点が等しい零長線分を受け付けるかどうかは、利用する各関数の説明に従ってください。
