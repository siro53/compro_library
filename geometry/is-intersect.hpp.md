---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: "3 \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: "\u5186"
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segments.hpp
    title: "\u7DDA\u5206\u9593\u306E\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: "\u70B9\u304B\u3089\u5186\u3078\u306E\u63A5\u7DDA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry-api.test.cpp
    title: test/mytest/geometry/geometry-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is-intersect.hpp\"\n\n#line 2 \"geometry/ccw.hpp\"\
    \n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n#include\
    \ <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point : \u8907\u7D20\
    \u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\
    \u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\
    \u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point =\
    \ std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\
    \n\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n    // \u5185\u7A4D\
    (dot product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n \
    \   }\n} // namespace geometry\n#line 5 \"geometry/ccw.hpp\"\n\nnamespace geometry\
    \ {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\n    // \u70B9a, b, c\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\u57FA\u6E96\u70B9)\n    inline\
    \ int ccw(const Point &a, Point b, Point c) {\n        b -= a, c -= a;\n     \
    \   // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\u56DE\u308A\u306E\u6642\
    \u3001\n        if(cross(b, c) > EPS) return 1;\n        // \u6642\u8A08\u56DE\
    \u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS) return -1;\n        //\
    \ c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return 2;\n        // a, b,\
    \ c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308B\u5834\u5408\u3001\n        if(std::norm(b) < std::norm(c)) return -2;\n\
    \        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n\
    \        return 0;\n    }\n} // namespace geometry\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 4 \"geometry/circle.hpp\"\n\nnamespace geometry {\n    // Circle : \u5186\
    \u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle {\n     \
    \   Point p;\n        D r;\n\n        Circle() = default;\n\n        Circle(Point\
    \ p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\nnamespace\
    \ geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n\
    \    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n \
    \   struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
    \ a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C)\
    \ {\n            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 4 \"geometry/segment.hpp\"\n\n\
    namespace geometry {\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n        Segment()\
    \ = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n        D get_dist()\
    \ { return std::abs(a - b); }\n    };\n} // namespace geometry\n#line 6 \"geometry/is-intersect.hpp\"\
    \n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068\u7DDA\u5206t\u304C\u4EA4\u5DEE\
    \u3057\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    // bound:\u7DDA\u5206\u306E\
    \u7AEF\u70B9\u3092\u542B\u3080\u304B\n    inline bool isIntersect(const Segment\
    \ &s, const Segment &t, bool bound) {\n        return ccw(s.a, s.b, t.a) * ccw(s.a,\
    \ s.b, t.b) < bound &&\n               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b)\
    \ < bound;\n    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\n\
    \    // \u8FD4\u308A\u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n    inline\
    \ int isIntersect(const Circle &c1, const Circle &c2) {\n        D d = std::abs(c1.p\
    \ - c2.p);\n        // 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\
    \u5834\u5408\n        if(d > c1.r + c2.r + EPS) return 4;\n        // \u5916\u63A5\
    \u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, c1.r + c2.r)) return\
    \ 3;\n        // \u5185\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d,\
    \ std::abs(c1.r - c2.r))) return 1;\n        // \u5185\u5305\u3057\u3066\u3044\
    \u308B\u5834\u5408\n        if(d < std::abs(c1.r - c2.r) - EPS) return 0;\n  \
    \      return 2;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"ccw.hpp\"\n#include \"circle.hpp\"\n#include \"\
    segment.hpp\"\n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068\u7DDA\u5206\
    t\u304C\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    // bound:\u7DDA\
    \u5206\u306E\u7AEF\u70B9\u3092\u542B\u3080\u304B\n    inline bool isIntersect(const\
    \ Segment &s, const Segment &t, bool bound) {\n        return ccw(s.a, s.b, t.a)\
    \ * ccw(s.a, s.b, t.b) < bound &&\n               ccw(t.a, t.b, s.a) * ccw(t.a,\
    \ t.b, s.b) < bound;\n    }\n\n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\
    \u5B9A\n    // \u8FD4\u308A\u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n\
    \    inline int isIntersect(const Circle &c1, const Circle &c2) {\n        D d\
    \ = std::abs(c1.p - c2.p);\n        // 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\
    \u3044\u308B\u5834\u5408\n        if(d > c1.r + c2.r + EPS) return 4;\n      \
    \  // \u5916\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, c1.r\
    \ + c2.r)) return 3;\n        // \u5185\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\
    \n        if(equal(d, std::abs(c1.r - c2.r))) return 1;\n        // \u5185\u5305\
    \u3057\u3066\u3044\u308B\u5834\u5408\n        if(d < std::abs(c1.r - c2.r) - EPS)\
    \ return 0;\n        return 2;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  - geometry/circle.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/is-intersect.hpp
  requiredBy:
  - geometry/geometry.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-intersect.hpp
layout: document
title: "\u4EA4\u5DEE\u5224\u5B9A"
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
