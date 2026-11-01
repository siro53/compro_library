---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/compact-bitvector.hpp
    title: Compact Bit Vector
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
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/bit-queries.test.cpp
    title: test/mytest/data-structure/bit-queries.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/wavelet-api.test.cpp
    title: test/mytest/data-structure/wavelet-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet-matrix.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"data-structure/compact-bitvector.hpp\"\n\n#line\
    \ 5 \"data-structure/compact-bitvector.hpp\"\n\nclass CompactBitVector {\n  private:\n\
    \    using u32 = unsigned int;\n    using u64 = unsigned long long;\n\n  public:\n\
    \    explicit CompactBitVector() : CompactBitVector(0) {}\n    explicit CompactBitVector(int\
    \ n) : N(n), sz((N + 63) >> 6) {\n        bv.assign(sz, 0);\n        sum.assign(sz\
    \ + 1, 0);\n    }\n    inline void set(int i, int b) {\n        if(b) bv[i >>\
    \ 6] |= (1ULL << (i & 63));\n        else bv[i >> 6] &= ~(1ULL << (i & 63));\n\
    \    }\n    inline int access(int i) const { return (bv[i >> 6] >> (i & 63) &\
    \ 1); }\n    void build() {\n        sum[0] = 0U;\n        for(int i = 0; i <\
    \ sz; i++) sum[i + 1] = sum[i] + (u32)__builtin_popcountll(bv[i]);\n    }\n  \
    \  // [0, i)\n    u32 rank(int i, int b) const {\n        assert(0 <= i && i <=\
    \ N);\n        u32 res = sum[i >> 6];\n        if(i & 63) res += __builtin_popcountll(bv[i\
    \ >> 6] & ((1ULL << (i & 63)) - 1));\n        if(b == 0) res = i - res;\n    \
    \    return res;\n    }\n    int select(int i, int b) const {\n        if(i <\
    \ 0 || (u32)i >= rank(N, b)) return -1;\n        int ok = N - 1, ng = -1;\n  \
    \      while(ok - ng > 1) {\n            int mid = (ok + ng) / 2;\n          \
    \  (rank(mid + 1, b) > (u32)i ? ok : ng) = mid;\n        }\n        return ok;\n\
    \    }\n    inline int operator[](const int i) const { return access(i); }\n\n\
    \  private:\n    int N, sz;\n    std::vector<u64> bv;\n    std::vector<u32> sum;\n\
    };\n#line 7 \"data-structure/wavelet-matrix.hpp\"\n\ntemplate <typename T, int\
    \ BITLEN = 31> \nclass WaveletMatrix {\npublic:\n    explicit WaveletMatrix()\
    \ = default;\n    explicit WaveletMatrix(std::vector<int> v): N((int)v.size()),\
    \ B(BITLEN, CompactBitVector(N)), zero_num(BITLEN, 0) {\n        for(int k = BITLEN\
    \ - 1; k >= 0; k--) {\n            std::vector<T> zeros, ones;\n            for(int\
    \ i = 0; i < N; i++) {\n                if(v[i] >> k & 1) {\n                \
    \    ones.emplace_back(v[i]);\n                    B[k].set(i, 1);\n         \
    \       } else {\n                    zeros.emplace_back(v[i]);\n            \
    \    }\n            }\n            B[k].build();\n            zero_num[k] = (int)zeros.size();\n\
    \            for(int i = 0; i < N; i++) {\n                if(i < (int)zeros.size())\
    \ v[i] = zeros[i];\n                else v[i] = ones[i - (int)zeros.size()];\n\
    \            }\n        }\n    }\n    T access(int pos) const {\n        T res\
    \ = 0; \n        for(int k = BITLEN - 1; k >= 0; k--) {\n            int b = B[k][pos];\n\
    \            res |= (T(b) << k);\n            pos = B[k].rank(pos, b) + zero_num[k]\
    \ * b;\n        }\n        return res;\n    }\n    // [0, i) \u306E\u7BC4\u56F2\
    \u5185\u306B\u5024 x \u304C\u4F55\u500B\u51FA\u73FE\u3057\u305F\u304B. O(log(\u03C3\
    ))\n    int rank(int i, T x) {\n        int l = 0, r = i;\n        for(int k =\
    \ BITLEN - 1; k >= 0; k--) {\n            int b = (x >> k & 1);\n            l\
    \ = B[k].rank(l, b) + zero_num[k] * b;\n            r = B[k].rank(r, b) + zero_num[k]\
    \ * b;\n        }\n        return (r - l);\n    };\n    // \u5DE6\u304B\u3089\
    \ i \u500B\u76EE\u306E\u5024 x \u306E index. O(log(N)log(\u03C3))\n    int select(int\
    \ i, T x) {\n        if(i < 0 || i >= rank(N, x)) return -1;\n        int pos\
    \ = 0;\n        for(int k = BITLEN - 1; k >= 0; k--) {\n            int b = (x\
    \ >> k) & 1;\n            pos = B[k].rank(pos, b) + zero_num[k] * b;\n       \
    \ }\n        pos += i;\n        for(int k = 0; k < BITLEN; k++) {\n          \
    \  if(x >> k & 1) {\n                pos = B[k].select(pos - zero_num[k], 1);\n\
    \            } else {\n                pos = B[k].select(pos, 0);\n          \
    \  }\n        }\n        return pos;\n    }\n    // [l, r) \u306E\u4E2D\u3067\
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
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"compact-bitvector.hpp\"\
    \n\ntemplate <typename T, int BITLEN = 31> \nclass WaveletMatrix {\npublic:\n\
    \    explicit WaveletMatrix() = default;\n    explicit WaveletMatrix(std::vector<int>\
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
    \     pos = B[k].rank(pos, b) + zero_num[k] * b;\n        }\n        return res;\n\
    \    }\n    // [0, i) \u306E\u7BC4\u56F2\u5185\u306B\u5024 x \u304C\u4F55\u500B\
    \u51FA\u73FE\u3057\u305F\u304B. O(log(\u03C3))\n    int rank(int i, T x) {\n \
    \       int l = 0, r = i;\n        for(int k = BITLEN - 1; k >= 0; k--) {\n  \
    \          int b = (x >> k & 1);\n            l = B[k].rank(l, b) + zero_num[k]\
    \ * b;\n            r = B[k].rank(r, b) + zero_num[k] * b;\n        }\n      \
    \  return (r - l);\n    };\n    // \u5DE6\u304B\u3089 i \u500B\u76EE\u306E\u5024\
    \ x \u306E index. O(log(N)log(\u03C3))\n    int select(int i, T x) {\n       \
    \ if(i < 0 || i >= rank(N, x)) return -1;\n        int pos = 0;\n        for(int\
    \ k = BITLEN - 1; k >= 0; k--) {\n            int b = (x >> k) & 1;\n        \
    \    pos = B[k].rank(pos, b) + zero_num[k] * b;\n        }\n        pos += i;\n\
    \        for(int k = 0; k < BITLEN; k++) {\n            if(x >> k & 1) {\n   \
    \             pos = B[k].select(pos - zero_num[k], 1);\n            } else {\n\
    \                pos = B[k].select(pos, 0);\n            }\n        }\n      \
    \  return pos;\n    }\n    // [l, r) \u306E\u4E2D\u3067 i \u756A\u76EE\u306B\u5C0F\
    \u3055\u3044\u5024\u3092\u8FD4\u3059 (i \u306F 0-indexed)\n    T quantile(int\
    \ l, int r, int i) {\n        assert(0 <= i and i < r - l);\n        T res = 0;\n\
    \        for(int k = BITLEN - 1; k >= 0; k--) {\n            int zero_cnt = B[k].rank(r,\
    \ 0) - B[k].rank(l, 0);\n            int b = (zero_cnt <= i);\n            if(b)\
    \ {\n                res |= (T(1) << k);\n                i -= zero_cnt;\n   \
    \         }\n            l = B[k].rank(l, b) + zero_num[k] * b;\n            r\
    \ = B[k].rank(r, b) + zero_num[k] * b;\n        }\n        return res;\n    }\n\
    \    // [l, r) \u306E\u4E2D\u3067 x < xr \u3092\u6E80\u305F\u3059 x \u306E\u500B\
    \u6570\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n    int rangefreq(int l, int r, T\
    \ xr) {\n        int res = 0;\n        for(int k = BITLEN - 1; k >= 0; k--) {\n\
    \            int b = (xr >> k & 1);\n            if(b) res += B[k].rank(r, 0)\
    \ - B[k].rank(l, 0);\n            l = B[k].rank(l, b) + zero_num[k] * b;\n   \
    \         r = B[k].rank(r, b) + zero_num[k] * b;\n        }\n        return res;\n\
    \    }\n    // [l, r) \u306E\u4E2D\u3067 xl <= x < xr \u3092\u6E80\u305F\u3059\
    \ x \u306E\u500B\u6570\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n    int rangefreq(int\
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
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/range-kth-smallest.test.cpp
  - test/mytest/data-structure/wavelet-api.test.cpp
  - test/mytest/data-structure/bit-queries.test.cpp
  - test/aoj/aoj1549.test.cpp
  - test/aoj/aoj2674.test.cpp
documentation_of: data-structure/wavelet-matrix.hpp
layout: document
title: Wavelet Matrix
---

## このライブラリでできること

`WaveletMatrix<T,BITLEN>` は、変更しない整数列について、区間内の順位や値の分布を調べるデータ構造です。「区間内で3番目に小さい値」「指定値未満の要素数」「ある値の直前・直後の値」といった問い合わせに向いています。

長さを $N$、扱う bit 数を $B=\mathrm{BITLEN}$ とします。上位 bit から順に値を $0$ 側と $1$ 側へ安定に分け、各段の移動先を bit 列の rank で追跡します。前処理は $O(NB)$、順位・個数の問い合わせは $O(B)$ 時間です。

## 使い方

配列を渡して構築した後は、その配列に対する問い合わせ専用として使います。例の列 $[3,1,4,1,5]$ を並べ替えると $[1,1,3,4,5]$ なので、0始まりの順位 $2$ にある値は $3$ です。また $2$ 未満の値は2個あるため、`rangefreq(0,5,2)` は $2$ を返します。

`prev_value(l,r,x)` は $x$ 未満の最大値、`next_value(l,r,x)` は $x$ 以上の最小値を求めます。前者が $x$ 自身を含まない点に注意してください。

```cpp
#include "template/template.cpp"
#include "data-structure/wavelet-matrix.hpp"

int main() {
    WaveletMatrix<int, 4> wm(vector<int>{3, 1, 4, 1, 5});
    assert(wm.quantile(0, 5, 2) == 3);
    assert(wm.rangefreq(0, 5, 2) == 2);
}
```

## API・計算量

保持するbit列と累積情報に $O(B\lceil N/64\rceil)$ ワード、構築中の作業用配列に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `WaveletMatrix(vector<int> v)` | 列をビットごとに分割して構築。 | O(NB) |
| `access(pos), operator[](pos)` | 元の値を返す。 | O(B) |
| `rank(i, x)` | [0,i) の x の個数。 | O(B) |
| `select(i, x)` | 0 始まりで i 番目の x の位置。存在しなければ -1。 | O(B log N) |
| `quantile(l, r, i)` | [l,r) 内の昇順 i 番目（0-indexed）。 | O(B) |
| `rangefreq(l, r, xr)` | [l,r) 内で x<xr の個数。 | O(B) |
| `rangefreq(l, r, xl, xr)` | [l,r) 内で xl<=x<xr の個数。 | O(B) |
| `prev_value(l, r, xr)` | xr 未満の最大値。なければ -1。 | O(B) |
| `next_value(l, r, xl)` | xl 以上の最小値。なければ -1。 | O(B) |

## 利用条件と実装上の注意

配列の値と検索に使う値の境界は $[0,2^B)$ に収めてください。`rangefreq` の上限にも $2^B$ 自体は渡せません。負の値は先に座標圧縮するなどして変換します。構築時の引数型は `T` によらず `vector<int>` です。

区間は $0\le l\le r\le N$ とし、`quantile(l,r,k)` ではさらに $0\le k<r-l$ が必要です。前後の値が存在しないときは $-1$ を返すため、返り値の型には符号付き型を推奨します。

空列や長さが64の倍数の列にも対応します。`select(i,x)` は左から0始まりで i 番目の x の位置を返し、負の i や出現個数以上の i には -1 を返します。
