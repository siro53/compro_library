---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C.test.cpp
    title: test/aoj/aoj-ALDS1-1-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/is-prime.hpp\"\n\n#include <array>\n\n#line 2 \"math/pow_mod.hpp\"\
    \n\nconstexpr long long pow_mod(long long x, long long k, int m) {\n    unsigned\
    \ int mod = m;\n    unsigned long long res = 1;\n    unsigned long long mul =\
    \ (x >= 0 ? x % mod : x % mod + mod);\n    while(k) {\n        if(k & 1) (res\
    \ *= mul) %= m;\n        (mul *= mul) %= m;\n        k >>= 1;\n    }\n    return\
    \ res;\n}\n#line 6 \"math/is-prime.hpp\"\n\n/*\nref: Fast Primality Testing for\
    \ Integers That Fit into a Machine Word\nMichal Fori\u02C7sek and Jakub Jan\u02C7\
    cina\n*/\n\nconstexpr bool is_prime(int n) {\n    if(n <= 1) return false;\n \
    \   if(n == 2 or n == 7 or n == 61) return true;\n    if((n & 1) == 0) return\
    \ false;\n    long long d = n - 1;\n    while((d & 1) == 0) d >>= 1;\n    constexpr\
    \ std::array<int, 3> bases = {2, 7, 61};\n    for(int a : bases) {\n        long\
    \ long t = d;\n        long long y = pow_mod(a, t, n);\n        while(t != n -\
    \ 1 && y != 1 && y != n - 1) {\n            (y *= y) %= n;\n            t <<=\
    \ 1;\n        }\n        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n\
    \    return true;\n}\n\nconstexpr bool is_prime(long long n) {\n    if(n <= 1)\
    \ return false;\n    if(n == 2 or n == 3 or n == 5 or n == 7 or n == 11 or n ==\
    \ 13 or n == 17 or\n       n == 19 or n == 23 or n == 29 or n == 31 or n == 37)\n\
    \        return true;\n    if((n & 1) == 0) return false;\n    long long d = n\
    \ - 1;\n    while((d & 1) == 0) d >>= 1;\n    constexpr std::array<int, 12> bases\
    \ = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,\n    };\n    for(int\
    \ a : bases) {\n        long long t = d;\n        long long y = pow_mod(a, t,\
    \ n);\n        while(t != n - 1 && y != 1 && y != n - 1) {\n            y = (__int128_t)y\
    \ * y % n;\n            t <<= 1;\n        }\n        if(y != n - 1 && (t & 1)\
    \ == 0) return false;\n    }\n    return true;\n}\n"
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
    \ long n) {\n    if(n <= 1) return false;\n    if(n == 2 or n == 3 or n == 5 or\
    \ n == 7 or n == 11 or n == 13 or n == 17 or\n       n == 19 or n == 23 or n ==\
    \ 29 or n == 31 or n == 37)\n        return true;\n    if((n & 1) == 0) return\
    \ false;\n    long long d = n - 1;\n    while((d & 1) == 0) d >>= 1;\n    constexpr\
    \ std::array<int, 12> bases = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37,\n    };\n    for(int a : bases) {\n        long long t = d;\n        long\
    \ long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 && y != n - 1)\
    \ {\n            y = (__int128_t)y * y % n;\n            t <<= 1;\n        }\n\
    \        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return true;\n\
    }"
  dependsOn:
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/is-prime.hpp
  requiredBy: []
  timestamp: '2023-09-29 00:04:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-1-C.test.cpp
documentation_of: math/is-prime.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A"
---

## Miller–Rabin 素数判定法

$p$ を奇素数とする。

### $1$ の平方根

$p$ を法とした剰余において、$1$ の平方根として $-1,1$ が存在する。逆に、$-1,1$ 以外に $1$ の平方根が存在しないこと背理法により示す。

$1$ の平方根を $x (\neq 1,-1) \pmod p$ とすると、

$\begin{aligned} x^2 &\equiv 1 \pmod p \\ (x-1)(x+1) &\equiv 0 \pmod p\end{aligned}$

$p$ は素数なので、$x+1,x-1$ のどちらか一方は必ず $p$ で割り切れる。
しかし、$x \neq 1,-1 \pmod p$ より $x+1,x-1$ は $p$ で割り切れない。よって矛盾が生じる。

以上より $\mathrm{mod}\space p$ において $1$ の平方根は $1, -1$ のみである。

### 強擬素数(strong pseudoprime)

$n$ を $3$ 以上の奇数とすると、奇数 $d$、正整数 $s$ を用いて $n-1 = d \cdot 2^s$ と表せる。 

$n$ が素数ならば、全ての $a \in \{0,1,2,...,n-1\}$ について:

1. $a^d \equiv 1 \pmod n$
2. ある $0 \leq r \leq s-1$ に対して、 $a^{d \cdot 2^r} \equiv -1 \pmod n$

のいずれかが成立する。... (a)

#### 証明
フェルマーの小定理より、

$\begin{aligned}a^{n-1} &\equiv 1 \pmod n\\a^{d \cdot 2^s} &\equiv 1 \pmod n\end{aligned}$

よって、$a^{n-1} \pmod n$ の平方根は $-1$ または $1 \pmod n$ である。

平方根が $-1$ の時は 2番目の式が成立する。$1$ だった時はまた平方根を考える。このように平方根を取り続け、1度も平方根にならず $r=0$ となった時を考える。

この時 $a^d \equiv 1 \pmod n$ が成り立ち、1番目の式が成立する。

以上より示された。

(a) の対偶を取ると、「ある $a \in \{0,1,2,...,n-1\}$ において、$ a^d \not\equiv 1 \pmod n$ かつ、任意の $0 \leq r \leq s-1$ に対して $a^{d \cdot 2^r} \not\equiv -1$ が成り立つ」となる。

このような $a$ を見つけた場合、$n$ は合成数だと判定出来る。このような $a$ を $n$ の合成性の証拠という。証拠にならない $a$ を「強い嘘つき(strong liar)」といい、$n$ を底 $a$ についての「強擬素数(strong pseudoprime)」という。

### 正しく素数判定出来る確率

この方法では $n$ が素数の時は必ず素数であると判定出来るが、$n$ が合成数の時に誤って素数だと判定してしまうことがある。

任意の奇数の合成数 $n$ において、少なくとも $\frac{3}{4}$ が合成数の証拠になることが分かっている。つまり、各 $a$ について誤って素数だと判定してしまう確率は $\frac{1}{4}$ である。

よって、$a$ を独立にランダムに $k$ 回選んで強擬素数かどうかの判定を行った場合、誤って素数だと判定してしまう確率は最悪でも $4^{-k}$ である。

なお、$n < 2^{32}$ の時、$a=2,7,61$を調べれば必ず素数判定が出来ることが分かっている。また、$n < 2^{64}$ の時、$a=2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37$ を調べれば十分であることが分かっている。

以上より、競プロの範囲ではほとんどの場合決定的なアルゴリズムなので安心して利用して良い。
