---
title: Compact Bit Vector
documentation_of: //data-structure/compact-bitvector.hpp
---

## このライブラリでできること

`CompactBitVector` は、長さ $N$ の $0/1$ 列を64 bitずつまとめて保存するクラスです。値そのものの参照に加え、「先頭から $i$ 個の中に $1$ がいくつあるか」を定数時間で数えられます。この個数を求める操作を rank と呼びます。

各64 bitブロックの手前までの個数を前計算し、端数の部分は bit の個数を数える命令で処理します。$K=\lceil N/64\rceil$ とすると、構築には $O(K+1)$ 時間・空間を使います。

## 使い方

`set(i,b)` で bit を設定した後に `build()` を呼びます。例では位置 $2,7$ が $1$ なので、`rank(8,1)` は区間 $[0,8)$ にある2個の $1$ を数えます。`set` で変更した後は累積情報が古くなるため、再び `build()` が必要です。

```cpp
#include "template/template.cpp"
#include "data-structure/compact-bitvector.hpp"

int main() {
    CompactBitVector bv(10);
    bv.set(2, 1);
    bv.set(7, 1);
    bv.build();
    assert(bv.rank(8, 1) == 2);
    assert(bv.select(1, 1) == 7);
    assert(bv.select(2, 1) == -1);
}
```

## API・計算量

必要な空間は $O(K+1)$ ワードです。空列でも累積和の先頭要素を保持します。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `CompactBitVector(), CompactBitVector(N)` | 空列、または N bit を 0 で初期化。 | O(K+1) |
| `set(i, b)` | i 番目を b（0 または 1）にする。 | O(1) |
| `access(i), operator[](i)` | i 番目の bit を返す。 | O(1) |
| `build()` | rank 用の累積和を構築。 | O(K+1) |
| `rank(i, b)` | [0, i) に含まれる b の個数。 | O(1) |
| `select(i, b)` | 0 始まりで i 番目の b の位置。存在しなければ -1。 | O(log(N+1)) |

## 利用条件と実装上の注意

要素の位置は $0\le i<N$、rank の境界は $0\le i\le N$ です。$N=0$ や64の倍数でも右端の rank を取得でき、空列の rank は0です。bit の値は0または1を指定してください。

`select(i,b)` は左から数えた出現順を0始まりで指定します。負の i や出現個数以上の i には -1 を返します。`rank/select` の前には、最後の `set` の後で `build()` を呼んでください。
