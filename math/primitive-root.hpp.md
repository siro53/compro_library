---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/primitive-root.hpp\"\n\n#line 2 \"math/pow_mod.hpp\"\
    \n\nconstexpr long long pow_mod(long long x, long long k, long long m) {\n   \
    \ long long res = 1;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n    while(k)\
    \ {\n        if(k & 1) res = res * mul % m;\n        mul = mul * mul % m;\n  \
    \      k >>= 1;\n    }\n    return res;\n}\n#line 4 \"math/primitive-root.hpp\"\
    \n\nconstexpr int primitive_root(int p) {\n    if(p == 2) return 1;\n    if(p\
    \ == 998244353) return 3;\n    int primes[31] = {};\n    int sz = 0, t = p - 1;\n\
    \    for(int i = 2; i * i <= t; i++) {\n        if(t % i == 0) {\n           \
    \ primes[sz++] = i;\n            while(t % i == 0) t /= i;\n        }\n    }\n\
    \    if(t > 1) primes[sz++] = t;\n    for(int g = 2;;g++) {\n        bool f =\
    \ true;\n        for(int i = 0; i < sz; i++) {\n            if(pow_mod(g, (p -\
    \ 1) / primes[i], p) == 1) {\n                f = false;\n                break;\n\
    \            }\n        }   \n        if(f) return g;\n    }\n}\n"
  code: "#pragma once\n\n#include \"pow_mod.hpp\"\n\nconstexpr int primitive_root(int\
    \ p) {\n    if(p == 2) return 1;\n    if(p == 998244353) return 3;\n    int primes[31]\
    \ = {};\n    int sz = 0, t = p - 1;\n    for(int i = 2; i * i <= t; i++) {\n \
    \       if(t % i == 0) {\n            primes[sz++] = i;\n            while(t %\
    \ i == 0) t /= i;\n        }\n    }\n    if(t > 1) primes[sz++] = t;\n    for(int\
    \ g = 2;;g++) {\n        bool f = true;\n        for(int i = 0; i < sz; i++) {\n\
    \            if(pow_mod(g, (p - 1) / primes[i], p) == 1) {\n                f\
    \ = false;\n                break;\n            }\n        }   \n        if(f)\
    \ return g;\n    }\n}"
  dependsOn:
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/primitive-root.hpp
  requiredBy:
  - math/convolution/ntt.hpp
  timestamp: '2023-10-01 12:02:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/convolution/convolution-mod.test.cpp
documentation_of: math/primitive-root.hpp
layout: document
redirect_from:
- /library/math/primitive-root.hpp
- /library/math/primitive-root.hpp.html
title: math/primitive-root.hpp
---
