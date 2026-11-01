---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: "\u70B9\u304B\u3089\u5186\u3078\u306E\u63A5\u7DDA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/distance-between-line-and-point.hpp\"\n\n#line\
    \ 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n\
    #include <complex>\n\nnamespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\
    \u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n   \
    \ // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\
    \u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point = std::complex<D>;\n\
    \    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool\
    \ equal(const D &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace\
    \ geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry {\n    // \u5916\
    \u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline D cross(const Point\
    \ &a, const Point &b) {\n        return (a.real() * b.imag() - a.imag() * b.real());\n\
    \    }\n} // namespace geometry\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\
    \n\nnamespace geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\
    \n    struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
    \ a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C)\
    \ {\n            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 5 \"geometry/distance-between-line-and-point.hpp\"\
    \n\nnamespace geometry {\n    // \u76F4\u7DDAl\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\n    inline D distanceBetweenLineAndPoint(const Line &l, const\
    \ Point &p) {\n        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b\
    \ - l.a);\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"cross.hpp\"\n#include \"line.hpp\"\n\nnamespace\
    \ geometry {\n    // \u76F4\u7DDAl\u3068\u70B9p\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\n    inline D distanceBetweenLineAndPoint(const Line &l, const Point &p)\
    \ {\n        return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b - l.a);\n\
    \    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/distance-between-line-and-point.hpp
  requiredBy:
  - geometry/tangent-to-circle.hpp
  - geometry/geometry.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/distance-between-line-and-point.hpp
layout: document
title: "\u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\u96E2"
---

## このライブラリでできること

`distanceBetweenLineAndPoint(l,p)` は、点 $p$ から無限直線 $l$ までの最短距離を返します。直線上の点を $a,b$ とすると、距離は $|(b-a)\times(p-a)|/|b-a|$ です。平行四辺形の面積を底辺の長さで割り、高さを求めています。

## 使い方

例の直線は $x$ 軸なので、点 $(2,3)$ までの距離は $3$ です。点の射影が `a,b` の間にあるかは関係なく、直線全体への距離を計算します。

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-line-and-point.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    assert(equal(distanceBetweenLineAndPoint(l, Point(2, 3)), 3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenLineAndPoint(l,p)` | 非負の距離 D。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線は異なる2点で指定してください。2点が一致すると0で割ることになります。線分への距離が欲しい場合は、端点の外側も考慮する `distanceBetweenSegmentAndPoint` を使います。
