---
title: 乱数生成
documentation_of: //random/rng.hpp
---

## 概要

`RNG32/RNG64` は Mersenne Twister による整数乱数、`RNG_0_1` は double の一様乱数を生成する。時刻を seed に使う。

エンジンの固定サイズの状態 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RNG32(), RNG64(), RNG_0_1()` | 時刻からエンジンを初期化。 | 固定サイズの初期化 O(1) |
| `RNG32::randint(l,r), RNG64::randint(l,r)` | [l,r) の整数。型は int / long long。 | 期待 O(1) |
| `RNG32::randint(r), RNG64::randint(r)` | [0,r) の整数。 | 期待 O(1) |
| `RNG_0_1::rand(), operator()()` | [0,1) の double（53 bit の分解能）。 | 償却 O(1) |

## 前提・注意点

整数範囲は必ず l<r。乱数 seed の指定 API はなく、再現性や暗号用途の乱数を提供するものではない。上端 r は含まれない。

## 使用例

```cpp
#include "template/template.cpp"
#include "random/rng.hpp"

int main() {
    RNG32 rng;
    int dice = rng.randint(1, 7);
    assert(1 <= dice && dice <= 6);
    RNG_0_1 real_rng;
    double x = real_rng();
    assert(0 <= x && x < 1);
}
```
