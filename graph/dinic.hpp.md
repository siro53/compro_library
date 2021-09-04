---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dinic.test.cpp
    title: test/dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dinic.hpp\"\ntemplate <class Cap> class Dinic {\n\
    \  private:\n    struct edge {\n        int to, rev;\n        Cap cap;\n    };\n\
    \    vector<vector<edge>> G;\n    vector<int> level, iter;\n    vector<pair<int,\
    \ int>> pos;\n\n    void bfs(int s, int t) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        vector<int> que;\n        int head = 0, tail = 0;\n        level[s]\
    \ = 0;\n        que.emplace_back(s), tail++; // push\n        while(head != tail)\
    \ {\n            int v = que[head++]; // pop\n            for(const auto &e :\
    \ G[v]) {\n                if(e.cap > 0 && level[e.to] < 0) {\n              \
    \      level[e.to] = level[v] + 1;\n                    if(e.to == t) return;\n\
    \                    que.emplace_back(e.to), tail++; // push\n               \
    \ }\n            }\n        }\n    }\n\n    Cap dfs(const int &v, const int &s,\
    \ Cap now) {\n        if(v == s || now == 0) return now;\n        Cap res = 0;\n\
    \        int sz = (int)G[v].size();\n        for(int &i = iter[v]; i < sz; i++)\
    \ {\n            edge &e = G[v][i], &re = G[e.to][e.rev];\n            if(level[v]\
    \ <= level[e.to] || re.cap <= 0) continue;\n            Cap d = dfs(e.to, s, min(now\
    \ - res, re.cap));\n            if(d > 0) {\n                e.cap += d;\n   \
    \             re.cap -= d;\n                res += d;\n                if(res\
    \ == now) break;\n            }\n        }\n        return res;\n    }\n\n  public:\n\
    \    Dinic(int n) : G(n), level(n), iter(n) {}\n\n    int add_edge(int from, int\
    \ to, Cap cap) {\n        int n = (int)G.size();\n        assert(0 <= from &&\
    \ from < n);\n        assert(0 <= to && to < n);\n        assert(0 <= cap);\n\
    \        int m = (int)pos.size();\n        pos.emplace_back(from, (int)G[from].size());\n\
    \        G[from].emplace_back(edge{to, (int)G[to].size(), cap});\n        G[to].emplace_back(edge{from,\
    \ (int)G[from].size() - 1, 0});\n        return m;\n    }\n\n    struct res_edge\
    \ {\n        int from, to;\n        Cap cap, flow;\n    };\n\n    res_edge get_edge(int\
    \ i) {\n        int m = (int)pos.size();\n        assert(0 <= i && i < m);\n \
    \       auto e = G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n\
    \        return res_edge{pos[i].first, e.to, e.cap + re.cap, re.cap};\n    }\n\
    \n    vector<res_edge> edges() {\n        int m = (int)pos.size();\n        vector<res_edge>\
    \ res;\n        for(int i = 0; i < m; i++) res.emplace_back(get_edge(i));\n  \
    \      return res;\n    }\n\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = (int)pos.size();\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto &e = G[pos[i].first][pos[i].second];\n\
    \        auto &re = G[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n   \
    \     re.cap = new_flow;\n    }\n\n    Cap max_flow(int s, int t, Cap limit =\
    \ numeric_limits<Cap>::max()) {\n        Cap flow = 0;\n        while(flow < limit)\
    \ {\n            bfs(s, t);\n            if(level[t] < 0) return flow;\n     \
    \       fill(iter.begin(), iter.end(), 0);\n            while(flow < limit) {\n\
    \                Cap f = dfs(t, s, limit - flow);\n                if(f == 0)\
    \ break;\n                flow += f;\n            }\n        }\n        return\
    \ flow;\n    }\n};\n"
  code: "template <class Cap> class Dinic {\n  private:\n    struct edge {\n     \
    \   int to, rev;\n        Cap cap;\n    };\n    vector<vector<edge>> G;\n    vector<int>\
    \ level, iter;\n    vector<pair<int, int>> pos;\n\n    void bfs(int s, int t)\
    \ {\n        fill(level.begin(), level.end(), -1);\n        vector<int> que;\n\
    \        int head = 0, tail = 0;\n        level[s] = 0;\n        que.emplace_back(s),\
    \ tail++; // push\n        while(head != tail) {\n            int v = que[head++];\
    \ // pop\n            for(const auto &e : G[v]) {\n                if(e.cap >\
    \ 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n \
    \                   if(e.to == t) return;\n                    que.emplace_back(e.to),\
    \ tail++; // push\n                }\n            }\n        }\n    }\n\n    Cap\
    \ dfs(const int &v, const int &s, Cap now) {\n        if(v == s || now == 0) return\
    \ now;\n        Cap res = 0;\n        int sz = (int)G[v].size();\n        for(int\
    \ &i = iter[v]; i < sz; i++) {\n            edge &e = G[v][i], &re = G[e.to][e.rev];\n\
    \            if(level[v] <= level[e.to] || re.cap <= 0) continue;\n          \
    \  Cap d = dfs(e.to, s, min(now - res, re.cap));\n            if(d > 0) {\n  \
    \              e.cap += d;\n                re.cap -= d;\n                res\
    \ += d;\n                if(res == now) break;\n            }\n        }\n   \
    \     return res;\n    }\n\n  public:\n    Dinic(int n) : G(n), level(n), iter(n)\
    \ {}\n\n    int add_edge(int from, int to, Cap cap) {\n        int n = (int)G.size();\n\
    \        assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n\
    \        assert(0 <= cap);\n        int m = (int)pos.size();\n        pos.emplace_back(from,\
    \ (int)G[from].size());\n        G[from].emplace_back(edge{to, (int)G[to].size(),\
    \ cap});\n        G[to].emplace_back(edge{from, (int)G[from].size() - 1, 0});\n\
    \        return m;\n    }\n\n    struct res_edge {\n        int from, to;\n  \
    \      Cap cap, flow;\n    };\n\n    res_edge get_edge(int i) {\n        int m\
    \ = (int)pos.size();\n        assert(0 <= i && i < m);\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return res_edge{pos[i].first, e.to,\
    \ e.cap + re.cap, re.cap};\n    }\n\n    vector<res_edge> edges() {\n        int\
    \ m = (int)pos.size();\n        vector<res_edge> res;\n        for(int i = 0;\
    \ i < m; i++) res.emplace_back(get_edge(i));\n        return res;\n    }\n\n \
    \   void change_edge(int i, Cap new_cap, Cap new_flow) {\n        int m = (int)pos.size();\n\
    \        assert(0 <= i && i < m);\n        assert(0 <= new_flow && new_flow <=\
    \ new_cap);\n        auto &e = G[pos[i].first][pos[i].second];\n        auto &re\
    \ = G[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n        re.cap = new_flow;\n\
    \    }\n\n    Cap max_flow(int s, int t, Cap limit = numeric_limits<Cap>::max())\
    \ {\n        Cap flow = 0;\n        while(flow < limit) {\n            bfs(s,\
    \ t);\n            if(level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            while(flow < limit) {\n                Cap f =\
    \ dfs(t, s, limit - flow);\n                if(f == 0) break;\n              \
    \  flow += f;\n            }\n        }\n        return flow;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dinic.test.cpp
documentation_of: graph/dinic.hpp
layout: document
title: Dinic
---
