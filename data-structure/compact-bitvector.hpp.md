---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj1549.test.cpp
    title: test/aoj/aoj1549.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2674.test.cpp
    title: test/aoj/aoj2674.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-kth-smallest.test.cpp
    title: test/library-checker/data-structure/range-kth-smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/compact-bitvector.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nclass CompactBitVector {\n  private:\n    using u32 = unsigned\
    \ int;\n    using u64 = unsigned long long;\n\n  public:\n    explicit CompactBitVector()\
    \ = default;\n    explicit CompactBitVector(int n) : N(n), sz((N + 63) >> 6) {\n\
    \        bv.assign(sz, 0);\n        sum.assign(sz + 1, 0);\n    }\n    inline\
    \ void set(int i, int b) {\n        if(b) bv[i >> 6] |= (1ULL << (i & 63));\n\
    \        else bv[i >> 6] &= ~(1ULL << (i & 63));\n    }\n    inline int access(int\
    \ i) const { return (bv[i >> 6] >> (i & 63) & 1); }\n    void build() {\n    \
    \    sum[0] = 0U;\n        for(int i = 0; i < sz; i++) sum[i + 1] = sum[i] + (u32)__builtin_popcountll(bv[i]);\n\
    \    }\n    // [0, i)\n    u32 rank(int i, int b) const {\n        assert(i >=\
    \ 0);\n        u32 res = sum[i >> 6] + __builtin_popcountll(bv[i >> 6] & ((1ULL\
    \ << (i & 63)) - 1));\n        if(b == 0) res = i - res;\n        return res;\n\
    \    }\n    int select(int i, int b) const {\n        if(b and sum.back() > i)\
    \ return -1;\n        if(!b and N - sum.back() > i) return -1;\n        int ok\
    \ = N, ng = -1;\n        while(ok - ng > 1) {\n            int mid = (ok + ng)\
    \ / 2;\n            (rank(i, b) >= mid ? ok : ng) = mid;\n        }\n        return\
    \ ok;\n    }\n    inline int operator[](const int i) const { return access(i);\
    \ }\n\n  private:\n    int N, sz;\n    std::vector<u64> bv;\n    std::vector<u32>\
    \ sum;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nclass CompactBitVector\
    \ {\n  private:\n    using u32 = unsigned int;\n    using u64 = unsigned long\
    \ long;\n\n  public:\n    explicit CompactBitVector() = default;\n    explicit\
    \ CompactBitVector(int n) : N(n), sz((N + 63) >> 6) {\n        bv.assign(sz, 0);\n\
    \        sum.assign(sz + 1, 0);\n    }\n    inline void set(int i, int b) {\n\
    \        if(b) bv[i >> 6] |= (1ULL << (i & 63));\n        else bv[i >> 6] &= ~(1ULL\
    \ << (i & 63));\n    }\n    inline int access(int i) const { return (bv[i >> 6]\
    \ >> (i & 63) & 1); }\n    void build() {\n        sum[0] = 0U;\n        for(int\
    \ i = 0; i < sz; i++) sum[i + 1] = sum[i] + (u32)__builtin_popcountll(bv[i]);\n\
    \    }\n    // [0, i)\n    u32 rank(int i, int b) const {\n        assert(i >=\
    \ 0);\n        u32 res = sum[i >> 6] + __builtin_popcountll(bv[i >> 6] & ((1ULL\
    \ << (i & 63)) - 1));\n        if(b == 0) res = i - res;\n        return res;\n\
    \    }\n    int select(int i, int b) const {\n        if(b and sum.back() > i)\
    \ return -1;\n        if(!b and N - sum.back() > i) return -1;\n        int ok\
    \ = N, ng = -1;\n        while(ok - ng > 1) {\n            int mid = (ok + ng)\
    \ / 2;\n            (rank(i, b) >= mid ? ok : ng) = mid;\n        }\n        return\
    \ ok;\n    }\n    inline int operator[](const int i) const { return access(i);\
    \ }\n\n  private:\n    int N, sz;\n    std::vector<u64> bv;\n    std::vector<u32>\
    \ sum;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/compact-bitvector.hpp
  requiredBy:
  - data-structure/wavelet-matrix.hpp
  timestamp: '2023-09-21 16:47:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/range-kth-smallest.test.cpp
  - test/aoj/aoj1549.test.cpp
  - test/aoj/aoj2674.test.cpp
documentation_of: data-structure/compact-bitvector.hpp
layout: document
redirect_from:
- /library/data-structure/compact-bitvector.hpp
- /library/data-structure/compact-bitvector.hpp.html
title: data-structure/compact-bitvector.hpp
---
