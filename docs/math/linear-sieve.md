---
title: 線形篩
documentation_of: //math/linear-sieve.hpp
---

## 概要

`LinearSieve` は各整数の最小素因数を線形時間で求める。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LinearSieve(N)` | [0,N] の最小素因数表を構築。 | O(N) |
| `operator[](k)` | k の最小素因数。0,1 は -1。 | O(1) |
| `factor(num)` | 重複込みの素因数を昇順で返す。0,1 は空。 | O(log(num+1)) |

## 前提・注意点

N>=0、`0<=num<=N`。0 の素因数分解を数学的に定義するわけではない。`p*d` を int で計算するので積が int の範囲を超えるサイズには注意。デフォルト構築のまま参照しない。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/linear-sieve.hpp"

int main() {
    LinearSieve sieve(100);
    assert(sieve[15] == 3);
    assert((sieve.factor(12) == vector<int>{2, 2, 3}));
}
```
