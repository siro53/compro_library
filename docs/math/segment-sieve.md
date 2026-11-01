---
title: 区間素数判定
documentation_of: //math/segment-sieve.hpp
---

## 概要

`SegmentSieve` は `[L,R)` の素数判定用の区間篩を意図するが、現実装には配列範囲と倍数計算の不備がある。

確保を意図した空間 O(sqrt(R)+R-L)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegmentSieve(L, R)` | 区間の素数判定表を作る意図。 | 現状は範囲外アクセスがあり保証なし |
| `operator[](k)` | large[k-L] の判定値を取得。 | O(1) |

## 前提・注意点

コンストラクタ内で small の長さが約 sqrt(R) なのに j<R まで書き込む。また large の開始位置を求める式で素数 i の乗算がなく、L 未満にアクセスし得る。0,1 の除外もないため、そのままでは利用不可。修正前に通常の区間篩の計算量・正しさを当てはめない。

## 使用例

以下は API の呼び出し形を示す例です。上記の実装上の問題があるため、そのままの利用は推奨しません。

```cpp
#include "template/template.cpp"
#include "math/segment-sieve.hpp"

int main() {
    SegmentSieve sieve(10, 20);
    bool prime = sieve[13];
}
```
