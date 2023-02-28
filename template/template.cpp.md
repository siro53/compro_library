---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/library-checker/data-structure/point-set-range-composite.cpp
    title: test/library-checker/data-structure/point-set-range-composite.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C.test.cpp
    title: test/aoj/aoj-ALDS1-1-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C_2.test.cpp
    title: test/aoj/aoj-ALDS1-1-C_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-5-D.test.cpp
    title: test/aoj/aoj-ALDS1-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2426.test.cpp
    title: test/aoj/aoj2426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2858.test.cpp
    title: test/aoj/aoj2858.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc104d.test.cpp
    title: test/atcoder/arc104d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/line-add-get-min.test.cpp
    title: test/library-checker/data-structure/line-add-get-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-queue.test.cpp
    title: test/library-checker/data-structure/persistent-queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-unionfind.test.cpp
    title: test/library-checker/data-structure/persistent-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/point-add-range-sum.test.cpp
    title: test/library-checker/data-structure/point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/segment-add-get-min.test.cpp
    title: test/library-checker/data-structure/segment-add-get-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/set-xor-min.test.cpp
    title: test/library-checker/data-structure/set-xor-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
    title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-sum.test.cpp
    title: test/library-checker/data-structure/static-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/unionfind.test.cpp
    title: test/library-checker/data-structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/scc.test.cpp
    title: test/library-checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/graph/shortest-path.test.cpp
    title: test/library-checker/graph/shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/math/two-sat.test.cpp
    title: test/library-checker/math/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/lowest-common-ancestor2.test.cpp
    title: test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/tree/tree-diameter.test.cpp
    title: test/library-checker/tree/tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/binary-trie.test.cpp
    title: test/mytest/data-structure/binary-trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki1435.test.cpp
    title: test/yukicoder/yuki1435.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki1750.test.cpp
    title: test/yukicoder/yuki1750.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki789.test.cpp
    title: test/yukicoder/yuki789.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\ntemplate <class T> inline bool chmax(T\
    \ &a, T b) {\n    if(a < b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\ntemplate <class T> inline bool chmin(T &a, T b) {\n    if(a > b) {\n\
    \        a = b;\n        return 1;\n    }\n    return 0;\n}\n#ifdef DEBUG\ntemplate\
    \ <class T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n\
    \    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate\
    \ <class T> ostream &operator<<(ostream &os, const vector<T> &v) {\n    os <<\
    \ '{';\n    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) { os << ',';\
    \ }\n        os << v[i];\n    }\n    os << '}';\n    return os;\n}\nvoid debugg()\
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
    \ }\n#pragma endregion Macros\n"
  code: "#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if(a < b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\ntemplate <class T> inline bool chmin(T\
    \ &a, T b) {\n    if(a > b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\n#ifdef DEBUG\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << '(' << p.first << ',' << p.second <<\
    \ ')';\n    return os;\n}\ntemplate <class T> ostream &operator<<(ostream &os,\
    \ const vector<T> &v) {\n    os << '{';\n    for(int i = 0; i < (int)v.size();\
    \ i++) {\n        if(i) { os << ','; }\n        os << v[i];\n    }\n    os <<\
    \ '}';\n    return os;\n}\nvoid debugg() { cerr << endl; }\ntemplate <class T,\
    \ class... Args>\nvoid debugg(const T &x, const Args &... args) {\n    cerr <<\
    \ \" \" << x;\n    debugg(args...);\n}\n#define debug(...)                   \
    \                                          \\\n    cerr << __LINE__ << \" [\"\
    \ << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n#define dump(x) cerr << __LINE__\
    \ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n\
    #define dump(x) (void(0))\n#endif\n\nstruct Setup {\n    Setup() {\n        cin.tie(0);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \    }\n} __Setup;\n\nusing ll = long long;\n#define OVERLOAD3(_1, _2, _3, name,\
    \ ...) name\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define REP1(i, n) for(int i = 0; i < int(n); i++)\n#define REP2(i,\
    \ a, b) for(int i = (a); i < int(b); i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\n#define REVERSE(v) reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\n\
    const int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\n\
    constexpr int MOD2 = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4]\
    \ = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\n\
    int popcount(int x) { return __builtin_popcount(x); }\nll popcount(ll x) { return\
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy:
  - test/library-checker/data-structure/point-set-range-composite.cpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki1750.test.cpp
  - test/yukicoder/yuki1435.test.cpp
  - test/yukicoder/yuki789.test.cpp
  - test/library-checker/math/two-sat.test.cpp
  - test/library-checker/graph/scc.test.cpp
  - test/library-checker/graph/shortest-path.test.cpp
  - test/library-checker/data-structure/persistent-unionfind.test.cpp
  - test/library-checker/data-structure/line-add-get-min.test.cpp
  - test/library-checker/data-structure/unionfind.test.cpp
  - test/library-checker/data-structure/set-xor-min.test.cpp
  - test/library-checker/data-structure/static-range-sum.test.cpp
  - test/library-checker/data-structure/segment-add-get-min.test.cpp
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/persistent-queue.test.cpp
  - test/library-checker/data-structure/point-add-range-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/tree/tree-diameter.test.cpp
  - test/library-checker/tree/lowest-common-ancestor2.test.cpp
  - test/library-checker/tree/lowest-common-ancestor.test.cpp
  - test/mytest/data-structure/binary-trie.test.cpp
  - test/aoj/aoj2426.test.cpp
  - test/aoj/aoj-ALDS1-1-C_2.test.cpp
  - test/aoj/aoj2858.test.cpp
  - test/aoj/aoj-ALDS1-1-C.test.cpp
  - test/aoj/aoj-ALDS1-5-D.test.cpp
  - test/aoj/aoj2821.test.cpp
  - test/atcoder/arc104d.test.cpp
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
