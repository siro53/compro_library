---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/affine.hpp
    title: data-structure/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library-checker/data-structure/point-set-range-composite.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ dim>(s, e);\n}\n#pragma endregion Macros\n#line 2 \"modint/modint.hpp\"\n\n\
    #line 6 \"modint/modint.hpp\"\n\ntemplate <int mod> class ModInt {\n  public:\n\
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
    \    static constexpr unsigned int umod() { return mod; }\n};\n#line 2 \"data-structure/monoid/affine.hpp\"\
    \n\n#line 4 \"data-structure/monoid/affine.hpp\"\n\ntemplate <typename T, bool\
    \ rev = false> struct MonoidAffine {\n    using S = std::pair<T, T>;\n    using\
    \ value_type = S;\n    inline static S op(const S &l, const S &r) {\n        if(rev)\
    \ return S(r.first * l.first, r.first * l.second + r.second);\n        return\
    \ S(l.first * r.first, l.first * r.second + l.second);\n    }\n    inline static\
    \ S e() { return S(T(1), T(0)); }\n};\n#line 2 \"data-structure/segtree/segtree.hpp\"\
    \n\n#line 5 \"data-structure/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\
    \ class Segtree {\n  public:\n    using T = typename Monoid::value_type;\n\n \
    \   Segtree() : Segtree(0) {}\n    explicit Segtree(int n) : Segtree(std::vector<T>(n,\
    \ Monoid::e())) {}\n    explicit Segtree(const std::vector<T> &v) : N((int)v.size()),\
    \ sz(1) {\n        while(sz < N) sz <<= 1;\n        node.resize(sz * 2, Monoid::e());\n\
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
    \ private:\n    int N, sz;\n    std::vector<T> node;\n};\n#line 6 \"test/library-checker/data-structure/point-set-range-composite.cpp\"\
    \n\nusing mint = ModInt<MOD2>;\n\nint main() {\n    int N, Q;\n    cin >> N >>\
    \ Q;\n    vector<pair<mint, mint>> v(N);\n    REP(i, N) {\n        int a, b;\n\
    \        cin >> a >> b;\n        v[i] = {a, b};\n    }\n    Segtree<MonoidAffine<mint>>\
    \ seg(v);\n    while(Q--) {\n        int t;\n        cin >> t;\n        if(t ==\
    \ 0) {\n            int p, c, d;\n            cin >> p >> c >> d;\n          \
    \  seg.set(p, pair<mint, mint>(c, d));\n        } else {\n            int l, r,\
    \ x;\n            cin >> l >> r >> x;\n            auto [a, b] = seg.prod(l, r);\n\
    \            cout << (a * x + b) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../../../template/template.cpp\"\n#include \"../../../modint/modint.hpp\"\
    \n#include \"../../../data-structure/monoid/affine.hpp\"\n#include \"../../../data-structure/segtree/segtree.hpp\"\
    \n\nusing mint = ModInt<MOD2>;\n\nint main() {\n    int N, Q;\n    cin >> N >>\
    \ Q;\n    vector<pair<mint, mint>> v(N);\n    REP(i, N) {\n        int a, b;\n\
    \        cin >> a >> b;\n        v[i] = {a, b};\n    }\n    Segtree<MonoidAffine<mint>>\
    \ seg(v);\n    while(Q--) {\n        int t;\n        cin >> t;\n        if(t ==\
    \ 0) {\n            int p, c, d;\n            cin >> p >> c >> d;\n          \
    \  seg.set(p, pair<mint, mint>(c, d));\n        } else {\n            int l, r,\
    \ x;\n            cin >> l >> r >> x;\n            auto [a, b] = seg.prod(l, r);\n\
    \            cout << (a * x + b) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - modint/modint.hpp
  - data-structure/monoid/affine.hpp
  - data-structure/segtree/segtree.hpp
  isVerificationFile: false
  path: test/library-checker/data-structure/point-set-range-composite.cpp
  requiredBy: []
  timestamp: '2023-12-13 04:53:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/library-checker/data-structure/point-set-range-composite.cpp
layout: document
redirect_from:
- /library/test/library-checker/data-structure/point-set-range-composite.cpp
- /library/test/library-checker/data-structure/point-set-range-composite.cpp.html
title: test/library-checker/data-structure/point-set-range-composite.cpp
---
