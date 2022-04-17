---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/disjoint_sparse_table.hpp
    title: data_structure/disjoint_sparse_table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ Macros\n#line 1 \"data_structure/disjoint_sparse_table.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()> \nclass DisjointSparseTable {\n    vector<vector<S>>\
    \ table;\n    vector<int> lookup;\n\npublic:\n    DisjointSparseTable() {}\n \
    \   DisjointSparseTable(vector<S> v) {\n        int b = 0;\n        while((1 <<\
    \ b) <= (int)v.size()) b++;\n        table.resize(b, vector<S>(v.size(), e()));\n\
    \n        for(int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n       \
    \ for(int i = 1; i < b; i++) {\n            int shift = (1 << i);\n          \
    \  for(int j = 0; j < (int)v.size(); j += (shift << 1)) {\n                int\
    \ t = min(j + shift, (int)v.size());\n                table[i][t-1] = v[t-1];\n\
    \                for(int k = t - 2; k >= j; k--) table[i][k] = op(v[k], table[i][k\
    \ + 1]);\n                if((int)v.size() <= t) break;\n                table[i][t]\
    \ = v[t];\n                int r = min(t + shift, (int)v.size());\n          \
    \      for(int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], v[k]);\n\
    \            }\n        }\n        lookup.resize(1 << b);\n        for(int i =\
    \ 2; i < (int)lookup.size(); i++) {\n            lookup[i] = lookup[i >> 1] +\
    \ 1;\n        }\n    }\n\n    S prod(int l, int r) {\n        if(l >= --r) return\
    \ table[0][l];\n        int p = lookup[l ^ r];\n        return op(table[p][l],\
    \ table[p][r]);\n    }\n};\n#line 5 \"test/staticrmq.test.cpp\"\n\nint op(int\
    \ a, int b) { return min(a, b); }\nint e() { return INF; }\n\nint main(){\n  \
    \  int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for(int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    DisjointSparseTable<int, op, e>\
    \ dst(a);\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n     \
    \   cout << dst.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../template/template.cpp\"\n#include \"../data_structure/disjoint_sparse_table.hpp\"\
    \n\nint op(int a, int b) { return min(a, b); }\nint e() { return INF; }\n\nint\
    \ main(){\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for(int\
    \ i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    DisjointSparseTable<int,\
    \ op, e> dst(a);\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n\
    \        cout << dst.prod(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2022-04-17 17:28:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/staticrmq.test.cpp
- /verify/test/staticrmq.test.cpp.html
title: test/staticrmq.test.cpp
---
