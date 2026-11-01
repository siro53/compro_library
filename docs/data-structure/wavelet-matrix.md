---
title: Wavelet Matrix
documentation_of: //data-structure/wavelet-matrix.hpp
---

## このライブラリでできること

`WaveletMatrix<T,BITLEN>` は、変更しない整数列について、区間内の順位や値の分布を調べるデータ構造です。「区間内で3番目に小さい値」「指定値未満の要素数」「ある値の直前・直後の値」といった問い合わせに向いています。

長さを $N$、扱う bit 数を $B=\mathrm{BITLEN}$ とします。上位 bit から順に値を $0$ 側と $1$ 側へ安定に分け、各段の移動先を bit 列の rank で追跡します。前処理は $O(NB)$、順位・個数の問い合わせは $O(B)$ 時間です。

## 使い方

配列を渡して構築した後は、その配列に対する問い合わせ専用として使います。例の列 $[3,1,4,1,5]$ を並べ替えると $[1,1,3,4,5]$ なので、0始まりの順位 $2$ にある値は $3$ です。また $2$ 未満の値は2個あるため、`rangefreq(0,5,2)` は $2$ を返します。

`prev_value(l,r,x)` は $x$ 未満の最大値、`next_value(l,r,x)` は $x$ 以上の最小値を求めます。前者が $x$ 自身を含まない点に注意してください。

```cpp
#include "template/template.cpp"
#include "data-structure/wavelet-matrix.hpp"

int main() {
    WaveletMatrix<int, 4> wm(vector<int>{3, 1, 4, 1, 5});
    assert(wm.quantile(0, 5, 2) == 3);
    assert(wm.rangefreq(0, 5, 2) == 2);
}
```

## API・計算量

保持するbit列と累積情報に $O(B\lceil N/64\rceil)$ ワード、構築中の作業用配列に $O(N)$ の空間を使います。

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

## 利用条件と実装上の注意

配列の値と検索に使う値の境界は $[0,2^B)$ に収めてください。`rangefreq` の上限にも $2^B$ 自体は渡せません。負の値は先に座標圧縮するなどして変換します。構築時の引数型は `T` によらず `vector<int>` です。

区間は $0\le l\le r\le N$ とし、`quantile(l,r,k)` ではさらに $0\le k<r-l$ が必要です。前後の値が存在しないときは $-1$ を返すため、返り値の型には符号付き型を推奨します。

下位の `CompactBitVector` に不備があり、$N$ が64の倍数のときの右端 $N$ を含む rank 計算は配列外参照になります。`select` も下位の実装に不備があるため使用できません。また、非修飾の `vector` を使うため、共通テンプレートを先に include してください。
