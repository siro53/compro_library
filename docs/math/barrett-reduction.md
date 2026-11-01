---
title: Barrett Reduction
documentation_of: //math/barrett-reduction.hpp
---

## 概要

`BarrettReduction` は固定した法 m に対して逆数近似を前計算し、整数演算で積・剰余を求める。

空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BarrettReduction(m=1)` | 法と近似逆数を保持。 | O(1) |
| `mul(a, b)` | a*b mod m。 | O(1) |
| `rem(a)` | a mod m。 | O(1) |
| `quo(a)` | unsigned int の商 a/m。 | O(1) |
| `quorem(a)` | unsigned int の (商,剰余)。 | O(1) |

## 前提・注意点

`2<=m<2^31`、`mul` は `0<=a,b<m`、`rem` は安全な利用範囲を `0<=a<m²` とする。`quo/quorem` の入力は unsigned int。m=1 では近似逆数が 0 に巻き戻るため商・剰余 API が一般に正しくない。コンストラクタは m=0 を検査しない。128 bit 整数拡張が必要。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/barrett-reduction.hpp"

int main() {
    BarrettReduction br(7);
    assert(br.mul(3, 5) == 1);
    auto [q, r] = br.quorem(23);
    assert(q == 3 && r == 2);
}
```
