---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/tree/diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/library-checker/tree/tree-diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#line 1 \"template/template.cpp\"\
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
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 2 \"graph/tree/diameter.hpp\"\
    \n\n#line 6 \"graph/tree/diameter.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct\
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
    #line 8 \"graph/tree/diameter.hpp\"\n\ntemplate <typename Cost = int>\nstd::pair<Cost,\
    \ std::vector<int>> get_diameter(const Graph<Cost> &G) {\n    std::vector<Cost>\
    \ depth(G.size());\n    std::vector<int> par(G.size(), -1);\n    auto dfs = [&](auto\
    \ &&self, int u, int p, Cost d) -> void {\n        depth[u] = d;\n        par[u]\
    \ = p;\n        for(const auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            self(self, e.to, u, d + e.cost);\n        }\n    };\n    dfs(dfs,\
    \ 0, -1, 0);\n    int from = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    dfs(dfs, from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<int> path = {to};\n    while(1) {\n      \
    \  int nxt = par[path.back()];\n        if(nxt == -1) break;\n        path.push_back(nxt);\n\
    \    }\n    return std::make_pair(depth[to], path);\n}\n#line 4 \"test/library-checker/tree/tree-diameter.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    Graph<ll> G(N);\n    REP(_, N-1)\
    \ {\n        int a, b;\n        ll c;\n        cin >> a >> b >> c;\n        G.add_undirected_edge(a,\
    \ b, c);\n    }\n    auto [diam, path] = get_diameter(G);\n    cout << diam <<\
    \ ' ' << SZ(path) << '\\n';\n    REP(i, SZ(path)) cout << path[i] << \" \\n\"\
    [i == SZ(path) - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ \"../../../template/template.cpp\"\n#include \"../../../graph/tree/diameter.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    Graph<ll> G(N);\n    REP(_, N-1)\
    \ {\n        int a, b;\n        ll c;\n        cin >> a >> b >> c;\n        G.add_undirected_edge(a,\
    \ b, c);\n    }\n    auto [diam, path] = get_diameter(G);\n    cout << diam <<\
    \ ' ' << SZ(path) << '\\n';\n    REP(i, SZ(path)) cout << path[i] << \" \\n\"\
    [i == SZ(path) - 1];\n}"
  dependsOn:
  - template/template.cpp
  - graph/tree/diameter.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/library-checker/tree/tree-diameter.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 22:24:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/tree/tree-diameter.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/tree/tree-diameter.test.cpp
- /verify/test/library-checker/tree/tree-diameter.test.cpp.html
title: test/library-checker/tree/tree-diameter.test.cpp
---
