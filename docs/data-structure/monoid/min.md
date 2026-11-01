---
title: 最小値モノイド
documentation_of: //data-structure/monoid/min.hpp
---

## 概要

`MonoidMin<T>` は 最小値を区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | min(l,r) を返す。 | O(1) |
| `e()` | 単位元 INF を返す。 | O(1) |

## 前提・注意点

第 2 テンプレート引数 INF の既定値は numeric_limits<T>::max()。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/min.hpp"

int main() {
    using M = MonoidMin<int>;
    assert(M::op(4, 6) == 4);
}
```
