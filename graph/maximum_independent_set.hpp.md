---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/maximum_independent_set.test.cpp
    title: test/maximum_independent_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/maximum_independent_set.hpp\"\nvector<int> maximum_independent_set(int\
    \ N, vector<vector<int>> G) {\n    int n1 = N / 2, n2 = N - n1;\n \n    // ok1[S1]\
    \ = S1\u304C\u72EC\u7ACB\u96C6\u5408\u304B\u3069\u3046\u304B\n    vector<bool>\
    \ ok1(1 << n1, true);\n    for(int u = 0; u < n1; u++) {\n        for(int v =\
    \ 0; v < u; v++) {\n            if(G[u][v]) ok1[(1 << u) | (1 << v)] = false;\n\
    \        }\n    }\n    for(int S = 0; S < (1 << n1); S++) {\n        if(ok1[S])\
    \ continue;\n        for(int v = 0; v < n1; v++) {\n            if(S >> v & 1)\
    \ continue;\n            ok1[S | (1 << v)] = false;\n        }\n    }\n    //\
    \ Set[S1] = S1\u306E\u9802\u70B9\u3068\u8FBA\u3067\u7D50\u3070\u308C\u3066\u306A\
    \u3044v2\u306E\u9802\u70B9\u96C6\u5408U\n    vector<int> Set(1 << n1, 0);\n  \
    \  Set[0] = (1 << n2) - 1;\n    for(int u = 0; u < n1; u++) {\n        for(int\
    \ v = 0; v < n2; v++) {\n            if(G[u][v + n1] == 0) Set[1 << u] |= (1 <<\
    \ v);\n        }\n    }\n    for(int S = 0; S < (1 << n1); S++) {\n        for(int\
    \ u = 0; u < n1; u++) {\n            if(S >> u & 1) continue;\n            Set[S\
    \ | (1 << u)] = Set[S] & Set[1 << u];\n        }\n    }\n    // dp[S2] = V2\u306E\
    \u90E8\u5206\u96C6\u5408S2\u306E\u6700\u5927\u72EC\u7ACB\u96C6\u5408\u306E\u30B5\
    \u30A4\u30BA\n    vector<int> dp(1 << n2), pre(1 << n2, -1);\n    for(int S =\
    \ 0; S < (1 << n2); S++) dp[S] = __builtin_popcount(S);\n    for(int u = 0; u\
    \ < n2; u++) {\n        for(int v = 0; v < u; v++) {\n            if(G[u + n1][v\
    \ + n1]) dp[(1 << u) | (1 << v)] = 0;\n        }\n    }\n    for(int S = 1; S\
    \ < (1 << n2); S++) {\n        if(dp[S] > 0) continue;\n        for(int v = 0;\
    \ v < n2; v++) {\n            if(S >> v & 1) continue;\n            dp[S | (1\
    \ << v)] = 0;\n        }\n    }\n    for(int S = 0; S < (1 << n2); S++) {\n  \
    \      for(int u = 0; u < n2; u++) {\n            if(S >> u & 1) continue;\n \
    \           if(dp[S | (1 << u)] < dp[S]) {\n                dp[S | (1 << u)] =\
    \ dp[S];\n                pre[S | (1 << u)] = S;\n            }\n        }\n \
    \   }\n    // \u5FA9\u5143\n    int max_size = 0;\n    int res_S1 = -1, res_S2\
    \ = -1;\n    for(int S1 = 0; S1 < (1 << n1); S1++) {\n        if(!ok1[S1]) continue;\n\
    \        int sz1 = __builtin_popcount(S1);\n        if(max_size < sz1 + dp[Set[S1]])\
    \ {\n            max_size = sz1 + dp[Set[S1]];\n            res_S1 = S1, res_S2\
    \ = Set[S1];\n        }\n    }\n    vector<int> res;\n    for(int i = 0; i < n1;\
    \ i++) if(res_S1 >> i & 1) res.push_back(i);\n    int now = res_S2;\n    while(pre[now]\
    \ != -1) {\n        int T = now ^ pre[now];\n        now = pre[now];\n    }\n\
    \    for(int i = 0; i < n2; i++) if(now >> i & 1) res.push_back(i+n1);\n    return\
    \ res;\n}\n"
  code: "vector<int> maximum_independent_set(int N, vector<vector<int>> G) {\n   \
    \ int n1 = N / 2, n2 = N - n1;\n \n    // ok1[S1] = S1\u304C\u72EC\u7ACB\u96C6\
    \u5408\u304B\u3069\u3046\u304B\n    vector<bool> ok1(1 << n1, true);\n    for(int\
    \ u = 0; u < n1; u++) {\n        for(int v = 0; v < u; v++) {\n            if(G[u][v])\
    \ ok1[(1 << u) | (1 << v)] = false;\n        }\n    }\n    for(int S = 0; S <\
    \ (1 << n1); S++) {\n        if(ok1[S]) continue;\n        for(int v = 0; v <\
    \ n1; v++) {\n            if(S >> v & 1) continue;\n            ok1[S | (1 <<\
    \ v)] = false;\n        }\n    }\n    // Set[S1] = S1\u306E\u9802\u70B9\u3068\u8FBA\
    \u3067\u7D50\u3070\u308C\u3066\u306A\u3044v2\u306E\u9802\u70B9\u96C6\u5408U\n\
    \    vector<int> Set(1 << n1, 0);\n    Set[0] = (1 << n2) - 1;\n    for(int u\
    \ = 0; u < n1; u++) {\n        for(int v = 0; v < n2; v++) {\n            if(G[u][v\
    \ + n1] == 0) Set[1 << u] |= (1 << v);\n        }\n    }\n    for(int S = 0; S\
    \ < (1 << n1); S++) {\n        for(int u = 0; u < n1; u++) {\n            if(S\
    \ >> u & 1) continue;\n            Set[S | (1 << u)] = Set[S] & Set[1 << u];\n\
    \        }\n    }\n    // dp[S2] = V2\u306E\u90E8\u5206\u96C6\u5408S2\u306E\u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408\u306E\u30B5\u30A4\u30BA\n    vector<int> dp(1 <<\
    \ n2), pre(1 << n2, -1);\n    for(int S = 0; S < (1 << n2); S++) dp[S] = __builtin_popcount(S);\n\
    \    for(int u = 0; u < n2; u++) {\n        for(int v = 0; v < u; v++) {\n   \
    \         if(G[u + n1][v + n1]) dp[(1 << u) | (1 << v)] = 0;\n        }\n    }\n\
    \    for(int S = 1; S < (1 << n2); S++) {\n        if(dp[S] > 0) continue;\n \
    \       for(int v = 0; v < n2; v++) {\n            if(S >> v & 1) continue;\n\
    \            dp[S | (1 << v)] = 0;\n        }\n    }\n    for(int S = 0; S < (1\
    \ << n2); S++) {\n        for(int u = 0; u < n2; u++) {\n            if(S >> u\
    \ & 1) continue;\n            if(dp[S | (1 << u)] < dp[S]) {\n               \
    \ dp[S | (1 << u)] = dp[S];\n                pre[S | (1 << u)] = S;\n        \
    \    }\n        }\n    }\n    // \u5FA9\u5143\n    int max_size = 0;\n    int\
    \ res_S1 = -1, res_S2 = -1;\n    for(int S1 = 0; S1 < (1 << n1); S1++) {\n   \
    \     if(!ok1[S1]) continue;\n        int sz1 = __builtin_popcount(S1);\n    \
    \    if(max_size < sz1 + dp[Set[S1]]) {\n            max_size = sz1 + dp[Set[S1]];\n\
    \            res_S1 = S1, res_S2 = Set[S1];\n        }\n    }\n    vector<int>\
    \ res;\n    for(int i = 0; i < n1; i++) if(res_S1 >> i & 1) res.push_back(i);\n\
    \    int now = res_S2;\n    while(pre[now] != -1) {\n        int T = now ^ pre[now];\n\
    \        now = pre[now];\n    }\n    for(int i = 0; i < n2; i++) if(now >> i &\
    \ 1) res.push_back(i+n1);\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2021-05-20 11:52:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/maximum_independent_set.test.cpp
documentation_of: graph/maximum_independent_set.hpp
layout: document
title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408"
---
