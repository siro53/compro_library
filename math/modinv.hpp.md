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
  bundledCode: "#line 1 \"math/modinv.hpp\"\nll modinv(ll a, ll m) {\n    ll b = m,\
    \ u = 1, v = 0;\n    while(b) {\n        ll t = a / b;\n        a -= t * b;\n\
    \        swap(a, b);\n        u -= t * v;\n        swap(u, v);\n    }\n    u %=\
    \ m;\n    if(u < 0) u += m;\n    return u;\n}\n"
  code: "ll modinv(ll a, ll m) {\n    ll b = m, u = 1, v = 0;\n    while(b) {\n  \
    \      ll t = a / b;\n        a -= t * b;\n        swap(a, b);\n        u -= t\
    \ * v;\n        swap(u, v);\n    }\n    u %= m;\n    if(u < 0) u += m;\n    return\
    \ u;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/modinv.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modinv.hpp
layout: document
title: "\u9006\u5143\u8A08\u7B97(\u62E1\u5F35Euclid)"
---
