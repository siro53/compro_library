---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: data-structure/BIT.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: "\u5EA7\u5727"
  - icon: ':heavy_check_mark:'
    path: misc/inversion-number.hpp
    title: "\u8EE2\u5012\u6570"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
  bundledCode: "#line 1 \"test/aoj/aoj-ALDS1-5-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\
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
    \ }\n#pragma endregion Macros\n#line 2 \"misc/compress.hpp\"\n\n#line 5 \"misc/compress.hpp\"\
    \n\ntemplate <typename T> class Compress {\n  public:\n    Compress() = default;\n\
    \    explicit Compress(const std::vector<T> &v) : dat(v) {\n        build();\n\
    \    }\n    void push_back(T val) { dat.push_back(val); }\n\tvoid build() {\n\t\
    \tstd::sort(dat.begin(), dat.end());\n        dat.erase(std::unique(dat.begin(),\
    \ dat.end()), dat.end());\n\t}\n    int get(T val) const {\n        int pos =\
    \ std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();\n        return\
    \ pos;\n    }\n    T operator[](int i) const { return dat[i]; }\n    size_t size()\
    \ const { return dat.size(); }\n\n  private:\n    std::vector<T> dat;\n};\n#line\
    \ 2 \"misc/inversion-number.hpp\"\n\n#line 2 \"data-structure/BIT.hpp\"\n\n#line\
    \ 5 \"data-structure/BIT.hpp\"\n\ntemplate <typename T> class BIT {\n  public:\n\
    \    BIT() = default;\n    explicit BIT(int N) : N(N), dat(N + 1, 0) {}\n    T\
    \ sum(int r) {\n        T ret = 0;\n        for(; r >= 1; r -= lsb(r)) ret +=\
    \ dat[r];\n        return ret;\n    }\n    T sum(int l, int r) {\n        assert(l\
    \ <= r);\n        if(l == r) return T(0);\n        return (sum(r) - sum(l));\n\
    \    }\n    void add(int pos, T val) {\n        for(int i = pos + 1; i <= N; i\
    \ += lsb(i)) dat[i] += val;\n    }\n    int lower_bound(T val) {\n        int\
    \ pos = 0;\n        int k = 1;\n        while(2 * k <= N) k <<= 1;\n        for(;\
    \ k >= 1; k >>= 1) {\n            if(pos + k <= N and dat[pos + k] < val) {\n\
    \                pos += k;\n                val -= dat[pos];\n            }\n\
    \        }\n        return pos + 1;\n    }\n\n  private:\n    int N;\n    std::vector<T>\
    \ dat;\n\n    inline int lsb(int i) { return i & (-i); }\n};\n#line 4 \"misc/inversion-number.hpp\"\
    \n\ntemplate<class T>\nT inversion_number(const std::vector<int>& v) {\n    int\
    \ N = (int)v.size();\n    BIT<int> bt(N);\n    T res = 0;\n    for(int i = 0;\
    \ i < N; i++) {\n        res += i - bt.sum(v[i]+1);\n        bt.add(v[i], 1);\n\
    \    }\n    return res;\n}\n#line 5 \"test/aoj/aoj-ALDS1-5-D.test.cpp\"\n\nint\
    \ main() {\n    int N;\n    cin >> N;\n    vector<int> a(N);\n    REP(i, N) cin\
    \ >> a[i];\n    \n    Compress<int> comp(a);\n    vector<int> v(N);\n    REP(i,\
    \ N) v[i] = comp.get(a[i]);\n\n    cout << inversion_number<ll>(v) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\n\
    #include \"../../template/template.cpp\"\n#include \"../../misc/compress.hpp\"\
    \n#include \"../../misc/inversion-number.hpp\"\n\nint main() {\n    int N;\n \
    \   cin >> N;\n    vector<int> a(N);\n    REP(i, N) cin >> a[i];\n    \n    Compress<int>\
    \ comp(a);\n    vector<int> v(N);\n    REP(i, N) v[i] = comp.get(a[i]);\n\n  \
    \  cout << inversion_number<ll>(v) << endl;\n}"
  dependsOn:
  - template/template.cpp
  - misc/compress.hpp
  - misc/inversion-number.hpp
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/aoj/aoj-ALDS1-5-D.test.cpp
  requiredBy: []
  timestamp: '2023-09-30 04:41:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/aoj-ALDS1-5-D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/aoj-ALDS1-5-D.test.cpp
- /verify/test/aoj/aoj-ALDS1-5-D.test.cpp.html
title: test/aoj/aoj-ALDS1-5-D.test.cpp
---
