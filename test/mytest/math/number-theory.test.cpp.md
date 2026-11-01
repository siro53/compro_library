---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':question:'
    path: math/eratosthenes.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  - icon: ':question:'
    path: math/is-prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':x:'
    path: math/linear-sieve.hpp
    title: "\u7DDA\u5F62\u7BE9"
  - icon: ':question:'
    path: math/pow_mod.hpp
    title: "\u5270\u4F59\u4ED8\u304D\u7D2F\u4E57"
  - icon: ':question:'
    path: math/prime-factor.hpp
    title: "\u8A66\u3057\u5272\u308A\u306B\u3088\u308B\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':question:'
    path: math/primitive-root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':question:'
    path: math/segment-factorize.hpp
    title: "\u533A\u9593\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':x:'
    path: math/segment-sieve.hpp
    title: "\u533A\u9593\u7D20\u6570\u5224\u5B9A"
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
  bundledCode: "#line 1 \"test/mytest/math/number-theory.test.cpp\"\n#define PROBLEM\
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
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"math/linear-sieve.hpp\"\n\
    \n#line 5 \"math/linear-sieve.hpp\"\n\nclass LinearSieve {\n  public:\n    LinearSieve()\
    \ {}\n    explicit LinearSieve(int n) : n(n), min_factor(n + 1, -1) {\n      \
    \  std::vector<int> prime_list;\n        for(int d = 2; d <= n; d++) {\n     \
    \       if(min_factor[d] == -1) {\n                min_factor[d] = d;\n      \
    \          prime_list.push_back(d);\n            }\n            for(int p : prime_list)\
    \ {\n                if(p * d > n or min_factor[d] < p) break;\n             \
    \   min_factor[p * d] = p;\n            }\n        }\n    }\n    std::vector<int>\
    \ factor(int num) {\n        assert(0 <= num and num <= n);\n        std::vector<int>\
    \ ret;\n        while(num > 1) {\n            ret.push_back(min_factor[num]);\n\
    \            num /= min_factor[num];\n        }\n        return ret;\n    }\n\
    \    const int &operator[](int k) const { return min_factor[k]; }\n\n  private:\n\
    \    int n;\n    std::vector<int> min_factor;\n};\n#line 2 \"math/eratosthenes.hpp\"\
    \n\n#line 4 \"math/eratosthenes.hpp\"\n\nclass Eratosthenes {\n  public:\n   \
    \ Eratosthenes() {}\n    explicit Eratosthenes(int n) : n(n), isp(n + 1, true)\
    \ {\n        isp[0] = isp[1] = false;\n        for(int i = 2; i * i <= n; i++)\
    \ {\n            if(!isp[i]) continue;\n            for(int j = i * i; j <= n;\
    \ j += i) isp[j] = false;\n        }\n    }\n    bool operator[](int k) const\
    \ { return isp[k]; }\n\n  private:\n    int n;\n    std::vector<bool> isp;\n};\n\
    #line 2 \"math/segment-sieve.hpp\"\n\n#line 7 \"math/segment-sieve.hpp\"\n\nclass\
    \ SegmentSieve {\n  public:\n    explicit SegmentSieve(long long L, long long\
    \ R)\n        : L(L), R(R), sq(std::sqrt((long double)R) + 1) {\n        assert(0\
    \ <= L && L <= R);\n        small.assign(sq, true);\n        large.assign(R -\
    \ L, true);\n        for(long long n = L; n < R && n < 2; n++) large[n - L] =\
    \ false;\n        for(long long i = 2; i < sq && i <= (R - 1) / i; i++) {\n  \
    \          if(!small[i]) continue;\n            for(long long j = i * i; j < sq;\
    \ j += i) small[j] = false;\n            long long first = L / i + (L % i != 0);\n\
    \            if(first > (R - 1) / i) continue;\n            long long start =\
    \ std::max(first * i, i * i);\n            for(long long j = start; j < R;) {\n\
    \                large[j - L] = false;\n                if(R - 1 - j < i) break;\n\
    \                j += i;\n            }\n        }\n    }\n    bool operator[](long\
    \ long k) const {\n        assert(L <= k && k < R);\n        return large[k -\
    \ L];\n    }\n\n  private:\n    long long L, R;\n    long long sq;\n    std::vector<bool>\
    \ small, large;\n};\n#line 2 \"math/segment-factorize.hpp\"\n\n#line 8 \"math/segment-factorize.hpp\"\
    \n\nclass SegmentFactorize {\npublic:\n    explicit SegmentFactorize(long long\
    \ L, long long R): L(L), R(R), sq(std::sqrt(R) + 1) {\n        small.resize(sq);\n\
    \        std::iota(small.begin(), small.end(), 0);\n        large.resize(R - L);\n\
    \        large_mul.assign(R - L, 1);\n        for(long long i = 2; i * i < R;\
    \ i++) {\n            if(small[i] < i) continue;\n            for(long long j\
    \ = i * i; j < sq; j += i) {\n                if(small[j] == j) small[j] = i;\n\
    \            }\n            for(long long j = (L + i - 1) / i * i; j < R; j +=\
    \ i) {\n                long long now = j;\n                do {\n           \
    \         if(large_mul[j - L] * large_mul[j - L] > R) break;\n               \
    \     large[j - L].push_back(i);\n                    large_mul[j - L] *= i;\n\
    \                    now /= i;\n                } while(now % i == 0);\n     \
    \       }\n        }\n    } \n    std::vector<long long> factor(long long n) {\n\
    \        assert(L <= n and n < R);\n        std::vector<long long> ret = large[n\
    \ - L];\n        n /= large_mul[n - L];\n        if(n >= sq) {\n            ret.push_back(n);\n\
    \            return ret;\n        }\n        while(n > 1) {\n            ret.push_back(small[n]);\n\
    \            n /= small[n];\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    long long L, R;\n    int sq;\n    std::vector<int> small;\n    std::vector<std::vector<long\
    \ long>> large;\n    std::vector<long long> large_mul;\n};\n#line 2 \"math/divisor.hpp\"\
    \n\n#line 4 \"math/divisor.hpp\"\n#include <type_traits>\n#line 6 \"math/divisor.hpp\"\
    \n\ntemplate <typename T, std::enable_if_t<std::is_integral<T>::value, int> =\
    \ 0>\nstd::vector<T> divisor(T n) {\n    std::vector<T> ret;\n    for(T i = 1;\
    \ i * i <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n\
    \            if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n#line 2 \"math/prime-factor.hpp\"\n\n#line\
    \ 5 \"math/prime-factor.hpp\"\n\ntemplate <class T, std::enable_if_t<std::is_integral<T>::value,\
    \ int> = 0>\nstd::map<T, int> prime_factor(T n) {\n    std::map<T, int> ret;\n\
    \    for(T i = 2; i * i <= n; i++) {\n        if(n % i == 0) {\n            int\
    \ cnt = 0;\n            while(n % i == 0) {\n                n /= i;\n       \
    \         cnt++;\n            }\n            ret[i] = cnt;\n        }\n    }\n\
    \    if(n != 1) ret[n] = 1;\n    return ret;\n}\n#line 2 \"math/is-prime.hpp\"\
    \n\n#line 4 \"math/is-prime.hpp\"\n\n#line 2 \"math/pow_mod.hpp\"\n\nconstexpr\
    \ long long pow_mod(long long x, long long k, long long m) {\n    long long res\
    \ = 1 % m;\n    long long mul = (x >= 0 ? x % m : x % m + m);\n    while(k) {\n\
    \        if(k & 1) res = (__int128_t)res * mul % m;\n        mul = (__int128_t)mul\
    \ * mul % m;\n        k >>= 1;\n    }\n    return res;\n}\n#line 6 \"math/is-prime.hpp\"\
    \n\n/*\nref: Fast Primality Testing for Integers That Fit into a Machine Word\n\
    Michal Fori\u02C7sek and Jakub Jan\u02C7cina\n*/\n\nconstexpr bool is_prime(int\
    \ n) {\n    if(n <= 1) return false;\n    if(n == 2 or n == 7 or n == 61) return\
    \ true;\n    if((n & 1) == 0) return false;\n    long long d = n - 1;\n    while((d\
    \ & 1) == 0) d >>= 1;\n    constexpr std::array<int, 3> bases = {2, 7, 61};\n\
    \    for(int a : bases) {\n        long long t = d;\n        long long y = pow_mod(a,\
    \ t, n);\n        while(t != n - 1 && y != 1 && y != n - 1) {\n            (y\
    \ *= y) %= n;\n            t <<= 1;\n        }\n        if(y != n - 1 && (t &\
    \ 1) == 0) return false;\n    }\n    return true;\n}\n\nconstexpr bool is_prime(long\
    \ long n) {\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if((n\
    \ & 1) == 0) return false;\n    long long d = n - 1;\n    while((d & 1) == 0)\
    \ d >>= 1;\n    constexpr std::array<long long, 7> bases = {\n        2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022\n    };\n    for(long long a : bases)\
    \ {\n        a %= n;\n        if(a == 0) continue;\n        long long t = d;\n\
    \        long long y = pow_mod(a, t, n);\n        while(t != n - 1 && y != 1 &&\
    \ y != n - 1) {\n            y = (__int128_t)y * y % n;\n            t <<= 1;\n\
    \        }\n        if(y != n - 1 && (t & 1) == 0) return false;\n    }\n    return\
    \ true;\n}\n#line 2 \"math/primitive-root.hpp\"\n\n#line 4 \"math/primitive-root.hpp\"\
    \n\nconstexpr int primitive_root(int p) {\n    if(p == 2) return 1;\n    if(p\
    \ == 998244353) return 3;\n    int primes[31] = {};\n    int sz = 0, t = p - 1;\n\
    \    for(int i = 2; i * i <= t; i++) {\n        if(t % i == 0) {\n           \
    \ primes[sz++] = i;\n            while(t % i == 0) t /= i;\n        }\n    }\n\
    \    if(t > 1) primes[sz++] = t;\n    for(int g = 2;;g++) {\n        bool f =\
    \ true;\n        for(int i = 0; i < sz; i++) {\n            if(pow_mod(g, (p -\
    \ 1) / primes[i], p) == 1) {\n                f = false;\n                break;\n\
    \            }\n        }   \n        if(f) return g;\n    }\n}\n#line 12 \"test/mytest/math/number-theory.test.cpp\"\
    \n\n\nint main() {\n    LinearSieve linear;\n    linear = LinearSieve(2000);\n\
    \    Eratosthenes sieve;\n    sieve = Eratosthenes(2000);\n    assert(linear[0]\
    \ == -1 && linear[1] == -1);\n    assert(linear.factor(0).empty() && linear.factor(1).empty());\n\
    \    SegmentSieve segment(0, 2001);\n    SegmentFactorize factorize(1, 2001);\n\
    \    for(int n = 1; n <= 2000; ++n) {\n        vector<int> divisors;\n       \
    \ for(int d = 1; d <= n; ++d) if(n % d == 0) divisors.push_back(d);\n        assert(divisor(n)\
    \ == divisors);\n        auto wide = divisor((ll)n);\n        assert(vector<ll>(divisors.begin(),\
    \ divisors.end()) == wide);\n        map<int, int> factors;\n        int rest\
    \ = n;\n        for(int d = 2; d <= n; ++d) while(rest % d == 0) { ++factors[d];\
    \ rest /= d; }\n        assert(prime_factor(n) == factors);\n        auto long_factors\
    \ = prime_factor((ll)n);\n        assert((map<ll, int>(factors.begin(), factors.end())\
    \ == long_factors));\n        vector<int> list;\n        for(auto [p, exponent]\
    \ : factors) while(exponent--) list.push_back(p);\n        assert(linear.factor(n)\
    \ == list);\n        auto segmented = factorize.factor(n);\n        sort(segmented.begin(),\
    \ segmented.end());\n        assert(segmented == vector<ll>(list.begin(), list.end()));\n\
    \        bool prime = divisors.size() == 2;\n        assert(sieve[n] == prime\
    \ && segment[n] == prime);\n        assert(is_prime(n) == prime && is_prime((ll)n)\
    \ == prime);\n        if(n >= 2) assert(linear[n] == list.front());\n    }\n \
    \   for(int n : {-10, -1, 0, 1}) assert(!is_prime(n) && !is_prime((ll)n));\n \
    \   for(ll mod : {1LL, 2LL, 7LL, 1000000007LL, LLONG_MAX}) {\n        for(ll base\
    \ : {-100LL, -7LL, 0LL, 1LL, 7LL, LLONG_MAX}) {\n            ll expected = 1 %\
    \ mod;\n            ll normalized = (base % mod + (__int128)mod) % mod;\n    \
    \        for(int exponent = 0; exponent <= 25; ++exponent) {\n               \
    \ assert(pow_mod(base, exponent, mod) == expected);\n                expected\
    \ = (__int128)expected * normalized % mod;\n            }\n        }\n    }\n\
    \    for(int p : {2, 3, 5, 7, 17, 97, 257}) {\n        int g = primitive_root(p),\
    \ value = 1;\n        set<int> powers;\n        for(int i = 0; i < p - 1; ++i)\
    \ { powers.insert(value); value = value * g % p; }\n        assert(int(powers.size())\
    \ == p - 1 && value == 1);\n    }\n    assert(primitive_root(998244353) == 3);\n\
    \    INT(a, b); print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../math/linear-sieve.hpp\"\n#include \"../../../math/eratosthenes.hpp\"\
    \n#include \"../../../math/segment-sieve.hpp\"\n#include \"../../../math/segment-factorize.hpp\"\
    \n#include \"../../../math/divisor.hpp\"\n#include \"../../../math/prime-factor.hpp\"\
    \n#include \"../../../math/is-prime.hpp\"\n#include \"../../../math/pow_mod.hpp\"\
    \n#include \"../../../math/primitive-root.hpp\"\n\n\nint main() {\n    LinearSieve\
    \ linear;\n    linear = LinearSieve(2000);\n    Eratosthenes sieve;\n    sieve\
    \ = Eratosthenes(2000);\n    assert(linear[0] == -1 && linear[1] == -1);\n   \
    \ assert(linear.factor(0).empty() && linear.factor(1).empty());\n    SegmentSieve\
    \ segment(0, 2001);\n    SegmentFactorize factorize(1, 2001);\n    for(int n =\
    \ 1; n <= 2000; ++n) {\n        vector<int> divisors;\n        for(int d = 1;\
    \ d <= n; ++d) if(n % d == 0) divisors.push_back(d);\n        assert(divisor(n)\
    \ == divisors);\n        auto wide = divisor((ll)n);\n        assert(vector<ll>(divisors.begin(),\
    \ divisors.end()) == wide);\n        map<int, int> factors;\n        int rest\
    \ = n;\n        for(int d = 2; d <= n; ++d) while(rest % d == 0) { ++factors[d];\
    \ rest /= d; }\n        assert(prime_factor(n) == factors);\n        auto long_factors\
    \ = prime_factor((ll)n);\n        assert((map<ll, int>(factors.begin(), factors.end())\
    \ == long_factors));\n        vector<int> list;\n        for(auto [p, exponent]\
    \ : factors) while(exponent--) list.push_back(p);\n        assert(linear.factor(n)\
    \ == list);\n        auto segmented = factorize.factor(n);\n        sort(segmented.begin(),\
    \ segmented.end());\n        assert(segmented == vector<ll>(list.begin(), list.end()));\n\
    \        bool prime = divisors.size() == 2;\n        assert(sieve[n] == prime\
    \ && segment[n] == prime);\n        assert(is_prime(n) == prime && is_prime((ll)n)\
    \ == prime);\n        if(n >= 2) assert(linear[n] == list.front());\n    }\n \
    \   for(int n : {-10, -1, 0, 1}) assert(!is_prime(n) && !is_prime((ll)n));\n \
    \   for(ll mod : {1LL, 2LL, 7LL, 1000000007LL, LLONG_MAX}) {\n        for(ll base\
    \ : {-100LL, -7LL, 0LL, 1LL, 7LL, LLONG_MAX}) {\n            ll expected = 1 %\
    \ mod;\n            ll normalized = (base % mod + (__int128)mod) % mod;\n    \
    \        for(int exponent = 0; exponent <= 25; ++exponent) {\n               \
    \ assert(pow_mod(base, exponent, mod) == expected);\n                expected\
    \ = (__int128)expected * normalized % mod;\n            }\n        }\n    }\n\
    \    for(int p : {2, 3, 5, 7, 17, 97, 257}) {\n        int g = primitive_root(p),\
    \ value = 1;\n        set<int> powers;\n        for(int i = 0; i < p - 1; ++i)\
    \ { powers.insert(value); value = value * g % p; }\n        assert(int(powers.size())\
    \ == p - 1 && value == 1);\n    }\n    assert(primitive_root(998244353) == 3);\n\
    \    INT(a, b); print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - math/linear-sieve.hpp
  - math/eratosthenes.hpp
  - math/segment-sieve.hpp
  - math/segment-factorize.hpp
  - math/divisor.hpp
  - math/prime-factor.hpp
  - math/is-prime.hpp
  - math/pow_mod.hpp
  - math/primitive-root.hpp
  isVerificationFile: true
  path: test/mytest/math/number-theory.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:39:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/math/number-theory.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/math/number-theory.test.cpp
- /verify/test/mytest/math/number-theory.test.cpp.html
title: test/mytest/math/number-theory.test.cpp
---
