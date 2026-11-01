---
title: 重心分解
documentation_of: //graph/tree/centroid-decomposition.hpp
---

## このライブラリでできること

`CentroidDecomposition` は、木を重心で切り分けて再帰的に分解します。重心とは、その頂点を取り除いてできる各連結成分の大きさが、元の木の半分以下になる頂点です。重心を介してパスを数える問題や、木上の距離クエリを整理する際の土台になります。

各段で残る木のサイズが半分以下になるため、分解でできる木の高さは $O(\log N)$ です。ただし各段では部分木サイズを計算する必要があり、頂点数 $N$ の木全体の分解時間は $O(N\log N)$ になります。

## 使い方

`Graph<int>` を渡して構築しただけでは分解は実行されません。`decomp(0,-1)` を呼ぶと、`parent[v]` に重心木での親が入り、重心木の根だけは $-1$ になります。

例の3頂点の鎖では中央の $1$ が重心です。そのため `parent[1]` は $-1$ になります。`get_subtree_size` は分解途中のサイズ計算用で、通常は `decomp` から呼ばれます。

```cpp
#include "template/template.cpp"
#include "graph/tree/centroid-decomposition.hpp"

int main() {
    Graph<> g(3);
    g.add_undirected_edge(0, 1);
    g.add_undirected_edge(1, 2);
    CentroidDecomposition cd(g);
    cd.decomp(0, -1);
    assert(cd.parent[1] == -1);
}
```

## API・計算量

必要な空間は $O(N)$ です。重心木の高さは $O(\log N)$ ですが、部分木サイズを求める探索の再帰深さは最悪 $O(N)$ になります。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `CentroidDecomposition(g)` | Graph<int> への参照と作業配列を用意。 | O(N) |
| `get_subtree_size(u, p)` | removed を除く u の連結部分の部分木サイズを計算。 | O(K)、K は訪問頂点数 |
| `decomp(u, p)` | u を含む残りの木を分解。最初は decomp(0,-1)。 | O(N log N)（木全体） |

## 利用条件と実装上の注意

非空・連結な無向木を渡してください。元のグラフ `G` はコピーではなく参照として保持されるため、分解器より長く生存している必要があります。

`removed` はすでに重心として処理した頂点を示す作業用配列で、分解終了時には全要素が真になります。`subtree_size` も最後の処理時点の作業結果であり、元の根付き木の部分木サイズ表ではありません。同じ状態のまま分解を最初から繰り返すことはできません。サイズ計算の再帰深さは、重心木の高さとは異なり最悪 $O(N)$ です。
