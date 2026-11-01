---
title: タイマー
documentation_of: //misc/timer.hpp
---

## このライブラリでできること

`Timer` は、構築した時点からの経過時間をミリ秒で測る小さな補助クラスです。処理時間を確認したり、探索を一定時間で打ち切ったりする場合に使えます。開始時刻は `start_time` に保存されます。

## 使い方

計測を始めたい位置でオブジェクトを作り、`elapsed()` または `timer()` で経過時間を取得します。計測を始め直す場合は `reset()` を呼びます。例では読み取った値を `ms` に保存してから、開始時刻を更新しています。

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

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Timer()` | 現在時刻を開始時刻として保存。 | O(1) |
| `reset()` | 開始時刻を現在時刻に更新。 | O(1) |
| `elapsed(), operator()()` | 経過ミリ秒を long long で返す。 | O(1) |

## 利用条件と実装上の注意

返り値は long long 型のミリ秒です。秒数ではなく、1ミリ秒未満の端数は切り捨てられます。

時計には `high_resolution_clock` を使っているため、時刻が逆行しない単調時計であるかどうかは実装に依存します。厳密な制限時間管理で単調性が必要なら、その環境の時計の仕様も確認してください。
