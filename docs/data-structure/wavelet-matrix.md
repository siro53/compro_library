---
title: Wavelet Matrix
documentation_of: //data-structure/wavelet-matrix.hpp
---

## 概要

`WaveletMatrix<T, BITLEN=31>` は静的な非負整数列の順位・個数検索を行う。`N` は長さ、`B=BITLEN`。

空間 O(B ceil(N/64)) ワードに加え、構築時 O(N) の作業領域。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `WaveletMatrix(vector<int> v)` | 列をビットごとに分割して構築。 | O(NB) |
| `access(pos), operator[](pos)` | 元の値を返す。 | O(B) |
| `rank(i, x)` | [0,i) の x の個数。 | O(B) |
| `select(i, x)` | x の i 番目の出現位置を意図するが、下位実装に不備がある。 | O(B log N) |
| `quantile(l, r, i)` | [l,r) 内の昇順 i 番目（0-indexed）。 | O(B) |
| `rangefreq(l, r, xr)` | [l,r) 内で x<xr の個数。 | O(B) |
| `rangefreq(l, r, xl, xr)` | [l,r) 内で xl<=x<xr の個数。 | O(B) |
| `prev_value(l, r, xr)` | xr 未満の最大値。なければ -1。 | O(B) |
| `next_value(l, r, xl)` | xl 以上の最小値。なければ -1。 | O(B) |

## 前提・注意点

値と検索境界を `[0,2^B)` に収める。上限 `2^B` は表現できず、`rangefreq` の上限としても使えない。負数は座標圧縮などで変換する。構築引数は T によらず `vector<int>`。

`CompactBitVector::rank` の不備により、N が 64 の倍数で右端 N を問い合わせると配列外参照する。`select` も下位の select の不備により使用不可。`T` は -1 を表せる符号付き型を推奨。単体ヘッダーに非修飾 `vector` があるため本例の include 順を使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/wavelet-matrix.hpp"

int main() {
    WaveletMatrix<int, 4> wm(vector<int>{3, 1, 4, 1, 5});
    assert(wm.quantile(0, 5, 2) == 3);
    assert(wm.rangefreq(0, 5, 2) == 2);
}
```
