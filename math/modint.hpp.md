---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/combination.hpp
    title: math/combination.hpp
  - icon: ':warning:'
    path: math/lagrange_interpolation.hpp
    title: math/lagrange_interpolation.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/determinant.test.cpp
    title: test/determinant.test.cpp
  - icon: ':x:'
    path: test/queue_operate_all_compose.test.cpp
    title: test/queue_operate_all_compose.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\ntemplate <int mod> struct ModInt {\n\
    \    using M = ModInt;\n    int x;\n    ModInt() : x(0) {}\n    ModInt(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    M &operator+=(const\
    \ M &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &p) {\n        if((x += mod - p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &p) {\n      \
    \  x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n    M &operator/=(const\
    \ M &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n    M\
    \ operator-() const { return M(-x); }\n    M operator+(const M &p) const { return\
    \ M(*this) += p; }\n    M operator-(const M &p) const { return M(*this) -= p;\
    \ }\n    M operator*(const M &p) const { return M(*this) *= p; }\n    M operator/(const\
    \ M &p) const { return M(*this) /= p; }\n    M inverse() const {\n        int\
    \ a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n            t = a\
    \ / b;\n            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n \
    \       }\n        return M(u);\n    }\n    M pow(int64_t n) const {\n       \
    \ M ret(1), mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n\
    \            mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const M &p) { return os <<\
    \ p.x; }\n    friend istream &operator>>(istream &is, M &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = M<mod>(t);\n        return (is);\n    }\n\
    \    static int get_mod() { return mod; }\n};\n"
  code: "template <int mod> struct ModInt {\n    using M = ModInt;\n    int x;\n \
    \   ModInt() : x(0) {}\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y)\
    \ % mod) % mod) {}\n    M &operator+=(const M &p) {\n        if((x += p.x) >=\
    \ mod) x -= mod;\n        return *this;\n    }\n    M &operator-=(const M &p)\
    \ {\n        if((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator*=(const M &p) {\n        x = (int)(1LL * x * p.x % mod);\n\
    \        return *this;\n    }\n    M &operator/=(const M &p) {\n        *this\
    \ *= p.inverse();\n        return *this;\n    }\n    M operator-() const { return\
    \ M(-x); }\n    M operator+(const M &p) const { return M(*this) += p; }\n    M\
    \ operator-(const M &p) const { return M(*this) -= p; }\n    M operator*(const\
    \ M &p) const { return M(*this) *= p; }\n    M operator/(const M &p) const { return\
    \ M(*this) /= p; }\n    M inverse() const {\n        int a = x, b = mod, u = 1,\
    \ v = 0, t;\n        while(b > 0) {\n            t = a / b;\n            swap(a\
    \ -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return M(u);\n\
    \    }\n    M pow(int64_t n) const {\n        M ret(1), mul(x);\n        while(n\
    \ > 0) {\n            if(n & 1) ret *= mul;\n            mul *= mul;\n       \
    \     n >>= 1;\n        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const M &p) { return os << p.x; }\n    friend istream &operator>>(istream\
    \ &is, M &a) {\n        int64_t t;\n        is >> t;\n        a = M<mod>(t);\n\
    \        return (is);\n    }\n    static int get_mod() { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/lagrange_interpolation.hpp
  - math/combination.hpp
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/queue_operate_all_compose.test.cpp
  - test/determinant.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
