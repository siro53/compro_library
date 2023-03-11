---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: data-structure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-5-D.test.cpp
    title: test/aoj/aoj-ALDS1-5-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/inversion-number.hpp\"\n\n#line 2 \"data-structure/BIT.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <typename T> class BIT {\n\
    \  public:\n    BIT() = default;\n    explicit BIT(int N) : N(N), dat(N + 1, 0)\
    \ {}\n    T sum(int r) {\n        T ret = 0;\n        for(; r >= 1; r -= lsb(r))\
    \ ret += dat[r];\n        return ret;\n    }\n    T sum(int l, int r) {\n    \
    \    assert(l <= r);\n        if(l == r) return T(0);\n        return (sum(r)\
    \ - sum(l));\n    }\n    void add(int pos, T val) {\n        for(int i = pos +\
    \ 1; i <= N; i += lsb(i)) dat[i] += val;\n    }\n    int lower_bound(T val) {\n\
    \        int pos = 0;\n        int k = 1;\n        while(2 * k <= N) k <<= 1;\n\
    \        for(; k >= 1; k >>= 1) {\n            if(pos + k <= N and dat[pos + k]\
    \ < val) {\n                pos += k;\n                val -= dat[pos];\n    \
    \        }\n        }\n        return pos + 1;\n    }\n\n  private:\n    int N;\n\
    \    std::vector<T> dat;\n\n    inline int lsb(int i) { return i & (-i); }\n};\n\
    #line 4 \"misc/inversion-number.hpp\"\n\ntemplate<class T>\nT inversion_number(const\
    \ std::vector<int>& v) {\n    int N = (int)v.size();\n    BIT<int> bt(N);\n  \
    \  T res = 0;\n    for(int i = 0; i < N; i++) {\n        res += i - bt.sum(v[i]+1);\n\
    \        bt.add(v[i], 1);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"../data-structure/BIT.hpp\"\n\ntemplate<class\
    \ T>\nT inversion_number(const std::vector<int>& v) {\n    int N = (int)v.size();\n\
    \    BIT<int> bt(N);\n    T res = 0;\n    for(int i = 0; i < N; i++) {\n     \
    \   res += i - bt.sum(v[i]+1);\n        bt.add(v[i], 1);\n    }\n    return res;\n\
    }"
  dependsOn:
  - data-structure/BIT.hpp
  isVerificationFile: false
  path: misc/inversion-number.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-5-D.test.cpp
documentation_of: misc/inversion-number.hpp
layout: document
title: "\u8EE2\u5012\u6570"
---
