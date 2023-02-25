---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/dijkstra.hpp
    title: graph/shortest-path/dijkstra.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/library-checker/graph/shortest-path.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 1 \"template/template.cpp\"\
    \n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 2 \"graph/shortest-path/dijkstra.hpp\"\
    \n\n#line 7 \"graph/shortest-path/dijkstra.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct\
    \ Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n\
    \    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n};\n\ntemplate <typename Cost = int> class Graph\
    \ {\n  public:\n    Graph() = default;\n    explicit Graph(int N) : N(N), M(0),\
    \ G(N) {}\n\n    inline void add_directed_edge(int from, int to, Cost cost = 1)\
    \ {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n\
    \        G[from].emplace_back(from, to, cost, M++);\n    }\n\n    inline void\
    \ add_undirected_edge(int from, int to, Cost cost = 1) {\n        assert(0 <=\
    \ from && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M);\n        G[to].emplace_back(to, from, cost, M++);\n    }\n\n \
    \   inline size_t size() const { return G.size(); }\n    inline std::vector<Edge<Cost>>\
    \ &operator[](const int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>>\
    \ &operator[](const int &i) const {\n        return G[i];\n    }\n\n  private:\n\
    \    int N, M;\n    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class\
    \ Cost = int> using Edges = std::vector<Edge<Cost>>;\n#line 9 \"graph/shortest-path/dijkstra.hpp\"\
    \n\ntemplate <typename Cost = int>\nstd::pair<std::vector<Cost>, std::vector<int>>\n\
    dijkstra(const Graph<Cost> &G, int start, Cost iv = 0,\n         Cost inf = std::numeric_limits<Cost>::max())\
    \ {\n    using Data = std::pair<Cost, int>;\n    int N = (int)G.size();\n    std::vector<Cost>\
    \ dist(N, inf);\n    std::vector<int> prev(N, -1);\n\n    dist[start] = iv;\n\
    \    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> que;\n \
    \   que.emplace(iv, start);\n    while(!que.empty()) {\n        auto [d, u] =\
    \ que.top();\n        que.pop();\n        if(d > dist[u]) continue;\n        for(const\
    \ auto &e : G[u]) {\n            if(dist[e.to] > d + e.cost) {\n             \
    \   dist[e.to] = d + e.cost;\n                prev[e.to] = u;\n              \
    \  que.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n    return\
    \ std::make_pair(dist, prev);\n}\n#line 4 \"test/library-checker/graph/shortest-path.test.cpp\"\
    \n\nint main() {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    Graph<ll>\
    \ G(N);\n    REP(_, M) {\n        int from, to;\n        ll cost;\n        cin\
    \ >> from >> to >> cost;\n        G.add_directed_edge(from, to, cost);\n    }\n\
    \    auto [dist, prev] = dijkstra<ll>(G, s, 0, LLINF);\n    if(dist[t] == LLINF)\
    \ {\n        cout << \"-1\\n\";\n    } else {\n        vector<int> path;\n   \
    \     path.push_back(t);\n        while(1) {\n            int p = prev[path.back()];\n\
    \            if(p == -1) break;\n            path.push_back(p);\n        }\n \
    \       reverse(ALL(path));\n        cout << dist[t] << ' ' << SZ(path) - 1 <<\
    \ '\\n';\n        REP(i, SZ(path) - 1) {\n            cout << path[i] << ' ' <<\
    \ path[i+1] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../../template/template.cpp\"\n#include \"../../../graph/shortest-path/dijkstra.hpp\"\
    \n\nint main() {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    Graph<ll>\
    \ G(N);\n    REP(_, M) {\n        int from, to;\n        ll cost;\n        cin\
    \ >> from >> to >> cost;\n        G.add_directed_edge(from, to, cost);\n    }\n\
    \    auto [dist, prev] = dijkstra<ll>(G, s, 0, LLINF);\n    if(dist[t] == LLINF)\
    \ {\n        cout << \"-1\\n\";\n    } else {\n        vector<int> path;\n   \
    \     path.push_back(t);\n        while(1) {\n            int p = prev[path.back()];\n\
    \            if(p == -1) break;\n            path.push_back(p);\n        }\n \
    \       reverse(ALL(path));\n        cout << dist[t] << ' ' << SZ(path) - 1 <<\
    \ '\\n';\n        REP(i, SZ(path) - 1) {\n            cout << path[i] << ' ' <<\
    \ path[i+1] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - graph/shortest-path/dijkstra.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/library-checker/graph/shortest-path.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/graph/shortest-path.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/graph/shortest-path.test.cpp
- /verify/test/library-checker/graph/shortest-path.test.cpp.html
title: test/library-checker/graph/shortest-path.test.cpp
---
