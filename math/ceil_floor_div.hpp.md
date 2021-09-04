---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ceil_floor_div.hpp\"\ntemplate<class T>\nT ceil_div(T\
    \ a, T b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0 ? (a + b - 1) /\
    \ b : a / b);\n}\n\ntemplate<class T>\nT floor_div(T a, T b) {\n    if(b < 0)\
    \ a = -a, b = -b;\n    return (a >= 0 ? a / b : (a - b + 1) / b);\n}\n"
  code: "template<class T>\nT ceil_div(T a, T b) {\n    if(b < 0) a = -a, b = -b;\n\
    \    return (a >= 0 ? (a + b - 1) / b : a / b);\n}\n\ntemplate<class T>\nT floor_div(T\
    \ a, T b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0 ? a / b : (a -\
    \ b + 1) / b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ceil_floor_div.hpp
  requiredBy: []
  timestamp: '2021-03-28 17:58:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ceil_floor_div.hpp
layout: document
title: "\u5272\u308A\u7B97(floor, ceil)"
---
