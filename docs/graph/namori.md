---
title: なもりグラフの分解
documentation_of: //graph/namori.hpp
---

## 概要

`Namori<Cost>` は連結な無向グラフで閉路がちょうど 1 つある場合に、各頂点を閉路上の根に対応させる。Graph を継承する。

空間 O(N+M)、再帰スタック最大 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Namori(N)` | N 頂点を作る。 | O(N) |
| `add_undirected_edge(u, v, cost=1)` | 辺追加（Graph から継承）。 | 償却 O(1) |
| `size()` | 頂点数（継承）。 | O(1) |
| `build()` | 葉を除去して閉路を抽出し、枝の頂点に閉路 ID を付ける。 | O(N+M) |
| `operator[](v)` | v が属する閉路頂点の ID。 | O(1) |

## 前提・注意点

単純・連結な無向なもりグラフを入力し、全辺追加後に一度 build する。ID は元の頂点番号ではなく、閉路上の探索順番号。`operator[]` は Graph の隣接リスト取得を隠す。重みは分解に使わない。その他の継承 API は [Graph](https://github.com/siro53/compro_library/blob/main/docs/graph/graph_template.md) を参照。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/namori.hpp"

int main() {
    Namori<int> g(4);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    g.add_undirected_edge(2, 0);
    g.add_undirected_edge(1, 3);
    g.build();
    assert(g[1] == g[3]);
}
```
