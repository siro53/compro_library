---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dsu.hpp
    title: UnionFind
  - icon: ':question:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/union-find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
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
    #define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v)\
    \ sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconst int dx[4]\
    \ = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout\
    \ << \"Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n#line 1 \"graph/dsu.hpp\"\nstruct UnionFind {\n    vector<int> par;\n\
    \n    UnionFind(int n) : par(n, -1) {}\n    void init(int n) { par.assign(n, -1);\
    \ }\n\n    int root(int x) {\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = root(par[x]);\n    }\n\n    bool issame(int\
    \ x, int y) { return root(x) == root(y); }\n\n    bool merge(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if(x == y)\n            return\
    \ false;\n        if(par[x] > par[y])\n            swap(x, y); // merge technique\n\
    \        par[x] += par[y];\n        par[y] = x;\n        return true;\n    }\n\
    \n    int size(int x) { return -par[root(x)]; }\n};\n#line 4 \"test/union-find.test.cpp\"\
    \n\nint main(){\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n   \
    \ while(q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if(t\
    \ == 0) {\n            uf.merge(u, v);\n        } else {\n            cout <<\
    \ uf.issame(u, v) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../template/template.cpp\"\n#include \"../graph/dsu.hpp\"\n\nint main(){\n   \
    \ int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    while(q--) {\n    \
    \    int t, u, v;\n        cin >> t >> u >> v;\n        if(t == 0) {\n       \
    \     uf.merge(u, v);\n        } else {\n            cout << uf.issame(u, v) <<\
    \ endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - graph/dsu.hpp
  isVerificationFile: true
  path: test/union-find.test.cpp
  requiredBy: []
  timestamp: '2021-10-04 10:02:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/union-find.test.cpp
layout: document
redirect_from:
- /verify/test/union-find.test.cpp
- /verify/test/union-find.test.cpp.html
title: test/union-find.test.cpp
---
