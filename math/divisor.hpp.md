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
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\n#include <algorithm>\n#include <type_traits>\n\
    #include <vector>\n\ntemplate <typename T, std::enable_if_t<std::is_integral<T>::value,\
    \ int> = 0>\nstd::vector<T> divisor(T n) {\n    std::vector<T> ret;\n    for(T\
    \ i = 1; i * i <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n\
    \            if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\
    \ntemplate <typename T, std::enable_if_t<std::is_integral<T>::value, int> = 0>\n\
    std::vector<T> divisor(T n) {\n    std::vector<T> ret;\n    for(T i = 1; i * i\
    \ <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n    \
    \        if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2023-12-05 16:32:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---
