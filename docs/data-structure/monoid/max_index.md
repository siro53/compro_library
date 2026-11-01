---
title: 添字付き最大値モノイド
documentation_of: //data-structure/monoid/max_index.hpp
---

## 概要

`MonoidMaxWithIndex<T>` は 添字付き最大値を区間集約に使うための型。`value_type` は `std::pair<T,int>`（値、添字）。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | pair の辞書順最大 を返す。 | O(1) |
| `e()` | 単位元 (MINUS_INF,-1) を返す。 | O(1) |

## 前提・注意点

同値なら大きい添字を選ぶ。MINUS_INF の既定値は numeric_limits<T>::min()。添字は非負。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/max_index.hpp"

int main() {
    using M = MonoidMaxWithIndex<int>;
    auto x = M::op({4, 2}, {4, 5});
    assert(x.second == 5);
}
```
