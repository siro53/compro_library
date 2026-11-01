---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/fraction-api.test.cpp
    title: test/mytest/misc/fraction-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/fraction.test.cpp
    title: test/mytest/misc/fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/mo-and-fraction.test.cpp
    title: test/mytest/misc/mo-and-fraction.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/fraction.hpp\"\n\n#include <numeric>\n\ntemplate<typename\
    \ Int = long long>\nstruct Fraction {\n    using F = Fraction;\n    Int a, b;\n\
    \n    Fraction(): a(0), b(1) {}\n    Fraction(Int _a, Int _b): a(_a), b(_b) {\n\
    \        normalize();\n    }\n    Fraction(Int _a): a(_a), b(1) {}\n    inline\
    \ void normalize() {\n        Int g = Fraction::gcd(a, b);\n        a /= g;\n\
    \        b /= g;\n        if(b < 0) {\n            a = -a, b = -b;\n        }\n\
    \    }\n    F &operator+=(const F& f) {\n        Int na = a * f.b + b * f.a;\n\
    \        Int nb = b * f.b;\n        a = na, b = nb;\n        normalize();\n  \
    \      return *this;\n    }\n    F &operator-=(const F& f) {\n        Int na =\
    \ a * f.b - b * f.a;\n        Int nb = b * f.b;\n        a = na, b = nb;\n   \
    \     normalize();\n        return *this;\n    }\n    F &operator*=(const F& f)\
    \ {\n        a *= f.a;\n        b *= f.b;\n        normalize();\n        return\
    \ *this;\n    }\n    F &operator/=(const F& f) {\n        Int na = a * f.b;\n\
    \        Int nb = b * f.a;\n        a = na, b = nb;\n        normalize();\n  \
    \      return *this;\n    }\n    F operator-() const { return F(-a, b); }\n  \
    \  F operator+(const F& f) const { return F(*this) += f; }\n    F operator-(const\
    \ F& f) const { return F(*this) -= f; }\n    F operator*(const F& f) const { return\
    \ F(*this) *= f; }\n    F operator/(const F& f) const { return F(*this) /= f;\
    \ }\n    bool operator==(const F& f) const {\n        return a * f.b == b * f.a;\n\
    \    }\n    bool operator!=(const F& f) const {\n        return !(*this == f);\n\
    \    }\n    bool operator<(const F& f) const {\n        return a * f.b < b * f.a;\n\
    \    }\n    bool operator<=(const F& f) const {\n        return a * f.b <= b *\
    \ f.a;\n    }\n    bool operator>(const F& f) const {\n        return !(*this\
    \ <= f);\n    }\n    bool operator>=(const F& f) const {\n        return !(*this\
    \ < f);\n    }\n    \n    inline static Int gcd(Int a, Int b) {\n        Int s\
    \ = (a > 0 ? a : -a), t = (b > 0 ? b : -b);\n        while (s % t != 0) {\n  \
    \          Int u = s % t;\n            s = t;\n            t = u;\n        }\n\
    \        return t;\n    }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n\ntemplate<typename Int = long long>\n\
    struct Fraction {\n    using F = Fraction;\n    Int a, b;\n\n    Fraction(): a(0),\
    \ b(1) {}\n    Fraction(Int _a, Int _b): a(_a), b(_b) {\n        normalize();\n\
    \    }\n    Fraction(Int _a): a(_a), b(1) {}\n    inline void normalize() {\n\
    \        Int g = Fraction::gcd(a, b);\n        a /= g;\n        b /= g;\n    \
    \    if(b < 0) {\n            a = -a, b = -b;\n        }\n    }\n    F &operator+=(const\
    \ F& f) {\n        Int na = a * f.b + b * f.a;\n        Int nb = b * f.b;\n  \
    \      a = na, b = nb;\n        normalize();\n        return *this;\n    }\n \
    \   F &operator-=(const F& f) {\n        Int na = a * f.b - b * f.a;\n       \
    \ Int nb = b * f.b;\n        a = na, b = nb;\n        normalize();\n        return\
    \ *this;\n    }\n    F &operator*=(const F& f) {\n        a *= f.a;\n        b\
    \ *= f.b;\n        normalize();\n        return *this;\n    }\n    F &operator/=(const\
    \ F& f) {\n        Int na = a * f.b;\n        Int nb = b * f.a;\n        a = na,\
    \ b = nb;\n        normalize();\n        return *this;\n    }\n    F operator-()\
    \ const { return F(-a, b); }\n    F operator+(const F& f) const { return F(*this)\
    \ += f; }\n    F operator-(const F& f) const { return F(*this) -= f; }\n    F\
    \ operator*(const F& f) const { return F(*this) *= f; }\n    F operator/(const\
    \ F& f) const { return F(*this) /= f; }\n    bool operator==(const F& f) const\
    \ {\n        return a * f.b == b * f.a;\n    }\n    bool operator!=(const F& f)\
    \ const {\n        return !(*this == f);\n    }\n    bool operator<(const F& f)\
    \ const {\n        return a * f.b < b * f.a;\n    }\n    bool operator<=(const\
    \ F& f) const {\n        return a * f.b <= b * f.a;\n    }\n    bool operator>(const\
    \ F& f) const {\n        return !(*this <= f);\n    }\n    bool operator>=(const\
    \ F& f) const {\n        return !(*this < f);\n    }\n    \n    inline static\
    \ Int gcd(Int a, Int b) {\n        Int s = (a > 0 ? a : -a), t = (b > 0 ? b :\
    \ -b);\n        while (s % t != 0) {\n            Int u = s % t;\n           \
    \ s = t;\n            t = u;\n        }\n        return t;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/fraction.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/misc/fraction-api.test.cpp
  - test/mytest/misc/mo-and-fraction.test.cpp
  - test/mytest/misc/fraction.test.cpp
documentation_of: misc/fraction.hpp
layout: document
title: "\u6709\u7406\u6570"
---

## このライブラリでできること

`Fraction<Int>` は、有理数を分子 `a` と分母 `b` の組で保持します。演算のたびに最大公約数で約分し、分母を正にそろえるため、浮動小数点の丸めを使わずに分数を計算できます。

ただし、分子・分母は固定長の整数です。無限精度ではなく、演算中の積や和が `Int` の範囲に収まる場合に正確さが得られます。約分前の分子・分母の絶対値の最大値に1を加えたものを $M$ とすると、約分を伴う演算は $O(\log M)$ 時間です。

## 使い方

`Fraction(a,b)` で $a/b$、引数1つなら整数、引数なしなら $0$ を作ります。例の $1/3+1/6$ は約分され、分子 $1$・分母 $2$ になります。

比較では浮動小数点へ変換せず、分母が正であることを使って交差積を比較します。公開されている `a,b` を自分で変更した場合は、比較や演算の前に `normalize()` で表現をそろえてください。

```cpp
#include "template/template.cpp"
#include "misc/fraction.hpp"

int main() {
    Fraction<> a(1, 3), b(1, 6);
    auto c = a + b;
    assert(c.a == 1 && c.b == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Fraction(), Fraction(a), Fraction(a,b)` | 0、整数、約分した分数を作る。 | O(1)、O(1)、O(log M) |
| `normalize()` | 約分し分母の符号を正にする。 | O(log M) |
| `operator+, -, *, / と複合代入` | 四則演算して約分。 | O(log M) |
| `単項 operator-` | 符号反転して約分。 | O(log M) |
| `operator==, !=, <, <=, >, >=` | 交差積による大小比較。 | O(1) |
| `gcd(a,b)` | 絶対値の gcd を求める static 補助関数。 | O(log M) |

## 利用条件と実装上の注意

`f /= f` のように左辺と右辺が同じオブジェクトでも計算できます。非零の f を自身で割った結果は1です。

分母は非零とし、除算の右辺も0にしないでください。内部の `gcd(a,b)` は第2引数が0の場合を扱えません。

掛け算の前に約分して桁あふれを防ぐ実装ではありません。最終結果が小さくても、中間の分母の積や比較の交差積がオーバーフローする場合があります。絶対値を取る際の符号反転も含めて値域を確認してください。
