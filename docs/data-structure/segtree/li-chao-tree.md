---
title: Li Chao Tree
documentation_of: //data-structure/segtree/li-chao-tree.hpp
link: https://smijake3.hatenablog.com/entry/2018/06/16/144548
---

## 概要

`LiChaoTree<T,inf>` は事前指定した座標上で直線群の最小値を求める。`N` は入力座標数。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LiChaoTree(xs)` | xs をソート・重複排除して初期化。 | O(N log N) |
| `add_line(a, b)` | 全域に y=ax+b を追加。 | O(log N) |
| `add_segment(a, b, xl, xr)` | xl<=x<xr に限り有効な y=ax+b を追加。 | O(log² N) |
| `get_min(x)` | 有効な直線の最小値。なければ inf。 | O(log N) |

## 前提・注意点

xs は非空とし、問い合わせる x は必ず事前登録する。`inf` は全評価値より大きくする。`a*x+b` と内部の座標補完（末尾+1）が T の範囲に収まること。デフォルト構築だけでは利用できない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/li-chao-tree.hpp"

int main() {
    LiChaoTree<long long, (1LL << 60)> tree(vector<long long>{0, 2, 5});
    tree.add_line(2, 3);
    tree.add_segment(-1, 8, 2, 6);
    assert(tree.get_min(5) == 3);
}
```
