---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/slope-trick.hpp
    title: Slope Trick
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
  bundledCode: "#line 1 \"test/mytest/data-structure/slope-trick.test.cpp\"\n#define\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"data-structure/slope-trick.hpp\"\
    \n\n#line 11 \"data-structure/slope-trick.hpp\"\n\n// ref: https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    template <typename T> struct SlopeTrick {\n    const T inf = std::numeric_limits<T>::max()\
    \ / 3;\n\n    T min_f, add_L, add_R;\n    std::priority_queue<T> L;\n    std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> R;\n\n  private:\n    void push_L(T a) { L.push(a\
    \ - add_L); }\n    T top_L() const {\n        if(L.empty()) return -inf;\n   \
    \     return L.top() + add_L;\n    }\n    T pop_L() {\n        T ret = top_L();\n\
    \        if(!L.empty()) L.pop();\n        return ret;\n    }\n    void push_R(T\
    \ a) { R.push(a - add_R); }\n    T top_R() const {\n        if(R.empty()) return\
    \ inf;\n        return R.top() + add_R;\n    }\n    T pop_R() {\n        T ret\
    \ = top_R();\n        if(!R.empty()) R.pop();\n        return ret;\n    }\n\n\
    \  public:\n    SlopeTrick() : min_f(0), add_L(0), add_R(0) {}\n    T get_min()\
    \ const { return min_f; }\n    std::tuple<T, T, T> get_min_lr() const { return\
    \ {min_f, top_L(), top_R()}; }\n    // \u5B9A\u6570\u95A2\u6570 f(x) = a \u3092\
    \u8FFD\u52A0\n    void add_const(T a) { min_f += a; }\n    // f(x) = (x - a)+\
    \ \u3092\u8FFD\u52A0\n    void add_right(T a) {\n        min_f += std::max(top_L()\
    \ - a, T(0));\n        push_L(a);\n        T t = pop_L();\n        push_R(t);\n\
    \    }\n    // f(x) = (a - x)+ \u3092\u8FFD\u52A0\n    void add_left(T a) {\n\
    \        min_f += std::max(a - top_R(), T(0));\n        push_R(a);\n        T\
    \ t = pop_R();\n        push_L(t);\n    }\n    // f(x) = |x - a| = (x - a)+ +\
    \ (a - x)+ \u3092\u8FFD\u52A0\n    void add_abs(T a) {\n        add_left(a);\n\
    \        add_right(a);\n    }\n    // (\u5DE6\u5074)\u7D2F\u7A4Dmin\n    // g(x)\
    \ := min_{y <= x} f(y) \u306A\u308B g \u306B\u5909\u66F4\n    void clear_right()\
    \ {\n        while(!R.empty()) R.pop();\n    }\n    // (\u53F3\u5074)\u7D2F\u7A4D\
    min\n    // g(x) := min_{y >= x} f(y) \u306A\u308B g \u306B\u5909\u66F4\n    void\
    \ clear_left() {\n        while(!L.empty()) L.pop();\n    }\n    // \u30B9\u30E9\
    \u30A4\u30C9\u6700\u5C0F\u5024\u95A2\u6570\n    // g(x) := min_{x - b <= y <=\
    \ x - a} f(y) (a <= b) \u306A\u308B g \u306B\u5909\u66F4\n    void shift(T a,\
    \ T b) {\n        assert(a <= b);\n        add_L += a;\n        add_R += b;\n\
    \    }\n    // \u5E73\u884C\u79FB\u52D5\n    // g(x) := f(x - a) \u306A\u308B\
    \ g \u306B\u5909\u66F4\n    void shift(T a) { shift(a, a); }\n    size_t size()\
    \ const { return L.size() + R.size(); }\n    void swap(SlopeTrick& rhs) {\n  \
    \      std::swap(min_f, rhs.min_f);\n        std::swap(add_L, rhs.add_L);\n  \
    \      std::swap(add_R, rhs.add_R);\n        std::swap(L, rhs.L);\n        std::swap(R,\
    \ rhs.R);\n    }\n    void merge(SlopeTrick& rhs) {\n        if(size() < rhs.size())\
    \ swap(rhs);\n        while(!rhs.L.empty()) add_left(rhs.pop_L());\n        while(!rhs.R.empty())\
    \ add_right(rhs.pop_R());\n        min_f += rhs.min_f;\n    }\n    // L, R \u306F\
    \u7A7A\u306B\u306A\u308B\n    T eval(T x) {\n        T ret = min_f;\n        while(!L.empty())\
    \ ret += std::max(T(0), pop_L() - x);\n        while(!R.empty()) ret += std::max(T(0),\
    \ x - pop_R());\n        return ret;\n    }\n};\n#line 4 \"test/mytest/data-structure/slope-trick.test.cpp\"\
    \n\n\nusing Slope = SlopeTrick<ll>;\nll evaluate(Slope s, ll x) {\n    ll value\
    \ = s.eval(x);\n    assert(s.size() == 0 && s.L.empty() && s.R.empty());\n   \
    \ return value;\n}\nint main() {\n    Slope zero;\n    assert(zero.size() == 0\
    \ && zero.min_f == 0 && zero.add_L == 0 && zero.add_R == 0);\n    assert(zero.get_min_lr()\
    \ == make_tuple(0LL, -zero.inf, zero.inf));\n    mt19937 rng(62);\n    for(int\
    \ trial = 0; trial < 100; ++trial) {\n        Slope base;\n        vector<pair<int,\
    \ int>> terms;\n        ll constant = int(rng() % 21) - 10;\n        base.add_const(constant);\n\
    \        for(int i = 0; i < 10; ++i) {\n            int kind = rng() % 3, a =\
    \ int(rng() % 21) - 10;\n            terms.emplace_back(kind, a);\n          \
    \  if(kind == 0) base.add_left(a);\n            if(kind == 1) base.add_right(a);\n\
    \            if(kind == 2) base.add_abs(a);\n        }\n        auto f = [&](ll\
    \ x) {\n            ll value = constant;\n            for(auto [kind, a] : terms)\
    \ {\n                if(kind == 0) value += max(0LL, a - x);\n               \
    \ if(kind == 1) value += max(0LL, x - a);\n                if(kind == 2) value\
    \ += abs(x - a);\n            }\n            return value;\n        };\n     \
    \   ll minimum = LLONG_MAX;\n        for(int x = -50; x <= 50; ++x) minimum =\
    \ min(minimum, f(x));\n        const auto& view = base;\n        auto [value,\
    \ l, r] = view.get_min_lr();\n        assert(view.get_min() == minimum && value\
    \ == minimum && l <= r);\n        for(int x = -30; x <= 30; ++x) {\n         \
    \   assert(evaluate(base, x) == f(x));\n            assert((l <= x && x <= r)\
    \ == (f(x) == minimum));\n        }\n        auto left = base, right = base, shifted\
    \ = base, window = base;\n        left.clear_right(); right.clear_left(); shifted.shift(-3);\
    \ window.shift(-2, 4);\n        for(int x = -30; x <= 30; ++x) {\n           \
    \ ll a = LLONG_MAX, b = LLONG_MAX, c = LLONG_MAX;\n            for(int y = -50;\
    \ y <= x; ++y) a = min(a, f(y));\n            for(int y = x; y <= 50; ++y) b =\
    \ min(b, f(y));\n            for(int y = x - 4; y <= x + 2; ++y) c = min(c, f(y));\n\
    \            assert(evaluate(left, x) == a && evaluate(right, x) == b);\n    \
    \        assert(evaluate(shifted, x) == f(x + 3) && evaluate(window, x) == c);\n\
    \        }\n        for(bool swap_sizes : {false, true}) {\n            auto a\
    \ = base; Slope b; b.add_abs(3); b.add_const(7);\n            if(swap_sizes) a.swap(b);\n\
    \            a.merge(b);\n            assert(b.size() == 0);\n            for(int\
    \ x = -30; x <= 30; ++x) assert(evaluate(a, x) == f(x) + abs(x - 3) + 7);\n  \
    \      }\n    }\n    INT(a, b); print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../data-structure/slope-trick.hpp\"\n\n\nusing Slope = SlopeTrick<ll>;\n\
    ll evaluate(Slope s, ll x) {\n    ll value = s.eval(x);\n    assert(s.size() ==\
    \ 0 && s.L.empty() && s.R.empty());\n    return value;\n}\nint main() {\n    Slope\
    \ zero;\n    assert(zero.size() == 0 && zero.min_f == 0 && zero.add_L == 0 &&\
    \ zero.add_R == 0);\n    assert(zero.get_min_lr() == make_tuple(0LL, -zero.inf,\
    \ zero.inf));\n    mt19937 rng(62);\n    for(int trial = 0; trial < 100; ++trial)\
    \ {\n        Slope base;\n        vector<pair<int, int>> terms;\n        ll constant\
    \ = int(rng() % 21) - 10;\n        base.add_const(constant);\n        for(int\
    \ i = 0; i < 10; ++i) {\n            int kind = rng() % 3, a = int(rng() % 21)\
    \ - 10;\n            terms.emplace_back(kind, a);\n            if(kind == 0) base.add_left(a);\n\
    \            if(kind == 1) base.add_right(a);\n            if(kind == 2) base.add_abs(a);\n\
    \        }\n        auto f = [&](ll x) {\n            ll value = constant;\n \
    \           for(auto [kind, a] : terms) {\n                if(kind == 0) value\
    \ += max(0LL, a - x);\n                if(kind == 1) value += max(0LL, x - a);\n\
    \                if(kind == 2) value += abs(x - a);\n            }\n         \
    \   return value;\n        };\n        ll minimum = LLONG_MAX;\n        for(int\
    \ x = -50; x <= 50; ++x) minimum = min(minimum, f(x));\n        const auto& view\
    \ = base;\n        auto [value, l, r] = view.get_min_lr();\n        assert(view.get_min()\
    \ == minimum && value == minimum && l <= r);\n        for(int x = -30; x <= 30;\
    \ ++x) {\n            assert(evaluate(base, x) == f(x));\n            assert((l\
    \ <= x && x <= r) == (f(x) == minimum));\n        }\n        auto left = base,\
    \ right = base, shifted = base, window = base;\n        left.clear_right(); right.clear_left();\
    \ shifted.shift(-3); window.shift(-2, 4);\n        for(int x = -30; x <= 30; ++x)\
    \ {\n            ll a = LLONG_MAX, b = LLONG_MAX, c = LLONG_MAX;\n           \
    \ for(int y = -50; y <= x; ++y) a = min(a, f(y));\n            for(int y = x;\
    \ y <= 50; ++y) b = min(b, f(y));\n            for(int y = x - 4; y <= x + 2;\
    \ ++y) c = min(c, f(y));\n            assert(evaluate(left, x) == a && evaluate(right,\
    \ x) == b);\n            assert(evaluate(shifted, x) == f(x + 3) && evaluate(window,\
    \ x) == c);\n        }\n        for(bool swap_sizes : {false, true}) {\n     \
    \       auto a = base; Slope b; b.add_abs(3); b.add_const(7);\n            if(swap_sizes)\
    \ a.swap(b);\n            a.merge(b);\n            assert(b.size() == 0);\n  \
    \          for(int x = -30; x <= 30; ++x) assert(evaluate(a, x) == f(x) + abs(x\
    \ - 3) + 7);\n        }\n    }\n    INT(a, b); print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - data-structure/slope-trick.hpp
  isVerificationFile: true
  path: test/mytest/data-structure/slope-trick.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:12:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/data-structure/slope-trick.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/data-structure/slope-trick.test.cpp
- /verify/test/mytest/data-structure/slope-trick.test.cpp.html
title: test/mytest/data-structure/slope-trick.test.cpp
---
