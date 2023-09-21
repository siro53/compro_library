---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/compact-bitvector.hpp
    title: data-structure/compact-bitvector.hpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 2 \"data-structure/wavelet-matrix.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"data-structure/compact-bitvector.hpp\"\n\n#line\
    \ 5 \"data-structure/compact-bitvector.hpp\"\n\nclass CompactBitVector {\n  private:\n\
    \    using u32 = unsigned int;\n    using u64 = unsigned long long;\n\n  public:\n\
    \    explicit CompactBitVector() = default;\n    explicit CompactBitVector(int\
    \ n) : N(n), sz((N + 63) >> 6) {\n        bv.assign(sz, 0);\n        sum.assign(sz\
    \ + 1, 0);\n    }\n    inline void set(int i, int b) {\n        if(b) bv[i >>\
    \ 6] |= (1ULL << (i & 63));\n        else bv[i >> 6] &= ~(1ULL << (i & 63));\n\
    \    }\n    inline int access(int i) const { return (bv[i >> 6] >> (i & 63) &\
    \ 1); }\n    void build() {\n        sum[0] = 0U;\n        for(int i = 0; i <\
    \ sz; i++) sum[i + 1] = sum[i] + (u32)__builtin_popcountll(bv[i]);\n    }\n  \
    \  // [0, i)\n    u32 rank(int i, int b) const {\n        assert(i >= 0);\n  \
    \      u32 res = sum[i >> 6] + __builtin_popcountll(bv[i >> 6] & ((1ULL << (i\
    \ & 63)) - 1));\n        if(b == 0) res = i - res;\n        return res;\n    }\n\
    \    int select(int i, int b) const {\n        if(b and sum.back() > i) return\
    \ -1;\n        if(!b and N - sum.back() > i) return -1;\n        int ok = N, ng\
    \ = -1;\n        while(ok - ng > 1) {\n            int mid = (ok + ng) / 2;\n\
    \            (rank(i, b) >= mid ? ok : ng) = mid;\n        }\n        return ok;\n\
    \    }\n    inline int operator[](const int i) const { return access(i); }\n\n\
    \  private:\n    int N, sz;\n    std::vector<u64> bv;\n    std::vector<u32> sum;\n\
    };\n#line 7 \"data-structure/wavelet-matrix.hpp\"\n\ntemplate <typename T, int\
    \ BITLEN = 31> \nclass WaveletMatrix {\npublic:\n    explicit WaveletMatrix()\
    \ = default;\n    explicit WaveletMatrix(vector<int> v): N((int)v.size()), B(BITLEN,\
    \ CompactBitVector(N)), zero_num(BITLEN, 0) {\n        for(int k = BITLEN - 1;\
    \ k >= 0; k--) {\n            std::vector<T> zeros, ones;\n            for(int\
    \ i = 0; i < N; i++) {\n                if(v[i] >> k & 1) {\n                \
    \    ones.emplace_back(v[i]);\n                    B[k].set(i, 1);\n         \
    \       } else {\n                    zeros.emplace_back(v[i]);\n            \
    \    }\n            }\n            B[k].build();\n            zero_num[k] = (int)zeros.size();\n\
    \            for(int i = 0; i < N; i++) {\n                if(i < (int)zeros.size())\
    \ v[i] = zeros[i];\n                else v[i] = ones[i - (int)zeros.size()];\n\
    \            }\n        }\n    }\n    T access(int pos) const {\n        T res\
    \ = 0; \n        for(int k = BITLEN - 1; k >= 0; k--) {\n            int b = B[k][pos];\n\
    \            res |= (T(b) << k);\n            pos = B[k].rank(pos, b) + zero_num[k]\
    \ * b;\n        }\n        return pos;\n    }\n    // [0, i) \u306E\u7BC4\u56F2\
    \u5185\u306B\u5024 x \u304C\u4F55\u500B\u51FA\u73FE\u3057\u305F\u304B. O(log(\u03C3\
    ))\n    int rank(int i, T x) {\n        int l = 0, r = i;\n        for(int k =\
    \ BITLEN - 1; k >= 0; k--) {\n            int b = (x >> k & 1);\n            l\
    \ = B[k].rank(l, b) + zero_num[k] * b;\n            r = B[k].rank(r, b) + zero_num[k]\
    \ * b;\n        }\n        return (r - l);\n    };\n    // \u5DE6\u304B\u3089\
    \ i \u500B\u76EE\u306E\u5024 x \u306E index. O(log(N)log(\u03C3))\n    int select(int\
    \ i, T x) {\n        int pos = 0;\n        for(int k = BITLEN - 1; k >= 0; k--)\
    \ {\n            int b = (x >> k) & 1;\n            pos = B[k].rank(pos, b) +\
    \ zero_num[k] * b;\n        }\n        pos += i;\n        for(int k = 0; k < BITLEN;\
    \ k++) {\n            if(x >> k & 1) {\n                pos = B[k].select(pos\
    \ - zero_num[k], 1);\n            } else {\n                pos = B[k].select(pos,\
    \ 0);\n            }\n        }\n        return pos;\n    }\n    // [l, r) \u306E\
    \u4E2D\u3067 i \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059 (i\
    \ \u306F 0-indexed)\n    T quantile(int l, int r, int i) {\n        assert(0 <=\
    \ i and i < r - l);\n        T res = 0;\n        for(int k = BITLEN - 1; k >=\
    \ 0; k--) {\n            int zero_cnt = B[k].rank(r, 0) - B[k].rank(l, 0);\n \
    \           int b = (zero_cnt <= i);\n            if(b) {\n                res\
    \ |= (T(1) << k);\n                i -= zero_cnt;\n            }\n           \
    \ l = B[k].rank(l, b) + zero_num[k] * b;\n            r = B[k].rank(r, b) + zero_num[k]\
    \ * b;\n        }\n        return res;\n    }\n    // [l, r) \u306E\u4E2D\u3067\
    \ x < xr \u3092\u6E80\u305F\u3059 x \u306E\u500B\u6570\u306E\u7DCF\u548C\u3092\
    \u8FD4\u3059\n    int rangefreq(int l, int r, T xr) {\n        int res = 0;\n\
    \        for(int k = BITLEN - 1; k >= 0; k--) {\n            int b = (xr >> k\
    \ & 1);\n            if(b) res += B[k].rank(r, 0) - B[k].rank(l, 0);\n       \
    \     l = B[k].rank(l, b) + zero_num[k] * b;\n            r = B[k].rank(r, b)\
    \ + zero_num[k] * b;\n        }\n        return res;\n    }\n    // [l, r) \u306E\
    \u4E2D\u3067 xl <= x < xr \u3092\u6E80\u305F\u3059 x \u306E\u500B\u6570\u306E\u7DCF\
    \u548C\u3092\u8FD4\u3059\n    int rangefreq(int l, int r, T xl, T xr) {\n    \
    \    return (rangefreq(l, r, xr) - rangefreq(l, r, xl));\n    }\n    // [l, r)\
    \ \u306E\u4E2D\u3067 x < xr \u3092\u6E80\u305F\u3059 x \u306E\u3046\u3061\u6700\
    \u5927\u5024\u3092\u8FD4\u3059\n    // \u305D\u306E\u3088\u3046\u306A x \u304C\
    \u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u3070 -1 \u3092\u8FD4\u3059\n    T\
    \ prev_value(int l, int r, T xr) {\n        int num = rangefreq(l, r, xr);\n \
    \       return (num == 0 ? -1 : quantile(l, r, num - 1));\n    }\n    // [l, r)\
    \ \u306E\u4E2D\u3067 xl <= x \u3092\u6E80\u305F\u3059 x \u306E\u3046\u3061\u6700\
    \u5C0F\u5024\u3092\u8FD4\u3059\n    // \u305D\u306E\u3088\u3046\u306A x \u304C\
    \u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u3070 -1 \u3092\u8FD4\u3059\n    T\
    \ next_value(int l, int r, T xl) {\n        int num = rangefreq(l, r, xl);\n \
    \       return (num == r - l ? -1 : quantile(l, r, num));\n    }\n    T operator[](const\
    \ int i) const { return access(i); }\nprivate:\n    int N;\n    std::vector<CompactBitVector>\
    \ B;\n    std::vector<int> zero_num;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"compact-bitvector.hpp\"\
    \n\ntemplate <typename T, int BITLEN = 31> \nclass WaveletMatrix {\npublic:\n\
    \    explicit WaveletMatrix() = default;\n    explicit WaveletMatrix(vector<int>\
    \ v): N((int)v.size()), B(BITLEN, CompactBitVector(N)), zero_num(BITLEN, 0) {\n\
    \        for(int k = BITLEN - 1; k >= 0; k--) {\n            std::vector<T> zeros,\
    \ ones;\n            for(int i = 0; i < N; i++) {\n                if(v[i] >>\
    \ k & 1) {\n                    ones.emplace_back(v[i]);\n                   \
    \ B[k].set(i, 1);\n                } else {\n                    zeros.emplace_back(v[i]);\n\
    \                }\n            }\n            B[k].build();\n            zero_num[k]\
    \ = (int)zeros.size();\n            for(int i = 0; i < N; i++) {\n           \
    \     if(i < (int)zeros.size()) v[i] = zeros[i];\n                else v[i] =\
    \ ones[i - (int)zeros.size()];\n            }\n        }\n    }\n    T access(int\
    \ pos) const {\n        T res = 0; \n        for(int k = BITLEN - 1; k >= 0; k--)\
    \ {\n            int b = B[k][pos];\n            res |= (T(b) << k);\n       \
    \     pos = B[k].rank(pos, b) + zero_num[k] * b;\n        }\n        return pos;\n\
    \    }\n    // [0, i) \u306E\u7BC4\u56F2\u5185\u306B\u5024 x \u304C\u4F55\u500B\
    \u51FA\u73FE\u3057\u305F\u304B. O(log(\u03C3))\n    int rank(int i, T x) {\n \
    \       int l = 0, r = i;\n        for(int k = BITLEN - 1; k >= 0; k--) {\n  \
    \          int b = (x >> k & 1);\n            l = B[k].rank(l, b) + zero_num[k]\
    \ * b;\n            r = B[k].rank(r, b) + zero_num[k] * b;\n        }\n      \
    \  return (r - l);\n    };\n    // \u5DE6\u304B\u3089 i \u500B\u76EE\u306E\u5024\
    \ x \u306E index. O(log(N)log(\u03C3))\n    int select(int i, T x) {\n       \
    \ int pos = 0;\n        for(int k = BITLEN - 1; k >= 0; k--) {\n            int\
    \ b = (x >> k) & 1;\n            pos = B[k].rank(pos, b) + zero_num[k] * b;\n\
    \        }\n        pos += i;\n        for(int k = 0; k < BITLEN; k++) {\n   \
    \         if(x >> k & 1) {\n                pos = B[k].select(pos - zero_num[k],\
    \ 1);\n            } else {\n                pos = B[k].select(pos, 0);\n    \
    \        }\n        }\n        return pos;\n    }\n    // [l, r) \u306E\u4E2D\u3067\
    \ i \u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059 (i \u306F 0-indexed)\n\
    \    T quantile(int l, int r, int i) {\n        assert(0 <= i and i < r - l);\n\
    \        T res = 0;\n        for(int k = BITLEN - 1; k >= 0; k--) {\n        \
    \    int zero_cnt = B[k].rank(r, 0) - B[k].rank(l, 0);\n            int b = (zero_cnt\
    \ <= i);\n            if(b) {\n                res |= (T(1) << k);\n         \
    \       i -= zero_cnt;\n            }\n            l = B[k].rank(l, b) + zero_num[k]\
    \ * b;\n            r = B[k].rank(r, b) + zero_num[k] * b;\n        }\n      \
    \  return res;\n    }\n    // [l, r) \u306E\u4E2D\u3067 x < xr \u3092\u6E80\u305F\
    \u3059 x \u306E\u500B\u6570\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n    int rangefreq(int\
    \ l, int r, T xr) {\n        int res = 0;\n        for(int k = BITLEN - 1; k >=\
    \ 0; k--) {\n            int b = (xr >> k & 1);\n            if(b) res += B[k].rank(r,\
    \ 0) - B[k].rank(l, 0);\n            l = B[k].rank(l, b) + zero_num[k] * b;\n\
    \            r = B[k].rank(r, b) + zero_num[k] * b;\n        }\n        return\
    \ res;\n    }\n    // [l, r) \u306E\u4E2D\u3067 xl <= x < xr \u3092\u6E80\u305F\
    \u3059 x \u306E\u500B\u6570\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n    int rangefreq(int\
    \ l, int r, T xl, T xr) {\n        return (rangefreq(l, r, xr) - rangefreq(l,\
    \ r, xl));\n    }\n    // [l, r) \u306E\u4E2D\u3067 x < xr \u3092\u6E80\u305F\u3059\
    \ x \u306E\u3046\u3061\u6700\u5927\u5024\u3092\u8FD4\u3059\n    // \u305D\u306E\
    \u3088\u3046\u306A x \u304C\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u3070 -1\
    \ \u3092\u8FD4\u3059\n    T prev_value(int l, int r, T xr) {\n        int num\
    \ = rangefreq(l, r, xr);\n        return (num == 0 ? -1 : quantile(l, r, num -\
    \ 1));\n    }\n    // [l, r) \u306E\u4E2D\u3067 xl <= x \u3092\u6E80\u305F\u3059\
    \ x \u306E\u3046\u3061\u6700\u5C0F\u5024\u3092\u8FD4\u3059\n    // \u305D\u306E\
    \u3088\u3046\u306A x \u304C\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u3070 -1\
    \ \u3092\u8FD4\u3059\n    T next_value(int l, int r, T xl) {\n        int num\
    \ = rangefreq(l, r, xl);\n        return (num == r - l ? -1 : quantile(l, r, num));\n\
    \    }\n    T operator[](const int i) const { return access(i); }\nprivate:\n\
    \    int N;\n    std::vector<CompactBitVector> B;\n    std::vector<int> zero_num;\n\
    };"
  dependsOn:
  - data-structure/compact-bitvector.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix.hpp
  requiredBy: []
  timestamp: '2023-09-21 16:47:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj2674.test.cpp
  - test/aoj/aoj1549.test.cpp
  - test/library-checker/data-structure/range-kth-smallest.test.cpp
documentation_of: data-structure/wavelet-matrix.hpp
layout: document
title: Wavelet Matrix
---

## 概要

非負整数列 $A$ に対して以下の操作を行うデータ構造。

以下、$A$ の要素数を $N$、$A$ の最大値を $M$ とする。 

- `access(i)` : $A_i$ を返す。$O(\log(M))$
- `rank(i, x)` : 値 $x$ が区間 $[0, i)$ に何個あるかを求める。$O(\log(M))$
- `select(i, x)` : 左から $i$ 個目の値 $x$ の位置を返す。$O(\log(N)\log(M))$
- `quantile(l, r, i)` : 区間 $[l, r)$ に含まれる要素の中で、$i$ 番目に小さい値を返す。$O(\log(M))$
- `rangefreq(l, r, x)` : 区間 $[l, r)$ に含まれる要素の中で、$x$ 未満の値を返す。$O(\log(M))$
- `prev_value(l, r, x)` : $\max_{l \leq i < r, A_i < x} A_i$ を返す。$O(\log(M))$
- `next_value(l, r, x)` : $\min_{l \leq i < r, A_i \geq x} A_i$ を返す。$O(\log(M))$

## メモ
- $A$ に負の値が入ってるとバグるので、その場合は適切に座圧して使うこと。
- 最下段の完備辞書に対して元の列$A$でのindexを保持しておくと、 `select` 操作を $O(\log(M))$ にすることが出来る。しかし、そもそも競プロで `select` を使う機会があまりないことからその工夫は行っていない。
- また、完備辞書において `select` を定数時間で行えるようにすることでも $O(\log(M))$ にすることが出来るが、定数が重すぎるため実用的ではない(らしい)。
- 完備辞書は succinct なものではなく compact なものを使っている（競プロの範囲なら compact でも問題ないため）。どちらが早いかは未検証。