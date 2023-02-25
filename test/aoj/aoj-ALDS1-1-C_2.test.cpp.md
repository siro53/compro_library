---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes.hpp
    title: math/eratosthenes.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp
  bundledCode: "#line 1 \"test/aoj/aoj-ALDS1-1-C_2.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp\"\n\
    #line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define REVERSE(v)\
    \ reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 2 \"math/eratosthenes.hpp\"\n\n#line 4 \"\
    math/eratosthenes.hpp\"\n\nclass Eratosthenes {\n  public:\n    Eratosthenes()\
    \ {}\n    explicit Eratosthenes(int n) : n(n), isp(n + 1, true) {\n        isp[0]\
    \ = isp[1] = false;\n        for(int i = 2; i * i <= n; i++) {\n            if(!isp[i])\
    \ continue;\n            for(int j = i * i; j <= n; j += i) isp[j] = false;\n\
    \        }\n    }\n    bool operator[](int k) const { return isp[k]; }\n\n  private:\n\
    \    int n;\n    std::vector<bool> isp;\n};\n#line 4 \"test/aoj/aoj-ALDS1-1-C_2.test.cpp\"\
    \n\nint main() {\n    int t; \n    cin >> t;\n    Eratosthenes isp(100000000);\n\
    \    int ans = 0;\n    while(t--) {\n        int n; \n        cin >> n;\n    \
    \    ans += isp[n];\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp\"\
    \n#include \"../../template/template.cpp\"\n#include \"../../math/eratosthenes.hpp\"\
    \n\nint main() {\n    int t; \n    cin >> t;\n    Eratosthenes isp(100000000);\n\
    \    int ans = 0;\n    while(t--) {\n        int n; \n        cin >> n;\n    \
    \    ans += isp[n];\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - template/template.cpp
  - math/eratosthenes.hpp
  isVerificationFile: true
  path: test/aoj/aoj-ALDS1-1-C_2.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/aoj-ALDS1-1-C_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/aoj-ALDS1-1-C_2.test.cpp
- /verify/test/aoj/aoj-ALDS1-1-C_2.test.cpp.html
title: test/aoj/aoj-ALDS1-1-C_2.test.cpp
---
