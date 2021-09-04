---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
  bundledCode: "#line 1 \"math/osa_k.hpp\"\n// https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    class osa_k {\n  private:\n    int N;\n    vector<int> min_factor;\n\n  public:\n\
    \    osa_k(int N) : N(N), min_factor(N) {\n        iota(ALL(min_factor), 0);\n\
    \        for(int i = 2; i * i < N; i++) {\n            if(min_factor[i] < i) continue;\n\
    \            for(int j = i * i; j < N; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n            }\n        }\n    }\n    \n    vector<int>\
    \ factor(int n) {\n        vector<int> res;\n        while(n > 1) {\n        \
    \    res.push_back(min_factor[n]);\n            n /= min_factor[n];\n        }\n\
    \        return res;\n    }\n};\n"
  code: "// https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\nclass osa_k\
    \ {\n  private:\n    int N;\n    vector<int> min_factor;\n\n  public:\n    osa_k(int\
    \ N) : N(N), min_factor(N) {\n        iota(ALL(min_factor), 0);\n        for(int\
    \ i = 2; i * i < N; i++) {\n            if(min_factor[i] < i) continue;\n    \
    \        for(int j = i * i; j < N; j += i) {\n                if(min_factor[j]\
    \ == j) min_factor[j] = i;\n            }\n        }\n    }\n    \n    vector<int>\
    \ factor(int n) {\n        vector<int> res;\n        while(n > 1) {\n        \
    \    res.push_back(min_factor[n]);\n            n /= min_factor[n];\n        }\n\
    \        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '2021-08-27 12:18:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osa_k.hpp
layout: document
title: "osa_k\u6CD5"
---
