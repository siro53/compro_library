---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/and.hpp
    title: "\u30D3\u30C3\u30C8 AND\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/kadane.hpp
    title: "\u6700\u5927\u90E8\u5206\u914D\u5217\u548C\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-array.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: Segment Tree
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
  bundledCode: "#line 1 \"test/mytest/data-structure/initialization-and-monoids.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
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
    \    return ord;\n}\n#pragma endregion Macros\n#line 2 \"data-structure/persistent/persistent-array.hpp\"\
    \n\n#line 6 \"data-structure/persistent/persistent-array.hpp\"\n\ntemplate <class\
    \ T, int LOG = 4> struct PersistentArray {\n    struct Node {\n        T val;\n\
    \        Node *childs[1 << LOG];\n\n        Node(): val{} { memset(childs, 0,\
    \ sizeof(childs)); }\n        Node(const Node *node): val(node->val) { memcpy(childs,\
    \ node->childs, sizeof(childs)); }\n        Node(const Node &node): val(node.val)\
    \ { memcpy(childs, node.childs, sizeof(childs)); }\n    };\n\n    Node *root;\n\
    \    int depth;\n    T identity;\n    const int full_bit = (1 << LOG) - 1;\n\n\
    \    PersistentArray(): PersistentArray(0) {}\n    explicit PersistentArray(int\
    \ N, const T &id = 0)\n        : PersistentArray(std::vector<T>(N, id)) {\n  \
    \      identity = id;\n    }\n    PersistentArray(const std::vector<T> &v) : root(new\
    \ Node()), depth(0), identity{} {\n        int N = (int)v.size();\n        while(N\
    \ > 0) {\n            N >>= LOG;\n            depth++;\n        }\n        N =\
    \ (int)v.size();\n        for(int i = 0; i < N; i++) {\n            Node *now\
    \ = root;\n            for(int mask = i, d = depth; d > 0; d--) {\n          \
    \      if(!now->childs[mask & full_bit]) {\n                    now->childs[mask\
    \ & full_bit] = new Node();\n                }\n                now = now->childs[mask\
    \ & full_bit];\n                mask >>= LOG;\n            }\n            now->val\
    \ = v[i];\n        }\n    }\n\n    T get(int idx) { return get(root, idx); }\n\
    \n    Node *set(int idx, const T &new_value) { return set(root, idx, new_value);\
    \ }\n\n    T get(Node *node, int idx) {\n        for(int i = 0; i < depth; i++)\
    \ {\n            node = node ? node->childs[idx & full_bit] : nullptr;\n     \
    \       idx >>= LOG;\n        }\n        return (node ? node->val : identity);\n\
    \    }\n\n    Node *set(Node *node, int idx, T new_value) {\n        std::vector<std::pair<Node\
    \ *, int>> st;\n        for(int i = 0; i < depth; i++) {\n            st.emplace_back(node,\
    \ idx & full_bit);\n            node = node ? node->childs[idx & full_bit] : nullptr;\n\
    \            idx >>= LOG;\n        }\n        Node *new_child = new Node();\n\
    \        new_child->val = new_value;\n        while(!st.empty()) {\n         \
    \   auto [par, k] = st.back();\n            st.pop_back();\n            Node *new_par\
    \ = par ? new Node(par) : new Node();\n            new_par->childs[k] = new_child;\n\
    \            new_child = new_par;\n        }\n        return (root = new_child);\n\
    \    }\n};\n#line 2 \"data-structure/monoid/and.hpp\"\n\ntemplate <typename T>\
    \ struct MonoidAND {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return (l & r); }\n    inline static T e() { return T(~T(0));\
    \ }\n};\n#line 2 \"data-structure/monoid/kadane.hpp\"\n\n#line 5 \"data-structure/monoid/kadane.hpp\"\
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
    \        return S(m, m, m, T(0));\n    }\n};\n#line 2 \"data-structure/segtree/segtree.hpp\"\
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
    \ private:\n    int N, sz;\n    std::vector<T> node;\n};\n#line 7 \"test/mytest/data-structure/initialization-and-monoids.test.cpp\"\
    \n\nvoid regression_test() {\n    for(int n : {1, 2, 16, 17, 64}) {\n        PersistentArray<int>\
    \ a(n, 7);\n        auto initial = a.root;\n        auto first = a.set(0, 3);\n\
    \        auto last = a.set(initial, n - 1, 9);\n        for(int i = 0; i < n;\
    \ i++) {\n            assert(a.get(initial, i) == 7);\n            assert(a.get(first,\
    \ i) == (i == 0 ? 3 : 7));\n            assert(a.get(last, i) == (i == n - 1 ?\
    \ 9 : 7));\n        }\n        typename PersistentArray<int>::Node copy(*first);\n\
    \        assert(copy.val == first->val);\n    }\n    using And = MonoidAND<unsigned>;\n\
    \    for(unsigned v : {0U, 1U, 2U, 0x80000000U, ~0U}) {\n        assert(And::op(v,\
    \ And::e()) == v);\n        assert(And::op(And::e(), v) == v);\n    }\n    using\
    \ K = MonoidKadane<int>;\n    assert(K::op(K::e(), K::e()).sum == 0);\n    K::S\
    \ smallest(INT_MIN, INT_MIN, INT_MIN, INT_MIN);\n    assert(K::op(K::e(), smallest).allmax\
    \ == INT_MIN);\n    mt19937 rng(53);\n    for(int n = 0; n <= 20; n++) {\n   \
    \     vector<int> a(n);\n        vector<K::S> init;\n        for(auto& x : a)\
    \ { x = (int)(rng() % 21) - 10; init.emplace_back(x, x, x, x); }\n        Segtree<K>\
    \ seg(init);\n        for(int l = 0; l <= n; l++) for(int r = l; r <= n; r++)\
    \ {\n            int best = INT_MIN;\n            for(int i = l; i < r; i++) {\n\
    \                int sum = 0;\n                for(int j = i; j < r; j++) { sum\
    \ += a[j]; best = max(best, sum); }\n            }\n            assert(seg.prod(l,\
    \ r).allmax == best);\n        }\n    }\n    using D = MonoidKadane<double>;\n\
    \    assert(D::op(D::e(), D::S(-2, -2, -2, -2)).allmax == -2);\n}\n\nint main()\
    \ {\n    regression_test();\n    INT(a, b);\n    print(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../data-structure/persistent/persistent-array.hpp\"\n#include\
    \ \"../../../data-structure/monoid/and.hpp\"\n#include \"../../../data-structure/monoid/kadane.hpp\"\
    \n#include \"../../../data-structure/segtree/segtree.hpp\"\n\nvoid regression_test()\
    \ {\n    for(int n : {1, 2, 16, 17, 64}) {\n        PersistentArray<int> a(n,\
    \ 7);\n        auto initial = a.root;\n        auto first = a.set(0, 3);\n   \
    \     auto last = a.set(initial, n - 1, 9);\n        for(int i = 0; i < n; i++)\
    \ {\n            assert(a.get(initial, i) == 7);\n            assert(a.get(first,\
    \ i) == (i == 0 ? 3 : 7));\n            assert(a.get(last, i) == (i == n - 1 ?\
    \ 9 : 7));\n        }\n        typename PersistentArray<int>::Node copy(*first);\n\
    \        assert(copy.val == first->val);\n    }\n    using And = MonoidAND<unsigned>;\n\
    \    for(unsigned v : {0U, 1U, 2U, 0x80000000U, ~0U}) {\n        assert(And::op(v,\
    \ And::e()) == v);\n        assert(And::op(And::e(), v) == v);\n    }\n    using\
    \ K = MonoidKadane<int>;\n    assert(K::op(K::e(), K::e()).sum == 0);\n    K::S\
    \ smallest(INT_MIN, INT_MIN, INT_MIN, INT_MIN);\n    assert(K::op(K::e(), smallest).allmax\
    \ == INT_MIN);\n    mt19937 rng(53);\n    for(int n = 0; n <= 20; n++) {\n   \
    \     vector<int> a(n);\n        vector<K::S> init;\n        for(auto& x : a)\
    \ { x = (int)(rng() % 21) - 10; init.emplace_back(x, x, x, x); }\n        Segtree<K>\
    \ seg(init);\n        for(int l = 0; l <= n; l++) for(int r = l; r <= n; r++)\
    \ {\n            int best = INT_MIN;\n            for(int i = l; i < r; i++) {\n\
    \                int sum = 0;\n                for(int j = i; j < r; j++) { sum\
    \ += a[j]; best = max(best, sum); }\n            }\n            assert(seg.prod(l,\
    \ r).allmax == best);\n        }\n    }\n    using D = MonoidKadane<double>;\n\
    \    assert(D::op(D::e(), D::S(-2, -2, -2, -2)).allmax == -2);\n}\n\nint main()\
    \ {\n    regression_test();\n    INT(a, b);\n    print(a + b);\n}\n"
  dependsOn:
  - template/template.cpp
  - data-structure/persistent/persistent-array.hpp
  - data-structure/monoid/and.hpp
  - data-structure/monoid/kadane.hpp
  - data-structure/segtree/segtree.hpp
  isVerificationFile: true
  path: test/mytest/data-structure/initialization-and-monoids.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/data-structure/initialization-and-monoids.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/data-structure/initialization-and-monoids.test.cpp
- /verify/test/mytest/data-structure/initialization-and-monoids.test.cpp.html
title: test/mytest/data-structure/initialization-and-monoids.test.cpp
---
