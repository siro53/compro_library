---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is-in-circle.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\n\
    namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n\
    #line 4 \"geometry/circle.hpp\"\n\nnamespace geometry {\n    // Circle : \u5186\
    \u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle {\n     \
    \   Point p;\n        D r;\n\n        Circle() = default;\n\n        Circle(Point\
    \ p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n#line 4 \"geometry/is-in-circle.hpp\"\
    \n\nnamespace geometry {\n    // \u70B9p\u304C\u5186c\u306E\u5185\u90E8(\u5186\
    \u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\n    inline bool isInCircle(const Circle &c, const Point &p) {\n\
    \        D d = std::abs(c.p - p);\n        return (equal(d, c.r) || d < c.r -\
    \ EPS);\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"circle.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    p\u304C\u5186c\u306E\u5185\u90E8(\u5186\u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    inline bool isInCircle(const\
    \ Circle &c, const Point &p) {\n        D d = std::abs(c.p - p);\n        return\
    \ (equal(d, c.r) || d < c.r - EPS);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/circle.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/is-in-circle.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-in-circle.hpp
layout: document
redirect_from:
- /library/geometry/is-in-circle.hpp
- /library/geometry/is-in-circle.hpp.html
title: geometry/is-in-circle.hpp
---
