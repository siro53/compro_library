---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: "\u5270\u4F59\u4ED8\u304D\u7D2F\u4E57"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C.test.cpp
    title: test/aoj/aoj-ALDS1-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/primality-test.test.cpp
    title: test/library-checker/math/primality-test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/is-prime.hpp\"\n\n#include <array>\n\n#line 2 \"math/pow_mod.hpp\"\
    \n\nconstexpr long long pow_mod(long long x, long long k, long long m) {\n   \
    \ long long res = 1;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n    while(k)\
    \ {\n        if(k & 1) res = (__int128_t)res * mul % m;\n        mul = (__int128_t)mul\
    \ * mul % m;\n        k >>= 1;\n    }\n    return res;\n}\n#line 6 \"math/is-prime.hpp\"\
    \n\n/*\nref: Fast Primality Testing for Integers That Fit into a Machine Word\n\
    Michal Fori\u02C7sek and Jakub Jan\u02C7cina\n*/\n\nconstexpr bool is_prime(int\
    \ n) {\n    if(n <= 1) return false;\n    if(n == 2 or n == 7 or n == 61) return\
    \ true;\n    if((n & 1) == 0) return false;\n    long long d = n - 1;\n    while((d\
    \ & 1) == 0) d >>= 1;\n    constexpr std::array<int, 3> bases = {2, 7, 61};\n\
    \    for(int a : bases) {\n        long long t = d;\n        long long y = pow_mod(a,\
    \ t, n);\n        while(t != n - 1 && y != 1 && y != n - 1) {\n            (y\
    \ *= y) %= n;\n            t <<= 1;\n        }\n        if(y != n - 1 && (t &\
    \ 1) == 0) return false;\n    }\n    return true;\n}\n\nconstexpr bool is_prime(long\
    \ long n) {\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if((n\
    \ & 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0)\
    \ d >>= 1;\n    constexpr std::array<long long, 7> bases = {\n        2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022\n    };\n    for(long long a : bases)\
    \ {\n        a %= n;\n        if(a == 0) continue;\n        long long t = d;\n\
    \        long long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 &&\
    \ y != n - 1) {\n            y = (__int128_t)y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return\
    \ true;\n}\n"
  code: "#pragma once\n\n#include <array>\n\n#include \"pow_mod.hpp\"\n\n/*\nref:\
    \ Fast Primality Testing for Integers That Fit into a Machine Word\nMichal Fori\u02C7\
    sek and Jakub Jan\u02C7cina\n*/\n\nconstexpr bool is_prime(int n) {\n    if(n\
    \ <= 1) return false;\n    if(n == 2 or n == 7 or n == 61) return true;\n    if((n\
    \ & 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0)\
    \ d >>= 1;\n    constexpr std::array<int, 3> bases = {2, 7, 61};\n    for(int\
    \ a : bases) {\n        long long t = d;\n        long long y = pow_mod(a, t,\
    \ n);\n        while(t != n - 1 && y != 1 && y != n - 1) {\n            (y *=\
    \ y) %= n;\n            t <<= 1;\n        }\n        if(y != n - 1 && (t & 1)\
    \ == 0) return false;\n    }\n    return true;\n}\n\nconstexpr bool is_prime(long\
    \ long n) {\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if((n\
    \ & 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0)\
    \ d >>= 1;\n    constexpr std::array<long long, 7> bases = {\n        2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022\n    };\n    for(long long a : bases)\
    \ {\n        a %= n;\n        if(a == 0) continue;\n        long long t = d;\n\
    \        long long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 &&\
    \ y != n - 1) {\n            y = (__int128_t)y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return\
    \ true;\n}"
  dependsOn:
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/is-prime.hpp
  requiredBy: []
  timestamp: '2023-10-01 12:06:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/math/primality-test.test.cpp
  - test/aoj/aoj-ALDS1-1-C.test.cpp
documentation_of: math/is-prime.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A"
---

## このライブラリでできること

`is_prime(n)` は、1つの整数が素数かどうかを判定します。上限までの表を作らないため、大きな値を少数だけ調べたい場合に適しています。$n\le1$ は素数ではないものとして `false` を返します。

判定には Miller–Rabin 法を使います。一般には底を乱択する方法ですが、この実装は引数型の範囲に対して十分な固定の底を使います。int版の底は $2,7,61$、long long版は $2,325,9375,28178,450775,9780504,1795265022$ です。したがって、対象の符号付き整数の範囲では確率的な判定ではなく決定的な判定になります。

## 使い方

整数を渡すと bool が返ります。大きな値を判定するときは、例の `1000000008LL` のように long long 型で渡してください。負数にも呼び出せますが、結果は常に偽です。

計算時間は、固定長整数の剰余乗算を定数時間とすると $O(\log n)$ です。アルゴリズムの根拠は後半の説明にまとめています。

```cpp
#include "template/template.cpp"
#include "math/is-prime.hpp"

int main() {
    assert(is_prime(998244353));
    assert(!is_prime(1000000008LL));
    assert(!is_prime(-3));
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `is_prime(int n)` | 符号付き 32 bit 整数の素数判定。 | O(log n)、n<=1 は O(1) |
| `is_prime(long long n)` | 符号付き 64 bit 整数の素数判定。 | O(log n)、n<=1 は O(1) |

## 利用条件と実装上の注意

対応するのは符号付き32 bitの int と符号付き64 bitの long long です。`unsigned long long` の全域を受け付けるAPIではありません。long long版では剰余乗算に128 bit整数拡張を使います。

多くの小さい数を同じ上限内で判定するなら、篩を一度作る方が適している場合があります。入力の大きさと判定回数に応じて使い分けてください。

## Miller–Rabin 法の判定条件

奇数 $n>2$ に対して、$n-1=2^s d$（$d$ は奇数）と分解します。底 $a$ を $1\le a<n$ から選び、まず $x=a^d\bmod n$ を求めます。次のいずれかが成り立てば、その底での検査は通過です。

- $a^d\equiv1\pmod n$ である。
- ある $0\le r<s$ について $a^{2^r d}\equiv-1\pmod n$ である。

$n$ が素数なら、これらの条件の少なくとも一方が必ず成り立ちます。したがって、両方とも成り立たない底が見つかれば、$n$ は確実に合成数です。一方、合成数でも特定の底について検査を通過する場合があるため、1つの底で通過したことだけから素数とは結論できません。

### 素数なら検査を通過する理由

法が素数 $p$ のとき、$x^2\equiv1\pmod p$ の解は $x\equiv\pm1\pmod p$ だけです。実際、$(x-1)(x+1)\equiv0\pmod p$ から、素数 $p$ はどちらかの因子を割り切ります。

また、$1\le a<p$ なら Fermat の小定理より $a^{p-1}\equiv1\pmod p$ です。$p-1=2^s d$ として、$a^d,a^{2d},\ldots,a^{2^s d}$ を順に考えます。最初が1なら第1条件を満たします。そうでなければ、この列で初めて1になる項の直前の項は、1以外の1の平方根なので $-1$ です。よって第2条件を満たします。

### 乱択版とこの実装の違い

奇数の合成数について、$1\le a<n$ から一様に選んだ底が検査を通過してしまう確率は高々 $1/4$ です。独立に $k$ 回選ぶ乱択版なら、すべての検査を誤って通過する確率は高々 $4^{-k}$ になります。

このライブラリは底を乱択せず、冒頭に示した固定の底を使います。その集合で十分な範囲に引数型を限定しているため、利用者が検査回数や許容誤り確率を設定するAPIではありません。
