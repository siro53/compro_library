---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: 2-SAT
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/graph/graph-scc-two-sat.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
    \n// #region Macros\n#include <bits/stdc++.h>\nusing namespace std;\n// input\
    \ output utils\nnamespace siro53_io {\n    // https://maspypy.github.io/library/other/io_old.hpp\n\
    \    struct has_val_impl {\n        template <class T>\n        static auto check(T\
    \ &&x) -> decltype(x.val(), std::true_type{});\n\n        template <class T> static\
    \ auto check(...) -> std::false_type;\n    };\n\n    template <class T>\n    class\
    \ has_val : public decltype(has_val_impl::check<T>(std::declval<T>())) {\n   \
    \ };\n\n    // debug\n    template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n    void dump(const T t) {\n        cerr << t;\n    }\n    template\
    \ <class T, enable_if_t<is_floating_point<T>::value, int> = 0>\n    void dump(const\
    \ T t) {\n        cerr << t;\n    }\n    template <class T, typename enable_if<has_val<T>::value>::type\
    \ * = nullptr>\n    void dump(const T &t) {\n        cerr << t.val();\n    }\n\
    \    void dump(__int128_t n) {\n        if(n == 0) {\n            cerr << '0';\n\
    \            return;\n        } else if(n < 0) {\n            cerr << '-';\n \
    \           n = -n;\n        }\n        string s;\n        while(n > 0) {\n  \
    \          s += (char)('0' + n % 10);\n            n /= 10;\n        }\n     \
    \   reverse(s.begin(), s.end());\n        cerr << s;\n    }\n    void dump(const\
    \ string &s) { cerr << s; }\n    void dump(const char *s) {\n        int n = (int)strlen(s);\n\
    \        for(int i = 0; i < n; i++) cerr << s[i];\n    }\n    template <class\
    \ T1, class T2> void dump(const pair<T1, T2> &p) {\n        cerr << '(';\n   \
    \     dump(p.first);\n        cerr << ',';\n        dump(p.second);\n        cerr\
    \ << ')';\n    }\n    template <class T> void dump(const vector<T> &v) {\n   \
    \     cerr << '{';\n        for(int i = 0; i < (int)v.size(); i++) {\n       \
    \     dump(v[i]);\n            if(i < (int)v.size() - 1) cerr << ',';\n      \
    \  }\n        cerr << '}';\n    }\n    template <class T> void dump(const set<T>\
    \ &s) {\n        cerr << '{';\n        for(auto it = s.begin(); it != s.end();\
    \ it++) {\n            dump(*it);\n            if(next(it) != s.end()) cerr <<\
    \ ',';\n        }\n        cerr << '}';\n    }\n    template <class Key, class\
    \ Value> void dump(const map<Key, Value> &mp) {\n        cerr << '{';\n      \
    \  for(auto it = mp.begin(); it != mp.end(); it++) {\n            dump(*it);\n\
    \            if(next(it) != mp.end()) cerr << ',';\n        }\n        cerr <<\
    \ '}';\n    }\n    template <class Key, class Value>\n    void dump(const unordered_map<Key,\
    \ Value> &mp) {\n        cerr << '{';\n        for(auto it = mp.begin(); it !=\
    \ mp.end(); it++) {\n            dump(*it);\n            if(next(it) != mp.end())\
    \ cerr << ',';\n        }\n        cerr << '}';\n    }\n    template <class T>\
    \ void dump(const deque<T> &v) {\n        cerr << '{';\n        for(int i = 0;\
    \ i < (int)v.size(); i++) {\n            dump(v[i]);\n            if(i < (int)v.size()\
    \ - 1) cerr << ',';\n        }\n        cerr << '}';\n    }\n    template <class\
    \ T> void dump(queue<T> q) {\n        cerr << '{';\n        while(!q.empty())\
    \ {\n            dump(q.front());\n            if((int)q.size() > 1) cerr << ',';\n\
    \            q.pop();\n        }\n        cerr << '}';\n    }\n\n    void debug_print()\
    \ { cerr << endl; }\n    template <class Head, class... Tail>\n    void debug_print(const\
    \ Head &h, const Tail &...t) {\n        dump(h);\n        if(sizeof...(Tail))\
    \ dump(' ');\n        debug_print(t...);\n    }\n    // print\n    template <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\n    void print_single(const\
    \ T t) {\n        cout << t;\n    }\n    template <class T, enable_if_t<is_floating_point<T>::value,\
    \ int> = 0>\n    void print_single(const T t) {\n        cout << t;\n    }\n \
    \   template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>\n\
    \    void print_single(const T t) {\n        cout << t.val();\n    }\n    void\
    \ print_single(__int128_t n) {\n        if(n == 0) {\n            cout << '0';\n\
    \            return;\n        } else if(n < 0) {\n            cout << '-';\n \
    \           n = -n;\n        }\n        string s;\n        while(n > 0) {\n  \
    \          s += (char)('0' + n % 10);\n            n /= 10;\n        }\n     \
    \   reverse(s.begin(), s.end());\n        cout << s;\n    }\n    void print_single(const\
    \ string &s) { cout << s; }\n    void print_single(const char *s) {\n        int\
    \ n = (int)strlen(s);\n        for(int i = 0; i < n; i++) cout << s[i];\n    }\n\
    \    template <class T1, class T2> void print_single(const pair<T1, T2> &p) {\n\
    \        print_single(p.first);\n        cout << ' ';\n        print_single(p.second);\n\
    \    }\n    template <class T> void print_single(const vector<T> &v) {\n     \
    \   for(int i = 0; i < (int)v.size(); i++) {\n            print_single(v[i]);\n\
    \            if(i < (int)v.size() - 1) cout << ' ';\n        }\n    }\n    template\
    \ <class T> void print_single(const set<T> &s) {\n        for(auto it = s.begin();\
    \ it != s.end(); it++) {\n            print_single(*it);\n            if(next(it)\
    \ != s.end()) cout << ' ';\n        }\n    }\n    template <class T> void print_single(const\
    \ deque<T> &v) {\n        for(int i = 0; i < (int)v.size(); i++) {\n         \
    \   print_single(v[i]);\n            if(i < (int)v.size() - 1) cout << ' ';\n\
    \        }\n    }\n    template <class T> void print_single(queue<T> q) {\n  \
    \      while(!q.empty()) {\n            print_single(q.front());\n           \
    \ if((int)q.size() > 1) cout << ' ';\n            q.pop();\n        }\n    }\n\
    \n    void print() { cout << '\\n'; }\n    template <class Head, class... Tail>\n\
    \    void print(const Head &h, const Tail &...t) {\n        print_single(h);\n\
    \        if(sizeof...(Tail)) print_single(' ');\n        print(t...);\n    }\n\
    \n    // input\n    template <class T, enable_if_t<is_integral<T>::value, int>\
    \ = 0>\n    void input_single(T &t) {\n        cin >> t;\n    }\n    template\
    \ <class T, enable_if_t<is_floating_point<T>::value, int> = 0>\n    void input_single(T\
    \ &t) {\n        cin >> t;\n    }\n    template <class T, typename enable_if<has_val<T>::value>::type\
    \ * = nullptr>\n    void input_single(T &t) {\n        cin >> t;\n    }\n    void\
    \ input_single(__int128_t &n) {\n        string s;\n        cin >> s;\n      \
    \  if(s == \"0\") {\n            n = 0;\n            return;\n        }\n    \
    \    bool is_minus = false;\n        if(s[0] == '-') {\n            s = s.substr(1);\n\
    \            is_minus = true;\n        }\n        n = 0;\n        for(int i =\
    \ 0; i < (int)s.size(); i++) n = n * 10 + (int)(s[i] - '0');\n        if(is_minus)\
    \ n = -n;\n    }\n    void input_single(string &s) { cin >> s; }\n    template\
    \ <class T1, class T2> void input_single(pair<T1, T2> &p) {\n        input_single(p.first);\n\
    \        input_single(p.second);\n    }\n    template <class T> void input_single(vector<T>\
    \ &v) {\n        for(auto &e : v) input_single(e);\n    }\n    void input() {}\n\
    \    template <class Head, class... Tail> void input(Head &h, Tail &...t) {\n\
    \        input_single(h);\n        input(t...);\n    }\n}; // namespace siro53_io\n\
    #ifdef DEBUG\n#define debug(...)                                             \
    \                \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \"\
    , debug_print(__VA_ARGS__)\n#else\n#define debug(...) (void(0))\n#endif\n// io\
    \ setup\nstruct Setup {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\nusing namespace\
    \ siro53_io;\n// types\nusing ll = long long;\nusing i128 = __int128_t;\n// input\
    \ macros\n#define INT(...)                                                   \
    \            \\\n    int __VA_ARGS__;                                        \
    \                   \\\n    input(__VA_ARGS__)\n#define LL(...)              \
    \                                                  \\\n    ll __VA_ARGS__;   \
    \                                                         \\\n    input(__VA_ARGS__)\n\
    #define STRING(...)                                                          \
    \  \\\n    string __VA_ARGS__;                                               \
    \         \\\n    input(__VA_ARGS__)\n#define CHAR(...)                      \
    \                                        \\\n    char __VA_ARGS__;           \
    \                                               \\\n    input(__VA_ARGS__)\n#define\
    \ DBL(...)                                                               \\\n\
    \    double __VA_ARGS__;                                                     \
    \   \\\n    input(__VA_ARGS__)\n#define LD(...)                              \
    \                                  \\\n    long double __VA_ARGS__;          \
    \                                         \\\n    input(__VA_ARGS__)\n#define\
    \ UINT(...)                                                              \\\n\
    \    unsigned int __VA_ARGS__;                                               \
    \   \\\n    input(__VA_ARGS__)\n#define ULL(...)                             \
    \                                  \\\n    unsigned long long __VA_ARGS__;   \
    \                                         \\\n    input(__VA_ARGS__)\n#define\
    \ VEC(name, type, len)                                                   \\\n\
    \    vector<type> name(len);                                                 \
    \   \\\n    input(name);\n#define VEC2(name, type, len1, len2)               \
    \                            \\\n    vector name(len1, vector<type>(len2));  \
    \                                   \\\n    input(name);\n// other macros\n//\
    \ https://trap.jp/post/1224/\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n\
    #define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(), (v).rend()\n\
    #define REP1(i, n) for(int i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int\
    \ i = (a); i < int(b); i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n\
    #define SORT(v) sort(ALL(v))\n#define RSORT(v) sort(RALL(v))\n#define UNIQUE(v)\
    \                                                              \\\n    sort(ALL(v)),\
    \ (v).erase(unique(ALL(v)), (v).end()), v.shrink_to_fit()\n#define REV(v) reverse(ALL(v))\n\
    #define SZ(v) ((int)(v).size())\n#define MIN(v) (*min_element(ALL(v)))\n#define\
    \ MAX(v) (*max_element(ALL(v)))\n// util const\nconst int INF = 1 << 30;\nconst\
    \ ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2 =\
    \ 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0, -1};\n\
    // util functions\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint\
    \ popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\ntemplate <class T> inline bool chmax(T &a, T b) {\n    return (a < b ? a\
    \ = b, true : false);\n}\ntemplate <class T> inline bool chmin(T &a, T b) {\n\
    \    return (a > b ? a = b, true : false);\n}\ntemplate <class T, int dim>\nauto\
    \ make_vector_impl(vector<int>& sizes, const T &e) {\n    if constexpr(dim ==\
    \ 1) {\n        return vector(sizes[0], e);\n    } else {\n        int n = sizes[dim\
    \ - 1];\n        sizes.pop_back();\n        return vector(n, make_vector_impl<T,\
    \ dim - 1>(sizes, e));\n    }\n}\ntemplate <class T, int dim>\nauto make_vector(const\
    \ int (&sizes)[dim], const T &e = T()) {\n    vector<int> s(dim);\n    for(int\
    \ i = 0; i < dim; i++) s[i] = sizes[dim - i - 1];\n    return make_vector_impl<T,\
    \ dim>(s, e);\n}\nvector<int> iota_gen(int n, int start = 0) {\n    vector<int>\
    \ ord(n);\n    iota(ord.begin(), ord.end(), start);\n    return ord;\n}\ntemplate<typename\
    \ T>\nvector<int> ord_sort(const vector<T>& v, bool greater = false) {\n    auto\
    \ ord = iota_gen((int)v.size());\n    sort(ALL(ord), [&](int i, int j) {\n   \
    \     if(greater) return v[i] > v[j];\n        return v[i] < v[j];\n    });\n\
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"graph/graph_template.hpp\"\
    \n\n#line 6 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct\
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
    \ from, cost, M++);\n    }\n\n    inline std::size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 2 \"graph/scc.hpp\"\n\n#line 6 \"graph/scc.hpp\"\n\n#line 8 \"graph/scc.hpp\"\
    \n\ntemplate <typename Cost = int> class SCC {\n  public:\n    explicit SCC(int\
    \ N)\n        : G(N), G_rev(N), comp(N, -1), seen(N, false), isBuilt(false) {}\n\
    \    explicit SCC(const Graph<Cost> &g)\n        : G(g), G_rev(g.size()), comp(g.size(),\
    \ -1), seen(g.size(), false), isBuilt(false) {\n        for(int i = 0; i < (int)g.size();\
    \ i++) {\n            for(const auto &e : g[i]) G_rev.add_directed_edge(e.to,\
    \ i);\n        }\n        build();\n    }\n    inline void add_directed_edge(int\
    \ from, int to) {\n        assert(!isBuilt &&\n               \"This scc_graph\
    \ is already built, but you tried to add edge.\");\n        G.add_directed_edge(from,\
    \ to);\n        G_rev.add_directed_edge(to, from);\n    }\n    void build() {\n\
    \        assert(!isBuilt && \"This scc_graph is already built.\");\n        for(int\
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
    \        }\n    }\n};\n#line 2 \"graph/shortest-path/dijkstra.hpp\"\n\n#line 7\
    \ \"graph/shortest-path/dijkstra.hpp\"\n\n#line 9 \"graph/shortest-path/dijkstra.hpp\"\
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
    \ std::make_pair(dist, prev);\n}\n#line 2 \"math/two_sat.hpp\"\n\n#line 4 \"math/two_sat.hpp\"\
    \n\ntemplate<class Cost = int>\nclass TwoSat {\npublic:\n    TwoSat(): TwoSat(0)\
    \ {}\n    explicit TwoSat(int N): N(N), scc(N * 2), ans(N), called_satisfiable(false)\
    \ {}\n\n    void add_clause(int i, bool f_i, int j, bool f_j) {\n        if(!f_i)\
    \ i = NOT(i);\n        if(!f_j) j = NOT(j);\n        scc.add_directed_edge(i,\
    \ NOT(j));\n        scc.add_directed_edge(j, NOT(i));\n    }\n    bool satisfiable()\
    \ {\n        scc.build();\n        for(int i = 0; i < N; i++) {\n            if(scc[i]\
    \ == scc[NOT(i)]) return false;\n            ans[i] = (scc[i] < scc[NOT(i)]);\n\
    \        }\n        called_satisfiable = true;\n        return true;\n    }\n\
    \    std::vector<bool> get_answer() const {\n        assert(called_satisfiable);\n\
    \        return ans;\n    }\n\nprivate:\n    int N;\n    SCC<Cost> scc;\n    std::vector<bool>\
    \ ans;\n    bool called_satisfiable;\n\n    inline int NOT(int i) { return i +\
    \ (i < N ? N : -N); }\n};\n#line 7 \"test/mytest/graph/graph-scc-two-sat.test.cpp\"\
    \n\n\nint main() {\n    Edge<int> edge; edge = Edge<int>(2, 3);\n    assert(edge.from\
    \ == 2 && int(edge) == 3 && edge.cost == 1 && edge.id == -1);\n    edge = Edge<int>(1,\
    \ 2, 7, 4); assert(edge.to == 2 && edge.cost == 7 && edge.id == 4);\n    Graph<int>\
    \ undirected; undirected = Graph<int>(3); undirected.add_undirected_edge(0, 1);\n\
    \    undirected.add_undirected_edge(1, 2, 7);\n    const auto& const_graph = undirected;\n\
    \    assert(const_graph.size() == 3 && const_graph[0][0].id == const_graph[1][0].id);\n\
    \    assert(const_graph[1][1].cost == 7 && const_graph[2][0].from == 2);\n   \
    \ mt19937 rng(65);\n    for(int n = 0; n <= 10; ++n) for(int trial = 0; trial\
    \ < 20; ++trial) {\n        Graph<ll> g(n); SCC<ll> built(n);\n        const ll\
    \ inf = 1000000000000LL;\n        vector<vector<ll>> d(n, vector<ll>(n, inf));\n\
    \        for(int i = 0; i < n; ++i) d[i][i] = 0;\n        for(int i = 0; i < n;\
    \ ++i) for(int j = 0; j < n; ++j) if(rng() % 4 == 0) {\n            ll w = rng()\
    \ % 10; g.add_directed_edge(i, j, w); built.add_directed_edge(i, j); d[i][j] =\
    \ min(d[i][j], w);\n        }\n        for(int k = 0; k < n; ++k) for(int i =\
    \ 0; i < n; ++i) for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n\
    \        SCC<ll> from_graph(g); built.build();\n        set<int> ids;\n      \
    \  for(int i = 0; i < n; ++i) {\n            ids.insert(built[i]);\n         \
    \   for(int j = 0; j < n; ++j) {\n                bool same = d[i][j] < inf &&\
    \ d[j][i] < inf;\n                assert((built[i] == built[j]) == same && (from_graph[i]\
    \ == from_graph[j]) == same);\n            }\n        }\n        assert(built.size()\
    \ == ids.size() && from_graph.size() == ids.size());\n        auto contracted\
    \ = from_graph.get_contracted_graph();\n        multiset<tuple<int, int, ll>>\
    \ expected, actual;\n        for(int u = 0; u < n; ++u) for(auto e : g[u]) if(from_graph[u]\
    \ != from_graph[e.to]) {\n            expected.emplace(from_graph[u], from_graph[e.to],\
    \ e.cost);\n        }\n        for(int u = 0; u < int(contracted.size()); ++u)\
    \ for(auto e : contracted[u]) {\n            assert(u < e.to); actual.emplace(u,\
    \ e.to, e.cost);\n        }\n        assert(actual == expected);\n        for(int\
    \ s = 0; s < n; ++s) {\n            auto [distance, previous] = dijkstra(g, s,\
    \ 17LL, inf);\n            auto defaults = dijkstra(g, s); auto initial_only =\
    \ dijkstra(g, s, 17LL);\n            for(int v = 0; v < n; ++v) {\n          \
    \      if(d[s][v] == inf) {\n                    assert(distance[v] == inf &&\
    \ previous[v] == -1);\n                    assert(defaults.first[v] == LLONG_MAX\
    \ && initial_only.first[v] == LLONG_MAX);\n                } else {\n        \
    \            assert(distance[v] == 17 + d[s][v] && defaults.first[v] == d[s][v]\
    \ && initial_only.first[v] == distance[v]);\n                    int u = v, length\
    \ = 0;\n                    while(u != s) {\n                        int p = previous[u];\
    \ assert(p >= 0 && p < n);\n                        bool found = false; for(auto\
    \ e : g[p]) if(e.to == u && distance[p] + e.cost == distance[u]) found = true;\n\
    \                        assert(found); u = p; assert(++length <= n);\n      \
    \              }\n                    assert(previous[s] == -1);\n           \
    \     }\n            }\n        }\n    }\n    for(int n = 0; n <= 5; ++n) for(int\
    \ trial = 0; trial < 100; ++trial) {\n        TwoSat sat(n); vector<tuple<int,\
    \ bool, int, bool>> clauses;\n        if(n) for(int k = 0; k < 10; ++k) {\n  \
    \          int i = rng() % n, j = rng() % n; bool a = rng() % 2, b = rng() % 2;\n\
    \            clauses.emplace_back(i, a, j, b); sat.add_clause(i, a, j, b);\n \
    \       }\n        auto valid = [&](const vector<bool>& value) {\n           \
    \ for(auto [i, a, j, b] : clauses) if(value[i] != a && value[j] != b) return false;\n\
    \            return true;\n        };\n        bool exists = false;\n        for(int\
    \ mask = 0; mask < (1 << n); ++mask) {\n            vector<bool> values(n); for(int\
    \ i = 0; i < n; ++i) values[i] = mask >> i & 1;\n            exists |= valid(values);\n\
    \        }\n        assert(sat.satisfiable() == exists);\n        if(exists) {\
    \ auto answer = sat.get_answer(); assert(int(answer.size()) == n && valid(answer));\
    \ }\n    }\n    INT(a, b); print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../graph/graph_template.hpp\"\n#include \"../../../graph/scc.hpp\"\
    \n#include \"../../../graph/shortest-path/dijkstra.hpp\"\n#include \"../../../math/two_sat.hpp\"\
    \n\n\nint main() {\n    Edge<int> edge; edge = Edge<int>(2, 3);\n    assert(edge.from\
    \ == 2 && int(edge) == 3 && edge.cost == 1 && edge.id == -1);\n    edge = Edge<int>(1,\
    \ 2, 7, 4); assert(edge.to == 2 && edge.cost == 7 && edge.id == 4);\n    Graph<int>\
    \ undirected; undirected = Graph<int>(3); undirected.add_undirected_edge(0, 1);\n\
    \    undirected.add_undirected_edge(1, 2, 7);\n    const auto& const_graph = undirected;\n\
    \    assert(const_graph.size() == 3 && const_graph[0][0].id == const_graph[1][0].id);\n\
    \    assert(const_graph[1][1].cost == 7 && const_graph[2][0].from == 2);\n   \
    \ mt19937 rng(65);\n    for(int n = 0; n <= 10; ++n) for(int trial = 0; trial\
    \ < 20; ++trial) {\n        Graph<ll> g(n); SCC<ll> built(n);\n        const ll\
    \ inf = 1000000000000LL;\n        vector<vector<ll>> d(n, vector<ll>(n, inf));\n\
    \        for(int i = 0; i < n; ++i) d[i][i] = 0;\n        for(int i = 0; i < n;\
    \ ++i) for(int j = 0; j < n; ++j) if(rng() % 4 == 0) {\n            ll w = rng()\
    \ % 10; g.add_directed_edge(i, j, w); built.add_directed_edge(i, j); d[i][j] =\
    \ min(d[i][j], w);\n        }\n        for(int k = 0; k < n; ++k) for(int i =\
    \ 0; i < n; ++i) for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n\
    \        SCC<ll> from_graph(g); built.build();\n        set<int> ids;\n      \
    \  for(int i = 0; i < n; ++i) {\n            ids.insert(built[i]);\n         \
    \   for(int j = 0; j < n; ++j) {\n                bool same = d[i][j] < inf &&\
    \ d[j][i] < inf;\n                assert((built[i] == built[j]) == same && (from_graph[i]\
    \ == from_graph[j]) == same);\n            }\n        }\n        assert(built.size()\
    \ == ids.size() && from_graph.size() == ids.size());\n        auto contracted\
    \ = from_graph.get_contracted_graph();\n        multiset<tuple<int, int, ll>>\
    \ expected, actual;\n        for(int u = 0; u < n; ++u) for(auto e : g[u]) if(from_graph[u]\
    \ != from_graph[e.to]) {\n            expected.emplace(from_graph[u], from_graph[e.to],\
    \ e.cost);\n        }\n        for(int u = 0; u < int(contracted.size()); ++u)\
    \ for(auto e : contracted[u]) {\n            assert(u < e.to); actual.emplace(u,\
    \ e.to, e.cost);\n        }\n        assert(actual == expected);\n        for(int\
    \ s = 0; s < n; ++s) {\n            auto [distance, previous] = dijkstra(g, s,\
    \ 17LL, inf);\n            auto defaults = dijkstra(g, s); auto initial_only =\
    \ dijkstra(g, s, 17LL);\n            for(int v = 0; v < n; ++v) {\n          \
    \      if(d[s][v] == inf) {\n                    assert(distance[v] == inf &&\
    \ previous[v] == -1);\n                    assert(defaults.first[v] == LLONG_MAX\
    \ && initial_only.first[v] == LLONG_MAX);\n                } else {\n        \
    \            assert(distance[v] == 17 + d[s][v] && defaults.first[v] == d[s][v]\
    \ && initial_only.first[v] == distance[v]);\n                    int u = v, length\
    \ = 0;\n                    while(u != s) {\n                        int p = previous[u];\
    \ assert(p >= 0 && p < n);\n                        bool found = false; for(auto\
    \ e : g[p]) if(e.to == u && distance[p] + e.cost == distance[u]) found = true;\n\
    \                        assert(found); u = p; assert(++length <= n);\n      \
    \              }\n                    assert(previous[s] == -1);\n           \
    \     }\n            }\n        }\n    }\n    for(int n = 0; n <= 5; ++n) for(int\
    \ trial = 0; trial < 100; ++trial) {\n        TwoSat sat(n); vector<tuple<int,\
    \ bool, int, bool>> clauses;\n        if(n) for(int k = 0; k < 10; ++k) {\n  \
    \          int i = rng() % n, j = rng() % n; bool a = rng() % 2, b = rng() % 2;\n\
    \            clauses.emplace_back(i, a, j, b); sat.add_clause(i, a, j, b);\n \
    \       }\n        auto valid = [&](const vector<bool>& value) {\n           \
    \ for(auto [i, a, j, b] : clauses) if(value[i] != a && value[j] != b) return false;\n\
    \            return true;\n        };\n        bool exists = false;\n        for(int\
    \ mask = 0; mask < (1 << n); ++mask) {\n            vector<bool> values(n); for(int\
    \ i = 0; i < n; ++i) values[i] = mask >> i & 1;\n            exists |= valid(values);\n\
    \        }\n        assert(sat.satisfiable() == exists);\n        if(exists) {\
    \ auto answer = sat.get_answer(); assert(int(answer.size()) == n && valid(answer));\
    \ }\n    }\n    INT(a, b); print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/graph_template.hpp
  - graph/scc.hpp
  - graph/shortest-path/dijkstra.hpp
  - math/two_sat.hpp
  isVerificationFile: true
  path: test/mytest/graph/graph-scc-two-sat.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:39:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/graph/graph-scc-two-sat.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/graph/graph-scc-two-sat.test.cpp
- /verify/test/mytest/graph/graph-scc-two-sat.test.cpp.html
title: test/mytest/graph/graph-scc-two-sat.test.cpp
---
