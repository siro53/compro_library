---
title: Union Find
documentation_of: //data-structure/unionfind.hpp
---

## このライブラリでできること

`UnionFind` は、互いに重ならない集合を管理するデータ構造です。最初は $N$ 個の要素がそれぞれ別の集合に属し、`merge(u,v)` で2つの集合をまとめます。「辺を追加した後、2頂点はつながっているか」といった連結性の管理に使えます。

各集合を根付き木で表し、その根を代表要素とします。小さい木を大きい木につなぎ、代表を調べる際には親を付け替えて経路を短くします。これにより、併合・代表取得・同一集合判定の時間は償却 $O(\alpha(N))$ です。$\alpha$ は逆 Ackermann 関数で、実用的なサイズでは非常に小さい値です。

## 使い方

要素数を指定して構築した後、`merge` で併合し、`same` で同じ集合かを調べます。例では $0$ と $2$ を併合しているので、`same(0,2)` は真、`size(0)` は $2$ です。`merge` は新たに併合したときだけ `true` を返すため、閉路検出などにも使えます。

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

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `UnionFind(N)` | 各頂点を別々の集合にする。 | O(N) |
| `leader(u)` | 代表頂点を返し、経路を圧縮。 | 償却 O(α(N)) |
| `same(u, v)` | 同じ集合か。 | 償却 O(α(N)) |
| `merge(u, v)` | 併合できたら true、既に同一なら false。 | 償却 O(α(N)) |
| `size(u)` | u の属する集合の要素数。 | 償却 O(α(N)) |
| `groups()` | 全集合を vector<vector<int>> で列挙。 | O(N α(N)) |
| `groups_with_map()` | 代表をキーとする map を作る。ただし現状は各集合の最初の頂点しか入らない。 | O(N log N) |

## 利用条件と実装上の注意

要素番号は $[0,N)$ です。一度併合した集合を分割する操作はありません。代表要素の番号も併合によって変わるため、常に最小番号になるとは考えないでください。

全集合の列挙には `groups()` を使ってください。`groups_with_map()` は現実装では各集合の最初の要素しか追加せず、集合全体を返せません。引数なしで構築した場合は、サイズ付きのオブジェクトを代入してから利用します。
