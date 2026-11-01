---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
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
  bundledCode: "#line 2 \"geometry/normal-vector.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/normal-vector.hpp\"\n\nnamespace\
    \ geometry {\n    // \u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB(normal vector)\u3092\
    \u6C42\u3081\u308B\n    // 90\u5EA6\u56DE\u8EE2\u3057\u305F\u5358\u4F4D\u30D9\u30AF\
    \u30C8\u30EB\u3092\u304B\u3051\u308B\n    // -90\u5EA6\u304C\u3088\u3051\u308C\
    \u3070Point(0, -1)\u3092\u304B\u3051\u308B\n    inline Point normalVector(const\
    \ Point &a) { return a * Point(0, 1); }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u6CD5\
    \u7DDA\u30D9\u30AF\u30C8\u30EB(normal vector)\u3092\u6C42\u3081\u308B\n    //\
    \ 90\u5EA6\u56DE\u8EE2\u3057\u305F\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\u3092\u304B\
    \u3051\u308B\n    // -90\u5EA6\u304C\u3088\u3051\u308C\u3070Point(0, -1)\u3092\
    \u304B\u3051\u308B\n    inline Point normalVector(const Point &a) { return a *\
    \ Point(0, 1); }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/normal-vector.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
  - test/mytest/geometry/geometry-api.test.cpp
documentation_of: geometry/normal-vector.hpp
layout: document
title: "\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB"
---

## このライブラリでできること

`normalVector(a)` は、ベクトル $a=(x,y)$ を90度反時計回りに回した $(-y,x)$ を返します。元のベクトルに垂直で長さが等しいため、直線の法線方向を求めるのに使えます。

## 使い方

例では $(2,0)$ が $(0,2)$ になります。直線 `l` の左側へ向く法線なら `normalVector(l.b-l.a)` とします。長さ1の法線が必要な場合は、非零ベクトルであることを確認してから単位ベクトルへ正規化してください。

```cpp
#include "template/template.cpp"
#include "geometry/normal-vector.hpp"

int main() {
    using namespace geometry;
    Point n = normalVector(Point(2, 0));
    assert(equal(n.real(), 0) && equal(n.imag(), 2));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `normalVector(a)` | a に垂直で同じ長さのベクトル。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

名前にnormalとありますが、長さを1にする関数ではありません。零ベクトルを渡すと零ベクトルが返り、その場合は特定の法線方向を表しません。
