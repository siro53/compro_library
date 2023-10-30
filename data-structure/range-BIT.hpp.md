---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: data-structure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/range-BIT.hpp\"\n\n#line 2 \"data-structure/BIT.hpp\"\
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
    #line 4 \"data-structure/range-BIT.hpp\"\n\ntemplate <typename T> class RangeBIT\
    \ {\n  public:\n    RangeBIT() = default;\n    explicit RangeBIT(int N) : bt1(N\
    \ + 1), bt2(N + 1){};\n    void add(int l, int r, T val) {\n        bt1.add(l,\
    \ -val * l);\n        bt1.add(r, val * r);\n        bt2.add(l, val);\n       \
    \ bt2.add(r, -val);\n    }\n    void add(int pos, T val) { add(pos, pos + 1, val);\
    \ }\n    T sum(int r) { return bt1.sum(r) + bt2.sum(r) * r; }\n    T sum(int l,\
    \ int r) {\n        assert(l <= r);\n        if(l == r) return T(0);\n       \
    \ return (sum(r) - sum(l));\n    }\n\n  private:\n    BIT<T> bt1, bt2;\n};\n"
  code: "#pragma once\n\n#include \"BIT.hpp\"\n\ntemplate <typename T> class RangeBIT\
    \ {\n  public:\n    RangeBIT() = default;\n    explicit RangeBIT(int N) : bt1(N\
    \ + 1), bt2(N + 1){};\n    void add(int l, int r, T val) {\n        bt1.add(l,\
    \ -val * l);\n        bt1.add(r, val * r);\n        bt2.add(l, val);\n       \
    \ bt2.add(r, -val);\n    }\n    void add(int pos, T val) { add(pos, pos + 1, val);\
    \ }\n    T sum(int r) { return bt1.sum(r) + bt2.sum(r) * r; }\n    T sum(int l,\
    \ int r) {\n        assert(l <= r);\n        if(l == r) return T(0);\n       \
    \ return (sum(r) - sum(l));\n    }\n\n  private:\n    BIT<T> bt1, bt2;\n};"
  dependsOn:
  - data-structure/BIT.hpp
  isVerificationFile: false
  path: data-structure/range-BIT.hpp
  requiredBy: []
  timestamp: '2023-10-30 20:10:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/range-BIT.hpp
layout: document
redirect_from:
- /library/data-structure/range-BIT.hpp
- /library/data-structure/range-BIT.hpp.html
title: data-structure/range-BIT.hpp
---
