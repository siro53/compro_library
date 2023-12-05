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
  bundledCode: "#line 2 \"math/prime-factor.hpp\"\n\n#include <map>\n#include <type_traits>\n\
    \ntemplate <class T, std::enable_if_t<std::is_integral<T>::value, int> = 0>\n\
    std::map<T, int> prime_factor(T n) {\n    std::map<T, int> ret;\n    for(T i =\
    \ 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            int cnt = 0;\n\
    \            while(n % i == 0) {\n                n /= i;\n                cnt++;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if(n != 1) ret[n]\
    \ = 1;\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <map>\n#include <type_traits>\n\ntemplate <class\
    \ T, std::enable_if_t<std::is_integral<T>::value, int> = 0>\nstd::map<T, int>\
    \ prime_factor(T n) {\n    std::map<T, int> ret;\n    for(T i = 2; i * i <= n;\
    \ i++) {\n        if(n % i == 0) {\n            int cnt = 0;\n            while(n\
    \ % i == 0) {\n                n /= i;\n                cnt++;\n            }\n\
    \            ret[i] = cnt;\n        }\n    }\n    if(n != 1) ret[n] = 1;\n   \
    \ return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-factor.hpp
  requiredBy: []
  timestamp: '2023-12-05 16:32:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime-factor.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---
