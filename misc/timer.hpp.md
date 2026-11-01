---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/utilities.test.cpp
    title: test/mytest/misc/utilities.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/timer.hpp\"\n\n#include <chrono>\n\nstruct Timer {\n\
    \    std::chrono::high_resolution_clock::time_point start_time;\n\n    Timer()\
    \ { reset(); }\n\n    // \u30BF\u30A4\u30DE\u30FC\u3092\u30EA\u30BB\u30C3\u30C8\
    \u3059\u308B\n    void reset() {\n        start_time = std::chrono::high_resolution_clock::now();\n\
    \    }\n\n    // \u30BF\u30A4\u30DE\u30FC\u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\
    \u4F55 milliseconds \u7D4C\u904E\u3057\u305F\u304B\u3092\u8FD4\u3059\n    long\
    \ long elapsed() {\n        auto end_time = std::chrono::high_resolution_clock::now();\n\
    \        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time\
    \ - start_time);\n        return elapsed_time.count();\n    }\n\n    // \u30BF\
    \u30A4\u30DE\u30FC\u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\u4F55 milliseconds\
    \ \u7D4C\u904E\u3057\u305F\u304B\u3092\u8FD4\u3059\n    auto operator()() { return\
    \ elapsed(); }\n};\n"
  code: "#pragma once\n\n#include <chrono>\n\nstruct Timer {\n    std::chrono::high_resolution_clock::time_point\
    \ start_time;\n\n    Timer() { reset(); }\n\n    // \u30BF\u30A4\u30DE\u30FC\u3092\
    \u30EA\u30BB\u30C3\u30C8\u3059\u308B\n    void reset() {\n        start_time =\
    \ std::chrono::high_resolution_clock::now();\n    }\n\n    // \u30BF\u30A4\u30DE\
    \u30FC\u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\u4F55 milliseconds \u7D4C\u904E\
    \u3057\u305F\u304B\u3092\u8FD4\u3059\n    long long elapsed() {\n        auto\
    \ end_time = std::chrono::high_resolution_clock::now();\n        auto elapsed_time\
    \ = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);\n\
    \        return elapsed_time.count();\n    }\n\n    // \u30BF\u30A4\u30DE\u30FC\
    \u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\u4F55 milliseconds \u7D4C\u904E\u3057\
    \u305F\u304B\u3092\u8FD4\u3059\n    auto operator()() { return elapsed(); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2025-03-09 11:08:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/misc/utilities.test.cpp
documentation_of: misc/timer.hpp
layout: document
title: "\u30BF\u30A4\u30DE\u30FC"
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
