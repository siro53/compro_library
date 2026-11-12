---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
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
  bundledCode: "#line 2 \"geometry/is-point-on-segment.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/is-point-on-segment.hpp\"\n\n\
    namespace geometry {\n    // \u70B9c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\u3042\
    \u308B\u304B\n    inline bool isPointOnSegment(const Point &a, const Point &b,\
    \ const Point &c) {\n        // |a-c| + |c-b| <= |a-b| \u306A\u3089\u7DDA\u5206\
    \u4E0A\n        return (std::abs(a - c) + std::abs(c - b) < std::abs(a - b) +\
    \ EPS);\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    c\u304C\"\u7DDA\u5206\"ab\u4E0A\u306B\u3042\u308B\u304B\n    inline bool isPointOnSegment(const\
    \ Point &a, const Point &b, const Point &c) {\n        // |a-c| + |c-b| <= |a-b|\
    \ \u306A\u3089\u7DDA\u5206\u4E0A\n        return (std::abs(a - c) + std::abs(c\
    \ - b) < std::abs(a - b) + EPS);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/is-point-on-segment.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-point-on-segment.hpp
layout: document
title: "\u70B9\u304C\u7DDA\u5206\u4E0A\u306B\u3042\u308B\u304B"
---

## このライブラリでできること

`isPointOnSegment(a,b,c)` は、点 $c$ が端点を含む線分 $ab$ 上にあるかを調べます。数学的には、三角不等式が等号になる条件 $\lvert a-c\rvert+\lvert c-b\rvert=\lvert a-b\rvert$ を利用しています。

## 使い方

例では $(1,0)$ が $(0,0)$ と $(2,0)$ の間にあるため真を返します。同じ直線上でも端点の外側にある点は、2つの距離の和が線分長より大きくなるので偽になります。

```cpp
#include "template/template.cpp"
#include "geometry/is-point-on-segment.hpp"

int main() {
    using namespace geometry;
    assert(isPointOnSegment(Point(0, 0), Point(2, 0), Point(1, 0)));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isPointOnSegment(a,b,c)` | abs(a-c)+abs(c-b)<abs(a-b)+EPS。端点を含む。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

実装は等号の代わりに $\lvert a-c\rvert+\lvert c-b\rvert<\lvert a-b\rvert+\mathrm{EPS}$ を用います。これは距離の和の差に対する許容誤差であり、点から線分への距離がEPS以下かを判定するものではありません。
