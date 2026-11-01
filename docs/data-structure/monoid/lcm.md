---
title: 最小公倍数モノイド
documentation_of: //data-structure/monoid/lcm.hpp
---

## 概要

`MonoidLCM<T>` は 最小公倍数を区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | lcm(l,r) を返す。 | O(log M)、M=max(abs(l),abs(r))+1 |
| `e()` | 単位元 1 を返す。 | O(1) |

## 前提・注意点

非負整数を使い、最小公倍数が T に収まること。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/lcm.hpp"

int main() {
    using M = MonoidLCM<long long>;
    assert(M::op(4, 6) == 12);
}
```
