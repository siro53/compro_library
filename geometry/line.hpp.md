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
    path: geometry/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: "\u76F4\u7DDA\u306B\u5BFE\u3059\u308B\u53CD\u5C04"
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
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
  bundledCode: "#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n\
    #include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point : \u8907\
    \u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\
    \u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/line.hpp\"\n\nnamespace geometry\
    \ {\n    // Line : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // b\
    \ - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n    struct\
    \ Line {\n        Point a, b;\n        Line() = default;\n        Line(Point a,\
    \ Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D A, D B, D C) {\n\
    \            if(equal(A, 0)) {\n                a = Point(0, C / B), b = Point(1,\
    \ C / B);\n            } else if(equal(B, 0)) {\n                a = Point(C /\
    \ A, 0), b = Point(C / A, 1);\n            } else if(equal(C, 0)) {\n        \
    \        a = Point(0, C / B), b = Point(1, (C - A) / B);\n            } else {\n\
    \                a = Point(0, C / B), b = Point(C / A, 0);\n            }\n  \
    \      }\n    };\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // Line\
    \ : \u76F4\u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // b - a \u3067\u76F4\
    \u7DDA\u30FB\u7DDA\u5206\u3092\u8868\u305B\u308B\n    struct Line {\n        Point\
    \ a, b;\n        Line() = default;\n        Line(Point a, Point b) : a(a), b(b)\
    \ {}\n        // Ax+By=C\n        Line(D A, D B, D C) {\n            if(equal(A,\
    \ 0)) {\n                a = Point(0, C / B), b = Point(1, C / B);\n         \
    \   } else if(equal(B, 0)) {\n                a = Point(C / A, 0), b = Point(C\
    \ / A, 1);\n            } else if(equal(C, 0)) {\n                a = Point(0,\
    \ C / B), b = Point(1, (C - A) / B);\n            } else {\n                a\
    \ = Point(0, C / B), b = Point(C / A, 0);\n            }\n        }\n    };\n\
    } // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/is-orthogonal.hpp
  - geometry/segment.hpp
  - geometry/projection.hpp
  - geometry/geometry.hpp
  - geometry/reflection.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/distance-between-segment-and-point.hpp
  - geometry/is-intersect.hpp
  - geometry/cross-point.hpp
  - geometry/is-point-on-line.hpp
  - geometry/is-parallel.hpp
  - geometry/convex-cut.hpp
  - geometry/tangent.hpp
  - geometry/distance-between-line-and-point.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/line.hpp
layout: document
title: "\u76F4\u7DDA"
---

## このライブラリでできること

`Line` は、異なる2点 `a,b` を通る無限に長い直線を表します。両端で切られた線分ではありません。切断などの向きを使う処理では、`a` から `b` へ向かう方向をその直線の向きとします。

点を直接渡す方法のほか、直線の方程式 $Ax+By=C$ の係数を渡して作ることもできます。

## 使い方

例の `Line(1,1,2)` は $x+y=2$ を表します。コンストラクタがこの直線上の2点を選んで `a,b` に保存するので、それ以降は点指定で作った直線と同じように使えます。

点指定なら `Line(Point(0,0),Point(1,1))` のように書きます。向きを反転したい場合は2点の順序を逆にしてください。

```cpp
#include "template/template.cpp"
#include "geometry/line.hpp"

int main() {
    using namespace geometry;
    Line l(1, 1, 2);
    assert(equal(l.a.real() + l.a.imag(), 2));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Line()` | デフォルト構築。使用前に異なる 2 点を設定する。 | O(1) |
| `Line(a,b)` | 2 点から直線を作る。 | O(1) |
| `Line(A,B,C)` | Ax+By=C を表す 2 点を計算。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

点指定では `a!=b` としてください。係数指定では $A,B$ が同時に0であってはいけません。実装は係数の0判定にEPSを使うため、どちらもEPS内の値でも不適切な分岐に入ります。

デフォルト構築した直線は有効な方向を持たないので、演算前に異なる2点を設定してください。
