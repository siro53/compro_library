---
title: 二次元いもす法
documentation_of: //data-structure/imos2D.hpp
---

## 概要

`imos2D<T>` は長方形への加算を差分配列でまとめて処理する。公開メンバ `H,W` は盤面サイズ。

空間 O(HW)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `imos2D(H, W)` | H×W の盤面を 0 で初期化。 | O(HW) |
| `add(li, lj, ri, rj, val)` | 行 [li,ri)、列 [lj,rj) に加算予約。 | O(1) |
| `build()` | 累積して各セルの値を確定。 | O(HW) |
| `operator[](i)` | 構築後の i 行目への参照。 | O(1) |

## 前提・注意点

全 `add` の後に `build` を 1 回だけ呼ぶ。構築後の追加・再構築には対応しない。`0 <= li < H, li <= ri <= H`、列も同様。デフォルト構築後はサイズ付きオブジェクトを代入する。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/imos2D.hpp"

int main() {
    imos2D<int> imos(3, 4);
    imos.add(0, 1, 2, 4, 5);
    imos.build();
    assert(imos[1][2] == 5);
}
```
