---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: graph/lca.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 1 \"graph/lca.hpp\"\
    \nstruct LCA {\n    const int n = 0;\n    const int log2_n = 0;\n    vector<vector<int>>\
    \ par;\n    vector<int> depth;\n\n    LCA(const vector<vector<int>> &g, int root)\n\
    \        : n(g.size()), log2_n(log2(n) + 1), par(log2_n, vector<int>(n)),\n  \
    \        depth(n) {\n        dfs(g, root, -1, 0);\n        for(int k = 0; k +\
    \ 1 < log2_n; k++) {\n            for(int v = 0; v < n; v++) {\n             \
    \   if(par[k][v] < 0) {\n                    par[k + 1][v] = -1;\n           \
    \     } else {\n                    par[k + 1][v] = par[k][par[k][v]];\n     \
    \           }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<int>>\
    \ &g, int v, int p, int d) {\n        par[0][v] = p;\n        depth[v] = d;\n\
    \        for(auto &u : g[v]) {\n            if(u != p) {\n                dfs(g,\
    \ u, v, d + 1);\n            }\n        }\n    }\n\n    int get_lca(int u, int\
    \ v) {\n        // u\u3068v\u306E\u6DF1\u3055\u304C\u540C\u3058\u306B\u306A\u308B\
    \u307E\u3067\u8FBF\u308B\n        if(depth[u] > depth[v]) {\n            swap(u,\
    \ v);\n        }\n        for(int k = 0; k < log2_n; k++) {\n            if(((depth[v]\
    \ - depth[u]) >> k) & 1) {\n                v = par[k][v];\n            }\n  \
    \      }\n\n        if(u == v) {\n            return u;\n        }\n\n       \
    \ for(int k = log2_n - 1; k >= 0; k--) {\n            if(par[k][u] != par[k][v])\
    \ {\n                u = par[k][u];\n                v = par[k][v];\n        \
    \    }\n        }\n        return par[0][u];\n    }\n\n    int get_dist(int u,\
    \ int v) {\n        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];\n \
    \   }\n};\n#line 4 \"test/lca.test.cpp\"\n\nint main(){\n    int n, q;\n    cin\
    \ >> n >> q;\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++) {\n\
    \        int p;\n        cin >> p;\n        g[i].emplace_back(p);\n        g[p].emplace_back(i);\n\
    \    }\n\n    LCA lca(g, 0);\n\n    while(q--) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        cout << lca.get_lca(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../template/template.cpp\"\
    \n#include \"../graph/lca.hpp\"\n\nint main(){\n    int n, q;\n    cin >> n >>\
    \ q;\n    vector<vector<int>> g(n);\n    for(int i = 1; i < n; i++) {\n      \
    \  int p;\n        cin >> p;\n        g[i].emplace_back(p);\n        g[p].emplace_back(i);\n\
    \    }\n\n    LCA lca(g, 0);\n\n    while(q--) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        cout << lca.get_lca(u, v) << endl;\n    }\n}"
  dependsOn:
  - template/template.cpp
  - graph/lca.hpp
  isVerificationFile: true
  path: test/lca.test.cpp
  requiredBy: []
  timestamp: '2021-07-01 11:58:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lca.test.cpp
layout: document
redirect_from:
- /verify/test/lca.test.cpp
- /verify/test/lca.test.cpp.html
title: test/lca.test.cpp
---
