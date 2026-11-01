---
title: 加算モノイド
documentation_of: //data-structure/monoid/add.hpp
---

## 概要

`MonoidAdd<T>` は 加算を区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l+r を返す。 | O(1) |
| `e()` | 単位元 0 を返す。 | O(1) |

## 前提・注意点



`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/add.hpp"

int main() {
    using M = MonoidAdd<long long>;
    auto x = M::op(2, 3);
    assert(x == 5);
}
```
