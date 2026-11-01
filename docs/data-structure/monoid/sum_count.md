---
title: 和・個数モノイド
documentation_of: //data-structure/monoid/sum_count.hpp
---

## 概要

`MonoidSumCount<sum_t,count_t>` は和と個数を同時に集約する。`S/value_type` の `sum` が和、`cnt` が個数。

空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `S(sum, cnt)` | 集約値を構築。デフォルト構築は未初期化。 | O(1) |
| `op(l, r)` | sum と cnt をそれぞれ加算。 | O(1) |
| `e()` | (0,0)。 | O(1) |

## 前提・注意点

値 x が c 個ある葉は `S(x*c,c)`。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/sum_count.hpp"

int main() {
    using M = MonoidSumCount<long long, int>;
    auto x = M::op(M::S(5, 1), M::S(6, 2));
    assert(x.sum == 11 && x.cnt == 3);
}
```
