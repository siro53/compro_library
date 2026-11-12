---
title: ランダムなグラフ
documentation_of: //random/gen/graph.hpp
---

## このライブラリでできること

[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) を使って、ランダムテスト用のグラフを生成します。どの関数も多重辺と自己ループを含まない単純グラフを返します。

- `random_simple_graph` は、$n$ 頂点 $m$ 辺の無向単純グラフ $\binom{N}{m}$ 通り（$N=n(n-1)/2$）から1つを一様に選びます。
- `random_connected_graph` は、連結な $n$ 頂点 $m$ 辺の無向単純グラフを作ります。
- `random_dag` は、$n$ 頂点 $m$ 辺の有向非巡回グラフ (DAG) を作ります。
- `add_random_weights` は、辺に一様ランダムな重みを付けます。

辺は0始まりの頂点番号の `pair` で返ります。[木の生成](https://github.com/siro53/compro_library/blob/main/docs/random/gen/tree.md) と同じく、最後に頂点番号の付け替えと、辺の向き・順序のシャッフルを行います。

## 使い方

例では、連結な重み付き無向グラフを1始まりで出力し、続けて DAG が位相順序を持つことを確かめています。$m$ の上限は単純グラフの辺数 $n(n-1)/2$ です。

```cpp
#include "template/template.cpp"
#include "random/gen/graph.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    int n = rng.size(2, 9);
    long long max_m = (long long)n * (n - 1) / 2;
    long long m = rng.randint(n - 1, max_m + 1);     // n-1 <= m <= max_m
    auto edges = add_random_weights(rng, random_connected_graph(rng, n, m), 1, 10);
    print(n, m);
    for(auto [u, v, w] : edges) print(u + 1, v + 1, w);

    auto dag = random_dag(rng, 5, 4);
    vector<int> indeg(5);
    for(auto [u, v] : dag) indeg[v]++;
    assert(count(indeg.begin(), indeg.end(), 0) >= 1);  // 入次数 0 の頂点がある
}
```

## API・計算量

頂点数を $n$、辺数を $m$、単純グラフの最大辺数を $N=n(n-1)/2$ とします。返り値の辺列に $O(m)$、頂点の置換に $O(n)$、使用済みの辺を記録するハッシュ集合に $O(m)$ の領域を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_simple_graph(rng, n, m)` | $n$ 頂点 $m$ 辺の無向単純グラフを一様に選んだ辺列。 | 期待 $O(n+m)$ |
| `random_connected_graph(rng, n, m)` | $n$ 頂点 $m$ 辺の連結な無向単純グラフの辺列。分布は後述。 | 期待 $O(n+m)$ |
| `random_dag(rng, n, m)` | $n$ 頂点 $m$ 辺の DAG。有向辺 $(u,v)$ は $u \to v$ を表す。 | 期待 $O(n+m)$ |
| `add_random_weights(rng, edges, l, r)` | 各辺 $(u,v)$ に $[l,r)$ の一様な重み $w$ を付けた `tuple(u, v, w)` の列。重みの型は `l`, `r`, `int` の共通型。 | 期待 $O(m)$ |

辺の選び方は、選ぶ本数 $k$ と候補の本数 $A$ の大小で切り替えます。$2k \le A$ なら、ランダムな頂点対を引き、未使用ならば採用することを繰り返します。各回で採用される確率は $1/2 \cdot A/N$ 以上です。そうでなければ候補をすべて列挙し、先頭 $k$ 本だけ Fisher-Yates を行います。このとき $N < 2k + (\text{除外する辺の本数})$ なので、列挙の手間も $O(n+m)$ です。

## 利用条件と実装上の注意

- `random_simple_graph` と `random_dag` は $n \ge 0$ かつ $0 \le m \le N$ を要求します。
- `random_connected_graph` は $n \ge 1$ かつ $n-1 \le m \le N$ を要求します。一様な木を作り、木に含まれない辺から $m-n+1$ 本を一様に加えます。連結グラフ全体の上での一様分布ではありません。
- `random_dag` は、一様な無向単純グラフの各辺を、一様ランダムな頂点の順序で前から後ろへ向けます。DAG 全体の上での一様分布ではありません。
- 頂点数 $n$ に対して $N$ を `long long` で計算します。
- 条件を満たさない場合は `assert` で停止します。
