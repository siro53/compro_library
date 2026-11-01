---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/range-BIT.hpp
    title: Range BIT
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
  - data-structure/range-BIT.hpp
  - misc/inversion-number.hpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/static-range-sum.test.cpp
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - test/library-checker/data-structure/point-add-range-sum.test.cpp
  - test/aoj/aoj-ALDS1-5-D.test.cpp
documentation_of: data-structure/BIT.hpp
layout: document
title: Binary Indexed Tree
---

## このライブラリでできること

`BIT<T>` は、配列の値を更新しながら区間和を求めるデータ構造です。たとえば「ある日の売上を加算する」「指定した期間の売上を合計する」という操作を繰り返す場面で使えます。Fenwick tree とも呼ばれます。

長さ $N$ の配列 $A$ に対し、`add(p,x)` は $A_p\leftarrow A_p+x$、`sum(l,r)` は $\sum_{i=l}^{r-1} A_i$ を計算します。配列全体の累積和を作り直す必要がなく、どちらも $O(\log N)$ 時間です。

## 使い方

まず要素数を指定して、全要素が $0$ の BIT を作ります。`add` の第1引数は要素の位置、第2引数は「代入する値」ではなく「加える量」です。値を上書きしたい場合は、現在値との差を加えてください。

例では $A_2$ に $7$ を加え、区間 $[1,4)$ の和を求めます。`lower_bound(7)` の返り値が $3$ なのは、先頭から **3 個** 取ると初めて累積和が $7$ 以上になるためです。位置 $2$ そのものを返す関数ではありません。

```cpp
#include "template/template.cpp"
#include "data-structure/BIT.hpp"

int main() {
    BIT<long long> bit(5);
    bit.add(2, 7);
    assert(bit.sum(1, 4) == 7);
    assert(bit.lower_bound(7) == 3);
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BIT(N)` | N 要素を 0 で初期化。 | O(N) |
| `add(pos, val)` | A[pos] に val を加算。 | O(log N) |
| `sum(r)` | [0, r) の和。 | O(log N) |
| `sum(l, r)` | [l, r) の和。空区間は 0。 | O(log N) |
| `lower_bound(val)` | 累積和が val 以上となる先頭からの要素数 r の最小値。見つからなければ N+1。 | O(log N) |

## 利用条件と実装上の注意

添字は $0$ から始まり、区間 $[l,r)$ には右端 $r$ を含めません。更新は $0\le p<N$、和の取得は $0\le l\le r\le N$ の範囲で行ってください。

`lower_bound(v)` は、全要素が非負で $v>0$ のときに使えます。この条件のもとで、$\sum_{i=0}^{r-1}A_i\ge v$ を満たす最小の $r$ を返し、存在しなければ $N+1$ を返します。負数を含む配列では累積和が単調にならず、この探索は使えません。

`T` には $0$ の構築と加減算が必要です。探索も使う場合は大小比較も必要になります。符号付き整数では和のオーバーフローを避けてください。引数なしで構築した場合は、サイズを指定したオブジェクトを代入してから利用します。

## 参考資料

[ACL の Fenwick Tree ドキュメント](https://atcoder.github.io/ac-library/production/document_ja/fenwicktree.html)も、点加算と区間和の使い分けの参考になります。`lower_bound` はこのライブラリ独自の API です。
