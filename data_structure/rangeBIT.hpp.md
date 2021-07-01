---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/BIT.hpp
    title: data_structure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rangeBIT.test.cpp
    title: test/rangeBIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/BIT.hpp\"\ntemplate <typename T> struct BIT\
    \ {\n    int n;\n    vector<T> bit;\n    BIT(int _n) { init(_n); }\n    void init(int\
    \ _n) {\n        n = _n + 1;\n        bit.resize(n + 1, 0);\n    }\n    // [0,\
    \ k)\n    T sum(int k) {\n        T res = 0;\n        for(int i = k - 1; i >=\
    \ 0; i = (i & (i + 1)) - 1) { res += bit[i]; }\n        return res;\n    }\n \
    \   // [l, r)\n    T sum(int l, int r) { return (l < r ? sum(r) - sum(l) : 0);\
    \ }\n    // bit[k] += x\n    void add(int k, T x) {\n        for(int i = k; i\
    \ < n; i |= i + 1) { bit[i] += x; }\n    }\n    // v[0] + ... + v[res] >= x\n\
    \    int lower_bound(T x) {\n        int res = -1;\n        int k = 1;\n     \
    \   while(2 * k <= n) { k <<= 1; }\n        for(; k > 0; k >>= 1) {\n        \
    \    if(res + k < n && bit[res + k] < x) {\n                x -= bit[res + k];\n\
    \                res += k;\n            }\n        }\n        return res + 1;\n\
    \    }\n};\n#line 2 \"data_structure/rangeBIT.hpp\"\n\ntemplate<class T>\nstruct\
    \ rangeBIT {\n    BIT<T> p, q;\n    rangeBIT(){}\n    rangeBIT(int n): p(n+1),\
    \ q(n+1) {}\n    void add(int l, int r, T val) { // [l, r)\u306Bval\u3092\u52A0\
    \u7B97\n        p.add(l, -val * l);\n        p.add(r, val * r);\n        q.add(l,\
    \ val);\n        q.add(r, -val);\n    }\n    void add(int i, T val) {\n      \
    \  add(i, i+1, val);\n    }\n    T sum(int r) { // [0, r)\n        return p.sum(r)\
    \ + q.sum(r) * r;\n    }\n    T sum(int l, int r) { // [l, r)\n        assert(l\
    \ <= r);\n        return sum(r) - sum(l);\n    }\n};\n"
  code: "#include \"./BIT.hpp\"\n\ntemplate<class T>\nstruct rangeBIT {\n    BIT<T>\
    \ p, q;\n    rangeBIT(){}\n    rangeBIT(int n): p(n+1), q(n+1) {}\n    void add(int\
    \ l, int r, T val) { // [l, r)\u306Bval\u3092\u52A0\u7B97\n        p.add(l, -val\
    \ * l);\n        p.add(r, val * r);\n        q.add(l, val);\n        q.add(r,\
    \ -val);\n    }\n    void add(int i, T val) {\n        add(i, i+1, val);\n   \
    \ }\n    T sum(int r) { // [0, r)\n        return p.sum(r) + q.sum(r) * r;\n \
    \   }\n    T sum(int l, int r) { // [l, r)\n        assert(l <= r);\n        return\
    \ sum(r) - sum(l);\n    }\n};"
  dependsOn:
  - data_structure/BIT.hpp
  isVerificationFile: false
  path: data_structure/rangeBIT.hpp
  requiredBy: []
  timestamp: '2021-05-06 11:13:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rangeBIT.test.cpp
documentation_of: data_structure/rangeBIT.hpp
layout: document
redirect_from:
- /library/data_structure/rangeBIT.hpp
- /library/data_structure/rangeBIT.hpp.html
title: data_structure/rangeBIT.hpp
---
