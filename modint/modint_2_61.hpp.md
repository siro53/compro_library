---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/monoid/rolling_hash.hpp
    title: data-structure/monoid/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
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
  - test/yukicoder/yuki2102.test.cpp
  - test/yukicoder/yuki430.test.cpp
documentation_of: modint/modint_2_61.hpp
layout: document
redirect_from:
- /library/modint/modint_2_61.hpp
- /library/modint/modint_2_61.hpp.html
title: modint/modint_2_61.hpp
---
