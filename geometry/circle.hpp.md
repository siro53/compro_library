---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geometry/cross-point.hpp
    title: "\u4EA4\u70B9"
  - icon: ':heavy_check_mark:'
    path: geometry/distance-between-segments.hpp
    title: "\u7DDA\u5206\u9593\u306E\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/is-in-circle.hpp
    title: "\u5186\u3078\u306E\u5305\u542B\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent-to-circle.hpp
    title: "\u70B9\u304B\u3089\u5186\u3078\u306E\u63A5\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: "2 \u5186\u306E\u5171\u901A\u63A5\u7DDA"
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
  bundledCode: "#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point :\
    \ \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/circle.hpp\"\n\nnamespace geometry\
    \ {\n    // Circle : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\
    \u4E2D\u5FC3\u306E\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\
    \n    struct Circle {\n        Point p;\n        D r;\n\n        Circle() = default;\n\
    \n        Circle(Point p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // Circle\
    \ : \u5186\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // p\u304C\u4E2D\u5FC3\u306E\
    \u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3001r\u306F\u534A\u5F84\n    struct Circle\
    \ {\n        Point p;\n        D r;\n\n        Circle() = default;\n\n       \
    \ Circle(Point p, D r) : p(p), r(r) {}\n    };\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/circle.hpp
  requiredBy:
  - geometry/geometry.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/is-intersect.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  - geometry/tangent.hpp
  - geometry/is-in-circle.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/circle.hpp
layout: document
title: "\u5186"
---

## このライブラリでできること

`Circle` は、中心 `p` と半径 `r` を持つ円を表す構造体です。円周は $\{x\mid\lvert x-p\rvert=r\}$、円の内部と境界を合わせた領域は $\{x\mid\lvert x-p\rvert\le r\}$ です。交点の関数は円周、包含の関数は内部も含む領域を扱います。

## 使い方

例の `Circle(Point(1,2),3)` は中心 $(1,2)$、半径 $3$ の円を作ります。中心や半径を保持するだけで、この構造体自体が交差判定や面積計算を行うわけではありません。必要な幾何関数へ渡して使います。

```cpp
#include "template/template.cpp"
#include "geometry/circle.hpp"

int main() {
    using namespace geometry;
    Circle c(Point(1, 2), 3);
    assert(equal(c.r, 3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Circle()` | デフォルト構築。r は未初期化。 | O(1) |
| `Circle(p,r)` | 中心・半径を設定。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

半径は非負で指定してください。交点・接線の計算では、さらに正の半径が必要な場合があります。デフォルト構築では半径が初期化されないので、使用前に中心と半径を設定してください。
