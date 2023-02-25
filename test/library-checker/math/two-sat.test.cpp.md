---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: math/two_sat.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/library-checker/math/two-sat.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#line 2 \"math/two_sat.hpp\"\n\n\
    #line 2 \"graph/scc.hpp\"\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"graph/graph_template.hpp\"\n\n#line 5 \"graph/graph_template.hpp\"\
    \n\ntemplate <typename Cost = int> struct Edge {\n    int from, to;\n    Cost\
    \ cost;\n    int id;\n    Edge() = default;\n    explicit Edge(int from, int to,\
    \ Cost cost = 1, int id = -1)\n        : from(from), to(to), cost(cost), id(id)\
    \ {}\n};\n\ntemplate <typename Cost = int> class Graph {\n  public:\n    Graph()\
    \ = default;\n    explicit Graph(int N) : N(N), M(0), G(N) {}\n\n    inline void\
    \ add_directed_edge(int from, int to, Cost cost = 1) {\n        assert(0 <= from\
    \ && from < N);\n        assert(0 <= to && to < N);\n        G[from].emplace_back(from,\
    \ to, cost, M++);\n    }\n\n    inline void add_undirected_edge(int from, int\
    \ to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        G[from].emplace_back(from, to, cost, M);\n      \
    \  G[to].emplace_back(to, from, cost, M++);\n    }\n\n    inline size_t size()\
    \ const { return G.size(); }\n    inline std::vector<Edge<Cost>> &operator[](const\
    \ int &i) { return G[i]; }\n    inline const std::vector<Edge<Cost>> &operator[](const\
    \ int &i) const {\n        return G[i];\n    }\n\n  private:\n    int N, M;\n\
    \    std::vector<std::vector<Edge<Cost>>> G;\n};\n\ntemplate <class Cost = int>\
    \ using Edges = std::vector<Edge<Cost>>;\n#line 8 \"graph/scc.hpp\"\n\ntemplate\
    \ <typename Cost = int> class SCC {\n  public:\n    explicit SCC(int N)\n    \
    \    : G(N), G_rev(N), comp(N, -1), seen(N, false), isBuilt(false) {}\n    explicit\
    \ SCC(const Graph<Cost> &g)\n        : G(g), G_rev(g.size()), comp(g.size(), -1),\
    \ seen(g.size(), false) {\n        for(int i = 0; i < (int)g.size(); i++) {\n\
    \            for(const auto &e : g[i]) G_rev.add_directed_edge(e.to, i);\n   \
    \     }\n        build();\n    }\n    inline void add_directed_edge(int from,\
    \ int to) {\n        assert(!isBuilt &&\n               \"This scc_graph is already\
    \ built, but you tried to add edge.\");\n        G.add_directed_edge(from, to);\n\
    \        G_rev.add_directed_edge(to, from);\n    }\n    void build() {\n     \
    \   assert(!isBuilt && \"This scc_graph is already built.\");\n        for(int\
    \ i = 0; i < (int)G.size(); i++) {\n            if(!seen[i]) dfs(i);\n       \
    \ }\n        std::reverse(vs.begin(), vs.end());\n        count = 0;\n       \
    \ for(const int v : vs) {\n            if(comp[v] == -1) {\n                dfs_rev(v,\
    \ count);\n                count++;\n            }\n        }\n        isBuilt\
    \ = true;\n    }\n    Graph<Cost> get_contracted_graph() {\n        assert(isBuilt\
    \ && \"This scc_graph is not yet built.\");\n        Graph<Cost> new_g(count);\n\
    \        for(int i = 0; i < (int)G.size(); i++) {\n            for(const auto\
    \ &e : G[i]) {\n                int from = comp[i];\n                int to =\
    \ comp[e.to];\n                if(from != to) new_g.add_directed_edge(from, to,\
    \ e.cost);\n            }\n        }\n        return new_g;\n    }\n    int operator[](const\
    \ int &k) const {\n        assert(isBuilt && \"This scc_graph is not yet built.\"\
    );\n        return comp[k];\n    }\n    size_t size() { return (size_t)count;\
    \ }\n\n  private:\n    Graph<Cost> G, G_rev;\n    std::vector<int> vs, comp;\n\
    \    std::vector<bool> seen;\n    int count;\n    bool isBuilt;\n\n    void dfs(int\
    \ u) {\n        seen[u] = true;\n        for(const auto &e : G[u]) {\n       \
    \     if(!seen[e.to]) dfs(e.to);\n        }\n        vs.push_back(u);\n    }\n\
    \    void dfs_rev(int u, int idx) {\n        comp[u] = idx;\n        for(const\
    \ auto &e : G_rev[u]) {\n            if(comp[e.to] == -1) dfs_rev(e.to, idx);\n\
    \        }\n    }\n};\n#line 4 \"math/two_sat.hpp\"\n\ntemplate<class Cost = int>\n\
    class TwoSat {\npublic:\n    TwoSat() = default;\n    explicit TwoSat(int N):\
    \ N(N), scc(N * 2), ans(N), called_satisfiable(false) {}\n\n    void add_clause(int\
    \ i, bool f_i, int j, bool f_j) {\n        if(!f_i) i = NOT(i);\n        if(!f_j)\
    \ j = NOT(j);\n        scc.add_directed_edge(i, NOT(j));\n        scc.add_directed_edge(j,\
    \ NOT(i));\n    }\n    bool satisfiable() {\n        scc.build();\n        for(int\
    \ i = 0; i < N; i++) {\n            if(scc[i] == scc[NOT(i)]) return false;\n\
    \            ans[i] = (scc[i] < scc[NOT(i)]);\n        }\n        called_satisfiable\
    \ = true;\n        return true;\n    }\n    std::vector<bool> get_answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int N;\n    SCC<Cost> scc;\n    std::vector<bool> ans;\n    bool called_satisfiable;\n\
    \n    inline int NOT(int i) { return i + (i < N ? N : -N); }\n};\n#line 1 \"template/template.cpp\"\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 4 \"test/library-checker/math/two-sat.test.cpp\"\
    \n\n\nint main() {\n    string tmp;\n    cin >> tmp;\n    cin >> tmp;\n    int\
    \ N, M;\n    cin >> N >> M;\n\n    TwoSat ts(N);\n\n    REP(i, M) {\n        int\
    \ a, b, c;\n        cin >> a >> b >> c;\n        ts.add_clause(abs(a) - 1, a >\
    \ 0, abs(b) - 1, b > 0);\n    }\n\n    if(!ts.satisfiable()) {\n        cout <<\
    \ \"s UNSATISFIABLE\\n\";\n        return 0;\n    }\n\n    auto ans = ts.get_answer();\n\
    \n    cout << \"s SATISFIABLE\\n\";\n    cout << \"v \";\n    REP(i, N) cout <<\
    \ (ans[i] ? 1 : -1) * (i + 1) << ' ';\n    cout << 0 << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include \"\
    ../../../math/two_sat.hpp\"\n#include \"../../../template/template.cpp\"\n\n\n\
    int main() {\n    string tmp;\n    cin >> tmp;\n    cin >> tmp;\n    int N, M;\n\
    \    cin >> N >> M;\n\n    TwoSat ts(N);\n\n    REP(i, M) {\n        int a, b,\
    \ c;\n        cin >> a >> b >> c;\n        ts.add_clause(abs(a) - 1, a > 0, abs(b)\
    \ - 1, b > 0);\n    }\n\n    if(!ts.satisfiable()) {\n        cout << \"s UNSATISFIABLE\\\
    n\";\n        return 0;\n    }\n\n    auto ans = ts.get_answer();\n\n    cout\
    \ << \"s SATISFIABLE\\n\";\n    cout << \"v \";\n    REP(i, N) cout << (ans[i]\
    \ ? 1 : -1) * (i + 1) << ' ';\n    cout << 0 << '\\n';\n}"
  dependsOn:
  - math/two_sat.hpp
  - graph/scc.hpp
  - graph/graph_template.hpp
  - template/template.cpp
  isVerificationFile: true
  path: test/library-checker/math/two-sat.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/math/two-sat.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/math/two-sat.test.cpp
- /verify/test/library-checker/math/two-sat.test.cpp.html
title: test/library-checker/math/two-sat.test.cpp
---
