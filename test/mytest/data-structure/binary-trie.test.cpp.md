---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-trie.hpp
    title: data-structure/binary-trie.hpp
  - icon: ':heavy_check_mark:'
    path: random/rng.hpp
    title: random/rng.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/data-structure/binary-trie.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"template/template.cpp\"\
    \n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if(a < b) {\n        a = b;\n\
    \        return 1;\n    }\n    return 0;\n}\ntemplate <class T> inline bool chmin(T\
    \ &a, T b) {\n    if(a > b) {\n        a = b;\n        return 1;\n    }\n    return\
    \ 0;\n}\n#ifdef DEBUG\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << '(' << p.first << ',' << p.second <<\
    \ ')';\n    return os;\n}\ntemplate <class T> ostream &operator<<(ostream &os,\
    \ const vector<T> &v) {\n    os << '{';\n    for(int i = 0; i < (int)v.size();\
    \ i++) {\n        if(i) { os << ','; }\n        os << v[i];\n    }\n    os <<\
    \ '}';\n    return os;\n}\nvoid debugg() { cerr << endl; }\ntemplate <class T,\
    \ class... Args>\nvoid debugg(const T &x, const Args &... args) {\n    cerr <<\
    \ \" \" << x;\n    debugg(args...);\n}\n#define debug(...)                   \
    \                                          \\\n    cerr << __LINE__ << \" [\"\
    \ << #__VA_ARGS__ << \"]: \", debugg(__VA_ARGS__)\n#define dump(x) cerr << __LINE__\
    \ << \" \" << #x << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n\
    #define dump(x) (void(0))\n#endif\n\nstruct Setup {\n    Setup() {\n        cin.tie(0);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \    }\n} __Setup;\n\nusing ll = long long;\n#define OVERLOAD3(_1, _2, _3, name,\
    \ ...) name\n#define ALL(v) (v).begin(), (v).end()\n#define RALL(v) (v).rbegin(),\
    \ (v).rend()\n#define REP1(i, n) for(int i = 0; i < int(n); i++)\n#define REP2(i,\
    \ a, b) for(int i = (a); i < int(b); i++)\n#define REP(...) OVERLOAD3(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\n#define REVERSE(v) reverse(ALL(v))\n#define SZ(v) ((int)(v).size())\n\
    const int INF = 1 << 30;\nconst ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\n\
    constexpr int MOD2 = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4]\
    \ = {0, 1, 0, -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\n\
    int popcount(int x) { return __builtin_popcount(x); }\nll popcount(ll x) { return\
    \ __builtin_popcountll(x); }\n#pragma endregion Macros\n#line 2 \"random/rng.hpp\"\
    \n\n#line 5 \"random/rng.hpp\"\n\nclass RNG32 {\n  public:\n    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n#line 2 \"data-structure/binary-trie.hpp\"\n\n#line\
    \ 7 \"data-structure/binary-trie.hpp\"\n\ntemplate <typename T = unsigned int,\
    \ int LOG = 32> class BinaryTrie {\n  public:\n    explicit BinaryTrie() : root(nullptr),\
    \ lazy_xor_value(0) {}\n    int count(T val) {\n        if(!root) return 0;\n\
    \        Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--) {\n    \
    \        now = now->child[val >> i & 1];\n            if(!now or now->count ==\
    \ 0) return 0;\n        }\n        return now->count;\n    }\n    void insert(T\
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
    \    Node *root;\n    T lazy_xor_value;\n};\n#line 5 \"test/mytest/data-structure/binary-trie.test.cpp\"\
    \n\nvoid binary_trie_test() {\n    REP(testcase_idx, 20) {\n        vector<int>\
    \ a;\n        BinaryTrie<int, 30> S;\n        RNG32 rng;\n        REP(_, 500)\
    \ {\n            int t = rng.randint(0, 7);\n            if(a.empty()) t = 0;\n\
    \            if(t == 0) { // insert\n                int x = rng.randint(0, 1\
    \ << 30);\n                S.insert(x);\n                a.push_back(x);\n   \
    \         } else if(t == 1) { // erase;\n                int k = rng.randint(0,\
    \ SZ(a));\n                swap(a[k], a.back());\n                S.erase(a.back());\n\
    \                a.pop_back();\n            } else if(t == 2) { // min_element\n\
    \                assert(*min_element(ALL(a)) == S.min_element());\n          \
    \  } else if(t == 3) { // max_element\n                assert(*max_element(ALL(a))\
    \ == S.max_element());\n            } else if(t == 4) { // kth_element\n     \
    \           sort(ALL(a));\n                int k = rng.randint(0, SZ(a));\n  \
    \              assert(a[k] == S.get_kth_element(k));\n            } else if(t\
    \ == 5) { // lower_bound\n                sort(ALL(a));\n                int k\
    \ = rng.randint(0, SZ(a));\n                int id1 = S.lower_bound(a[k]);\n \
    \               int id2 = lower_bound(ALL(a), a[k]) - a.begin();\n           \
    \     assert(id1 == id2);\n            } else if(t == 6) {\n                sort(ALL(a));\n\
    \                int k = rng.randint(0, SZ(a));\n                int id1 = S.upper_bound(a[k]);\n\
    \                int id2 = upper_bound(ALL(a), a[k]) - a.begin();\n          \
    \      assert(id1 == id2);\n            }\n        }\n    }\n}\n\nint main() {\n\
    \    binary_trie_test();\n    int a, b;\n    cin >> a >> b;\n    cout << a + b\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../../template/template.cpp\"\
    \n#include \"../../../random/rng.hpp\"\n#include \"../../../data-structure/binary-trie.hpp\"\
    \n\nvoid binary_trie_test() {\n    REP(testcase_idx, 20) {\n        vector<int>\
    \ a;\n        BinaryTrie<int, 30> S;\n        RNG32 rng;\n        REP(_, 500)\
    \ {\n            int t = rng.randint(0, 7);\n            if(a.empty()) t = 0;\n\
    \            if(t == 0) { // insert\n                int x = rng.randint(0, 1\
    \ << 30);\n                S.insert(x);\n                a.push_back(x);\n   \
    \         } else if(t == 1) { // erase;\n                int k = rng.randint(0,\
    \ SZ(a));\n                swap(a[k], a.back());\n                S.erase(a.back());\n\
    \                a.pop_back();\n            } else if(t == 2) { // min_element\n\
    \                assert(*min_element(ALL(a)) == S.min_element());\n          \
    \  } else if(t == 3) { // max_element\n                assert(*max_element(ALL(a))\
    \ == S.max_element());\n            } else if(t == 4) { // kth_element\n     \
    \           sort(ALL(a));\n                int k = rng.randint(0, SZ(a));\n  \
    \              assert(a[k] == S.get_kth_element(k));\n            } else if(t\
    \ == 5) { // lower_bound\n                sort(ALL(a));\n                int k\
    \ = rng.randint(0, SZ(a));\n                int id1 = S.lower_bound(a[k]);\n \
    \               int id2 = lower_bound(ALL(a), a[k]) - a.begin();\n           \
    \     assert(id1 == id2);\n            } else if(t == 6) {\n                sort(ALL(a));\n\
    \                int k = rng.randint(0, SZ(a));\n                int id1 = S.upper_bound(a[k]);\n\
    \                int id2 = upper_bound(ALL(a), a[k]) - a.begin();\n          \
    \      assert(id1 == id2);\n            }\n        }\n    }\n}\n\nint main() {\n\
    \    binary_trie_test();\n    int a, b;\n    cin >> a >> b;\n    cout << a + b\
    \ << endl;\n}"
  dependsOn:
  - template/template.cpp
  - random/rng.hpp
  - data-structure/binary-trie.hpp
  isVerificationFile: true
  path: test/mytest/data-structure/binary-trie.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/data-structure/binary-trie.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/data-structure/binary-trie.test.cpp
- /verify/test/mytest/data-structure/binary-trie.test.cpp.html
title: test/mytest/data-structure/binary-trie.test.cpp
---
