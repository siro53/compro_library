---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: math/pow_mod.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/aoj/aoj-ALDS1-1-C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp\"\
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
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define REVERSE(v)\
    \ reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 2 \"math/is-prime.hpp\"\n\n#line 4 \"math/is-prime.hpp\"\
    \n\n#line 2 \"math/pow_mod.hpp\"\n\nconstexpr long long pow_mod(long long x, long\
    \ long k, long long m) {\n    long long res = 1;\n    long long mul = (x >= 0\
    \ ? x % m : x % m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res\
    \ * mul % m;\n        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n   \
    \ }\n    return res;\n}\n#line 6 \"math/is-prime.hpp\"\n\n/*\nref: Fast Primality\
    \ Testing for Integers That Fit into a Machine Word\nMichal Fori\u02C7sek and\
    \ Jakub Jan\u02C7cina\n*/\n\nconstexpr bool is_prime(int n) {\n    if(n <= 1)\
    \ return false;\n    if(n == 2 or n == 7 or n == 61) return true;\n    if((n &\
    \ 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0) d\
    \ >>= 1;\n    constexpr std::array<int, 3> bases = {2, 7, 61};\n    for(int a\
    \ : bases) {\n        long long t = d;\n        long long y = pow_mod(a, t, n);\n\
    \        while(t != n - 1 && y != 1 && y != n - 1) {\n            (y *= y) %=\
    \ n;\n            t <<= 1;\n        }\n        if(y != n - 1 && (t & 1) == 0)\
    \ return false;\n    }\n    return true;\n}\n\nconstexpr bool is_prime(long long\
    \ n) {\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if((n &\
    \ 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0) d\
    \ >>= 1;\n    constexpr std::array<long long, 7> bases = {\n        2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022\n    };\n    for(long long a : bases) {\n\
    \        a %= n;\n        if(a == 0) continue;\n        long long t = d;\n   \
    \     long long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 && y\
    \ != n - 1) {\n            y = (__int128_t)y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return\
    \ true;\n}\n#line 4 \"test/aoj/aoj-ALDS1-1-C.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    cin >> n;\n    int ans = 0;\n    while(n--) {\n        int p;\n    \
    \    cin >> p;\n        ans += is_prime(p);\n    }\n    cout << ans << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp\"\
    \n#include \"../../template/template.cpp\"\n#include \"../../math/is-prime.hpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    int ans = 0;\n    while(n--)\
    \ {\n        int p;\n        cin >> p;\n        ans += is_prime(p);\n    }\n \
    \   cout << ans << endl;\n}"
  dependsOn:
  - template/template.cpp
  - math/is-prime.hpp
  - math/pow_mod.hpp
  isVerificationFile: true
  path: test/aoj/aoj-ALDS1-1-C.test.cpp
  requiredBy: []
  timestamp: '2023-10-01 12:06:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/aoj-ALDS1-1-C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/aoj-ALDS1-1-C.test.cpp
- /verify/test/aoj/aoj-ALDS1-1-C.test.cpp.html
title: test/aoj/aoj-ALDS1-1-C.test.cpp
---
