---
title: 二次元累積和
documentation_of: //data-structure/sum2D.hpp
---

## 概要

`sum2D<T>` は静的な盤面の長方形和を求める。

空間 O(HW)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `sum2D(H, W)` | H×W の盤面を 0 で初期化。 | O(HW) |
| `add(row, column, val)` | 1 セルに加算。 | O(1) |
| `build()` | 二次元累積和を構築。 | O(HW) |
| `get_sum(row_l, row_r, column_l, column_r)` | 行 [row_l,row_r)、列 [column_l,column_r) の和。 | O(1) |

## 前提・注意点

全 `add` の後に `build` を 1 回だけ呼ぶ。構築後の追加・再構築には対応しない。いもす法の `add` と異なり、範囲取得の引数は行の両端・列の両端の順。添字は 0-indexed。デフォルト構築後はサイズ付きオブジェクトを代入する。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/sum2D.hpp"

int main() {
    sum2D<long long> sum(3, 4);
    sum.add(1, 2, 7);
    sum.build();
    assert(sum.get_sum(0, 2, 1, 3) == 7);
}
```
