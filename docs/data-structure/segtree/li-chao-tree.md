---
title: Li Chao Tree
documentation_of: //data-structure/segtree/li-chao-tree.hpp
link: https://smijake3.hatenablog.com/entry/2018/06/16/144548
---

## このライブラリでできること

`LiChaoTree<T,inf>` は、直線 $y=a_ix+b_i$ を追加しながら、指定した $x$ における最小値 $\min_i(a_ix+b_i)$ を求めます。一次式の最小値を繰り返し使う動的計画法などで役立ちます。有効な $x$ の範囲を限定した線分の追加にも対応します。

この実装では、問い合わせる $x$ 座標を最初にすべて登録します。その個数を $N$ とすると、直線の追加と最小値の取得は $O(\log N)$、区間を限定した追加は $O(\log^2 N)$ 時間です。

## 使い方

まず問い合わせ予定の座標を配列で渡します。`add_line(a,b)` は全登録座標で有効な直線、`add_segment(a,b,xl,xr)` は $xl\le x<xr$ だけで有効な直線を追加します。

例では $y=2x+3$ と、$[2,6)$ でだけ有効な $y=-x+8$ を追加しています。$x=5$ での値はそれぞれ $13,3$ なので、`get_min(5)` は $3$ を返します。

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/li-chao-tree.hpp"

int main() {
    LiChaoTree<long long, (1LL << 60)> tree(vector<long long>{0, 2, 5});
    tree.add_line(2, 3);
    tree.add_segment(-1, 8, 2, 6);
    assert(tree.get_min(5) == 3);
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LiChaoTree(xs)` | xs をソート・重複排除して初期化。 | O(N log N) |
| `add_line(a, b)` | 全域に y=ax+b を追加。 | O(log N) |
| `add_segment(a, b, xl, xr)` | xl<=x<xr に限り有効な y=ax+b を追加。 | O(log² N) |
| `get_min(x)` | 有効な直線の最小値。なければ inf。 | O(log N) |

## 利用条件と実装上の注意

座標配列は非空にし、問い合わせる座標は必ず構築時に登録してください。内部で座標をソート・重複除去しますが、登録していない位置での正しさは保証されません。

`inf` は有効な直線がないときの返り値でもあるため、すべての有限な答えより大きい値にします。評価式 `a*x+b` と、内部で座標を補う際の「末尾の座標+1」が型の範囲に収まることも必要です。引数なしで構築しただけのオブジェクトは利用できません。
