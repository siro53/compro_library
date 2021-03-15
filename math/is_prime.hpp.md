---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/is_prime.test.cpp
    title: test/is_prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/is_prime.hpp\"\nbool is_prime(int n) {\n    if(n <=\
    \ 1) return false;\n    for(int i = 2; i * i <= n; i++) {\n        if(n % i ==\
    \ 0) return false;\n    }\n    return true;\n}\n"
  code: "bool is_prime(int n) {\n    if(n <= 1) return false;\n    for(int i = 2;\
    \ i * i <= n; i++) {\n        if(n % i == 0) return false;\n    }\n    return\
    \ true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy: []
  timestamp: '2021-03-15 20:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/is_prime.test.cpp
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
