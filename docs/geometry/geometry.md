---
title: 幾何ライブラリ（まとめて include）
documentation_of: //geometry/geometry.hpp
link: https://bakamono1357.hatenablog.com/entry/2020/04/29/025320
---

## このライブラリでできること

`geometry/geometry.hpp` は、幾何ライブラリのすべてのヘッダーをまとめて読み込む入口です。このファイル自体が新しいアルゴリズムを実装しているわけではなく、点・直線・円の型と、交差・距離・多角形などの関数を一括で使えるようにします。

## 使い方

どの機能を使うか決める前や、複数の幾何操作を組み合わせるときは、このヘッダーを include すると便利です。必要な機能だけを使いたい場合は、`geometry/projection.hpp` のように個別のヘッダーを選んでも構いません。

例では点から直線への射影を計算しています。各関数の引数の意味、計算量、零長の図形などの扱いは、それぞれの個別ページを確認してください。

```cpp
#include "template/template.cpp"
#include "geometry/geometry.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    Point foot = projection(l, Point(2, 3));
    assert(equal(foot.imag(), 0));
}
```

## API・計算量

時間・空間計算量は、利用する各関数のページを参照してください。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `geometry.hpp の include` | 型・関数をまとめて宣言する。独自の実行時処理は持たない。 | 各 API のページ参照 |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

同じ図形でも「直線」と「線分」、「円周」と「円の内部」では関数の意味が変わります。名前だけで判断せず、対象と返り値を確認して使ってください。

共通のEPSは絶対誤差の目安であり、すべての判定が同じ距離誤差で定義されているわけではありません。整数座標の厳密な幾何計算を提供するライブラリではなく、浮動小数点の許容誤差を伴う実装です。
