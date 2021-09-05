---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/BIT.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: data_structure/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
  bundledCode: "#line 1 \"test/inversion_number.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 1 \"data_structure/compress.hpp\"\
    \ntemplate <typename T> struct Compress {\n    vector<T> v;\n    Compress() {}\n\
    \    Compress(vector<T> vv) : v(vv) {\n        sort(ALL(v));\n        v.erase(unique(ALL(v)),\
    \ end(v));\n    }\n    void build(vector<T> vv) {\n        v = vv;\n        sort(ALL(v));\n\
    \        v.erase(unique(ALL(v)), end(v));\n    }\n    int get(T x) { return (int)(lower_bound(ALL(v),\
    \ x) - v.begin()); }\n    T &operator[](int i) { return v[i]; }\n    size_t size()\
    \ { return v.size(); }\n};\n#line 1 \"data_structure/BIT.hpp\"\ntemplate <typename\
    \ T> struct BIT {\n    int n;\n    vector<T> bit;\n    BIT(){}\n    BIT(int _n)\
    \ { init(_n); }\n    void init(int _n) {\n        n = _n + 1;\n        bit.resize(n\
    \ + 1, 0);\n    }\n    // [0, k)\n    T sum(int k) {\n        T res = 0;\n   \
    \     for(int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) { res += bit[i]; }\n \
    \       return res;\n    }\n    // [l, r)\n    T sum(int l, int r) { return (l\
    \ < r ? sum(r) - sum(l) : 0); }\n    // bit[k] += x\n    void add(int k, T x)\
    \ {\n        for(int i = k; i < n; i |= i + 1) { bit[i] += x; }\n    }\n    //\
    \ v[0] + ... + v[res] >= x\n    int lower_bound(T x) {\n        int res = -1;\n\
    \        int k = 1;\n        while(2 * k <= n) { k <<= 1; }\n        for(; k >\
    \ 0; k >>= 1) {\n            if(res + k < n && bit[res + k] < x) {\n         \
    \       x -= bit[res + k];\n                res += k;\n            }\n       \
    \ }\n        return res + 1;\n    }\n};\n#line 2 \"data_structure/inversion_number.hpp\"\
    \n\n// v\u306F {0, 1, ... , N-1} \u304B\u3089\u306A\u308B\u91CD\u8907\u3092\u8A31\
    \u3057\u305F\u6570\u5217\n// \u3053\u306E\u6570\u5217\u306E\u8EE2\u5012\u6570\u3092\
    \u8FD4\u3059\ntemplate<class T>\nT inversion_number(const vector<int>& v) {\n\
    \    int N = (int)v.size();\n    BIT<int> bt(N);\n    T res = 0;\n    for(int\
    \ i = 0; i < N; i++) {\n        res += i - bt.sum(v[i]+1);\n        bt.add(v[i],\
    \ 1);\n    }\n    return res;\n}\n#line 5 \"test/inversion_number.test.cpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<int> a(N);\n    REP(i, N)\
    \ cin >> a[i];\n    \n    Compress<int> comp(a);\n    vector<int> v(N);\n    REP(i,\
    \ N) v[i] = comp.get(a[i]);\n\n    cout << inversion_number<ll>(v) << \"\\n\"\
    ;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\n\
    #include \"../template/template.cpp\"\n#include \"../data_structure/compress.hpp\"\
    \n#include \"../data_structure/inversion_number.hpp\"\n\nint main() {\n    int\
    \ N;\n    cin >> N;\n    vector<int> a(N);\n    REP(i, N) cin >> a[i];\n    \n\
    \    Compress<int> comp(a);\n    vector<int> v(N);\n    REP(i, N) v[i] = comp.get(a[i]);\n\
    \n    cout << inversion_number<ll>(v) << \"\\n\";\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/compress.hpp
  - data_structure/inversion_number.hpp
  - data_structure/BIT.hpp
  isVerificationFile: true
  path: test/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 16:29:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/test/inversion_number.test.cpp
- /verify/test/inversion_number.test.cpp.html
title: test/inversion_number.test.cpp
---
