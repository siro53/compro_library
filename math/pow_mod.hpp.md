---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C.test.cpp
    title: test/aoj/aoj-ALDS1-1-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/pow_mod.hpp\"\n\nconstexpr long long pow_mod(long long\
    \ x, long long k, int m) {\n    unsigned int mod = m;\n    unsigned long long\
    \ res = 1;\n    unsigned long long mul = (x >= 0 ? x % mod : x % mod + mod);\n\
    \    while(k) {\n        if(k & 1) (res *= mul) %= m;\n        (mul *= mul) %=\
    \ m;\n        k >>= 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nconstexpr long long pow_mod(long long x, long long k, int\
    \ m) {\n    unsigned int mod = m;\n    unsigned long long res = 1;\n    unsigned\
    \ long long mul = (x >= 0 ? x % mod : x % mod + mod);\n    while(k) {\n      \
    \  if(k & 1) (res *= mul) %= m;\n        (mul *= mul) %= m;\n        k >>= 1;\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_mod.hpp
  requiredBy:
  - math/is-prime.hpp
  timestamp: '2023-09-29 00:04:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-1-C.test.cpp
documentation_of: math/pow_mod.hpp
layout: document
redirect_from:
- /library/math/pow_mod.hpp
- /library/math/pow_mod.hpp.html
title: math/pow_mod.hpp
---
