---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic_number.hpp
    title: "\u5F69\u8272\u6570"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/chromatic_number.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\
    \n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    using namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
    \ < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate\
    \ <class T> inline bool chmin(T &a, T b) {\n    if(a > b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\n#ifdef DEBUG\ntemplate <class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n    os <<\
    \ '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate <class\
    \ T> ostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '{';\n\
    \    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) { os << ','; }\n\
    \        os << v[i];\n    }\n    os << '}';\n    return os;\n}\nvoid debugg()\
    \ { cerr << endl; }\ntemplate <class T, class... Args>\nvoid debugg(const T &x,\
    \ const Args &... args) {\n    cerr << \" \" << x;\n    debugg(args...);\n}\n\
    #define debug(...)                                                           \
    \  \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nstruct Setup\
    \ {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\n\nusing ll = long\
    \ long;\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n#define ALL(v) (v).begin(),\
    \ (v).end()\n#define RALL(v) (v).rbegin(), (v).rend()\n#define REP1(i, n) for(int\
    \ i = 0; i < (n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b); i++)\n\
    #define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\nconst int INF\
    \ = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconst\
    \ int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int\
    \ i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"graph/chromatic_number.hpp\"\n// \u5F69\u8272\u6570 O(n*2^n)\n\
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
    \    return N;\n}\n#line 4 \"test/chromatic_number.test.cpp\"\n\nint main() {\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N, vector<int>(N,\
    \ 0));\n    REP(i, M) {\n        int u, v;\n        cin >> u >> v;\n        G[u][v]\
    \ = G[v][u] = 1;\n    }\n    cout << chromatic_number(N, G) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../graph/chromatic_number.hpp\"\n\n\
    int main() {\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N,\
    \ vector<int>(N, 0));\n    REP(i, M) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        G[u][v] = G[v][u] = 1;\n    }\n    cout << chromatic_number(N, G)\
    \ << \"\\n\";\n}"
  dependsOn:
  - template/template.cpp
  - graph/chromatic_number.hpp
  isVerificationFile: true
  path: test/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2021-10-01 13:55:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/chromatic_number.test.cpp
- /verify/test/chromatic_number.test.cpp.html
title: test/chromatic_number.test.cpp
---
