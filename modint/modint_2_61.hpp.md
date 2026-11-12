---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/rolling_hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/monoids.test.cpp
    title: test/mytest/data-structure/monoids.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/modint/dynamic-modint.test.cpp
    title: test/mytest/modint/dynamic-modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/string/string-api.test.cpp
    title: test/mytest/string/string-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki2102.test.cpp
    title: test/yukicoder/yuki2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki430.test.cpp
    title: test/yukicoder/yuki430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"modint/modint_2_61.hpp\"\n\n#include <istream>\n#include\
    \ <utility>\n\n// \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u7528\
    \ modint\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\nclass ModInt_2_61\
    \ {\n  public:\n    using M = ModInt_2_61;\n    ModInt_2_61() : x(0) {}\n    ModInt_2_61(long\
    \ long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    unsigned long\
    \ long val() const { return x; }\n    M &operator+=(const M &m) {\n        if((x\
    \ += m.x) >= mod) x -= mod;\n        return *this;\n    }\n    M &operator-=(const\
    \ M &m) {\n        if((x += mod - m.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n    M &operator*=(const M &m) {\n        __uint128_t t = (__uint128_t)x\
    \ * m.x;\n        unsigned long long na = t >> 61;\n        unsigned long long\
    \ nb = t & mod;\n        if((na += nb) >= mod) na -= mod;\n        x = na;\n \
    \       return *this;\n    }\n    M &operator/=(const M &m) {\n        *this *=\
    \ m.inv();\n        return *this;\n    }\n    M operator-() const { return M(-(long\
    \ long)x); }\n    M operator+(const M &m) const { return M(*this) += m; }\n  \
    \  M operator-(const M &m) const { return M(*this) -= m; }\n    M operator*(const\
    \ M &m) const { return M(*this) *= m; }\n    M operator/(const M &m) const { return\
    \ M(*this) /= m; }\n    bool operator==(const M &m) const { return (x == m.x);\
    \ }\n    bool operator!=(const M &m) const { return (x != m.x); }\n    M inv()\
    \ const {\n        long long a = x, b = mod, u = 1, v = 0, t;\n        while(b\
    \ > 0) {\n            t = a / b;\n            std::swap(a -= t * b, b);\n    \
    \        std::swap(u -= t * v, v);\n        }\n        return M(u);\n    }\n \
    \   M pow(unsigned long long n) const {\n        M ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const M &p) {\n        return os << p.x;\n   \
    \ }\n    friend std::istream &operator>>(std::istream &is, M &a) {\n        long\
    \ long t;\n        is >> t;\n        a = M(t);\n        return (is);\n    }\n\
    \    static constexpr unsigned long long get_mod() { return mod; }\n\n  private:\n\
    \    unsigned long long x;\n    static constexpr unsigned long long mod = (1LL\
    \ << 61) - 1;\n};\n"
  code: "#pragma once\n\n#include <istream>\n#include <utility>\n\n// \u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u7528 modint\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class ModInt_2_61 {\n  public:\n    using M = ModInt_2_61;\n    ModInt_2_61()\
    \ : x(0) {}\n    ModInt_2_61(long long y) : x(y >= 0 ? y % mod : (mod - (-y) %\
    \ mod) % mod) {}\n    unsigned long long val() const { return x; }\n    M &operator+=(const\
    \ M &m) {\n        if((x += m.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &m) {\n        if((x += mod - m.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &m) {\n      \
    \  __uint128_t t = (__uint128_t)x * m.x;\n        unsigned long long na = t >>\
    \ 61;\n        unsigned long long nb = t & mod;\n        if((na += nb) >= mod)\
    \ na -= mod;\n        x = na;\n        return *this;\n    }\n    M &operator/=(const\
    \ M &m) {\n        *this *= m.inv();\n        return *this;\n    }\n    M operator-()\
    \ const { return M(-(long long)x); }\n    M operator+(const M &m) const { return\
    \ M(*this) += m; }\n    M operator-(const M &m) const { return M(*this) -= m;\
    \ }\n    M operator*(const M &m) const { return M(*this) *= m; }\n    M operator/(const\
    \ M &m) const { return M(*this) /= m; }\n    bool operator==(const M &m) const\
    \ { return (x == m.x); }\n    bool operator!=(const M &m) const { return (x !=\
    \ m.x); }\n    M inv() const {\n        long long a = x, b = mod, u = 1, v = 0,\
    \ t;\n        while(b > 0) {\n            t = a / b;\n            std::swap(a\
    \ -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ M(u);\n    }\n    M pow(unsigned long long n) const {\n        M ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const M &p) {\n        return os\
    \ << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, M &a)\
    \ {\n        long long t;\n        is >> t;\n        a = M(t);\n        return\
    \ (is);\n    }\n    static constexpr unsigned long long get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned long long x;\n    static constexpr unsigned long\
    \ long mod = (1LL << 61) - 1;\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint_2_61.hpp
  requiredBy:
  - string/rolling-hash.hpp
  - data-structure/monoid/rolling_hash.hpp
  timestamp: '2023-12-05 19:29:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/string/string-api.test.cpp
  - test/mytest/modint/dynamic-modint.test.cpp
  - test/mytest/data-structure/monoids.test.cpp
  - test/yukicoder/yuki2102.test.cpp
  - test/yukicoder/yuki430.test.cpp
documentation_of: modint/modint_2_61.hpp
layout: document
title: "\u6CD5 2^61-1 \u306E modint"
---

## このライブラリでできること

`ModInt_2_61` は、整数を法 $m$ の剰余として扱う型です。加減乗算のたびに `% m` を書く代わりに、通常の算術演算子で計算できます。内部の値は原則として $0$ 以上 $m$ 未満に正規化され、`val()` で通常の整数として取り出せます。

剰余上の除算 $a/b$ は、$bc\equiv1\pmod m$ を満たす逆元 $c$ を求めて $ac$ を計算する操作です。逆元が存在する条件は $\gcd(b,m)=1$ であり、通常の整数除算とは意味が異なります。

## 使い方

法は $m=2^{61}-1$ に固定されているため、型の引数や初期設定は不要です。ローリングハッシュなど、大きい法の剰余を高速に計算したい場合に使えます。積は128 bit整数で計算し、$2^{61}\equiv1\pmod m$ を使って剰余を取ります。

例では小さい値で基本演算を確認しています。`val()` の返り値は unsigned long long です。ハッシュ値の一致判定に使う場合も、ハッシュの衝突がなくなるわけではありません。

```cpp
#include "template/template.cpp"
#include "modint/modint_2_61.hpp"

int main() {
    using mint = ModInt_2_61;
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

逆元は非零の値に対してのみ求めてください。法は素数ですが、`inv(0)` を検査する処理はありません。`pow` の指数型は unsigned long long なので、負の指数は渡さないでください。

負数の正規化で符号反転するため、long long の最小値をコンストラクタに渡すことはできません。また、128 bit整数拡張を利用できるGCC/Clang系の環境が必要です。
