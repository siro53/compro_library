---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: "2 \u5186\u306E\u5171\u901A\u63A5\u7DDA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/rotate.hpp\"\n\n#line 2 \"geometry/base.hpp\"\n\
    \n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point :\
    \ \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/rotate.hpp\"\n\nnamespace geometry\
    \ {\n    // \u70B9p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Btheta\u5EA6\u56DE\
    \u8EE2\n    // theta\u306F\u30E9\u30B8\u30A2\u30F3\uFF01\uFF01\uFF01\n    inline\
    \ Point rotate(const Point &p, const D &theta) {\n        return Point(std::cos(theta)\
    \ * p.real() - std::sin(theta) * p.imag(),\n                     std::sin(theta)\
    \ * p.real() + std::cos(theta) * p.imag());\n    }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u70B9\
    p\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306Btheta\u5EA6\u56DE\u8EE2\n    // theta\u306F\
    \u30E9\u30B8\u30A2\u30F3\uFF01\uFF01\uFF01\n    inline Point rotate(const Point\
    \ &p, const D &theta) {\n        return Point(std::cos(theta) * p.real() - std::sin(theta)\
    \ * p.imag(),\n                     std::sin(theta) * p.real() + std::cos(theta)\
    \ * p.imag());\n    }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/rotate.hpp
  requiredBy:
  - geometry/tangent.hpp
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/rotate.hpp
layout: document
title: "\u70B9\u30FB\u30D9\u30AF\u30C8\u30EB\u306E\u56DE\u8EE2"
---

## このライブラリでできること

`rotate(p,theta)` は、原点を中心に点 $p$ を反時計回りへ $\theta$ ラジアン回転します。ベクトルの向きを変える操作としても使え、理論上は長さを保ちます。

座標 $(x,y)$ は $(x\cos\theta-y\sin\theta,\ x\sin\theta+y\cos\theta)$ に移ります。

## 使い方

例では $(1,0)$ を $\pi/2$ ラジアン、すなわち90度回転して $(0,1)$ に移しています。原点以外の点 $c$ の周りに回転したい場合は、`c+rotate(p-c,theta)` として一度中心を原点へ移してください。

```cpp
#include "template/template.cpp"
#include "geometry/rotate.hpp"

int main() {
    using namespace geometry;
    Point q = rotate(Point(1, 0), PI / 2);
    assert(equal(q.real(), 0) && equal(q.imag(), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `rotate(p,theta)` | theta ラジアンだけ反時計回りに回転した Point。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

角度の単位は度ではなくラジアンです。負の角度なら時計回りの回転になります。計算には三角関数を使うため、座標や長さには浮動小数点の誤差が入ります。
