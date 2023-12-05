---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-array.hpp
    title: data-structure/persistent/persistent-array.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-unionfind.hpp
    title: data-structure/persistent/persistent-unionfind.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library-checker/data-structure/persistent-unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line\
    \ 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \    return (a > b ? a = b, true : false);\n}\ntemplate <class T, size_t dim>\n\
    auto make_vector_impl(vector<size_t>& sizes, const T &e) {\n    if constexpr(dim\
    \ == 1) {\n        return vector(sizes[0], e);\n    } else {\n        size_t n\
    \ = sizes[dim - 1];\n        sizes.pop_back();\n        return vector(n, make_vector_impl<T,\
    \ dim - 1>(sizes, e));\n    }\n}\ntemplate <class T, size_t dim>\nauto make_vector(const\
    \ size_t (&sizes)[dim], const T &e) {\n    vector<size_t> s(dim);\n    for(size_t\
    \ i = 0; i < dim; i++) s[i] = sizes[dim - i - 1];\n    return make_vector_impl<T,\
    \ dim>(s, e);\n}\n#pragma endregion Macros\n#line 2 \"data-structure/persistent/persistent-unionfind.hpp\"\
    \n\n#line 5 \"data-structure/persistent/persistent-unionfind.hpp\"\n\n#line 2\
    \ \"data-structure/persistent/persistent-array.hpp\"\n\n#line 6 \"data-structure/persistent/persistent-array.hpp\"\
    \n\ntemplate <class T, int LOG = 4> struct PersistentArray {\n    struct Node\
    \ {\n        T val;\n        Node *childs[1 << LOG];\n\n        Node() { memset(childs,\
    \ 0, sizeof(childs)); }\n        Node(const Node *node) { memcpy(childs, node->childs,\
    \ sizeof(childs)); }\n        Node(const Node &node) { memcpy(childs, node.childs,\
    \ sizeof(childs)); }\n    };\n\n    Node *root;\n    int depth;\n    T identity;\n\
    \    const int full_bit = (1 << LOG) - 1;\n\n    PersistentArray() {}\n    explicit\
    \ PersistentArray(int N, const T &id = 0)\n        : root(new Node()), depth(0),\
    \ identity(id) {\n        PersistentArray(std::vector<T>(N, id));\n    }\n   \
    \ PersistentArray(const std::vector<T> &v) : root(new Node()), depth(0) {\n  \
    \      int N = (int)v.size();\n        while(N > 0) {\n            N >>= LOG;\n\
    \            depth++;\n        }\n        N = (int)v.size();\n        for(int\
    \ i = 0; i < N; i++) {\n            Node *now = root;\n            for(int mask\
    \ = i, d = depth; d > 0; d--) {\n                if(!now->childs[mask & full_bit])\
    \ {\n                    now->childs[mask & full_bit] = new Node();\n        \
    \        }\n                now = now->childs[mask & full_bit];\n            \
    \    mask >>= LOG;\n            }\n            now->val = v[i];\n        }\n \
    \   }\n\n    T get(int idx) { return get(root, idx); }\n\n    Node *set(int idx,\
    \ const T &new_value) { return set(root, idx, new_value); }\n\n    T get(Node\
    \ *node, int idx) {\n        for(int i = 0; i < depth; i++) {\n            node\
    \ = node ? node->childs[idx & full_bit] : nullptr;\n            idx >>= LOG;\n\
    \        }\n        return (node ? node->val : identity);\n    }\n\n    Node *set(Node\
    \ *node, int idx, T new_value) {\n        std::vector<std::pair<Node *, int>>\
    \ st;\n        for(int i = 0; i < depth; i++) {\n            st.emplace_back(node,\
    \ idx & full_bit);\n            node = node ? node->childs[idx & full_bit] : nullptr;\n\
    \            idx >>= LOG;\n        }\n        Node *new_child = new Node();\n\
    \        new_child->val = new_value;\n        while(!st.empty()) {\n         \
    \   auto [par, k] = st.back();\n            st.pop_back();\n            Node *new_par\
    \ = par ? new Node(par) : new Node();\n            new_par->childs[k] = new_child;\n\
    \            new_child = new_par;\n        }\n        return (root = new_child);\n\
    \    }\n};\n#line 7 \"data-structure/persistent/persistent-unionfind.hpp\"\n\n\
    struct PersistentUnionFind {\n    PersistentArray<int> par;\n    using Node =\
    \ decltype(par)::Node;\n    Node* root;\n\n    explicit PersistentUnionFind(int\
    \ n): par(std::vector<int>(n, -1)) {\n        root = par.root;\n    }\n    //\
    \ (leader, size)\n    std::pair<int, int> leader_and_size(int u, Node* r) {\n\
    \        int p = par.get(r, u);\n        return (p < 0 ? std::make_pair(u, -p)\
    \ : leader_and_size(p, r));\n    }\n    std::pair<int, int> leader_and_size(int\
    \ u) {\n        return leader_and_size(u, root);\n    }\n    inline int leader(int\
    \ u, Node* r) { return leader_and_size(u, r).first; }\n    inline int leader(int\
    \ u) { return leader_and_size(u, root).first; }\n    inline int size(int u, Node*\
    \ r) { return leader_and_size(u, r).second; }\n    inline int size(int u) { return\
    \ leader_and_size(u, root).second; }\n    inline bool same(int u, int v, Node*\
    \ r) { return (leader(u, r) == leader(v, r)); }\n    inline bool same(int u, int\
    \ v) { return same(u, v, root); }\n    bool merge(int u, int v, Node* r) {\n \
    \       int sz_u, sz_v;\n        std::tie(u, sz_u) = leader_and_size(u, r);\n\
    \        std::tie(v, sz_v) = leader_and_size(v, r);\n        if(u == v) return\
    \ false;\n        if(sz_u < sz_v) {\n            std::swap(u, v);\n          \
    \  std::swap(sz_u, sz_v);\n        }\n        r = par.set(r, u, -(sz_u + sz_v));\n\
    \        r = par.set(r, v, u);\n        root = r;\n        return true;\n    }\n\
    \    bool merge(int u, int v) { return merge(u, v, root); }\n    Node* get_root()\
    \ const { return root; }\n};\n#line 4 \"test/library-checker/data-structure/persistent-unionfind.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    PersistentUnionFind uf(N);\n\
    \    vector<decltype(uf)::Node*> roots(Q + 1, nullptr);\n    roots[0] = uf.get_root();\n\
    \    REP(i, Q) {\n        int t, k, u, v;\n        cin >> t >> k >> u >> v;\n\
    \        auto r = roots[k + 1];\n        if(t == 0) {\n            uf.merge(u,\
    \ v, r);\n            roots[i + 1] = uf.get_root();\n        } else {\n      \
    \      cout << (int)uf.same(u, v, r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include \"../../../template/template.cpp\"\n#include \"../../../data-structure/persistent/persistent-unionfind.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    PersistentUnionFind uf(N);\n\
    \    vector<decltype(uf)::Node*> roots(Q + 1, nullptr);\n    roots[0] = uf.get_root();\n\
    \    REP(i, Q) {\n        int t, k, u, v;\n        cin >> t >> k >> u >> v;\n\
    \        auto r = roots[k + 1];\n        if(t == 0) {\n            uf.merge(u,\
    \ v, r);\n            roots[i + 1] = uf.get_root();\n        } else {\n      \
    \      cout << (int)uf.same(u, v, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/persistent/persistent-unionfind.hpp
  - data-structure/persistent/persistent-array.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/persistent-unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-12-05 16:11:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/persistent-unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/persistent-unionfind.test.cpp
- /verify/test/library-checker/data-structure/persistent-unionfind.test.cpp.html
title: test/library-checker/data-structure/persistent-unionfind.test.cpp
---
