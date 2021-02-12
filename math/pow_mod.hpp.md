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
  bundledCode: "#line 1 \"math/pow_mod.hpp\"\nll pow_mod(ll n, ll k, ll mod) {\n \
    \   if(k == 0) {\n        return 1;\n    } else if(k % 2 == 1) {\n        return\
    \ pow_mod(n, k - 1, mod) * n % mod;\n    } else {\n        ll t = pow_mod(n, k\
    \ / 2, mod);\n        return t * t % mod;\n    }\n}\n"
  code: "ll pow_mod(ll n, ll k, ll mod) {\n    if(k == 0) {\n        return 1;\n \
    \   } else if(k % 2 == 1) {\n        return pow_mod(n, k - 1, mod) * n % mod;\n\
    \    } else {\n        ll t = pow_mod(n, k / 2, mod);\n        return t * t %\
    \ mod;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_mod.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow_mod.hpp
layout: document
redirect_from:
- /library/math/pow_mod.hpp
- /library/math/pow_mod.hpp.html
title: math/pow_mod.hpp
---
