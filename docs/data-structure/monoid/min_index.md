---
title: 添字付き最小値モノイド
documentation_of: //data-structure/monoid/min_index.hpp
---

## 概要

`MonoidMinWithIndex<T>` は 添字付き最小値を区間集約に使うための型。`value_type` は `std::pair<T,int>`（値、添字）。

追加空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | pair の辞書順最小 を返す。 | O(1) |
| `e()` | 単位元 (INF,-1) を返す。 | O(1) |

## 前提・注意点

同値なら小さい添字を選ぶ。INF の既定値は numeric_limits<T>::max()。実データの値は INF 未満とする（同値だと単位元の添字 -1 が優先される）。

`Segtree<M>` などのテンプレート引数に渡す。演算の中間値が型の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/min_index.hpp"

int main() {
    using M = MonoidMinWithIndex<int>;
    auto x = M::op({4, 2}, {4, 5});
    assert(x.second == 2);
}
```
