---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barrett-reduction.hpp
    title: Barrett Reduction
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc104d.test.cpp
    title: test/atcoder/arc104d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ long long m_inv;\n};\n#line 8 \"modint/dynamic-modint.hpp\"\n\nclass DynamicModInt\
    \ {\n  public:\n    DynamicModInt() : x(0) {}\n    DynamicModInt(long long y)\n\
    \        : x(y >= 0\n                ? y % (long long)mod\n                : ((long\
    \ long)mod - (-y) % (long long)mod) % (long long)mod) {}\n    static void set_mod(unsigned\
    \ int m) {\n        assert(m > 0);\n        mod = m;\n        bt = BarrettReduction(m);\n\
    \    }\n    unsigned int val() const { return x; }\n    DynamicModInt &operator+=(const\
    \ DynamicModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n    DynamicModInt &operator-=(const DynamicModInt &p) {\n   \
    \     if((x += (mod - p.x)) >= mod) x -= mod;\n        return *this;\n    }\n\
    \    DynamicModInt &operator*=(const DynamicModInt &p) {\n        x = bt.mul(x,\
    \ p.x);\n        return *this;\n    }\n    DynamicModInt &operator/=(const DynamicModInt\
    \ &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    DynamicModInt\
    \ operator-() const { return DynamicModInt(-x); }\n    DynamicModInt operator+(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) += p;\n    }\n\
    \    DynamicModInt operator-(const DynamicModInt &p) const {\n        return DynamicModInt(*this)\
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
    \ = DynamicModInt(t);\n        return (is);\n    }\n\n  private:\n    unsigned\
    \ int x;\n    static inline unsigned int mod;\n    static inline BarrettReduction\
    \ bt;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <istream>\n#include <ostream>\n\
    \n#include \"../math/barrett-reduction.hpp\"\n\nclass DynamicModInt {\n  public:\n\
    \    DynamicModInt() : x(0) {}\n    DynamicModInt(long long y)\n        : x(y\
    \ >= 0\n                ? y % (long long)mod\n                : ((long long)mod\
    \ - (-y) % (long long)mod) % (long long)mod) {}\n    static void set_mod(unsigned\
    \ int m) {\n        assert(m > 0);\n        mod = m;\n        bt = BarrettReduction(m);\n\
    \    }\n    unsigned int val() const { return x; }\n    DynamicModInt &operator+=(const\
    \ DynamicModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n    DynamicModInt &operator-=(const DynamicModInt &p) {\n   \
    \     if((x += (mod - p.x)) >= mod) x -= mod;\n        return *this;\n    }\n\
    \    DynamicModInt &operator*=(const DynamicModInt &p) {\n        x = bt.mul(x,\
    \ p.x);\n        return *this;\n    }\n    DynamicModInt &operator/=(const DynamicModInt\
    \ &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    DynamicModInt\
    \ operator-() const { return DynamicModInt(-x); }\n    DynamicModInt operator+(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) += p;\n    }\n\
    \    DynamicModInt operator-(const DynamicModInt &p) const {\n        return DynamicModInt(*this)\
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
    \ = DynamicModInt(t);\n        return (is);\n    }\n\n  private:\n    unsigned\
    \ int x;\n    static inline unsigned int mod;\n    static inline BarrettReduction\
    \ bt;\n};"
  dependsOn:
  - math/barrett-reduction.hpp
  isVerificationFile: false
  path: modint/dynamic-modint.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/arc104d.test.cpp
documentation_of: modint/dynamic-modint.hpp
layout: document
redirect_from:
- /library/modint/dynamic-modint.hpp
- /library/modint/dynamic-modint.hpp.html
title: modint/dynamic-modint.hpp
---
