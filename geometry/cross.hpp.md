---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: "3 \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geometry/convex-hull.hpp
    title: "\u51F8\u5305"
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-line-and-point.hpp
    title: "\u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segment-and-point.hpp
    title: "\u7DDA\u5206\u3068\u70B9\u306E\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segments.hpp
    title: "\u7DDA\u5206\u9593\u306E\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/is-contained.hpp
    title: "\u591A\u89D2\u5F62\u3078\u306E\u5305\u542B\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-convex.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-parallel.hpp
    title: "\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-line.hpp
    title: "\u70B9\u304C\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u304B"
  - icon: ':heavy_check_mark:'
    path: geometry/polygon-area.hpp
    title: "\u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: "\u70B9\u304B\u3089\u5186\u3078\u306E\u63A5\u7DDA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry-api.test.cpp
    title: test/mytest/geometry/geometry-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n\
    #include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point : \u8907\
    \u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\
    \u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u5916\
    \u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline D cross(const Point\
    \ &a, const Point &b) {\n        return (a.real() * b.imag() - a.imag() * b.real());\n\
    \    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/cross.hpp
  requiredBy:
  - geometry/tangent-to-circle.hpp
  - geometry/convex-hull.hpp
  - geometry/is-point-on-line.hpp
  - geometry/geometry.hpp
  - geometry/is-intersect.hpp
  - geometry/ccw.hpp
  - geometry/is-parallel.hpp
  - geometry/distance-between-segments.hpp
  - geometry/distance-between-line-and-point.hpp
  - geometry/is-contained.hpp
  - geometry/polygon-area.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  - geometry/is-convex.hpp
  - geometry/distance-between-segment-and-point.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
  - test/mytest/geometry/geometry-api.test.cpp
documentation_of: geometry/cross.hpp
layout: document
title: "\u5916\u7A4D"
---

## このライブラリでできること

`cross(a,b)` は、2次元ベクトルの外積に相当する行列式 $a_xb_y-a_yb_x$ を返します。この値は、2ベクトルが作る平行四辺形の符号付き面積でもあります。

正なら $a$ から $b$ への回転が反時計回り、負なら時計回りです。0なら2ベクトルは平行です。この符号は凸包や線分の交差判定など、多くの幾何アルゴリズムの基本になります。

## 使い方

例では右向きの $(1,0)$ から上向きの $(0,1)$ へ反時計回りに回るので、外積は $1$ です。3点 $a,b,c$ の向きを調べる場合は `cross(b-a,c-a)` として、基準点をそろえたベクトルを渡します。

```cpp
#include "template/template.cpp"
#include "geometry/cross.hpp"

int main() {
    using namespace geometry;
    assert(equal(cross(Point(1, 0), Point(0, 1)), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `cross(a,b)` | ax*by-ay*bx。正なら a から b が反時計回り。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

返り値は0/1の判定ではなく、符号と大きさを持つ数値です。関数内でEPSによる丸めはしません。ほぼ一直線上の点の判定では、座標の尺度と丸め誤差を考慮して符号を判定してください。
