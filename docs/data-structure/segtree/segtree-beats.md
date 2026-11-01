---
title: Segment Tree Beats
documentation_of: //data-structure/segtree/segtree-beats.hpp
---

## このライブラリでできること

`SegtreeBeats<MonoidAct>` は、区間をまとめて更新できる場合だけ更新し、できない場合は子の区間へ降りるセグメント木です。通常の遅延セグメント木では、すべての更新を区間の集約値だけから処理できる必要があります。Segment Tree Beats では、その判定自体を集約型の `fail` フラグで表します。

典型例は $A_i\leftarrow\min(A_i,x)$ という上限を設ける更新です。区間の最大値・2番目に大きい値・最大値の個数などを持てば、最大値だけが変わる場合は和を一度に更新できます。それ以外の場合に、より細かい区間へ降ります。ただし、このヘッダーがその集約型を用意しているわけではありません。

## 使い方

`LazySegtree` と同じ集約・作用の定義に加え、集約型に `bool fail` を持たせます。`mapping` は集約値だけで正しく更新できないときに `fail=true` を返し、葉では必ず成功させてください。

以下の例は、APIの接続方法を示すために、常に更新が成功する区間加算を使っています。したがって Beats 特有の高速化を示す例ではありません。上限・下限を設ける更新を使う場合は、それに必要な統計量と失敗条件を別途設計します。

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/segtree-beats.hpp"
struct RangeAddSum {
    struct S { long long sum; int len; bool fail = false; };
    using value_type_S = S;
    using value_type_F = long long;
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {0, 0}; }
    static S mapping(long long f, S x) { return {x.sum + f * x.len, x.len}; }
    static long long composition(long long f, long long g) { return f + g; }
    static long long id() { return 0; }
};

int main() {
    SegtreeBeats<RangeAddSum> seg(vector<RangeAddSum::S>{ {1, 1}, {2, 1}, {3, 1}});
    seg.apply(0, 2, 5);
    assert(seg.prod(0, 3).sum == 16);
}
```

## API・計算量

必要な空間は $O(N+1)$ です。表では、渡した集約・作用の演算を $O(1)$ としています。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegtreeBeats(), SegtreeBeats(n), SegtreeBeats(v)` | 空、n 個の e()、列 v から構築。 | O(N+1) |
| `set(pos, val)` | 点を上書き。 | O(log N + V) |
| `get(pos)` | 遅延作用を反映した点の値。 | O(log N + V) |
| `prod(l, r)` | [l,r) の積。 | O(log N + V) |
| `all_prod()` | 全体の積。 | O(1) |
| `apply(pos, f)` | 点に作用 f を適用。 | O(log N + V) |
| `apply(l, r, f)` | [l,r) に作用 f を適用。 | O(log N + V) |
| `max_right(l, g)` | g(prod(l,r)) が true となる最大 r。 | O(log N + V) |
| `min_left(r, g)` | g(prod(l,r)) が true となる最小 l。 | O(log N + V) |

## 利用条件と実装上の注意

配列長を $N$、1操作中に失敗処理によって追加で訪問するノード数を $V$ とします。表の $O(\log N+V)$ は各集約・作用を定数時間とした評価です。$V$ は最悪 $O(N)$ になり得るため、この汎用クラスを使うだけで対数時間が保証されるわけではありません。償却計算量は、実装する更新の種類と集約情報に応じて証明する必要があります。

`composition(f,g)` は $g$ の後に $f$ を適用する合成です。失敗した更新も子へ伝えられる必要があり、`op/e` が返す `fail` の状態も整合させてください。サイズだけで構築すると葉は `e()` になるため、必要なら長さなどを持つ初期配列を渡します。

現実装では `max_right` の外側ループに次のノードへ進む処理がなく、`min_left` の上方移動条件にも不備があります。これらの境界探索は使用しないでください。
