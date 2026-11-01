---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/add.hpp
    title: "\u52A0\u7B97\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/affine.hpp
    title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/and.hpp
    title: "\u30D3\u30C3\u30C8 AND\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/gcd.hpp
    title: "\u6700\u5927\u516C\u7D04\u6570\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/kadane.hpp
    title: "\u6700\u5927\u90E8\u5206\u914D\u5217\u548C\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/lcm.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/max.hpp
    title: "\u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/max_index.hpp
    title: "\u6DFB\u5B57\u4ED8\u304D\u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/min.hpp
    title: "\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/min_index.hpp
    title: "\u6DFB\u5B57\u4ED8\u304D\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/or.hpp
    title: "\u30D3\u30C3\u30C8 OR\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/rolling_hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/sum_count.hpp
    title: "\u548C\u30FB\u500B\u6570\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61.hpp
    title: "\u6CD5 2^61-1 \u306E modint"
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: Rolling Hash
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
  bundledCode: "#line 1 \"test/mytest/data-structure/monoids.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"data-structure/monoid/add.hpp\"\
    \n\ntemplate <typename T> struct MonoidAdd {\n    using value_type = T;\n    inline\
    \ static T op(const T &l, const T &r) { return (l + r); }\n    inline static T\
    \ e() { return T(0); }\n};\n#line 2 \"data-structure/monoid/affine.hpp\"\n\n#line\
    \ 4 \"data-structure/monoid/affine.hpp\"\n\ntemplate <typename T, bool rev = false>\
    \ struct MonoidAffine {\n    using S = std::pair<T, T>;\n    using value_type\
    \ = S;\n    inline static S op(const S &l, const S &r) {\n        if(rev) return\
    \ S(r.first * l.first, r.first * l.second + r.second);\n        return S(l.first\
    \ * r.first, l.first * r.second + l.second);\n    }\n    inline static S e() {\
    \ return S(T(1), T(0)); }\n};\n#line 2 \"data-structure/monoid/and.hpp\"\n\ntemplate\
    \ <typename T> struct MonoidAND {\n    using value_type = T;\n    inline static\
    \ T op(const T &l, const T &r) { return (l & r); }\n    inline static T e() {\
    \ return T(~T(0)); }\n};\n#line 2 \"data-structure/monoid/or.hpp\"\n\ntemplate\
    \ <typename T> struct MonoidOR {\n    using value_type = T;\n    inline static\
    \ T op(const T &l, const T &r) { return (l | r); }\n    inline static T e() {\
    \ return T(0); }\n};\n#line 2 \"data-structure/monoid/gcd.hpp\"\n\n#line 4 \"\
    data-structure/monoid/gcd.hpp\"\n\ntemplate <typename T> struct MonoidGCD {\n\
    \    using value_type = T;\n    inline static T op(const T& l, const T& r) {\n\
    \        return std::gcd(l, r);\n    }\n    inline static T e() { return T(0);\
    \ }\n};\n#line 2 \"data-structure/monoid/lcm.hpp\"\n\n#line 4 \"data-structure/monoid/lcm.hpp\"\
    \n\ntemplate <typename T> struct MonoidLCM {\n    using value_type = T;\n    inline\
    \ static T op(const T& l, const T& r) {\n        return std::lcm(l, r);\n    }\n\
    \    inline static T e() { return T(1); }\n};\n#line 2 \"data-structure/monoid/min.hpp\"\
    \n\n#line 5 \"data-structure/monoid/min.hpp\"\n\ntemplate <typename T, T INF =\
    \ std::numeric_limits<T>::max()> struct MonoidMin {\n    using value_type = T;\n\
    \    inline static T op(const T &l, const T &r) { return std::min(l, r); }\n \
    \   inline static T e() { return INF; }\n};\n#line 2 \"data-structure/monoid/max.hpp\"\
    \n\n#line 5 \"data-structure/monoid/max.hpp\"\n\ntemplate <typename T, T MINUS_INF\
    \ = std::numeric_limits<T>::min()> struct MonoidMax {\n    using value_type =\
    \ T;\n    inline static T op(const T &l, const T &r) { return std::max(l, r);\
    \ }\n    inline static T e() { return MINUS_INF; }\n};\n#line 2 \"data-structure/monoid/min_index.hpp\"\
    \n\n#line 6 \"data-structure/monoid/min_index.hpp\"\n\ntemplate <typename T, T\
    \ INF = std::numeric_limits<T>::max()> struct MonoidMinWithIndex {\n    using\
    \ S = std::pair<T, int>;\n    using value_type = S;\n    inline static S op(const\
    \ S &l, const S &r) { return std::min(l, r); }\n    inline static S e() {\n  \
    \      return std::make_pair(INF, -1);\n    }\n};\n#line 2 \"data-structure/monoid/max_index.hpp\"\
    \n\n#line 6 \"data-structure/monoid/max_index.hpp\"\n\ntemplate <typename T, T\
    \ MINUS_INF = std::numeric_limits<T>::min()> struct MonoidMaxWithIndex {\n   \
    \ using S = std::pair<T, int>;\n    using value_type = S;\n    inline static S\
    \ op(const S &l, const S &r) { return std::max(l, r); }\n    inline static S e()\
    \ {\n        return std::make_pair(MINUS_INF, -1);\n    }\n};\n#line 2 \"data-structure/monoid/sum_count.hpp\"\
    \n\ntemplate <typename sum_t, typename count_t> struct MonoidSumCount {\n    struct\
    \ S {\n        sum_t sum;\n        count_t cnt;\n        S() = default;\n    \
    \    S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type\
    \ = S;\n    inline static S op(const S& l, const S& r) {\n        return S(l.sum\
    \ + r.sum, l.cnt + r.cnt);\n    }\n    inline static S e() { return S(sum_t(0),\
    \ count_t(0)); }\n};\n#line 2 \"data-structure/monoid/rolling_hash.hpp\"\n\n#line\
    \ 5 \"data-structure/monoid/rolling_hash.hpp\"\n\n#line 2 \"string/rolling-hash.hpp\"\
    \n\n#line 8 \"string/rolling-hash.hpp\"\n\n#line 2 \"modint/modint_2_61.hpp\"\n\
    \n#line 5 \"modint/modint_2_61.hpp\"\n\n// \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\
    \u30C3\u30B7\u30E5\u7528 modint\n// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class ModInt_2_61 {\n  public:\n    using M = ModInt_2_61;\n    ModInt_2_61()\
    \ : x(0) {}\n    ModInt_2_61(long long y) : x(y >= 0 ? y % mod : (mod - (-y) %\
    \ mod) % mod) {}\n    unsigned long long val() const { return x; }\n    M &operator+=(const\
    \ M &m) {\n        if((x += m.x) >= mod) x -= mod;\n        return *this;\n  \
    \  }\n    M &operator-=(const M &m) {\n        if((x += mod - m.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    M &operator*=(const M &m) {\n      \
    \  __uint128_t t = (__uint128_t)x * m.x;\n        unsigned long long na = t >>\
    \ 61;\n        unsigned long long nb = t & mod;\n        if((na += nb) >= mod)\
    \ na -= mod;\n        x = na;\n        return *this;\n    }\n    M &operator/=(const\
    \ M &m) {\n        *this *= m.inv();\n        return *this;\n    }\n    M operator-()\
    \ const { return M(-(long long)x); }\n    M operator+(const M &m) const { return\
    \ M(*this) += m; }\n    M operator-(const M &m) const { return M(*this) -= m;\
    \ }\n    M operator*(const M &m) const { return M(*this) *= m; }\n    M operator/(const\
    \ M &m) const { return M(*this) /= m; }\n    bool operator==(const M &m) const\
    \ { return (x == m.x); }\n    bool operator!=(const M &m) const { return (x !=\
    \ m.x); }\n    M inv() const {\n        long long a = x, b = mod, u = 1, v = 0,\
    \ t;\n        while(b > 0) {\n            t = a / b;\n            std::swap(a\
    \ -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ M(u);\n    }\n    M pow(unsigned long long n) const {\n        M ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const M &p) {\n        return os\
    \ << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is, M &a)\
    \ {\n        long long t;\n        is >> t;\n        a = M(t);\n        return\
    \ (is);\n    }\n    static constexpr unsigned long long get_mod() { return mod;\
    \ }\n\n  private:\n    unsigned long long x;\n    static constexpr unsigned long\
    \ long mod = (1LL << 61) - 1;\n};\n#line 10 \"string/rolling-hash.hpp\"\n\nstruct\
    \ RollingHash {\n    using u64 = unsigned long long;\n    using mint = ModInt_2_61;\n\
    \    static constexpr u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    std::vector<mint>\
    \ hashed, power;\n\n    explicit RollingHash(const std::vector<int> &v, u64 base)\
    \ : base(base) {\n        int n = (int)v.size();\n        hashed.assign(n + 1,\
    \ 0);\n        power.assign(n + 1, 0);\n        power[0] = 1;\n        for(int\
    \ i = 0; i < n; i++) {\n            power[i + 1] = power[i] * base;\n        \
    \    hashed[i + 1] = (hashed[i] * base) + v[i];\n        }\n    }\n    explicit\
    \ RollingHash(const std::string &s, u64 base) : base(base) {\n        int n =\
    \ (int)s.size();\n        hashed.assign(n + 1, 0);\n        power.assign(n + 1,\
    \ 0);\n        power[0] = 1;\n        for(int i = 0; i < n; i++) {\n         \
    \   power[i + 1] = power[i] * base;\n            hashed[i + 1] = (hashed[i] *\
    \ base) + s[i];\n        }\n    }\n    static inline u64 gen_base() {\n      \
    \  std::random_device seed_gen;\n        std::mt19937_64 engine(seed_gen());\n\
    \        std::uniform_int_distribution<u64> rand(2, mod - 2);\n        return\
    \ rand(engine);\n    }\n    mint get(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r < (int)power.size());\n        return\
    \ (hashed[r] - (hashed[l] * power[r - l]));\n    }\n    mint connect(mint h1,\
    \ mint h2, int h2len) {\n        return (h1 * power[h2len] + h2);\n    }\n   \
    \ int get_lcp(RollingHash &b, int l1, int r1, int l2, int r2) {\n        assert(mod\
    \ == b.mod);\n        int len = std::min(r1 - l1, r2 - l2);\n        int low =\
    \ -1, high = len + 1;\n        while(high - low > 1) {\n            int mid =\
    \ (low + high) >> 1;\n            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))\
    \ {\n                low = mid;\n            } else {\n                high =\
    \ mid;\n            }\n        }\n        return low;\n    }\n};\n#line 7 \"data-structure/monoid/rolling_hash.hpp\"\
    \n\ntemplate <int N> struct MonoidRollingHash {\n  public:\n    using mint = ModInt_2_61;\n\
    \    struct S {\n        mint h;\n        int len;\n        S() {}\n        S(mint\
    \ h, int len) : h(h), len(len) {}\n    };\n    using value_type = S;\n\n    static\
    \ inline S op(const S &a, const S &b) {\n        static auto [base, powers] =\
    \ gen();\n        mint h = a.h + b.h * powers[a.len];\n        int len = a.len\
    \ + b.len;\n        return S(h, len);\n    }\n    static inline S e() { return\
    \ S(0, 0); }\n\n  private:\n    static std::pair<mint, std::array<mint, N>> gen()\
    \ {\n        mint base = RollingHash::gen_base();\n        std::array<mint, N>\
    \ powers;\n        powers[0] = 1;\n        for(int i = 1; i < N; i++) powers[i]\
    \ = powers[i - 1] * base;\n        return std::make_pair(base, powers);\n    }\n\
    };\n#line 2 \"data-structure/monoid/kadane.hpp\"\n\n#line 5 \"data-structure/monoid/kadane.hpp\"\
    \n\n// ref: https://hotman78.hatenablog.com/entry/2020/06/17/102519\ntemplate\
    \ <typename T> struct MonoidKadane {\n    struct S {\n        T lmax, rmax, allmax,\
    \ sum;\n        S() = default;\n        S(T lmax, T rmax, T allmax, T sum)\n \
    \           : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}\n    };\n  \
    \  using value_type = S;\n    inline static S op(const S &l, const S &r) {\n \
    \       const T m = std::numeric_limits<T>::lowest();\n        if(l.lmax == m\
    \ && l.rmax == m && l.allmax == m && l.sum == T(0)) return r;\n        if(r.lmax\
    \ == m && r.rmax == m && r.allmax == m && r.sum == T(0)) return l;\n        T\
    \ lmax = std::max(l.lmax, l.sum + r.lmax);\n        T rmax = std::max(r.rmax,\
    \ l.rmax + r.sum);\n        T allmax = std::max({l.allmax, r.allmax, l.rmax +\
    \ r.lmax});\n        T sum = l.sum + r.sum;\n        return S(lmax, rmax, allmax,\
    \ sum);\n    }\n    inline static S e() {\n        T m = std::numeric_limits<T>::lowest();\n\
    \        return S(m, m, m, T(0));\n    }\n};\n#line 16 \"test/mytest/data-structure/monoids.test.cpp\"\
    \n\n\ntemplate<class M> void identity(typename M::value_type x) {\n    assert(M::op(M::e(),\
    \ x) == x && M::op(x, M::e()) == x);\n}\nint main() {\n    for(int a = 0; a <=\
    \ 20; ++a) for(int b = 0; b <= 20; ++b) {\n        assert(MonoidAdd<int>::op(a,\
    \ b) == a + b);\n        assert(MonoidAND<unsigned>::op(a, b) == unsigned(a &\
    \ b));\n        assert(MonoidOR<unsigned>::op(a, b) == unsigned(a | b));\n   \
    \     assert(MonoidMin<int>::op(a, b) == min(a, b));\n        assert(MonoidMax<int>::op(a,\
    \ b) == max(a, b));\n        int gcd_expected = 0;\n        for(int d = 1; d <=\
    \ max(a, b); ++d) if(a % d == 0 && b % d == 0) gcd_expected = d;\n        assert(MonoidGCD<int>::op(a,\
    \ b) == gcd_expected);\n        int lcm_expected = 0;\n        if(a && b) { lcm_expected\
    \ = 1; while(lcm_expected % a || lcm_expected % b) ++lcm_expected; }\n       \
    \ assert(MonoidLCM<int>::op(a, b) == lcm_expected);\n        identity<MonoidAdd<int>>(a);\
    \ identity<MonoidAND<unsigned>>(a);\n        identity<MonoidOR<unsigned>>(a);\
    \ identity<MonoidGCD<int>>(a);\n        identity<MonoidLCM<int>>(a); identity<MonoidMin<int>>(a);\
    \ identity<MonoidMax<int>>(a);\n        pair<int, int> x{a, 3}, y{b, 5};\n   \
    \     identity<MonoidMinWithIndex<int>>(x); identity<MonoidMaxWithIndex<int>>(x);\n\
    \        assert(MonoidMinWithIndex<int>::op(x, y) == min(x, y));\n        assert(MonoidMaxWithIndex<int>::op(x,\
    \ y) == max(x, y));\n        using Count = MonoidSumCount<ll, int>;\n        Count::S\
    \ c; c = Count::S(a, b);\n        auto combined = Count::op(c, Count::S(b, a));\n\
    \        assert(combined.sum == a + b && combined.cnt == a + b);\n        assert(Count::op(c,\
    \ Count::e()).sum == a && Count::op(Count::e(), c).cnt == b);\n    }\n    assert((MonoidMin<int,\
    \ 100>::e() == 100));\n    assert((MonoidMax<int, -100>::e() == -100));\n    assert((MonoidMinWithIndex<int,\
    \ 100>::e() == make_pair(100, -1)));\n    assert((MonoidMaxWithIndex<int, -100>::e()\
    \ == make_pair(-100, -1)));\n    for(ll a = -3; a <= 3; ++a) for(ll b = -3; b\
    \ <= 3; ++b) {\n        pair<ll, ll> f{a, b}, g{2, -1};\n        identity<MonoidAffine<ll>>(f);\
    \ identity<MonoidAffine<ll, true>>(f);\n        auto left = MonoidAffine<ll>::op(f,\
    \ g);\n        auto right = MonoidAffine<ll, true>::op(f, g);\n        for(ll\
    \ x = -3; x <= 3; ++x) {\n            assert(left.first * x + left.second == a\
    \ * (2 * x - 1) + b);\n            assert(right.first * x + right.second == 2\
    \ * (a * x + b) - 1);\n        }\n    }\n    using Hash = MonoidRollingHash<64>;\n\
    \    Hash::S h; h = Hash::e();\n    auto base = Hash::op(Hash::S(0, 1), Hash::S(1,\
    \ 1)).h;\n    Hash::mint expected = 0, power = 1;\n    for(int i = 1; i <= 30;\
    \ ++i) {\n        h = Hash::op(h, Hash::S(i, 1)); expected += power * i; power\
    \ *= base;\n        assert(h.h == expected && h.len == i);\n        assert(Hash::op(Hash::e(),\
    \ h).h == h.h && Hash::op(h, Hash::e()).h == h.h);\n    }\n    using K = MonoidKadane<ll>;\n\
    \    vector<ll> a{-7, 2, 3, -8, 9, -1};\n    for(int l = 0; l < int(a.size());\
    \ ++l) for(int r = l + 1; r <= int(a.size()); ++r) {\n        K::S x; x = K::e();\n\
    \        ll sum = 0, prefix = LLONG_MIN, suffix = LLONG_MIN, best = LLONG_MIN;\n\
    \        for(int i = l; i < r; ++i) {\n            x = K::op(x, K::S(a[i], a[i],\
    \ a[i], a[i]));\n            sum += a[i]; prefix = max(prefix, sum);\n       \
    \     ll part = 0;\n            for(int j = i; j < r; ++j) { part += a[j]; best\
    \ = max(best, part); }\n            suffix = max(suffix, part);\n        }\n \
    \       assert(x.sum == sum && x.lmax == prefix && x.rmax == suffix && x.allmax\
    \ == best);\n    }\n    INT(a0, b0); print(a0 + b0);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../data-structure/monoid/add.hpp\"\n#include \"../../../data-structure/monoid/affine.hpp\"\
    \n#include \"../../../data-structure/monoid/and.hpp\"\n#include \"../../../data-structure/monoid/or.hpp\"\
    \n#include \"../../../data-structure/monoid/gcd.hpp\"\n#include \"../../../data-structure/monoid/lcm.hpp\"\
    \n#include \"../../../data-structure/monoid/min.hpp\"\n#include \"../../../data-structure/monoid/max.hpp\"\
    \n#include \"../../../data-structure/monoid/min_index.hpp\"\n#include \"../../../data-structure/monoid/max_index.hpp\"\
    \n#include \"../../../data-structure/monoid/sum_count.hpp\"\n#include \"../../../data-structure/monoid/rolling_hash.hpp\"\
    \n#include \"../../../data-structure/monoid/kadane.hpp\"\n\n\ntemplate<class M>\
    \ void identity(typename M::value_type x) {\n    assert(M::op(M::e(), x) == x\
    \ && M::op(x, M::e()) == x);\n}\nint main() {\n    for(int a = 0; a <= 20; ++a)\
    \ for(int b = 0; b <= 20; ++b) {\n        assert(MonoidAdd<int>::op(a, b) == a\
    \ + b);\n        assert(MonoidAND<unsigned>::op(a, b) == unsigned(a & b));\n \
    \       assert(MonoidOR<unsigned>::op(a, b) == unsigned(a | b));\n        assert(MonoidMin<int>::op(a,\
    \ b) == min(a, b));\n        assert(MonoidMax<int>::op(a, b) == max(a, b));\n\
    \        int gcd_expected = 0;\n        for(int d = 1; d <= max(a, b); ++d) if(a\
    \ % d == 0 && b % d == 0) gcd_expected = d;\n        assert(MonoidGCD<int>::op(a,\
    \ b) == gcd_expected);\n        int lcm_expected = 0;\n        if(a && b) { lcm_expected\
    \ = 1; while(lcm_expected % a || lcm_expected % b) ++lcm_expected; }\n       \
    \ assert(MonoidLCM<int>::op(a, b) == lcm_expected);\n        identity<MonoidAdd<int>>(a);\
    \ identity<MonoidAND<unsigned>>(a);\n        identity<MonoidOR<unsigned>>(a);\
    \ identity<MonoidGCD<int>>(a);\n        identity<MonoidLCM<int>>(a); identity<MonoidMin<int>>(a);\
    \ identity<MonoidMax<int>>(a);\n        pair<int, int> x{a, 3}, y{b, 5};\n   \
    \     identity<MonoidMinWithIndex<int>>(x); identity<MonoidMaxWithIndex<int>>(x);\n\
    \        assert(MonoidMinWithIndex<int>::op(x, y) == min(x, y));\n        assert(MonoidMaxWithIndex<int>::op(x,\
    \ y) == max(x, y));\n        using Count = MonoidSumCount<ll, int>;\n        Count::S\
    \ c; c = Count::S(a, b);\n        auto combined = Count::op(c, Count::S(b, a));\n\
    \        assert(combined.sum == a + b && combined.cnt == a + b);\n        assert(Count::op(c,\
    \ Count::e()).sum == a && Count::op(Count::e(), c).cnt == b);\n    }\n    assert((MonoidMin<int,\
    \ 100>::e() == 100));\n    assert((MonoidMax<int, -100>::e() == -100));\n    assert((MonoidMinWithIndex<int,\
    \ 100>::e() == make_pair(100, -1)));\n    assert((MonoidMaxWithIndex<int, -100>::e()\
    \ == make_pair(-100, -1)));\n    for(ll a = -3; a <= 3; ++a) for(ll b = -3; b\
    \ <= 3; ++b) {\n        pair<ll, ll> f{a, b}, g{2, -1};\n        identity<MonoidAffine<ll>>(f);\
    \ identity<MonoidAffine<ll, true>>(f);\n        auto left = MonoidAffine<ll>::op(f,\
    \ g);\n        auto right = MonoidAffine<ll, true>::op(f, g);\n        for(ll\
    \ x = -3; x <= 3; ++x) {\n            assert(left.first * x + left.second == a\
    \ * (2 * x - 1) + b);\n            assert(right.first * x + right.second == 2\
    \ * (a * x + b) - 1);\n        }\n    }\n    using Hash = MonoidRollingHash<64>;\n\
    \    Hash::S h; h = Hash::e();\n    auto base = Hash::op(Hash::S(0, 1), Hash::S(1,\
    \ 1)).h;\n    Hash::mint expected = 0, power = 1;\n    for(int i = 1; i <= 30;\
    \ ++i) {\n        h = Hash::op(h, Hash::S(i, 1)); expected += power * i; power\
    \ *= base;\n        assert(h.h == expected && h.len == i);\n        assert(Hash::op(Hash::e(),\
    \ h).h == h.h && Hash::op(h, Hash::e()).h == h.h);\n    }\n    using K = MonoidKadane<ll>;\n\
    \    vector<ll> a{-7, 2, 3, -8, 9, -1};\n    for(int l = 0; l < int(a.size());\
    \ ++l) for(int r = l + 1; r <= int(a.size()); ++r) {\n        K::S x; x = K::e();\n\
    \        ll sum = 0, prefix = LLONG_MIN, suffix = LLONG_MIN, best = LLONG_MIN;\n\
    \        for(int i = l; i < r; ++i) {\n            x = K::op(x, K::S(a[i], a[i],\
    \ a[i], a[i]));\n            sum += a[i]; prefix = max(prefix, sum);\n       \
    \     ll part = 0;\n            for(int j = i; j < r; ++j) { part += a[j]; best\
    \ = max(best, part); }\n            suffix = max(suffix, part);\n        }\n \
    \       assert(x.sum == sum && x.lmax == prefix && x.rmax == suffix && x.allmax\
    \ == best);\n    }\n    INT(a0, b0); print(a0 + b0);\n}\n"
  dependsOn:
  - template/template.cpp
  - data-structure/monoid/add.hpp
  - data-structure/monoid/affine.hpp
  - data-structure/monoid/and.hpp
  - data-structure/monoid/or.hpp
  - data-structure/monoid/gcd.hpp
  - data-structure/monoid/lcm.hpp
  - data-structure/monoid/min.hpp
  - data-structure/monoid/max.hpp
  - data-structure/monoid/min_index.hpp
  - data-structure/monoid/max_index.hpp
  - data-structure/monoid/sum_count.hpp
  - data-structure/monoid/rolling_hash.hpp
  - string/rolling-hash.hpp
  - modint/modint_2_61.hpp
  - data-structure/monoid/kadane.hpp
  isVerificationFile: true
  path: test/mytest/data-structure/monoids.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:12:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/data-structure/monoids.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/data-structure/monoids.test.cpp
- /verify/test/mytest/data-structure/monoids.test.cpp.html
title: test/mytest/data-structure/monoids.test.cpp
---
