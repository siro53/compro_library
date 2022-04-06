---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/lagrange_interpolation.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/determinant.test.cpp
    title: test/determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_operate_all_compose.test.cpp
    title: test/queue_operate_all_compose.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki1333.test.cpp
    title: test/yuki1333.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\ntemplate <int mod> struct ModInt {\n\
    \    int x;\n    ModInt() : x(0) {}\n    ModInt(int64_t y) : x(y >= 0 ? y % mod\
    \ : (mod - (-y) % mod) % mod) {}\n    ModInt &operator+=(const ModInt &p) {\n\
    \        if((x += p.x) >= mod)\n            x -= mod;\n        return *this;\n\
    \    }\n    ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x)\
    \ >= mod)\n            x -= mod;\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n    bool operator==(const ModInt &p) const { return x == p.x; }\n    bool\
    \ operator!=(const ModInt &p) const { return x != p.x; }\n    ModInt inv() const\
    \ {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0) {\n  \
    \          t = a / b;\n            swap(a -= t * b, b);\n            swap(u -=\
    \ t * v, v);\n        }\n        return ModInt(u);\n    }\n    ModInt pow(int64_t\
    \ n) const {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n       \
    \     if(n & 1)\n                ret *= mul;\n            mul *= mul;\n      \
    \      n >>= 1;\n        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt<mod>(t);\n        return (is);\n    }\n    static int get_mod()\
    \ { return mod; }\n};\n"
  code: "template <int mod> struct ModInt {\n    int x;\n    ModInt() : x(0) {}\n\
    \    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n \
    \   ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= mod)\n   \
    \         x -= mod;\n        return *this;\n    }\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if((x += mod - p.x) >= mod)\n            x -= mod;\n \
    \       return *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n    \
    \    x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n    ModInt\
    \ &operator/=(const ModInt &p) {\n        *this *= p.inv();\n        return *this;\n\
    \    }\n    ModInt operator-() const { return ModInt(-x); }\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {\n        int a = x, b = mod, u\
    \ = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n           \
    \ swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return\
    \ ModInt(u);\n    }\n    ModInt pow(int64_t n) const {\n        ModInt ret(1),\
    \ mul(x);\n        while(n > 0) {\n            if(n & 1)\n                ret\
    \ *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n    friend ostream &operator<<(ostream &os, const ModInt &p) {\n\
    \        return os << p.x;\n    }\n    friend istream &operator>>(istream &is,\
    \ ModInt &a) {\n        int64_t t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n    static int get_mod() { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/lagrange_interpolation.hpp
  timestamp: '2021-02-13 09:10:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_operate_all_compose.test.cpp
  - test/determinant.test.cpp
  - test/yuki1333.test.cpp
  - test/vertex_set_path_composite.test.cpp
documentation_of: math/modint.hpp
layout: document
title: ModInt
---
