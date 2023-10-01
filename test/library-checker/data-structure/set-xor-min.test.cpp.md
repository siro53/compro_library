---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-trie.hpp
    title: data-structure/binary-trie.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/library-checker/data-structure/set-xor-min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 1 \"\
    template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if(a\
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
    \ }\n#pragma endregion Macros\n#line 2 \"data-structure/binary-trie.hpp\"\n\n\
    #line 7 \"data-structure/binary-trie.hpp\"\n\ntemplate <typename T = unsigned\
    \ int, int LOG = 32> class BinaryTrie {\n  public:\n    explicit BinaryTrie()\
    \ : root(nullptr), lazy_xor_value(0) {}\n    int count(T val) {\n        if(!root)\
    \ return 0;\n        Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--)\
    \ {\n            now = now->child[val >> i & 1];\n            if(!now or now->count\
    \ == 0) return 0;\n        }\n        return now->count;\n    }\n    void insert(T\
    \ val) {\n        if(!root) root = new Node();\n        Node *now = root;\n  \
    \      now->count++;\n        for(int i = LOG - 1; i >= 0; i--) {\n          \
    \  int dir = val >> i & 1;\n            Node *nxt = now->child[dir];\n       \
    \     if(!nxt) {\n                nxt = new Node();\n                now->child[dir]\
    \ = nxt;\n            }\n            now = nxt;\n            now->count++;\n \
    \       }\n    }\n    bool erase(T val) {\n        if(count(val) == 0) return\
    \ false;\n        Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--)\
    \ {\n            now->count--;\n            now = now->child[val >> i & 1];\n\
    \            assert(now != nullptr);\n            assert(now->count > 0);\n  \
    \      }\n        now->count--;\n        return true;\n    }\n    T min_element()\
    \ {\n        assert(root != nullptr);\n        T ret = 0;\n        Node *now =\
    \ root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            int dir = (lazy_xor_value\
    \ >> i & 1);\n            Node *nxt = now->child[dir];\n            if(!nxt or\
    \ nxt->count == 0) {\n                ret += T(1) << i;\n                nxt =\
    \ now->child[dir ^ 1];\n            }\n            now = nxt;\n            assert(now\
    \ != nullptr and now->count > 0);\n        }\n        return ret;\n    }\n   \
    \ T max_element() {\n        assert(root != nullptr);\n        T ret = 0;\n  \
    \      Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--) {\n      \
    \      int dir = (lazy_xor_value >> i & 1) ^ 1;\n            Node *nxt = now->child[dir];\n\
    \            if(!nxt or nxt->count == 0) {\n                nxt = now->child[dir\
    \ ^ 1];\n            } else {\n                ret += T(1) << i;\n           \
    \ }\n            now = nxt;\n            assert(now != nullptr and now->count\
    \ > 0);\n        }\n        return ret;\n    }\n    T get_kth_element(int k) {\
    \ // \u5C0F\u3055\u3044\u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024(0-indexed)\n\
    \        assert(0 <= k and k < size());\n        Node *now = root;\n        T\
    \ ret = 0;\n        for(int i = LOG - 1; i >= 0; i--) {\n            int b = lazy_xor_value\
    \ >> i & 1;\n            int small_count = (now->child[b] ? now->child[b]->count\
    \ : 0);\n            int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count\
    \ : 0);\n            assert(0 < small_count + big_count);\n            assert(k\
    \ < small_count + big_count);\n            if(k >= small_count) {\n          \
    \      ret += T(1) << i;\n                now = now->child[b ^ 1];\n         \
    \       k -= small_count;\n            } else {\n                now = now->child[b];\n\
    \            }\n        }\n        return ret;\n    }\n    int lower_bound(T val)\
    \ {\n        int ret = 0;\n        Node* now = root;\n        for(int i = LOG\
    \ - 1; i >= 0; i--) {\n            int b = lazy_xor_value >> i & 1;\n        \
    \    int small_count = (now->child[b] ? now->child[b]->count : 0);\n         \
    \   int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count : 0);\n    \
    \        if(small_count == 0) {\n                assert(big_count);\n        \
    \        now = now->child[b ^ 1];\n            } else if(big_count == 0) {\n \
    \               assert(small_count);\n                now = now->child[b];\n \
    \           } else {\n                if(b == (val >> i & 1)) { \n           \
    \         now = now->child[b];\n                } else {\n                   \
    \ ret += small_count;\n                    now = now->child[b ^ 1];\n        \
    \        }\n            }\n        }\n        return ret;\n    }\n    int upper_bound(T\
    \ val) {\n        int id = lower_bound(val);\n        T kth_element = get_kth_element(id);\n\
    \        if(kth_element != val) return id;\n        int cnt = count(kth_element);\n\
    \        return id + cnt;\n    }\n    int size() const {\n        if(!root) return\
    \ 0;\n        return root->count;\n    }\n    inline bool empty() const { return\
    \ (!root or root->count == 0); }\n    void all_xor(T val) { lazy_xor_value ^=\
    \ val; }\n\n  private:\n    struct Node {\n        int count;\n        std::array<Node\
    \ *, 2> child;\n        Node() : count(0), child({nullptr, nullptr}) {}\n    };\n\
    \    Node *root;\n    T lazy_xor_value;\n};\n#line 4 \"test/library-checker/data-structure/set-xor-min.test.cpp\"\
    \n\nint main() {\n    BinaryTrie<int, 30> S;\n    int Q;\n    cin >> Q;\n    while(Q--)\
    \ {\n        unsigned int t, x;\n        cin >> t >> x;\n        if(t == 0) {\n\
    \            if(S.count(x) > 0) continue;\n            S.insert(x);\n        \
    \    assert(S.count(x) > 0);\n        } else if(t == 1) {\n            S.erase(x);\n\
    \            assert(S.count(x) == 0);\n        } else {\n            S.all_xor(x);\n\
    \            cout << S.min_element() << '\\n';\n            S.all_xor(x);\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"../../../template/template.cpp\"\n#include \"../../../data-structure/binary-trie.hpp\"\
    \n\nint main() {\n    BinaryTrie<int, 30> S;\n    int Q;\n    cin >> Q;\n    while(Q--)\
    \ {\n        unsigned int t, x;\n        cin >> t >> x;\n        if(t == 0) {\n\
    \            if(S.count(x) > 0) continue;\n            S.insert(x);\n        \
    \    assert(S.count(x) > 0);\n        } else if(t == 1) {\n            S.erase(x);\n\
    \            assert(S.count(x) == 0);\n        } else {\n            S.all_xor(x);\n\
    \            cout << S.min_element() << '\\n';\n            S.all_xor(x);\n  \
    \      }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data-structure/binary-trie.hpp
  isVerificationFile: true
  path: test/library-checker/data-structure/set-xor-min.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/data-structure/set-xor-min.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/set-xor-min.test.cpp
- /verify/test/library-checker/data-structure/set-xor-min.test.cpp.html
title: test/library-checker/data-structure/set-xor-min.test.cpp
---
