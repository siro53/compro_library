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
    path: geometry/geometry.hpp
    title: "\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\uFF08\u307E\u3068\u3081\u3066\
      \ include\uFF09"
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
  bundledCode: "#line 2 \"geometry/unit-vector.hpp\"\n\n#line 2 \"geometry/base.hpp\"\
    \n\n#include <cmath>\n#include <complex>\n\nnamespace geometry {\n    // Point\
    \ : \u8907\u7D20\u6570\u578B\u3092\u4F4D\u7F6E\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u6271\u3046\n    // \u5B9F\u8EF8(real)\u3092x\u8EF8\u3001\u6319\u8EF8(imag)\u3092\
    y\u8EF8\u3068\u3057\u3066\u898B\u308B\n    using D = long double;\n    using Point\
    \ = std::complex<D>;\n    const D EPS = 1e-7;\n    const D PI = std::acos(D(-1));\n\
    \n    inline bool equal(const D &a, const D &b) { return std::fabs(a - b) < EPS;\
    \ }\n} // namespace geometry\n#line 4 \"geometry/unit-vector.hpp\"\n\nnamespace\
    \ geometry {\n    // \u5358\u4F4D\u30D9\u30AF\u30C8\u30EB(unit vector)\u3092\u6C42\
    \u3081\u308B\n    inline Point unitVector(const Point &a) { return a / std::abs(a);\
    \ }\n} // namespace geometry\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\nnamespace geometry {\n    // \u5358\
    \u4F4D\u30D9\u30AF\u30C8\u30EB(unit vector)\u3092\u6C42\u3081\u308B\n    inline\
    \ Point unitVector(const Point &a) { return a / std::abs(a); }\n} // namespace\
    \ geometry\n"
  dependsOn:
  - geometry/base.hpp
  isVerificationFile: false
  path: geometry/unit-vector.hpp
  requiredBy:
  - geometry/geometry.hpp
  - geometry/tangent-to-circle.hpp
  - geometry/cross-point.hpp
  - geometry/convex-cut.hpp
  - geometry/tangent.hpp
  timestamp: '2026-08-30 15:33:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/geometry/geometry-api.test.cpp
  - test/mytest/geometry/geometry.test.cpp
documentation_of: geometry/unit-vector.hpp
layout: document
title: "\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB"
---

## このライブラリでできること

`unitVector(a)` は、非零ベクトルの向きを保ちながら長さを1にします。式では $a/\lvert a\rvert$ です。向きだけを使って点を一定距離だけ動かしたい場合などに使えます。

## 使い方

例の $(3,4)$ は長さ $5$ なので、結果は $(3/5,4/5)$ となり、その長さは1です。点 $p$ から方向 $a$ に距離 $d$ 進む点は `p+unitVector(a)*d` と表せます。

```cpp
#include "template/template.cpp"
#include "geometry/unit-vector.hpp"

int main() {
    using namespace geometry;
    assert(equal(abs(unitVector(Point(3, 4))), 1));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `unitVector(a)` | a/abs(a)。 | O(1) |

## 利用条件と実装上の注意

型と関数は `geometry` 名前空間にあります。座標型 `D` は long double、`Point` は `complex<D>` です。実部を $x$ 座標、虚部を $y$ 座標として扱います。

零ベクトルは長さで割れないため渡せません。非常に短いベクトルを正規化すると、元の座標誤差が方向の大きな誤差になる場合もあります。入力が有効な方向を表していることを確認してください。
