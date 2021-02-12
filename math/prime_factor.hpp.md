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
  bundledCode: "#line 1 \"math/prime_factor.hpp\"\ntemplate<class T>\nmap<T, int>\
    \ prime_factor(T n) {\n    map<T, int> ret;\n    for(T i = 2; i * i <= n; i++)\
    \ {\n        while(n % i == 0) {\n            ret[i]++;\n            n /= i;\n\
    \        }\n    }\n    if(n != 1)\n        ret[n] = 1;\n    return ret;\n}\n"
  code: "template<class T>\nmap<T, int> prime_factor(T n) {\n    map<T, int> ret;\n\
    \    for(T i = 2; i * i <= n; i++) {\n        while(n % i == 0) {\n          \
    \  ret[i]++;\n            n /= i;\n        }\n    }\n    if(n != 1)\n        ret[n]\
    \ = 1;\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factor.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime_factor.hpp
- /library/math/prime_factor.hpp.html
title: math/prime_factor.hpp
---
