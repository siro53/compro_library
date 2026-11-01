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
  bundledCode: "#line 2 \"geometry/is-contained.hpp\"\n\n#include <vector>\n\n#line\
    \ 2 \"geometry/cross.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\n#include <cmath>\n\
    #include <complex>\n\nnamespace geometry {\n    // Point : \u8907\u7D20\u6570\u578B\
    \u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3046\n   \
    \ // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092y\u8EF8\u3068\
    \u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point = std::complex<D>;\n\
    \    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\n    inline bool\
    \ equal(const D &a, const D &b) { return std::fabs(a - b) < EPS; }\n} // namespace\
    \ geometry\n#line 4 \"geometry/cross.hpp\"\n\nnamespace geometry {\n    // \u5916\
    \u7A4D(cross product) : a\xD7b = |a||b|sin\u0398\n    inline D cross(const Point\
    \ &a, const Point &b) {\n        return (a.real() * b.imag() - a.imag() * b.real());\n\
    \    }\n} // namespace geometry\n#line 2 \"geometry/dot.hpp\"\n\n#line 4 \"geometry/dot.hpp\"\
    \n\nnamespace geometry {\n    // \u5185\u7A4D(dot product) : a\u30FBb = |a||b|cos\u0398\
    \n    inline D dot(const Point &a, const Point &b) {\n        return (a.real()\
    \ * b.real() + a.imag() * b.imag());\n    }\n} // namespace geometry\n#line 7\
    \ \"geometry/is-contained.hpp\"\n\nnamespace geometry {\n    // \u591A\u89D2\u5F62\
    g\u306B\u70B9p\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B?\n    // \u542B\
    \u307E\u308C\u308B:2, \u8FBA\u4E0A\u306B\u3042\u308B:1, \u542B\u307E\u308C\u306A\
    \u3044:0\n    inline int isContained(const std::vector<Point> &g, const Point\
    \ &p) {\n        bool in = false;\n        int n = (int)g.size();\n        for(int\
    \ i = 0; i < n; i++) {\n            Point a = g[i] - p, b = g[(i + 1) % n] - p;\n\
    \            if(imag(a) > imag(b)) swap(a, b);\n            if(imag(a) <= EPS\
    \ && EPS < imag(b) && cross(a, b) < -EPS) in = !in;\n            if(cross(a, b)\
    \ == 0 && dot(a, b) <= 0) return 1;\n        }\n        return (in ? 2 : 0);\n\
    \    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"cross.hpp\"\n#include \"\
    dot.hpp\"\n\nnamespace geometry {\n    // \u591A\u89D2\u5F62g\u306B\u70B9p\u304C\
    \u542B\u307E\u308C\u3066\u3044\u308B\u304B?\n    // \u542B\u307E\u308C\u308B:2,\
    \ \u8FBA\u4E0A\u306B\u3042\u308B:1, \u542B\u307E\u308C\u306A\u3044:0\n    inline\
    \ int isContained(const std::vector<Point> &g, const Point &p) {\n        bool\
    \ in = false;\n        int n = (int)g.size();\n        for(int i = 0; i < n; i++)\
    \ {\n            Point a = g[i] - p, b = g[(i + 1) % n] - p;\n            if(imag(a)\
    \ > imag(b)) swap(a, b);\n            if(imag(a) <= EPS && EPS < imag(b) && cross(a,\
    \ b) < -EPS) in = !in;\n            if(cross(a, b) == 0 && dot(a, b) <= 0) return\
    \ 1;\n        }\n        return (in ? 2 : 0);\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/cross.hpp
  - geometry/base.hpp
  - geometry/dot.hpp
  isVerificationFile: false
  path: geometry/is-contained.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
  - test/mytest/geometry/geometry-api.test.cpp
documentation_of: geometry/is-contained.hpp
layout: document
title: "\u591A\u89D2\u5F62\u3078\u306E\u5305\u542B\u5224\u5B9A"
---

## このライブラリでできること

`isContained(g,p)` は、点と単純多角形の位置関係を調べ、内部なら2、辺上なら1、外部なら0を返します。凸多角形である必要はなく、凹んだ形も扱えます。頂点数を $N$ とすると、辺を一周する $O(N)$ 時間です。

点から伸ばした半直線が境界を横切る回数の偶奇によって内外を区別し、同時に点が辺上にあるかを確認します。

## 使い方

多角形の頂点は境界に沿った順に渡します。例の正方形の中心 $(1,1)$ は内部なので2です。先頭の頂点を末尾へ重ねて追加する必要はありません。

```cpp
#include "template/template.cpp"
#include "geometry/is-contained.hpp"

int main() {
    using namespace geometry;
    vector<Point> p{ {0, 0}, {2, 0}, {2, 2}, {0, 2}};
    assert(isContained(p, Point(1, 1)) == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `isContained(g,p)` | 内部 2、辺上 1、外部 0。 | O(N) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

自己交差しない多角形を渡してください。内部判定にはEPSを使う箇所がありますが、辺上の判定では外積を `==0` で比較しています。そのため、丸め誤差を含む点が数学的には辺上でも、必ず1に分類されるとは限りません。
