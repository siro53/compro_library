---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/BIT.hpp
    title: Binary Indexed Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/staticrangesum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
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
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v)\
    \ ((int)(v).size())\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr\
    \ int MOD = 1000000007;\nconstexpr int MOD2 = 998244353;\nconst int dx[4] = {1,\
    \ 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"\
    Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"data_structure/BIT.hpp\"\ntemplate <typename T> struct BIT\
    \ {\n    int n;\n    vector<T> bit;\n    BIT(){}\n    BIT(int _n) { init(_n);\
    \ }\n    void init(int _n) {\n        n = _n + 1;\n        bit.resize(n + 1, 0);\n\
    \    }\n    // [0, k)\n    T sum(int k) {\n        T res = 0;\n        for(int\
    \ i = k - 1; i >= 0; i = (i & (i + 1)) - 1) { res += bit[i]; }\n        return\
    \ res;\n    }\n    // [l, r)\n    T sum(int l, int r) { return (l < r ? sum(r)\
    \ - sum(l) : 0); }\n    // bit[k] += x\n    void add(int k, T x) {\n        for(int\
    \ i = k; i < n; i |= i + 1) { bit[i] += x; }\n    }\n    // v[0] + ... + v[res]\
    \ >= x\n    int lower_bound(T x) {\n        int res = -1;\n        int k = 1;\n\
    \        while(2 * k <= n) { k <<= 1; }\n        for(; k > 0; k >>= 1) {\n   \
    \         if(res + k < n && bit[res + k] < x) {\n                x -= bit[res\
    \ + k];\n                res += k;\n            }\n        }\n        return res\
    \ + 1;\n    }\n};\n#line 4 \"test/staticrangesum.test.cpp\"\n\nint main(){\n \
    \   int N, Q;\n    cin >> N >> Q;\n    BIT<ll> bit(N);\n    REP(i, N){\n     \
    \   int a; cin >> a;\n        bit.add(i, a);\n    }\n\n    while(Q--){\n     \
    \   int l, r;\n        cin >> l >> r;\n        cout << bit.sum(l, r) << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../data_structure/BIT.hpp\"\n\nint\
    \ main(){\n    int N, Q;\n    cin >> N >> Q;\n    BIT<ll> bit(N);\n    REP(i,\
    \ N){\n        int a; cin >> a;\n        bit.add(i, a);\n    }\n\n    while(Q--){\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << bit.sum(l, r) << \"\
    \\n\";\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/BIT.hpp
  isVerificationFile: true
  path: test/staticrangesum.test.cpp
  requiredBy: []
  timestamp: '2021-11-14 12:43:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/staticrangesum.test.cpp
layout: document
redirect_from:
- /verify/test/staticrangesum.test.cpp
- /verify/test/staticrangesum.test.cpp.html
title: test/staticrangesum.test.cpp
---
