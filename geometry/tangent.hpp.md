---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/rotate.hpp
    title: geometry/rotate.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/unit-vector.hpp
    title: geometry/unit-vector.hpp
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
  bundledCode: "#line 2 \"geometry/tangent.hpp\"\n\n#include <cmath>\n#include <vector>\n\
    \n#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n#line 4\
    \ \"geometry/base.hpp\"\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/circle.hpp\"\n\nnamespace geometry\
    \ {\n    // Circle : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\
    \u4E2D\u5FC3\u306E\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\
    \n    struct Circle {\n        Point p;\n        D r;\n\n        Circle() = default;\n\
    \n        Circle(Point p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n\
    #line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\nnamespace geometry\
    \ {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // b\
    \ - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n    struct\
    \ Line {\n        Point a, b;\n        Line() = default;\n        Line(Point a,\
    \ Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C) {\n\
    \            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 2 \"geometry/rotate.hpp\"\n\n\
    #line 4 \"geometry/rotate.hpp\"\n\nnamespace geometry {\n    // \u70B9p\u3092\u53CD\
    \u6642\u8A08\u56DE\u308A\u306Btheta\u5EA6\u56DE\u8EE2\n    // theta\u306F\u30E9\
    \u30B8\u30A2\u30F3\uFF01\uFF01\uFF01\n    inline Point rotate(const Point &p,\
    \ const D &theta) {\n        return Point(std::cos(theta) * p.real() - std::sin(theta)\
    \ * p.imag(),\n                     std::sin(theta) * p.real() + std::cos(theta)\
    \ * p.imag());\n    }\n} // namespace geometry\n#line 2 \"geometry/unit-vector.hpp\"\
    \n\n#line 4 \"geometry/unit-vector.hpp\"\n\nnamespace geometry {\n    // \u5358\
    \u4F4D\u30D9\u30AF\u30C8\u30EB(unit vector)\u3092\u6C42\u3081\u308B\n    inline\
    \ Point unitVector(const Point &a) { return a / std::abs(a); }\n} // namespace\
    \ geometry\n#line 10 \"geometry/tangent.hpp\"\n\nnamespace geometry {\n    //\
    \ \u5186\u306E\u5171\u901A\u63A5\u7DDA\n    inline std::vector<Line> tangent(const\
    \ Circle &a, const Circle &b) {\n        std::vector<Line> ret;\n        // 2\u5186\
    \u306E\u4E2D\u5FC3\u9593\u306E\u8DDD\u96E2\n        D g = std::abs(a.p - b.p);\n\
    \        // \u5186\u304C\u5185\u5305\u3055\u308C\u3066\u3044\u308B\u5834\u5408\
    \n        if(equal(g, 0)) return ret;\n        Point u = unitVector(b.p - a.p);\n\
    \        Point v = rotate(u, PI / 2);\n        for(int s : {-1, 1}) {\n      \
    \      D h = (a.r + b.r * s) / g;\n            if(equal(h * h, 1)) {\n       \
    \         ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,\n                   \
    \              a.p + (h > 0 ? u : -u) * a.r + v);\n\n            } else if(1 -\
    \ h * h > 0) {\n                Point U = u * h, V = v * std::sqrt(1 - h * h);\n\
    \                ret.emplace_back(a.p + (U + V) * a.r,\n                     \
    \            b.p - (U + V) * (b.r * s));\n                ret.emplace_back(a.p\
    \ + (U - V) * a.r,\n                                 b.p - (U - V) * (b.r * s));\n\
    \            }\n        }\n        return ret;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <cmath>\n#include <vector>\n\n#include \"circle.hpp\"\
    \n#include \"line.hpp\"\n#include \"rotate.hpp\"\n#include \"unit-vector.hpp\"\
    \n\nnamespace geometry {\n    // \u5186\u306E\u5171\u901A\u63A5\u7DDA\n    inline\
    \ std::vector<Line> tangent(const Circle &a, const Circle &b) {\n        std::vector<Line>\
    \ ret;\n        // 2\u5186\u306E\u4E2D\u5FC3\u9593\u306E\u8DDD\u96E2\n       \
    \ D g = std::abs(a.p - b.p);\n        // \u5186\u304C\u5185\u5305\u3055\u308C\u3066\
    \u3044\u308B\u5834\u5408\n        if(equal(g, 0)) return ret;\n        Point u\
    \ = unitVector(b.p - a.p);\n        Point v = rotate(u, PI / 2);\n        for(int\
    \ s : {-1, 1}) {\n            D h = (a.r + b.r * s) / g;\n            if(equal(h\
    \ * h, 1)) {\n                ret.emplace_back(a.p + (h > 0 ? u : -u) * a.r,\n\
    \                                 a.p + (h > 0 ? u : -u) * a.r + v);\n\n     \
    \       } else if(1 - h * h > 0) {\n                Point U = u * h, V = v * std::sqrt(1\
    \ - h * h);\n                ret.emplace_back(a.p + (U + V) * a.r,\n         \
    \                        b.p - (U + V) * (b.r * s));\n                ret.emplace_back(a.p\
    \ + (U - V) * a.r,\n                                 b.p - (U - V) * (b.r * s));\n\
    \            }\n        }\n        return ret;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/circle.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  - geometry/rotate.hpp
  - geometry/unit-vector.hpp
  isVerificationFile: false
  path: geometry/tangent.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/tangent.hpp
layout: document
redirect_from:
- /library/geometry/tangent.hpp
- /library/geometry/tangent.hpp.html
title: geometry/tangent.hpp
---
