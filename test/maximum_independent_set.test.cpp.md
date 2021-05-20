---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/maximum_independent_set.hpp
    title: graph/maximum_independent_set.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/maximum_independent_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n#line 1 \"template/template.cpp\"\
    \n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if(a < b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\ntemplate <class T> inline bool chmin(T\
    \ &a, T b) {\n    if(a > b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\n#ifdef DEBUG\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << '(' << p.first << ',' << p.second <<\
    \ ')';\n    return os;\n}\ntemplate <class T> ostream &operator<<(ostream &os,\
    \ const vector<T> &v) {\n    os << '{';\n    for(int i = 0; i < (int)v.size();\
    \ i++) {\n        if(i) { os << ','; }\n        os << v[i];\n    }\n    os <<\
    \ '}';\n    return os;\n}\nvoid debugg() { cerr << endl; }\ntemplate <class T,\
    \ class... Args>\nvoid debugg(const T &x, const Args &... args) {\n    cerr <<\
    \ \" \" << x;\n    debugg(args...);\n}\n#define debug(...)                   \
    \                                          \\\n    cerr << __LINE__ << \" [\"\
    \ << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n#define dump(x) cerr << __LINE__\
    \ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n\
    #define dump(x) (void(0))\n#endif\n\nstruct Setup {\n    Setup() {\n        cin.tie(0);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \    }\n} __Setup;\n\nusing ll = long long;\n#define ALL(v) (v).begin(), (v).end()\n\
    #define RALL(v) (v).rbegin(), (v).rend()\n#define FOR(i, a, b) for(int i = (a);\
    \ i < int(b); i++)\n#define REP(i, n) FOR(i, 0, n)\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconst int dx[4]\
    \ = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout\
    \ << \"Case #\" << i << \": \"; }\n#pragma endregion Macros\n#line 1 \"graph/maximum_independent_set.hpp\"\
    \nvector<int> maximum_independent_set(int N, vector<vector<int>> G) {\n    int\
    \ n1 = N / 2, n2 = N - n1;\n \n    // ok1[S1] = S1\u304C\u72EC\u7ACB\u96C6\u5408\
    \u304B\u3069\u3046\u304B\n    vector<bool> ok1(1 << n1, true);\n    for(int u\
    \ = 0; u < n1; u++) {\n        for(int v = 0; v < u; v++) {\n            if(G[u][v])\
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
    \ 1) res.push_back(i+n1);\n    return res;\n}\n#line 4 \"test/maximum_independent_set.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    vector G(N, vector<int>(N,\
    \ 0));\n    REP(i, M) {\n        int u, v;\n        cin >> u >> v;\n        G[u][v]\
    \ = G[v][u] = 1;\n    }\n\n    auto res = maximum_independent_set(N, G);\n   \
    \ cout << res.size() << \"\\n\";\n    REP(i, res.size()) cout << res[i] << \"\
    \ \\n\"[i + 1 == res.size()];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n#include \"../template/template.cpp\"\n#include \"../graph/maximum_independent_set.hpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    vector G(N, vector<int>(N,\
    \ 0));\n    REP(i, M) {\n        int u, v;\n        cin >> u >> v;\n        G[u][v]\
    \ = G[v][u] = 1;\n    }\n\n    auto res = maximum_independent_set(N, G);\n   \
    \ cout << res.size() << \"\\n\";\n    REP(i, res.size()) cout << res[i] << \"\
    \ \\n\"[i + 1 == res.size()];\n}"
  dependsOn:
  - template/template.cpp
  - graph/maximum_independent_set.hpp
  isVerificationFile: true
  path: test/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2021-05-20 11:52:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/maximum_independent_set.test.cpp
- /verify/test/maximum_independent_set.test.cpp.html
title: test/maximum_independent_set.test.cpp
---
