---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/add.hpp
    title: data-structure/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/tree/hld.hpp
    title: "HL\u5206\u89E3"
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/library-checker/data-structure/vertex-add-path-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#line\
    \ 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    using namespace std;\n// input output utils\nnamespace siro53_io {\n    // https://maspypy.github.io/library/other/io_old.hpp\n\
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
    \ dim>(s, e);\n}\n#pragma endregion Macros\n#line 2 \"data-structure/monoid/add.hpp\"\
    \n\ntemplate <typename T> struct MonoidAdd {\n    using value_type = T;\n    inline\
    \ static T op(const T &l, const T &r) { return (l + r); }\n    inline static T\
    \ e() { return T(0); }\n};\n#line 2 \"data-structure/segtree/segtree.hpp\"\n\n\
    #line 5 \"data-structure/segtree/segtree.hpp\"\n\ntemplate <class Monoid> class\
    \ Segtree {\n  public:\n    using T = typename Monoid::value_type;\n\n    Segtree()\
    \ : Segtree(0) {}\n    explicit Segtree(int n) : Segtree(std::vector<T>(n, Monoid::e()))\
    \ {}\n    explicit Segtree(const std::vector<T> &v) : N((int)v.size()), sz(1)\
    \ {\n        while(sz < N) sz <<= 1;\n        node.resize(sz * 2, Monoid::e());\n\
    \        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n        for(int i =\
    \ sz - 1; i >= 1; i--) {\n            node[i] = Monoid::op(node[i << 1], node[i\
    \ << 1 | 1]);\n        }\n    }\n    void set(int pos, T val) {\n        assert(0\
    \ <= pos && pos < N);\n        pos += sz;\n        node[pos] = val;\n        while(pos\
    \ > 1) {\n            pos >>= 1;\n            node[pos] = Monoid::op(node[pos\
    \ << 1], node[pos << 1 | 1]);\n        }\n    }\n    T get(int pos) const {\n\
    \        assert(0 <= pos && pos < N);\n        return node[pos + sz];\n    }\n\
    \    void apply(int pos, T val) {\n        this->set(pos, Monoid::op(this->get(pos),\
    \ val));\n    }\n    T prod(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= N);\n        T value_l = Monoid::e(), value_r = Monoid::e();\n\
    \        l += sz;\n        r += sz;\n        while(l < r) {\n            if(l\
    \ & 1) value_l = Monoid::op(value_l, node[l++]);\n            if(r & 1) value_r\
    \ = Monoid::op(node[--r], value_r);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return Monoid::op(value_l, value_r);\n    }\n    T all_prod()\
    \ const { return node[1]; }\n    template <class F> int max_right(int l, F f)\
    \ const {\n        assert(0 <= l && l <= N);\n        assert(f(Monoid::e()));\n\
    \        if(l == N) return N;\n        l += sz;\n        T value_now = Monoid::e();\n\
    \        do {\n            while((l & 1) == 0) l >>= 1;\n            if(!f(Monoid::op(value_now,\
    \ node[l]))) {\n                while(l < sz) {\n                    l = 2 * l;\n\
    \                    if(f(Monoid::op(value_now, node[l]))) {\n               \
    \         value_now = Monoid::op(value_now, node[l]);\n                      \
    \  l++;\n                    }\n                }\n                return (l -\
    \ sz);\n            }\n            value_now = Monoid::op(value_now, node[l]);\n\
    \            l++;\n        } while((l & -l) != l);\n        return N;\n    }\n\
    \    template <class F> int min_left(int r, F f) const {\n        assert(0 <=\
    \ r && r <= N);\n        assert(f(Monoid::e()));\n        if(r == 0) return 0;\n\
    \        r += sz;\n        T value_now = Monoid::e();\n        do {\n        \
    \    r--;\n            while(r > 1 && (r & 1)) r >>= 1;\n            if(!f(Monoid::op(node[r],\
    \ value_now))) {\n                while(r < sz) {\n                    r = 2 *\
    \ r + 1;\n                    if(f(Monoid::op(node[r], value_now))) {\n      \
    \                  value_now = Monoid::op(node[r], value_now);\n             \
    \           r--;\n                    }\n                }\n                return\
    \ ((r + 1) - sz);\n            }\n            value_now = Monoid::op(node[r],\
    \ value_now);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n \
    \ private:\n    int N, sz;\n    std::vector<T> node;\n};\n#line 2 \"graph/tree/hld.hpp\"\
    \n\n#line 4 \"graph/tree/hld.hpp\"\n\n#line 2 \"graph/graph_template.hpp\"\n\n\
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
    \     }\n        out[u] = idx;\n    }\n};\n#line 6 \"test/library-checker/data-structure/vertex-add-path-sum.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n  \
    \  REP(i, N) cin >> a[i];\n    HeavyLightDecomposition hld(N);\n    REP(_, N-1)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        hld.add_edge(u, v);\n\
    \    }\n    hld.build();\n    Segtree<MonoidAdd<ll>> seg(N);\n    REP(i, N) seg.set(hld[i],\
    \ a[i]);\n\n    REP(_, Q) {\n        int type;\n        cin >> type;\n       \
    \ if(type == 0) {\n            int u;\n            ll x;\n            cin >> u\
    \ >> x;\n            seg.set(hld[u], seg.get(hld[u]) + x);\n        } else {\n\
    \            int u, v;\n            cin >> u >> v;\n            ll ans = 0;\n\
    \            auto f = [&](int l, int r) -> void {\n                ans += seg.prod(l,\
    \ r);\n            };\n            hld.path_query<decltype(f)>(u, v, f);\n   \
    \         cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"../../../template/template.cpp\"\n#include \"../../../data-structure/monoid/add.hpp\"\
    \n#include \"../../../data-structure/segtree/segtree.hpp\"\n#include \"../../../graph/tree/hld.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n  \
    \  REP(i, N) cin >> a[i];\n    HeavyLightDecomposition hld(N);\n    REP(_, N-1)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        hld.add_edge(u, v);\n\
    \    }\n    hld.build();\n    Segtree<MonoidAdd<ll>> seg(N);\n    REP(i, N) seg.set(hld[i],\
    \ a[i]);\n\n    REP(_, Q) {\n        int type;\n        cin >> type;\n       \
    \ if(type == 0) {\n            int u;\n            ll x;\n            cin >> u\
    \ >> x;\n            seg.set(hld[u], seg.get(hld[u]) + x);\n        } else {\n\
    \            int u, v;\n            cin >> u >> v;\n            ll ans = 0;\n\
    \            auto f = [&](int l, int r) -> void {\n                ans += seg.prod(l,\
    \ r);\n            };\n            hld.path_query<decltype(f)>(u, v, f);\n   \
    \         cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/monoid/add.hpp
  - data-structure/segtree/segtree.hpp
  - graph/tree/hld.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  requiredBy: []
  timestamp: '2023-12-13 04:53:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/vertex-add-path-sum.test.cpp
- /verify/test/library-checker/data-structure/vertex-add-path-sum.test.cpp.html
title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
---
