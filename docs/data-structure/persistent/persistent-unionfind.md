---
title: 永続 Union Find
documentation_of: //data-structure/persistent/persistent-unionfind.hpp
---

## 概要

`PersistentUnionFind` は永続配列に親・サイズを保存する。サイズによる併合を行い、経路圧縮はしない。`N` は頂点数。`Node*` を版の識別子として使う。

構築空間 O(N)、併合成功ごとに O(log N) の追加空間（配列の分岐数を定数とする）。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentUnionFind(N)` | N 個の単独集合を構築。 | O(N log N) 上界 |
| `leader_and_size(u[, r])` | 現在版または r 版で (代表, 集合サイズ)。 | O(log² N) |
| `leader(u[, r]), size(u[, r])` | 代表・集合サイズ。 | O(log² N) |
| `same(u, v[, r])` | 同じ集合か。 | O(log² N) |
| `merge(u, v[, r])` | 指定版から併合し現在 root を更新。既に同じなら false。 | O(log² N) |
| `get_root()` | 現在版の root。 | O(1) |

## 前提・注意点

`[,r]` は末尾の Node* 引数を省略したオーバーロードもあることを表す。併合成功後に `get_root()` を保存する。指定版で既に同じ集合のときは root は変わらず、その指定版へ切り替わるわけではない。`par/root` は内部状態。添字は `[0,N)`。ノードの解放処理はない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-unionfind.hpp"

int main() {
    PersistentUnionFind uf(3);
    auto r0 = uf.get_root();
    uf.merge(0, 1, r0);
    auto r1 = uf.get_root();
    assert(!uf.same(0, 1, r0));
    assert(uf.same(0, 1, r1));
}
```
