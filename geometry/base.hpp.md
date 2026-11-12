---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: "3 \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: "\u5186"
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
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/degree-to-radian.hpp
    title: "\u5EA6\u304B\u3089\u30E9\u30B8\u30A2\u30F3"
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
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
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
    path: geometry/is-in-circle.hpp
    title: "\u5186\u3078\u306E\u5305\u542B\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-orthogonal.hpp
    title: "\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-parallel.hpp
    title: "\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-line.hpp
    title: "\u70B9\u304C\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u304B"
  - icon: ':heavy_check_mark:'
    path: geometry/is-point-on-segment.hpp
    title: "\u70B9\u304C\u7DDA\u5206\u4E0A\u306B\u3042\u308B\u304B"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/normal-vector.hpp
    title: "\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: geometry/polygon-area.hpp
    title: "\u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':heavy_check_mark:'
    path: geometry/radian-to-degree.hpp
    title: "\u30E9\u30B8\u30A2\u30F3\u304B\u3089\u5EA6"
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: "\u76F4\u7DDA\u306B\u5BFE\u3059\u308B\u53CD\u5C04"
  - icon: ':heavy_check_mark:'
    path: geometry/rotate.hpp
    title: "\u70B9\u30FB\u30D9\u30AF\u30C8\u30EB\u306E\u56DE\u8EE2"
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: "\u70B9\u304B\u3089\u5186\u3078\u306E\u63A5\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: "2 \u5186\u306E\u5171\u901A\u63A5\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/unit-vector.hpp
    title: "\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB"
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
  bundledCode: "#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\
    \nnamespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\
    \u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092\
    x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n \
    \   using D = long double;\n    using Point = std::complex<D>;\n    const D EPS\
    \ = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D\
    \ &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <cmath>\n#include <complex>\n\nnamespace geometry\
    \ {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\
    \u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\
    \u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long\
    \ double;\n    using Point = std::complex<D>;\n    const D EPS = 1e-7;\n    const\
    \ D PI = std::acos(D(-1));\n\n    inline bool equal(const D &a, const D &b) {\
    \ return std::fabs(a - b) < EPS; }\n} // namespace geometry\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/base.hpp
  requiredBy:
  - geometry/is-orthogonal.hpp
  - geometry/convex-hull.hpp
  - geometry/segment.hpp
  - geometry/is-convex.hpp
  - geometry/line.hpp
  - geometry/projection.hpp
  - geometry/ccw.hpp
  - geometry/geometry.hpp
  - geometry/reflection.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/distance-between-segment-and-point.hpp
  - geometry/rotate.hpp
  - geometry/is-intersect.hpp
  - geometry/cross-point.hpp
  - geometry/is-point-on-line.hpp
  - geometry/is-parallel.hpp
  - geometry/normal-vector.hpp
  - geometry/circle.hpp
  - geometry/dot.hpp
  - geometry/polygon-area.hpp
  - geometry/convex-cut.hpp
  - geometry/radian-to-degree.hpp
  - geometry/unit-vector.hpp
  - geometry/is-contained.hpp
  - geometry/tangent.hpp
  - geometry/distance-between-line-and-point.hpp
  - geometry/is-point-on-segment.hpp
  - geometry/cross.hpp
  - geometry/is-in-circle.hpp
  - geometry/degree-to-radian.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/base.hpp
layout: document
title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
---

## このライブラリでできること

`base.hpp` は、幾何ライブラリ全体で共有する点・座標型と定数を定義します。点を複素数で表すことで、2点の差をベクトルとして扱い、その加減算や長さの計算に標準の複素数演算を使えます。

`Point(x,y)` が座標 $(x,y)$、`abs(p)` が原点からの距離、`norm(p)` が距離の二乗です。たとえば点 $(3,4)$ の距離は $5$、距離の二乗は $25$ になります。

## 使い方

例では点 $(3,4)$ の長さを計算しています。浮動小数点値の比較には `equal(a,b)` を使うと、差の絶対値が `EPS` 未満かどうかを判定できます。

`PI` は円周率、`EPS` は $10^{-7}$ です。幾何の各ヘッダーは必要な基本定義を include するので、通常は使う機能のヘッダーを選べば構いません。

```cpp
#include "template/template.cpp"
#include "geometry/base.hpp"

int main() {
    using namespace geometry;
    Point p(3, 4);
    assert(equal(abs(p), 5));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `equal(a,b)` | abs(a-b)<EPS かを返す（絶対誤差）。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

`equal(a,b)` は $\lvert a-b\rvert<\mathrm{EPS}$ という絶対誤差での比較です。相対誤差ではないため、座標の大きさに応じて許容幅が変わるわけではありません。また、近似的な一致は一般に推移律を満たさないので、ソートの厳密な同値関係などにそのまま使わないでください。
