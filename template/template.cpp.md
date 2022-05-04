---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ2426.test.cpp
    title: test/AOJ2426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ2748.test.cpp
    title: test/AOJ2748.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ2821.test.cpp
    title: test/AOJ2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ2858.test.cpp
    title: test/AOJ2858.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Hopcroft-Karp.test.cpp
    title: test/Hopcroft-Karp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/a_plus_b.test.cpp
    title: test/a_plus_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/chromatic_number.test.cpp
    title: test/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/determinant.test.cpp
    title: test/determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dinic.test.cpp
    title: test/dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/erathosthenes.test.cpp
    title: test/erathosthenes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/euler_phi.test.cpp
    title: test/euler_phi.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fast_factorize.test.cpp
    title: test/fast_factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/is_prime.test.cpp
    title: test/is_prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lca.test.cpp
    title: test/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/line_add_get_min.test.cpp
    title: test/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/maximum_independent_set.test.cpp
    title: test/maximum_independent_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_operate_all_compose.test.cpp
    title: test/queue_operate_all_compose.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rangeBIT.test.cpp
    title: test/rangeBIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sa-is.test.cpp
    title: test/sa-is.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/scc.test.cpp
    title: test/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/set_xor_min.test.cpp
    title: test/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_inversions_query.test.cpp
    title: test/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/staticrangesum.test.cpp
    title: test/staticrangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/staticrmq.test.cpp
    title: test/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/two_edge_connected_components.test.cpp
    title: test/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/two_sat.test.cpp
    title: test/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/union-find.test.cpp
    title: test/union-find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki0206.test.cpp
    title: test/yuki0206.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki1333.test.cpp
    title: test/yuki1333.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/zalgorothm.test.cpp
    title: test/zalgorothm.test.cpp
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
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v)\
    \ ((int)(v).size())\nconst int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr\
    \ int MOD = 1000000007;\nconstexpr int MOD2 = 998244353;\nconst int dx[4] = {1,\
    \ 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"\
    Case #\" << i << \": \"; }\nint popcount(int x) { return __builtin_popcount(x);\
    \ }\nll popcount(ll x) { return __builtin_popcountll(x); }\n#pragma endregion\
    \ Macros\n"
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
    \ (v).end())\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\nconst\
    \ ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2 =\
    \ 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\
    \nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int x)\
    \ { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy: []
  timestamp: '2021-11-14 12:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rangeBIT.test.cpp
  - test/staticrangesum.test.cpp
  - test/static_range_inversions_query.test.cpp
  - test/maximum_independent_set.test.cpp
  - test/two_sat.test.cpp
  - test/two_edge_connected_components.test.cpp
  - test/AOJ2748.test.cpp
  - test/dinic.test.cpp
  - test/a_plus_b.test.cpp
  - test/inversion_number.test.cpp
  - test/line_add_get_min.test.cpp
  - test/determinant.test.cpp
  - test/AOJ2821.test.cpp
  - test/yuki0206.test.cpp
  - test/scc.test.cpp
  - test/sa-is.test.cpp
  - test/fast_factorize.test.cpp
  - test/union-find.test.cpp
  - test/AOJ2426.test.cpp
  - test/Hopcroft-Karp.test.cpp
  - test/zalgorothm.test.cpp
  - test/lca.test.cpp
  - test/queue_operate_all_compose.test.cpp
  - test/chromatic_number.test.cpp
  - test/erathosthenes.test.cpp
  - test/yuki1333.test.cpp
  - test/AOJ2858.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/euler_phi.test.cpp
  - test/is_prime.test.cpp
  - test/vertex_set_path_composite.test.cpp
  - test/set_xor_min.test.cpp
  - test/staticrmq.test.cpp
documentation_of: template/template.cpp
layout: document
title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
