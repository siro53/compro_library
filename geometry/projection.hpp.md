---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: "\u76F4\u7DDA\u306B\u5BFE\u3059\u308B\u53CD\u5C04"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: "\u70B9\u304B\u3089\u5186\u3078\u306E\u63A5\u7DDA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/projection.hpp\"\n\n#line 2 \"geometry/dot.hpp\"\
    \n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\n\
    namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n\
    #line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n    // \u5185\u7A4D(dot\
    \ product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n \
    \   }\n} // namespace geometry\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\
    \n\nnamespace geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\
    \n    struct Line {\n        Point a, b;\n        Line() = default;\n        Line(Point\
    \ a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C)\
    \ {\n            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n#line 2 \"geometry/segment.hpp\"\n\n\
    #line 4 \"geometry/segment.hpp\"\n\nnamespace geometry {\n    // Segment : \u7DDA\
    \u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // Line\u3068\u540C\u3058\n  \
    \  struct Segment : Line {\n        Segment() = default;\n\n        Segment(Point\
    \ a, Point b) : Line(a, b) {}\n        D get_dist() { return std::abs(a - b);\
    \ }\n    };\n} // namespace geometry\n#line 6 \"geometry/projection.hpp\"\n\n\
    namespace geometry {\n    // \u5C04\u5F71(projection)\n    // \u76F4\u7DDA(\u7DDA\
    \u5206)l\u306B\u70B9p\u304B\u3089\u5F15\u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\
    \u6C42\u3081\u308B\n    inline Point projection(const Line &l, const Point &p)\
    \ {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n        return\
    \ l.a + (l.a - l.b) * t;\n    }\n\n    inline Point projection(const Segment &l,\
    \ const Point &p) {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n\
    \        return l.a + (l.a - l.b) * t;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"dot.hpp\"\n#include \"line.hpp\"\n#include \"\
    segment.hpp\"\n\nnamespace geometry {\n    // \u5C04\u5F71(projection)\n    //\
    \ \u76F4\u7DDA(\u7DDA\u5206)l\u306B\u70B9p\u304B\u3089\u5F15\u3044\u305F\u5782\
    \u7DDA\u306E\u8DB3\u3092\u6C42\u3081\u308B\n    inline Point projection(const\
    \ Line &l, const Point &p) {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a\
    \ - l.b);\n        return l.a + (l.a - l.b) * t;\n    }\n\n    inline Point projection(const\
    \ Segment &l, const Point &p) {\n        D t = dot(p - l.a, l.a - l.b) / std::norm(l.a\
    \ - l.b);\n        return l.a + (l.a - l.b) * t;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/dot.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  - geometry/segment.hpp
  isVerificationFile: false
  path: geometry/projection.hpp
  requiredBy:
  - geometry/tangent-to-circle.hpp
  - geometry/geometry.hpp
  - geometry/reflection.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/projection.hpp
layout: document
title: "\u5C04\u5F71"
---

## このライブラリでできること

`projection(l,p)` は、点 $p$ から直線 $l$ に下ろした垂線の足を返します。直線の方向を $d=b-a$ とすると、足は $a+d\,((p-a)\cdot d)/(d\cdot d)$ です。点を直線方向と垂直方向に分解する際に使えます。

## 使い方

例では水平な直線に点 $(1,3)$ を射影するので、足は $(1,0)$ になります。`Line` と `Segment` の両方を受け取れますが、Segment版も同じ無限直線への射影を行います。

```cpp
#include "template/template.cpp"
#include "geometry/projection.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(2, 0));
    Point q = projection(l, Point(1, 3));
    assert(equal(q.real(), 1) && equal(q.imag(), 0));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `projection(Line l,p)` | 無限直線 l への射影。 | O(1) |
| `projection(Segment l,p)` | 線分を含む無限直線への射影。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

2端点は異なる点にしてください。零方向では分母が0になります。Segment版の結果は線分の外に出ることがあり、端点へ切り詰める処理はありません。線分上の最近点を求めたい場合は、射影位置が端点の間にあるかも判定する必要があります。
