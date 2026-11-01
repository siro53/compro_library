---
title: 交差判定
documentation_of: //geometry/is-intersect.hpp
---

## このライブラリでできること

`isIntersect` は、線分同士と円同士で意味が異なるオーバーロードを持ちます。線分版は交差するかのbool、円版は2円の位置関係を0から4の整数で返します。

相異なる正半径の2円では、その整数は共通接線の本数にも対応します。離れていれば4、外接なら3、2点で交差すれば2、内接なら1、一方が他方の内部に完全に入れば0です。

## 使い方

線分版の `bound=true` は端点の接触や同一直線上の重なりを含めます。例の対角線2本は内点で交差するため真です。円の例は半径1の中心が距離3だけ離れているため、返り値は4になります。

円版の返り値をそのままboolとして「交点がある」と解釈しないでください。返り値4は交点がない場合です。

```cpp
#include "template/template.cpp"
#include "geometry/is-intersect.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(2, 2));
    Segment t(Point(0, 2), Point(2, 0));
    assert(isIntersect(s, t, true));
    assert(isIntersect(Circle(Point(0, 0), 1), Circle(Point(3, 0), 1)) == 4);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isIntersect(s,t,bound)` | 線分同士の交差判定。bound=true は端点・重なりを含む。 | O(1) |
| `isIntersect(c1,c2)` | 円の位置関係を 0..4 で返す。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

線分は非零長を前提にしてください。`bound=false` は交差判定の積が厳密に負の場合だけを認めるので、端点での接触だけでなく同一直線上の重なりも除外します。

同一円には無限本の共通接線があり、この0から4の分類の意味を適用できません。円は正半径の相異なる円を対象とします。円の接触は中心距離と半径の和・差をEPSで比較する近似判定です。
