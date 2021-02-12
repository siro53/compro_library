---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/staticrmq.test.cpp
    title: test/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segtree/segtree.hpp\"\ntemplate <typename\
    \ Monoid> struct SegmentTree {\n    using F = function<Monoid(Monoid, Monoid)>;\n\
    \n  private:\n    int n;\n    vector<Monoid> node;\n    Monoid E;\n    F f;\n\n\
    \  public:\n    SegmentTree(vector<Monoid> &v, Monoid e, const F func) : f(func),\
    \ E(e) {\n        int sz = v.size();\n        n = 1;\n        while(n < sz) {\n\
    \            n *= 2;\n        }\n        node.resize(2 * n - 1, E);\n        for(int\
    \ i = 0; i < sz; i++) {\n            node[i + n - 1] = v[i];\n        }\n    \
    \    for(int i = n - 2; i >= 0; i--) {\n            node[i] = f(node[2 * i + 1],\
    \ node[2 * i + 2]);\n        }\n    }\n\n    void update(int i, Monoid val) {\n\
    \        i += (n - 1);\n        node[i] = val;\n        while(i > 0) {\n     \
    \       i = (i - 1) / 2;\n            node[i] = f(node[2 * i + 1], node[2 * i\
    \ + 2]);\n        }\n    }\n\n    Monoid query(int a, int b, int i = 0, int l\
    \ = 0, int r = -1) {\n        if(r < 0) {\n            r = n;\n        }\n   \
    \     if(r <= a || b <= l) {\n            return E;\n        }\n        if(a <=\
    \ l && r <= b) {\n            return node[i];\n        }\n        Monoid vl =\
    \ query(a, b, 2 * i + 1, l, (l + r) / 2);\n        Monoid vr = query(a, b, 2 *\
    \ i + 2, (l + r) / 2, r);\n        return f(vl, vr);\n    }\n\n    Monoid operator[](const\
    \ int &i) const { return node[i + n - 1]; }\n};\n"
  code: "template <typename Monoid> struct SegmentTree {\n    using F = function<Monoid(Monoid,\
    \ Monoid)>;\n\n  private:\n    int n;\n    vector<Monoid> node;\n    Monoid E;\n\
    \    F f;\n\n  public:\n    SegmentTree(vector<Monoid> &v, Monoid e, const F func)\
    \ : f(func), E(e) {\n        int sz = v.size();\n        n = 1;\n        while(n\
    \ < sz) {\n            n *= 2;\n        }\n        node.resize(2 * n - 1, E);\n\
    \        for(int i = 0; i < sz; i++) {\n            node[i + n - 1] = v[i];\n\
    \        }\n        for(int i = n - 2; i >= 0; i--) {\n            node[i] = f(node[2\
    \ * i + 1], node[2 * i + 2]);\n        }\n    }\n\n    void update(int i, Monoid\
    \ val) {\n        i += (n - 1);\n        node[i] = val;\n        while(i > 0)\
    \ {\n            i = (i - 1) / 2;\n            node[i] = f(node[2 * i + 1], node[2\
    \ * i + 2]);\n        }\n    }\n\n    Monoid query(int a, int b, int i = 0, int\
    \ l = 0, int r = -1) {\n        if(r < 0) {\n            r = n;\n        }\n \
    \       if(r <= a || b <= l) {\n            return E;\n        }\n        if(a\
    \ <= l && r <= b) {\n            return node[i];\n        }\n        Monoid vl\
    \ = query(a, b, 2 * i + 1, l, (l + r) / 2);\n        Monoid vr = query(a, b, 2\
    \ * i + 2, (l + r) / 2, r);\n        return f(vl, vr);\n    }\n\n    Monoid operator[](const\
    \ int &i) const { return node[i + n - 1]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree/segtree.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/staticrmq.test.cpp
documentation_of: data_structure/segtree/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree/segtree.hpp
- /library/data_structure/segtree/segtree.hpp.html
title: data_structure/segtree/segtree.hpp
---
