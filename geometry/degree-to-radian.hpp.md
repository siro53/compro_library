---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base.hpp
    title: "\u5E7E\u4F55\u306E\u57FA\u672C\u578B"
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
  bundledCode: "#line 2 \"geometry/degree-to-radian.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/degree-to-radian.hpp\"\n\nnamespace\
    \ geometry {\n    // \u5EA6->\u30E9\u30B8\u30A2\u30F3\n    inline D degreeToRadian(const\
    \ D &degree) { return degree * PI / 180.0; }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u5EA6\
    ->\u30E9\u30B8\u30A2\u30F3\n    inline D degreeToRadian(const D &degree) { return\
    \ degree * PI / 180.0; }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/degree-to-radian.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/degree-to-radian.hpp
layout: document
title: "\u5EA6\u304B\u3089\u30E9\u30B8\u30A2\u30F3"
---

## このライブラリでできること

`degreeToRadian` は、度数法の角度をラジアンへ変換します。$180$ 度が $\pi$ ラジアンなので、角度 $d$ に対して $d\pi/180$ を計算します。三角関数や回転関数へ、度で与えられた角度を渡す前に使えます。

## 使い方

例では $180$ 度を変換して `PI` と比較しています。$90$ 度なら $\pi/2$ です。角度の範囲を一周分へ丸める処理はないので、負の角度や $360$ 度以上の角度もそのまま比例変換します。

```cpp
#include "template/template.cpp"
#include "geometry/degree-to-radian.hpp"

int main() {
    using namespace geometry;
    assert(equal(degreeToRadian(180), PI));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `degreeToRadian(degree)` | degree*PI/180。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

返り値は浮動小数点値なので、厳密な等号で比較せず必要な許容誤差を使ってください。変換後の値を、度を受け取る関数へ再び渡さないよう単位をそろえます。
