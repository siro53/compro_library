---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/set-xor-min.test.cpp
    title: test/library-checker/data-structure/set-xor-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/binary-trie.test.cpp
    title: test/mytest/data-structure/binary-trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/binary-trie.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\ntemplate <typename T = unsigned\
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
    \    Node *root;\n    T lazy_xor_value;\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T = unsigned int, int LOG = 32> class\
    \ BinaryTrie {\n  public:\n    explicit BinaryTrie() : root(nullptr), lazy_xor_value(0)\
    \ {}\n    int count(T val) {\n        if(!root) return 0;\n        Node *now =\
    \ root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            now = now->child[val\
    \ >> i & 1];\n            if(!now or now->count == 0) return 0;\n        }\n \
    \       return now->count;\n    }\n    void insert(T val) {\n        if(!root)\
    \ root = new Node();\n        Node *now = root;\n        now->count++;\n     \
    \   for(int i = LOG - 1; i >= 0; i--) {\n            int dir = val >> i & 1;\n\
    \            Node *nxt = now->child[dir];\n            if(!nxt) {\n          \
    \      nxt = new Node();\n                now->child[dir] = nxt;\n           \
    \ }\n            now = nxt;\n            now->count++;\n        }\n    }\n   \
    \ bool erase(T val) {\n        if(count(val) == 0) return false;\n        Node\
    \ *now = root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            now->count--;\n\
    \            now = now->child[val >> i & 1];\n            assert(now != nullptr);\n\
    \            assert(now->count > 0);\n        }\n        now->count--;\n     \
    \   return true;\n    }\n    T min_element() {\n        assert(root != nullptr);\n\
    \        T ret = 0;\n        Node *now = root;\n        for(int i = LOG - 1; i\
    \ >= 0; i--) {\n            int dir = (lazy_xor_value >> i & 1);\n           \
    \ Node *nxt = now->child[dir];\n            if(!nxt or nxt->count == 0) {\n  \
    \              ret += T(1) << i;\n                nxt = now->child[dir ^ 1];\n\
    \            }\n            now = nxt;\n            assert(now != nullptr and\
    \ now->count > 0);\n        }\n        return ret;\n    }\n    T max_element()\
    \ {\n        assert(root != nullptr);\n        T ret = 0;\n        Node *now =\
    \ root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            int dir = (lazy_xor_value\
    \ >> i & 1) ^ 1;\n            Node *nxt = now->child[dir];\n            if(!nxt\
    \ or nxt->count == 0) {\n                nxt = now->child[dir ^ 1];\n        \
    \    } else {\n                ret += T(1) << i;\n            }\n            now\
    \ = nxt;\n            assert(now != nullptr and now->count > 0);\n        }\n\
    \        return ret;\n    }\n    T get_kth_element(int k) { // \u5C0F\u3055\u3044\
    \u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024(0-indexed)\n        assert(0 <= k\
    \ and k < size());\n        Node *now = root;\n        T ret = 0;\n        for(int\
    \ i = LOG - 1; i >= 0; i--) {\n            int b = lazy_xor_value >> i & 1;\n\
    \            int small_count = (now->child[b] ? now->child[b]->count : 0);\n \
    \           int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count : 0);\n\
    \            assert(0 < small_count + big_count);\n            assert(k < small_count\
    \ + big_count);\n            if(k >= small_count) {\n                ret += T(1)\
    \ << i;\n                now = now->child[b ^ 1];\n                k -= small_count;\n\
    \            } else {\n                now = now->child[b];\n            }\n \
    \       }\n        return ret;\n    }\n    int lower_bound(T val) {\n        int\
    \ ret = 0;\n        Node* now = root;\n        for(int i = LOG - 1; i >= 0; i--)\
    \ {\n            int b = lazy_xor_value >> i & 1;\n            int small_count\
    \ = (now->child[b] ? now->child[b]->count : 0);\n            int big_count = (now->child[b\
    \ ^ 1] ? now->child[b ^ 1]->count : 0);\n            if(small_count == 0) {\n\
    \                assert(big_count);\n                now = now->child[b ^ 1];\n\
    \            } else if(big_count == 0) {\n                assert(small_count);\n\
    \                now = now->child[b];\n            } else {\n                if(b\
    \ == (val >> i & 1)) { \n                    now = now->child[b];\n          \
    \      } else {\n                    ret += small_count;\n                   \
    \ now = now->child[b ^ 1];\n                }\n            }\n        }\n    \
    \    return ret;\n    }\n    int upper_bound(T val) {\n        int id = lower_bound(val);\n\
    \        T kth_element = get_kth_element(id);\n        if(kth_element != val)\
    \ return id;\n        int cnt = count(kth_element);\n        return id + cnt;\n\
    \    }\n    int size() const {\n        if(!root) return 0;\n        return root->count;\n\
    \    }\n    inline bool empty() const { return (!root or root->count == 0); }\n\
    \    void all_xor(T val) { lazy_xor_value ^= val; }\n\n  private:\n    struct\
    \ Node {\n        int count;\n        std::array<Node *, 2> child;\n        Node()\
    \ : count(0), child({nullptr, nullptr}) {}\n    };\n    Node *root;\n    T lazy_xor_value;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/set-xor-min.test.cpp
  - test/mytest/data-structure/binary-trie.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/data-structure/binary-trie.hpp
- /library/data-structure/binary-trie.hpp.html
title: data-structure/binary-trie.hpp
---
