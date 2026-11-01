---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/barrett-reduction.hpp
    title: Barrett Reduction
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc104/submissions/38888866
  bundledCode: "#line 2 \"modint/dynamic-modint.hpp\"\n\n#include <cassert>\n#include\
    \ <istream>\n#include <ostream>\n\n#line 2 \"math/barrett-reduction.hpp\"\n\n\
    #include <utility>\n\nclass BarrettReduction {\npublic:\n    BarrettReduction():\
    \ BarrettReduction(1) {}\n    BarrettReduction(unsigned int m)\n        : m(m),\
    \ m_inv((unsigned long long)(-1) / m + 1) {}\n    unsigned int mul(unsigned int\
    \ a, unsigned int b) const {\n        unsigned long long z = (unsigned long long)a\
    \ * b;\n        unsigned long long v =  (unsigned long long)(((__uint128_t)z *\
    \ m_inv) >> 64);\n        unsigned int result = (unsigned int)(z - v * m);\n \
    \       if(m <= result) result += m;\n        return result;\n    }\n    unsigned\
    \ int quo(unsigned int a) const {\n        unsigned int result = (unsigned int)(((__uint128_t)a\
    \ * m_inv) >> 64);\n        return result;\n    }\n    unsigned int rem(unsigned\
    \ long long a) const {\n        unsigned long long v = (unsigned long long)(((__uint128_t)a\
    \ * m_inv) >> 64);\n        unsigned int result = (unsigned int)(a - v * m);\n\
    \        if(m <= result) result += m;\n        return result;\n    }\n    std::pair<unsigned\
    \ int, unsigned int> quorem(unsigned int a) const {\n        unsigned long long\
    \ v =  (unsigned long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned\
    \ int r = (unsigned int)((unsigned long long)a - v * m);\n        if(m <= r) r\
    \ += m;\n        return {v, r};\n    }\nprivate:\n    unsigned int m;\n    unsigned\
    \ long long m_inv;\n};\n#line 8 \"modint/dynamic-modint.hpp\"\n\n// verify: https://atcoder.jp/contests/arc104/submissions/38888866\n\
    class DynamicModInt {\n  public:\n    DynamicModInt() : x(0) {}\n    DynamicModInt(long\
    \ long y)\n        : x(y >= 0\n                ? y % (long long)mod\n        \
    \        : ((long long)mod - (-y) % (long long)mod) % (long long)mod) {}\n   \
    \ static void set_mod(unsigned int m) {\n        assert(m > 0);\n        mod =\
    \ m;\n        bt = BarrettReduction(m);\n    }\n    unsigned int val() const {\
    \ return x; }\n    DynamicModInt &operator+=(const DynamicModInt &p) {\n     \
    \   if((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n    DynamicModInt\
    \ &operator-=(const DynamicModInt &p) {\n        if((x += (mod - p.x)) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n    DynamicModInt &operator*=(const\
    \ DynamicModInt &p) {\n        x = bt.mul(x, p.x);\n        return *this;\n  \
    \  }\n    DynamicModInt &operator/=(const DynamicModInt &p) {\n        *this *=\
    \ p.inv();\n        return *this;\n    }\n    DynamicModInt operator-() const\
    \ { return DynamicModInt(-x); }\n    DynamicModInt operator+(const DynamicModInt\
    \ &p) const {\n        return DynamicModInt(*this) += p;\n    }\n    DynamicModInt\
    \ operator-(const DynamicModInt &p) const {\n        return DynamicModInt(*this)\
    \ -= p;\n    }\n    DynamicModInt operator*(const DynamicModInt &p) const {\n\
    \        return DynamicModInt(*this) *= p;\n    }\n    DynamicModInt operator/(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) /= p;\n    }\n\
    \    bool operator==(const DynamicModInt &p) const { return x == p.x; }\n    bool\
    \ operator!=(const DynamicModInt &p) const { return x != p.x; }\n    DynamicModInt\
    \ inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b\
    \ > 0) {\n            t = a / b;\n            std::swap(a -= t * b, b);\n    \
    \        std::swap(u -= t * v, v);\n        }\n        assert(a == 1 && \"gcd(x,\
    \ mod) must be '1'.\");\n        return DynamicModInt(u);\n    }\n    DynamicModInt\
    \ pow(long long n) const {\n        assert(n >= 0);\n        DynamicModInt ret(1),\
    \ mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n       \
    \     mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &p)\
    \ {\n        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModInt &a) {\n        long long t;\n        is >> t;\n        a\
    \ = DynamicModInt(t);\n        return (is);\n    }\n    static unsigned int get_mod()\
    \ { return mod; }\n\n  private:\n    unsigned int x;\n    static inline unsigned\
    \ int mod;\n    static inline BarrettReduction bt;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <istream>\n#include <ostream>\n\
    \n#include \"../math/barrett-reduction.hpp\"\n\n// verify: https://atcoder.jp/contests/arc104/submissions/38888866\n\
    class DynamicModInt {\n  public:\n    DynamicModInt() : x(0) {}\n    DynamicModInt(long\
    \ long y)\n        : x(y >= 0\n                ? y % (long long)mod\n        \
    \        : ((long long)mod - (-y) % (long long)mod) % (long long)mod) {}\n   \
    \ static void set_mod(unsigned int m) {\n        assert(m > 0);\n        mod =\
    \ m;\n        bt = BarrettReduction(m);\n    }\n    unsigned int val() const {\
    \ return x; }\n    DynamicModInt &operator+=(const DynamicModInt &p) {\n     \
    \   if((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n    DynamicModInt\
    \ &operator-=(const DynamicModInt &p) {\n        if((x += (mod - p.x)) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n    DynamicModInt &operator*=(const\
    \ DynamicModInt &p) {\n        x = bt.mul(x, p.x);\n        return *this;\n  \
    \  }\n    DynamicModInt &operator/=(const DynamicModInt &p) {\n        *this *=\
    \ p.inv();\n        return *this;\n    }\n    DynamicModInt operator-() const\
    \ { return DynamicModInt(-x); }\n    DynamicModInt operator+(const DynamicModInt\
    \ &p) const {\n        return DynamicModInt(*this) += p;\n    }\n    DynamicModInt\
    \ operator-(const DynamicModInt &p) const {\n        return DynamicModInt(*this)\
    \ -= p;\n    }\n    DynamicModInt operator*(const DynamicModInt &p) const {\n\
    \        return DynamicModInt(*this) *= p;\n    }\n    DynamicModInt operator/(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) /= p;\n    }\n\
    \    bool operator==(const DynamicModInt &p) const { return x == p.x; }\n    bool\
    \ operator!=(const DynamicModInt &p) const { return x != p.x; }\n    DynamicModInt\
    \ inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b\
    \ > 0) {\n            t = a / b;\n            std::swap(a -= t * b, b);\n    \
    \        std::swap(u -= t * v, v);\n        }\n        assert(a == 1 && \"gcd(x,\
    \ mod) must be '1'.\");\n        return DynamicModInt(u);\n    }\n    DynamicModInt\
    \ pow(long long n) const {\n        assert(n >= 0);\n        DynamicModInt ret(1),\
    \ mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n       \
    \     mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &p)\
    \ {\n        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModInt &a) {\n        long long t;\n        is >> t;\n        a\
    \ = DynamicModInt(t);\n        return (is);\n    }\n    static unsigned int get_mod()\
    \ { return mod; }\n\n  private:\n    unsigned int x;\n    static inline unsigned\
    \ int mod;\n    static inline BarrettReduction bt;\n};"
  dependsOn:
  - math/barrett-reduction.hpp
  isVerificationFile: false
  path: modint/dynamic-modint.hpp
  requiredBy: []
  timestamp: '2023-10-01 12:14:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/dynamic-modint.hpp
layout: document
title: "\u52D5\u7684\u6CD5 modint"
---

## このライブラリでできること

`DynamicModInt` は、整数を法 $m$ の剰余として扱う型です。加減乗算のたびに `% m` を書く代わりに、通常の算術演算子で計算できます。内部の値は原則として $0$ 以上 $m$ 未満に正規化され、`val()` で通常の整数として取り出せます。

剰余上の除算 $a/b$ は、$bc\equiv1\pmod m$ を満たす逆元 $c$ を求めて $ac$ を計算する操作です。逆元が存在する条件は $\gcd(b,m)=1$ であり、通常の整数除算とは意味が異なります。

## 使い方

最初に `set_mod(m)` を呼ぶと、その後に作る値が法 $m$ で計算されます。入力として法が与えられるなど、コンパイル時には法が決まらない問題で使います。例では法を設定した後、通常の modint と同じ形で演算しています。

法はオブジェクトごとではなく、すべての `DynamicModInt` で共有されます。別の法を設定しても既存の値は変換されないため、値が残っている間に法を変えないでください。

```cpp
#include "template/template.cpp"
#include "modint/dynamic-modint.hpp"

int main() {
    using mint = DynamicModInt;
    mint::set_mod(998244353);
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
| `set_mod(m)` | 全インスタンス共通の法を設定。 | O(1) |

## 利用条件と実装上の注意

法は $2\le m<2^{31}$ の範囲で使用してください。乗算には `BarrettReduction`、逆元には int を使った拡張Euclid法を利用します。除算は除数と法が互いに素なときだけ可能です。

現実装の単項マイナス `-x` は、内部の unsigned int のまま符号反転するため、意図した加法逆元にならない場合があります。代わりに `DynamicModInt(0)-x` を使ってください。

`pow` は非負の long long 指数を受け取ります。コンストラクタには long long の最小値を渡さず、最初の値の構築前に必ず `set_mod` を実行してください。
