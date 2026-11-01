---
title: Binary Indexed Tree
documentation_of: //data-structure/BIT.hpp
---

## 概要

`BIT<T>` は点加算と区間和を扱う Fenwick tree。`N` は要素数。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BIT(N)` | N 要素を 0 で初期化。 | O(N) |
| `add(pos, val)` | A[pos] に val を加算。 | O(log N) |
| `sum(r)` | [0, r) の和。 | O(log N) |
| `sum(l, r)` | [l, r) の和。空区間は 0。 | O(log N) |
| `lower_bound(val)` | 累積和が val 以上となる最小の prefix 長 r。見つからなければ N+1。 | O(log N) |

## 前提・注意点

添字は 0-indexed、区間は半開区間。`lower_bound` は全要素が非負かつ `val > 0` の場合に使う。返り値は要素の添字ではない。`T` は加減算と 0 の構築に対応すること。デフォルト構築後はサイズ付きオブジェクトを代入してから使う。

## 使用例

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
