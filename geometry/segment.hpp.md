---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  _extendedRequiredBy:
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
    path: geometry/is-intersect.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
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
  bundledCode: "#line 2 \"geometry/segment.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\
    \n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n#include <complex>\n\nnamespace\
    \ geometry {\n    // Point : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\
    \u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\
    \u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using\
    \ D = long double;\n    using Point = std::complex<D>;\n    const D EPS = 1e-7;\n\
    \    const D PI = std::acos(D(-1));\n\n    inline bool equal(const D &a, const\
    \ D &b) { return std::fabs(a - b) < EPS; }\n} // namespace geometry\n#line 4 \"\
    geometry/line.hpp\"\n\nnamespace geometry {\n    // Line : \u76F4\u7DDA\u3092\u8868\
    \u3059\u69CB\u9020\u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\u7DDA\u5206\u3092\
    \u8868\u305B\u308B\n    struct Line {\n        Point a, b;\n        Line() = default;\n\
    \        Line(Point a, Point b) : a(a), b(b) {}\n        // Ax+By=C\n        Line(D\
    \ A, D B, D C) {\n            if(equal(A, 0)) {\n                a = Point(0,\
    \ C / B), b = Point(1, C / B);\n            } else if(equal(B, 0)) {\n       \
    \         a = Point(C / A, 0), b = Point(C / A, 1);\n            } else if(equal(C,\
    \ 0)) {\n                a = Point(0, C / B), b = Point(1, (C - A) / B);\n   \
    \         } else {\n                a = Point(0, C / B), b = Point(C / A, 0);\n\
    \            }\n        }\n    };\n} // namespace geometry\n#line 4 \"geometry/segment.hpp\"\
    \n\nnamespace geometry {\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\
    \u9020\u4F53\n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n   \
    \     Segment() = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n\
    \        D get_dist() { return std::abs(a - b); }\n    };\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"line.hpp\"\n\nnamespace geometry {\n    // Segment\
    \ : \u7DDA\u5206\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // Line\u3068\u540C\u3058\
    \n    struct Segment : Line {\n        Segment() = default;\n\n        Segment(Point\
    \ a, Point b) : Line(a, b) {}\n        D get_dist() { return std::abs(a - b);\
    \ }\n    };\n} // namespace geometry\n"
  dependsOn:
  - geometry/line.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/segment.hpp
  requiredBy:
  - geometry/projection.hpp
  - geometry/geometry.hpp
  - geometry/reflection.hpp
  - geometry/distance-between-segments.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/distance-between-segment-and-point.hpp
  - geometry/is-intersect.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/segment.hpp
layout: document
title: "\u7DDA\u5206"
---

## このライブラリでできること

`Segment` は、端点 `a,b` の間の線分を表します。数学的には $\{a+t(b-a)\mid0\le t\le1\}$ です。`Line` を継承して同じ端点を持ちますが、距離や交差判定では端点の外へ伸びない図形として扱います。

## 使い方

2端点を渡して構築し、`get_dist()` で長さを取得します。例では $(0,0)$ と $(3,4)$ の距離が $5$ であることを確認しています。`a,b` は公開メンバなので、端点の参照にも使えます。

```cpp
#include "template/template.cpp"
#include "geometry/segment.hpp"

int main() {
    using namespace geometry;
    Segment s(Point(0, 0), Point(3, 4));
    assert(equal(s.get_dist(), 5));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Segment(), Segment(a,b)` | デフォルトまたは端点指定で構築。 | O(1) |
| `get_dist()` | 線分の長さ。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

`Line` に変換すると、この線分を含む無限直線として扱われます。関数によって線分版の意味が異なる場合があり、たとえば `projection(Segment,Point)` は線分内への丸めを行いません。

2端点が等しい零長線分を受け付けるかどうかは、利用する各関数の説明に従ってください。
