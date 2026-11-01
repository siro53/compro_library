---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/subset-iterator.hpp
    title: "bit \u96C6\u5408\u306E\u5217\u6319"
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
  bundledCode: "#line 1 \"test/mytest/misc/subset-iterator.test.cpp\"\n#define PROBLEM\
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
    \    return ord;\n}\n// #endregion Macros\n#line 2 \"misc/subset-iterator.hpp\"\
    \n\n#line 6 \"misc/subset-iterator.hpp\"\n#include <x86intrin.h>\n\n// Subset(S)\
    \ := S\u306E\u90E8\u5206\u96C6\u5408\u3092\u8D70\u67FB\u3059\u308B\nstruct Subset\
    \ {\n    struct SubsetIter {\n        uint32_t S, T;\n        bool is_end;\n\n\
    \        SubsetIter(uint32_t s): S(s), T(s), is_end(false) {}\n\n        auto\
    \ operator*() const { return T; }\n        auto operator++() { T = (T - 1) & S;\
    \ }\n        auto operator!=(std::nullptr_t) {\n            if(is_end) return\
    \ false;\n            is_end = (T == 0);\n            return true;\n        }\n\
    \    };\n\n    uint32_t S;\n\n    Subset(uint32_t s): S(s) {}\n    auto begin()\
    \ { return SubsetIter(S); }\n    auto end() { return nullptr; }\n};\n\n// Subset_k(S,\
    \ k) := S\u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u3001size\u304Ck\u306E\
    \u96C6\u5408\u306E\u307F\u8D70\u67FB\u3059\u308B\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct Subset_k {\n    struct SubsetIter_k {\n        const uint32_t n, k, S;\n\
    \        uint32_t T;\n\n        SubsetIter_k(uint32_t S, uint32_t k): n(uint32_t(1)\
    \ << __builtin_popcount(S)), k(k), S(S), T((uint32_t(1) << k) - 1) {}\n\n    \
    \    __attribute__((target(\"bmi2\")))\n        auto operator*() const { return\
    \ _pdep_u32(T, S); }\n\n        __attribute__((target(\"bmi\")))\n        auto\
    \ operator++() {\n            uint32_t y = T + _blsi_u32(T);\n            T =\
    \ y | (__andn_u32(y, T) >> _tzcnt_u32(T << 1));\n        }\n        auto operator!=(std::nullptr_t)\
    \ const { return T < n; }\n    };\n\n    uint32_t S, k;\n    \n    Subset_k(uint32_t\
    \ S, uint32_t k): S(S), k(k) {\n        assert(k != 0);\n    }\n\n    auto begin()\
    \ { return SubsetIter_k(S, k); }\n    auto end() { return nullptr; }\n};\n\n//\
    \ SetBit(S) := S\u306E\u3046\u3061\u3001bit\u304C\u7ACB\u3063\u3066\u3044\u308B\
    index\u3092\u5C0F\u3055\u3044\u9806\u306B\u8FD4\u3059\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct SetBit {\n    struct SetBitIter {\n        uint32_t S;\n\n        SetBitIter(uint32_t\
    \ S): S(S) {}\n\n        __attribute__((target(\"bmi\")))\n        auto operator*()\
    \ { return _tzcnt_u32(S); }\n\n        __attribute__((target(\"bmi\")))\n    \
    \    auto operator++() { S = _blsr_u32(S); }\n\n        auto operator!=(std::nullptr_t)\
    \ { return S; }\n    };\n\n    uint32_t S;\n\n    SetBit(uint32_t S): S(S) {}\n\
    \n    auto begin() { return SetBitIter(S); }\n    auto end() { return nullptr;\
    \ }\n};\n#line 4 \"test/mytest/misc/subset-iterator.test.cpp\"\n\nvoid check(uint32_t\
    \ mask) {\n    vector<uint32_t> bits;\n    for(unsigned i = 0; i < 32; ++i) if(mask\
    \ >> i & 1) bits.push_back(i);\n    vector<uint32_t> actual_bits;\n    SetBit\
    \ bit_range(mask);\n    assert(bit_range.S == mask);\n    for(auto bit : bit_range)\
    \ actual_bits.push_back(bit);\n    assert(actual_bits == bits);\n    vector<uint32_t>\
    \ expected;\n    for(unsigned choice = 0; choice < (1U << bits.size()); ++choice)\
    \ {\n        uint32_t value = 0;\n        for(unsigned j = 0; j < bits.size();\
    \ ++j) if(choice >> j & 1) {\n            value |= 1U << bits[j];\n        }\n\
    \        expected.push_back(value);\n    }\n    sort(expected.begin(), expected.end(),\
    \ greater<uint32_t>());\n    Subset subset_range(mask);\n    assert(subset_range.S\
    \ == mask);\n    vector<uint32_t> actual;\n    for(auto value : subset_range)\
    \ actual.push_back(value);\n    assert(actual == expected);\n    // A new begin()\
    \ must allow a second traversal, including the empty set.\n    actual.clear();\n\
    \    for(auto value : subset_range) actual.push_back(value);\n    assert(actual\
    \ == expected);\n    for(unsigned k = 1; k <= bits.size(); ++k) {\n        vector<uint32_t>\
    \ fixed_expected, fixed_actual;\n        for(auto value : expected) if(unsigned(__builtin_popcount(value))\
    \ == k) {\n            fixed_expected.push_back(value);\n        }\n        reverse(fixed_expected.begin(),\
    \ fixed_expected.end());\n        Subset_k fixed_range(mask, k);\n        assert(fixed_range.S\
    \ == mask && fixed_range.k == k);\n        for(auto value : fixed_range) fixed_actual.push_back(value);\n\
    \        assert(fixed_actual == fixed_expected);\n    }\n}\n\nint main() {\n \
    \   for(uint32_t mask = 0; mask < 256; ++mask) check(mask);\n    for(uint32_t\
    \ mask : {0x80000000U, 0x80000005U, 0xf0000000U, 0x80808080U}) check(mask);\n\
    \    SetBit::SetBitIter bit(1U << 31);\n    assert(bit != nullptr && *bit == 31);\n\
    \    ++bit;\n    assert(!(bit != nullptr));\n    Subset::SubsetIter subset(0);\n\
    \    assert(subset != nullptr && *subset == 0);\n    ++subset;\n    assert(!(subset\
    \ != nullptr));\n    Subset_k::SubsetIter_k fixed(0x80000001U, 1);\n    assert(fixed\
    \ != nullptr && *fixed == 1);\n    ++fixed;\n    assert(fixed != nullptr && *fixed\
    \ == 0x80000000U);\n    ++fixed;\n    assert(!(fixed != nullptr));\n    INT(a,\
    \ b);\n    print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../misc/subset-iterator.hpp\"\n\nvoid check(uint32_t mask)\
    \ {\n    vector<uint32_t> bits;\n    for(unsigned i = 0; i < 32; ++i) if(mask\
    \ >> i & 1) bits.push_back(i);\n    vector<uint32_t> actual_bits;\n    SetBit\
    \ bit_range(mask);\n    assert(bit_range.S == mask);\n    for(auto bit : bit_range)\
    \ actual_bits.push_back(bit);\n    assert(actual_bits == bits);\n    vector<uint32_t>\
    \ expected;\n    for(unsigned choice = 0; choice < (1U << bits.size()); ++choice)\
    \ {\n        uint32_t value = 0;\n        for(unsigned j = 0; j < bits.size();\
    \ ++j) if(choice >> j & 1) {\n            value |= 1U << bits[j];\n        }\n\
    \        expected.push_back(value);\n    }\n    sort(expected.begin(), expected.end(),\
    \ greater<uint32_t>());\n    Subset subset_range(mask);\n    assert(subset_range.S\
    \ == mask);\n    vector<uint32_t> actual;\n    for(auto value : subset_range)\
    \ actual.push_back(value);\n    assert(actual == expected);\n    // A new begin()\
    \ must allow a second traversal, including the empty set.\n    actual.clear();\n\
    \    for(auto value : subset_range) actual.push_back(value);\n    assert(actual\
    \ == expected);\n    for(unsigned k = 1; k <= bits.size(); ++k) {\n        vector<uint32_t>\
    \ fixed_expected, fixed_actual;\n        for(auto value : expected) if(unsigned(__builtin_popcount(value))\
    \ == k) {\n            fixed_expected.push_back(value);\n        }\n        reverse(fixed_expected.begin(),\
    \ fixed_expected.end());\n        Subset_k fixed_range(mask, k);\n        assert(fixed_range.S\
    \ == mask && fixed_range.k == k);\n        for(auto value : fixed_range) fixed_actual.push_back(value);\n\
    \        assert(fixed_actual == fixed_expected);\n    }\n}\n\nint main() {\n \
    \   for(uint32_t mask = 0; mask < 256; ++mask) check(mask);\n    for(uint32_t\
    \ mask : {0x80000000U, 0x80000005U, 0xf0000000U, 0x80808080U}) check(mask);\n\
    \    SetBit::SetBitIter bit(1U << 31);\n    assert(bit != nullptr && *bit == 31);\n\
    \    ++bit;\n    assert(!(bit != nullptr));\n    Subset::SubsetIter subset(0);\n\
    \    assert(subset != nullptr && *subset == 0);\n    ++subset;\n    assert(!(subset\
    \ != nullptr));\n    Subset_k::SubsetIter_k fixed(0x80000001U, 1);\n    assert(fixed\
    \ != nullptr && *fixed == 1);\n    ++fixed;\n    assert(fixed != nullptr && *fixed\
    \ == 0x80000000U);\n    ++fixed;\n    assert(!(fixed != nullptr));\n    INT(a,\
    \ b);\n    print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - misc/subset-iterator.hpp
  isVerificationFile: true
  path: test/mytest/misc/subset-iterator.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 17:39:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/misc/subset-iterator.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/misc/subset-iterator.test.cpp
- /verify/test/mytest/misc/subset-iterator.test.cpp.html
title: test/mytest/misc/subset-iterator.test.cpp
---
