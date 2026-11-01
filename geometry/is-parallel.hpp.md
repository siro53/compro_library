---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-line.hpp
    title: "\u70B9\u304C\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u304B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is-parallel.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\
    \n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\n\
    namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n\
    #line 4 \"geometry/cross.hpp\"\n\nnamespace geometry {\n    // \u5916\u7A4D(cross\
    \ product) : a\xD7b = |a||b|sin\u0398\n    inline D cross(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.imag() - a.imag() * b.real());\n \
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
    \      }\n    };\n} // namespace geometry\n#line 5 \"geometry/is-parallel.hpp\"\
    \n\nnamespace geometry {\n    // 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A :\
    \ a//b <=> cross(a, b) = 0\n    inline bool isParallel(const Line &a, const Line\
    \ &b) {\n        return equal(cross(a.b - a.a, b.b - b.a), 0);\n    }\n} // namespace\
    \ geometry\n"
  code: "#pragma once\n\n#include \"cross.hpp\"\n#include \"line.hpp\"\n\nnamespace\
    \ geometry {\n    // 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A : a//b <=> cross(a,\
    \ b) = 0\n    inline bool isParallel(const Line &a, const Line &b) {\n       \
    \ return equal(cross(a.b - a.a, b.b - b.a), 0);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/is-parallel.hpp
  requiredBy:
  - geometry/is-point-on-line.hpp
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-parallel.hpp
layout: document
title: "\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A"
---

## このライブラリでできること

`isParallel(a,b)` は、2直線の方向ベクトルが平行かを調べます。方向ベクトル $u,v$ が平行である条件は $u_xv_y-u_yv_x=0$ です。実装では外積がEPS未満で0に近いかを判定します。

## 使い方

例の直線はどちらも方向ベクトル $(1,1)$ を持つため、平行と判定されます。同一直線も平行として真を返します。「交点がないか」を判定する関数とは異なります。

```cpp
#include "template/template.cpp"
#include "geometry/is-parallel.hpp"

int main() {
    using namespace geometry;
    Line a(Point(0, 0), Point(1, 1));
    Line b(Point(0, 1), Point(1, 2));
    assert(isParallel(a, b));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isParallel(a,b)` | 2 直線が平行か（同一直線も true）。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

それぞれの直線は異なる2点で指定してください。零方向ベクトルでは外積が常に0になり、有効な平行判定になりません。外積の絶対値で比較するため、判定の許容角度は方向ベクトルの長さにも依存します。
