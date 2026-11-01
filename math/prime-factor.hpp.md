---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-NTL-1-A.test.cpp
    title: test/aoj/aoj-NTL-1-A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/number-theory.test.cpp
    title: test/mytest/math/number-theory.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime-factor.hpp\"\n\n#include <map>\n#include <type_traits>\n\
    \ntemplate <class T, std::enable_if_t<std::is_integral<T>::value, int> = 0>\n\
    std::map<T, int> prime_factor(T n) {\n    std::map<T, int> ret;\n    for(T i =\
    \ 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            int cnt = 0;\n\
    \            while(n % i == 0) {\n                n /= i;\n                cnt++;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if(n != 1) ret[n]\
    \ = 1;\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <map>\n#include <type_traits>\n\ntemplate <class\
    \ T, std::enable_if_t<std::is_integral<T>::value, int> = 0>\nstd::map<T, int>\
    \ prime_factor(T n) {\n    std::map<T, int> ret;\n    for(T i = 2; i * i <= n;\
    \ i++) {\n        if(n % i == 0) {\n            int cnt = 0;\n            while(n\
    \ % i == 0) {\n                n /= i;\n                cnt++;\n            }\n\
    \            ret[i] = cnt;\n        }\n    }\n    if(n != 1) ret[n] = 1;\n   \
    \ return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-factor.hpp
  requiredBy: []
  timestamp: '2023-12-05 16:32:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/math/number-theory.test.cpp
  - test/aoj/aoj-NTL-1-A.test.cpp
documentation_of: math/prime-factor.hpp
layout: document
title: "\u8A66\u3057\u5272\u308A\u306B\u3088\u308B\u7D20\u56E0\u6570\u5206\u89E3"
---

## このライブラリでできること

`prime_factor(n)` は、正整数 $n$ を $n=\prod_p p^{e_p}$ の形に分解し、素数 $p$ とその指数 $e_p$ を返します。返り値は map なので、素因数を小さい順に取り出せます。

小さい整数から試し割りし、割れる間は同じ値で割り続けます。残りの値の平方根まで試した時点で、残りが1より大きければそれ自身が素数です。異なる素因数の個数を $K$ とすると、時間の上界は $O(\sqrt n+K\log K)$ です。

## 使い方

例の $360=2^3\cdot3^2\cdot5$ に対して、キー $2,3,5$ にそれぞれ指数 $3,2,1$ が入ります。素因数を重複付きで並べる形式ではないので、個数が必要なときは map の値を参照してください。

```cpp
#include "template/template.cpp"
#include "math/prime-factor.hpp"

int main() {
    auto f = prime_factor(360LL);
    assert(f[2] == 3 && f[3] == 2 && f[5] == 1);
}
```

## API・計算量

必要な空間は $O(K)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `prime_factor(n)` | map<T,int>。n=1 なら空。 | O(sqrt(n)+K log K) |

## 利用条件と実装上の注意

入力は整数型の $n\ge1$ としてください。$n=1$ のときは空の map を返します。試し割りの条件に使う `i*i` がオーバーフローしない範囲で利用してください。大きな整数を大量に分解する場合は、篩による前処理も検討してください。
