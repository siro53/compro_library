---
title: Union Find
documentation_of: //data-structure/unionfind.hpp
---

## 概要

`UnionFind` は集合の併合と同一集合判定を行う。サイズによる併合と経路圧縮を使う。`N` は頂点数、α は逆 Ackermann 関数。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `UnionFind(N)` | 各頂点を別々の集合にする。 | O(N) |
| `leader(u)` | 代表頂点を返し、経路を圧縮。 | 償却 O(α(N)) |
| `same(u, v)` | 同じ集合か。 | 償却 O(α(N)) |
| `merge(u, v)` | 併合できたら true、既に同一なら false。 | 償却 O(α(N)) |
| `size(u)` | u の属する集合の要素数。 | 償却 O(α(N)) |
| `groups()` | 全集合を vector<vector<int>> で列挙。 | O(N α(N)) |
| `groups_with_map()` | 代表をキーとする map を作る。ただし現状は各集合の最初の頂点しか入らない。 | O(N log N) |

## 前提・注意点

頂点番号は `[0,N)`。`groups_with_map()` は `if(!g.count(l))` のため全頂点を列挙できない。集合列挙には `groups()` を使う。デフォルト構築後はサイズ付きオブジェクトを代入する。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/unionfind.hpp"

int main() {
    UnionFind uf(4);
    uf.merge(0, 2);
    assert(uf.same(0, 2));
    assert(uf.size(0) == 2);
    auto groups = uf.groups();
}
```
