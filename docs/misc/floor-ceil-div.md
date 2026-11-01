---
title: 整数の切り上げ・切り捨て除算
documentation_of: //misc/floor-ceil-div.hpp
---

## 概要

負数も含め、数学的な床・天井関数で整数除算を行う。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `floor_div(a,b)` | floor(a/b)。 | O(1) |
| `ceil_div(a,b)` | ceil(a/b)。 | O(1) |

## 前提・注意点

T は符号付き整数、b!=0。内部で符号反転や a+b-1、a-b+1 を計算するので、それらが T の範囲内に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/floor-ceil-div.hpp"

int main() {
    assert(floor_div(-7LL, 3LL) == -3);
    assert(ceil_div(-7LL, 3LL) == -2);
}
```
