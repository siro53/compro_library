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
    path: geometry/distance-between-segments.hpp
    title: "\u7DDA\u5206\u9593\u306E\u8DDD\u96E2"
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/distance-between-segment-and-point.hpp\"\n\n#line\
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
    \    }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\n\n#line 4 \"geometry/dot.hpp\"\
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
    \ - l.a, p - l.a)) / std::abs(l.b - l.a);\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"cross.hpp\"\n#include \"dot.hpp\"\n#include \"\
    segment.hpp\"\n\nnamespace geometry {\n    // \u7DDA\u5206l\u3068\u70B9p\u306E\
    \u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    // \u5B9A\u7FA9\uFF1A\u70B9p\u304B\u3089\
    \u300C\u7DDA\u5206l\u306E\u3069\u3053\u304B\u300D\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2\n    inline D distanceBetweenSegmentAndPoint(const Segment &l, const Point\
    \ &p) {\n        if(dot(l.b - l.a, p - l.a) < EPS) return std::abs(p - l.a);\n\
    \        if(dot(l.a - l.b, p - l.b) < EPS) return std::abs(p - l.b);\n       \
    \ return std::abs(cross(l.b - l.a, p - l.a)) / std::abs(l.b - l.a);\n    }\n}\
    \ // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/distance-between-segment-and-point.hpp
  requiredBy:
  - geometry/geometry.hpp
  - geometry/distance-between-segments.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/distance-between-segment-and-point.hpp
layout: document
title: "\u7DDA\u5206\u3068\u70B9\u306E\u8DDD\u96E2"
---

## このライブラリでできること

`distanceBetweenSegmentAndPoint(l,p)` は、線分上の点 $q$ のうち $|p-q|$ が最小になる距離を返します。垂線の足が線分の中にあれば直線への距離を使い、外にあれば近い方の端点までの距離を使います。

## 使い方

例では点 $(2,0)$ が線分 $(0,0)$–$(1,0)$ の延長上にあります。直線への距離は0ですが、線分の最近点は端点 $(1,0)$ なので、返り値は $1$ です。

```cpp
#include "template/template.cpp"
#include "geometry/distance-between-segment-and-point.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(1, 0));
    assert(equal(distanceBetweenSegmentAndPoint(s, Point(2, 0)), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `distanceBetweenSegmentAndPoint(l,p)` | 線分上の点までの最短距離。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

この実装では零長線分も端点までの距離として処理されます。垂線の足が端点の内側かを調べる際には内積とEPSを比較しているため、端点付近の分岐は近似的です。
