---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modint/dynamic-modint.hpp
    title: "\u52D5\u7684\u6CD5 modint"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-NTL-1-B-dynamic-modint.test.cpp
    title: test/aoj/aoj-NTL-1-B-dynamic-modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/arithmetic-regressions.test.cpp
    title: test/mytest/math/arithmetic-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/barrett-reduction.test.cpp
    title: test/mytest/math/barrett-reduction.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/modint/dynamic-modint.test.cpp
    title: test/mytest/modint/dynamic-modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/barrett-reduction.hpp\"\n\n#include <utility>\n\nclass\
    \ BarrettReduction {\npublic:\n    BarrettReduction(): BarrettReduction(1) {}\n\
    \    BarrettReduction(unsigned int m)\n        : m(m), m_inv((unsigned long long)(-1)\
    \ / m + 1) {}\n    unsigned int mul(unsigned int a, unsigned int b) const {\n\
    \        unsigned long long z = (unsigned long long)a * b;\n        unsigned long\
    \ long v =  (unsigned long long)(((__uint128_t)z * m_inv) >> 64);\n        unsigned\
    \ int result = (unsigned int)(z - v * m);\n        if(m <= result) result += m;\n\
    \        return result;\n    }\n    unsigned int quo(unsigned int a) const {\n\
    \        if(m == 1) return a;\n        unsigned int result = (unsigned int)(((__uint128_t)a\
    \ * m_inv) >> 64);\n        return result;\n    }\n    unsigned int rem(unsigned\
    \ long long a) const {\n        if(m == 1) return 0;\n        unsigned long long\
    \ v = (unsigned long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned\
    \ int result = (unsigned int)(a - v * m);\n        if(m <= result) result += m;\n\
    \        return result;\n    }\n    std::pair<unsigned int, unsigned int> quorem(unsigned\
    \ int a) const {\n        if(m == 1) return {a, 0};\n        unsigned long long\
    \ v =  (unsigned long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned\
    \ int r = (unsigned int)((unsigned long long)a - v * m);\n        if(m <= r) r\
    \ += m;\n        return {v, r};\n    }\nprivate:\n    unsigned int m;\n    unsigned\
    \ long long m_inv;\n};\n"
  code: "#pragma once\n\n#include <utility>\n\nclass BarrettReduction {\npublic:\n\
    \    BarrettReduction(): BarrettReduction(1) {}\n    BarrettReduction(unsigned\
    \ int m)\n        : m(m), m_inv((unsigned long long)(-1) / m + 1) {}\n    unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n        unsigned long long\
    \ z = (unsigned long long)a * b;\n        unsigned long long v =  (unsigned long\
    \ long)(((__uint128_t)z * m_inv) >> 64);\n        unsigned int result = (unsigned\
    \ int)(z - v * m);\n        if(m <= result) result += m;\n        return result;\n\
    \    }\n    unsigned int quo(unsigned int a) const {\n        if(m == 1) return\
    \ a;\n        unsigned int result = (unsigned int)(((__uint128_t)a * m_inv) >>\
    \ 64);\n        return result;\n    }\n    unsigned int rem(unsigned long long\
    \ a) const {\n        if(m == 1) return 0;\n        unsigned long long v = (unsigned\
    \ long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned int result = (unsigned\
    \ int)(a - v * m);\n        if(m <= result) result += m;\n        return result;\n\
    \    }\n    std::pair<unsigned int, unsigned int> quorem(unsigned int a) const\
    \ {\n        if(m == 1) return {a, 0};\n        unsigned long long v =  (unsigned\
    \ long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned int r = (unsigned\
    \ int)((unsigned long long)a - v * m);\n        if(m <= r) r += m;\n        return\
    \ {v, r};\n    }\nprivate:\n    unsigned int m;\n    unsigned long long m_inv;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/barrett-reduction.hpp
  requiredBy:
  - modint/dynamic-modint.hpp
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/modint/dynamic-modint.test.cpp
  - test/mytest/math/arithmetic-regressions.test.cpp
  - test/mytest/math/barrett-reduction.test.cpp
  - test/aoj/aoj-NTL-1-B-dynamic-modint.test.cpp
documentation_of: math/barrett-reduction.hpp
layout: document
title: Barrett Reduction
---

## このライブラリでできること

`BarrettReduction` は、同じ法 $m$ で何度も剰余を計算するためのクラスです。$m$ の逆数に相当する値を整数として前計算し、乗算とシフトで商を近似してから誤差を補正します。法が固定された剰余乗算の内部処理として使えます。

APIは、剰余乗算 `mul`、剰余 `rem`、商 `quo`、商と剰余の組 `quorem` に分かれています。いずれも固定長の整数演算を定数時間とした評価では $O(1)$ です。

## 使い方

まず `BarrettReduction br(m)` として法を指定します。例では $m=7$ なので、`mul(3,5)` は $15\bmod7=1$ を返し、`quorem(23)` は $23=3\cdot7+2$ に対応する組 $(3,2)$ を返します。

入力型が広いことと、その全範囲で補正が正しく動くことは別です。以下の利用範囲に収めて使ってください。

```cpp
#include "template/template.cpp"
#include "math/barrett-reduction.hpp"

int main() {
    BarrettReduction br(7);
    assert(br.mul(3, 5) == 1);
    auto [q, r] = br.quorem(23);
    assert(q == 3 && r == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BarrettReduction(m=1)` | 法と近似逆数を保持。 | O(1) |
| `mul(a, b)` | a*b mod m。 | O(1) |
| `rem(a)` | a mod m。 | O(1) |
| `quo(a)` | unsigned int の商 a/m。 | O(1) |
| `quorem(a)` | unsigned int の (商,剰余)。 | O(1) |

## 利用条件と実装上の注意

この実装の利用範囲は $1\le m<2^{31}$ とします。`mul(a,b)` は $0\le a,b<m$、`rem(a)` は $0\le a<m^2$ の範囲で利用してください。`quo/quorem` の入力型は unsigned int です。

$m=0$ は利用できません。デフォルトコンストラクタは法1を設定します。法1では商は入力そのもの、剰余は0です。この場合だけ rem(a) は unsigned long long の全域を受け付けます。128 bit整数拡張が必要です。
