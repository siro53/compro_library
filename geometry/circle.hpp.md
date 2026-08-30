---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: geometry/convex-cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: geometry/cross-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segments.hpp
    title: geometry/distance-between-segments.hpp
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: geometry/is-in-circle.hpp
    title: geometry/is-in-circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: geometry/is-intersect.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: geometry/tangent-to-circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: geometry/tangent.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point :\
    \ \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/circle.hpp\"\n\nnamespace geometry\
    \ {\n    // Circle : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\
    \u4E2D\u5FC3\u306E\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\
    \n    struct Circle {\n        Point p;\n        D r;\n\n        Circle() = default;\n\
    \n        Circle(Point p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // Circle\
    \ : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\
    \u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle\
    \ {\n        Point p;\n        D r;\n\n        Circle() = default;\n\n       \
    \ Circle(Point p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/circle.hpp
  requiredBy:
  - geometry/is-in-circle.hpp
  - geometry/cross-point.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/tangent.hpp
  - geometry/is-intersect.hpp
  - geometry/distance-between-segments.hpp
  - geometry/geometry.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/circle.hpp
layout: document
redirect_from:
- /library/geometry/circle.hpp
- /library/geometry/circle.hpp.html
title: geometry/circle.hpp
---
