---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: geometry/convex-cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex-hull.hpp
    title: geometry/convex-hull.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: geometry/cross-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: geometry/cross.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/degree-to-radian.hpp
    title: geometry/degree-to-radian.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-line-and-point.hpp
    title: geometry/distance-between-line-and-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segment-and-point.hpp
    title: geometry/distance-between-segment-and-point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segments.hpp
    title: geometry/distance-between-segments.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: geometry/dot.hpp
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: geometry/is-contained.hpp
    title: geometry/is-contained.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-convex.hpp
    title: geometry/is-convex.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-in-circle.hpp
    title: geometry/is-in-circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: geometry/is-intersect.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-orthogonal.hpp
    title: geometry/is-orthogonal.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-parallel.hpp
    title: geometry/is-parallel.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-line.hpp
    title: geometry/is-point-on-line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-segment.hpp
    title: geometry/is-point-on-segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/normal-vector.hpp
    title: geometry/normal-vector.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon-area.hpp
    title: geometry/polygon-area.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/radian-to-degree.hpp
    title: geometry/radian-to-degree.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/rotate.hpp
    title: geometry/rotate.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: geometry/tangent-to-circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: geometry/tangent.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/unit-vector.hpp
    title: geometry/unit-vector.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\
    \nnamespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <cmath>\n#include <complex>\n\nnamespace geometry\
    \ {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\
    \u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\
    \u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long\
    \ double;\n    using Point = std::complex<D>;\n    const D EPS = 1e-7;\n    const\
    \ D PI = std::acos(D(-1));\n\n    inline bool equal(const D &a, const D &b) {\
    \ return std::fabs(a - b) < EPS; }\n} // namespace geometry\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/base.hpp
  requiredBy:
  - geometry/is-point-on-segment.hpp
  - geometry/is-in-circle.hpp
  - geometry/normal-vector.hpp
  - geometry/cross.hpp
  - geometry/cross-point.hpp
  - geometry/dot.hpp
  - geometry/degree-to-radian.hpp
  - geometry/is-contained.hpp
  - geometry/polygon-area.hpp
  - geometry/projection.hpp
  - geometry/segment.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/ccw.hpp
  - geometry/tangent.hpp
  - geometry/is-orthogonal.hpp
  - geometry/is-parallel.hpp
  - geometry/reflection.hpp
  - geometry/unit-vector.hpp
  - geometry/is-intersect.hpp
  - geometry/radian-to-degree.hpp
  - geometry/circle.hpp
  - geometry/rotate.hpp
  - geometry/convex-hull.hpp
  - geometry/is-point-on-line.hpp
  - geometry/distance-between-segments.hpp
  - geometry/geometry.hpp
  - geometry/distance-between-line-and-point.hpp
  - geometry/is-convex.hpp
  - geometry/convex-cut.hpp
  - geometry/line.hpp
  - geometry/distance-between-segment-and-point.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/base.hpp
layout: document
redirect_from:
- /library/geometry/base.hpp
- /library/geometry/base.hpp.html
title: geometry/base.hpp
---
