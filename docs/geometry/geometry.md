---
title: 幾何ライブラリ（まとめて include）
documentation_of: //geometry/geometry.hpp
link: https://bakamono1357.hatenablog.com/entry/2020/04/29/025320
---

## 概要

全幾何ヘッダーを include する互換ヘッダー。個別利用では必要なヘッダーだけを include してよい。

実行時間・空間は各関数の説明を参照。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `geometry.hpp の include` | 型・関数をまとめて宣言する。独自の実行時処理は持たない。 | 各 API のページ参照 |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

主な入口は [基本型](https://github.com/siro53/compro_library/blob/main/docs/geometry/base.md)、[直線](https://github.com/siro53/compro_library/blob/main/docs/geometry/line.md)、[線分](https://github.com/siro53/compro_library/blob/main/docs/geometry/segment.md)、[円](https://github.com/siro53/compro_library/blob/main/docs/geometry/circle.md)。交差は [交差判定](https://github.com/siro53/compro_library/blob/main/docs/geometry/is-intersect.md) と [交点](https://github.com/siro53/compro_library/blob/main/docs/geometry/cross-point.md)、多角形は [凸包](https://github.com/siro53/compro_library/blob/main/docs/geometry/convex-hull.md) と [面積](https://github.com/siro53/compro_library/blob/main/docs/geometry/polygon-area.md) を参照。

## 使用例

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
