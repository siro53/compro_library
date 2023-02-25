---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-queue.test.cpp
    title: test/library-checker/data-structure/persistent-queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent/persistent-queue.hpp\"\n\ntemplate\
    \ <class T, int LOG = 20> struct PersistentQueue {\n    struct Node {\n      \
    \  T val;\n        int idx;\n        Node *pre[LOG]; // pre[k] := \u3053\u306E\
    \u30CE\u30FC\u30C9\u306E2^k\u500B\u524D\u306E\u30CE\u30FC\u30C9\n\n        Node(T\
    \ val, int idx) : val(val), idx(idx) {}\n    };\n    Node *front_node;\n    Node\
    \ *back_node;\n\n    PersistentQueue() : front_node(nullptr), back_node(nullptr)\
    \ {}\n    explicit PersistentQueue(Node *front_node, Node *back_node)\n      \
    \  : front_node(front_node), back_node(back_node) {}\n    PersistentQueue push(const\
    \ T &x) {\n        Node *new_node = new Node(x, back_node ? back_node->idx + 1\
    \ : 0);\n        new_node->pre[0] = back_node;\n        for(int i = 1; i < LOG;\
    \ i++) {\n            Node *tmp = new_node->pre[i - 1];\n            if(!tmp)\
    \ break;\n            new_node->pre[i] = tmp->pre[i - 1];\n        }\n       \
    \ return PersistentQueue(front_node ? front_node : new_node, new_node);\n    }\n\
    \    PersistentQueue pop() {\n        if(!front_node or !back_node or front_node->idx\
    \ == back_node->idx) {\n            return PersistentQueue();\n        }\n   \
    \     int sz = back_node->idx - front_node->idx - 1;\n        Node *node = back_node;\n\
    \        for(int i = 0; i < LOG; i++)\n            if(sz >> i & 1) node = node->pre[i];\n\
    \        return PersistentQueue(node, back_node);\n    }\n    bool empty() const\
    \ { return (front_node == nullptr and back_node == nullptr); }\n    T front()\
    \ const { return front_node->val; }\n    T back() const { return back_node->val;\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class T, int LOG = 20> struct PersistentQueue {\n\
    \    struct Node {\n        T val;\n        int idx;\n        Node *pre[LOG];\
    \ // pre[k] := \u3053\u306E\u30CE\u30FC\u30C9\u306E2^k\u500B\u524D\u306E\u30CE\
    \u30FC\u30C9\n\n        Node(T val, int idx) : val(val), idx(idx) {}\n    };\n\
    \    Node *front_node;\n    Node *back_node;\n\n    PersistentQueue() : front_node(nullptr),\
    \ back_node(nullptr) {}\n    explicit PersistentQueue(Node *front_node, Node *back_node)\n\
    \        : front_node(front_node), back_node(back_node) {}\n    PersistentQueue\
    \ push(const T &x) {\n        Node *new_node = new Node(x, back_node ? back_node->idx\
    \ + 1 : 0);\n        new_node->pre[0] = back_node;\n        for(int i = 1; i <\
    \ LOG; i++) {\n            Node *tmp = new_node->pre[i - 1];\n            if(!tmp)\
    \ break;\n            new_node->pre[i] = tmp->pre[i - 1];\n        }\n       \
    \ return PersistentQueue(front_node ? front_node : new_node, new_node);\n    }\n\
    \    PersistentQueue pop() {\n        if(!front_node or !back_node or front_node->idx\
    \ == back_node->idx) {\n            return PersistentQueue();\n        }\n   \
    \     int sz = back_node->idx - front_node->idx - 1;\n        Node *node = back_node;\n\
    \        for(int i = 0; i < LOG; i++)\n            if(sz >> i & 1) node = node->pre[i];\n\
    \        return PersistentQueue(node, back_node);\n    }\n    bool empty() const\
    \ { return (front_node == nullptr and back_node == nullptr); }\n    T front()\
    \ const { return front_node->val; }\n    T back() const { return back_node->val;\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent/persistent-queue.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/persistent-queue.test.cpp
documentation_of: data-structure/persistent/persistent-queue.hpp
layout: document
redirect_from:
- /library/data-structure/persistent/persistent-queue.hpp
- /library/data-structure/persistent/persistent-queue.hpp.html
title: data-structure/persistent/persistent-queue.hpp
---
