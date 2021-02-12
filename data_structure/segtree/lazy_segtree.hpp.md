---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segtree/lazy_segtree.hpp\"\ntemplate <typename\
    \ T, typename E> struct LazySegmentTree {\n    using F = function<T(T, T)>;\n\
    \    using G = function<T(T, E)>;\n    using H = function<E(E, E)>;\n    using\
    \ P = function<E(E, int)>;\n    F f;\n    G g;\n    H h;\n    P p;\n    T d1;\n\
    \    E d0;\n    int n;\n    vector<T> node;\n    vector<E> lazy;\n\n    LazySegmentTree(\n\
    \        int sz, F f, G g, H h, T d1, E d0, vector<T> v = vector<T>(),\n     \
    \   P p = [](E a, int b) { return a; })\n        : f(f), g(g), h(h), d1(d1), d0(d0),\
    \ p(p) {\n        init(sz);\n        if(sz == (int)v.size()) {\n            build(sz,\
    \ v);\n        }\n    }\n\n    void init(int sz) {\n        n = 1;\n        while(n\
    \ < sz) {\n            n *= 2;\n        }\n        node.clear();\n        node.resize(2\
    \ * n - 1, d1);\n        lazy.clear();\n        lazy.resize(2 * n - 1, d0);\n\
    \    }\n\n    void build(int sz, vector<T> v) {\n        for(int i = 0; i < sz;\
    \ i++) {\n            node[i + n - 1] = v[i];\n        }\n        for(int i =\
    \ n - 2; i >= 0; i--) {\n            node[i] = f(node[2 * i + 1], node[2 * i +\
    \ 2]);\n        }\n    }\n\n    inline void eval(int len, int now) {\n       \
    \ if(lazy[now] == d0) {\n            return;\n        }\n        if(2 * now +\
    \ 1 < 2 * n - 1) {\n            lazy[2 * now + 1] = h(lazy[2 * now + 1], lazy[now]);\n\
    \            lazy[2 * now + 2] = h(lazy[2 * now + 2], lazy[now]);\n        }\n\
    \        node[now] = g(node[now], p(lazy[now], len));\n        lazy[now] = d0;\n\
    \    }\n\n    T update(int a, int b, E x, int now = 0, int l = 0, int r = -1)\
    \ {\n        if(r < 0) {\n            r = n;\n        }\n        eval(r - l, now);\n\
    \        if(r <= a || b <= l) {\n            return node[now];\n        }\n  \
    \      if(a <= l && r <= b) {\n            lazy[now] = h(lazy[now], x);\n    \
    \        return g(node[now], p(lazy[now], r - l));\n        }\n        T vl =\
    \ update(a, b, x, 2 * now + 1, l, (l + r) / 2);\n        T vr = update(a, b, x,\
    \ 2 * now + 2, (l + r) / 2, r);\n        return node[now] = f(vl, vr);\n    }\n\
    \n    T query(int a, int b, int now = 0, int l = 0, int r = -1) {\n        if(r\
    \ < 0) {\n            r = n;\n        }\n        eval(r - l, now);\n        if(r\
    \ <= a || b <= l) {\n            return d1;\n        }\n        if(a <= l && r\
    \ <= b) {\n            return node[now];\n        }\n        T vl = query(a, b,\
    \ 2 * now + 1, l, (l + r) / 2);\n        T vr = query(a, b, 2 * now + 2, (l +\
    \ r) / 2, r);\n        return f(vl, vr);\n    }\n};\n"
  code: "template <typename T, typename E> struct LazySegmentTree {\n    using F =\
    \ function<T(T, T)>;\n    using G = function<T(T, E)>;\n    using H = function<E(E,\
    \ E)>;\n    using P = function<E(E, int)>;\n    F f;\n    G g;\n    H h;\n   \
    \ P p;\n    T d1;\n    E d0;\n    int n;\n    vector<T> node;\n    vector<E> lazy;\n\
    \n    LazySegmentTree(\n        int sz, F f, G g, H h, T d1, E d0, vector<T> v\
    \ = vector<T>(),\n        P p = [](E a, int b) { return a; })\n        : f(f),\
    \ g(g), h(h), d1(d1), d0(d0), p(p) {\n        init(sz);\n        if(sz == (int)v.size())\
    \ {\n            build(sz, v);\n        }\n    }\n\n    void init(int sz) {\n\
    \        n = 1;\n        while(n < sz) {\n            n *= 2;\n        }\n   \
    \     node.clear();\n        node.resize(2 * n - 1, d1);\n        lazy.clear();\n\
    \        lazy.resize(2 * n - 1, d0);\n    }\n\n    void build(int sz, vector<T>\
    \ v) {\n        for(int i = 0; i < sz; i++) {\n            node[i + n - 1] = v[i];\n\
    \        }\n        for(int i = n - 2; i >= 0; i--) {\n            node[i] = f(node[2\
    \ * i + 1], node[2 * i + 2]);\n        }\n    }\n\n    inline void eval(int len,\
    \ int now) {\n        if(lazy[now] == d0) {\n            return;\n        }\n\
    \        if(2 * now + 1 < 2 * n - 1) {\n            lazy[2 * now + 1] = h(lazy[2\
    \ * now + 1], lazy[now]);\n            lazy[2 * now + 2] = h(lazy[2 * now + 2],\
    \ lazy[now]);\n        }\n        node[now] = g(node[now], p(lazy[now], len));\n\
    \        lazy[now] = d0;\n    }\n\n    T update(int a, int b, E x, int now = 0,\
    \ int l = 0, int r = -1) {\n        if(r < 0) {\n            r = n;\n        }\n\
    \        eval(r - l, now);\n        if(r <= a || b <= l) {\n            return\
    \ node[now];\n        }\n        if(a <= l && r <= b) {\n            lazy[now]\
    \ = h(lazy[now], x);\n            return g(node[now], p(lazy[now], r - l));\n\
    \        }\n        T vl = update(a, b, x, 2 * now + 1, l, (l + r) / 2);\n   \
    \     T vr = update(a, b, x, 2 * now + 2, (l + r) / 2, r);\n        return node[now]\
    \ = f(vl, vr);\n    }\n\n    T query(int a, int b, int now = 0, int l = 0, int\
    \ r = -1) {\n        if(r < 0) {\n            r = n;\n        }\n        eval(r\
    \ - l, now);\n        if(r <= a || b <= l) {\n            return d1;\n       \
    \ }\n        if(a <= l && r <= b) {\n            return node[now];\n        }\n\
    \        T vl = query(a, b, 2 * now + 1, l, (l + r) / 2);\n        T vr = query(a,\
    \ b, 2 * now + 2, (l + r) / 2, r);\n        return f(vl, vr);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segtree/lazy_segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree/lazy_segtree.hpp
- /library/data_structure/segtree/lazy_segtree.hpp.html
title: data_structure/segtree/lazy_segtree.hpp
---
