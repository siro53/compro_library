---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  - icon: ':heavy_check_mark:'
    path: geometry/cross.hpp
    title: "\u5916\u7A4D"
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
  bundledCode: "#line 2 \"geometry/convex-hull.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\n#line 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point :\
    \ \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry\
    \ {\n    // \u5916\u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline\
    \ D cross(const Point &a, const Point &b) {\n        return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n    }\n} // namespace geometry\n#line 7 \"geometry/convex-hull.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u5305 O(NlogN)\n    inline std::vector<Point>\
    \ ConvexHull(std::vector<Point> p) {\n        int n = (int)p.size(), k = 0;\n\
    \        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {\n\
    \            return (a.real() != b.real() ? a.real() < b.real()\n            \
    \                             : a.imag() < b.imag());\n        });\n        p.erase(std::unique(p.begin(),\
    \ p.end()), p.end());\n        n = (int)p.size();\n        if(n <= 1) return p;\n\
    \        std::vector<Point> ch(2 * n);\n        // \u4E00\u76F4\u7DDA\u4E0A\u306E\
    3\u70B9\u3092\u542B\u3081\u308B -> (< -EPS)\n        // \u542B\u3081\u7121\u3044\
    \ -> (< EPS)\n        for(int i = 0; i < n; ch[k++] = p[i++]) { // lower\n   \
    \         while(k >= 2 &&\n                  cross(ch[k - 1] - ch[k - 2], p[i]\
    \ - ch[k - 1]) < EPS)\n                --k;\n        }\n        for(int i = n\
    \ - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) { // upper\n            while(k >=\
    \ t &&\n                  cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n\
    \                --k;\n        }\n        ch.resize(k - 1);\n        return ch;\n\
    \    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"cross.hpp\"\
    \n\nnamespace geometry {\n    // \u51F8\u5305 O(NlogN)\n    inline std::vector<Point>\
    \ ConvexHull(std::vector<Point> p) {\n        int n = (int)p.size(), k = 0;\n\
    \        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {\n\
    \            return (a.real() != b.real() ? a.real() < b.real()\n            \
    \                             : a.imag() < b.imag());\n        });\n        p.erase(std::unique(p.begin(),\
    \ p.end()), p.end());\n        n = (int)p.size();\n        if(n <= 1) return p;\n\
    \        std::vector<Point> ch(2 * n);\n        // \u4E00\u76F4\u7DDA\u4E0A\u306E\
    3\u70B9\u3092\u542B\u3081\u308B -> (< -EPS)\n        // \u542B\u3081\u7121\u3044\
    \ -> (< EPS)\n        for(int i = 0; i < n; ch[k++] = p[i++]) { // lower\n   \
    \         while(k >= 2 &&\n                  cross(ch[k - 1] - ch[k - 2], p[i]\
    \ - ch[k - 1]) < EPS)\n                --k;\n        }\n        for(int i = n\
    \ - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) { // upper\n            while(k >=\
    \ t &&\n                  cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)\n\
    \                --k;\n        }\n        ch.resize(k - 1);\n        return ch;\n\
    \    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/convex-hull.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/convex-hull.hpp
layout: document
title: "\u51F8\u5305"
---

## このライブラリでできること

`ConvexHull(p)` は、点集合をすべて含む最小の凸な領域の境界を求めます。点に輪ゴムを掛けて外側から張ったときの形が凸包です。入力点数を $N$ とすると、ソートを含めて $O(N\log N)$ 時間です。

実装は点を座標順に並べ、下側と上側の境界をそれぞれ作る単調鎖法です。凸性を保たなくなる途中の点を取り除きながら進めます。

## 使い方

点は周回順でなくても構いません。例では正方形の4頂点と中心を渡し、境界の4頂点だけを得ています。結果は反時計回りで、始点は $x$、次に $y$ の辞書順で最小の点です。末尾に始点は重ねません。

この実装では、一直線上にある辺の途中の点を除きます。境界上の入力点をすべて列挙する関数ではありません。

```cpp
#include "template/template.cpp"
#include "geometry/convex-hull.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{ {0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 1}};
    auto hull = ConvexHull(p);
    assert(hull.size() == 4);
}
```

## API・計算量

入力のコピー、ソート、結果の保持に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ConvexHull(p)` | 凸包の頂点列を反時計回りで返す。 | O(N log N) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

座標が厳密に一致する重複点は内部で取り除きます。空入力には空の配列、異なる点が1個だけならその1点を返します。

向きの判定にEPSを使うので、ほぼ一直線上の点は削除される場合があります。すべての点が一直線上なら、通常は両端の2点が結果になります。
