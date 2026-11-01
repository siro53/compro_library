---
title: 剰余付き累乗
documentation_of: //math/pow_mod.hpp
---

## 概要

繰り返し二乗法で x^k mod m を計算する constexpr 関数。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `pow_mod(x, k, m)` | long long の剰余を返す。積には __int128_t を使う。 | O(log(k+1)) |

## 前提・注意点

k>=0、m>0。現実装は k=0,m=1 でも 1 を返すので、この組み合わせでは呼び出し側で 0 にする。GCC/Clang の 128 bit 整数拡張が必要。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/pow_mod.hpp"

int main() {
    assert(pow_mod(2, 10, 1000) == 24);
    assert(pow_mod(-2, 3, 5) == 2);
}
```
