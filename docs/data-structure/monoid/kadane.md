---
title: 最大部分配列和モノイド
documentation_of: //data-structure/monoid/kadane.hpp
---

## 概要

`MonoidKadane<T>` は区間の非空最大部分配列和を集約する。`S/value_type` は `lmax`（最大 prefix 和）、`rmax`（最大 suffix 和）、`allmax`（最大部分配列和）、`sum`（全体和）を持つ。

空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `S(lmax, rmax, allmax, sum)` | 集約値を作る。デフォルト構築では各値は未初期化。 | O(1) |
| `op(l, r)` | 左右を連結した区間の集約値。 | O(1) |
| `e()` | (numeric_limits<T>::min(), 同左, 同左, 0)。 | O(1) |

## 前提・注意点

1 要素 x は `S(x,x,x,x)`。現実装は負の無限大相当の値をそのまま加算するため、整数型で `op(e(),e())` や負数との演算が符号付きオーバーフローを起こす。通常の Segtree の単位元として安全に使うには実装修正が必要。ここでは実要素同士の結合だけを例示する。浮動小数点の min() も負の無限大ではない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/kadane.hpp"

int main() {
    using M = MonoidKadane<long long>;
    auto s = M::op(M::S(2, 2, 2, 2), M::S(-1, -1, -1, -1));
    assert(s.allmax == 2 && s.sum == 1);
}
```
