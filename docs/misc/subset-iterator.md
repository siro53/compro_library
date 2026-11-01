---
title: bit 集合の列挙
documentation_of: //misc/subset-iterator.hpp
---

## 概要

32 bit のマスクについて、部分集合と立っている bit の位置を range-for で列挙する。k=popcount(S)。各型の内部 Iter は現在のマスクと終了状態を保持する。

列挙器の追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Subset(S)` | S の全ての部分集合を降順に列挙。0 も含む。 | 構築 O(1)、全体 O(2^k) |
| `Subset_k(S,t)` | 要素数 t の部分集合を昇順に列挙。 | 構築 O(1)、全体 O(C(k,t)) |
| `SetBit(S)` | 立っている bit の添字を昇順に列挙。 | 構築 O(1)、全体 O(k) |
| `begin(), end()` | イテレータと nullptr の番兵を返す。 | O(1) |
| `各 Iter の構築、operator*, operator++, operator!=` | 初期化、現在値取得、次へ移動、終端判定。 | O(1) |

## 前提・注意点

`Subset_k` は `1<=t<=k<32`。k=32 は 32 bit シフトで未定義。SetBit は BMI、Subset_k は BMI/BMI2 対応の x86 CPU が必要で、実行時の CPU 判定は行わない。Subset は終端比較自体に副作用があり、汎用 STL イテレータではなく range-for 用として使う。ヘッダー内の assert のため <cassert> 等を先に include する。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/subset-iterator.hpp"

int main() {
    vector<uint32_t> subsets;
    for (auto s : Subset(5)) subsets.push_back(s);
    assert((subsets == vector<uint32_t>{5, 4, 1, 0}));
    vector<unsigned> bits;
    for (auto i : SetBit(10)) bits.push_back(i);
    assert((bits == vector<unsigned>{1, 3}));
}
```
