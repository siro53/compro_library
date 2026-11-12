---
title: ランダムな木
documentation_of: //random/gen/tree.hpp
---

## このライブラリでできること

[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) を使って、ランダムテスト用の木を生成します。

- `random_tree` は、頂点 $0,\dots,n-1$ 上のラベル付き木 $n^{n-2}$ 通りから1つを一様に選びます。
- `random_path_tree` と `random_star_tree` は、それぞれパスグラフとスターグラフを作ります。直径が最大・最小になる極端な形で、再帰の深さや次数の偏りを試すのに使います。
- `random_parent_array` は、「頂点 $i$ の親 $p_i$ は $p_i<i$ を満たす」という形式の入力を作ります。
- `relabel_edges` は、与えた辺集合の頂点番号を一様ランダムに付け替え、辺の向きと順序をシャッフルします。

辺の列を返す関数は、すべて最後に `relabel_edges` を通します。生成アルゴリズムの癖として「辺 $(u,v)$ が常に $u<v$」「辺が親から子の順に並ぶ」といった規則性が残ると、解答がそれに依存していてもバグが見つかりません。それを防ぐための処理です。

## 使い方

辺は0始まりの頂点番号の `pair` で返ります。1始まりの入力形式なら、出力時に $1$ を足します。例では、木の辺を1行ずつ出力し、続けて親配列を $p_2,\dots,p_n$ の形式で出力します。

```cpp
#include "template/template.cpp"
#include "random/gen/tree.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    int n = rng.size(2, 9);
    vector<pair<int, int>> edges = random_tree(rng, n);
    assert((int)edges.size() == n - 1);
    print(n);
    for(auto [u, v] : edges) print(u + 1, v + 1);

    vector<int> par = random_parent_array(rng, n);
    assert(par[0] == -1);
    vector<int> p;
    for(int i = 1; i < n; i++) p.push_back(par[i] + 1);  // p_i < i (1-indexed)
    print(p);
}
```

`random_parent_array` は頂点 $0$ を根とし、`par[0]` に $-1$ を入れます。

## API・計算量

頂点数を $n$、`relabel_edges` に渡す辺の本数を $m$ とします。返り値の領域は $O(n)$ または $O(m)$ で、`relabel_edges` は頂点の置換のために追加で $O(n)$ を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_tree(rng, n)` | 一様ランダムなラベル付き木の辺 $n-1$ 本。 | 期待 $O(n)$ |
| `random_path_tree(rng, n)` | パスグラフの辺 $n-1$ 本。頂点の並びは一様ランダム。 | 期待 $O(n)$ |
| `random_star_tree(rng, n)` | スターグラフの辺 $n-1$ 本。中心は一様ランダム。 | 期待 $O(n)$ |
| `random_parent_array(rng, n)` | 長さ $n$ の `vector<int>`。`par[0] = -1`、$i \ge 1$ では `par[i]` は $[0,i)$ の一様乱数。 | 期待 $O(n)$ |
| `relabel_edges(rng, n, edges)` | 一様ランダムな頂点の置換 $\sigma$ で各辺 $(u,v)$ を $(\sigma(u),\sigma(v))$ に写し、確率 $1/2$ で向きを反転し、辺の順序をシャッフルした辺列。 | 期待 $O(n+m)$ |

`random_tree` は、各項が $[0,n)$ の一様乱数である長さ $n-2$ の Prüfer 列を作り、線形時間で木に復元します。Prüfer 列とラベル付き木は一対一に対応するので、得られる木は一様分布に従います。

## 利用条件と実装上の注意

- すべての木生成関数は $n \ge 1$ を要求します。$n=1$ なら辺は空です。
- `relabel_edges` の各端点は $[0,n)$ に含まれる必要があります。辺集合が木でなくても使えます。
- `random_parent_array` が作る木はランダム再帰木で、深さの期待値は $O(\log n)$ です。この形式で深い木を試したい場合は、`random_path_tree` などとは別に、`par[i] = i - 1` に近い値を混ぜる生成を自分で書いてください。
- `random_tree` が作る一様な木の直径は、期待値で $\Theta(\sqrt{n})$ 程度です。直径の大きい木や次数の大きい頂点は出にくいので、パスやスターも併用すると極端なケースを試せます。
- 条件を満たさない場合は `assert` で停止します。
