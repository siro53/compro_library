---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki789.test.cpp
    title: test/yukicoder/yuki789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/dynamic-segtree.hpp\"\n\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\n\ntemplate <class Monoid, long\
    \ long id_min, long long id_max>\nclass DynamicSegtree {\n  public:\n    using\
    \ T = typename Monoid::value_type;\n\n    explicit DynamicSegtree() : root(nullptr)\
    \ {}\n\n    void set(long long p, T val) { set(root, id_min, id_max, p, val);\
    \ }\n    T get(long long p) { return get(root, id_min, id_max, p); }\n    T prod(long\
    \ long l, long long r) { return prod(root, id_min, id_max, l, r); }\n \n  private:\n\
    \    struct Node {\n        T val;\n        std::array<Node *, 2> ch;\n      \
    \  Node() : val(Monoid::e()), ch({nullptr, nullptr}) {}\n        Node(T val) :\
    \ val(val), ch({nullptr, nullptr}) {}\n    };\n\n    Node *root;\n\n    void set(Node\
    \ *&node, long long l, long long r, long long p, T val) {\n        if(node ==\
    \ nullptr) node = new Node();\n        if(r - l == 1) {\n            node->val\
    \ = val;\n            return;\n        }\n        long long mid = (l + r) / 2;\n\
    \        if(p < mid)\n            set(node->ch[0], l, mid, p, val);\n        else\n\
    \            set(node->ch[1], mid, r, p, val);\n        node->val =\n        \
    \    Monoid::op(node->ch[0] == nullptr ? Monoid::e() : node->ch[0]->val,\n   \
    \                    node->ch[1] == nullptr ? Monoid::e() : node->ch[1]->val);\n\
    \    }\n\n    T get(Node *&node, long long l, long long r, long long p) {\n  \
    \      if(node == nullptr) return Monoid::e();\n        if(r - l == 1) return\
    \ node->val;\n        long long mid = (l + r) / 2;\n        if(p < mid)\n    \
    \        return get(node->ch[0], l, mid, p);\n        else\n            return\
    \ get(node->ch[1], mid, r, p);\n    }\n\n    T prod(Node *&node, long long l,\
    \ long long r, long long ql, long long qr) {\n        if(node == nullptr or (qr\
    \ <= l or r <= ql)) return Monoid::e();\n        if(ql <= l and r <= qr) return\
    \ node->val;\n        long long mid = (l + r) / 2;\n        return Monoid::op(prod(node->ch[0],\
    \ l, mid, ql, qr),\n                          prod(node->ch[1], mid, r, ql, qr));\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class Monoid, long long id_min, long long id_max>\nclass DynamicSegtree\
    \ {\n  public:\n    using T = typename Monoid::value_type;\n\n    explicit DynamicSegtree()\
    \ : root(nullptr) {}\n\n    void set(long long p, T val) { set(root, id_min, id_max,\
    \ p, val); }\n    T get(long long p) { return get(root, id_min, id_max, p); }\n\
    \    T prod(long long l, long long r) { return prod(root, id_min, id_max, l, r);\
    \ }\n \n  private:\n    struct Node {\n        T val;\n        std::array<Node\
    \ *, 2> ch;\n        Node() : val(Monoid::e()), ch({nullptr, nullptr}) {}\n  \
    \      Node(T val) : val(val), ch({nullptr, nullptr}) {}\n    };\n\n    Node *root;\n\
    \n    void set(Node *&node, long long l, long long r, long long p, T val) {\n\
    \        if(node == nullptr) node = new Node();\n        if(r - l == 1) {\n  \
    \          node->val = val;\n            return;\n        }\n        long long\
    \ mid = (l + r) / 2;\n        if(p < mid)\n            set(node->ch[0], l, mid,\
    \ p, val);\n        else\n            set(node->ch[1], mid, r, p, val);\n    \
    \    node->val =\n            Monoid::op(node->ch[0] == nullptr ? Monoid::e()\
    \ : node->ch[0]->val,\n                       node->ch[1] == nullptr ? Monoid::e()\
    \ : node->ch[1]->val);\n    }\n\n    T get(Node *&node, long long l, long long\
    \ r, long long p) {\n        if(node == nullptr) return Monoid::e();\n       \
    \ if(r - l == 1) return node->val;\n        long long mid = (l + r) / 2;\n   \
    \     if(p < mid)\n            return get(node->ch[0], l, mid, p);\n        else\n\
    \            return get(node->ch[1], mid, r, p);\n    }\n\n    T prod(Node *&node,\
    \ long long l, long long r, long long ql, long long qr) {\n        if(node ==\
    \ nullptr or (qr <= l or r <= ql)) return Monoid::e();\n        if(ql <= l and\
    \ r <= qr) return node->val;\n        long long mid = (l + r) / 2;\n        return\
    \ Monoid::op(prod(node->ch[0], l, mid, ql, qr),\n                          prod(node->ch[1],\
    \ mid, r, ql, qr));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/dynamic-segtree.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki789.test.cpp
documentation_of: data-structure/segtree/dynamic-segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree/dynamic-segtree.hpp
- /library/data-structure/segtree/dynamic-segtree.hpp.html
title: data-structure/segtree/dynamic-segtree.hpp
---
