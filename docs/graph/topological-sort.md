---
title: トポロジカルソート
documentation_of: //graph/topological-sort.hpp
---

## このライブラリでできること

`topological_sort(G)` は、有向辺 $u\to v$ に対して $u$ が $v$ より前に来るように頂点を並べます。依存関係のある作業を実行する順序や、DAG上の動的計画法の処理順を決めるために使えます。

入次数が0の頂点を取り出し、その頂点から出る辺を除く処理を繰り返します。頂点数 $N$、辺数 $M$ に対して $O(N+M)$ 時間です。

## 使い方

返り値は頂点番号の配列です。例の辺は $0\to1\to2$ なので、順序は $[0,1,2]$ になります。処理後は、返り値の長さが元の頂点数と等しいかも確認してください。等しければ全頂点を並べられています。

```cpp
#include "template/template.cpp"
#include "graph/topological-sort.hpp"

int main() {
    Graph<> g(3);
    g.add_directed_edge(0, 1);
    g.add_directed_edge(1, 2);
    auto order = topological_sort(g);
    assert((order == vector<int>{0, 1, 2}));
}
```

## API・計算量

入力とは別に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `topological_sort(G)` | 辺の向きに沿った頂点順序の vector<int>。 | O(N+M) |

## 利用条件と実装上の注意

閉路がある場合、トポロジカル順序は存在しません。この関数は例外ではなく、取り出せた頂点だけの配列を返すため、長さが $N$ 未満なら閉路ありと判断します。

複数の正しい順序があるとき、辞書順最小になる保証はありません。辺の重みは並べ替えに使いません。
