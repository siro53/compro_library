---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/set_xor_min.test.cpp
    title: test/set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_trie.hpp\"\nstruct BinaryTrie {\n\
    \    static const int B = 64;\n    using ull = uint64_t;\n    struct Node {\n\
    \        int cnt;\n        Node *child[2];\n        Node() : cnt(0), child{nullptr,\
    \ nullptr} {}\n    };\n    Node *root;\n    BinaryTrie() : root(nullptr) {}\n\
    \    int count(ull val) const {\n        if(!root) {\n            return 0;\n\
    \        }\n        Node *now = root;\n        for(int i = B - 1; i >= 0; i--)\
    \ {\n            now = now->child[(val >> i) & 1ULL];\n            if(!now) {\n\
    \                return 0;\n            }\n        }\n        return now->cnt;\n\
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
    \ val); }\n};\n"
  code: "struct BinaryTrie {\n    static const int B = 64;\n    using ull = uint64_t;\n\
    \    struct Node {\n        int cnt;\n        Node *child[2];\n        Node()\
    \ : cnt(0), child{nullptr, nullptr} {}\n    };\n    Node *root;\n    BinaryTrie()\
    \ : root(nullptr) {}\n    int count(ull val) const {\n        if(!root) {\n  \
    \          return 0;\n        }\n        Node *now = root;\n        for(int i\
    \ = B - 1; i >= 0; i--) {\n            now = now->child[(val >> i) & 1ULL];\n\
    \            if(!now) {\n                return 0;\n            }\n        }\n\
    \        return now->cnt;\n    }\n    Node *insert(Node *now, ull val, int i =\
    \ B - 1) {\n        if(!now) {\n            now = new Node();\n        }\n   \
    \     now->cnt++;\n        if(i < 0) {\n            return now;\n        }\n \
    \       bool dir = (val >> i) & 1ULL;\n        now->child[dir] = insert(now->child[dir],\
    \ val, i - 1);\n        return now;\n    }\n    void insert(ull val) {\n     \
    \   if(count(val)) {\n            return;\n        }\n        root = insert(root,\
    \ val);\n    }\n    Node *erase(Node *now, ull val, int i = B - 1) {\n       \
    \ assert(now);\n        now->cnt--;\n        if(now->cnt == 0) {\n           \
    \ return nullptr;\n        }\n        if(i < 0) {\n            return now;\n \
    \       }\n        bool dir = (val >> i) & 1ULL;\n        now->child[dir] = erase(now->child[dir],\
    \ val, i - 1);\n        return now;\n    }\n    void erase(ull val) {\n      \
    \  if(count(val) == 0) {\n            return;\n        }\n        root = erase(root,\
    \ val);\n    }\n    ull min_element(Node *now, ull val, int i = B - 1) {\n   \
    \     assert(now);\n        if(i < 0) {\n            return 0;\n        }\n  \
    \      bool dir = (val >> i) & 1ULL;\n        if(!now->child[dir]) {\n       \
    \     dir = !dir;\n            return (1ULL << i) | min_element(now->child[dir],\
    \ val, i - 1);\n        } else {\n            return min_element(now->child[dir],\
    \ val, i - 1);\n        }\n    }\n    ull min_element(ull val = 0) { return min_element(root,\
    \ val); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---
