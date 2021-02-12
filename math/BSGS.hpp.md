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
  bundledCode: "#line 1 \"math/BSGS.hpp\"\n// \u4E0E\u3048\u3089\u308C\u305Fx, y,\
    \ p\u306B\u5BFE\u3057\u3066\u3001x^i=y(mod p)\u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306E\u6B63\u306E\u6574\u6570i\u3092\u8FD4\u3059\n// \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F-1\n// O(\u221Ap log(p))\nll modlog(ll x, ll y, ll p)\
    \ {\n    ll H = sqrt(p) + 1;\n    pair<ll, ll> baby[H];\n    for(ll b = 0, xby\
    \ = y; b < H; b++, xby = (xby * x) % p) {\n        baby[b] = make_pair(xby, b);\n\
    \    }\n    sort(baby, baby + H);\n    ll xH = 1;\n    for(int i = 0; i < H; ++i)\
    \ {\n        xH = (xH * x) % p;\n    }\n    for(ll a = 1, xaH = xH; a <= H; a++,\
    \ xaH = (xaH * xH) % p) {\n        auto it = lower_bound(baby, baby + H, make_pair(xaH\
    \ + 1, 0LL));\n        if(it == baby) {\n            continue;\n        }\n  \
    \      it--;\n        if(it->first == xaH) {\n            return a * H - it->second;\n\
    \        }\n    }\n    return -1;\n}\n"
  code: "// \u4E0E\u3048\u3089\u308C\u305Fx, y, p\u306B\u5BFE\u3057\u3066\u3001x^i=y(mod\
    \ p)\u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u6B63\u306E\u6574\u6570i\u3092\u8FD4\
    \u3059\n// \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\n// O(\u221Ap log(p))\n\
    ll modlog(ll x, ll y, ll p) {\n    ll H = sqrt(p) + 1;\n    pair<ll, ll> baby[H];\n\
    \    for(ll b = 0, xby = y; b < H; b++, xby = (xby * x) % p) {\n        baby[b]\
    \ = make_pair(xby, b);\n    }\n    sort(baby, baby + H);\n    ll xH = 1;\n   \
    \ for(int i = 0; i < H; ++i) {\n        xH = (xH * x) % p;\n    }\n    for(ll\
    \ a = 1, xaH = xH; a <= H; a++, xaH = (xaH * xH) % p) {\n        auto it = lower_bound(baby,\
    \ baby + H, make_pair(xaH + 1, 0LL));\n        if(it == baby) {\n            continue;\n\
    \        }\n        it--;\n        if(it->first == xaH) {\n            return\
    \ a * H - it->second;\n        }\n    }\n    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/BSGS.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/BSGS.hpp
layout: document
redirect_from:
- /library/math/BSGS.hpp
- /library/math/BSGS.hpp.html
title: math/BSGS.hpp
---
