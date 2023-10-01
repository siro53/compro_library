---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: data-structure/BIT.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library-checker/data-structure/static-range-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line\
    \ 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/BIT.hpp\"\n\n#line 5 \"\
    data-structure/BIT.hpp\"\n\ntemplate <typename T> class BIT {\n  public:\n   \
    \ BIT() = default;\n    explicit BIT(int N) : N(N), dat(N + 1, 0) {}\n    T sum(int\
    \ r) {\n        T ret = 0;\n        for(; r >= 1; r -= lsb(r)) ret += dat[r];\n\
    \        return ret;\n    }\n    T sum(int l, int r) {\n        assert(l <= r);\n\
    \        if(l == r) return T(0);\n        return (sum(r) - sum(l));\n    }\n \
    \   void add(int pos, T val) {\n        for(int i = pos + 1; i <= N; i += lsb(i))\
    \ dat[i] += val;\n    }\n    int lower_bound(T val) {\n        int pos = 0;\n\
    \        int k = 1;\n        while(2 * k <= N) k <<= 1;\n        for(; k >= 1;\
    \ k >>= 1) {\n            if(pos + k <= N and dat[pos + k] < val) {\n        \
    \        pos += k;\n                val -= dat[pos];\n            }\n        }\n\
    \        return pos + 1;\n    }\n\n  private:\n    int N;\n    std::vector<T>\
    \ dat;\n\n    inline int lsb(int i) { return i & (-i); }\n};\n#line 4 \"test/library-checker/data-structure/static-range-sum.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    BIT<ll> bt(N);\n    REP(i,\
    \ N) {\n        ll a;\n        cin >> a;\n        bt.add(i, a);\n    }\n    while(Q--)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        cout << bt.sum(l, r) <<\
    \ '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../../../template/template.cpp\"\n#include \"../../../data-structure/BIT.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    BIT<ll> bt(N);\n    REP(i,\
    \ N) {\n        ll a;\n        cin >> a;\n        bt.add(i, a);\n    }\n    while(Q--)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        cout << bt.sum(l, r) <<\
    \ '\\n';\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/static-range-sum.test.cpp
- /verify/test/library-checker/data-structure/static-range-sum.test.cpp.html
title: test/library-checker/data-structure/static-range-sum.test.cpp
---
