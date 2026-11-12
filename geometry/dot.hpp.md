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
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
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
    path: geometry/is-orthogonal.hpp
    title: "\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: "\u76F4\u7DDA\u306B\u5BFE\u3059\u308B\u53CD\u5C04"
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
  bundledCode: "#line 2 \"geometry/dot.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n\
    #include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point : \u8907\
    \u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\
    \u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\n    inline\
    \ D dot(const Point &a, const Point &b) {\n        return (a.real() * b.real()\
    \ + a.imag() * b.imag());\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u5185\
    \u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point\
    \ &a, const Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n\
    \    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/dot.hpp
  requiredBy:
  - geometry/is-orthogonal.hpp
  - geometry/is-convex.hpp
  - geometry/projection.hpp
  - geometry/ccw.hpp
  - geometry/geometry.hpp
  - geometry/reflection.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/distance-between-segment-and-point.hpp
  - geometry/is-intersect.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  - geometry/is-contained.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/dot.hpp
layout: document
title: "\u5185\u7A4D"
---

## このライブラリでできること

`dot(a,b)` は2つのベクトルの内積 $a_xb_x+a_yb_y$ を返します。長さと角度を使うと $a\cdot b=\lvert a\rvert\lvert b\rvert\cos\theta$ と表せるので、向きの近さや直交を調べるために使えます。

非零ベクトル同士なら、内積が正のときはなす角が鋭角、0なら直角、負なら鈍角です。射影や、点からの垂線の足が線分内にあるかの判定にも使います。

## 使い方

例の $(1,2)$ と $(3,4)$ の内積は $1\cdot3+2\cdot4=11$ です。2点間の方向を調べたい場合は、点そのものではなく `b-a` のような差を渡してください。

```cpp
#include "template/template.cpp"
#include "geometry/dot.hpp"

int main() {
    using namespace geometry;
    assert(equal(dot(Point(1, 2), Point(3, 4)), 11));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `dot(a,b)` | ax*bx+ay*by。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

関数は内積をそのまま計算し、0への丸めは行いません。直交判定では `equal(dot(a,b),0)` などの許容誤差を使う必要がありますが、内積の値はベクトルの長さにも依存するため、同じEPSでも角度としての許容幅は一定ではありません。
