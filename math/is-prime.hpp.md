---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"math/is-prime.hpp\"\n\n#include <type_traits>\n\ntemplate\
    \ <class T = int> bool is_prime(T n) {\n    static_assert(std::is_integral<T>::value\
    \ == true, \"type 'T' should be integer.\");\n    if(n <= 1) return false;\n \
    \   for(T i = 2; i * i <= n; i++) {\n        if(n % i == 0) return false;\n  \
    \  }\n    return true;\n}\n"
  code: "#pragma once\n\n#include <type_traits>\n\ntemplate <class T = int> bool is_prime(T\
    \ n) {\n    static_assert(std::is_integral<T>::value == true, \"type 'T' should\
    \ be integer.\");\n    if(n <= 1) return false;\n    for(T i = 2; i * i <= n;\
    \ i++) {\n        if(n % i == 0) return false;\n    }\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is-prime.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-1-C.test.cpp
documentation_of: math/is-prime.hpp
layout: document
redirect_from:
- /library/math/is-prime.hpp
- /library/math/is-prime.hpp.html
title: math/is-prime.hpp
---
