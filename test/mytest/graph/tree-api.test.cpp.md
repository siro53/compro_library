---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':x:'
    path: graph/namori.hpp
    title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\u89E3"
  - icon: ':x:'
    path: graph/tree/centroid-decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  - icon: ':question:'
    path: graph/tree/diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':question:'
    path: graph/tree/hld.hpp
    title: Heavy Light Decomposition
  - icon: ':x:'
    path: graph/tree/lca.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148\uFF08\u30C0\u30D6\u30EA\u30F3\u30B0\
      \uFF09"
  - icon: ':question:'
    path: graph/tree/tree-hash.hpp
    title: "\u6728\u30CF\u30C3\u30B7\u30E5"
  - icon: ':question:'
    path: random/rng.hpp
    title: "\u4E71\u6570\u751F\u6210"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u7AF6\u30D7\u30ED\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/graph/tree-api.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\n\
    // #region Macros\n#include <bits/stdc++.h>\nusing namespace std;\n// input output\
    \ utils\nnamespace siro53_io {\n    // https://maspypy.github.io/library/other/io_old.hpp\n\
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
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"graph/tree/hld.hpp\"\n\n\
    #line 4 \"graph/tree/hld.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n#line\
    \ 6 \"graph/graph_template.hpp\"\n\ntemplate <typename Cost = int> struct Edge\
    \ {\n    int from, to;\n    Cost cost;\n    int id;\n    Edge() = default;\n \
    \   explicit Edge(int from, int to, Cost cost = 1, int id = -1)\n        : from(from),\
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
    #line 6 \"graph/tree/hld.hpp\"\n\ntemplate <typename Cost = int> class HeavyLightDecomposition\
    \ {\n  public:\n    explicit HeavyLightDecomposition(int N)\n        : G(N), in(N),\
    \ out(N), sz(N), head(N), par(N), dep(N), rev(N),\n          isBuilt(false) {}\n\
    \    explicit HeavyLightDecomposition(const Graph<Cost> &g)\n        : G(g), in(g.size()),\
    \ out(g.size()), sz(g.size()), head(g.size()),\n          par(g.size()), dep(g.size()),\
    \ rev(g.size()), isBuilt(false) {\n        build();\n    }\n    void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    void build(int root = 0) {\n        dfs1(root, -1, 0);\n        head[root]\
    \ = root;\n        int idx = 0;\n        dfs2(root, -1, idx);\n        isBuilt\
    \ = true;\n    }\n\tint lca(int u, int v) const {\n\t\tassert(isBuilt);\n\t\t\
    assert(0 <= u && u < (int)G.size());\n\t\tassert(0 <= v && v < (int)G.size());\n\
    \t\twhile(1) {\n\t\t\tif(in[u] > in[v]) std::swap(u, v);\n\t\t\tif(head[u] ==\
    \ head[v]) return u;\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\tint dist(int u, int\
    \ v) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\treturn (dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)]);\n\t}\n\tint la(int u, int k) const {\n\t\tassert(isBuilt);\n\t\tassert(0\
    \ <= u && u < (int)G.size());\n\t\tif(dep[u] < k) return -1;\n\t\twhile(1) {\n\
    \t\t\tif(in[u] - k >= in[head[u]]) {\n\t\t\t\treturn rev[in[u] - k];\n\t\t\t}\n\
    \t\t\tk -= (in[u] - in[head[u]] + 1);\n\t\t\tu = par[head[u]];\n\t\t}\n\t}\n\t\
    template<class F>\n\tvoid path_query(int u, int v, const F& f, bool edge = false)\
    \ const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\t\t\
    assert(0 <= v && v < (int)G.size());\n\t\twhile(1) {\n\t\t\tif(in[u] > in[v])\
    \ std::swap(u, v);\n\t\t\tif(head[u] == head[v]) {\n\t\t\t\tf(in[u] + (int)(edge),\
    \ in[v] + 1);\n\t\t\t\tbreak;\n\t\t\t} else {\n\t\t\t\tf(in[head[v]], in[v] +\
    \ 1);\n\t\t\t}\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate<class F, class\
    \ F_rev>\n\tvoid path_query(int u, int v, const F& f, const F_rev& f_rev, bool\
    \ edge = false) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\tassert(0 <= v && v < (int)G.size());\n\t\tint L = lca(u, v);\n\t\tpath_query<F>(u,\
    \ L, f, edge);\n\t\tpath_query<F_rev>(L, v, f_rev, true);\n\t}\n\ttemplate<class\
    \ F>\n\tvoid subtree_query(int u, const F& f) const {\n\t\tassert(isBuilt);\n\t\
    \tassert(0 <= u && u < (int)G.size());\n\t\tf(in[u], out[u]);\n\t}\n\tint operator[](int\
    \ u) const {\n\t\tassert(isBuilt);\n\t\tassert(0 <= u && u < (int)G.size());\n\
    \t\treturn in[u];\n\t}\n\n  private:\n    Graph<Cost> G;\n    std::vector<int>\
    \ in, out, sz, head, par, dep, rev;\n    bool isBuilt;\n\n    void dfs1(int u,\
    \ int p, int d) {\n        dep[u] = d;\n        sz[u] = 1;\n        if(!G[u].empty()\
    \ && G[u].front().to == p) {\n            std::swap(G[u].front(), G[u].back());\n\
    \        }\n        for(auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            dfs1(e.to, u, d + 1);\n            sz[u] += sz[e.to];\n         \
    \   if(sz[e.to] > sz[G[u].front().to]) { std::swap(G[u].front(), e); }\n     \
    \   }\n    }\n\n    void dfs2(int u, int p, int &idx) {\n        par[u] = p;\n\
    \        in[u] = idx++;\n        rev[in[u]] = u;\n        for(const auto &e :\
    \ G[u]) {\n            if(e.to == p) continue;\n            head[e.to] = (e.to\
    \ == G[u].front().to ? head[u] : e.to);\n            dfs2(e.to, u, idx);\n   \
    \     }\n        out[u] = idx;\n    }\n};\n#line 2 \"graph/tree/lca.hpp\"\n\n\
    #line 5 \"graph/tree/lca.hpp\"\n\n#line 7 \"graph/tree/lca.hpp\"\n\ntemplate <typename\
    \ Cost = int> class LCA {\n  public:\n    LCA(): G(0), root(0), LOG(0) {}\n  \
    \  explicit LCA(const Graph<Cost> &G, int root = 0)\n        : G(G), root(root),\
    \ LOG((int)log2(G.size()) + 1), depth(G.size()),\n          parent(LOG, std::vector<int>(G.size()))\
    \ {\n        dfs(root, -1, 0);\n        for(int k = 0; k + 1 < LOG; k++) {\n \
    \           for(int i = 0; i < (int)G.size(); i++) {\n                if(parent[k][i]\
    \ < 0) {\n                    parent[k + 1][i] = -1;\n                } else {\n\
    \                    parent[k + 1][i] = parent[k][parent[k][i]];\n           \
    \     }\n            }\n        }\n    }\n    int get_lca(int u, int v) {\n  \
    \      assert(0 <= u && u < (int)G.size());\n        assert(0 <= v && v < (int)G.size());\n\
    \        if(depth[u] > depth[v]) std::swap(u, v);\n        for(int k = 0; k <\
    \ LOG; k++) {\n            if((depth[v] - depth[u]) >> k & 1) v = parent[k][v];\n\
    \        }\n        if(u == v) return u;\n        for(int k = LOG - 1; k >= 0;\
    \ k--) {\n            if(parent[k][u] != parent[k][v]) {\n                u =\
    \ parent[k][u];\n                v = parent[k][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n    int get_dist(int u, int v) {\n     \
    \   return (depth[u] + depth[v] - 2 * depth[get_lca(u, v)]);\n    }\n\n  private:\n\
    \    Graph<Cost> G;\n    const int root;\n    const int LOG;\n    std::vector<int>\
    \ depth;\n    std::vector<std::vector<int>> parent;\n\n    void dfs(int u, int\
    \ p, int d) {\n        depth[u] = d;\n        parent[0][u] = p;\n        for(int\
    \ v : G[u]) {\n            if(v == p) continue;\n            dfs(v, u, d + 1);\n\
    \        }\n    }\n};\n#line 2 \"graph/tree/diameter.hpp\"\n\n#line 6 \"graph/tree/diameter.hpp\"\
    \n\n#line 8 \"graph/tree/diameter.hpp\"\n\ntemplate <typename Cost = int>\nstd::pair<Cost,\
    \ std::vector<int>> get_diameter(const Graph<Cost> &G) {\n    std::vector<Cost>\
    \ depth(G.size());\n    std::vector<int> par(G.size(), -1);\n    auto dfs = [&](auto\
    \ &&self, int u, int p, Cost d) -> void {\n        depth[u] = d;\n        par[u]\
    \ = p;\n        for(const auto &e : G[u]) {\n            if(e.to == p) continue;\n\
    \            self(self, e.to, u, d + e.cost);\n        }\n    };\n    dfs(dfs,\
    \ 0, -1, 0);\n    int from = std::max_element(depth.begin(), depth.end()) - depth.begin();\n\
    \    dfs(dfs, from, -1, 0);\n    int to = std::max_element(depth.begin(), depth.end())\
    \ - depth.begin();\n    std::vector<int> path = {to};\n    while(1) {\n      \
    \  int nxt = par[path.back()];\n        if(nxt == -1) break;\n        path.push_back(nxt);\n\
    \    }\n    return std::make_pair(depth[to], path);\n}\n#line 2 \"graph/tree/centroid-decomposition.hpp\"\
    \n\n#line 4 \"graph/tree/centroid-decomposition.hpp\"\n\n// TODO: \u826F\u3044\
    \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30A4\u30B9\u3092\u6A21\u7D22\u3059\u308B\
    \nstruct CentroidDecomposition {\n    const Graph<int>& G;\n    std::vector<int>\
    \ subtree_size, parent;\n    std::vector<bool> removed;\n\n    explicit CentroidDecomposition(const\
    \ Graph<int>& g): G(g), subtree_size(g.size(), 0), parent(g.size(), -1), removed(g.size(),\
    \ false) {}\n\n    void get_subtree_size(int u, int p) {\n        subtree_size[u]\
    \ = 1;\n        for(int v : G[u]) {\n            if(v == p or removed[v]) continue;\n\
    \            get_subtree_size(v, u);\n            subtree_size[u] += subtree_size[v];\n\
    \        }\n    }\n\n    void decomp(int u, int p) {\n        get_subtree_size(u,\
    \ -1);\n        int sz = subtree_size[u];\n        int pre = -1;\n        while(1)\
    \ {\n            int mx = -1, mx_v = -1;\n            for(int v : G[u]) {\n  \
    \              if(v == pre or removed[v]) continue;\n                if(mx < subtree_size[v])\
    \ {\n                    mx = subtree_size[v];\n                    mx_v = v;\n\
    \                }\n            }\n            if(mx * 2 <= sz) break;\n     \
    \       pre = u;\n            u = mx_v;\n        }\n        removed[u] = true;\n\
    \        parent[u] = p;\n        for(int v : G[u]) {\n            if(removed[v])\
    \ continue;\n            decomp(v, u);\n        }\n    }\n};\n#line 2 \"graph/tree/tree-hash.hpp\"\
    \n\n#line 2 \"random/rng.hpp\"\n\n#line 5 \"random/rng.hpp\"\n\nclass RNG32 {\n\
    \  public:\n    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n\nclass RNG_0_1 {\n  public:\n    RNG_0_1() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    // [0.0, 1.0)\n    double rand() {\n      auto bits = mt() >> 11;\n\
    \      return (double)bits / denomitor;\n    }\n\n    auto operator()() { return\
    \ rand(); }\n\n  private:\n    std::mt19937_64 mt;\n    const double denomitor\
    \ = 1LL << 53;\n};\n#line 5 \"graph/tree/tree-hash.hpp\"\n\ntemplate <typename\
    \ Cost = int> class TreeHash {\n  public:\n    explicit TreeHash(int n) : G(n)\
    \ {\n        RNG64 rng;\n        for(int i = 0; i < n; i++) rnd.push_back(rng.randint(1,\
    \ mod - 1));\n    }\n    explicit TreeHash(const Graph<Cost> &g) : G(g) {\n  \
    \      RNG64 rng;\n        for(int i = 0; i < (int)G.size(); i++)\n          \
    \  rnd.push_back(rng.randint(1, mod - 1));\n    }\n    inline void add_edge(int\
    \ from, int to, Cost cost = 1) {\n        G.add_undirected_edge(from, to, cost);\n\
    \    }\n    unsigned long long get_hash() {\n        auto [_, path] = get_diameter(G);\n\
    \        int len = (int)path.size();\n        std::vector<int> cent;\n       \
    \ if(len & 1) {\n            cent = {path[len / 2]};\n        } else {\n     \
    \       cent = {path[len / 2], path[len / 2 - 1]};\n        }\n        unsigned\
    \ long long res = std::numeric_limits<unsigned long long>::max();\n        for(const\
    \ int &root : cent) {\n            std::vector<unsigned long long> hashed(G.size(),\
    \ 1);\n            hash_dfs(root, -1, 0, hashed);\n            res = std::min(res,\
    \ hashed[root]);\n        }\n        return res;\n    }\n\n  private:\n    Graph<Cost>\
    \ G;\n    static constexpr unsigned long long mod = (1ULL << 61) - 1;\n    static\
    \ inline std::vector<unsigned long long> rnd;\n\n    inline unsigned long long\
    \ add(unsigned long long a, unsigned long long b) {\n        if((a += b) >= mod)\
    \ a -= mod;\n        return a;\n    }\n    inline unsigned long long mul(unsigned\
    \ long long a, unsigned long long b) {\n        __uint128_t t = a;\n        t\
    \ *= b;\n        unsigned long long na = t >> 61;\n        unsigned long long\
    \ nb = t & mod;\n        if((na += nb) >= mod) na -= mod;\n        return na;\n\
    \    }\n    unsigned long long hash_dfs(int v, int p, int d,\n               \
    \                 std::vector<unsigned long long> &res) {\n        for(const auto\
    \ &e : G[v]) {\n            if(e.to != p) {\n                res[v] = mul(res[v],\
    \ hash_dfs(e.to, v, d + 1, res));\n            }\n        }\n        return res[v]\
    \ = add(res[v], rnd[d]);\n    }\n};\n#line 2 \"graph/namori.hpp\"\n\n#line 4 \"\
    graph/namori.hpp\"\n\ntemplate <typename Cost> class Namori : public Graph<Cost>\
    \ {\n  public:\n    using Graph<Cost>::Graph;\n    using Graph<Cost>::G;\n\n \
    \   void build() {\n        int N = (int)G.size();\n        std::vector<int> deg(N),\
    \ st;\n        std::vector<bool> seen(N);\n        for(int i = 0; i < N; i++)\
    \ {\n            deg[i] = (int)G[i].size();\n            if(deg[i] == 1) {\n \
    \               st.emplace_back(i);\n                seen[i] = true;\n       \
    \     }\n        }\n        while(!st.empty()) {\n            int u = st.back();\n\
    \            st.pop_back();\n            for(int v : G[u]) {\n               \
    \ if(seen[v]) continue;\n                deg[v]--;\n                if(deg[v]\
    \ == 1) {\n                    st.emplace_back(v);\n                    seen[v]\
    \ = true;\n                }\n            }\n        }\n        loop_id.resize(N,\
    \ -1);\n        std::vector<int> loop;\n        for(int i = 0; i < N; i++) {\n\
    \            if(seen[i]) continue;\n            auto dfs = [&](auto &&self, int\
    \ u) -> void {\n                loop_id[u] = (int)loop.size();\n             \
    \   loop.push_back(u);\n                seen[u] = true;\n                for(int\
    \ v : G[u]) {\n                    if(seen[v]) continue;\n                   \
    \ self(self, v);\n                }\n            };\n            dfs(dfs, i);\n\
    \            break;\n        }\n        for(int i = 0; i < (int)loop.size(); i++)\
    \ {\n            auto dfs = [&](auto&& self, int u) -> void {\n              \
    \  for(int v : G[u]) {\n                    if(loop_id[v] != -1) continue;\n \
    \                   loop_id[v] = loop_id[u];\n                    self(self, v);\n\
    \                }\n            };\n            dfs(dfs, loop[i]);\n        }\n\
    \    }\n    int operator[](int i) const { return loop_id[i]; }\n\n  private:\n\
    \    std::vector<int> loop_id;\n};\n#line 9 \"test/mytest/graph/tree-api.test.cpp\"\
    \n\n\nint main() {\n    mt19937 rng(66);\n    for(int n = 1; n <= 20; ++n) {\n\
    \        Graph<int> g(n); vector<vector<int>> d(n, vector<int>(n, 1000));\n  \
    \      for(int i = 0; i < n; ++i) d[i][i] = 0;\n        vector<pair<int, int>>\
    \ edges;\n        for(int i = 1; i < n; ++i) { int p = rng() % i; g.add_undirected_edge(p,\
    \ i); edges.emplace_back(p, i); d[i][p] = d[p][i] = 1; }\n        for(int k =\
    \ 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) d[i][j]\
    \ = min(d[i][j], d[i][k] + d[k][j]);\n        auto [length, path] = get_diameter(g);\n\
    \        int expected_diameter = 0; for(auto& row : d) for(int x : row) expected_diameter\
    \ = max(expected_diameter, x);\n        assert(length == expected_diameter &&\
    \ int(path.size()) == length + 1);\n        for(int i = 1; i < int(path.size());\
    \ ++i) assert(d[path[i - 1]][path[i]] == 1);\n        for(int root : {0, n - 1})\
    \ {\n            HeavyLightDecomposition<int> hld(n);\n            for(auto [u,\
    \ v] : edges) hld.add_edge(u, v);\n            hld.build(root); HeavyLightDecomposition<int>\
    \ copied(g);\n            LCA<int> empty_lca;\n            LCA<int> lca(g, root);\n\
    \            LCA<int> default_root(g); assert(default_root.get_lca(0, n - 1) ==\
    \ 0);\n            vector<int> parent(n, -1), depth(n), stack{root}, rev(n);\n\
    \            for(int i = 0; i < int(stack.size()); ++i) for(int v : g[stack[i]])\
    \ if(v != parent[stack[i]]) {\n                parent[v] = stack[i]; depth[v]\
    \ = depth[stack[i]] + 1; stack.push_back(v);\n            }\n            for(int\
    \ i = 0; i < n; ++i) rev[hld[i]] = i;\n            for(int u = 0; u < n; ++u)\
    \ {\n                int ancestor = u;\n                for(int k = 0; k <= depth[u]\
    \ + 1; ++k) { assert(hld.la(u, k) == ancestor); if(ancestor != -1) ancestor =\
    \ parent[ancestor]; }\n                vector<int> subtree;\n                hld.subtree_query(u,\
    \ [&](int l, int r) { for(int i = l; i < r; ++i) subtree.push_back(rev[i]); });\n\
    \                sort(subtree.begin(), subtree.end()); vector<int> wanted;\n \
    \               for(int v = 0; v < n; ++v) { int x = v; while(x != -1 && x !=\
    \ u) x = parent[x]; if(x == u) wanted.push_back(v); }\n                assert(subtree\
    \ == wanted);\n                for(int v = 0; v < n; ++v) {\n                \
    \    int x = u, y = v; while(depth[x] > depth[y]) x = parent[x]; while(depth[y]\
    \ > depth[x]) y = parent[y];\n                    while(x != y) { x = parent[x];\
    \ y = parent[y]; }\n                    assert(hld.lca(u, v) == x && lca.get_lca(u,\
    \ v) == x);\n                    assert(hld.dist(u, v) == d[u][v] && lca.get_dist(u,\
    \ v) == d[u][v] && copied.dist(u, v) == d[u][v]);\n                    for(bool\
    \ edge : {false, true}) {\n                        vector<int> actual, expected;\n\
    \                        auto collect = [&](int l, int r) { for(int i = l; i <\
    \ r; ++i) actual.push_back(rev[i]); };\n                        hld.path_query(u,\
    \ v, collect, edge);\n                        for(int z = u; z != x; z = parent[z])\
    \ expected.push_back(z);\n                        for(int z = v; z != x; z = parent[z])\
    \ expected.push_back(z);\n                        if(!edge) expected.push_back(x);\n\
    \                        sort(expected.begin(), expected.end()); sort(actual.begin(),\
    \ actual.end()); assert(actual == expected);\n                        actual.clear();\
    \ hld.path_query(u, v, collect, collect, edge); sort(actual.begin(), actual.end());\
    \ assert(actual == expected);\n                    }\n                }\n    \
    \        }\n        }\n        CentroidDecomposition centroid(g);\n        assert(&centroid.G\
    \ == &g && centroid.parent == vector<int>(n, -1) && centroid.removed == vector<bool>(n,\
    \ false));\n        centroid.get_subtree_size(0, -1); assert(centroid.subtree_size[0]\
    \ == n);\n        centroid.decomp(0, -1); assert(count(centroid.parent.begin(),\
    \ centroid.parent.end(), -1) == 1);\n        for(int u = 0; u < n; ++u) {\n  \
    \          assert(centroid.removed[u]);\n            vector<int> component;\n\
    \            for(int v = 0; v < n; ++v) { int x = v; while(x != -1 && x != u)\
    \ x = centroid.parent[x]; if(x == u) component.push_back(v); }\n            vector<bool>\
    \ present(n); for(int v : component) present[v] = true; present[u] = false;\n\
    \            for(int v : g[u]) if(present[v]) {\n                vector<int> todo{v};\
    \ vector<bool> visited(n); visited[v] = true;\n                for(int i = 0;\
    \ i < int(todo.size()); ++i) for(int w : g[todo[i]]) if(present[w] && !visited[w])\
    \ { visited[w] = true; todo.push_back(w); }\n                assert(todo.size()\
    \ * 2 <= component.size());\n            }\n        }\n        TreeHash<int> first(g),\
    \ relabeled(n);\n        vector<int> permutation(n); iota(permutation.begin(),\
    \ permutation.end(), 0); shuffle(permutation.begin(), permutation.end(), rng);\n\
    \        for(auto [u, v] : edges) relabeled.add_edge(permutation[u], permutation[v]);\n\
    \        assert(first.get_hash() == relabeled.get_hash() && first.get_hash() ==\
    \ first.get_hash());\n    }\n    for(int cycle = 3; cycle <= 8; ++cycle) {\n \
    \       int n = cycle + 15; Namori<int> graph(n); vector<int> attached(n);\n \
    \       for(int i = 0; i < cycle; ++i) { graph.add_undirected_edge(i, (i + 1)\
    \ % cycle); attached[i] = i; }\n        for(int i = cycle; i < n; ++i) { int p\
    \ = rng() % i; graph.add_undirected_edge(i, p); attached[i] = attached[p]; }\n\
    \        assert(graph.size() == unsigned(n)); graph.build();\n        for(int\
    \ i = 0; i < n; ++i) for(int j = 0; j < n; ++j) assert((graph[i] == graph[j])\
    \ == (attached[i] == attached[j]));\n    }\n    INT(a, b); print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../graph/tree/hld.hpp\"\n#include \"../../../graph/tree/lca.hpp\"\
    \n#include \"../../../graph/tree/diameter.hpp\"\n#include \"../../../graph/tree/centroid-decomposition.hpp\"\
    \n#include \"../../../graph/tree/tree-hash.hpp\"\n#include \"../../../graph/namori.hpp\"\
    \n\n\nint main() {\n    mt19937 rng(66);\n    for(int n = 1; n <= 20; ++n) {\n\
    \        Graph<int> g(n); vector<vector<int>> d(n, vector<int>(n, 1000));\n  \
    \      for(int i = 0; i < n; ++i) d[i][i] = 0;\n        vector<pair<int, int>>\
    \ edges;\n        for(int i = 1; i < n; ++i) { int p = rng() % i; g.add_undirected_edge(p,\
    \ i); edges.emplace_back(p, i); d[i][p] = d[p][i] = 1; }\n        for(int k =\
    \ 0; k < n; ++k) for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) d[i][j]\
    \ = min(d[i][j], d[i][k] + d[k][j]);\n        auto [length, path] = get_diameter(g);\n\
    \        int expected_diameter = 0; for(auto& row : d) for(int x : row) expected_diameter\
    \ = max(expected_diameter, x);\n        assert(length == expected_diameter &&\
    \ int(path.size()) == length + 1);\n        for(int i = 1; i < int(path.size());\
    \ ++i) assert(d[path[i - 1]][path[i]] == 1);\n        for(int root : {0, n - 1})\
    \ {\n            HeavyLightDecomposition<int> hld(n);\n            for(auto [u,\
    \ v] : edges) hld.add_edge(u, v);\n            hld.build(root); HeavyLightDecomposition<int>\
    \ copied(g);\n            LCA<int> empty_lca;\n            LCA<int> lca(g, root);\n\
    \            LCA<int> default_root(g); assert(default_root.get_lca(0, n - 1) ==\
    \ 0);\n            vector<int> parent(n, -1), depth(n), stack{root}, rev(n);\n\
    \            for(int i = 0; i < int(stack.size()); ++i) for(int v : g[stack[i]])\
    \ if(v != parent[stack[i]]) {\n                parent[v] = stack[i]; depth[v]\
    \ = depth[stack[i]] + 1; stack.push_back(v);\n            }\n            for(int\
    \ i = 0; i < n; ++i) rev[hld[i]] = i;\n            for(int u = 0; u < n; ++u)\
    \ {\n                int ancestor = u;\n                for(int k = 0; k <= depth[u]\
    \ + 1; ++k) { assert(hld.la(u, k) == ancestor); if(ancestor != -1) ancestor =\
    \ parent[ancestor]; }\n                vector<int> subtree;\n                hld.subtree_query(u,\
    \ [&](int l, int r) { for(int i = l; i < r; ++i) subtree.push_back(rev[i]); });\n\
    \                sort(subtree.begin(), subtree.end()); vector<int> wanted;\n \
    \               for(int v = 0; v < n; ++v) { int x = v; while(x != -1 && x !=\
    \ u) x = parent[x]; if(x == u) wanted.push_back(v); }\n                assert(subtree\
    \ == wanted);\n                for(int v = 0; v < n; ++v) {\n                \
    \    int x = u, y = v; while(depth[x] > depth[y]) x = parent[x]; while(depth[y]\
    \ > depth[x]) y = parent[y];\n                    while(x != y) { x = parent[x];\
    \ y = parent[y]; }\n                    assert(hld.lca(u, v) == x && lca.get_lca(u,\
    \ v) == x);\n                    assert(hld.dist(u, v) == d[u][v] && lca.get_dist(u,\
    \ v) == d[u][v] && copied.dist(u, v) == d[u][v]);\n                    for(bool\
    \ edge : {false, true}) {\n                        vector<int> actual, expected;\n\
    \                        auto collect = [&](int l, int r) { for(int i = l; i <\
    \ r; ++i) actual.push_back(rev[i]); };\n                        hld.path_query(u,\
    \ v, collect, edge);\n                        for(int z = u; z != x; z = parent[z])\
    \ expected.push_back(z);\n                        for(int z = v; z != x; z = parent[z])\
    \ expected.push_back(z);\n                        if(!edge) expected.push_back(x);\n\
    \                        sort(expected.begin(), expected.end()); sort(actual.begin(),\
    \ actual.end()); assert(actual == expected);\n                        actual.clear();\
    \ hld.path_query(u, v, collect, collect, edge); sort(actual.begin(), actual.end());\
    \ assert(actual == expected);\n                    }\n                }\n    \
    \        }\n        }\n        CentroidDecomposition centroid(g);\n        assert(&centroid.G\
    \ == &g && centroid.parent == vector<int>(n, -1) && centroid.removed == vector<bool>(n,\
    \ false));\n        centroid.get_subtree_size(0, -1); assert(centroid.subtree_size[0]\
    \ == n);\n        centroid.decomp(0, -1); assert(count(centroid.parent.begin(),\
    \ centroid.parent.end(), -1) == 1);\n        for(int u = 0; u < n; ++u) {\n  \
    \          assert(centroid.removed[u]);\n            vector<int> component;\n\
    \            for(int v = 0; v < n; ++v) { int x = v; while(x != -1 && x != u)\
    \ x = centroid.parent[x]; if(x == u) component.push_back(v); }\n            vector<bool>\
    \ present(n); for(int v : component) present[v] = true; present[u] = false;\n\
    \            for(int v : g[u]) if(present[v]) {\n                vector<int> todo{v};\
    \ vector<bool> visited(n); visited[v] = true;\n                for(int i = 0;\
    \ i < int(todo.size()); ++i) for(int w : g[todo[i]]) if(present[w] && !visited[w])\
    \ { visited[w] = true; todo.push_back(w); }\n                assert(todo.size()\
    \ * 2 <= component.size());\n            }\n        }\n        TreeHash<int> first(g),\
    \ relabeled(n);\n        vector<int> permutation(n); iota(permutation.begin(),\
    \ permutation.end(), 0); shuffle(permutation.begin(), permutation.end(), rng);\n\
    \        for(auto [u, v] : edges) relabeled.add_edge(permutation[u], permutation[v]);\n\
    \        assert(first.get_hash() == relabeled.get_hash() && first.get_hash() ==\
    \ first.get_hash());\n    }\n    for(int cycle = 3; cycle <= 8; ++cycle) {\n \
    \       int n = cycle + 15; Namori<int> graph(n); vector<int> attached(n);\n \
    \       for(int i = 0; i < cycle; ++i) { graph.add_undirected_edge(i, (i + 1)\
    \ % cycle); attached[i] = i; }\n        for(int i = cycle; i < n; ++i) { int p\
    \ = rng() % i; graph.add_undirected_edge(i, p); attached[i] = attached[p]; }\n\
    \        assert(graph.size() == unsigned(n)); graph.build();\n        for(int\
    \ i = 0; i < n; ++i) for(int j = 0; j < n; ++j) assert((graph[i] == graph[j])\
    \ == (attached[i] == attached[j]));\n    }\n    INT(a, b); print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/tree/hld.hpp
  - graph/graph_template.hpp
  - graph/tree/lca.hpp
  - graph/tree/diameter.hpp
  - graph/tree/centroid-decomposition.hpp
  - graph/tree/tree-hash.hpp
  - random/rng.hpp
  - graph/namori.hpp
  isVerificationFile: true
  path: test/mytest/graph/tree-api.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:39:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/graph/tree-api.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/graph/tree-api.test.cpp
- /verify/test/mytest/graph/tree-api.test.cpp.html
title: test/mytest/graph/tree-api.test.cpp
---
