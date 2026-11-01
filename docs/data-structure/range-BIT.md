---
title: Range BIT
documentation_of: //data-structure/range-BIT.hpp
---

## 概要

`RangeBIT<T>` は 2 本の BIT で区間加算・区間和を扱う。`N` は要素数。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RangeBIT(N)` | N 要素を 0 で初期化。 | O(N) |
| `add(l, r, val)` | [l, r) の全要素に加算。 | O(log N) |
| `add(pos, val)` | 1 要素に加算。 | O(log N) |
| `sum(r)` | [0, r) の和。 | O(log N) |
| `sum(l, r)` | [l, r) の和。 | O(log N) |

## 前提・注意点

0-indexed、`0 <= l <= r <= N`。`T` は整数との乗算と加減算が必要。デフォルト構築だけでは利用できない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/range-BIT.hpp"

int main() {
    RangeBIT<long long> bit(5);
    bit.add(1, 4, 2);
    assert(bit.sum(0, 5) == 6);
}
```
