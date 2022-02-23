---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: data_structure/rangeBIT.hpp
    title: range BIT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rangeBIT.test.cpp
    title: test/rangeBIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_inversions_query.test.cpp
    title: test/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/staticrangesum.test.cpp
    title: test/staticrangesum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/BIT.hpp\"\ntemplate <typename T> struct BIT\
    \ {\n    int n;\n    vector<T> bit;\n    BIT(){}\n    BIT(int _n) { init(_n);\
    \ }\n    void init(int _n) {\n        n = _n + 1;\n        bit.resize(n + 1, 0);\n\
    \    }\n    // [0, k)\n    T sum(int k) {\n        T res = 0;\n        for(int\
    \ i = k - 1; i >= 0; i = (i & (i + 1)) - 1) { res += bit[i]; }\n        return\
    \ res;\n    }\n    // [l, r)\n    T sum(int l, int r) { return (l < r ? sum(r)\
    \ - sum(l) : 0); }\n    // bit[k] += x\n    void add(int k, T x) {\n        for(int\
    \ i = k; i < n; i |= i + 1) { bit[i] += x; }\n    }\n    // v[0] + ... + v[res]\
    \ >= x\n    int lower_bound(T x) {\n        int res = -1;\n        int k = 1;\n\
    \        while(2 * k <= n) { k <<= 1; }\n        for(; k > 0; k >>= 1) {\n   \
    \         if(res + k < n && bit[res + k] < x) {\n                x -= bit[res\
    \ + k];\n                res += k;\n            }\n        }\n        return res\
    \ + 1;\n    }\n};\n"
  code: "template <typename T> struct BIT {\n    int n;\n    vector<T> bit;\n    BIT(){}\n\
    \    BIT(int _n) { init(_n); }\n    void init(int _n) {\n        n = _n + 1;\n\
    \        bit.resize(n + 1, 0);\n    }\n    // [0, k)\n    T sum(int k) {\n   \
    \     T res = 0;\n        for(int i = k - 1; i >= 0; i = (i & (i + 1)) - 1) {\
    \ res += bit[i]; }\n        return res;\n    }\n    // [l, r)\n    T sum(int l,\
    \ int r) { return (l < r ? sum(r) - sum(l) : 0); }\n    // bit[k] += x\n    void\
    \ add(int k, T x) {\n        for(int i = k; i < n; i |= i + 1) { bit[i] += x;\
    \ }\n    }\n    // v[0] + ... + v[res] >= x\n    int lower_bound(T x) {\n    \
    \    int res = -1;\n        int k = 1;\n        while(2 * k <= n) { k <<= 1; }\n\
    \        for(; k > 0; k >>= 1) {\n            if(res + k < n && bit[res + k] <\
    \ x) {\n                x -= bit[res + k];\n                res += k;\n      \
    \      }\n        }\n        return res + 1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/BIT.hpp
  requiredBy:
  - data_structure/rangeBIT.hpp
  - data_structure/inversion_number.hpp
  timestamp: '2021-09-04 16:29:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_range_inversions_query.test.cpp
  - test/rangeBIT.test.cpp
  - test/inversion_number.test.cpp
  - test/staticrangesum.test.cpp
documentation_of: data_structure/BIT.hpp
layout: document
title: Binary Indexed Tree
---

## 内容
- 1点更新区間sum取得が出来るデータ構造
- segtree より定数倍が良い

## 使い方
- `sum(k)`: $[0, k)$の和を求める
- `sum(l, r)`: $[l, r)$の和を求める。$l \geq r$の時は0を返す
- `add(k, x)`: index $k$ に$x$を足す
- `lower_bound(x)`: $[0, r)$のsumが$x$以上になるような最小の$r$を返す

## 計算量
- `add`,`sum`,`lower_bound`は全て$O(\log{N})$