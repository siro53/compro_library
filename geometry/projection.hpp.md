---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: geometry/dot.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: geometry/convex-cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: geometry/cross-point.hpp
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: geometry/tangent-to-circle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/projection.hpp\"\n\n#line 2 \"geometry/dot.hpp\"\
    \n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\n\
    namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n\
    #line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n    // \u5185\u7A4D(dot\
    \ product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n \
    \   }\n} // namespace geometry\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\
    \n\nnamespace geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\
    \n    struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
    \ a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C)\
    \ {\n            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 2 \"geometry/segment.hpp\"\n\n\
    #line 4 \"geometry/segment.hpp\"\n\nnamespace geometry {\n    // Segment : \u7DDA\
    \u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // Line\u3068\u540C\u3058\n  \
    \  struct Segment : Line {\n        Segment() = default;\n\n        Segment(Point\
    \ a, Point b) : Line(a, b) {}\n        D get_dist() { return std::abs(a - b);\
    \ }\n    };\n} // namespace geometry\n#line 6 \"geometry/projection.hpp\"\n\n\
    namespace geometry {\n    // \u5C04\u5F71(projection)\n    // \u76F4\u7DDA(\u7DDA\
    \u5206)l\u306B\u70B9p\u304B\u3089\u5F15\u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\
    \u6C42\u3081\u308B\n    inline Point projection(const Line &l, const Point &p)\
    \ {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n        return\
    \ l.a + (l.a - l.b) * t;\n    }\n\n    inline Point projection(const Segment &l,\
    \ const Point &p) {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n\
    \        return l.a + (l.a - l.b) * t;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"dot.hpp\"\n#include \"line.hpp\"\n#include \"\
    segment.hpp\"\n\nnamespace geometry {\n    // \u5C04\u5F71(projection)\n    //\
    \ \u76F4\u7DDA(\u7DDA\u5206)l\u306B\u70B9p\u304B\u3089\u5F15\u3044\u305F\u5782\
    \u7DDA\u306E\u8DB3\u3092\u6C42\u3081\u308B\n    inline Point projection(const\
    \ Line &l, const Point &p) {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a\
    \ - l.b);\n        return l.a + (l.a - l.b) * t;\n    }\n\n    inline Point projection(const\
    \ Segment &l, const Point &p) {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a\
    \ - l.b);\n        return l.a + (l.a - l.b) * t;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/dot.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  - geometry/segment.hpp
  isVerificationFile: false
  path: geometry/projection.hpp
  requiredBy:
  - geometry/cross-point.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/reflection.hpp
  - geometry/geometry.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/projection.hpp
layout: document
redirect_from:
- /library/geometry/projection.hpp
- /library/geometry/projection.hpp.html
title: geometry/projection.hpp
---
