---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/inversion_number.hpp
    title: data_structure/inversion_number.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/rangeBIT.hpp
    title: data_structure/rangeBIT.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rangeBIT.test.cpp
    title: test/rangeBIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/staticrangesum.test.cpp
    title: test/staticrangesum.test.cpp
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
    \    }\n};\n"
  code: "template <typename T> struct BIT {\n    int n;\n    vector<T> bit;\n    BIT(int\
    \ _n) { init(_n); }\n    void init(int _n) {\n        n = _n + 1;\n        bit.resize(n\
    \ + 1, 0);\n    }\n    // [0, k)\n    T sum(int k) {\n        T res = 0;\n   \
    \     for(int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) { res += bit[i]; }\n \
    \       return res;\n    }\n    // [l, r)\n    T sum(int l, int r) { return (l\
    \ < r ? sum(r) - sum(l) : 0); }\n    // bit[k] += x\n    void add(int k, T x)\
    \ {\n        for(int i = k; i < n; i |= i + 1) { bit[i] += x; }\n    }\n    //\
    \ v[0] + ... + v[res] >= x\n    int lower_bound(T x) {\n        int res = -1;\n\
    \        int k = 1;\n        while(2 * k <= n) { k <<= 1; }\n        for(; k >\
    \ 0; k >>= 1) {\n            if(res + k < n && bit[res + k] < x) {\n         \
    \       x -= bit[res + k];\n                res += k;\n            }\n       \
    \ }\n        return res + 1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/BIT.hpp
  requiredBy:
  - data_structure/rangeBIT.hpp
  - data_structure/inversion_number.hpp
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rangeBIT.test.cpp
  - test/staticrangesum.test.cpp
  - test/inversion_number.test.cpp
documentation_of: data_structure/BIT.hpp
layout: document
redirect_from:
- /library/data_structure/BIT.hpp
- /library/data_structure/BIT.hpp.html
title: data_structure/BIT.hpp
---
