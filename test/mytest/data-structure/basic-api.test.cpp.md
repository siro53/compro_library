---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/erasable-priority-queue.hpp
    title: "\u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\
      \u30FC"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/sum_count.hpp
    title: "\u548C\u30FB\u500B\u6570\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/sum2D.hpp
    title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: data-structure/utils/sum_count_manager.hpp
    title: "\u5024\u3054\u3068\u306E\u548C\u30FB\u500B\u6570\u7BA1\u7406"
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
  bundledCode: "#line 1 \"test/mytest/data-structure/basic-api.test.cpp\"\n#define\
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
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"data-structure/BIT.hpp\"\n\
    \n#line 5 \"data-structure/BIT.hpp\"\n\ntemplate <typename T> class BIT {\n  public:\n\
    \    BIT() = default;\n    explicit BIT(int N) : N(N), dat(N + 1, 0) {}\n    T\
    \ sum(int r) {\n        T ret = 0;\n        for(; r >= 1; r -= lsb(r)) ret +=\
    \ dat[r];\n        return ret;\n    }\n    T sum(int l, int r) {\n        assert(l\
    \ <= r);\n        if(l == r) return T(0);\n        return (sum(r) - sum(l));\n\
    \    }\n    void add(int pos, T val) {\n        for(int i = pos + 1; i <= N; i\
    \ += lsb(i)) dat[i] += val;\n    }\n    int lower_bound(T val) {\n        int\
    \ pos = 0;\n        int k = 1;\n        while(2 * k <= N) k <<= 1;\n        for(;\
    \ k >= 1; k >>= 1) {\n            if(pos + k <= N and dat[pos + k] < val) {\n\
    \                pos += k;\n                val -= dat[pos];\n            }\n\
    \        }\n        return pos + 1;\n    }\n\n  private:\n    int N;\n    std::vector<T>\
    \ dat;\n\n    inline int lsb(int i) { return i & (-i); }\n};\n#line 2 \"data-structure/sum2D.hpp\"\
    \n\n#line 5 \"data-structure/sum2D.hpp\"\n\ntemplate <typename T> class sum2D\
    \ {\n  public:\n    sum2D() = default;\n    explicit sum2D(int height, int width)\n\
    \        : sum(height + 1, std::vector<T>(width + 1, 0)), isBuilt(false) {}\n\
    \    void add(int row, int column, T val) {\n        assert(0 <= row + 1 && row\
    \ + 1 < (int)sum.size());\n        assert(0 <= column + 1 && column + 1 < (int)sum[0].size());\n\
    \        sum[row + 1][column + 1] += val;\n    }\n    void build() {\n       \
    \ for(int i = 1; i < (int)sum.size(); i++) {\n            for(int j = 1; j < (int)sum[0].size();\
    \ j++) {\n                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i -\
    \ 1][j - 1];\n            }\n        }\n        isBuilt = true;\n    }\n    T\
    \ get_sum(int row_l, int row_r, int column_l, int column_r) const {\n        assert(row_l\
    \ <= row_r);\n        assert(column_l <= column_r);\n        assert(isBuilt);\n\
    \        return (sum[row_r][column_r] - sum[row_l][column_r] -\n             \
    \   sum[row_r][column_l] + sum[row_l][column_l]);\n    }\n\n  private:\n    std::vector<std::vector<T>>\
    \ sum;\n    bool isBuilt;\n};\n#line 2 \"data-structure/unionfind.hpp\"\n\n#line\
    \ 7 \"data-structure/unionfind.hpp\"\n\nclass UnionFind {\n  public:\n    UnionFind()\
    \ = default;\n    explicit UnionFind(int n) : N(n), parent_or_size(n, -1) {}\n\
    \    int leader(int u) {\n        assert(0 <= u && u < N);\n        if(parent_or_size[u]\
    \ < 0) return u;\n        return (parent_or_size[u] = leader(parent_or_size[u]));\n\
    \    }\n    bool same(int u, int v) { return (leader(u) == leader(v)); }\n   \
    \ bool merge(int u, int v) {\n        u = leader(u);\n        v = leader(v);\n\
    \        if(u == v) return false;\n        if(-parent_or_size[u] < -parent_or_size[v])\
    \ std::swap(u, v);\n        parent_or_size[u] += parent_or_size[v];\n        parent_or_size[v]\
    \ = u;\n        return true;\n    }\n    int size(int u) { return (-parent_or_size[leader(u)]);\
    \ }\n    std::vector<std::vector<int>> groups() {\n        std::vector<int> leaders(N),\
    \ group_size(N, 0);\n        for(int i = 0; i < N; i++) {\n            leaders[i]\
    \ = leader(i);\n            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ g(N);\n        for(int i = 0; i < N; i++) g[i].reserve(group_size[i]);\n   \
    \     for(int i = 0; i < N; i++) g[leaders[i]].push_back(i);\n        g.erase(std::remove_if(\n\
    \                    g.begin(), g.end(),\n                    [&](const std::vector<int>\
    \ &v) { return v.empty(); }),\n                g.end());\n        return g;\n\
    \    }\n    std::map<int, std::vector<int>> groups_with_map() {\n        std::map<int,\
    \ std::vector<int>> g;\n        for(int i = 0; i < N; i++) {\n            int\
    \ l = leader(i);\n            g[l].push_back(i);\n        }\n        return g;\n\
    \    }\n\n  private:\n    int N;\n    std::vector<int> parent_or_size;\n};\n#line\
    \ 2 \"data-structure/erasable-priority-queue.hpp\"\n\n#line 5 \"data-structure/erasable-priority-queue.hpp\"\
    \n#include <type_traits>\n#line 8 \"data-structure/erasable-priority-queue.hpp\"\
    \n\ntemplate<class T, bool isAscending = true>\nstruct ErasablePriorityQueue {\n\
    \    using PQ = std::conditional_t<\n        isAscending,\n        std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>,\n        std::priority_queue<T>\n    >;\n\
    \    PQ que, rm_que;\n\n    ErasablePriorityQueue() = default;\n\n    void push(const\
    \ T& val) {\n        que.emplace(val);\n    }\n\n    T top() {\n        normalize();\n\
    \        assert(!que.empty());\n        return que.top();\n    }\n\n    void pop()\
    \ {\n        normalize();\n        assert(!que.empty());\n        que.pop();\n\
    \    }\n\n    void erase(const T& val) {\n        rm_que.emplace(val);\n    }\n\
    \n    bool empty() {\n        normalize();\n        return que.empty();\n    }\n\
    private:\n    void normalize() {\n        while(!que.empty() and !rm_que.empty()\
    \ and que.top() == rm_que.top()) {\n            que.pop();\n            rm_que.pop();\n\
    \        }\n    }\n};\n#line 2 \"data-structure/utils/sum_count_manager.hpp\"\n\
    \n#line 5 \"data-structure/utils/sum_count_manager.hpp\"\n\n#line 2 \"misc/compress.hpp\"\
    \n\n#line 5 \"misc/compress.hpp\"\n\ntemplate <typename T> class Compress {\n\
    \  public:\n    Compress() = default;\n    explicit Compress(const std::vector<T>\
    \ &v) : dat(v) {\n        build();\n    }\n    void push_back(T val) { dat.push_back(val);\
    \ }\n\tvoid build() {\n\t\tstd::sort(dat.begin(), dat.end());\n        dat.erase(std::unique(dat.begin(),\
    \ dat.end()), dat.end());\n\t}\n    int get(T val) const {\n        int pos =\
    \ std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();\n        return\
    \ pos;\n    }\n    T operator[](int i) const { return dat[i]; }\n    size_t size()\
    \ const { return dat.size(); }\n\n  private:\n    std::vector<T> dat;\n};\n#line\
    \ 2 \"data-structure/segtree/segtree.hpp\"\n\n#line 5 \"data-structure/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid> class Segtree {\n  public:\n    using T = typename\
    \ Monoid::value_type;\n\n    Segtree() : Segtree(0) {}\n    explicit Segtree(int\
    \ n) : Segtree(std::vector<T>(n, Monoid::e())) {}\n    explicit Segtree(const\
    \ std::vector<T> &v) : N((int)v.size()), sz(1) {\n        while(sz < N) sz <<=\
    \ 1;\n        node.resize(sz * 2, Monoid::e());\n        for(int i = 0; i < N;\
    \ i++) node[i + sz] = v[i];\n        for(int i = sz - 1; i >= 1; i--) {\n    \
    \        node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);\n        }\n  \
    \  }\n    void set(int pos, T val) {\n        assert(0 <= pos && pos < N);\n \
    \       pos += sz;\n        node[pos] = val;\n        while(pos > 1) {\n     \
    \       pos >>= 1;\n            node[pos] = Monoid::op(node[pos << 1], node[pos\
    \ << 1 | 1]);\n        }\n    }\n    T get(int pos) const {\n        assert(0\
    \ <= pos && pos < N);\n        return node[pos + sz];\n    }\n    void apply(int\
    \ pos, T val) {\n        this->set(pos, Monoid::op(this->get(pos), val));\n  \
    \  }\n    T prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=\
    \ N);\n        T value_l = Monoid::e(), value_r = Monoid::e();\n        l += sz;\n\
    \        r += sz;\n        while(l < r) {\n            if(l & 1) value_l = Monoid::op(value_l,\
    \ node[l++]);\n            if(r & 1) value_r = Monoid::op(node[--r], value_r);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(value_l,\
    \ value_r);\n    }\n    T all_prod() const { return node[1]; }\n    template <class\
    \ F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= N);\n  \
    \      assert(f(Monoid::e()));\n        if(l == N) return N;\n        l += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            while((l & 1) ==\
    \ 0) l >>= 1;\n            if(!f(Monoid::op(value_now, node[l]))) {\n        \
    \        while(l < sz) {\n                    l = 2 * l;\n                   \
    \ if(f(Monoid::op(value_now, node[l]))) {\n                        value_now =\
    \ Monoid::op(value_now, node[l]);\n                        l++;\n            \
    \        }\n                }\n                return (l - sz);\n            }\n\
    \            value_now = Monoid::op(value_now, node[l]);\n            l++;\n \
    \       } while((l & -l) != l);\n        return N;\n    }\n    template <class\
    \ F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= N);\n   \
    \     assert(f(Monoid::e()));\n        if(r == 0) return 0;\n        r += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            r--;\n        \
    \    while(r > 1 && (r & 1)) r >>= 1;\n            if(!f(Monoid::op(node[r], value_now)))\
    \ {\n                while(r < sz) {\n                    r = 2 * r + 1;\n   \
    \                 if(f(Monoid::op(node[r], value_now))) {\n                  \
    \      value_now = Monoid::op(node[r], value_now);\n                        r--;\n\
    \                    }\n                }\n                return ((r + 1) - sz);\n\
    \            }\n            value_now = Monoid::op(node[r], value_now);\n    \
    \    } while((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int\
    \ N, sz;\n    std::vector<T> node;\n};\n#line 2 \"data-structure/monoid/sum_count.hpp\"\
    \n\ntemplate <typename sum_t, typename count_t> struct MonoidSumCount {\n    struct\
    \ S {\n        sum_t sum;\n        count_t cnt;\n        S() = default;\n    \
    \    S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type\
    \ = S;\n    inline static S op(const S& l, const S& r) {\n        return S(l.sum\
    \ + r.sum, l.cnt + r.cnt);\n    }\n    inline static S e() { return S(sum_t(0),\
    \ count_t(0)); }\n};\n#line 9 \"data-structure/utils/sum_count_manager.hpp\"\n\
    \ntemplate<typename T>\nstruct SumCountManager {\n    using S = typename MonoidSumCount<T,\
    \ int>::S;\n    Segtree<MonoidSumCount<T, int>> seg;\n    Compress<T> comp;\n\n\
    \    SumCountManager() = default;\n    SumCountManager(std::vector<T> xs) {\n\
    \        comp = Compress<T>(xs);\n        seg = Segtree<MonoidSumCount<T, int>>((int)comp.size());\n\
    \    }\n\n    void add(T val) {\n        int pos = comp.get(val);\n        assert(pos\
    \ < (int)comp.size() && comp[pos] == val);\n        auto x = seg.get(pos);\n \
    \       seg.set(pos, S(x.sum + val, x.cnt + 1));\n    }\n\n    int get(T val)\
    \ const {\n        return comp.get(val);\n    }\n};\n#line 8 \"test/mytest/data-structure/basic-api.test.cpp\"\
    \n\n\nint main() {\n    BIT<ll> bit; bit = BIT<ll>(8);\n    vector<ll> a{0, 2,\
    \ 0, 5, 1, 0, 3, 0};\n    for(int i = 0; i < 8; ++i) bit.add(i, a[i]);\n    for(int\
    \ l = 0; l <= 8; ++l) for(int r = l; r <= 8; ++r) assert(bit.sum(l, r) == accumulate(a.begin()\
    \ + l, a.begin() + r, 0LL));\n    for(int r = 0; r <= 8; ++r) assert(bit.sum(r)\
    \ == accumulate(a.begin(), a.begin() + r, 0LL));\n    for(ll x = 1; x <= 12; ++x)\
    \ {\n        int r = 1; while(r <= 8 && accumulate(a.begin(), a.begin() + r, 0LL)\
    \ < x) ++r;\n        assert(bit.lower_bound(x) == r);\n    }\n    BIT<ll> empty(0);\
    \ assert(empty.sum(0) == 0 && empty.sum(0, 0) == 0 && empty.lower_bound(1) ==\
    \ 1);\n    sum2D<ll> grid; grid = sum2D<ll>(4, 5);\n    for(int i = 0; i < 4;\
    \ ++i) for(int j = 0; j < 5; ++j) { grid.add(i, j, i - j); grid.add(i, j, 1);\
    \ }\n    grid.build(); const auto& cg = grid;\n    for(int l = 0; l <= 4; ++l)\
    \ for(int r = l; r <= 4; ++r) for(int b = 0; b <= 5; ++b) for(int e = b; e <=\
    \ 5; ++e) {\n        ll expected = 0;\n        for(int i = l; i < r; ++i) for(int\
    \ j = b; j < e; ++j) expected += i - j + 1;\n        assert(cg.get_sum(l, r, b,\
    \ e) == expected);\n    }\n    sum2D<ll> zero(0, 0); zero.build(); assert(zero.get_sum(0,\
    \ 0, 0, 0) == 0);\n    UnionFind uf; uf = UnionFind(8); vector<int> label(8);\
    \ iota(label.begin(), label.end(), 0);\n    mt19937 rng(63);\n    for(int t =\
    \ 0; t < 30; ++t) {\n        int u = rng() % 8, v = rng() % 8, before = label[u],\
    \ after = label[v];\n        assert(uf.merge(u, v) == (before != after));\n  \
    \      for(int& x : label) if(x == before) x = after;\n        vector<vector<int>>\
    \ expected;\n        for(int id = 0; id < 8; ++id) {\n            vector<int>\
    \ group; for(int i = 0; i < 8; ++i) if(label[i] == id) group.push_back(i);\n \
    \           if(!group.empty()) expected.push_back(group);\n        }\n       \
    \ auto groups = uf.groups(); sort(groups.begin(), groups.end()); sort(expected.begin(),\
    \ expected.end());\n        assert(groups == expected);\n        vector<vector<int>>\
    \ mapped;\n        for(auto [leader, group] : uf.groups_with_map()) {\n      \
    \      for(int x : group) assert(uf.leader(x) == leader);\n            mapped.push_back(group);\n\
    \        }\n        sort(mapped.begin(), mapped.end()); assert(mapped == expected);\n\
    \        for(int i = 0; i < 8; ++i) {\n            assert(uf.size(i) == count(label.begin(),\
    \ label.end(), label[i]));\n            for(int j = 0; j < 8; ++j) assert(uf.same(i,\
    \ j) == (label[i] == label[j]));\n        }\n    }\n    UnionFind none(0); assert(none.groups().empty()\
    \ && none.groups_with_map().empty());\n    ErasablePriorityQueue<int> queue; multiset<int>\
    \ reference;\n    for(int t = 0; t < 500; ++t) {\n        if(reference.empty()\
    \ || rng() % 3 == 0) { int x = rng() % 20; queue.push(x); reference.insert(x);\
    \ }\n        else if(rng() % 2) { auto it = next(reference.begin(), rng() % reference.size());\
    \ queue.erase(*it); reference.erase(it); }\n        else { assert(queue.top()\
    \ == *reference.begin()); queue.pop(); reference.erase(reference.begin()); }\n\
    \        assert(queue.empty() == reference.empty());\n        if(!reference.empty())\
    \ assert(queue.top() == *reference.begin());\n    }\n    SumCountManager<ll> manager;\
    \ manager = SumCountManager<ll>({5, -2, 5, 9});\n    const auto& cm = manager;\n\
    \    assert(cm.get(-3) == 0 && cm.get(0) == 1 && cm.get(10) == 3 && manager.comp.size()\
    \ == 3);\n    manager.add(-2); manager.add(-2); manager.add(9);\n    assert(manager.seg.get(0).sum\
    \ == -4 && manager.seg.get(0).cnt == 2);\n    assert(manager.seg.all_prod().sum\
    \ == 5 && manager.seg.all_prod().cnt == 3);\n    INT(a0, b0); print(a0 + b0);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../data-structure/BIT.hpp\"\n#include \"../../../data-structure/sum2D.hpp\"\
    \n#include \"../../../data-structure/unionfind.hpp\"\n#include \"../../../data-structure/erasable-priority-queue.hpp\"\
    \n#include \"../../../data-structure/utils/sum_count_manager.hpp\"\n\n\nint main()\
    \ {\n    BIT<ll> bit; bit = BIT<ll>(8);\n    vector<ll> a{0, 2, 0, 5, 1, 0, 3,\
    \ 0};\n    for(int i = 0; i < 8; ++i) bit.add(i, a[i]);\n    for(int l = 0; l\
    \ <= 8; ++l) for(int r = l; r <= 8; ++r) assert(bit.sum(l, r) == accumulate(a.begin()\
    \ + l, a.begin() + r, 0LL));\n    for(int r = 0; r <= 8; ++r) assert(bit.sum(r)\
    \ == accumulate(a.begin(), a.begin() + r, 0LL));\n    for(ll x = 1; x <= 12; ++x)\
    \ {\n        int r = 1; while(r <= 8 && accumulate(a.begin(), a.begin() + r, 0LL)\
    \ < x) ++r;\n        assert(bit.lower_bound(x) == r);\n    }\n    BIT<ll> empty(0);\
    \ assert(empty.sum(0) == 0 && empty.sum(0, 0) == 0 && empty.lower_bound(1) ==\
    \ 1);\n    sum2D<ll> grid; grid = sum2D<ll>(4, 5);\n    for(int i = 0; i < 4;\
    \ ++i) for(int j = 0; j < 5; ++j) { grid.add(i, j, i - j); grid.add(i, j, 1);\
    \ }\n    grid.build(); const auto& cg = grid;\n    for(int l = 0; l <= 4; ++l)\
    \ for(int r = l; r <= 4; ++r) for(int b = 0; b <= 5; ++b) for(int e = b; e <=\
    \ 5; ++e) {\n        ll expected = 0;\n        for(int i = l; i < r; ++i) for(int\
    \ j = b; j < e; ++j) expected += i - j + 1;\n        assert(cg.get_sum(l, r, b,\
    \ e) == expected);\n    }\n    sum2D<ll> zero(0, 0); zero.build(); assert(zero.get_sum(0,\
    \ 0, 0, 0) == 0);\n    UnionFind uf; uf = UnionFind(8); vector<int> label(8);\
    \ iota(label.begin(), label.end(), 0);\n    mt19937 rng(63);\n    for(int t =\
    \ 0; t < 30; ++t) {\n        int u = rng() % 8, v = rng() % 8, before = label[u],\
    \ after = label[v];\n        assert(uf.merge(u, v) == (before != after));\n  \
    \      for(int& x : label) if(x == before) x = after;\n        vector<vector<int>>\
    \ expected;\n        for(int id = 0; id < 8; ++id) {\n            vector<int>\
    \ group; for(int i = 0; i < 8; ++i) if(label[i] == id) group.push_back(i);\n \
    \           if(!group.empty()) expected.push_back(group);\n        }\n       \
    \ auto groups = uf.groups(); sort(groups.begin(), groups.end()); sort(expected.begin(),\
    \ expected.end());\n        assert(groups == expected);\n        vector<vector<int>>\
    \ mapped;\n        for(auto [leader, group] : uf.groups_with_map()) {\n      \
    \      for(int x : group) assert(uf.leader(x) == leader);\n            mapped.push_back(group);\n\
    \        }\n        sort(mapped.begin(), mapped.end()); assert(mapped == expected);\n\
    \        for(int i = 0; i < 8; ++i) {\n            assert(uf.size(i) == count(label.begin(),\
    \ label.end(), label[i]));\n            for(int j = 0; j < 8; ++j) assert(uf.same(i,\
    \ j) == (label[i] == label[j]));\n        }\n    }\n    UnionFind none(0); assert(none.groups().empty()\
    \ && none.groups_with_map().empty());\n    ErasablePriorityQueue<int> queue; multiset<int>\
    \ reference;\n    for(int t = 0; t < 500; ++t) {\n        if(reference.empty()\
    \ || rng() % 3 == 0) { int x = rng() % 20; queue.push(x); reference.insert(x);\
    \ }\n        else if(rng() % 2) { auto it = next(reference.begin(), rng() % reference.size());\
    \ queue.erase(*it); reference.erase(it); }\n        else { assert(queue.top()\
    \ == *reference.begin()); queue.pop(); reference.erase(reference.begin()); }\n\
    \        assert(queue.empty() == reference.empty());\n        if(!reference.empty())\
    \ assert(queue.top() == *reference.begin());\n    }\n    SumCountManager<ll> manager;\
    \ manager = SumCountManager<ll>({5, -2, 5, 9});\n    const auto& cm = manager;\n\
    \    assert(cm.get(-3) == 0 && cm.get(0) == 1 && cm.get(10) == 3 && manager.comp.size()\
    \ == 3);\n    manager.add(-2); manager.add(-2); manager.add(9);\n    assert(manager.seg.get(0).sum\
    \ == -4 && manager.seg.get(0).cnt == 2);\n    assert(manager.seg.all_prod().sum\
    \ == 5 && manager.seg.all_prod().cnt == 3);\n    INT(a0, b0); print(a0 + b0);\n\
    }\n"
  dependsOn:
  - template/template.cpp
  - data-structure/BIT.hpp
  - data-structure/sum2D.hpp
  - data-structure/unionfind.hpp
  - data-structure/erasable-priority-queue.hpp
  - data-structure/utils/sum_count_manager.hpp
  - misc/compress.hpp
  - data-structure/segtree/segtree.hpp
  - data-structure/monoid/sum_count.hpp
  isVerificationFile: true
  path: test/mytest/data-structure/basic-api.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:39:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/data-structure/basic-api.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/data-structure/basic-api.test.cpp
- /verify/test/mytest/data-structure/basic-api.test.cpp.html
title: test/mytest/data-structure/basic-api.test.cpp
---
