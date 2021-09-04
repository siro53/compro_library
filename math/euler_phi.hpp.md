---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/euler_phi.test.cpp
    title: test/euler_phi.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/euler_phi.hpp\"\ntemplate<class T>\nT phi(T n) {\n\
    \    T ret = n;\n    for(T i = 2; i * i <= n; i++) {\n        if(n % i == 0) {\n\
    \            ret -= ret / i;\n            while(n % i == 0) n /= i;\n        }\n\
    \    }\n    if(n > 1) ret -= ret / n;\n    return ret;\n}\n"
  code: "template<class T>\nT phi(T n) {\n    T ret = n;\n    for(T i = 2; i * i <=\
    \ n; i++) {\n        if(n % i == 0) {\n            ret -= ret / i;\n         \
    \   while(n % i == 0) n /= i;\n        }\n    }\n    if(n > 1) ret -= ret / n;\n\
    \    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy: []
  timestamp: '2021-08-06 10:40:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/euler_phi.test.cpp
documentation_of: math/euler_phi.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u306Ephi\u95A2\u6570"
---
