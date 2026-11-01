---
title: エラトステネスの篩
documentation_of: //math/eratosthenes.hpp
---

## 概要

`Eratosthenes` は 0 以上 N 以下の素数判定表を作る。

空間 O(N) bit。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Eratosthenes(N)` | 素数判定表を構築。 | O(N log log N) |
| `operator[](k)` | k が素数か。 | O(1) |

## 前提・注意点

N>=1、問い合わせは `[0,N]`。デフォルト構築のまま参照しない。i*i と倍数列挙の int 演算がオーバーフローしない範囲で使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/eratosthenes.hpp"

int main() {
    Eratosthenes sieve(100);
    assert(sieve[97] && !sieve[1]);
}
```
