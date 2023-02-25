---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-array.hpp
    title: data-structure/persistent/persistent-array.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-unionfind.hpp
    title: data-structure/persistent/persistent-unionfind.hpp
  - icon: ':question:'
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
    using namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
    \ < b) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\ntemplate\
    \ <class T> inline bool chmin(T &a, T b) {\n    if(a > b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\n#ifdef DEBUG\ntemplate <class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n    os <<\
    \ '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate <class\
    \ T> ostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '{';\n\
    \    for(int i = 0; i < (int)v.size(); i++) {\n        if(i) { os << ','; }\n\
    \        os << v[i];\n    }\n    os << '}';\n    return os;\n}\nvoid debugg()\
    \ { cerr << endl; }\ntemplate <class T, class... Args>\nvoid debugg(const T &x,\
    \ const Args &... args) {\n    cerr << \" \" << x;\n    debugg(args...);\n}\n\
    #define debug(...)                                                           \
    \  \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\nstruct Setup\
    \ {\n    Setup() {\n        cin.tie(0);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    }\n} __Setup;\n\nusing ll = long\
    \ long;\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n#define ALL(v) (v).begin(),\
    \ (v).end()\n#define RALL(v) (v).rbegin(), (v).rend()\n#define REP1(i, n) for(int\
    \ i = 0; i < int(n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b);\
    \ i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define\
    \ UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define REVERSE(v)\
    \ reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/persistent/persistent-unionfind.hpp\"\
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
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/persistent-unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/persistent-unionfind.test.cpp
- /verify/test/library-checker/data-structure/persistent-unionfind.test.cpp.html
title: test/library-checker/data-structure/persistent-unionfind.test.cpp
---
