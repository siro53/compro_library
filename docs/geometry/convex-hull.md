---
title: 凸包
documentation_of: //geometry/convex-hull.hpp
---

## 概要

点集合の凸包を単調鎖法で求める。N は点数。

入力コピー・ソート・結果に O(N) 空間。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ConvexHull(p)` | 凸包の頂点列を反時計回りで返す。 | O(N log N) |

## 前提・注意点

全て `geometry` 名前空間内。座標型は `D=long double`、点は `Point=complex<D>`、許容誤差は `EPS=1e-7`。

辺上の中間点は除く。始点は x,y の辞書順最小、末尾に始点を重ねない。現実装は 0 点で不正な resize、1 点で空列になるため、異なる点を 2 個以上渡す。重複点は事前に除去しておく。

## 使用例

```cpp
#include "template/template.cpp"
#include "geometry/convex-hull.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 1}};
    auto hull = ConvexHull(p);
    assert(hull.size() == 4);
}
```
