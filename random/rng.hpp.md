---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: "\u6728\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/binary-trie.test.cpp
    title: test/mytest/data-structure/binary-trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/erasable-priority-queue.test.cpp
    title: test/mytest/data-structure/erasable-priority-queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph/tree-api.test.cpp
    title: test/mytest/graph/tree-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/fraction.test.cpp
    title: test/mytest/misc/fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/utilities.test.cpp
    title: test/mytest/misc/utilities.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/rng.hpp\"\n\n#include <chrono>\n#include <random>\n\
    \nclass RNG32 {\n  public:\n    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n\nclass RNG_0_1 {\n  public:\n    RNG_0_1() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    // [0.0, 1.0)\n    double rand() {\n      auto bits = mt() >> 11;\n\
    \      return (double)bits / denomitor;\n    }\n\n    auto operator()() { return\
    \ rand(); }\n\n  private:\n    std::mt19937_64 mt;\n    const double denomitor\
    \ = 1LL << 53;\n};\n"
  code: "#pragma once\n\n#include <chrono>\n#include <random>\n\nclass RNG32 {\n \
    \ public:\n    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n\nclass RNG_0_1 {\n  public:\n    RNG_0_1() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n    // [0.0, 1.0)\n    double rand() {\n      auto bits = mt() >> 11;\n\
    \      return (double)bits / denomitor;\n    }\n\n    auto operator()() { return\
    \ rand(); }\n\n  private:\n    std::mt19937_64 mt;\n    const double denomitor\
    \ = 1LL << 53;\n};"
  dependsOn: []
  isVerificationFile: false
  path: random/rng.hpp
  requiredBy:
  - graph/tree/tree-hash.hpp
  timestamp: '2025-03-09 11:07:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj2821.test.cpp
  - test/mytest/misc/fraction.test.cpp
  - test/mytest/misc/utilities.test.cpp
  - test/mytest/data-structure/binary-trie.test.cpp
  - test/mytest/data-structure/erasable-priority-queue.test.cpp
  - test/mytest/graph/tree-api.test.cpp
documentation_of: random/rng.hpp
layout: document
title: "\u4E71\u6570\u751F\u6210"
---

## このライブラリでできること

`RNG32` と `RNG64` は範囲を指定した整数乱数、`RNG_0_1` は $[0,1)$ の実数乱数を生成するクラスです。テスト用の入力や乱択アルゴリズムの選択肢を作るために使えます。

整数版の返り値はそれぞれ int と long long です。実数版は53 bitから値を作るため、数学的な連続分布ではなく、$k/2^{53}$（$0\le k<2^{53}$）という離散的な値を返します。

## 使い方

整数乱数の範囲は右端を含みません。サイコロなら例のように `randint(1,7)` とすると $1$ から $6$ までを得られます。引数1つの `randint(r)` は `randint(0,r)` と同じです。

`RNG_0_1` は `rand()` と関数呼び出し演算子のどちらでも利用できます。上端の $1$ は返さないため、確率 $p$ の判定なら `rng()<p` と書けます。

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

## API・計算量

各エンジンは固定サイズの状態を持つため、空間計算量は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RNG32(), RNG64(), RNG_0_1()` | 時刻からエンジンを初期化。 | 固定サイズの初期化 O(1) |
| `RNG32::randint(l,r), RNG64::randint(l,r)` | [l,r) の整数。型は int / long long。 | 期待 O(1) |
| `RNG32::randint(r), RNG64::randint(r)` | [0,r) の整数。 | 期待 O(1) |
| `RNG_0_1::rand(), operator()()` | [0,1) の double（53 bit の分解能）。 | 償却 O(1) |

## 利用条件と実装上の注意

整数の範囲は必ず $l<r$ にしてください。エンジンは構築時の時刻で初期化され、seedを指定するAPIはありません。結果を再現したいテストや暗号用途の乱数を提供するものではありません。

整数分布は範囲を均等にするために再試行する場合があるので、表では期待計算量を使っています。エンジンの状態は入力サイズに依存しない固定サイズです。
