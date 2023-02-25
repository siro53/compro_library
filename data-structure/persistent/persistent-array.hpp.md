---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-unionfind.hpp
    title: data-structure/persistent/persistent-unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-unionfind.test.cpp
    title: test/library-checker/data-structure/persistent-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent/persistent-array.hpp\"\n\n#include\
    \ <string.h>\n#include <utility>\n#include <vector>\n\ntemplate <class T, int\
    \ LOG = 4> struct PersistentArray {\n    struct Node {\n        T val;\n     \
    \   Node *childs[1 << LOG];\n\n        Node() { memset(childs, 0, sizeof(childs));\
    \ }\n        Node(const Node *node) { memcpy(childs, node->childs, sizeof(childs));\
    \ }\n        Node(const Node &node) { memcpy(childs, node.childs, sizeof(childs));\
    \ }\n    };\n\n    Node *root;\n    int depth;\n    T identity;\n    const int\
    \ full_bit = (1 << LOG) - 1;\n\n    PersistentArray() {}\n    explicit PersistentArray(int\
    \ N, const T &id = 0)\n        : root(new Node()), depth(0), identity(id) {\n\
    \        PersistentArray(std::vector<T>(N, id));\n    }\n    PersistentArray(const\
    \ std::vector<T> &v) : root(new Node()), depth(0) {\n        int N = (int)v.size();\n\
    \        while(N > 0) {\n            N >>= LOG;\n            depth++;\n      \
    \  }\n        N = (int)v.size();\n        for(int i = 0; i < N; i++) {\n     \
    \       Node *now = root;\n            for(int mask = i, d = depth; d > 0; d--)\
    \ {\n                if(!now->childs[mask & full_bit]) {\n                   \
    \ now->childs[mask & full_bit] = new Node();\n                }\n            \
    \    now = now->childs[mask & full_bit];\n                mask >>= LOG;\n    \
    \        }\n            now->val = v[i];\n        }\n    }\n\n    T get(int idx)\
    \ { return get(root, idx); }\n\n    Node *set(int idx, const T &new_value) { return\
    \ set(root, idx, new_value); }\n\n    T get(Node *node, int idx) {\n        for(int\
    \ i = 0; i < depth; i++) {\n            node = node ? node->childs[idx & full_bit]\
    \ : nullptr;\n            idx >>= LOG;\n        }\n        return (node ? node->val\
    \ : identity);\n    }\n\n    Node *set(Node *node, int idx, T new_value) {\n \
    \       std::vector<std::pair<Node *, int>> st;\n        for(int i = 0; i < depth;\
    \ i++) {\n            st.emplace_back(node, idx & full_bit);\n            node\
    \ = node ? node->childs[idx & full_bit] : nullptr;\n            idx >>= LOG;\n\
    \        }\n        Node *new_child = new Node();\n        new_child->val = new_value;\n\
    \        while(!st.empty()) {\n            auto [par, k] = st.back();\n      \
    \      st.pop_back();\n            Node *new_par = par ? new Node(par) : new Node();\n\
    \            new_par->childs[k] = new_child;\n            new_child = new_par;\n\
    \        }\n        return (root = new_child);\n    }\n};\n"
  code: "#pragma once\n\n#include <string.h>\n#include <utility>\n#include <vector>\n\
    \ntemplate <class T, int LOG = 4> struct PersistentArray {\n    struct Node {\n\
    \        T val;\n        Node *childs[1 << LOG];\n\n        Node() { memset(childs,\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent/persistent-array.hpp
  requiredBy:
  - data-structure/persistent/persistent-unionfind.hpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/persistent-unionfind.test.cpp
documentation_of: data-structure/persistent/persistent-array.hpp
layout: document
redirect_from:
- /library/data-structure/persistent/persistent-array.hpp
- /library/data-structure/persistent/persistent-array.hpp.html
title: data-structure/persistent/persistent-array.hpp
---
