---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(SCC)"
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: 2-SAT
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
    \ {}\n    operator int() const { return to; }\n};\n\ntemplate <typename Cost =\
    \ int> class Graph {\n  public:\n    Graph() = default;\n    explicit Graph(int\
    \ N) : N(N), M(0), G(N) {}\n\n    inline void add_directed_edge(int from, int\
    \ to, Cost cost = 1) {\n        assert(0 <= from && from < N);\n        assert(0\
    \ <= to && to < N);\n        G[from].emplace_back(from, to, cost, M++);\n    }\n\
    \n    inline void add_undirected_edge(int from, int to, Cost cost = 1) {\n   \
    \     assert(0 <= from && from < N);\n        assert(0 <= to && to < N);\n   \
    \     G[from].emplace_back(from, to, cost, M);\n        G[to].emplace_back(to,\
    \ from, cost, M++);\n    }\n\n    inline size_t size() const { return G.size();\
    \ }\n    inline std::vector<Edge<Cost>> &operator[](const int &i) { return G[i];\
    \ }\n    inline const std::vector<Edge<Cost>> &operator[](const int &i) const\
    \ {\n        return G[i];\n    }\n\n  protected:\n    int N, M;\n    std::vector<std::vector<Edge<Cost>>>\
    \ G;\n};\n\ntemplate <class Cost = int> using Edges = std::vector<Edge<Cost>>;\n\
    #line 8 \"graph/scc.hpp\"\n\ntemplate <typename Cost = int> class SCC {\n  public:\n\
    \    explicit SCC(int N)\n        : G(N), G_rev(N), comp(N, -1), seen(N, false),\
    \ isBuilt(false) {}\n    explicit SCC(const Graph<Cost> &g)\n        : G(g), G_rev(g.size()),\
    \ comp(g.size(), -1), seen(g.size(), false) {\n        for(int i = 0; i < (int)g.size();\
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
    \n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\n// input\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 4 \"test/library-checker/math/two-sat.test.cpp\"\
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
  timestamp: '2024-09-08 23:17:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/math/two-sat.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/math/two-sat.test.cpp
- /verify/test/library-checker/math/two-sat.test.cpp.html
title: test/library-checker/math/two-sat.test.cpp
---
