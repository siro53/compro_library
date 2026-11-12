---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: random/gen/random.hpp
    title: "\u30C6\u30B9\u30C8\u751F\u6210\u7528\u306E\u4E71\u6570 (Random)"
  - icon: ':heavy_check_mark:'
    path: random/gen/sequence.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6570\u5217\u30FB\u9806\u5217\u30FB\u90E8\
      \u5206\u96C6\u5408\u30FB\u533A\u9593"
  - icon: ':heavy_check_mark:'
    path: random/gen/tree.hpp
    title: "\u30E9\u30F3\u30C0\u30E0\u306A\u6728"
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
  bundledCode: "#line 1 \"test/mytest/random/gen/tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
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
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"data-structure/unionfind.hpp\"\
    \n\n#line 7 \"data-structure/unionfind.hpp\"\n\nclass UnionFind {\n  public:\n\
    \    UnionFind() = default;\n    explicit UnionFind(int n) : N(n), parent_or_size(n,\
    \ -1) {}\n    int leader(int u) {\n        assert(0 <= u && u < N);\n        if(parent_or_size[u]\
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
    \ 2 \"random/gen/tree.hpp\"\n\n#line 6 \"random/gen/tree.hpp\"\n\n#line 2 \"random/gen/random.hpp\"\
    \n\n#line 11 \"random/gen/random.hpp\"\n#include <type_traits>\n#line 14 \"random/gen/random.hpp\"\
    \n\n// seed \u3092\u6307\u5B9A\u3067\u304D\u308B\u3001\u30E9\u30F3\u30C0\u30E0\
    \u30C6\u30B9\u30C8\u306E\u5165\u529B\u751F\u6210\u7528\u306E\u4E71\u6570\nclass\
    \ Random {\n  public:\n    explicit Random(std::uint64_t seed = 0) : mt(seed)\
    \ {}\n    // argv[1] \u3092 seed \u3068\u3057\u3066\u8AAD\u3080\u3002\u5F15\u6570\
    \u304C\u306A\u3051\u308C\u3070 seed = 0\n    Random(int argc, char **argv) : mt(parse_seed(argc,\
    \ argv)) {}\n\n    // [0, n) \u306E\u4E00\u69D8\u306A\u6574\u6570 (n > 0)\n  \
    \  std::uint64_t uniform(std::uint64_t n) {\n        assert(n > 0);\n        //\
    \ 2^64 mod n \u500B\u306E\u5024\u3092\u68C4\u5374\u3057\u3066\u5270\u4F59\u306E\
    \u504F\u308A\u3092\u306A\u304F\u3059\n        const std::uint64_t threshold =\
    \ (0 - n) % n;\n        std::uint64_t x = mt();\n        while(x < threshold)\
    \ x = mt();\n        return x % n;\n    }\n\n    // [l, r) \u306E\u4E00\u69D8\u306A\
    \u6574\u6570\n    template <class T, class U>\n    std::common_type_t<T, U, int>\
    \ randint(T l, U r) {\n        using C = std::common_type_t<T, U, int>;\n    \
    \    static_assert(std::is_integral<C>::value, \"randint requires integers\");\n\
    \        const C lo = C(l), hi = C(r);\n        assert(lo < hi);\n        using\
    \ UC = std::make_unsigned_t<C>;\n        const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n        return C(UC(lo) + UC(uniform(width)));\n    }\n    // [0,\
    \ r) \u306E\u4E00\u69D8\u306A\u6574\u6570\n    template <class T> std::common_type_t<T,\
    \ int> randint(T r) {\n        return randint(T(0), r);\n    }\n\n    // [l, r)\
    \ \u306B\u542B\u307E\u308C\u308B\u5076\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\
    \u3076 (\u5076\u6570\u304C 1 \u3064\u4EE5\u4E0A\u3042\u308B\u3053\u3068)\n   \
    \ template <class T, class U>\n    std::common_type_t<T, U, int> even(T l, U r)\
    \ {\n        return with_parity(l, r, 0);\n    }\n    // [0, r) \u306B\u542B\u307E\
    \u308C\u308B\u5076\u6570\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076\n    template\
    \ <class T> std::common_type_t<T, int> even(T r) {\n        return even(T(0),\
    \ r);\n    }\n\n    // [l, r) \u306B\u542B\u307E\u308C\u308B\u5947\u6570\u304B\
    \u3089\u4E00\u69D8\u306B\u9078\u3076 (\u5947\u6570\u304C 1 \u3064\u4EE5\u4E0A\u3042\
    \u308B\u3053\u3068)\n    template <class T, class U>\n    std::common_type_t<T,\
    \ U, int> odd(T l, U r) {\n        return with_parity(l, r, 1);\n    }\n    //\
    \ [0, r) \u306B\u542B\u307E\u308C\u308B\u5947\u6570\u304B\u3089\u4E00\u69D8\u306B\
    \u9078\u3076\n    template <class T> std::common_type_t<T, int> odd(T r) {\n \
    \       return odd(T(0), r);\n    }\n\n    // [l, r) \u306E\u5B9F\u6570 (53 bit\
    \ \u306E\u5206\u89E3\u80FD)\n    double real(double l, double r) {\n        assert(l\
    \ < r);\n        const double u = double(mt() >> 11) / double(std::uint64_t(1)\
    \ << 53);\n        const double x = l + (r - l) * u;\n        return x < r ? x\
    \ : std::nextafter(r, l);\n    }\n    double real() { return real(0.0, 1.0); }\n\
    \n    // \u78BA\u7387 p \u3067 true\n    bool coin(double p = 0.5) { return real()\
    \ < p; }\n\n    // \u5C0F\u3055\u3044\u5024\u306B\u504F\u3089\u305B\u305F [l,\
    \ r) \u306E\u6574\u6570\n    // 2 \u51AA\u306E\u30B9\u30B1\u30FC\u30EB 1, 2, 4,\
    \ ... \u3092\u7B49\u78BA\u7387\u3067\u9078\u3073\u3001\u305D\u306E\u7BC4\u56F2\
    \u3067\u4E00\u69D8\u306B\u9078\u3076\n    template <class T, class U>\n    std::common_type_t<T,\
    \ U, int> size(T l, U r) {\n        using C = std::common_type_t<T, U, int>;\n\
    \        const C lo = C(l), hi = C(r);\n        assert(lo < hi);\n        using\
    \ UC = std::make_unsigned_t<C>;\n        const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n        int scales = 0;\n        while(scales < 64 && (std::uint64_t(1)\
    \ << scales) < width) scales++;\n        const int k = int(uniform(std::uint64_t(scales\
    \ + 1)));\n        const std::uint64_t w = k >= 64 ? width : std::min(width, std::uint64_t(1)\
    \ << k);\n        return C(UC(lo) + UC(uniform(w)));\n    }\n\n    // v \u306E\
    \u8981\u7D20\u3092\u4E00\u69D8\u306B 1 \u3064\u9078\u3076 (v \u306F\u7A7A\u3067\
    \u306A\u3044)\n    template <class T> const T &choice(const std::vector<T> &v)\
    \ {\n        assert(!v.empty());\n        return v[uniform(v.size())];\n    }\n\
    \n    // Fisher-Yates \u3067 v \u3092\u4E00\u69D8\u306B\u30B7\u30E3\u30C3\u30D5\
    \u30EB\u3059\u308B\n    template <class T> void shuffle(std::vector<T> &v) {\n\
    \        for(std::size_t i = v.size(); i > 1; i--) {\n            std::swap(v[i\
    \ - 1], v[uniform(i)]);\n        }\n    }\n\n    // \u6A19\u6E96\u306E\u5206\u5E03\
    \u3068\u7D44\u307F\u5408\u308F\u305B\u308B\u5834\u5408\u306E\u30A8\u30F3\u30B8\
    \u30F3\n    std::mt19937_64 &engine() { return mt; }\n\n  private:\n    std::mt19937_64\
    \ mt;\n\n    // [l, r) \u306E\u3046\u3061 2 \u3067\u5272\u3063\u305F\u4F59\u308A\
    \u304C parity (\u8CA0\u306E\u6570\u3082\u542B\u3081\u3066\u6570\u5B66\u7684\u306A\
    \u5076\u5947) \u306E\u5024\u304B\u3089\u4E00\u69D8\u306B\u9078\u3076\n    template\
    \ <class T, class U>\n    std::common_type_t<T, U, int> with_parity(T l, U r,\
    \ unsigned parity) {\n        using C = std::common_type_t<T, U, int>;\n     \
    \   static_assert(std::is_integral<C>::value, \"even/odd requires integers\");\n\
    \        using UC = std::make_unsigned_t<C>;\n        const C lo = C(l), hi =\
    \ C(r);\n        assert(lo < hi);\n        const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n        // 2 \u306E\u88DC\u6570\u8868\u73FE\u3067\u306F UC \u3078\
    \u306E\u5909\u63DB\u3067\u5076\u5947\u304C\u4FDD\u305F\u308C\u308B\n        const\
    \ std::uint64_t first = (std::uint64_t(UC(lo)) & 1) == parity ? 0 : 1;\n     \
    \   assert(first < width && \"no integer of the requested parity in [l, r)\");\n\
    \        // first, first + 2, ... < width \u306E\u500B\u6570 (width - first +\
    \ 1 \u306E\u3042\u3075\u308C\u3092\u907F\u3051\u308B)\n        const std::uint64_t\
    \ count = (width - first - 1) / 2 + 1;\n        return C(UC(lo) + UC(first + 2\
    \ * uniform(count)));\n    }\n\n    static std::uint64_t parse_seed(int argc,\
    \ char **argv) {\n        if(argc < 2) return 0;\n        const char *s = argv[1];\n\
    \        char *end = nullptr;\n        errno = 0;\n        const unsigned long\
    \ long seed = std::strtoull(s, &end, 10);\n        if(*s == '\\0' || *s == '-'\
    \ || *end != '\\0' || errno == ERANGE) {\n            std::cerr << \"Random: invalid\
    \ seed '\" << s << \"'\\n\";\n            std::exit(2);\n        }\n        return\
    \ seed;\n    }\n};\n#line 2 \"random/gen/sequence.hpp\"\n\n#line 11 \"random/gen/sequence.hpp\"\
    \n\n#line 13 \"random/gen/sequence.hpp\"\n\n// \u5404\u8981\u7D20\u304C [l, r)\
    \ \u306E\u4E00\u69D8\u4E71\u6570\u3067\u3042\u308B\u9577\u3055 n \u306E\u6570\u5217\
    \ntemplate <class T, class U>\nstd::vector<std::common_type_t<T, U, int>> random_vector(Random\
    \ &rng, int n,\n                                                         T l,\
    \ U r) {\n    assert(n >= 0);\n    std::vector<std::common_type_t<T, U, int>>\
    \ v(n);\n    for(auto &x : v) x = rng.randint(l, r);\n    return v;\n}\n\n// [l,\
    \ r) \u304B\u3089\u76F8\u7570\u306A\u308B n \u500B\u3092\u4E00\u69D8\u306B\u9078\
    \u3073\u3001\u30E9\u30F3\u30C0\u30E0\u306A\u9806\u306B\u4E26\u3079\u305F\u6570\
    \u5217\n// (Floyd \u306E\u30B5\u30F3\u30D7\u30EA\u30F3\u30B0)\ntemplate <class\
    \ T, class U>\nstd::vector<std::common_type_t<T, U, int>>\nrandom_distinct_vector(Random\
    \ &rng, int n, T l, U r) {\n    using C = std::common_type_t<T, U, int>;\n   \
    \ using UC = std::make_unsigned_t<C>;\n    const C lo = C(l), hi = C(r);\n   \
    \ assert(n >= 0 && lo <= hi);\n    const std::uint64_t width = std::uint64_t(UC(hi)\
    \ - UC(lo));\n    assert(std::uint64_t(n) <= width);\n    std::unordered_set<std::uint64_t>\
    \ used;\n    used.reserve(std::size_t(n) * 2);\n    std::vector<C> v;\n    v.reserve(n);\n\
    \    for(std::uint64_t j = width - std::uint64_t(n); j < width; j++) {\n     \
    \   std::uint64_t t = rng.uniform(j + 1);\n        if(used.count(t)) t = j;\n\
    \        used.insert(t);\n        v.push_back(C(UC(lo) + UC(t)));\n    }\n   \
    \ rng.shuffle(v);\n    return v;\n}\n\n// (0, 1, ..., n-1) \u306E\u4E00\u69D8\u30E9\
    \u30F3\u30C0\u30E0\u306A\u9806\u5217\ninline std::vector<int> random_permutation(Random\
    \ &rng, int n) {\n    assert(n >= 0);\n    std::vector<int> p(n);\n    std::iota(p.begin(),\
    \ p.end(), 0);\n    rng.shuffle(p);\n    return p;\n}\n\n// {0, 1, ..., n-1} \u306E\
    \u5927\u304D\u3055 k \u306E\u90E8\u5206\u96C6\u5408\u3092\u4E00\u69D8\u306B\u9078\
    \u3073\u3001\u6607\u9806\u3067\u8FD4\u3059\ninline std::vector<int> random_subset(Random\
    \ &rng, int n, int k) {\n    assert(0 <= k && k <= n);\n    std::vector<int> s\
    \ = random_distinct_vector(rng, k, 0, n);\n    std::sort(s.begin(), s.end());\n\
    \    return s;\n}\n\n// l <= a < b <= r \u3092\u6E80\u305F\u3059\u534A\u958B\u533A\
    \u9593 [a, b) \u3092\u4E00\u69D8\u306B\u9078\u3076\ntemplate <class T, class U>\n\
    std::pair<std::common_type_t<T, U, int>, std::common_type_t<T, U, int>>\nrandom_interval(Random\
    \ &rng, T l, U r) {\n    using C = std::common_type_t<T, U, int>;\n    const C\
    \ lo = C(l), hi = C(r);\n    assert(lo < hi);\n    // {lo, ..., hi} \u304B\u3089\
    \u76F8\u7570\u306A\u308B 2 \u70B9\u3092\u9078\u3076\n    std::vector<C> e = random_distinct_vector(rng,\
    \ 2, lo, C(hi + 1));\n    if(e[0] > e[1]) std::swap(e[0], e[1]);\n    return {e[0],\
    \ e[1]};\n}\n#line 9 \"random/gen/tree.hpp\"\n\n// \u9802\u70B9\u756A\u53F7\u3092\
    \u4E00\u69D8\u30E9\u30F3\u30C0\u30E0\u306B\u4ED8\u3051\u66FF\u3048\u3001\u5404\
    \u8FBA\u306E\u5411\u304D\u3068\u8FBA\u306E\u9806\u5E8F\u3092\u30B7\u30E3\u30C3\
    \u30D5\u30EB\u3059\u308B\ninline std::vector<std::pair<int, int>>\nrelabel_edges(Random\
    \ &rng, int n, std::vector<std::pair<int, int>> edges) {\n    const std::vector<int>\
    \ p = random_permutation(rng, n);\n    for(auto &[u, v] : edges) {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n);\n        u = p[u], v = p[v];\n        if(rng.coin())\
    \ std::swap(u, v);\n    }\n    rng.shuffle(edges);\n    return edges;\n}\n\n//\
    \ n \u9802\u70B9\u306E\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\u3092\u4E00\u69D8\u306B\
    \u9078\u3076 (Pr\xFCfer \u5217\u306E\u5FA9\u5143)\ninline std::vector<std::pair<int,\
    \ int>> random_tree(Random &rng, int n) {\n    assert(n >= 1);\n    std::vector<std::pair<int,\
    \ int>> edges;\n    if(n == 1) return edges;\n    edges.reserve(n - 1);\n    std::vector<int>\
    \ code(n - 2), degree(n, 1);\n    for(auto &x : code) x = int(rng.uniform(n)),\
    \ degree[x]++;\n    int ptr = 0;\n    while(degree[ptr] != 1) ptr++;\n    int\
    \ leaf = ptr;\n    for(int v : code) {\n        edges.emplace_back(leaf, v);\n\
    \        if(--degree[v] == 1 && v < ptr) {\n            leaf = v;\n        } else\
    \ {\n            ptr++;\n            while(degree[ptr] != 1) ptr++;\n        \
    \    leaf = ptr;\n        }\n    }\n    edges.emplace_back(leaf, n - 1);\n   \
    \ return relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9\u306E\u30D1\u30B9\
    \u30B0\u30E9\u30D5 (\u9802\u70B9\u306E\u4E26\u3073\u306F\u4E00\u69D8\u30E9\u30F3\
    \u30C0\u30E0)\ninline std::vector<std::pair<int, int>> random_path_tree(Random\
    \ &rng, int n) {\n    assert(n >= 1);\n    std::vector<std::pair<int, int>> edges;\n\
    \    for(int i = 0; i + 1 < n; i++) edges.emplace_back(i, i + 1);\n    return\
    \ relabel_edges(rng, n, edges);\n}\n\n// n \u9802\u70B9\u306E\u30B9\u30BF\u30FC\
    \u30B0\u30E9\u30D5 (\u4E2D\u5FC3\u306F\u4E00\u69D8\u30E9\u30F3\u30C0\u30E0)\n\
    inline std::vector<std::pair<int, int>> random_star_tree(Random &rng, int n) {\n\
    \    assert(n >= 1);\n    std::vector<std::pair<int, int>> edges;\n    for(int\
    \ i = 1; i < n; i++) edges.emplace_back(0, i);\n    return relabel_edges(rng,\
    \ n, edges);\n}\n\n// \u9802\u70B9 0 \u3092\u6839\u3068\u3059\u308B\u89AA\u914D\
    \u5217\u3002par[0] = -1\u3001i >= 1 \u3067\u306F par[i] \u306F [0, i) \u306E\u4E00\
    \u69D8\u4E71\u6570\ninline std::vector<int> random_parent_array(Random &rng, int\
    \ n) {\n    assert(n >= 1);\n    std::vector<int> par(n, -1);\n    for(int i =\
    \ 1; i < n; i++) par[i] = rng.randint(0, i);\n    return par;\n}\n#line 5 \"test/mytest/random/gen/tree.test.cpp\"\
    \n\nbool is_tree(int n, const vector<pair<int, int>> &edges) {\n    if((int)edges.size()\
    \ != n - 1) return false;\n    UnionFind uf(n);\n    for(auto [u, v] : edges)\
    \ {\n        if(u < 0 || u >= n || v < 0 || v >= n || !uf.merge(u, v)) return\
    \ false;\n    }\n    return true;\n}\n\nvector<pair<int, int>> normalize(vector<pair<int,\
    \ int>> edges) {\n    for(auto &[u, v] : edges) if(u > v) swap(u, v);\n    sort(edges.begin(),\
    \ edges.end());\n    return edges;\n}\n\nint main() {\n    Random rng(11);\n \
    \   // \u4E00\u69D8\u6027: 4 \u9802\u70B9\u306E\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\
    \u306F 4^2 = 16 \u901A\u308A\n    {\n        map<vector<pair<int, int>>, int>\
    \ cnt;\n        for(int iter = 0; iter < 16000; iter++) {\n            auto e\
    \ = random_tree(rng, 4);\n            assert(is_tree(4, e));\n            cnt[normalize(e)]++;\n\
    \        }\n        assert(cnt.size() == 16);\n        for(auto [e, c] : cnt)\
    \ assert(700 < c && c < 1300);\n    }\n    // \u5411\u304D\u3082\u9806\u5E8F\u3082\
    \u30E9\u30F3\u30C0\u30E0\n    {\n        bool forward = false, backward = false;\n\
    \        set<vector<pair<int, int>>> orders;\n        for(int iter = 0; iter <\
    \ 200; iter++) {\n            auto e = random_tree(rng, 3);\n            for(auto\
    \ [u, v] : e) (u < v ? forward : backward) = true;\n            orders.insert(e);\n\
    \        }\n        assert(forward && backward && orders.size() > 6);\n    }\n\
    \    for(int n = 1; n <= 50; n++) {\n        assert(is_tree(n, random_tree(rng,\
    \ n)));\n        auto path = random_path_tree(rng, n);\n        assert(is_tree(n,\
    \ path));\n        vector<int> deg(n);\n        for(auto [u, v] : path) deg[u]++,\
    \ deg[v]++;\n        for(int d : deg) assert(d <= 2);\n        auto star = random_star_tree(rng,\
    \ n);\n        assert(is_tree(n, star));\n        if(n >= 3) {\n            vector<int>\
    \ sd(n);\n            for(auto [u, v] : star) sd[u]++, sd[v]++;\n            assert(*max_element(sd.begin(),\
    \ sd.end()) == n - 1);\n        }\n        auto par = random_parent_array(rng,\
    \ n);\n        assert((int)par.size() == n && par[0] == -1);\n        for(int\
    \ i = 1; i < n; i++) assert(0 <= par[i] && par[i] < i);\n    }\n    {\n      \
    \  set<int> centers;\n        for(int iter = 0; iter < 200; iter++) {\n      \
    \      vector<int> sd(5);\n            for(auto [u, v] : random_star_tree(rng,\
    \ 5)) sd[u]++, sd[v]++;\n            centers.insert(int(max_element(sd.begin(),\
    \ sd.end()) - sd.begin()));\n        }\n        assert(centers.size() == 5);\n\
    \    }\n    {\n        auto e = relabel_edges(rng, 3, {{0, 1}, {1, 2}});\n   \
    \     assert(is_tree(3, e));\n        assert(relabel_edges(rng, 2, {}).empty());\n\
    \    }\n    INT(a, b);\n    print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../../template/template.cpp\"\
    \n#include \"../../../../data-structure/unionfind.hpp\"\n#include \"../../../../random/gen/tree.hpp\"\
    \n\nbool is_tree(int n, const vector<pair<int, int>> &edges) {\n    if((int)edges.size()\
    \ != n - 1) return false;\n    UnionFind uf(n);\n    for(auto [u, v] : edges)\
    \ {\n        if(u < 0 || u >= n || v < 0 || v >= n || !uf.merge(u, v)) return\
    \ false;\n    }\n    return true;\n}\n\nvector<pair<int, int>> normalize(vector<pair<int,\
    \ int>> edges) {\n    for(auto &[u, v] : edges) if(u > v) swap(u, v);\n    sort(edges.begin(),\
    \ edges.end());\n    return edges;\n}\n\nint main() {\n    Random rng(11);\n \
    \   // \u4E00\u69D8\u6027: 4 \u9802\u70B9\u306E\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\
    \u306F 4^2 = 16 \u901A\u308A\n    {\n        map<vector<pair<int, int>>, int>\
    \ cnt;\n        for(int iter = 0; iter < 16000; iter++) {\n            auto e\
    \ = random_tree(rng, 4);\n            assert(is_tree(4, e));\n            cnt[normalize(e)]++;\n\
    \        }\n        assert(cnt.size() == 16);\n        for(auto [e, c] : cnt)\
    \ assert(700 < c && c < 1300);\n    }\n    // \u5411\u304D\u3082\u9806\u5E8F\u3082\
    \u30E9\u30F3\u30C0\u30E0\n    {\n        bool forward = false, backward = false;\n\
    \        set<vector<pair<int, int>>> orders;\n        for(int iter = 0; iter <\
    \ 200; iter++) {\n            auto e = random_tree(rng, 3);\n            for(auto\
    \ [u, v] : e) (u < v ? forward : backward) = true;\n            orders.insert(e);\n\
    \        }\n        assert(forward && backward && orders.size() > 6);\n    }\n\
    \    for(int n = 1; n <= 50; n++) {\n        assert(is_tree(n, random_tree(rng,\
    \ n)));\n        auto path = random_path_tree(rng, n);\n        assert(is_tree(n,\
    \ path));\n        vector<int> deg(n);\n        for(auto [u, v] : path) deg[u]++,\
    \ deg[v]++;\n        for(int d : deg) assert(d <= 2);\n        auto star = random_star_tree(rng,\
    \ n);\n        assert(is_tree(n, star));\n        if(n >= 3) {\n            vector<int>\
    \ sd(n);\n            for(auto [u, v] : star) sd[u]++, sd[v]++;\n            assert(*max_element(sd.begin(),\
    \ sd.end()) == n - 1);\n        }\n        auto par = random_parent_array(rng,\
    \ n);\n        assert((int)par.size() == n && par[0] == -1);\n        for(int\
    \ i = 1; i < n; i++) assert(0 <= par[i] && par[i] < i);\n    }\n    {\n      \
    \  set<int> centers;\n        for(int iter = 0; iter < 200; iter++) {\n      \
    \      vector<int> sd(5);\n            for(auto [u, v] : random_star_tree(rng,\
    \ 5)) sd[u]++, sd[v]++;\n            centers.insert(int(max_element(sd.begin(),\
    \ sd.end()) - sd.begin()));\n        }\n        assert(centers.size() == 5);\n\
    \    }\n    {\n        auto e = relabel_edges(rng, 3, {{0, 1}, {1, 2}});\n   \
    \     assert(is_tree(3, e));\n        assert(relabel_edges(rng, 2, {}).empty());\n\
    \    }\n    INT(a, b);\n    print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - data-structure/unionfind.hpp
  - random/gen/tree.hpp
  - random/gen/random.hpp
  - random/gen/sequence.hpp
  isVerificationFile: true
  path: test/mytest/random/gen/tree.test.cpp
  requiredBy: []
  timestamp: '2026-11-13 01:10:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/random/gen/tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/random/gen/tree.test.cpp
- /verify/test/mytest/random/gen/tree.test.cpp.html
title: test/mytest/random/gen/tree.test.cpp
---
