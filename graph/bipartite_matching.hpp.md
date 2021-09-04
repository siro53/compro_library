---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Hopcroft-Karp.test.cpp
    title: test/Hopcroft-Karp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bipartite_matching.hpp\"\nstruct BipartiteMatching\
    \ {\n    int L, R;\n    vector<int> l, r, d;\n    vector<bool> seen;\n    vector<vector<int>>\
    \ G;\n\n    BipartiteMatching(int L, int R)\n        : L(L), R(R), l(L, -1), r(R,\
    \ -1), d(L), seen(L), G(L) {}\n\n    void add_edge(int _l, int _r) { G[_l].emplace_back(_r);\
    \ }\n\n    void bfs() {\n        vector<int> que;\n        int head = 0, tail\
    \ = 0;\n        fill(d.begin(), d.end(), -1);\n        for(int i = 0; i < L; i++)\
    \ {\n            if(l[i] == -1) {\n                que.emplace_back(i), tail++;\n\
    \                d[i] = 0;\n            }\n        }\n        while(head != tail)\
    \ {\n            int v = que[head++];\n            for(const auto &u : G[v]) {\n\
    \                if(r[u] != -1 && d[r[u]] == -1) {\n                    d[r[u]]\
    \ = d[v] + 1;\n                    que.emplace_back(r[u]), tail++;\n         \
    \       }\n            }\n        }\n    }\n\n    bool dfs(int v) {\n        if(seen[v])\
    \ return false;\n        seen[v] = true;\n        for(const auto &u : G[v]) {\n\
    \            if(r[u] == -1 || (d[r[u]] == d[v] + 1 && dfs(r[u]))) {\n        \
    \        l[v] = u;\n                r[u] = v;\n                return true;\n\
    \            }\n        }\n        return false;\n    }\n\n    int matching()\
    \ {\n        int res = 0;\n        while(1) {\n            bfs();\n          \
    \  fill(seen.begin(), seen.end(), false);\n            int f = 0;\n          \
    \  for(int i = 0; i < L; i++) {\n                if(l[i] == -1 && dfs(i)) f++;\n\
    \            }\n            if(f == 0) return res;\n            res += f;\n  \
    \      }\n    }\n};\n"
  code: "struct BipartiteMatching {\n    int L, R;\n    vector<int> l, r, d;\n   \
    \ vector<bool> seen;\n    vector<vector<int>> G;\n\n    BipartiteMatching(int\
    \ L, int R)\n        : L(L), R(R), l(L, -1), r(R, -1), d(L), seen(L), G(L) {}\n\
    \n    void add_edge(int _l, int _r) { G[_l].emplace_back(_r); }\n\n    void bfs()\
    \ {\n        vector<int> que;\n        int head = 0, tail = 0;\n        fill(d.begin(),\
    \ d.end(), -1);\n        for(int i = 0; i < L; i++) {\n            if(l[i] ==\
    \ -1) {\n                que.emplace_back(i), tail++;\n                d[i] =\
    \ 0;\n            }\n        }\n        while(head != tail) {\n            int\
    \ v = que[head++];\n            for(const auto &u : G[v]) {\n                if(r[u]\
    \ != -1 && d[r[u]] == -1) {\n                    d[r[u]] = d[v] + 1;\n       \
    \             que.emplace_back(r[u]), tail++;\n                }\n           \
    \ }\n        }\n    }\n\n    bool dfs(int v) {\n        if(seen[v]) return false;\n\
    \        seen[v] = true;\n        for(const auto &u : G[v]) {\n            if(r[u]\
    \ == -1 || (d[r[u]] == d[v] + 1 && dfs(r[u]))) {\n                l[v] = u;\n\
    \                r[u] = v;\n                return true;\n            }\n    \
    \    }\n        return false;\n    }\n\n    int matching() {\n        int res\
    \ = 0;\n        while(1) {\n            bfs();\n            fill(seen.begin(),\
    \ seen.end(), false);\n            int f = 0;\n            for(int i = 0; i <\
    \ L; i++) {\n                if(l[i] == -1 && dfs(i)) f++;\n            }\n  \
    \          if(f == 0) return res;\n            res += f;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Hopcroft-Karp.test.cpp
documentation_of: graph/bipartite_matching.hpp
layout: document
title: "Hopcroft-Karp algorithm(\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0)"
---
