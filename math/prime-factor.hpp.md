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
  bundledCode: "#line 2 \"math/prime-factor.hpp\"\n\n#include <map>\n\ntemplate <typename\
    \ T = int> std::map<T, int> prime_factor(T n) {\n    static_assert(std::is_integral<T>::value\
    \ == true, \"type 'T' should be integer.\");\n    std::map<T, int> ret;\n    for(T\
    \ i = 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            int cnt = 0;\n\
    \            while(n % i == 0) {\n                n /= i;\n                cnt++;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if(n != 0) ret[n]\
    \ = 1;\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <map>\n\ntemplate <typename T = int> std::map<T,\
    \ int> prime_factor(T n) {\n    static_assert(std::is_integral<T>::value == true,\
    \ \"type 'T' should be integer.\");\n    std::map<T, int> ret;\n    for(T i =\
    \ 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            int cnt = 0;\n\
    \            while(n % i == 0) {\n                n /= i;\n                cnt++;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if(n != 0) ret[n]\
    \ = 1;\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-factor.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime-factor.hpp
layout: document
redirect_from:
- /library/math/prime-factor.hpp
- /library/math/prime-factor.hpp.html
title: math/prime-factor.hpp
---
