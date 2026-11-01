---
title: 最大値モノイド
documentation_of: //data-structure/monoid/max.hpp
---

## 概要

`MonoidMax<T>` は 最大値を区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | max(l,r) を返す。 | O(1) |
| `e()` | 単位元 MINUS_INF を返す。 | O(1) |

## 前提・注意点

第 2 テンプレート引数 MINUS_INF の既定値は numeric_limits<T>::min()。浮動小数点では min() は負の無限大ではない。C++17 では浮動小数点の非型テンプレート引数は使えないため、整数型で使う。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/max.hpp"

int main() {
    using M = MonoidMax<int>;
    assert(M::op(4, 6) == 6);
}
```
