---
title: グラフ構造体
documentation_of: //graph/graph_template.hpp
---

## このライブラリでできること

`Graph<Cost>` は、各頂点から出る辺を隣接リストで保持するグラフです。頂点数を $N$、辺の追加回数を $M$ とすると、必要な空間は $O(N+M)$ です。有向辺と無向辺の両方を追加でき、辺の重みの型を `Cost` で指定します。

1本の辺を表す `Edge<Cost>` は、始点 `from`、終点 `to`、重み `cost`、辺番号 `id` を持ちます。無向辺は同じ辺番号を持つ2本の有向辺として保存するため、どちら側から見ても元の辺を識別できます。

## 使い方

頂点数を指定して構築し、`add_directed_edge` または `add_undirected_edge` で辺を追加します。例では $0$ と $1$ の間に重み $5$ の無向辺、$1$ から $2$ へ重み $7$ の有向辺を追加しています。

頂点 `u` の隣接辺は `g[u]` で取得します。`for (const auto& e : g[u])` とすれば重みや辺番号も参照でき、`for (int v : g[u])` とすれば `Edge` の整数変換によって行き先だけを取り出せます。

```cpp
#include "template/template.cpp"
#include "graph/graph_template.hpp"

int main() {
    Graph<long long> g(3);
    g.add_undirected_edge(0, 1, 5);
    g.add_directed_edge(1, 2, 7);
    assert(g[0][0].to == 1 && g[0][0].cost == 5);
}
```

## API・計算量

グラフと作業領域を合わせて $O(N+M)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Graph(N)` | N 頂点・辺なしで初期化。 | O(N) |
| `Edge(from, to, cost=1, id=-1)` | 辺を作る。デフォルト構築の整数メンバは未初期化。 | O(1) |
| `Edge::operator int()` | 行き先 to に変換。 | O(1) |
| `add_directed_edge(from, to, cost=1)` | 有向辺を 1 本追加。 | 償却 O(1) |
| `add_undirected_edge(from, to, cost=1)` | 同じ id の辺を両方向に追加。 | 償却 O(1) |
| `size()` | 頂点数。 | O(1) |
| `operator[](i)` | i の出辺リストへの参照（const 版もある）。 | O(1) |

## 利用条件と実装上の注意

頂点番号は $[0,N)$ です。辺番号は追加順に0から付き、無向辺も1回の追加で番号を1つだけ消費します。`Edges<Cost>` は `vector<Edge<Cost>>` の別名であり、グラフ全体とは別の辺のリストです。

`Graph()` のデフォルト構築では頂点数などが初期化されません。サイズ付きのグラフを代入してから利用してください。`Edge()` の数値メンバも未初期化なので、辺を直接作る場合は端点などを明示します。
