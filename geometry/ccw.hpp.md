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
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
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
    path: geometry/is-convex.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
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
  bundledCode: "#line 2 \"geometry/ccw.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\n\n\
    #line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\nnamespace\
    \ geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\
    \u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\
    \u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using\
    \ D = long double;\n    using Point = std::complex<D>;\n    const D EPS = 1e-7;\n\
    \    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D &a, const\
    \ D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n#line 4 \"\
    geometry/cross.hpp\"\n\nnamespace geometry {\n    // \u5916\u7A4D(cross product)\
    \ : a\xD7b = |a||b|sin\u0398\n    inline D cross(const Point &a, const Point &b)\
    \ {\n        return (a.real() * b.imag() - a.imag() * b.real());\n    }\n} //\
    \ namespace geometry\n#line 2 \"geometry/dot.hpp\"\n\n#line 4 \"geometry/dot.hpp\"\
    \n\nnamespace geometry {\n    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\
    \n    inline D dot(const Point &a, const Point &b) {\n        return (a.real()\
    \ * b.real() + a.imag() * b.imag());\n    }\n} // namespace geometry\n#line 5\
    \ \"geometry/ccw.hpp\"\n\nnamespace geometry {\n    // \u70B9\u306E\u56DE\u8EE2\
    \u65B9\u5411\n    // \u70B9a, b, c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u306B\u3064\u3044\
    \u3066(a\u304C\u57FA\u6E96\u70B9)\n    inline int ccw(const Point &a, Point b,\
    \ Point c) {\n        b -= a, c -= a;\n        // \u70B9a, b, c \u304C\n     \
    \   // \u53CD\u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c)\
    \ > EPS) return 1;\n        // \u6642\u8A08\u56DE\u308A\u306E\u6642\u3001\n  \
    \      if(cross(b, c) < -EPS) return -1;\n        // c, a, b\u304C\u3053\u306E\
    \u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u6642\u3001\
    \n        if(dot(b, c) < 0) return 2;\n        // a, b, c\u304C\u3053\u306E\u9806\
    \u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\
    \n        if(std::norm(b) < std::norm(c)) return -2;\n        // c\u304C\u7DDA\
    \u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n        return 0;\n    }\n\
    } // namespace geometry\n"
  code: "#pragma once\n\n#include \"cross.hpp\"\n#include \"dot.hpp\"\n\nnamespace\
    \ geometry {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\n    // \u70B9a, b,\
    \ c\u306E\u4F4D\u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\u57FA\u6E96\u70B9\
    )\n    inline int ccw(const Point &a, Point b, Point c) {\n        b -= a, c -=\
    \ a;\n        // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\u56DE\u308A\
    \u306E\u6642\u3001\n        if(cross(b, c) > EPS) return 1;\n        // \u6642\
    \u8A08\u56DE\u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS) return -1;\n\
    \        // c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\
    \u4E0A\u306B\u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return 2;\n  \
    \      // a, b, c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \u306B\u3042\u308B\u5834\u5408\u3001\n        if(std::norm(b) < std::norm(c))\
    \ return -2;\n        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \u3001\n        return 0;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  isVerificationFile: false
  path: geometry/ccw.hpp
  requiredBy:
  - geometry/is-convex.hpp
  - geometry/geometry.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/is-intersect.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/ccw.hpp
layout: document
title: "3 \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2"
---

## このライブラリでできること

`ccw(a,b,c)` は、有向線分 $a\to b$ を基準に点 $c$ の位置を5種類に分類します。左側なら $1$、右側なら $-1$、同一直線上なら「aより後ろ」「線分上」「bより先」をそれぞれ $2,0,-2$ で表します。

単に回転方向だけを返す関数ではなく、一直線上の位置まで区別するため、線分の交差判定にも使えます。

## 使い方

最初の例では $c$ が $a\to b$ の左側にあるので $1$ を返します。次の例では $(1,0)$ が $(0,0)$ と $(2,0)$ の間にあるため $0$ です。

返り値 $2$ は $c,a,b$ の順、$-2$ は $a,b,c$ の順に一直線上に並ぶことを表します。端点と一致した場合も線分上の $0$ に分類されます。

```cpp
#include "template/template.cpp"
#include "geometry/ccw.hpp"

int main() {
    using namespace geometry;
    assert(ccw(Point(0, 0), Point(1, 0), Point(0, 1)) == 1);
    assert(ccw(Point(0, 0), Point(2, 0), Point(1, 0)) == 0);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ccw(a,b,c)` | 反時計回り 1、時計回り -1、c-a-b の順 2、a-b-c の順 -2、c が線分 ab 上なら 0。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

基準となる $a,b$ は異なる点にしてください。回転の判定には外積とEPSを使いますが、その後の前後判定は内積と長さの二乗の直接比較です。したがって5分類すべてが同じ距離誤差で定義されているわけではありません。
