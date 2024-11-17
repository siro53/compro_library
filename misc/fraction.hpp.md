---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/fraction.test.cpp
    title: test/mytest/misc/fraction.test.cpp
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
    \ *this;\n    }\n    F &operator/=(const F& f) {\n        a *= f.b;\n        b\
    \ *= f.a;\n        normalize();\n        return *this;\n    }\n    F operator-()\
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
    \ s = t;\n            t = u;\n        }\n        return t;\n    }\n};\n"
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
    \ F& f) {\n        a *= f.b;\n        b *= f.a;\n        normalize();\n      \
    \  return *this;\n    }\n    F operator-() const { return F(-a, b); }\n    F operator+(const\
    \ F& f) const { return F(*this) += f; }\n    F operator-(const F& f) const { return\
    \ F(*this) -= f; }\n    F operator*(const F& f) const { return F(*this) *= f;\
    \ }\n    F operator/(const F& f) const { return F(*this) /= f; }\n    bool operator==(const\
    \ F& f) const {\n        return a * f.b == b * f.a;\n    }\n    bool operator!=(const\
    \ F& f) const {\n        return !(*this == f);\n    }\n    bool operator<(const\
    \ F& f) const {\n        return a * f.b < b * f.a;\n    }\n    bool operator<=(const\
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
  timestamp: '2024-11-17 22:22:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/misc/fraction.test.cpp
documentation_of: misc/fraction.hpp
layout: document
redirect_from:
- /library/misc/fraction.hpp
- /library/misc/fraction.hpp.html
title: misc/fraction.hpp
---
