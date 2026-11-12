---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: "\u5270\u4F59\u4ED8\u304D\u7D2F\u4E57"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: "NTT \u306B\u3088\u308B\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/convolution-regressions.test.cpp
    title: test/mytest/math/convolution-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/number-theory.test.cpp
    title: test/mytest/math/number-theory.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/transforms-api.test.cpp
    title: test/mytest/math/transforms-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/primitive-root.hpp\"\n\n#line 2 \"math/pow_mod.hpp\"\
    \n\nconstexpr long long pow_mod(long long x, long long k, long long m) {\n   \
    \ long long res = 1 % m;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n\
    \    while(k) {\n        if(k & 1) res = (__int128_t)res * mul % m;\n        mul\
    \ = (__int128_t)mul * mul % m;\n        k >>= 1;\n    }\n    return res;\n}\n\
    #line 4 \"math/primitive-root.hpp\"\n\nconstexpr int primitive_root(int p) {\n\
    \    if(p == 2) return 1;\n    if(p == 998244353) return 3;\n    int primes[31]\
    \ = {};\n    int sz = 0, t = p - 1;\n    for(int i = 2; i * i <= t; i++) {\n \
    \       if(t % i == 0) {\n            primes[sz++] = i;\n            while(t %\
    \ i == 0) t /= i;\n        }\n    }\n    if(t > 1) primes[sz++] = t;\n    for(int\
    \ g = 2;;g++) {\n        bool f = true;\n        for(int i = 0; i < sz; i++) {\n\
    \            if(pow_mod(g, (p - 1) / primes[i], p) == 1) {\n                f\
    \ = false;\n                break;\n            }\n        }   \n        if(f)\
    \ return g;\n    }\n}\n"
  code: "#pragma once\n\n#include \"pow_mod.hpp\"\n\nconstexpr int primitive_root(int\
    \ p) {\n    if(p == 2) return 1;\n    if(p == 998244353) return 3;\n    int primes[31]\
    \ = {};\n    int sz = 0, t = p - 1;\n    for(int i = 2; i * i <= t; i++) {\n \
    \       if(t % i == 0) {\n            primes[sz++] = i;\n            while(t %\
    \ i == 0) t /= i;\n        }\n    }\n    if(t > 1) primes[sz++] = t;\n    for(int\
    \ g = 2;;g++) {\n        bool f = true;\n        for(int i = 0; i < sz; i++) {\n\
    \            if(pow_mod(g, (p - 1) / primes[i], p) == 1) {\n                f\
    \ = false;\n                break;\n            }\n        }   \n        if(f)\
    \ return g;\n    }\n}"
  dependsOn:
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/primitive-root.hpp
  requiredBy:
  - math/convolution/ntt.hpp
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/math/convolution-regressions.test.cpp
  - test/mytest/math/number-theory.test.cpp
  - test/mytest/math/transforms-api.test.cpp
  - test/library-checker/convolution/convolution-mod.test.cpp
documentation_of: math/primitive-root.hpp
layout: document
title: "\u539F\u59CB\u6839"
---

## このライブラリでできること

`primitive_root(p)` は、素数 $p$ を法として、$0$ 以外のすべての剰余を累乗で生成できる整数を1つ求めます。すなわち、返り値 $g$ の位数が $p-1$ となり、$g^0,g^1,\ldots,g^{p-2}$ が相異なる非零剰余になります。数論変換の1の原始根を作る場合などに使います。

$p-1$ の異なる素因数を $q$ とすると、候補 $g$ が原始根であるための条件は、すべての $q$ に対して $g^{(p-1)/q}\not\equiv1\pmod p$ となることです。この実装は試し割りで素因数を集め、候補を小さい方から検査します。

## 使い方

素数を渡すと原始根を整数で返します。例では $p=17$ に対する原始根 $3$ を取得しています。$p=2$ と $p=998244353$ は特別扱いで、それぞれ $1,3$ を返します。

表の $G$ は試した候補数、$K$ は $p-1$ の異なる素因数の個数です。候補を定数個試せば必ず見つかると仮定した計算量ではありません。

```cpp
#include "template/template.cpp"
#include "math/primitive-root.hpp"

int main() {
    assert(primitive_root(17) == 3);
}
```

## API・計算量

素因数を保持する配列は固定長なので、追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `primitive_root(p)` | 1<=g<p の原始根。p=2 は 1、998244353 は 3。 | O(sqrt(p)+G K log p)、G は検査候補数、K は p-1 の異なる素因数数 |

## 利用条件と実装上の注意

入力が素数であることを呼び出し側で保証してください。この関数自身は素数判定をしません。

入力型は int です。試し割りの `i*i` も int で評価するため、int の上限付近では中間積がオーバーフローする可能性があります。扱う値が型に収まることだけでは十分ではありません。
