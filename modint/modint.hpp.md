---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
  - icon: ':warning:'
    path: test/library-checker/data-structure/point-set-range-composite.cpp
    title: test/library-checker/data-structure/point-set-range-composite.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
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
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/convolution/convolution-mod.test.cpp
  - test/yukicoder/yuki117.test.cpp
  - test/yukicoder/yuki1750.test.cpp
documentation_of: modint/modint.hpp
layout: document
redirect_from:
- /library/modint/modint.hpp
- /library/modint/modint.hpp.html
title: modint/modint.hpp
---
