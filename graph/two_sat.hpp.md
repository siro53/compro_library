---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(SCC)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/two_sat.test.cpp
    title: test/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.hpp\"\n// \u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\
    \u3057\u305F\u3089build()\u3092\u5FC5\u305A\u547C\u3076\u3053\u3068!!!\nclass\
    \ SCC {\n  private:\n    vector<vector<int>> G;\n    vector<vector<int>> revG;\n\
    \    vector<int> vs, comp;\n    vector<bool> seen;\n    int cnt;\n    void dfs(int\
    \ v) {\n        seen[v] = true;\n        for(const int &u : G[v]) {\n        \
    \    if(!seen[u]) { dfs(u); }\n        }\n        vs.emplace_back(v);\n    }\n\
    \    void rev_dfs(int v, int id) {\n        seen[v] = true;\n        comp[v] =\
    \ id;\n        for(const int &u : revG[v]) {\n            if(comp[u] == -1) {\
    \ rev_dfs(u, id); }\n        }\n    }\n\n  public:\n    SCC(int N) : G(N), revG(N),\
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
    \ { return ans; }\n};\n"
  code: "#include \"scc.hpp\"\n\nclass two_sat {\n  private:\n    int N;\n    vector<vector<int>>\
    \ G;\n    vector<bool> ans;\n    int NOT(int i) { return i + (i < N ? N : -N);\
    \ }\n\n  public:\n    two_sat() {}\n    two_sat(int N) : N(N), G(2 * N), ans(N)\
    \ {}\n    void add_clause(int i, bool f, int j, bool g) {\n        if(!f) i =\
    \ NOT(i);\n        if(!g) j = NOT(j);\n        G[i].emplace_back(NOT(j));\n  \
    \      G[j].emplace_back(NOT(i));\n    }\n    bool satisfiable() {\n        SCC\
    \ scc(G);\n        scc.build();\n        for(int i = 0; i < N; i++) {\n      \
    \      if(scc[i] == scc[NOT(i)]) return false;\n            ans[i] = scc[i] <\
    \ scc[NOT(i)];\n        }\n        return true;\n    }\n    vector<bool> answer()\
    \ { return ans; }\n};"
  dependsOn:
  - graph/scc.hpp
  isVerificationFile: false
  path: graph/two_sat.hpp
  requiredBy: []
  timestamp: '2021-03-16 22:41:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/two_sat.test.cpp
documentation_of: graph/two_sat.hpp
layout: document
title: 2-SAT
---
