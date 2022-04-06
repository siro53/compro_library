---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/staticrmq.test.cpp
    title: test/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segtree/segtree.hpp\"\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)()> class segtree {\n    int N, sz;\n    vector<S> node;\n\
    \n  public:\n    segtree() {}\n    segtree(vector<S> v) : N(int(v.size())) {\n\
    \        sz = 1;\n        while(sz < N) sz <<= 1;\n        node.resize(2 * sz,\
    \ e());\n        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n        for(int\
    \ i = sz - 1; i >= 1; i--)\n            node[i] = op(node[2 * i], node[2 * i +\
    \ 1]);\n    }\n    segtree(int n) : segtree(vector<S>(n, e())) {}\n    void set(int\
    \ p, S val) {\n        p += sz;\n        node[p] = val;\n        while(p >>= 1)\
    \ node[p] = op(node[2 * p], node[2 * p + 1]);\n    }\n    S get(int p) { return\
    \ node[p + sz]; }\n    S prod(int l, int r) {\n        S vl = e(), vr = e();\n\
    \        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n            if(l &\
    \ 1) vl = op(vl, node[l++]);\n            if(r & 1) vr = op(vr, node[--r]);\n\
    \        }\n        return op(vl, vr);\n    }\n    S all_prod() { return node[1];\
    \ }\n};\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> class segtree {\n    int N, sz;\n\
    \    vector<S> node;\n\n  public:\n    segtree() {}\n    segtree(vector<S> v)\
    \ : N(int(v.size())) {\n        sz = 1;\n        while(sz < N) sz <<= 1;\n   \
    \     node.resize(2 * sz, e());\n        for(int i = 0; i < N; i++) node[i + sz]\
    \ = v[i];\n        for(int i = sz - 1; i >= 1; i--)\n            node[i] = op(node[2\
    \ * i], node[2 * i + 1]);\n    }\n    segtree(int n) : segtree(vector<S>(n, e()))\
    \ {}\n    void set(int p, S val) {\n        p += sz;\n        node[p] = val;\n\
    \        while(p >>= 1) node[p] = op(node[2 * p], node[2 * p + 1]);\n    }\n \
    \   S get(int p) { return node[p + sz]; }\n    S prod(int l, int r) {\n      \
    \  S vl = e(), vr = e();\n        for(l += sz, r += sz; l < r; l >>= 1, r >>=\
    \ 1) {\n            if(l & 1) vl = op(vl, node[l++]);\n            if(r & 1) vr\
    \ = op(vr, node[--r]);\n        }\n        return op(vl, vr);\n    }\n    S all_prod()\
    \ { return node[1]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree/segtree.hpp
  requiredBy: []
  timestamp: '2022-04-06 16:19:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/staticrmq.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/vertex_set_path_composite.test.cpp
documentation_of: data_structure/segtree/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree/segtree.hpp
- /library/data_structure/segtree/segtree.hpp.html
title: data_structure/segtree/segtree.hpp
---
