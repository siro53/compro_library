---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: "NTT \u306B\u3088\u308B\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: "\u539F\u59CB\u6839"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C.test.cpp
    title: test/aoj/aoj-ALDS1-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/primality-test.test.cpp
    title: test/library-checker/math/primality-test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/pow_mod.hpp\"\n\nconstexpr long long pow_mod(long long\
    \ x, long long k, long long m) {\n    long long res = 1;\n    long long mul =\
    \ (x >= 0 ? x % m : x % m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res\
    \ * mul % m;\n        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n   \
    \ }\n    return res;\n}\n"
  code: "#pragma once\n\nconstexpr long long pow_mod(long long x, long long k, long\
    \ long m) {\n    long long res = 1;\n    long long mul = (x >= 0 ? x % m : x %\
    \ m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res * mul % m;\n\
    \        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n    }\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_mod.hpp
  requiredBy:
  - math/convolution/ntt.hpp
  - math/primitive-root.hpp
  - math/is-prime.hpp
  timestamp: '2023-10-01 12:06:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/math/primality-test.test.cpp
  - test/library-checker/convolution/convolution-mod.test.cpp
  - test/aoj/aoj-ALDS1-1-C.test.cpp
documentation_of: math/pow_mod.hpp
layout: document
title: "\u5270\u4F59\u4ED8\u304D\u7D2F\u4E57"
---

## このライブラリでできること

`pow_mod(x,k,m)` は、$x^k$ を直接作らずに $m$ で割った余りを求めます。指数を二進数で見て、$x,x^2,x^4,\ldots$ のうち必要なものだけを掛ける繰り返し二乗法です。指数 $k$ に対して $O(\log(k+1))$ 時間で計算できます。

掛け算ごとに剰余を取るため、巨大な累乗そのものを保存しません。剰余同士の積には `__int128_t` を使い、long long の入力範囲で積を安全に扱います。

## 使い方

引数は底・指数・法の順です。例では $2^{10}\bmod1000=24$ と、負の底に対する $(-2)^3\bmod5=2$ を確認しています。負の底も非負の剰余に直して扱うため、通常は返り値が $[0,m)$ に入ります。

```cpp
#include "template/template.cpp"
#include "math/pow_mod.hpp"

int main() {
    assert(pow_mod(2, 10, 1000) == 24);
    assert(pow_mod(-2, 3, 5) == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `pow_mod(x, k, m)` | long long の剰余を返す。積には __int128_t を使う。 | O(log(k+1)) |

## 利用条件と実装上の注意

指数は $k\ge0$、法は $m>0$ としてください。負の指数から逆元を求める機能はありません。

例外として現実装は $k=0,m=1$ の場合にも $1$ を返します。数学的な剰余は $0$ なので、この組み合わせは呼び出し側で処理してください。128 bit整数を使うため、GCC/Clangの拡張を利用できる環境が必要です。
