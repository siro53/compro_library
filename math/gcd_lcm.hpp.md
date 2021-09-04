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
  bundledCode: "#line 1 \"math/gcd_lcm.hpp\"\nll GCD(ll a, ll b) {\n    if(b == 0)\n\
    \        return a;\n    else\n        return GCD(b, a % b);\n}\n\nll LCM(ll a,\
    \ ll b) { return a * b / GCD(a, b); }\n"
  code: "ll GCD(ll a, ll b) {\n    if(b == 0)\n        return a;\n    else\n     \
    \   return GCD(b, a % b);\n}\n\nll LCM(ll a, ll b) { return a * b / GCD(a, b);\
    \ }"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd_lcm.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gcd_lcm.hpp
layout: document
title: GCD, LCM
---
