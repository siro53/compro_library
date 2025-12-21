---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: math/primitive-root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C.test.cpp
    title: test/aoj/aoj-ALDS1-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/primality-test.test.cpp
    title: test/library-checker/math/primality-test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/pow_mod.hpp\"\n\nconstexpr long long pow_mod(long long\
    \ x, long long k, long long m) {\n    long long res = 1;\n    long long mul =\
    \ (x >= 0 ? x % m : x % m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res\
    \ * mul % m;\n        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n   \
    \ }\n    return res;\n}\n"
  code: "#pragma once\n\nconstexpr long long pow_mod(long long x, long long k, long\
    \ long m) {\n    long long res = 1;\n    long long mul = (x >= 0 ? x % m : x %\
    \ m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res * mul % m;\n\
    \        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n    }\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_mod.hpp
  requiredBy:
  - math/is-prime.hpp
  - math/convolution/ntt.hpp
  - math/primitive-root.hpp
  timestamp: '2023-10-01 12:06:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-1-C.test.cpp
  - test/library-checker/math/primality-test.test.cpp
  - test/library-checker/convolution/convolution-mod.test.cpp
documentation_of: math/pow_mod.hpp
layout: document
redirect_from:
- /library/math/pow_mod.hpp
- /library/math/pow_mod.hpp.html
title: math/pow_mod.hpp
---
