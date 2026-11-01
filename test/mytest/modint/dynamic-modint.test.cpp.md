---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/barrett-reduction.hpp
    title: Barrett Reduction
  - icon: ':question:'
    path: modint/dynamic-modint.hpp
    title: "\u52D5\u7684\u6CD5 modint"
  - icon: ':question:'
    path: modint/modint.hpp
    title: "\u56FA\u5B9A\u6CD5 modint"
  - icon: ':x:'
    path: modint/modint_2_61.hpp
    title: "\u6CD5 2^61-1 \u306E modint"
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
  bundledCode: "#line 1 \"test/mytest/modint/dynamic-modint.test.cpp\"\n#define PROBLEM\
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
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"modint/dynamic-modint.hpp\"\
    \n\n#line 6 \"modint/dynamic-modint.hpp\"\n\n#line 2 \"math/barrett-reduction.hpp\"\
    \n\n#line 4 \"math/barrett-reduction.hpp\"\n\nclass BarrettReduction {\npublic:\n\
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
    };\n#line 8 \"modint/dynamic-modint.hpp\"\n\n// verify: https://atcoder.jp/contests/arc104/submissions/38888866\n\
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
    \ int mod;\n    static inline BarrettReduction bt;\n};\n#line 2 \"modint/modint.hpp\"\
    \n\n#line 6 \"modint/modint.hpp\"\n\ntemplate <int mod> class ModInt {\n  public:\n\
    \    ModInt() : x(0) {}\n    ModInt(long long y)\n        : x(y >= 0 ? y % umod()\
    \ : (umod() - (-y) % umod()) % umod()) {}\n    unsigned int val() const { return\
    \ x; }\n    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= umod())\
    \ x -= umod();\n        return *this;\n    }\n    ModInt &operator-=(const ModInt\
    \ &p) {\n        if((x += umod() - p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n        x = (unsigned\
    \ int)(1ULL * x * p.x % umod());\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt\
    \ operator-() const { return ModInt(-(long long)x); }\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {\n        long long a = x, b = mod,\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n       \
    \ }\n        return ModInt(u);\n    }\n    ModInt pow(unsigned long long n) const\
    \ {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n            if(n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, ModInt &a) {\n        long long t;\n        is\
    \ >> t;\n        a = ModInt<mod>(t);\n        return (is);\n    }\n    static\
    \ constexpr int get_mod() { return mod; }\n\n  private:\n    unsigned int x;\n\
    \    static constexpr unsigned int umod() { return mod; }\n};\n#line 2 \"modint/modint_2_61.hpp\"\
    \n\n#line 5 \"modint/modint_2_61.hpp\"\n\n// \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\
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
    \ long mod = (1LL << 61) - 1;\n};\n#line 6 \"test/mytest/modint/dynamic-modint.test.cpp\"\
    \n\ntemplate<class mint> void check(ll mod) {\n    auto value = [](const mint\
    \ &x) { return static_cast<ll>(x.val()); };\n    mt19937_64 rng(20261106);\n \
    \   {\n        assert(mint::get_mod() == mod && value(mint()) == 0);\n       \
    \ auto normalize = [mod](ll x) { return (x % mod + mod) % mod; };\n        for(ll\
    \ x : {0LL, 1LL, -1LL, mod - 1, mod, -mod, LLONG_MAX, -LLONG_MAX}) {\n       \
    \     assert(value(mint(x)) == normalize(x));\n        }\n        for(int trial\
    \ = 0; trial < 500; ++trial) {\n            ll a = rng() % mod, b = rng() % mod;\n\
    \            mint x(a), y(b);\n            assert(value(x + y) == (a + b) % mod);\n\
    \            assert(value(x - y) == normalize(a - b));\n            assert(value(x\
    \ * y) == (__int128)a * b % mod);\n            assert(value(-x) == normalize(-a));\n\
    \            assert((x == y) == (a == b) && (x != y) == (a != b));\n         \
    \   mint copy = x;\n            assert(&(copy += y) == &copy && copy == x + y);\n\
    \            copy = x;\n            assert(&(copy -= y) == &copy && copy == x\
    \ - y);\n            copy = x;\n            assert(&(copy *= y) == &copy && copy\
    \ == x * y);\n            assert(value(x) == a && value(y) == b);\n          \
    \  ll expected = 1;\n            for(int exponent = 0; exponent < 20; ++exponent)\
    \ {\n                assert(value(x.pow(exponent)) == expected);\n           \
    \     expected = (__int128)expected * a % mod;\n            }\n            if(gcd(b,\
    \ mod) == 1) {\n                // The inverse is characterized by b * inv(b)\
    \ == 1 mod m.\n                assert((__int128)y.inv().val() * b % mod == 1);\n\
    \                assert((x / y * y) == x);\n                copy = x;\n      \
    \          assert(&(copy /= y) == &copy && copy == x / y);\n            }\n  \
    \      }\n        assert(value(mint(1).pow(LLONG_MAX)) == 1);\n        stringstream\
    \ stream;\n        stream << mint(-1) << ' ' << mint(0);\n        assert(stream.str()\
    \ == to_string(mod - 1) + \" 0\");\n        mint x, y;\n        stream >> x >>\
    \ y;\n        assert(value(x) == mod - 1 && value(y) == 0);\n        stringstream\
    \ negative(\"-123456789012345\");\n        negative >> x;\n        assert(value(x)\
    \ == normalize(-123456789012345LL));\n    }\n}\n\nint main() {\n    for(ll mod\
    \ : {2LL, 4LL, 7LL, 12LL, 998244353LL, 1000000007LL, 2147483647LL}) {\n      \
    \  DynamicModInt::set_mod(mod);\n        check<DynamicModInt>(mod);\n    }\n \
    \   check<ModInt<7>>(7);\n    check<ModInt<12>>(12);\n    check<ModInt<998244353>>(998244353);\n\
    \    check<ModInt_2_61>((1LL << 61) - 1);\n    INT(a, b); print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../modint/dynamic-modint.hpp\"\n#include \"../../../modint/modint.hpp\"\
    \n#include \"../../../modint/modint_2_61.hpp\"\n\ntemplate<class mint> void check(ll\
    \ mod) {\n    auto value = [](const mint &x) { return static_cast<ll>(x.val());\
    \ };\n    mt19937_64 rng(20261106);\n    {\n        assert(mint::get_mod() ==\
    \ mod && value(mint()) == 0);\n        auto normalize = [mod](ll x) { return (x\
    \ % mod + mod) % mod; };\n        for(ll x : {0LL, 1LL, -1LL, mod - 1, mod, -mod,\
    \ LLONG_MAX, -LLONG_MAX}) {\n            assert(value(mint(x)) == normalize(x));\n\
    \        }\n        for(int trial = 0; trial < 500; ++trial) {\n            ll\
    \ a = rng() % mod, b = rng() % mod;\n            mint x(a), y(b);\n          \
    \  assert(value(x + y) == (a + b) % mod);\n            assert(value(x - y) ==\
    \ normalize(a - b));\n            assert(value(x * y) == (__int128)a * b % mod);\n\
    \            assert(value(-x) == normalize(-a));\n            assert((x == y)\
    \ == (a == b) && (x != y) == (a != b));\n            mint copy = x;\n        \
    \    assert(&(copy += y) == &copy && copy == x + y);\n            copy = x;\n\
    \            assert(&(copy -= y) == &copy && copy == x - y);\n            copy\
    \ = x;\n            assert(&(copy *= y) == &copy && copy == x * y);\n        \
    \    assert(value(x) == a && value(y) == b);\n            ll expected = 1;\n \
    \           for(int exponent = 0; exponent < 20; ++exponent) {\n             \
    \   assert(value(x.pow(exponent)) == expected);\n                expected = (__int128)expected\
    \ * a % mod;\n            }\n            if(gcd(b, mod) == 1) {\n            \
    \    // The inverse is characterized by b * inv(b) == 1 mod m.\n             \
    \   assert((__int128)y.inv().val() * b % mod == 1);\n                assert((x\
    \ / y * y) == x);\n                copy = x;\n                assert(&(copy /=\
    \ y) == &copy && copy == x / y);\n            }\n        }\n        assert(value(mint(1).pow(LLONG_MAX))\
    \ == 1);\n        stringstream stream;\n        stream << mint(-1) << ' ' << mint(0);\n\
    \        assert(stream.str() == to_string(mod - 1) + \" 0\");\n        mint x,\
    \ y;\n        stream >> x >> y;\n        assert(value(x) == mod - 1 && value(y)\
    \ == 0);\n        stringstream negative(\"-123456789012345\");\n        negative\
    \ >> x;\n        assert(value(x) == normalize(-123456789012345LL));\n    }\n}\n\
    \nint main() {\n    for(ll mod : {2LL, 4LL, 7LL, 12LL, 998244353LL, 1000000007LL,\
    \ 2147483647LL}) {\n        DynamicModInt::set_mod(mod);\n        check<DynamicModInt>(mod);\n\
    \    }\n    check<ModInt<7>>(7);\n    check<ModInt<12>>(12);\n    check<ModInt<998244353>>(998244353);\n\
    \    check<ModInt_2_61>((1LL << 61) - 1);\n    INT(a, b); print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - modint/dynamic-modint.hpp
  - math/barrett-reduction.hpp
  - modint/modint.hpp
  - modint/modint_2_61.hpp
  isVerificationFile: true
  path: test/mytest/modint/dynamic-modint.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:39:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/modint/dynamic-modint.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/modint/dynamic-modint.test.cpp
- /verify/test/mytest/modint/dynamic-modint.test.cpp.html
title: test/mytest/modint/dynamic-modint.test.cpp
---
