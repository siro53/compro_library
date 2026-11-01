---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: "NTT \u306B\u3088\u308B\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: test/library-checker/data-structure/point-set-range-composite.cpp
    title: test/library-checker/data-structure/point-set-range-composite.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
    title: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-affine-range-sum.test.cpp
    title: test/library-checker/data-structure/range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/arithmetic-regressions.test.cpp
    title: test/mytest/math/arithmetic-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/convolution-regressions.test.cpp
    title: test/mytest/math/convolution-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki117.test.cpp
    title: test/yukicoder/yuki117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki1750.test.cpp
    title: test/yukicoder/yuki1750.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint.hpp\"\n\n#include <istream>\n#include <ostream>\n\
    #include <utility>\n\ntemplate <int mod> class ModInt {\n  public:\n    ModInt()\
    \ : x(0) {}\n    ModInt(long long y)\n        : x(y >= 0 ? y % umod() : (umod()\
    \ - (-y) % umod()) % umod()) {}\n    unsigned int val() const { return x; }\n\
    \    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= umod()) x\
    \ -= umod();\n        return *this;\n    }\n    ModInt &operator-=(const ModInt\
    \ &p) {\n        if((x += umod() - p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n        x = (unsigned\
    \ int)(1ULL * x * p.x % umod());\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt\
    \ operator-() const { return ModInt(-(long long)x); }\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {\n        long long a = x, b = mod,\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n       \
    \ }\n        return ModInt(u);\n    }\n    ModInt pow(unsigned long long n) const\
    \ {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n            if(n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, ModInt &a) {\n        long long t;\n        is\
    \ >> t;\n        a = ModInt<mod>(t);\n        return (is);\n    }\n    static\
    \ constexpr int get_mod() { return mod; }\n\n  private:\n    unsigned int x;\n\
    \    static constexpr unsigned int umod() { return mod; }\n};\n"
  code: "#pragma once\n\n#include <istream>\n#include <ostream>\n#include <utility>\n\
    \ntemplate <int mod> class ModInt {\n  public:\n    ModInt() : x(0) {}\n    ModInt(long\
    \ long y)\n        : x(y >= 0 ? y % umod() : (umod() - (-y) % umod()) % umod())\
    \ {}\n    unsigned int val() const { return x; }\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator-=(const ModInt &p) {\n        if((x += umod()\
    \ - p.x) >= umod()) x -= umod();\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (unsigned int)(1ULL * x * p.x % umod());\n       \
    \ return *this;\n    }\n    ModInt &operator/=(const ModInt &p) {\n        *this\
    \ *= p.inv();\n        return *this;\n    }\n    ModInt operator-() const { return\
    \ ModInt(-(long long)x); }\n    ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n    ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n    ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n    ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n    bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n    bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \    ModInt inv() const {\n        long long a = x, b = mod, u = 1, v = 0, t;\n\
    \        while(b > 0) {\n            t = a / b;\n            std::swap(a -= t\
    \ * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n    ModInt pow(unsigned long long n) const {\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt &p) {\n        return\
    \ os << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, ModInt\
    \ &a) {\n        long long t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n    static constexpr int get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned int x;\n    static constexpr unsigned int umod()\
    \ { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint.hpp
  requiredBy:
  - math/convolution/ntt.hpp
  - test/library-checker/data-structure/point-set-range-composite.cpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki117.test.cpp
  - test/yukicoder/yuki1750.test.cpp
  - test/library-checker/convolution/convolution-mod.test.cpp
  - test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/range-affine-range-sum.test.cpp
  - test/mytest/math/convolution-regressions.test.cpp
  - test/mytest/math/arithmetic-regressions.test.cpp
documentation_of: modint/modint.hpp
layout: document
title: "\u56FA\u5B9A\u6CD5 modint"
---

## このライブラリでできること

`ModInt<mod>` は、整数を法 $m$ の剰余として扱う型です。加減乗算のたびに `% m` を書く代わりに、通常の算術演算子で計算できます。内部の値は原則として $0$ 以上 $m$ 未満に正規化され、`val()` で通常の整数として取り出せます。

剰余上の除算 $a/b$ は、$bc\equiv1\pmod m$ を満たす逆元 $c$ を求めて $ac$ を計算する操作です。逆元が存在する条件は $\gcd(b,m)=1$ であり、通常の整数除算とは意味が異なります。

## 使い方

法をテンプレート引数に指定します。例の `ModInt<998244353>` なら、同じ法の値を何個作っても型は同じです。整数からの構築で正規化されるので、負の整数も渡せます。

例では乗算、可逆な値による除算、累乗を確認しています。`pow(n)` は繰り返し二乗法で $n$ 乗を $O(\log(n+1))$ 時間で求めます。法が異なる値は異なる型になるため、そのまま演算することはできません。

```cpp
#include "template/template.cpp"
#include "modint/modint.hpp"

int main() {
    using mint = ModInt<998244353>;
    mint a = 3, b = 5;
    assert((a * b).val() == 15);
    assert((a / a).val() == 1);
    assert(a.pow(3).val() == 27);
}
```

## API・計算量

各値が使う空間は $O(1)$ です。法のbit幅に収まる固定長整数の演算を、定数時間として評価しています。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `コンストラクタ(), コンストラクタ(long long y)` | 0 または y mod m を保持。 | O(1) |
| `val(), get_mod()` | 正規化された値・法（get_mod は static）。 | O(1) |
| `operator+, -, *, +=, -=, *=` | 剰余の加減乗算。 | O(1) |
| `単項 operator-` | 加法逆元（動的版は注意点参照）。 | O(1) |
| `operator/, /=, inv()` | 除算・拡張 Euclid 法による逆元。 | O(log m) |
| `pow(n)` | n 乗。 | O(log(n+1)) |
| `operator==, !=` | 値の一致・不一致。 | O(1) |
| `operator<<, >>` | 正規化された値の出力・long long の入力。 | 数字の桁数に比例 |

## 利用条件と実装上の注意

法は正の int とし、`pow` の指数は非負にしてください。指数型は unsigned long long なので、負数を渡すと大きな正数へ変換されてしまいます。

`inv()` は可逆性を検査しません。法が素数でも0の逆元は存在しないため、除算前に条件を確認してください。コンストラクタは負数を符号反転するので、long long の最小値は渡さないでください。比較演算は正規化された値の一致を調べます。
