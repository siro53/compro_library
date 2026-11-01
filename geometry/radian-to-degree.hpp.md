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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/geometry/geometry.test.cpp
    title: test/mytest/geometry/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/radian-to-degree.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/radian-to-degree.hpp\"\n\nnamespace\
    \ geometry {\n    // \u30E9\u30B8\u30A2\u30F3->\u5EA6\n    inline D radianToDegree(const\
    \ D &radian) { return radian * 180.0 / PI; }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u30E9\
    \u30B8\u30A2\u30F3->\u5EA6\n    inline D radianToDegree(const D &radian) { return\
    \ radian * 180.0 / PI; }\n} // namespace geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/radian-to-degree.hpp
  requiredBy:
  - geometry/geometry.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/radian-to-degree.hpp
layout: document
title: "\u30E9\u30B8\u30A2\u30F3\u304B\u3089\u5EA6"
---

## このライブラリでできること

`radianToDegree` は、ラジアンの角度を度数法へ変換します。角度 $\theta$ に対して $180\theta/\pi$ を計算します。三角関数などで得た角度を度で表示したい場合に使えます。

## 使い方

例の $\pi$ ラジアンは $180$ 度になります。$2\pi$ を渡せば $360$ が返り、0に正規化されるわけではありません。負の角度も符号を保って変換します。

```cpp
#include "template/template.cpp"
#include "geometry/radian-to-degree.hpp"

int main() {
    using namespace geometry;
    assert(equal(radianToDegree(PI), 180));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `radianToDegree(radian)` | radian*180/PI。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

浮動小数点演算のため、理論上整数の度数になる場合でも小さな誤差が生じ得ます。必要に応じて許容誤差で比較したり、表示時に丸めたりしてください。
