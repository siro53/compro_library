---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':x:'
    path: geometry/circle.hpp
    title: "\u5186"
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/geometry/geometry-api.test.cpp
    title: test/mytest/geometry/geometry-api.test.cpp
  - icon: ':x:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/is-in-circle.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\n\
    namespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n\
    #line 4 \"geometry/circle.hpp\"\n\nnamespace geometry {\n    // Circle : \u5186\
    \u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle {\n     \
    \   Point p;\n        D r;\n\n        Circle() = default;\n\n        Circle(Point\
    \ p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n#line 4 \"geometry/is-in-circle.hpp\"\
    \n\nnamespace geometry {\n    // \u70B9p\u304C\u5186c\u306E\u5185\u90E8(\u5186\
    \u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\n    inline bool isInCircle(const Circle &c, const Point &p) {\n\
    \        D d = std::abs(c.p - p);\n        return (equal(d, c.r) || d < c.r -\
    \ EPS);\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"circle.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    p\u304C\u5186c\u306E\u5185\u90E8(\u5186\u5468\u4E0A\u3082\u542B\u3080)\u306B\u5165\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n    inline bool isInCircle(const\
    \ Circle &c, const Point &p) {\n        D d = std::abs(c.p - p);\n        return\
    \ (equal(d, c.r) || d < c.r - EPS);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/circle.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/is-in-circle.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
  - test/mytest/geometry/geometry-api.test.cpp
documentation_of: geometry/is-in-circle.hpp
layout: document
title: "\u5186\u3078\u306E\u5305\u542B\u5224\u5B9A"
---

## このライブラリでできること

`isInCircle(c,p)` は、点 $p$ が円の内部または円周上にあるかを判定します。数学的な条件は、中心を $c.p$、半径を $r$ として $|p-c.p|\le r$ です。円周だけを調べる関数ではありません。

## 使い方

例の点 $(1,0)$ は、原点中心・半径2の円の内部にあるため真になります。内部と境界を区別して返すAPIではないので、境界だけを扱う場合は中心距離と半径を別途比較してください。

```cpp
#include "template/template.cpp"
#include "geometry/is-in-circle.hpp"

int main() {
    using namespace geometry;
    Circle c(Point(0, 0), 2);
    assert(isInCircle(c, Point(1, 0)));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isInCircle(c,p)` | 内部・境界なら true。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

半径は非負としてください。実装は中心距離と半径の差にEPSを用いるため、円の外側にわずかにはみ出た点も境界相当として真になる場合があります。境界の数値的な意味は厳密な集合包含とは異なります。
