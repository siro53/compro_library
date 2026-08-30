---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: geometry/cross.hpp
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
  bundledCode: "#line 2 \"geometry/polygon-area.hpp\"\n\n#include <vector>\n\n#line\
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
    \    }\n} // namespace geometry\n#line 6 \"geometry/polygon-area.hpp\"\n\nnamespace\
    \ geometry {\n    // \u591A\u89D2\u5F62\u306E\u9762\u7A4D\u3092\u6C42\u3081\u308B\
    \n    inline D PolygonArea(const std::vector<Point> &p) {\n        D res = 0;\n\
    \        int n = p.size();\n        for(int i = 0; i < n - 1; i++) res += cross(p[i],\
    \ p[i + 1]);\n        res += cross(p[n - 1], p[0]);\n        return res * 0.5;\n\
    \    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"cross.hpp\"\n\nnamespace\
    \ geometry {\n    // \u591A\u89D2\u5F62\u306E\u9762\u7A4D\u3092\u6C42\u3081\u308B\
    \n    inline D PolygonArea(const std::vector<Point> &p) {\n        D res = 0;\n\
    \        int n = p.size();\n        for(int i = 0; i < n - 1; i++) res += cross(p[i],\
    \ p[i + 1]);\n        res += cross(p[n - 1], p[0]);\n        return res * 0.5;\n\
    \    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/polygon-area.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/polygon-area.hpp
layout: document
redirect_from:
- /library/geometry/polygon-area.hpp
- /library/geometry/polygon-area.hpp.html
title: geometry/polygon-area.hpp
---
