---
title: 最大公約数モノイド
documentation_of: //data-structure/monoid/gcd.hpp
---

## 概要

`MonoidGCD<T>` は 最大公約数を区間集約に使うための型。`value_type` は `T`。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | gcd(l,r) を返す。 | O(log M)、M=max(abs(l),abs(r))+1 |
| `e()` | 単位元 0 を返す。 | O(1) |

## 前提・注意点

整数型を使い、絶対値が型に収まること。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/gcd.hpp"

int main() {
    using M = MonoidGCD<long long>;
    assert(M::op(12, 18) == 6);
}
```
