---
title: タイマー
documentation_of: //misc/timer.hpp
---

## 概要

`Timer` は構築・リセットからの経過時間を測る。公開メンバ start_time は開始時刻。

空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Timer()` | 現在時刻を開始時刻として保存。 | O(1) |
| `reset()` | 開始時刻を現在時刻に更新。 | O(1) |
| `elapsed(), operator()()` | 経過ミリ秒を long long で返す。 | O(1) |

## 前提・注意点

単位は秒ではなくミリ秒。high_resolution_clock を使うため、単調時計であることは環境依存。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/timer.hpp"

int main() {
    Timer timer;
    long long ms = timer.elapsed();
    timer.reset();
    (void)ms;
}
```
