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
    path: geometry/distance-between-segment-and-point.hpp
    title: "\u7DDA\u5206\u3068\u70B9\u306E\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
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
  bundledCode: "#line 2 \"geometry/distance-between-segments.hpp\"\n\n#include <algorithm>\n\
    \n#line 2 \"geometry/distance-between-segment-and-point.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\
    \n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\n\
    namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n\
    #line 4 \"geometry/cross.hpp\"\n\nnamespace geometry {\n    // \u5916\u7A4D(cross\
    \ product) : a\xD7b = |a||b|sin\u0398\n    inline D cross(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.imag() - a.imag() * b.real());\n \
    \   }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\n\n#line 4 \"geometry/dot.hpp\"\
    \n\nnamespace geometry {\n    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\
    \n    inline D dot(const Point &a, const Point &b) {\n        return (a.real()\
    \ * b.real() + a.imag() * b.imag());\n    }\n} // namespace geometry\n#line 2\
    \ \"geometry/segment.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\
    \n\nnamespace geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\
    \n    struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
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
    \ { return std::abs(a - b); }\n    };\n} // namespace geometry\n#line 6 \"geometry/distance-between-segment-and-point.hpp\"\
    \n\nnamespace geometry {\n    // \u7DDA\u5206l\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\n    // \u5B9A\u7FA9\uFF1A\u70B9p\u304B\u3089\u300C\u7DDA\u5206\
    l\u306E\u3069\u3053\u304B\u300D\u3078\u306E\u6700\u77ED\u8DDD\u96E2\n    inline\
    \ D distanceBetweenSegmentAndPoint(const Segment &l, const Point &p) {\n     \
    \   if(dot(l.b - l.a, p - l.a) < EPS) return std::abs(p - l.a);\n        if(dot(l.a\
    \ - l.b, p - l.b) < EPS) return std::abs(p - l.b);\n        return std::abs(cross(l.b\
    \ - l.a, p - l.a)) / std::abs(l.b - l.a);\n    }\n} // namespace geometry\n#line\
    \ 2 \"geometry/is-intersect.hpp\"\n\n#line 2 \"geometry/ccw.hpp\"\n\n#line 5 \"\
    geometry/ccw.hpp\"\n\nnamespace geometry {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\
    \u5411\n    // \u70B9a, b, c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066\
    (a\u304C\u57FA\u6E96\u70B9)\n    inline int ccw(const Point &a, Point b, Point\
    \ c) {\n        b -= a, c -= a;\n        // \u70B9a, b, c \u304C\n        // \u53CD\
    \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c) > EPS) return\
    \ 1;\n        // \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b,\
    \ c) < -EPS) return -1;\n        // c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\
    \u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u6642\u3001\n        if(dot(b,\
    \ c) < 0) return 2;\n        // a, b, c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\
    \u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n        if(std::norm(b)\
    \ < std::norm(c)) return -2;\n        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\
    \u308B\u5834\u5408\u3001\n        return 0;\n    }\n} // namespace geometry\n\
    #line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\n\nnamespace\
    \ geometry {\n    // Circle : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n   \
    \ // p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\
    \u534A\u5F84\n    struct Circle {\n        Point p;\n        D r;\n\n        Circle()\
    \ = default;\n\n        Circle(Point p, D r) : p(p), r(r) {}\n    };\n} // namespace\
    \ geometry\n#line 6 \"geometry/is-intersect.hpp\"\n\nnamespace geometry {\n  \
    \  // \u7DDA\u5206s\u3068\u7DDA\u5206t\u304C\u4EA4\u5DEE\u3057\u3066\u3044\u308B\
    \u304B\u3069\u3046\u304B\n    // bound:\u7DDA\u5206\u306E\u7AEF\u70B9\u3092\u542B\
    \u3080\u304B\n    inline bool isIntersect(const Segment &s, const Segment &t,\
    \ bool bound) {\n        return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) < bound\
    \ &&\n               ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) < bound;\n    }\n\
    \n    // 2\u3064\u306E\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\n    // \u8FD4\u308A\
    \u5024\u306F\u5171\u901A\u63A5\u7DDA\u306E\u6570\n    inline int isIntersect(const\
    \ Circle &c1, const Circle &c2) {\n        D d = std::abs(c1.p - c2.p);\n    \
    \    // 2\u3064\u306E\u5186\u304C\u96E2\u308C\u3066\u3044\u308B\u5834\u5408\n\
    \        if(d > c1.r + c2.r + EPS) return 4;\n        // \u5916\u63A5\u3057\u3066\
    \u3044\u308B\u5834\u5408\n        if(equal(d, c1.r + c2.r)) return 3;\n      \
    \  // \u5185\u63A5\u3057\u3066\u3044\u308B\u5834\u5408\n        if(equal(d, std::abs(c1.r\
    \ - c2.r))) return 1;\n        // \u5185\u5305\u3057\u3066\u3044\u308B\u5834\u5408\
    \n        if(d < std::abs(c1.r - c2.r) - EPS) return 0;\n        return 2;\n \
    \   }\n} // namespace geometry\n#line 7 \"geometry/distance-between-segments.hpp\"\
    \n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068t\u306E\u8DDD\u96E2\n    inline\
    \ D distanceBetweenSegments(const Segment &s, const Segment &t) {\n        if(isIntersect(s,\
    \ t, 1)) return (D)(0);\n        D ans = distanceBetweenSegmentAndPoint(s, t.a);\n\
    \        ans = std::min(ans, distanceBetweenSegmentAndPoint(s, t.b));\n      \
    \  ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.a));\n        ans =\
    \ std::min(ans, distanceBetweenSegmentAndPoint(t, s.b));\n        return ans;\n\
    \    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <algorithm>\n\n#include \"distance-between-segment-and-point.hpp\"\
    \n#include \"is-intersect.hpp\"\n\nnamespace geometry {\n    // \u7DDA\u5206s\u3068\
    t\u306E\u8DDD\u96E2\n    inline D distanceBetweenSegments(const Segment &s, const\
    \ Segment &t) {\n        if(isIntersect(s, t, 1)) return (D)(0);\n        D ans\
    \ = distanceBetweenSegmentAndPoint(s, t.a);\n        ans = std::min(ans, distanceBetweenSegmentAndPoint(s,\
    \ t.b));\n        ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.a));\n\
    \        ans = std::min(ans, distanceBetweenSegmentAndPoint(t, s.b));\n      \
    \  return ans;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/distance-between-segment-and-point.hpp
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/is-intersect.hpp
  - geometry/ccw.hpp
  - geometry/circle.hpp
  isVerificationFile: false
  path: geometry/distance-between-segments.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
  - test/mytest/geometry/geometry-api.test.cpp
documentation_of: geometry/distance-between-segments.hpp
layout: document
title: "\u7DDA\u5206\u9593\u306E\u8DDD\u96E2"
---

## このライブラリでできること

`distanceBetweenSegments(s,t)` は、2本の線分にそれぞれ点を選んだときの最短距離を返します。交差や接触があれば0です。交差しない場合は、どちらかの線分の端点と、もう一方の線分との距離の最小値になります。

## 使い方

例の2本の線分は平行で、$y$ 座標が $0$ と $3$ なので距離は $3$ です。端点同士だけで距離を比べると最短距離を見落とす場合があるため、関数内では端点から線分への距離を4通り調べます。

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-segments.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(2, 0));
    Segment t(Point(0, 3), Point(2, 3));
    assert(equal(distanceBetweenSegments(s, t), 3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenSegments(s,t)` | 線分間の非負の最短距離。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

通常の非零長線分を渡してください。内部の交差判定も使用するため、零長の図形や退化した配置を含めて扱いたい場合は別途処理が必要です。端点での接触も距離0として扱います。
