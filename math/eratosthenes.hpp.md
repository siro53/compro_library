---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ2858.test.cpp
    title: test/AOJ2858.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/erathosthenes.test.cpp
    title: test/erathosthenes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/eratosthenes.hpp\"\nvector<bool> eratosthenes(int n)\
    \ {\n    vector<bool> isp(n + 1, true);\n    isp[0] = isp[1] = false;\n    for(int\
    \ i = 2; i * i <= n; i++) {\n        if(!isp[i]) continue;\n        for(int j\
    \ = i+i; j <= n; j += i) isp[j] = false;\n    }\n    return isp;\n}\n"
  code: "vector<bool> eratosthenes(int n) {\n    vector<bool> isp(n + 1, true);\n\
    \    isp[0] = isp[1] = false;\n    for(int i = 2; i * i <= n; i++) {\n       \
    \ if(!isp[i]) continue;\n        for(int j = i+i; j <= n; j += i) isp[j] = false;\n\
    \    }\n    return isp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2021-03-15 20:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/erathosthenes.test.cpp
  - test/AOJ2858.test.cpp
documentation_of: math/eratosthenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
