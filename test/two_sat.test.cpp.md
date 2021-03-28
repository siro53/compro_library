---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':x:'
    path: graph/two_sat.hpp
    title: graph/two_sat.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
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
    #pragma endregion Macros\n#line 1 \"graph/scc.hpp\"\n// \u30B0\u30E9\u30D5\u3092\
    \u69CB\u7BC9\u3057\u305F\u3089build()\u3092\u5FC5\u305A\u547C\u3076\u3053\u3068\
    !!!\nclass SCC {\n  private:\n    vector<vector<int>> G;\n    vector<vector<int>>\
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
    \ = 0; i < n; i++) {\n            if(!seen[i]) dfs(i);\n        }\n        reverse(ALL(vs));\n\
    \        cnt = 0;\n        for(const int &v : vs) {\n            if(comp[v] ==\
    \ -1) {\n                rev_dfs(v, cnt);\n                cnt++;\n          \
    \  }\n        }\n    }\n    // \u5FC5\u305Abuild()\u3057\u305F\u5F8C\u306B\u547C\
    \u3073\u51FA\u3059\u3053\u3068!!!\n    vector<vector<int>> get_contract_graph()\
    \ {\n        vector<vector<int>> res_g(cnt);\n        for(int i = 0; i < int(G.size());\
    \ i++) {\n            for(const int& to : G[i]) {\n                int a = comp[i],\
    \ b = comp[to];\n                if(a == b) continue;\n                res_g[a].push_back(b);\n\
    \            }\n        }\n        return res_g;\n    }\n    int operator[](int\
    \ k) const { return comp[k]; }\n    int size() const { return cnt; }\n};\n#line\
    \ 2 \"graph/two_sat.hpp\"\n\nclass two_sat {\n  private:\n    int N;\n    vector<vector<int>>\
    \ G;\n    vector<bool> ans;\n    int NOT(int i) { return i + (i < N ? N : -N);\
    \ }\n\n  public:\n    two_sat() {}\n    two_sat(int N) : N(N), G(2 * N), ans(N)\
    \ {}\n    void add_clause(int i, bool f, int j, bool g) {\n        if(!f) i =\
    \ NOT(i);\n        if(!g) j = NOT(j);\n        G[i].emplace_back(NOT(j));\n  \
    \      G[j].emplace_back(NOT(i));\n    }\n    bool satisfiable() {\n        SCC\
    \ scc(G);\n        scc.build();\n        for(int i = 0; i < N; i++) {\n      \
    \      if(scc[i] == scc[NOT(i)]) return false;\n            ans[i] = scc[i] <\
    \ scc[NOT(i)];\n        }\n        return true;\n    }\n    vector<bool> answer()\
    \ { return ans; }\n};\n#line 4 \"test/two_sat.test.cpp\"\n\nstring tmp;\n\nint\
    \ main() {\n    cin >> tmp; cin >> tmp;\n    int N, M; cin >> N >> M;\n\n    two_sat\
    \ ts(N);\n\n    REP(i, M) {\n        int a, b, c; cin >> a >> b >> c;\n      \
    \  ts.add_clause(abs(a)-1, a>0, abs(b)-1, b>0);\n    }\n\n    if(!ts.satisfiable())\
    \ {\n        cout << \"s UNSATISFIABLE\\n\";\n        return 0;\n    }\n\n   \
    \ auto ans = ts.answer();\n\n    cout << \"s SATISFIABLE\\n\";\n    cout << \"\
    v \";\n    REP(i, N) cout << (ans[i] ? 1 : -1) * (i + 1) << \" \";\n    cout <<\
    \ 0 << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    ../template/template.cpp\"\n#include \"../graph/two_sat.hpp\"\n\nstring tmp;\n\
    \nint main() {\n    cin >> tmp; cin >> tmp;\n    int N, M; cin >> N >> M;\n\n\
    \    two_sat ts(N);\n\n    REP(i, M) {\n        int a, b, c; cin >> a >> b >>\
    \ c;\n        ts.add_clause(abs(a)-1, a>0, abs(b)-1, b>0);\n    }\n\n    if(!ts.satisfiable())\
    \ {\n        cout << \"s UNSATISFIABLE\\n\";\n        return 0;\n    }\n\n   \
    \ auto ans = ts.answer();\n\n    cout << \"s SATISFIABLE\\n\";\n    cout << \"\
    v \";\n    REP(i, N) cout << (ans[i] ? 1 : -1) * (i + 1) << \" \";\n    cout <<\
    \ 0 << \"\\n\";\n}"
  dependsOn:
  - template/template.cpp
  - graph/two_sat.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/two_sat.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 17:58:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/two_sat.test.cpp
- /verify/test/two_sat.test.cpp.html
title: test/two_sat.test.cpp
---
