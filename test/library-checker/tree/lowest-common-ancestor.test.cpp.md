---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148(LCA)"
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library-checker/tree/lowest-common-ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 1 \"template/template.cpp\"\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 2 \"graph/tree/lca.hpp\"\
    \n\n#line 5 \"graph/tree/lca.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n\
    #line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct\
    \ Edge {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n\
    \    explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from),\
    \ to(to), cost(cost), id(id) {}\n    operator int() const { return to; }\n};\n\
    \ntemplate <typename Cost = int> class Graph {\n  public:\n    Graph() = default;\n\
    \    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int\
    \ from, int to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n   \
    \     assert(0 <= to && to < N);\n        G[from].emplace_back(from, to, cost,\
    \ M++);\n    }\n\n    inline void add_undirected_edge(int from, int to, Cost cost\
    \ = 1) {\n        assert(0 <= from && from < N);\n        assert(0 <= to && to\
    \ < N);\n        G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  private:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 7 \"graph/tree/lca.hpp\"\n\ntemplate <typename Cost = int> class LCA {\n\
    \  public:\n    LCA() = default;\n    explicit LCA(const Graph<Cost> &G, int root\
    \ = 0)\n        : G(G), root(root), LOG((int)log2(G.size()) + 1), depth(G.size()),\n\
    \          parent(LOG, std::vector<int>(G.size())) {\n        dfs(root, -1, 0);\n\
    \        for(int k = 0; k + 1 < LOG; k++) {\n            for(int i = 0; i < (int)G.size();\
    \ i++) {\n                if(parent[k][i] < 0) {\n                    parent[k\
    \ + 1][i] = -1;\n                } else {\n                    parent[k + 1][i]\
    \ = parent[k][parent[k][i]];\n                }\n            }\n        }\n  \
    \  }\n    int get_lca(int u, int v) {\n        if(depth[u] > depth[v]) std::swap(u,\
    \ v);\n        for(int k = 0; k < LOG; k++) {\n            if((depth[u] - depth[v])\
    \ >> k & 1) v = parent[k][v];\n        }\n        if(u == v) return u;\n     \
    \   for(int k = LOG - 1; k >= 0; k--) {\n            if(parent[k][u] != parent[k][v])\
    \ {\n                u = parent[k][u];\n                v = parent[k][v];\n  \
    \          }\n        }\n        return parent[0][u];\n    }\n    int get_dist(int\
    \ u, int v) {\n        return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);\n\
    \    }\n\n  private:\n    Graph<Cost> G;\n    const int root;\n    const int LOG;\n\
    \    std::vector<int> depth;\n    std::vector<std::vector<int>> parent;\n\n  \
    \  void dfs(int u, int p, int d) {\n        depth[u] = d;\n        parent[0][u]\
    \ = p;\n        for(int v : G[u]) {\n            if(v == p) continue;\n      \
    \      dfs(v, u, d + 1);\n        }\n    }\n};\n#line 4 \"test/library-checker/tree/lowest-common-ancestor.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    Graph<int> G(N);\n  \
    \  REP(i, 1, N) {\n        int p;\n        cin >> p;   \n        G.add_undirected_edge(i,\
    \ p);\n    }\n    LCA<int> lca(G);\n    REP(_, Q) {\n        int u, v;\n     \
    \   cin >> u >> v;\n        cout << lca.get_lca(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../graph/tree/lca.hpp\"\n\nint main() {\n    int N, Q;\n  \
    \  cin >> N >> Q;\n    Graph<int> G(N);\n    REP(i, 1, N) {\n        int p;\n\
    \        cin >> p;   \n        G.add_undirected_edge(i, p);\n    }\n    LCA<int>\
    \ lca(G);\n    REP(_, Q) {\n        int u, v;\n        cin >> u >> v;\n      \
    \  cout << lca.get_lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.cpp
  - graph/tree/lca.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/library-checker/tree/lowest-common-ancestor.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 22:24:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/tree/lowest-common-ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/tree/lowest-common-ancestor.test.cpp
- /verify/test/library-checker/tree/lowest-common-ancestor.test.cpp.html
title: test/library-checker/tree/lowest-common-ancestor.test.cpp
---
