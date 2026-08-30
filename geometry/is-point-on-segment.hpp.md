---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
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
  bundledCode: "#line 2 \"geometry/is-point-on-segment.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/is-point-on-segment.hpp\"\n\n\
    namespace geometry {\n    // \u70B9c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\u3042\
    \u308B\u304B\n    inline bool isPointOnSegment(const Point &a, const Point &b,\
    \ const Point &c) {\n        // |a-c| + |c-b| <= |a-b| \u306A\u3089\u7DDA\u5206\
    \u4E0A\n        return (std::abs(a - c) + std::abs(c - b) < std::abs(a - b) +\
    \ EPS);\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\u3042\u308B\u304B\n    inline bool isPointOnSegment(const\
    \ Point &a, const Point &b, const Point &c) {\n        // |a-c| + |c-b| <= |a-b|\
    \ \u306A\u3089\u7DDA\u5206\u4E0A\n        return (std::abs(a - c) + std::abs(c\
    \ - b) < std::abs(a - b) + EPS);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/is-point-on-segment.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-point-on-segment.hpp
layout: document
redirect_from:
- /library/geometry/is-point-on-segment.hpp
- /library/geometry/is-point-on-segment.hpp.html
title: geometry/is-point-on-segment.hpp
---
