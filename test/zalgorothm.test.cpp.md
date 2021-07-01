---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/z_algo.hpp
    title: string/z_algo.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/zalgorothm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \ long;\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define FOR(i, a, b) for(int i = (a); i < int(b); i++)\n#define\
    \ REP(i, n) FOR(i, 0, n)\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\n\
    constexpr int MOD = 1000000007;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4]\
    \ = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\n\
    int popcount(int x) { return __builtin_popcount(x); }\nll popcount(ll x) { return\
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 1 \"string/z_algo.hpp\"\
    \n// \u3059\u3079\u30660-indexed\n// n := |S| \u3068\u3059\u308B\u3002\n// s[i,j]\
    \ := s\u306E[i,j]\u306E\u7BC4\u56F2\u306E\u9023\u7D9A\u90E8\u5206\u6587\u5B57\u5217\
    \u3068\u3059\u308B\u3002\u3053\u306E\u3068\u304D\u3001\n// s[0, n-1](= s)\u3068\
    s[i, n-1]\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\
    \u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\n// \u8A08\u7B97\u91CF\
    \u306FO(|S|)\nvector<int> z_algo(const string &s) {\n    int c = 0, n = (int)s.size();\n\
    \    vector<int> z(n, 0);\n    for(int i = 1; i < n; i++) {\n        if(i + z[i\
    \ - c] < c + z[c]) {\n            z[i] = z[i - c];\n        } else {\n       \
    \     int j = max(0, c + z[c] - i);\n            while(i + j < n && s[j] == s[i\
    \ + j]) {\n                j++;\n            }\n            z[i] = j;\n      \
    \      c = i;\n        }\n    }\n    z[0] = n;\n    return z;\n}\n#line 4 \"test/zalgorothm.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin >> s;\n    auto z = z_algo(s);\n    for(int\
    \ i = 0; i < z.size(); i++) {\n        cout << z[i] << ' ';\n    }\n    cout <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../string/z_algo.hpp\"\n\nint main(){\n\
    \    string s;\n    cin >> s;\n    auto z = z_algo(s);\n    for(int i = 0; i <\
    \ z.size(); i++) {\n        cout << z[i] << ' ';\n    }\n    cout << \"\\n\";\n\
    }"
  dependsOn:
  - template/template.cpp
  - string/z_algo.hpp
  isVerificationFile: true
  path: test/zalgorothm.test.cpp
  requiredBy: []
  timestamp: '2021-07-01 11:58:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/zalgorothm.test.cpp
layout: document
redirect_from:
- /verify/test/zalgorothm.test.cpp
- /verify/test/zalgorothm.test.cpp.html
title: test/zalgorothm.test.cpp
---
