---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/chromatic_number.test.cpp
    title: test/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/chromatic_number.hpp\"\n// \u5F69\u8272\u6570 O(n*2^n)\n\
    int chromatic_number(int N, const vector<vector<int>>& G) {\n    // \u672C\u5F53\
    \u306Frandom\u306B\u7D20\u6570\u3092\u53D6\u3063\u305F\u65B9\u304C\u3044\u3044\
    \n    constexpr int mod = int(1e9) + 9;\n    // ind[S] = \u9802\u70B9\u96C6\u5408\
    S\u306E\u90E8\u5206\u96C6\u5408\u3067\u3042\u3063\u3066\u3001\u72EC\u7ACB\u96C6\
    \u5408\u3092\u306A\u3059\u3082\u306E\u306E\u500B\u6570\n    vector<int> ind(1\
    \ << N, 0);\n    // adj_bit[v] = v\u3068\u96A3\u63A5\u3057\u3066\u308B\u9802\u70B9\
    \u306E\u5834\u6240\u306Bbit\u3092\u7ACB\u3066\u305F\u3082\u306E\n    vector<int>\
    \ adj_bit(N, 0);\n    for(int i = 0; i < N; i++) {\n        for(int j = 0; j <\
    \ N; j++) if(G[i][j]) adj_bit[i] |= (1 << j);\n    }\n    ind[0] = 1;\n    for(int\
    \ S = 1; S < (1 << N); S++) {\n        int v = __builtin_ctz(S);\n        ind[S]\
    \ = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~adj_bit[v]];\n        if(ind[S]\
    \ >= mod) ind[S] -= mod;\n    }\n    vector<ll> sum(1 << N);\n    for(int S =\
    \ 0; S < (1 << N); S++) sum[S] = ((N - (int)__builtin_popcount(S)) & 1 ? mod-1\
    \ : 1);\n    for(int K = 1; K < N; K++) {\n        ll res = 0;\n        for(int\
    \ S = 0; S < (1 << N); S++) {\n            (sum[S] *= ind[S]) %= mod;\n      \
    \      res += sum[S];\n        }\n        if(res % mod > 0) return K;\n    } \n\
    \    return N;\n}\n"
  code: "// \u5F69\u8272\u6570 O(n*2^n)\nint chromatic_number(int N, const vector<vector<int>>&\
    \ G) {\n    // \u672C\u5F53\u306Frandom\u306B\u7D20\u6570\u3092\u53D6\u3063\u305F\
    \u65B9\u304C\u3044\u3044\n    constexpr int mod = int(1e9) + 9;\n    // ind[S]\
    \ = \u9802\u70B9\u96C6\u5408S\u306E\u90E8\u5206\u96C6\u5408\u3067\u3042\u3063\u3066\
    \u3001\u72EC\u7ACB\u96C6\u5408\u3092\u306A\u3059\u3082\u306E\u306E\u500B\u6570\
    \n    vector<int> ind(1 << N, 0);\n    // adj_bit[v] = v\u3068\u96A3\u63A5\u3057\
    \u3066\u308B\u9802\u70B9\u306E\u5834\u6240\u306Bbit\u3092\u7ACB\u3066\u305F\u3082\
    \u306E\n    vector<int> adj_bit(N, 0);\n    for(int i = 0; i < N; i++) {\n   \
    \     for(int j = 0; j < N; j++) if(G[i][j]) adj_bit[i] |= (1 << j);\n    }\n\
    \    ind[0] = 1;\n    for(int S = 1; S < (1 << N); S++) {\n        int v = __builtin_ctz(S);\n\
    \        ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~adj_bit[v]];\n   \
    \     if(ind[S] >= mod) ind[S] -= mod;\n    }\n    vector<ll> sum(1 << N);\n \
    \   for(int S = 0; S < (1 << N); S++) sum[S] = ((N - (int)__builtin_popcount(S))\
    \ & 1 ? mod-1 : 1);\n    for(int K = 1; K < N; K++) {\n        ll res = 0;\n \
    \       for(int S = 0; S < (1 << N); S++) {\n            (sum[S] *= ind[S]) %=\
    \ mod;\n            res += sum[S];\n        }\n        if(res % mod > 0) return\
    \ K;\n    } \n    return N;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2021-05-22 00:40:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/chromatic_number.test.cpp
documentation_of: graph/chromatic_number.hpp
layout: document
title: "\u5F69\u8272\u6570"
---
