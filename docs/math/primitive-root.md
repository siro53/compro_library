---
title: 原始根
documentation_of: //math/primitive-root.hpp
---

## 概要

素数 p に対する原始根を求める constexpr 関数。p-1 を試し割りし、候補 g を順に検査する。

追加空間 O(1)（固定長配列）。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `primitive_root(p)` | 1<=g<p の原始根。p=2 は 1、998244353 は 3。 | O(sqrt(p)+G K log p)、G は検査候補数、K は p-1 の異なる素因数数 |

## 前提・注意点

p は int に収まる素数であること。素数判定は行わない。候補数を定数とした厳密な計算量保証はない。試し割りの i*i は int のため、上限付近ではオーバーフローし得る。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/primitive-root.hpp"

int main() {
    assert(primitive_root(17) == 3);
}
```
