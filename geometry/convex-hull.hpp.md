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
  bundledCode: "#line 2 \"geometry/convex-hull.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point :\
    \ \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 7 \"geometry/convex-hull.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u5305 O(NlogN)\n    inline std::vector<Point>\
    \ ConvexHull(std::vector<Point> p) {\n        int n = (int)p.size(), k = 0;\n\
    \        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {\n\
    \            return (a.real() != b.real() ? a.real() < b.real()\n            \
    \                             : a.imag() < b.imag());\n        });\n        std::vector<Point>\
    \ ch(2 * n);\n        // \u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\
    \u308B -> (< -EPS)\n        // \u542B\u3081\u7121\u3044 -> (< EPS)\n        for(int\
    \ i = 0; i < n; ch[k++] = p[i++]) { // lower\n            while(k >= 2 &&\n  \
    \                cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n     \
    \           --k;\n        }\n        for(int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) { // upper\n            while(k >= t &&\n                  cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n                --k;\n        }\n\
    \        ch.resize(k - 1);\n        return ch;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"cross.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u5305 O(NlogN)\n    inline std::vector<Point>\
    \ ConvexHull(std::vector<Point> p) {\n        int n = (int)p.size(), k = 0;\n\
    \        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {\n\
    \            return (a.real() != b.real() ? a.real() < b.real()\n            \
    \                             : a.imag() < b.imag());\n        });\n        std::vector<Point>\
    \ ch(2 * n);\n        // \u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\
    \u308B -> (< -EPS)\n        // \u542B\u3081\u7121\u3044 -> (< EPS)\n        for(int\
    \ i = 0; i < n; ch[k++] = p[i++]) { // lower\n            while(k >= 2 &&\n  \
    \                cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n     \
    \           --k;\n        }\n        for(int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = p[i--]) { // upper\n            while(k >= t &&\n                  cross(ch[k\
    \ - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n                --k;\n        }\n\
    \        ch.resize(k - 1);\n        return ch;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/convex-hull.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/convex-hull.hpp
layout: document
redirect_from:
- /library/geometry/convex-hull.hpp
- /library/geometry/convex-hull.hpp.html
title: geometry/convex-hull.hpp
---
