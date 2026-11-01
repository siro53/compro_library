---
title: 約数列挙
documentation_of: //math/divisor.hpp
---

## 概要

整数 n の正の約数を昇順で列挙する。`D` は約数の個数。

空間 O(D)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `divisor(n)` | vector<T> で全約数を返す。 | O(sqrt(n)+D log D) |

## 前提・注意点

T は整数型、n>=1。ループ条件の i*i がオーバーフローしない範囲で使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/divisor.hpp"

int main() {
    auto ds = divisor(12);
    assert((ds == vector<int>{1, 2, 3, 4, 6, 12}));
}
```
