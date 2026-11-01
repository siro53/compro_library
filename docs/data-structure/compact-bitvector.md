---
title: Compact Bit Vector
documentation_of: //data-structure/compact-bitvector.hpp
---

## 概要

`CompactBitVector` は 64 bit 単位でビット列を保存し、ブロック累積和から rank を求める。`N` はビット数、`K=ceil(N/64)`。

空間 O(K) ワード。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `CompactBitVector(N)` | N bit を 0 で初期化。 | O(K) |
| `set(i, b)` | i 番目を b（0 または 1）にする。 | O(1) |
| `access(i), operator[](i)` | i 番目の bit を返す。 | O(1) |
| `build()` | rank 用の累積和を構築。 | O(K) |
| `rank(i, b)` | [0, i) に含まれる b の個数。 | O(1) |
| `select(i, b)` | b の出現位置検索用だが、現状は実装不備がある。 | O(log N) |

## 前提・注意点

`set` 後に `rank` を使う前には `build()` を呼ぶ。`rank(N,b)` は N が 64 の倍数だと配列外参照になる。N=0 も同様。`select` は個数の判定が逆で、二分探索中も `rank(mid,b)` ではなく `rank(i,b)` を呼んでいるため利用不可。デフォルト構築では配列が未初期化。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/compact-bitvector.hpp"

int main() {
    CompactBitVector bv(10);
    bv.set(2, 1);
    bv.set(7, 1);
    bv.build();
    assert(bv.rank(8, 1) == 2);
}
```
