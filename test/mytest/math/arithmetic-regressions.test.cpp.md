---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/F2.hpp
    title: "F\u2082 \u4E0A\u306E\u884C\u5217\u30FB\u9023\u7ACB\u65B9\u7A0B\u5F0F"
  - icon: ':heavy_check_mark:'
    path: math/barrett-reduction.hpp
    title: Barrett Reduction
  - icon: ':heavy_check_mark:'
    path: math/binom.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  - icon: ':heavy_check_mark:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/pow_mod.hpp
    title: "\u5270\u4F59\u4ED8\u304D\u7D2F\u4E57"
  - icon: ':heavy_check_mark:'
    path: math/segment-sieve.hpp
    title: "\u533A\u9593\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: modint/dynamic-modint.hpp
    title: "\u52D5\u7684\u6CD5 modint"
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: "\u56FA\u5B9A\u6CD5 modint"
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
  bundledCode: "#line 1 \"test/mytest/math/arithmetic-regressions.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"math/segment-sieve.hpp\"\
    \n\n#line 7 \"math/segment-sieve.hpp\"\n\nclass SegmentSieve {\n  public:\n  \
    \  explicit SegmentSieve(long long L, long long R)\n        : L(L), R(R), sq(std::sqrt((long\
    \ double)R) + 1) {\n        assert(0 <= L && L <= R);\n        small.assign(sq,\
    \ true);\n        large.assign(R - L, true);\n        for(long long n = L; n <\
    \ R && n < 2; n++) large[n - L] = false;\n        for(long long i = 2; i < sq\
    \ && i <= (R - 1) / i; i++) {\n            if(!small[i]) continue;\n         \
    \   for(long long j = i * i; j < sq; j += i) small[j] = false;\n            long\
    \ long first = L / i + (L % i != 0);\n            if(first > (R - 1) / i) continue;\n\
    \            long long start = std::max(first * i, i * i);\n            for(long\
    \ long j = start; j < R;) {\n                large[j - L] = false;\n         \
    \       if(R - 1 - j < i) break;\n                j += i;\n            }\n   \
    \     }\n    }\n    bool operator[](long long k) const {\n        assert(L <=\
    \ k && k < R);\n        return large[k - L];\n    }\n\n  private:\n    long long\
    \ L, R;\n    long long sq;\n    std::vector<bool> small, large;\n};\n#line 2 \"\
    math/is-prime.hpp\"\n\n#line 4 \"math/is-prime.hpp\"\n\n#line 2 \"math/pow_mod.hpp\"\
    \n\nconstexpr long long pow_mod(long long x, long long k, long long m) {\n   \
    \ long long res = 1 % m;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n\
    \    while(k) {\n        if(k & 1) res = (__int128_t)res * mul % m;\n        mul\
    \ = (__int128_t)mul * mul % m;\n        k >>= 1;\n    }\n    return res;\n}\n\
    #line 6 \"math/is-prime.hpp\"\n\n/*\nref: Fast Primality Testing for Integers\
    \ That Fit into a Machine Word\nMichal Fori\u02C7sek and Jakub Jan\u02C7cina\n\
    */\n\nconstexpr bool is_prime(int n) {\n    if(n <= 1) return false;\n    if(n\
    \ == 2 or n == 7 or n == 61) return true;\n    if((n & 1) == 0) return false;\n\
    \    long long d = n - 1;\n    while((d & 1) == 0) d >>= 1;\n    constexpr std::array<int,\
    \ 3> bases = {2, 7, 61};\n    for(int a : bases) {\n        long long t = d;\n\
    \        long long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 &&\
    \ y != n - 1) {\n            (y *= y) %= n;\n            t <<= 1;\n        }\n\
    \        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return true;\n\
    }\n\nconstexpr bool is_prime(long long n) {\n    if(n <= 1) return false;\n  \
    \  if(n == 2) return true;\n    if((n & 1) == 0) return false;\n    long long\
    \ d = n - 1;\n    while((d & 1) == 0) d >>= 1;\n    constexpr std::array<long\
    \ long, 7> bases = {\n        2, 325, 9375, 28178, 450775, 9780504, 1795265022\n\
    \    };\n    for(long long a : bases) {\n        a %= n;\n        if(a == 0) continue;\n\
    \        long long t = d;\n        long long y = pow_mod(a, t, n);\n        while(t\
    \ != n - 1 && y != 1 && y != n - 1) {\n            y = (__int128_t)y * y % n;\n\
    \            t <<= 1;\n        }\n        if(y != n - 1 && (t & 1) == 0) return\
    \ false;\n    }\n    return true;\n}\n#line 2 \"math/barrett-reduction.hpp\"\n\
    \n#line 4 \"math/barrett-reduction.hpp\"\n\nclass BarrettReduction {\npublic:\n\
    \    BarrettReduction(): BarrettReduction(1) {}\n    BarrettReduction(unsigned\
    \ int m)\n        : m(m), m_inv((unsigned long long)(-1) / m + 1) {}\n    unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n        unsigned long long\
    \ z = (unsigned long long)a * b;\n        unsigned long long v =  (unsigned long\
    \ long)(((__uint128_t)z * m_inv) >> 64);\n        unsigned int result = (unsigned\
    \ int)(z - v * m);\n        if(m <= result) result += m;\n        return result;\n\
    \    }\n    unsigned int quo(unsigned int a) const {\n        if(m == 1) return\
    \ a;\n        unsigned int result = (unsigned int)(((__uint128_t)a * m_inv) >>\
    \ 64);\n        return result;\n    }\n    unsigned int rem(unsigned long long\
    \ a) const {\n        if(m == 1) return 0;\n        unsigned long long v = (unsigned\
    \ long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned int result = (unsigned\
    \ int)(a - v * m);\n        if(m <= result) result += m;\n        return result;\n\
    \    }\n    std::pair<unsigned int, unsigned int> quorem(unsigned int a) const\
    \ {\n        if(m == 1) return {a, 0};\n        unsigned long long v =  (unsigned\
    \ long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned int r = (unsigned\
    \ int)((unsigned long long)a - v * m);\n        if(m <= r) r += m;\n        return\
    \ {v, r};\n    }\nprivate:\n    unsigned int m;\n    unsigned long long m_inv;\n\
    };\n#line 2 \"math/binom.hpp\"\n\n#line 6 \"math/binom.hpp\"\n\ntemplate <class\
    \ mint> class Binomial {\n  public:\n    explicit Binomial(): Binomial(1) {}\n\
    \    explicit Binomial(int MAX) : f(MAX, mint(1)), f_inv(MAX, mint(1)) {\n   \
    \     for(int i = 1; i < MAX; i++) f[i] = f[i-1] * mint(i);\n        f_inv[MAX\
    \ - 1] = f[MAX - 1].inv();\n        for(int i = MAX - 2; i >= 1; i--) {\n    \
    \        f_inv[i] = f_inv[i + 1] * mint(i + 1);\n        } \n    }\n    void extend()\
    \ {\n        int n = (int)f.size();\n        f.resize(n * 2);\n        f_inv.resize(n\
    \ * 2);\n        for(int i = n; i < n * 2; i++) f[i] = f[i - 1] * mint(i);\n \
    \       f_inv[n * 2 - 1] = f[n * 2 - 1].inv();\n        for(int i = n * 2 - 2;\
    \ i >= n; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i + 1);\n       \
    \ }\n    }\n    mint fac(int n) {\n        if(n < 0) return mint(0);\n       \
    \ while(n >= (int)f.size()) extend();\n        return f[n];\n    }\n    mint fac_inv(int\
    \ n) {\n        if(n < 0) return mint(0);\n        while(n >= (int)f_inv.size())\
    \ extend();\n        return f_inv[n];\n    }\n    mint inv(int n) {\n        if(n\
    \ < 0) return mint(n).inv();\n        assert(n != 0);\n        while(n >= (int)f_inv.size())\
    \ extend();\n        return (f_inv[n] * f[n - 1]);\n    }\n    mint binom(int\
    \ n, int k) {\n        if(n < k || n < 0 || k < 0) return mint(0);\n        return\
    \ (fac(n) * fac_inv(k) * fac_inv(n - k));\n    }\n    mint binom_naive(long long\
    \ n, long long k) {\n        if(n < k || n < 0 || k < 0) return mint(0);\n   \
    \     mint res(1);\n        k = std::min(k, n - k);\n        for(int i = 0; i\
    \ < k; i++) res *= inv(i + 1) * mint(n - i);\n        return res;\n    }\n   \
    \ mint perm(int n, int k) {\n        if(n < k || n < 0 || k < 0) return mint(0);\n\
    \        return (fac(n) * fac_inv(n - k));\n    }\n    mint hom(int n, int k)\
    \ {\n        if(n < 0 || k < 0) return mint(0);\n        return (k == 0 ? mint(1)\
    \ : binom(n + k - 1, k));\n    }\n\n  private:\n    std::vector<mint> f, f_inv;\n\
    };\n#line 2 \"modint/modint.hpp\"\n\n#line 6 \"modint/modint.hpp\"\n\ntemplate\
    \ <int mod> class ModInt {\n  public:\n    ModInt() : x(0) {}\n    ModInt(long\
    \ long y)\n        : x(y >= 0 ? y % umod() : (umod() - (-y) % umod()) % umod())\
    \ {}\n    unsigned int val() const { return x; }\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator-=(const ModInt &p) {\n        if((x += umod()\
    \ - p.x) >= umod()) x -= umod();\n        return *this;\n    }\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (unsigned int)(1ULL * x * p.x % umod());\n       \
    \ return *this;\n    }\n    ModInt &operator/=(const ModInt &p) {\n        *this\
    \ *= p.inv();\n        return *this;\n    }\n    ModInt operator-() const { return\
    \ ModInt(-(long long)x); }\n    ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n    ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n    ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n    ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n    bool operator==(const ModInt &p) const { return x\
    \ == p.x; }\n    bool operator!=(const ModInt &p) const { return x != p.x; }\n\
    \    ModInt inv() const {\n        long long a = x, b = mod, u = 1, v = 0, t;\n\
    \        while(b > 0) {\n            t = a / b;\n            std::swap(a -= t\
    \ * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n    ModInt pow(unsigned long long n) const {\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt &p) {\n        return\
    \ os << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, ModInt\
    \ &a) {\n        long long t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n    static constexpr int get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned int x;\n    static constexpr unsigned int umod()\
    \ { return mod; }\n};\n#line 2 \"modint/dynamic-modint.hpp\"\n\n#line 6 \"modint/dynamic-modint.hpp\"\
    \n\n#line 8 \"modint/dynamic-modint.hpp\"\n\n// verify: https://atcoder.jp/contests/arc104/submissions/38888866\n\
    class DynamicModInt {\n  public:\n    DynamicModInt() : x(0) {}\n    DynamicModInt(long\
    \ long y)\n        : x(y >= 0\n                ? y % (long long)mod\n        \
    \        : ((long long)mod - (-y) % (long long)mod) % (long long)mod) {}\n   \
    \ static void set_mod(unsigned int m) {\n        assert(m > 0);\n        mod =\
    \ m;\n        bt = BarrettReduction(m);\n    }\n    unsigned int val() const {\
    \ return x; }\n    DynamicModInt &operator+=(const DynamicModInt &p) {\n     \
    \   if((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n    DynamicModInt\
    \ &operator-=(const DynamicModInt &p) {\n        if((x += (mod - p.x)) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n    DynamicModInt &operator*=(const\
    \ DynamicModInt &p) {\n        x = bt.mul(x, p.x);\n        return *this;\n  \
    \  }\n    DynamicModInt &operator/=(const DynamicModInt &p) {\n        *this *=\
    \ p.inv();\n        return *this;\n    }\n    DynamicModInt operator-() const\
    \ { return DynamicModInt(-(long long)x); }\n    DynamicModInt operator+(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) += p;\n    }\n\
    \    DynamicModInt operator-(const DynamicModInt &p) const {\n        return DynamicModInt(*this)\
    \ -= p;\n    }\n    DynamicModInt operator*(const DynamicModInt &p) const {\n\
    \        return DynamicModInt(*this) *= p;\n    }\n    DynamicModInt operator/(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) /= p;\n    }\n\
    \    bool operator==(const DynamicModInt &p) const { return x == p.x; }\n    bool\
    \ operator!=(const DynamicModInt &p) const { return x != p.x; }\n    DynamicModInt\
    \ inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b\
    \ > 0) {\n            t = a / b;\n            std::swap(a -= t * b, b);\n    \
    \        std::swap(u -= t * v, v);\n        }\n        assert(a == 1 && \"gcd(x,\
    \ mod) must be '1'.\");\n        return DynamicModInt(u);\n    }\n    DynamicModInt\
    \ pow(long long n) const {\n        assert(n >= 0);\n        DynamicModInt ret(1),\
    \ mul(x);\n        while(n > 0) {\n            if(n & 1) ret *= mul;\n       \
    \     mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &p)\
    \ {\n        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModInt &a) {\n        long long t;\n        is >> t;\n        a\
    \ = DynamicModInt(t);\n        return (is);\n    }\n    static unsigned int get_mod()\
    \ { return mod; }\n\n  private:\n    unsigned int x;\n    static inline unsigned\
    \ int mod;\n    static inline BarrettReduction bt;\n};\n#line 2 \"math/F2.hpp\"\
    \n\n#line 7 \"math/F2.hpp\"\n\n// verify: https://atcoder.jp/contests/abc276/submissions/60797388\n\
    \ntemplate<int MAX_WIDTH>\nclass BitMatrix {\npublic:\n    int H, W;\n\n    BitMatrix():\
    \ H(1), W(1), mat(1) {\n        assert(W <= MAX_WIDTH);\n    }\n\n    BitMatrix(int\
    \ H, int W): H(H), W(W), mat(H) {\n        assert(W <= MAX_WIDTH);\n    }\n\n\
    \    inline std::bitset<MAX_WIDTH>& operator[](int i) { return mat[i]; }\n\n \
    \   // \u6383\u304D\u51FA\u3057\u6CD5\n    // https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    \    int row_reduction(std::vector<int>& b) {\n        assert((int)b.size() ==\
    \ H);\n        int rank = 0;\n        for(int j = 0; j < W; j++) {\n         \
    \   int pivot = -1;\n            for(int i = rank; i < H; i++) {\n           \
    \     if(mat[i][j]) {\n                    pivot = i;\n                    break;\n\
    \                }\n            }\n            if(pivot == -1) continue;\n   \
    \         std::swap(mat[pivot], mat[rank]);\n            std::swap(b[pivot], b[rank]);\n\
    \            for(int i = 0; i < H; i++) {\n                if(i != rank and mat[i][j])\
    \ {\n                    mat[i] ^= mat[rank];\n                    b[i] ^= b[rank];\n\
    \                }\n            }\n            rank++;\n        }\n        return\
    \ rank;\n    }\n\n    // \u6383\u304D\u51FA\u3057\u6CD5\n    // https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    \    int row_reduction() {\n        std::vector<int> b(H, 0);\n        return\
    \ row_reduction(b);\n    }\n\nprivate:\n    std::vector<std::bitset<MAX_WIDTH>>\
    \ mat;\n};\n\n// {rank, Ax = b\u306E\u89E3\u306E\u3046\u30611\u3064} \u3092\u8FD4\
    \u3059\n// \u89E3\u306A\u3057\u306E\u5834\u5408\u306F {-1, {}} \u3092\u8FD4\u3059\
    \ntemplate<int MAX_WIDTH>\nstd::pair<int, std::vector<int>> linear_equation_F2(BitMatrix<MAX_WIDTH>\
    \ A, std::vector<int> b) {\n    int H = A.H, W = A.W;\n    int rank = A.row_reduction(b);\n\
    \    // \u89E3\u306E\u5B58\u5728\u30C1\u30A7\u30C3\u30AF\n    for(int i = rank;\
    \ i < H; i++) if(b[i]) {\n        return {-1, {}};\n    }\n    std::vector<int>\
    \ ret(W);\n    for(int i = 0; i < rank; i++) {\n        int p = -1;\n        for(int\
    \ j = 0; j < W; j++) {\n            if(A[i][j]) {\n                p = j;\n  \
    \              break;\n            }\n        }\n        if(p == -1) continue;\n\
    \        ret[p] = b[i];\n    }\n    return {rank, ret};\n}\n#line 10 \"test/mytest/math/arithmetic-regressions.test.cpp\"\
    \n\nvoid regression_test() {\n    for(int l = 0; l <= 300; l++) for(int width\
    \ : {0, 1, 2, 30, 100}) {\n        SegmentSieve s(l, l + width);\n        for(int\
    \ x = l; x < l + width; x++) assert(s[x] == is_prime(x));\n    }\n    SegmentSieve\
    \ big(10000000000LL, 10000000100LL);\n    for(long long x = 10000000000LL; x <\
    \ 10000000100LL; x++) assert(big[x] == is_prime(x));\n    BarrettReduction one;\n\
    \    for(unsigned x : {0U, 1U, 123U, UINT_MAX}) {\n        assert(one.quo(x) ==\
    \ x && one.rem(x) == 0);\n        assert(one.quorem(x) == make_pair(x, 0U));\n\
    \    }\n    assert(one.rem(ULLONG_MAX) == 0);\n    assert(pow_mod(2, 0, 1) ==\
    \ 0 && pow_mod(-2, 3, 5) == 2);\n    Binomial<ModInt<7>> b;\n    assert(b.inv(-2).val()\
    \ == 3 && b.inv(2).val() == 4);\n    DynamicModInt::set_mod(7);\n    for(int i\
    \ = 0; i < 7; i++) assert((-DynamicModInt(i) + DynamicModInt(i)).val() == 0);\n\
    \    BitMatrix<2> mat(2, 2);\n    mat[0][0] = mat[1][1] = true;\n    auto solution\
    \ = linear_equation_F2(mat, vector<int>{1, 0});\n    assert(solution.first ==\
    \ 2 && solution.second == vector<int>({1, 0}));\n}\n\nint main() {\n    regression_test();\n\
    \    INT(a, b);\n    print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../math/segment-sieve.hpp\"\n#include \"../../../math/is-prime.hpp\"\
    \n#include \"../../../math/barrett-reduction.hpp\"\n#include \"../../../math/binom.hpp\"\
    \n#include \"../../../modint/modint.hpp\"\n#include \"../../../modint/dynamic-modint.hpp\"\
    \n#include \"../../../math/F2.hpp\"\n\nvoid regression_test() {\n    for(int l\
    \ = 0; l <= 300; l++) for(int width : {0, 1, 2, 30, 100}) {\n        SegmentSieve\
    \ s(l, l + width);\n        for(int x = l; x < l + width; x++) assert(s[x] ==\
    \ is_prime(x));\n    }\n    SegmentSieve big(10000000000LL, 10000000100LL);\n\
    \    for(long long x = 10000000000LL; x < 10000000100LL; x++) assert(big[x] ==\
    \ is_prime(x));\n    BarrettReduction one;\n    for(unsigned x : {0U, 1U, 123U,\
    \ UINT_MAX}) {\n        assert(one.quo(x) == x && one.rem(x) == 0);\n        assert(one.quorem(x)\
    \ == make_pair(x, 0U));\n    }\n    assert(one.rem(ULLONG_MAX) == 0);\n    assert(pow_mod(2,\
    \ 0, 1) == 0 && pow_mod(-2, 3, 5) == 2);\n    Binomial<ModInt<7>> b;\n    assert(b.inv(-2).val()\
    \ == 3 && b.inv(2).val() == 4);\n    DynamicModInt::set_mod(7);\n    for(int i\
    \ = 0; i < 7; i++) assert((-DynamicModInt(i) + DynamicModInt(i)).val() == 0);\n\
    \    BitMatrix<2> mat(2, 2);\n    mat[0][0] = mat[1][1] = true;\n    auto solution\
    \ = linear_equation_F2(mat, vector<int>{1, 0});\n    assert(solution.first ==\
    \ 2 && solution.second == vector<int>({1, 0}));\n}\n\nint main() {\n    regression_test();\n\
    \    INT(a, b);\n    print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - math/segment-sieve.hpp
  - math/is-prime.hpp
  - math/pow_mod.hpp
  - math/barrett-reduction.hpp
  - math/binom.hpp
  - modint/modint.hpp
  - modint/dynamic-modint.hpp
  - math/F2.hpp
  isVerificationFile: true
  path: test/mytest/math/arithmetic-regressions.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/math/arithmetic-regressions.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/math/arithmetic-regressions.test.cpp
- /verify/test/mytest/math/arithmetic-regressions.test.cpp.html
title: test/mytest/math/arithmetic-regressions.test.cpp
---
