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
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \ntemplate<typename T>\nstd::vector<T> divisor(T n) {\n    static_assert(std::is_integral<T>::value\
    \ == true, \"type 'T' should be integer.\");\n    std::vector<T> ret;\n    for(T\
    \ i = 1; i * i <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n\
    \            if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate<typename\
    \ T>\nstd::vector<T> divisor(T n) {\n    static_assert(std::is_integral<T>::value\
    \ == true, \"type 'T' should be integer.\");\n    std::vector<T> ret;\n    for(T\
    \ i = 1; i * i <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n\
    \            if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
redirect_from:
- /library/math/divisor.hpp
- /library/math/divisor.hpp.html
title: math/divisor.hpp
---
