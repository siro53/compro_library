---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: "3 \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geometry/dot.hpp
    title: "\u5185\u7A4D"
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
  bundledCode: "#line 2 \"geometry/is-convex.hpp\"\n\n#include <vector>\n\n#line 2\
    \ \"geometry/ccw.hpp\"\n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\
    \n\n#line 4 \"geometry/dot.hpp\"\n\nnamespace geometry {\n    // \u5185\u7A4D\
    (dot product) : a\u30FBb = |a||b|cos\u0398\n    inline D dot(const Point &a, const\
    \ Point &b) {\n        return (a.real() * b.real() + a.imag() * b.imag());\n \
    \   }\n} // namespace geometry\n#line 5 \"geometry/ccw.hpp\"\n\nnamespace geometry\
    \ {\n    // \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\n    // \u70B9a, b, c\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\u306B\u3064\u3044\u3066(a\u304C\u57FA\u6E96\u70B9)\n    inline\
    \ int ccw(const Point &a, Point b, Point c) {\n        b -= a, c -= a;\n     \
    \   // \u70B9a, b, c \u304C\n        // \u53CD\u6642\u8A08\u56DE\u308A\u306E\u6642\
    \u3001\n        if(cross(b, c) > EPS) return 1;\n        // \u6642\u8A08\u56DE\
    \u308A\u306E\u6642\u3001\n        if(cross(b, c) < -EPS) return -1;\n        //\
    \ c, a, b\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u3042\u308B\u6642\u3001\n        if(dot(b, c) < 0) return 2;\n        // a, b,\
    \ c\u304C\u3053\u306E\u9806\u756A\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308B\u5834\u5408\u3001\n        if(std::norm(b) < std::norm(c)) return -2;\n\
    \        // c\u304C\u7DDA\u5206ab\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\n\
    \        return 0;\n    }\n} // namespace geometry\n#line 6 \"geometry/is-convex.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u591A\u89D2\u5F62\u304B\u3069\u3046\u304B\
    \n    inline bool isConvex(const std::vector<Point> &p) {\n        int n = p.size();\n\
    \        int now, pre, nxt;\n        for(int i = 0; i < n; i++) {\n          \
    \  pre = (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n            now = i;\n\
    \            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n        }\n\
    \        return true;\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"ccw.hpp\"\n\nnamespace geometry\
    \ {\n    // \u51F8\u591A\u89D2\u5F62\u304B\u3069\u3046\u304B\n    inline bool\
    \ isConvex(const std::vector<Point> &p) {\n        int n = p.size();\n       \
    \ int now, pre, nxt;\n        for(int i = 0; i < n; i++) {\n            pre =\
    \ (i - 1 + n) % n;\n            nxt = (i + 1) % n;\n            now = i;\n   \
    \         if(ccw(p[pre], p[now], p[nxt]) == -1) return false;\n        }\n   \
    \     return true;\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/ccw.hpp
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  isVerificationFile: false
  path: geometry/is-convex.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/is-convex.hpp
layout: document
title: "\u51F8\u591A\u89D2\u5F62\u5224\u5B9A"
---

## このライブラリでできること

`isConvex(p)` は、多角形の境界をたどるときに右へ曲がる箇所がないかを調べます。反時計回りの単純多角形を前提にすると、これは凸であるための条件になります。頂点数を $N$ とすると計算時間は $O(N)$ です。

## 使い方

例では頂点を反時計回りに並べた正方形を渡しているため真になります。連続する3点が一直線上にあることは許すので、辺の途中に余分な頂点があっても、それだけで偽にはなりません。

```cpp
#include "template/template.cpp"
#include "geometry/is-convex.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{ {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(isConvex(p));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isConvex(p)` | 時計回りの曲がりがなければ true。 | O(N) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

3頂点以上の単純多角形を、反時計回りに並べて渡してください。時計回りの凸多角形は偽になり得ます。この関数は頂点数や自己交差を検査するものではないため、「任意の点列が正しい凸多角形か」を丸ごと検証する用途には使えません。
