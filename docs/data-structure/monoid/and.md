---
title: ビット ANDモノイド
documentation_of: //data-structure/monoid/and.hpp
---

## 概要

`MonoidAND<T>` は ビット ANDを区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l & r を返す。 | O(1) |
| `e()` | 単位元 1 を返す。 | O(1) |

## 前提・注意点

現実装の単位元は 1。一般の整数の全 bit AND の単位元ではないため、値を 0/1 に限定して使う。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/and.hpp"

int main() {
    using M = MonoidAND<int>;
    assert(M::op(1, 0) == 0);
}
```
