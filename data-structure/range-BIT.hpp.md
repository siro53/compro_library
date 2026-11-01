---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/BIT.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-DSL-2-G.test.cpp
    title: test/aoj/aoj-DSL-2-G.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/range-bit.test.cpp
    title: test/mytest/data-structure/range-bit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/data-structure/range-bit.test.cpp
  - test/aoj/aoj-DSL-2-G.test.cpp
documentation_of: data-structure/range-BIT.hpp
layout: document
title: Range BIT
---

## このライブラリでできること

`RangeBIT<T>` は、区間内の全要素への加算と区間和の取得を扱います。「区間に同じ数を加える」という更新が多いときに、点加算用の BIT よりも適しています。長さ $N$ の配列に対して、どちらの操作も $O(\log N)$ 時間です。

内部では差分列を2本の BIT に分けて保持します。区間への加算を両端の差分更新に変換し、先頭 $r$ 個の和を「定数項と $r$ に比例する項」の和として求める仕組みです。

## 使い方

サイズを指定して初期化し、`add(l,r,x)` で $l\le i<r$ の各 $A_i$ に $x$ を加えます。`sum(l,r)` は同じ半開区間の和を返します。例では $A_1,A_2,A_3$ に $2$ ずつ加えるので、全体の和は $6$ になります。

```cpp
#include "template/template.cpp"
#include "data-structure/range-BIT.hpp"

int main() {
    RangeBIT<long long> bit(5);
    bit.add(1, 4, 2);
    assert(bit.sum(0, 5) == 6);
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RangeBIT(N)` | N 要素を 0 で初期化。 | O(N) |
| `add(l, r, val)` | [l, r) の全要素に加算。 | O(log N) |
| `add(pos, val)` | 1 要素に加算。 | O(log N) |
| `sum(r)` | [0, r) の和。 | O(log N) |
| `sum(l, r)` | [l, r) の和。 | O(log N) |

## 利用条件と実装上の注意

添字は $0$ から始め、$0\le l\le r\le N$ としてください。`add(p,x)` は1点だけへの加算、`sum(r)` は先頭 $r$ 個の和です。

`T` には加減算と整数との乗算が必要です。実装では値に添字を掛けるため、各要素だけでなく中間積と区間和も型の範囲内に収めてください。引数なしで構築したオブジェクトは、そのままでは使えません。
