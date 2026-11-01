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
  bundledCode: "#line 2 \"geometry/is-orthogonal.hpp\"\n\n#line 2 \"geometry/dot.hpp\"\
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
    \      }\n    };\n} // namespace geometry\n#line 5 \"geometry/is-orthogonal.hpp\"\
    \n\nnamespace geometry {\n    // 2\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A :\
    \ a\u22A5b <=> dot(a, b) = 0\n    inline bool isOrthogonal(const Line &a, const\
    \ Line &b) {\n        return equal(dot(a.b - a.a, b.b - b.a), 0);\n    }\n} //\
    \ namespace geometry\n"
  code: "#pragma once\n\n#include \"dot.hpp\"\n#include \"line.hpp\"\n\nnamespace\
    \ geometry {\n    // 2\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A : a\u22A5b <=>\
    \ dot(a, b) = 0\n    inline bool isOrthogonal(const Line &a, const Line &b) {\n\
    \        return equal(dot(a.b - a.a, b.b - b.a), 0);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/dot.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/is-orthogonal.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-orthogonal.hpp
layout: document
title: "\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A"
---

## このライブラリでできること

`isOrthogonal(a,b)` は、2直線の方向ベクトルの内積を使って直交を判定します。非零ベクトル $u,v$ に対し、直交の条件は $u\cdot v=0$ です。実装では内積がEPS未満で0に近いかを調べます。

## 使い方

例では水平方向と垂直方向の直線を渡しているため、真を返します。直線上のどの2点で表しても数学的には同じ直交関係ですが、数値計算では方向ベクトルの尺度にも注意が必要です。

```cpp
#include "template/template.cpp"
#include "geometry/is-orthogonal.hpp"

int main() {
    using namespace geometry;
    Line a(Point(0, 0), Point(1, 0));
    Line b(Point(0, 0), Point(0, 1));
    assert(isOrthogonal(a, b));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isOrthogonal(a,b)` | 2 直線が直交するか。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線の2点は異なる点にしてください。零方向ベクトルの内積は常に0なので、その場合の返り値には直交という幾何的な意味がありません。また、判定は角度そのものの誤差ではなく、内積の絶対誤差に基づきます。
