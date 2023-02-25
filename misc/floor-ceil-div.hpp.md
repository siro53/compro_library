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
  bundledCode: "#line 2 \"misc/floor-ceil-div.hpp\"\n\ntemplate <typename T> T ceil_div(T\
    \ a, T b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0 ? (a + b - 1) /\
    \ b : a / b);\n}\n\ntemplate <typename T> T floor_div(T a, T b) {\n    if(b <\
    \ 0) a = -a, b = -b;\n    return (a >= 0 ? a / b : (a - b + 1) / b);\n}\n"
  code: "#pragma once\n\ntemplate <typename T> T ceil_div(T a, T b) {\n    if(b <\
    \ 0) a = -a, b = -b;\n    return (a >= 0 ? (a + b - 1) / b : a / b);\n}\n\ntemplate\
    \ <typename T> T floor_div(T a, T b) {\n    if(b < 0) a = -a, b = -b;\n    return\
    \ (a >= 0 ? a / b : (a - b + 1) / b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/floor-ceil-div.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/floor-ceil-div.hpp
layout: document
redirect_from:
- /library/misc/floor-ceil-div.hpp
- /library/misc/floor-ceil-div.hpp.html
title: misc/floor-ceil-div.hpp
---
