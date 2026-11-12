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
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: "\u7DDA\u5206"
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
  bundledCode: "#line 2 \"geometry/reflection.hpp\"\n\n#line 2 \"geometry/projection.hpp\"\
    \n\n#line 2 \"geometry/dot.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n#include\
    \ <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point : \u8907\u7D20\
    \u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\
    \u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\
    \u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point =\
    \ std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\n    inline\
    \ D dot(const Point &a, const Point &b) {\n        return (a.real() * b.real()\
    \ + a.imag() * b.imag());\n    }\n} // namespace geometry\n#line 2 \"geometry/line.hpp\"\
    \n\n#line 4 \"geometry/line.hpp\"\n\nnamespace geometry {\n    // Line : \u76F4\
    \u7DDA\u3092\u8868\u3059\u69CB\u9020\u4F53\n    // b - a \u3067\u76F4\u7DDA\u30FB\
    \u7DDA\u5206\u3092\u8868\u305B\u308B\n    struct Line {\n        Point a, b;\n\
    \        Line() = default;\n        Line(Point a, Point b) : a(a), b(b) {}\n \
    \       // Ax+By=C\n        Line(D A, D B, D C) {\n            if(equal(A, 0))\
    \ {\n                a = Point(0, C / B), b = Point(1, C / B);\n            }\
    \ else if(equal(B, 0)) {\n                a = Point(C / A, 0), b = Point(C / A,\
    \ 1);\n            } else if(equal(C, 0)) {\n                a = Point(0, C /\
    \ B), b = Point(1, (C - A) / B);\n            } else {\n                a = Point(0,\
    \ C / B), b = Point(C / A, 0);\n            }\n        }\n    };\n} // namespace\
    \ geometry\n#line 2 \"geometry/segment.hpp\"\n\n#line 4 \"geometry/segment.hpp\"\
    \n\nnamespace geometry {\n    // Segment : \u7DDA\u5206\u3092\u8868\u3059\u69CB\
    \u9020\u4F53\n    // Line\u3068\u540C\u3058\n    struct Segment : Line {\n   \
    \     Segment() = default;\n\n        Segment(Point a, Point b) : Line(a, b) {}\n\
    \        D get_dist() { return std::abs(a - b); }\n    };\n} // namespace geometry\n\
    #line 6 \"geometry/projection.hpp\"\n\nnamespace geometry {\n    // \u5C04\u5F71\
    (projection)\n    // \u76F4\u7DDA(\u7DDA\u5206)l\u306B\u70B9p\u304B\u3089\u5F15\
    \u3044\u305F\u5782\u7DDA\u306E\u8DB3\u3092\u6C42\u3081\u308B\n    inline Point\
    \ projection(const Line &l, const Point &p) {\n        D t = dot(p - l.a, l.a\
    \ - l.b) / std::norm(l.a - l.b);\n        return l.a + (l.a - l.b) * t;\n    }\n\
    \n    inline Point projection(const Segment &l, const Point &p) {\n        D t\
    \ = dot(p - l.a, l.a - l.b) / std::norm(l.a - l.b);\n        return l.a + (l.a\
    \ - l.b) * t;\n    }\n} // namespace geometry\n#line 4 \"geometry/reflection.hpp\"\
    \n\nnamespace geometry {\n    // \u53CD\u5C04(reflection)\n    // \u76F4\u7DDA\
    l\u3092\u5BFE\u79F0\u8EF8\u3068\u3057\u3066\u70B9p\u3068\u7DDA\u5BFE\u79F0\u306E\
    \u4F4D\u7F6E\u306B\u3042\u308B\u70B9\u3092\u6C42\u3081\u308B\n    inline Point\
    \ reflection(const Line &l, const Point &p) {\n        return p + (projection(l,\
    \ p) - p) * (D)2.0;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"projection.hpp\"\n\nnamespace geometry {\n   \
    \ // \u53CD\u5C04(reflection)\n    // \u76F4\u7DDAl\u3092\u5BFE\u79F0\u8EF8\u3068\
    \u3057\u3066\u70B9p\u3068\u7DDA\u5BFE\u79F0\u306E\u4F4D\u7F6E\u306B\u3042\u308B\
    \u70B9\u3092\u6C42\u3081\u308B\n    inline Point reflection(const Line &l, const\
    \ Point &p) {\n        return p + (projection(l, p) - p) * (D)2.0;\n    }\n} //\
    \ namespace geometry\n"
  dependsOn:
  - geometry/projection.hpp
  - geometry/dot.hpp
  - geometry/base.hpp
  - geometry/line.hpp
  - geometry/segment.hpp
  isVerificationFile: false
  path: geometry/reflection.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/reflection.hpp
layout: document
title: "\u76F4\u7DDA\u306B\u5BFE\u3059\u308B\u53CD\u5C04"
---

## このライブラリでできること

`reflection(l,p)` は、直線 $l$ を鏡として点 $p$ を反対側へ移した点を返します。垂線の足を $h$ とすると、反射後の点は $2h-p$ です。鏡面反射や、対称な位置への変換に使えます。

## 使い方

例では $x$ 軸を表す直線に対して $(2,3)$ を反射するので、結果は $(2,-3)$ になります。直線上の点を渡した場合、数学的には元と同じ点が返ります。

```cpp
#include "template/template.cpp"
#include "geometry/reflection.hpp"

int main() {
    using namespace geometry;
    Line l(Point(0, 0), Point(1, 0));
    Point q = reflection(l, Point(2, 3));
    assert(equal(q.real(), 2) && equal(q.imag(), -3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `reflection(l,p)` | l に関して p と線対称な点。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

直線は異なる2点で表してください。内部で射影を計算するため、零長の方向ベクトルは使えません。浮動小数点演算なので、対称な点を再び反射しても元の座標とbit単位で一致するとは限りません。
