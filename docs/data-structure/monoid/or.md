---
title: ビット ORモノイド
documentation_of: //data-structure/monoid/or.hpp
---

## 概要

`MonoidOR<T>` は ビット ORを区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l &#124; r を返す。 | O(1) |
| `e()` | 単位元 0 を返す。 | O(1) |

## 前提・注意点



`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/or.hpp"

int main() {
    using M = MonoidOR<unsigned int>;
    assert(M::op(1, 2) == 3);
}
```
