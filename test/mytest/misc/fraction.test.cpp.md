---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/fraction.hpp
    title: misc/fraction.hpp
  - icon: ':heavy_check_mark:'
    path: random/rng.hpp
    title: "\u4E71\u6570\u751F\u6210"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/misc/fraction.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\n\
    #pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\n// input\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"misc/fraction.hpp\"\n\
    \n#line 4 \"misc/fraction.hpp\"\n\ntemplate<typename Int = long long>\nstruct\
    \ Fraction {\n    using F = Fraction;\n    Int a, b;\n\n    Fraction(): a(0),\
    \ b(1) {}\n    Fraction(Int _a, Int _b): a(_a), b(_b) {\n        normalize();\n\
    \    }\n    Fraction(Int _a): a(_a), b(1) {}\n    inline void normalize() {\n\
    \        Int g = Fraction::gcd(a, b);\n        a /= g;\n        b /= g;\n    \
    \    if(b < 0) {\n            a = -a, b = -b;\n        }\n    }\n    F &operator+=(const\
    \ F& f) {\n        Int na = a * f.b + b * f.a;\n        Int nb = b * f.b;\n  \
    \      a = na, b = nb;\n        normalize();\n        return *this;\n    }\n \
    \   F &operator-=(const F& f) {\n        Int na = a * f.b - b * f.a;\n       \
    \ Int nb = b * f.b;\n        a = na, b = nb;\n        normalize();\n        return\
    \ *this;\n    }\n    F &operator*=(const F& f) {\n        a *= f.a;\n        b\
    \ *= f.b;\n        normalize();\n        return *this;\n    }\n    F &operator/=(const\
    \ F& f) {\n        a *= f.b;\n        b *= f.a;\n        normalize();\n      \
    \  return *this;\n    }\n    F operator-() const { return F(-a, b); }\n    F operator+(const\
    \ F& f) const { return F(*this) += f; }\n    F operator-(const F& f) const { return\
    \ F(*this) -= f; }\n    F operator*(const F& f) const { return F(*this) *= f;\
    \ }\n    F operator/(const F& f) const { return F(*this) /= f; }\n    bool operator==(const\
    \ F& f) const {\n        return a * f.b == b * f.a;\n    }\n    bool operator!=(const\
    \ F& f) const {\n        return !(*this == f);\n    }\n    bool operator<(const\
    \ F& f) const {\n        return a * f.b < b * f.a;\n    }\n    bool operator<=(const\
    \ F& f) const {\n        return a * f.b <= b * f.a;\n    }\n    bool operator>(const\
    \ F& f) const {\n        return !(*this <= f);\n    }\n    bool operator>=(const\
    \ F& f) const {\n        return !(*this < f);\n    }\n    \n    inline static\
    \ Int gcd(Int a, Int b) {\n        Int s = (a > 0 ? a : -a), t = (b > 0 ? b :\
    \ -b);\n        while (s % t != 0) {\n            Int u = s % t;\n           \
    \ s = t;\n            t = u;\n        }\n        return t;\n    }\n};\n#line 2\
    \ \"random/rng.hpp\"\n\n#line 5 \"random/rng.hpp\"\n\nclass RNG32 {\n  public:\n\
    \    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n#line 5 \"test/mytest/misc/fraction.test.cpp\"\n\
    \nusing F = Fraction<i128>;\nRNG32 r;\n\nF generate_random_frac() {\n    ll a\
    \ = r.randint(-100000, 100000 + 1);\n    ll b = r.randint(-100000, 100000 + 1);\n\
    \    while(b == 0) {\n        b = r.randint(-100000, 100000 + 1);\n    }\n   \
    \ return F(a, b);\n}\n\nvoid fraction_test() {\n    REP(_, 100) {\n        F f1\
    \ = generate_random_frac();\n        F f2 = generate_random_frac();\n        F\
    \ f = f1 * f2 / f2;\n        assert(f == f1);\n        f = f1 + f2 - f2;\n   \
    \     assert(f == f1);\n        f = f1 - f2 + f2;\n        assert(f == f1);\n\
    \        f = f1 / f2 * f2;\n        assert(f == f1);\n        f = f2 / f1 * f1;\n\
    \        assert(f != f1);\n        f = f1 + f2 * 2;\n        assert(f != f1);\n\
    \    }\n}\n\nint main() {\n    fraction_test();\n    INT(a, b);\n    print(a +\
    \ b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../misc/fraction.hpp\"\n#include \"../../../random/rng.hpp\"\
    \n\nusing F = Fraction<i128>;\nRNG32 r;\n\nF generate_random_frac() {\n    ll\
    \ a = r.randint(-100000, 100000 + 1);\n    ll b = r.randint(-100000, 100000 +\
    \ 1);\n    while(b == 0) {\n        b = r.randint(-100000, 100000 + 1);\n    }\n\
    \    return F(a, b);\n}\n\nvoid fraction_test() {\n    REP(_, 100) {\n       \
    \ F f1 = generate_random_frac();\n        F f2 = generate_random_frac();\n   \
    \     F f = f1 * f2 / f2;\n        assert(f == f1);\n        f = f1 + f2 - f2;\n\
    \        assert(f == f1);\n        f = f1 - f2 + f2;\n        assert(f == f1);\n\
    \        f = f1 / f2 * f2;\n        assert(f == f1);\n        f = f2 / f1 * f1;\n\
    \        assert(f != f1);\n        f = f1 + f2 * 2;\n        assert(f != f1);\n\
    \    }\n}\n\nint main() {\n    fraction_test();\n    INT(a, b);\n    print(a +\
    \ b);\n}"
  dependsOn:
  - template/template.cpp
  - misc/fraction.hpp
  - random/rng.hpp
  isVerificationFile: true
  path: test/mytest/misc/fraction.test.cpp
  requiredBy: []
  timestamp: '2024-11-17 22:22:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/misc/fraction.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/misc/fraction.test.cpp
- /verify/test/mytest/misc/fraction.test.cpp.html
title: test/mytest/misc/fraction.test.cpp
---
