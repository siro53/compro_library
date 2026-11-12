---
title: ランダムな数列・順列・部分集合・区間
documentation_of: //random/gen/sequence.hpp
---

## このライブラリでできること

ランダムテストの入力でよく使う数列を、[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) から生成する関数群です。

- `random_vector` は、各要素を独立に $[l,r)$ から選んだ数列を作ります。
- `random_distinct_vector` は、$[l,r)$ から相異なる $n$ 個を選び、ランダムな順に並べます。要素が相異なるという制約の問題に使えます。
- `random_permutation` は $(0,1,\dots,n-1)$ の順列を、`random_subset` は $\{0,1,\dots,n-1\}$ の $k$ 元部分集合を作ります。
- `random_interval` は、区間クエリの入力として $l \le a < b \le r$ を満たす半開区間 $[a,b)$ を作ります。

どの関数も、取り得る結果の上で一様分布になるように選びます。数列の範囲はすべて右端を含まない半開区間です。

## 使い方

第1引数に `Random` を渡し、続けて長さと値の範囲を渡します。例では、$1$ 以上 $9$ 以下の値からなる長さ $5$ の数列、$0$ 以上 $99$ 以下の相異なる $3$ 個、長さ $4$ の順列、区間を作っています。

```cpp
#include "template/template.cpp"
#include "random/gen/sequence.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    vector<int> a = random_vector(rng, 5, 1, 10);
    for(int x : a) assert(1 <= x && x < 10);

    vector<int> d = random_distinct_vector(rng, 3, 0, 100);
    assert(set<int>(d.begin(), d.end()).size() == 3);

    vector<int> p = random_permutation(rng, 4);   // 0, 1, 2, 3 の並べ替え
    vector<int> s = random_subset(rng, 10, 3);    // 昇順の 3 要素
    assert(s.size() == 3 && is_sorted(s.begin(), s.end()));

    auto [l, r] = random_interval(rng, 0, 5);     // 0 <= l < r <= 5
    assert(0 <= l && l < r && r <= 5);

    // 1-indexed の順列と閉区間 [l+1, r] で出力する
    for(int &x : p) x++;
    print(p);
    print(l + 1, r);
}
```

順列は0始まりで返すので、1始まりで出力する場合は例のように $1$ を足します。`random_interval` の結果 $[l,r)$ は、閉区間 $[l+1,r]$ と書く1始まりの形式に変換できます。

## API・計算量

以下では、生成する長さを $n$ または $k$、値の範囲の幅を $w=r-l$ とします。各関数は結果の `vector` として $O(n)$ の領域を使い、`random_distinct_vector` は選んだ値を記録するハッシュ集合として追加で $O(n)$ を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_vector(rng, n, l, r)` | 各要素が独立に $[l,r)$ の一様乱数である長さ $n$ の `vector`。要素型は `l`, `r`, `int` の共通型。 | 期待 $O(n)$ |
| `random_distinct_vector(rng, n, l, r)` | $[l,r)$ の $n$ 元部分集合を一様に選び、一様ランダムな順に並べた `vector`。 | 期待 $O(n)$ |
| `random_permutation(rng, n)` | $(0,\dots,n-1)$ の一様ランダムな順列。 | 期待 $O(n)$ |
| `random_subset(rng, n, k)` | $\{0,\dots,n-1\}$ の $k$ 元部分集合を一様に選び、昇順で返す。 | 期待 $O(k \log k)$ |
| `random_interval(rng, l, r)` | $l \le a < b \le r$ を満たす $(a,b)$ を一様に選び、`pair` で返す。 | 期待 $O(1)$ |

`random_distinct_vector` は Floyd のサンプリングで値を選びます。$j=w-n,\dots,w-1$ の順に $t \in [0,j]$ を一様に引き、$t$ が選択済みなら代わりに $j$ を選びます。こうすると、$n$ 元部分集合のどれもが等確率で得られます。その後で全体をシャッフルするため、並び順も一様です。ハッシュ集合の操作は期待 $O(1)$ として計算量を示しています。

## 利用条件と実装上の注意

- `random_vector` は $n \ge 0$ かつ $l<r$ を要求します。$n=0$ なら空の `vector` を返します。
- `random_distinct_vector` は $0 \le n \le w$ を要求します。$n=w$ なら $[l,r)$ の全要素の並べ替えになります。$w$ が大きくても、計算量は $w$ に依存しません。
- `random_subset` は $0 \le k \le n$ を要求します。
- `random_interval` は $l<r$ を要求し、空でない区間だけを返します。幅 $w$ に対して $w(w+1)/2$ 通りの区間がそれぞれ等確率で出ます。内部で $r+1$ を計算するため、$r$ が型の最大値のときは使えません。
- 範囲や長さが条件を満たさない場合は `assert` で停止します。
