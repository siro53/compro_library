---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/binary_trie.hpp
    title: Binary Trie
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n#line 1 \"template/template.cpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
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
    \ i = 0; i < (n); i++)\n#define REP2(i, a, b) for(int i = (a); i < int(b); i++)\n\
    #define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define UNIQUE(v)\
    \ sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\nconst int INF = 1 << 30;\n\
    const ll LLINF = 1LL << 60;\nconstexpr int MOD = 1000000007;\nconstexpr int MOD2\
    \ = 998244353;\nconst int dx[4] = {1, 0, -1, 0};\nconst int dy[4] = {0, 1, 0,\
    \ -1};\n\nvoid Case(int i) { cout << \"Case #\" << i << \": \"; }\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n#pragma endregion Macros\n#line 1 \"data_structure/binary_trie.hpp\"\nstruct\
    \ BinaryTrie {\n    static const int B = 64;\n    using ull = uint64_t;\n    struct\
    \ Node {\n        int cnt;\n        Node *child[2];\n        Node() : cnt(0),\
    \ child{nullptr, nullptr} {}\n    };\n    Node *root;\n    BinaryTrie() : root(nullptr)\
    \ {}\n    int count(ull val) const {\n        if(!root) {\n            return\
    \ 0;\n        }\n        Node *now = root;\n        for(int i = B - 1; i >= 0;\
    \ i--) {\n            now = now->child[(val >> i) & 1ULL];\n            if(!now)\
    \ {\n                return 0;\n            }\n        }\n        return now->cnt;\n\
    \    }\n    Node *insert(Node *now, ull val, int i = B - 1) {\n        if(!now)\
    \ {\n            now = new Node();\n        }\n        now->cnt++;\n        if(i\
    \ < 0) {\n            return now;\n        }\n        bool dir = (val >> i) &\
    \ 1ULL;\n        now->child[dir] = insert(now->child[dir], val, i - 1);\n    \
    \    return now;\n    }\n    void insert(ull val) {\n        if(count(val)) {\n\
    \            return;\n        }\n        root = insert(root, val);\n    }\n  \
    \  Node *erase(Node *now, ull val, int i = B - 1) {\n        assert(now);\n  \
    \      now->cnt--;\n        if(now->cnt == 0) {\n            return nullptr;\n\
    \        }\n        if(i < 0) {\n            return now;\n        }\n        bool\
    \ dir = (val >> i) & 1ULL;\n        now->child[dir] = erase(now->child[dir], val,\
    \ i - 1);\n        return now;\n    }\n    void erase(ull val) {\n        if(count(val)\
    \ == 0) {\n            return;\n        }\n        root = erase(root, val);\n\
    \    }\n    ull min_element(Node *now, ull val, int i = B - 1) {\n        assert(now);\n\
    \        if(i < 0) {\n            return 0;\n        }\n        bool dir = (val\
    \ >> i) & 1ULL;\n        if(!now->child[dir]) {\n            dir = !dir;\n   \
    \         return (1ULL << i) | min_element(now->child[dir], val, i - 1);\n   \
    \     } else {\n            return min_element(now->child[dir], val, i - 1);\n\
    \        }\n    }\n    ull min_element(ull val = 0) { return min_element(root,\
    \ val); }\n};\n#line 4 \"test/set_xor_min.test.cpp\"\n\nint main(){\n    int Q;\n\
    \    cin >> Q;\n    BinaryTrie btrie;\n    while(Q--) {\n        int t, x;\n \
    \       cin >> t >> x;\n        if(t == 0) {\n            btrie.insert(x);\n \
    \       } else if(t == 1) {\n            btrie.erase(x);\n        } else {\n \
    \           cout << btrie.min_element(x) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"../template/template.cpp\"\n#include \"../data_structure/binary_trie.hpp\"\
    \n\nint main(){\n    int Q;\n    cin >> Q;\n    BinaryTrie btrie;\n    while(Q--)\
    \ {\n        int t, x;\n        cin >> t >> x;\n        if(t == 0) {\n       \
    \     btrie.insert(x);\n        } else if(t == 1) {\n            btrie.erase(x);\n\
    \        } else {\n            cout << btrie.min_element(x) << \"\\n\";\n    \
    \    }\n    }\n}"
  dependsOn:
  - template/template.cpp
  - data_structure/binary_trie.hpp
  isVerificationFile: true
  path: test/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2021-10-12 21:25:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/set_xor_min.test.cpp
- /verify/test/set_xor_min.test.cpp.html
title: test/set_xor_min.test.cpp
---
