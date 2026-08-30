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
  bundledCode: "#line 2 \"geometry/rotate.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point :\
    \ \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/rotate.hpp\"\n\nnamespace geometry\
    \ {\n    // \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Btheta\u5EA6\u56DE\
    \u8EE2\n    // theta\u306F\u30E9\u30B8\u30A2\u30F3\uFF01\uFF01\uFF01\n    inline\
    \ Point rotate(const Point &p, const D &theta) {\n        return Point(std::cos(theta)\
    \ * p.real() - std::sin(theta) * p.imag(),\n                     std::sin(theta)\
    \ * p.real() + std::cos(theta) * p.imag());\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Btheta\u5EA6\u56DE\u8EE2\n    // theta\u306F\
    \u30E9\u30B8\u30A2\u30F3\uFF01\uFF01\uFF01\n    inline Point rotate(const Point\
    \ &p, const D &theta) {\n        return Point(std::cos(theta) * p.real() - std::sin(theta)\
    \ * p.imag(),\n                     std::sin(theta) * p.real() + std::cos(theta)\
    \ * p.imag());\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/rotate.hpp
  requiredBy:
  - geometry/tangent.hpp
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/rotate.hpp
layout: document
redirect_from:
- /library/geometry/rotate.hpp
- /library/geometry/rotate.hpp.html
title: geometry/rotate.hpp
---
