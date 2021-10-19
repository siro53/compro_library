---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bi_edge_connected_components.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3(BECC)"
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/two_edge_connected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n#line 1 \"\
    template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
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
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 1 \"graph/bi_edge_connected_components.hpp\"\
    \nclass BECC {\nprivate:\n    int N, sz;\n    vector<vector<int>> G;\n    vector<int>\
    \ seen, imos, comp;\n\n    void dfs1(int u, int p) {\n        seen[u] = 1;\n \
    \       bool is_skipped_par = false;\n        for(int v : G[u]) {\n          \
    \  if(v == p and !is_skipped_par) {\n                is_skipped_par = true;\n\
    \                continue;\n            }\n            if(seen[v] == 0) {\n  \
    \              dfs1(v, u);\n                imos[u] += imos[v];\n            }\
    \ else if(seen[v] == 1) {\n                imos[u]++;\n                imos[v]--;\n\
    \            }\n        }\n        seen[u] = 2;\n    }\n\n    void dfs2(int u)\
    \ {\n        for(int v : G[u]) {\n            if(comp[v] != -1) continue;\n  \
    \          comp[v] = (imos[v] == 0 ? sz++ : comp[u]);\n            dfs2(v);\n\
    \        }\n    }\n\npublic:\n    BECC(int N): N(N), G(N), seen(N, 0), imos(N,\
    \ 0), sz(0), comp(N, -1) {}\n    BECC(vector<vector<int>> g) : N(g.size()), G(g),\
    \ seen(N, 0), imos(N, 0), sz(0), comp(N, -1) {}\n    \n    void add_edge(int u,\
    \ int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n   \
    \ } \n\n    void build() {\n        for(int i = 0; i < N; i++) {\n           \
    \ if(seen[i] != 0) continue;\n            dfs1(i, -1);\n        }\n        for(int\
    \ i = 0; i < N; i++) {\n            if(comp[i] != -1) continue;\n            comp[i]\
    \ = sz++;\n            dfs2(i);\n        }\n    }\n    \n    // \u5FC5\u305Abuild()\u3057\
    \u305F\u5F8C\u306B\u547C\u3073\u51FA\u3059\u3053\u3068!!!\n    vector<vector<int>>\
    \ get_contract_graph() {\n        vector<vector<int>> h(sz);\n        for(int\
    \ u = 0; u < N; u++) {\n            for(const int& v : G[u]) {\n             \
    \   int x = comp[u], y = comp[v];\n                if(x == y) continue;\n    \
    \            h[x].push_back(y);\n                h[y].push_back(x);\n        \
    \    }\n        }\n        return h;\n    }\n\n    int operator[](int k) const\
    \ { return comp[k]; }\n    int size() const { return sz; }\n};\n#line 4 \"test/two_edge_connected_components.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    BECC becc(N);\n    REP(i,\
    \ M) {\n        int a, b;\n        cin >> a >> b;\n        becc.add_edge(a, b);\n\
    \    }\n    becc.build();\n    int K = becc.size();\n    vector<vector<int>> res(K);\n\
    \    REP(i, N) res[becc[i]].push_back(i);\n    \n    cout << K << \"\\n\";\n \
    \   REP(i, K) {\n        int sz = res[i].size();\n        cout << sz << \" \"\
    ;\n        REP(j, sz) cout << res[i][j] << \" \\n\"[j == sz-1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include \"../template/template.cpp\"\n#include \"../graph/bi_edge_connected_components.hpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    BECC becc(N);\n    REP(i,\
    \ M) {\n        int a, b;\n        cin >> a >> b;\n        becc.add_edge(a, b);\n\
    \    }\n    becc.build();\n    int K = becc.size();\n    vector<vector<int>> res(K);\n\
    \    REP(i, N) res[becc[i]].push_back(i);\n    \n    cout << K << \"\\n\";\n \
    \   REP(i, K) {\n        int sz = res[i].size();\n        cout << sz << \" \"\
    ;\n        REP(j, sz) cout << res[i][j] << \" \\n\"[j == sz-1];\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/bi_edge_connected_components.hpp
  isVerificationFile: true
  path: test/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2021-10-12 21:25:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/two_edge_connected_components.test.cpp
- /verify/test/two_edge_connected_components.test.cpp.html
title: test/two_edge_connected_components.test.cpp
---
