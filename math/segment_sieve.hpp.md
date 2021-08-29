---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ2858.test.cpp
    title: test/AOJ2858.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/segment_sieve.hpp\"\n// \u533A\u9593\u7BE9\n// [L,\
    \ R)\u306B\u542B\u307E\u308C\u308B\u6574\u6570\u306E\u7D20\u56E0\u6570\u5206\u89E3\
    \n// R <= 10^12, R - L <= 10^6 \u3068\u3057\u3066 O(log(R-L))\nclass segment_sieve\
    \ {\nprivate:\n    ll L, R, M; // M = sqrt(R)+1\n    vector<int> small;\n    vector<vector<ll>>\
    \ large;\n    vector<ll> aux;\npublic:\n    segment_sieve(ll L, ll R): L(L), R(R),\
    \ M(sqrt(R)+1) {\n        small.resize(M);\n        iota(small.begin(), small.end(),\
    \ 0);\n        large.resize(R - L);\n        aux.resize(R - L, 1);\n\n       \
    \ for(ll i = 2; i*i < R; i++) {\n            if(small[i] < i) continue;\n    \
    \        for(ll j = i*i; j < M; j += i) {\n                if(small[j] == j) small[j]\
    \ = i;\n            }\n\n            for(ll j = (L+i-1)/i*i; j < R; j += i) {\n\
    \                ll k = j;\n                do{\n                    if(aux[j-L]\
    \ * aux[j-L] > R) break;\n                    large[j-L].push_back(i);\n     \
    \               aux[j-L] *= i;\n                    k /= i;\n                }while(k\
    \ % i == 0);\n            }\n        }\n    }\n\n    vector<ll> factor(ll n) {\n\
    \        assert(L <= n and n < R);\n        vector<ll> res = large[n-L];\n   \
    \     n /= aux[n-L];\n        if(n >= M) {\n            res.push_back(n);\n  \
    \          return res;\n        }\n        while(n > 1) {\n            res.push_back(small[n]);\n\
    \            n /= small[n];\n        }\n        return res;\n    }\n};\n"
  code: "// \u533A\u9593\u7BE9\n// [L, R)\u306B\u542B\u307E\u308C\u308B\u6574\u6570\
    \u306E\u7D20\u56E0\u6570\u5206\u89E3\n// R <= 10^12, R - L <= 10^6 \u3068\u3057\
    \u3066 O(log(R-L))\nclass segment_sieve {\nprivate:\n    ll L, R, M; // M = sqrt(R)+1\n\
    \    vector<int> small;\n    vector<vector<ll>> large;\n    vector<ll> aux;\n\
    public:\n    segment_sieve(ll L, ll R): L(L), R(R), M(sqrt(R)+1) {\n        small.resize(M);\n\
    \        iota(small.begin(), small.end(), 0);\n        large.resize(R - L);\n\
    \        aux.resize(R - L, 1);\n\n        for(ll i = 2; i*i < R; i++) {\n    \
    \        if(small[i] < i) continue;\n            for(ll j = i*i; j < M; j += i)\
    \ {\n                if(small[j] == j) small[j] = i;\n            }\n\n      \
    \      for(ll j = (L+i-1)/i*i; j < R; j += i) {\n                ll k = j;\n \
    \               do{\n                    if(aux[j-L] * aux[j-L] > R) break;\n\
    \                    large[j-L].push_back(i);\n                    aux[j-L] *=\
    \ i;\n                    k /= i;\n                }while(k % i == 0);\n     \
    \       }\n        }\n    }\n\n    vector<ll> factor(ll n) {\n        assert(L\
    \ <= n and n < R);\n        vector<ll> res = large[n-L];\n        n /= aux[n-L];\n\
    \        if(n >= M) {\n            res.push_back(n);\n            return res;\n\
    \        }\n        while(n > 1) {\n            res.push_back(small[n]);\n   \
    \         n /= small[n];\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/segment_sieve.hpp
  requiredBy: []
  timestamp: '2021-08-29 15:17:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ2858.test.cpp
documentation_of: math/segment_sieve.hpp
layout: document
redirect_from:
- /library/math/segment_sieve.hpp
- /library/math/segment_sieve.hpp.html
title: math/segment_sieve.hpp
---
