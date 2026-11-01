---
title: Heavy Light Decomposition
documentation_of: //graph/tree/hld.hpp
---

## このライブラリでできること

`HeavyLightDecomposition<Cost>` は、木の頂点を配列上に並べ直し、木の上の問い合わせを配列の区間問い合わせへ変換します。たとえば「頂点 $u$ から $v$ までのパス上の値の和」を、セグメント木の区間和へ分解できます。頂点数を $N$ とします。

各頂点で最も大きい部分木へ向かう辺を優先してたどり、長い鎖を連続した添字に並べます。優先しなかった辺を下るたびに部分木の大きさが少なくとも半分になるため、1本のパスは $O(\log N)$ 個の区間に分かれます。また、各部分木は1つの連続区間になります。

## 使い方

辺を追加して `build()` した後、頂点 $v$ の値をセグメント木などの位置 `hld[v]` に置きます。`path_query(u,v,f)` はパスを区間 $[l,r)$ に分解し、各区間について `f(l,r)` を呼びます。区間和なら、その中で `seg.prod(l,r)` を足し合わせる使い方になります。

以下の例は、各区間の長さを足してパス上の頂点数を数えています。$2\to1\to3$ のパスには3頂点あり、最小共通祖先は $1$ です。辺の値を扱う場合は、辺の深い側の頂点に値を置き、`edge=true` で LCA の位置を除きます。

```cpp
#include "template/template.cpp"
#include "graph/tree/hld.hpp"

int main() {
    HeavyLightDecomposition<> hld(4);
    hld.add_edge(0, 1);
    hld.add_edge(1, 2);
    hld.add_edge(1, 3);
    hld.build();
    int count = 0;
    hld.path_query(2, 3, [&](int l, int r) { count += r - l; });
    assert(count == 3 && hld.lca(2, 3) == 1);
}
```

## API・計算量

必要な空間と最大の再帰深さは、どちらも $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `HeavyLightDecomposition(N)` | N 頂点で初期化。 | O(N) |
| `HeavyLightDecomposition(G)` | 木をコピーして根 0 で構築。 | O(N) |
| `add_edge(u, v, cost=1)` | 無向辺追加。 | 償却 O(1) |
| `build(root=0)` | 重い子を選び DFS 順に番号を付ける。 | O(N) |
| `operator[](u)` | 頂点 u の配列上の位置。 | O(1) |
| `lca(u, v)` | 最小共通祖先。 | O(log N) |
| `dist(u, v)` | パスの辺数。重みは無視。 | O(log N) |
| `la(u, k)` | k 個上の祖先。存在しなければ -1。 | O(log N) |
| `path_query(u, v, f, edge=false)` | 分解した [l,r) ごとに f(l,r) を呼ぶ。 | O(log N) 回のコールバック |
| `path_query(u, v, f, f_rev, edge=false)` | u→LCA 側を f、LCA→v 側を f_rev で処理。 | O(log N) 回のコールバック |
| `subtree_query(u, f)` | 部分木の [l,r) に対して f を 1 回呼ぶ。 | O(1) + コールバック |

## 利用条件と実装上の注意

非空・連結な無向木に対して構築してください。辺を追加するコンストラクタでは全辺追加後に `build` が必要ですが、`Graph` を渡すコンストラクタは根0で構築まで行います。`la(u,k)` の $k$ は非負で、根より上なら $-1$ を返します。`dist` は重みではなく辺数です。

通知される区間は、$u$ から $v$ へ歩く順序に並ぶとは限りません。特に関数合成などの非可換な集約では、区間内の向きと区間同士の連結順を呼び出し側で管理してください。2つのコールバックを渡す版も、$v$ 側の区間は終点側から通知されます。

1区間の処理に $O(\log N)$ かかる場合、パス全体は $O(\log^2 N)$ 時間です。部分木の問い合わせは根頂点自身も含み、コールバックは1回だけ呼ばれます。
