---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#line 1 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a < b) {\n \
    \       a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate <class T>\
    \ inline bool chmin(T &a, T b) {\n    if(a > b) {\n        a = b;\n        return\
    \ 1;\n    }\n    return 0;\n}\n#define DEBUG\n#ifdef DEBUG\ntemplate <class T,\
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
    \ = {0, 1, 0, -1};\n\n//-------------------------------------\n#line 1 \"graph/scc.hpp\"\
    \nclass SCC {\n  private:\n    vector<vector<int>> G;\n    vector<vector<int>>\
    \ revG;\n    vector<int> vs, comp;\n    vector<bool> seen;\n    int cnt;\n   \
    \ void dfs(int v) {\n        seen[v] = true;\n        for(const int &u : G[v])\
    \ {\n            if(!seen[u]) { dfs(u); }\n        }\n        vs.emplace_back(v);\n\
    \    }\n    void rev_dfs(int v, int id) {\n        seen[v] = true;\n        comp[v]\
    \ = id;\n        for(const int &u : revG[v]) {\n            if(comp[u] == -1)\
    \ { rev_dfs(u, id); }\n        }\n    }\n\n  public:\n    SCC(int N) : G(N), revG(N),\
    \ comp(N, -1), seen(N, false) {}\n    SCC(vector<vector<int>> g)\n        : G(g),\
    \ revG(g.size()), comp(g.size(), -1), seen(g.size(), false) {\n        int n =\
    \ (int)g.size();\n        for(int i = 0; i < n; i++) {\n            for(const\
    \ auto &u : g[i]) { revG[u].emplace_back(i); }\n        }\n    }\n    void add_edge(int\
    \ i, int j) {\n        G[i].emplace_back(j);\n        revG[j].emplace_back(i);\n\
    \    }\n    void build() {\n        int n = (int)G.size();\n        for(int i\
    \ = 0; i < n; i++) {\n            if(!seen[i]) { dfs(i); }\n        }\n      \
    \  reverse(ALL(vs));\n        cnt = 0;\n        for(const int &v : vs) {\n   \
    \         if(comp[v] == -1) {\n                rev_dfs(v, cnt);\n            \
    \    cnt++;\n            }\n        }\n    }\n    int operator[](int k) const\
    \ { return comp[k]; }\n    int size() const { return cnt; }\n};\n#line 4 \"test/scc.test.cpp\"\
    \n\nint main() {\n    int N, M;\n    cin >> N >> M;\n\n    SCC scc(N);\n    REP(i,\
    \ M) {\n        int a, b; cin >> a >> b;\n        scc.add_edge(a, b);\n    }\n\
    \    scc.build();\n\n    vector<vector<int>> res(scc.size());\n    for(int i =\
    \ 0; i < N; i++) {\n        res[scc[i]].emplace_back(i);\n    }\n    cout << scc.size()\
    \ << \"\\n\";\n    for(int i = 0; i < res.size(); i++) {\n        int sz = res[i].size();\n\
    \        cout << sz << \" \";\n        for(int j = 0; j < sz; j++) {\n       \
    \     cout << res[i][j] << \" \\n\"[j == sz - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../template/template.cpp\"\
    \n#include \"../graph/scc.hpp\"\n\nint main() {\n    int N, M;\n    cin >> N >>\
    \ M;\n\n    SCC scc(N);\n    REP(i, M) {\n        int a, b; cin >> a >> b;\n \
    \       scc.add_edge(a, b);\n    }\n    scc.build();\n\n    vector<vector<int>>\
    \ res(scc.size());\n    for(int i = 0; i < N; i++) {\n        res[scc[i]].emplace_back(i);\n\
    \    }\n    cout << scc.size() << \"\\n\";\n    for(int i = 0; i < res.size();\
    \ i++) {\n        int sz = res[i].size();\n        cout << sz << \" \";\n    \
    \    for(int j = 0; j < sz; j++) {\n            cout << res[i][j] << \" \\n\"\
    [j == sz - 1];\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/scc.test.cpp
  requiredBy: []
  timestamp: '2021-02-22 10:22:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/scc.test.cpp
layout: document
redirect_from:
- /verify/test/scc.test.cpp
- /verify/test/scc.test.cpp.html
title: test/scc.test.cpp
---
