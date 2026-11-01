---
title: 試し割りによる素因数分解
documentation_of: //math/prime-factor.hpp
---

## 概要

整数 n を素因数分解し、素数から指数への map を返す。`K` は異なる素因数の個数。

空間 O(K)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `prime_factor(n)` | map<T,int>。n=1 なら空。 | O(sqrt(n)+K log K) |

## 前提・注意点

T は整数型、n>=1。i*i がオーバーフローしない範囲で使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/prime-factor.hpp"

int main() {
    auto f = prime_factor(360LL);
    assert(f[2] == 3 && f[3] == 2 && f[5] == 1);
}
```
