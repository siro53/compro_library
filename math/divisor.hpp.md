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
  bundledCode: "#line 1 \"math/divisor.hpp\"\ntemplate<class T>\nvector<T> divisor(T\
    \ n) {\n    vector<T> ret;\n    for(T i = 1; i * i <= n; i++) {\n        if(n\
    \ % i == 0) {\n            ret.push_back(i);\n            if(i * i != n)\n   \
    \             ret.push_back(n / i);\n        }\n    }\n    sort(begin(ret), end(ret));\n\
    \    return (ret);\n}\n"
  code: "template<class T>\nvector<T> divisor(T n) {\n    vector<T> ret;\n    for(T\
    \ i = 1; i * i <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n\
    \            if(i * i != n)\n                ret.push_back(n / i);\n        }\n\
    \    }\n    sort(begin(ret), end(ret));\n    return (ret);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
title: "\u7D04\u6570"
---
