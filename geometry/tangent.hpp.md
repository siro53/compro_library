---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: "\u5186"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/rotate.hpp
    title: "\u70B9\u30FB\u30D9\u30AF\u30C8\u30EB\u306E\u56DE\u8EE2"
  - icon: ':heavy_check_mark:'
    path: geometry/unit-vector.hpp
    title: "\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
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
title: "2 \u5186\u306E\u5171\u901A\u63A5\u7DDA"
---

## このライブラリでできること

`tangent(a,b)` は、2つの円の両方に接する直線を列挙します。通常の相異なる円では、離れていると4本、外接で3本、2点で交差すると2本、内接で1本、一方が他方の内部に入ると0本です。

返り値は `vector<Line>` で、中心を結ぶ方向とその法線方向から各接線を構成します。接点ではなく直線を返す点が、`tangentToCircle` との違いです。

## 使い方

例の円はどちらも半径1で、中心間距離が4なので、共通接線が4本あります。必要な向きや順序で処理したい場合は、返された直線を呼び出し側で整理してください。

```cpp
#include "template/template.cpp"
#include "geometry/tangent.hpp"

int main() {
    using namespace geometry;
    auto lines = tangent(Circle(Point(0, 0), 1), Circle(Point(4, 0), 1));
    assert(lines.size() == 4);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `tangent(a,b)` | vector<Line>。位置関係に応じ 0..4 本。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

半径は正とし、同一円は通常の列挙対象から除いてください。同一円には無限本の接線がありますが、この実装は中心がEPS内で一致する場合に空の配列を返します。接する付近の判定はEPSを使うため、非常に近い退化配置では本数や座標に数値誤差の影響があります。
