---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: graph/dinic.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/dinic.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 1 \"graph/dinic.hpp\"\
    \ntemplate <class Cap> class Dinic {\n  private:\n    struct edge {\n        int\
    \ to, rev;\n        Cap cap;\n    };\n    vector<vector<edge>> G;\n    vector<int>\
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
    \  flow += f;\n            }\n        }\n        return flow;\n    }\n};\n#line\
    \ 4 \"test/dinic.test.cpp\"\n\nint main() {\n    int L, R, M;\n    cin >> L >>\
    \ R >> M;\n    Dinic<int> G(L + R + 2);\n    int s = L + R;\n    int t = s + 1;\n\
    \    for(int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        b += L;\n        G.add_edge(a, b, 1);\n    }\n    for(int i = 0; i <\
    \ L; i++) {\n        G.add_edge(s, i, 1);\n    }\n    for(int i = 0; i < R; i++)\
    \ {\n        G.add_edge(i + L, t, 1);\n    }\n    int ans = G.max_flow(s, t);\n\
    \    cout << ans << \"\\n\";\n    const auto es = G.edges();\n    for(const auto\
    \ &e : es) {\n        if(0 <= e.from && e.from < L && L <= e.to && e.to < L +\
    \ R &&\n           e.flow == 1) {\n            cout << e.from << \" \" << e.to\
    \ - L << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../graph/dinic.hpp\"\n\nint main()\
    \ {\n    int L, R, M;\n    cin >> L >> R >> M;\n    Dinic<int> G(L + R + 2);\n\
    \    int s = L + R;\n    int t = s + 1;\n    for(int i = 0; i < M; i++) {\n  \
    \      int a, b;\n        cin >> a >> b;\n        b += L;\n        G.add_edge(a,\
    \ b, 1);\n    }\n    for(int i = 0; i < L; i++) {\n        G.add_edge(s, i, 1);\n\
    \    }\n    for(int i = 0; i < R; i++) {\n        G.add_edge(i + L, t, 1);\n \
    \   }\n    int ans = G.max_flow(s, t);\n    cout << ans << \"\\n\";\n    const\
    \ auto es = G.edges();\n    for(const auto &e : es) {\n        if(0 <= e.from\
    \ && e.from < L && L <= e.to && e.to < L + R &&\n           e.flow == 1) {\n \
    \           cout << e.from << \" \" << e.to - L << \"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - template/template.cpp
  - graph/dinic.hpp
  isVerificationFile: true
  path: test/dinic.test.cpp
  requiredBy: []
  timestamp: '2021-07-01 11:58:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dinic.test.cpp
layout: document
redirect_from:
- /verify/test/dinic.test.cpp
- /verify/test/dinic.test.cpp.html
title: test/dinic.test.cpp
---
