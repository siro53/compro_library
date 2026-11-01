---
title: bit 集合の列挙
documentation_of: //misc/subset-iterator.hpp
---

## このライブラリでできること

`Subset`、`Subset_k`、`SetBit` は、32 bit整数を集合とみなし、range-forで部分集合や要素を列挙するための型です。bit $i$ が立っていることを、要素 $i$ が集合に含まれることと対応させます。

$k=\operatorname{popcount}(S)$ とすると、`Subset(S)` は空集合を含む $2^k$ 個、`Subset_k(S,t)` は要素数が $t$ の $\binom kt$ 個、`SetBit(S)` は $k$ 個の要素の添字を列挙します。1回のイテレータ操作は定数時間です。

## 使い方

例の `Subset(5)` では $5=101_2$ なので、部分集合のマスクは $5,4,1,0$ の順に現れます。`Subset` は降順、`Subset_k` は固定個数の部分集合を昇順に列挙します。

`SetBit(10)` は $10=1010_2$ の立っている位置を返すので、返り値はマスクではなく添字 $1,3$ です。何を列挙しているかを区別して使ってください。

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

## API・計算量

列挙器自身が使う追加空間は $O(1)$ です。列挙結果を配列などに保存する場合、その分の領域は別途必要になります。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Subset(S)` | S の全ての部分集合を降順に列挙。0 も含む。 | 構築 O(1)、全体 O(2^k) |
| `Subset_k(S,t)` | 要素数 t の部分集合を昇順に列挙。 | 構築 O(1)、全体 O(C(k,t)) |
| `SetBit(S)` | 立っている bit の添字を昇順に列挙。 | 構築 O(1)、全体 O(k) |
| `begin(), end()` | イテレータと nullptr の番兵を返す。 | O(1) |
| `各 Iter の構築、operator*, operator++, operator!=` | 初期化、現在値取得、次へ移動、終端判定。 | O(1) |

## 利用条件と実装上の注意

`Subset_k(S,t)` は $1\le t\le k<32$ の範囲で使います。$k=32$ は32 bit幅を超えるシフトになるため使えません。`SetBit` はBMI、`Subset_k` はBMI/BMI2命令に対応したx86 CPUが必要で、実行時の対応判定はしません。

各内部イテレータは `operator*` で現在値、`operator++` で次の状態、`operator!=` で終了を扱います。特に `Subset` の終端比較には副作用があるため、汎用STLイテレータではなくrange-for用として使ってください。ヘッダーは assert に必要な標準ヘッダーも含みます。
