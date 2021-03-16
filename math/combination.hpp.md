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
  bundledCode: "#line 1 \"math/combination.hpp\"\nstruct Combination {\n    int MAX;\n\
    \    vector<mint> fac, finv;\n    Combination(int _MAX) : fac(_MAX), finv(_MAX),\
    \ MAX(_MAX) {\n        fac[0] = fac[1] = 1;\n        for(int i = 2; i < MAX; i++)\
    \ { fac[i] = fac[i - 1] * i; }\n        finv[MAX - 1] = fac[MAX - 1].inv();\n\
    \        for(int i = MAX - 1; i >= 1; i--) { finv[i - 1] = finv[i] * i; }\n  \
    \  }\n    mint COM(int n, int k) {\n        if(n < k || n < 0 || k < 0) { return\
    \ 0; }\n        return fac[n] * finv[k] * finv[n - k];\n    }\n};\n"
  code: "struct Combination {\n    int MAX;\n    vector<mint> fac, finv;\n    Combination(int\
    \ _MAX) : fac(_MAX), finv(_MAX), MAX(_MAX) {\n        fac[0] = fac[1] = 1;\n \
    \       for(int i = 2; i < MAX; i++) { fac[i] = fac[i - 1] * i; }\n        finv[MAX\
    \ - 1] = fac[MAX - 1].inv();\n        for(int i = MAX - 1; i >= 1; i--) { finv[i\
    \ - 1] = finv[i] * i; }\n    }\n    mint COM(int n, int k) {\n        if(n < k\
    \ || n < 0 || k < 0) { return 0; }\n        return fac[n] * finv[k] * finv[n -\
    \ k];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2021-03-16 22:41:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: math/combination.hpp
---
