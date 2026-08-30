---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: geometry/cross.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: geometry/dot.hpp
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
  bundledCode: "#line 2 \"geometry/is-convex.hpp\"\n\n#include <vector>\n\n#line 2\
    \ \"geometry/ccw.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\
    \n\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n    // \u5185\u7A4D\
    (dot product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n \
    \   }\n} // namespace geometry\n#line 5 \"geometry/ccw.hpp\"\n\nnamespace geometry\
    \ {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\n    // \u70B9a, b, c\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\u57FA\u6E96\u70B9)\n    inline\
    \ int ccw(const Point &a, Point b, Point c) {\n        b -= a, c -= a;\n     \
    \   // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\u56DE\u308A\u306E\u6642\
    \u3001\n        if(cross(b, c) > EPS) return 1;\n        // \u6642\u8A08\u56DE\
    \u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS) return -1;\n        //\
    \ c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return 2;\n        // a, b,\
    \ c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308B\u5834\u5408\u3001\n        if(std::norm(b) < std::norm(c)) return -2;\n\
    \        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n\
    \        return 0;\n    }\n} // namespace geometry\n#line 6 \"geometry/is-convex.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u591A\u89D2\u5F62\u304B\u3069\u3046\u304B\
    \n    inline bool isConvex(const std::vector<Point> &p) {\n        int n = p.size();\n\
    \        int now, pre, nxt;\n        for(int i = 0; i < n; i++) {\n          \
    \  pre = (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n            now = i;\n\
    \            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n        }\n\
    \        return true;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"ccw.hpp\"\n\nnamespace geometry\
    \ {\n    // \u51F8\u591A\u89D2\u5F62\u304B\u3069\u3046\u304B\n    inline bool\
    \ isConvex(const std::vector<Point> &p) {\n        int n = p.size();\n       \
    \ int now, pre, nxt;\n        for(int i = 0; i < n; i++) {\n            pre =\
    \ (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n            now = i;\n   \
    \         if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n        }\n   \
    \     return true;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  isVerificationFile: false
  path: geometry/is-convex.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-convex.hpp
layout: document
redirect_from:
- /library/geometry/is-convex.hpp
- /library/geometry/is-convex.hpp.html
title: geometry/is-convex.hpp
---
