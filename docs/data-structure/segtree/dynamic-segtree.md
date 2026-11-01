---
title: Dynamic Segment Tree
documentation_of: //data-structure/segtree/dynamic-segtree.hpp
link: https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
---

## 概要

`DynamicSegtree<Monoid,id_min,id_max>` は必要なノードのみ確保する区間積の木。定義域は `[id_min,id_max)`、`U=id_max-id_min`。

Q 回の更新で空間 O(Q log U)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `DynamicSegtree()` | 空の木。未設定点は e()。 | O(1) |
| `set(p, val)` | 点 p を上書き。 | O(log U) |
| `get(p)` | 点 p の値。 | O(log U) |
| `prod(l, r)` | [l,r) の積。 | O(log U) |

## 前提・注意点

`Monoid` は `value_type`、結合的な `op(l,r)`、単位元 `e()` を提供する型。演算・コピーが O(1) であるとして計算量を記す。添字は 0-indexed、区間は半開区間。

`id_min < id_max`、p は定義域内。現実装は `(l+r)/2` で分割するため、負の境界では丸めによって再帰が進まない場合がある。非負の定義域を使い、l+r のオーバーフローも避ける。解放処理はなく、コピーはノードを共有する。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/dynamic-segtree.hpp"
#include "data-structure/monoid/add.hpp"

int main() {
    DynamicSegtree<MonoidAdd<long long>, 0, 1000000000LL> seg;
    seg.set(123456, 10);
    assert(seg.prod(0, 200000) == 10);
}
```
