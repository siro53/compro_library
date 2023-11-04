---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/range-BIT.hpp
    title: data-structure/range-BIT.hpp
  - icon: ':heavy_check_mark:'
    path: misc/inversion-number.hpp
    title: "\u8EE2\u5012\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-5-D.test.cpp
    title: test/aoj/aoj-ALDS1-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/point-add-range-sum.test.cpp
    title: test/library-checker/data-structure/point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
    title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-sum.test.cpp
    title: test/library-checker/data-structure/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/BIT.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename T> class BIT {\n  public:\n    BIT() = default;\n\
    \    explicit BIT(int N) : N(N), dat(N + 1, 0) {}\n    T sum(int r) {\n      \
    \  T ret = 0;\n        for(; r >= 1; r -= lsb(r)) ret += dat[r];\n        return\
    \ ret;\n    }\n    T sum(int l, int r) {\n        assert(l <= r);\n        if(l\
    \ == r) return T(0);\n        return (sum(r) - sum(l));\n    }\n    void add(int\
    \ pos, T val) {\n        for(int i = pos + 1; i <= N; i += lsb(i)) dat[i] += val;\n\
    \    }\n    int lower_bound(T val) {\n        int pos = 0;\n        int k = 1;\n\
    \        while(2 * k <= N) k <<= 1;\n        for(; k >= 1; k >>= 1) {\n      \
    \      if(pos + k <= N and dat[pos + k] < val) {\n                pos += k;\n\
    \                val -= dat[pos];\n            }\n        }\n        return pos\
    \ + 1;\n    }\n\n  private:\n    int N;\n    std::vector<T> dat;\n\n    inline\
    \ int lsb(int i) { return i & (-i); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> class BIT {\n  public:\n    BIT() = default;\n    explicit BIT(int N) : N(N),\
    \ dat(N + 1, 0) {}\n    T sum(int r) {\n        T ret = 0;\n        for(; r >=\
    \ 1; r -= lsb(r)) ret += dat[r];\n        return ret;\n    }\n    T sum(int l,\
    \ int r) {\n        assert(l <= r);\n        if(l == r) return T(0);\n       \
    \ return (sum(r) - sum(l));\n    }\n    void add(int pos, T val) {\n        for(int\
    \ i = pos + 1; i <= N; i += lsb(i)) dat[i] += val;\n    }\n    int lower_bound(T\
    \ val) {\n        int pos = 0;\n        int k = 1;\n        while(2 * k <= N)\
    \ k <<= 1;\n        for(; k >= 1; k >>= 1) {\n            if(pos + k <= N and\
    \ dat[pos + k] < val) {\n                pos += k;\n                val -= dat[pos];\n\
    \            }\n        }\n        return pos + 1;\n    }\n\n  private:\n    int\
    \ N;\n    std::vector<T> dat;\n\n    inline int lsb(int i) { return i & (-i);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/BIT.hpp
  requiredBy:
  - misc/inversion-number.hpp
  - data-structure/range-BIT.hpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - test/library-checker/data-structure/point-add-range-sum.test.cpp
  - test/library-checker/data-structure/static-range-sum.test.cpp
  - test/aoj/aoj-ALDS1-5-D.test.cpp
documentation_of: data-structure/BIT.hpp
layout: document
redirect_from:
- /library/data-structure/BIT.hpp
- /library/data-structure/BIT.hpp.html
title: data-structure/BIT.hpp
---
