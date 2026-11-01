---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binom.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "\u884C\u5217"
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
  bundledCode: "#line 1 \"test/mytest/math/matrix-binom.test.cpp\"\n#define PROBLEM\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"math/matrix.hpp\"\n\n\
    #line 7 \"math/matrix.hpp\"\n\ntemplate <typename T> class Matrix {\n  public:\n\
    \    Matrix() {}\n    explicit Matrix(int n) : Matrix(n, n) {}\n    explicit Matrix(int\
    \ n, int m) : dat(n, std::vector<T>(m)) {}\n    std::size_t height() const { return\
    \ dat.size(); }\n    std::size_t width() const { return dat[0].size(); }\n   \
    \ const std::vector<T> &operator[](int k) const { return dat[k]; }\n    std::vector<T>\
    \ &operator[](int k) { return dat[k]; }\n    static inline Matrix I(int n) {\n\
    \        Matrix ret(n);\n        for(int i = 0; i < n; i++) ret[i][i] = T(1);\n\
    \        return ret;\n    }\n    Matrix &operator+=(const Matrix &other) {\n \
    \       std::size_t n = height(), m = width();\n        assert(n == other.height()\
    \ && m == other.width());\n        for(std::size_t i = 0; i < n; i++) {\n    \
    \        for(std::size_t j = 0; j < m; j++) { (*this)[i][j] += other[i][j]; }\n\
    \        }\n        return (*this);\n    }\n    Matrix &operator-=(const Matrix\
    \ &other) {\n        std::size_t n = height(), m = width();\n        assert(n\
    \ == other.height() && m == other.width());\n        for(std::size_t i = 0; i\
    \ < n; i++) {\n            for(std::size_t j = 0; j < m; j++) { (*this)[i][j]\
    \ -= other[i][j]; }\n        }\n        return (*this);\n    }\n    Matrix &operator*=(const\
    \ Matrix &other) {\n        std::size_t n = height(), m2 = width();\n        std::size_t\
    \ m = other.width();\n        assert(m2 == other.height());\n        std::vector\
    \ res(n, std::vector<T>(m));\n        for(std::size_t i = 0; i < n; i++) {\n \
    \           for(std::size_t j = 0; j < m; j++) {\n                T sum = 0;\n\
    \                for(std::size_t k = 0; k < m2; k++) {\n                    sum\
    \ += (*this)[i][k] * other[k][j];\n                }\n                res[i][j]\
    \ = sum;\n            }\n        }\n        this->dat.swap(res);\n        return\
    \ (*this);\n    }\n    Matrix operator+(const Matrix &other) const {\n       \
    \ return (Matrix(*this) += other);\n    }\n    Matrix operator-(const Matrix &other)\
    \ const {\n        return (Matrix(*this) -= other);\n    }\n    Matrix operator*(const\
    \ Matrix &other) const {\n        return (Matrix(*this) *= other);\n    }\n  \
    \  Matrix pow(long long k) const {\n        Matrix res = Matrix::I(height()),\
    \ mul = (*this);\n        while(k > 0) {\n            if(k & 1) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n  private:\n    std::vector<std::vector<T>> dat;\n};\n#line 2 \"math/binom.hpp\"\
    \n\n#line 6 \"math/binom.hpp\"\n\ntemplate <class mint> class Binomial {\n  public:\n\
    \    explicit Binomial(): Binomial(1) {}\n    explicit Binomial(int MAX) : f(MAX,\
    \ mint(1)), f_inv(MAX, mint(1)) {\n        for(int i = 1; i < MAX; i++) f[i] =\
    \ f[i-1] * mint(i);\n        f_inv[MAX - 1] = f[MAX - 1].inv();\n        for(int\
    \ i = MAX - 2; i >= 1; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i +\
    \ 1);\n        } \n    }\n    void extend() {\n        int n = (int)f.size();\n\
    \        f.resize(n * 2);\n        f_inv.resize(n * 2);\n        for(int i = n;\
    \ i < n * 2; i++) f[i] = f[i - 1] * mint(i);\n        f_inv[n * 2 - 1] = f[n *\
    \ 2 - 1].inv();\n        for(int i = n * 2 - 2; i >= n; i--) {\n            f_inv[i]\
    \ = f_inv[i + 1] * mint(i + 1);\n        }\n    }\n    mint fac(int n) {\n   \
    \     if(n < 0) return mint(0);\n        while(n >= (int)f.size()) extend();\n\
    \        return f[n];\n    }\n    mint fac_inv(int n) {\n        if(n < 0) return\
    \ mint(0);\n        while(n >= (int)f_inv.size()) extend();\n        return f_inv[n];\n\
    \    }\n    mint inv(int n) {\n        if(n < 0) return mint(n).inv();\n     \
    \   assert(n != 0);\n        while(n >= (int)f_inv.size()) extend();\n       \
    \ return (f_inv[n] * f[n - 1]);\n    }\n    mint binom(int n, int k) {\n     \
    \   if(n < k || n < 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(k)\
    \ * fac_inv(n - k));\n    }\n    mint binom_naive(long long n, long long k) {\n\
    \        if(n < k || n < 0 || k < 0) return mint(0);\n        mint res(1);\n \
    \       k = std::min(k, n - k);\n        for(int i = 0; i < k; i++) res *= inv(i\
    \ + 1) * mint(n - i);\n        return res;\n    }\n    mint perm(int n, int k)\
    \ {\n        if(n < k || n < 0 || k < 0) return mint(0);\n        return (fac(n)\
    \ * fac_inv(n - k));\n    }\n    mint hom(int n, int k) {\n        if(n < 0 ||\
    \ k < 0) return mint(0);\n        return (k == 0 ? mint(1) : binom(n + k - 1,\
    \ k));\n    }\n\n  private:\n    std::vector<mint> f, f_inv;\n};\n#line 2 \"modint/modint.hpp\"\
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
    \    static constexpr unsigned int umod() { return mod; }\n};\n#line 6 \"test/mytest/math/matrix-binom.test.cpp\"\
    \n\n\nint main() {\n    using mint = ModInt<1000000007>;\n    Binomial<mint> binom,\
    \ precomputed(64);\n    binom.extend();\n    vector<vector<ll>> choose(31, vector<ll>(31));\n\
    \    for(int n = 0; n <= 30; ++n) {\n        choose[n][0] = 1;\n        for(int\
    \ k = 1; k <= n; ++k) choose[n][k] = (choose[n - 1][k - 1] + choose[n - 1][k])\
    \ % 1000000007;\n    }\n    mint factorial = 1;\n    for(int n = 0; n <= 30; ++n)\
    \ {\n        if(n) factorial *= mint(n);\n        assert(binom.fac(n) == factorial\
    \ && precomputed.fac(n) == factorial);\n        assert(binom.fac_inv(n) * factorial\
    \ == mint(1));\n        if(n) assert(binom.inv(n) * mint(n) == mint(1));\n   \
    \     for(int k = -1; k <= n + 1; ++k) {\n            mint expected = 0;\n   \
    \         if(0 <= k && k <= n) expected = choose[n][k];\n            assert(binom.binom(n,\
    \ k) == expected && binom.binom_naive(n, k) == expected);\n            mint permutations\
    \ = 0;\n            if(0 <= k && k <= n) { permutations = 1; for(int i = 0; i\
    \ < k; ++i) permutations *= mint(n - i); }\n            assert(binom.perm(n, k)\
    \ == permutations);\n        }\n        for(int k = 0; k <= 10 && n + k <= 30;\
    \ ++k) {\n            mint expected = k == 0 ? 1 : (n == 0 ? 0 : choose[n + k\
    \ - 1][k]);\n            assert(binom.hom(n, k) == expected);\n        }\n   \
    \ }\n    assert(binom.fac(-1) == mint(0) && binom.fac_inv(-1) == mint(0));\n \
    \   assert(binom.inv(-3) * mint(-3) == mint(1));\n    assert(binom.binom(-1, 0)\
    \ == mint(0) && binom.binom_naive(-1, 0) == mint(0));\n    assert(binom.perm(-1,\
    \ 0) == mint(0) && binom.hom(-1, 0) == mint(0));\n    assert(binom.binom_naive(1000000000LL,\
    \ 2) == mint(1000000000LL) * mint(999999999) / mint(2));\n    mt19937 rng(53);\n\
    \    for(int n = 1; n <= 5; ++n) for(int m = 1; m <= 5; ++m) {\n        Matrix<ll>\
    \ a, b(n, m);\n        assert(a.height() == 0);\n        a = Matrix<ll>(n, m);\n\
    \        assert(a.height() == unsigned(n) && a.width() == unsigned(m));\n    \
    \    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {\n            assert(a[i][j]\
    \ == 0);\n            a[i][j] = int(rng() % 9) - 4; b[i][j] = int(rng() % 9) -\
    \ 4;\n        }\n        const auto& ca = a;\n        auto sum = ca + b, diff\
    \ = ca - b, inplace = a;\n        assert(&(inplace += b) == &inplace);\n     \
    \   for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {\n            assert(sum[i][j]\
    \ == ca[i][j] + b[i][j] && inplace[i][j] == sum[i][j]);\n            assert(diff[i][j]\
    \ == ca[i][j] - b[i][j]);\n        }\n        assert(&(inplace -= b) == &inplace);\n\
    \        Matrix<ll> right(m, 3);\n        for(int i = 0; i < m; ++i) for(int j\
    \ = 0; j < 3; ++j) right[i][j] = i - j;\n        auto product = ca * right;\n\
    \        inplace = a; assert(&(inplace *= right) == &inplace);\n        for(int\
    \ i = 0; i < n; ++i) for(int j = 0; j < 3; ++j) {\n            ll expected = 0;\n\
    \            for(int k = 0; k < m; ++k) expected += a[i][k] * right[k][j];\n \
    \           assert(product[i][j] == expected && inplace[i][j] == expected);\n\
    \        }\n    }\n    Matrix<ll> fib(2); fib[0][0] = fib[0][1] = fib[1][0] =\
    \ 1;\n    auto expected = Matrix<ll>::I(2);\n    for(int k = 0; k <= 30; ++k)\
    \ {\n        auto power = fib.pow(k);\n        for(int i = 0; i < 2; ++i) for(int\
    \ j = 0; j < 2; ++j) assert(power[i][j] == expected[i][j]);\n        expected\
    \ *= fib;\n    }\n    INT(a, b); print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../math/matrix.hpp\"\n#include \"../../../math/binom.hpp\"\n\
    #include \"../../../modint/modint.hpp\"\n\n\nint main() {\n    using mint = ModInt<1000000007>;\n\
    \    Binomial<mint> binom, precomputed(64);\n    binom.extend();\n    vector<vector<ll>>\
    \ choose(31, vector<ll>(31));\n    for(int n = 0; n <= 30; ++n) {\n        choose[n][0]\
    \ = 1;\n        for(int k = 1; k <= n; ++k) choose[n][k] = (choose[n - 1][k -\
    \ 1] + choose[n - 1][k]) % 1000000007;\n    }\n    mint factorial = 1;\n    for(int\
    \ n = 0; n <= 30; ++n) {\n        if(n) factorial *= mint(n);\n        assert(binom.fac(n)\
    \ == factorial && precomputed.fac(n) == factorial);\n        assert(binom.fac_inv(n)\
    \ * factorial == mint(1));\n        if(n) assert(binom.inv(n) * mint(n) == mint(1));\n\
    \        for(int k = -1; k <= n + 1; ++k) {\n            mint expected = 0;\n\
    \            if(0 <= k && k <= n) expected = choose[n][k];\n            assert(binom.binom(n,\
    \ k) == expected && binom.binom_naive(n, k) == expected);\n            mint permutations\
    \ = 0;\n            if(0 <= k && k <= n) { permutations = 1; for(int i = 0; i\
    \ < k; ++i) permutations *= mint(n - i); }\n            assert(binom.perm(n, k)\
    \ == permutations);\n        }\n        for(int k = 0; k <= 10 && n + k <= 30;\
    \ ++k) {\n            mint expected = k == 0 ? 1 : (n == 0 ? 0 : choose[n + k\
    \ - 1][k]);\n            assert(binom.hom(n, k) == expected);\n        }\n   \
    \ }\n    assert(binom.fac(-1) == mint(0) && binom.fac_inv(-1) == mint(0));\n \
    \   assert(binom.inv(-3) * mint(-3) == mint(1));\n    assert(binom.binom(-1, 0)\
    \ == mint(0) && binom.binom_naive(-1, 0) == mint(0));\n    assert(binom.perm(-1,\
    \ 0) == mint(0) && binom.hom(-1, 0) == mint(0));\n    assert(binom.binom_naive(1000000000LL,\
    \ 2) == mint(1000000000LL) * mint(999999999) / mint(2));\n    mt19937 rng(53);\n\
    \    for(int n = 1; n <= 5; ++n) for(int m = 1; m <= 5; ++m) {\n        Matrix<ll>\
    \ a, b(n, m);\n        assert(a.height() == 0);\n        a = Matrix<ll>(n, m);\n\
    \        assert(a.height() == unsigned(n) && a.width() == unsigned(m));\n    \
    \    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {\n            assert(a[i][j]\
    \ == 0);\n            a[i][j] = int(rng() % 9) - 4; b[i][j] = int(rng() % 9) -\
    \ 4;\n        }\n        const auto& ca = a;\n        auto sum = ca + b, diff\
    \ = ca - b, inplace = a;\n        assert(&(inplace += b) == &inplace);\n     \
    \   for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {\n            assert(sum[i][j]\
    \ == ca[i][j] + b[i][j] && inplace[i][j] == sum[i][j]);\n            assert(diff[i][j]\
    \ == ca[i][j] - b[i][j]);\n        }\n        assert(&(inplace -= b) == &inplace);\n\
    \        Matrix<ll> right(m, 3);\n        for(int i = 0; i < m; ++i) for(int j\
    \ = 0; j < 3; ++j) right[i][j] = i - j;\n        auto product = ca * right;\n\
    \        inplace = a; assert(&(inplace *= right) == &inplace);\n        for(int\
    \ i = 0; i < n; ++i) for(int j = 0; j < 3; ++j) {\n            ll expected = 0;\n\
    \            for(int k = 0; k < m; ++k) expected += a[i][k] * right[k][j];\n \
    \           assert(product[i][j] == expected && inplace[i][j] == expected);\n\
    \        }\n    }\n    Matrix<ll> fib(2); fib[0][0] = fib[0][1] = fib[1][0] =\
    \ 1;\n    auto expected = Matrix<ll>::I(2);\n    for(int k = 0; k <= 30; ++k)\
    \ {\n        auto power = fib.pow(k);\n        for(int i = 0; i < 2; ++i) for(int\
    \ j = 0; j < 2; ++j) assert(power[i][j] == expected[i][j]);\n        expected\
    \ *= fib;\n    }\n    INT(a, b); print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - math/matrix.hpp
  - math/binom.hpp
  - modint/modint.hpp
  isVerificationFile: true
  path: test/mytest/math/matrix-binom.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:12:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/math/matrix-binom.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/math/matrix-binom.test.cpp
- /verify/test/mytest/math/matrix-binom.test.cpp.html
title: test/mytest/math/matrix-binom.test.cpp
---
