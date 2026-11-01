---
title: Li Chao Tree
documentation_of: //data-structure/segtree/li-chao-tree.hpp
link: https://smijake3.hatenablog.com/entry/2018/06/16/144548
---

## このライブラリでできること

`LiChaoTree<T, inf>` は、直線を追加しながら、あらかじめ登録した座標での最小値を求めます。区間内だけで有効な直線（線分）も追加できます。問い合わせに使う座標を事前に集められる場合に利用します。

## 使い方

座標配列で初期化し、`add_line(a, b)` で直線 $y=ax+b$ を追加します。`add_segment(a, b, xl, xr)` は半開区間 $[xl,xr)$ にだけ直線を追加します。

次の例では、$x=0$ で線分の値 $-4$ が最小になります。$x=3$ は線分の右端なので含まれず、直線の値 $9$ が返ります。

```cpp
#include <cassert>
#include <vector>
#include "data-structure/segtree/li-chao-tree.hpp"

int main() {
    using Tree = LiChaoTree<long long, (1LL << 60)>;
    Tree tree(std::vector<long long>{-2, 0, 3});
    tree.add_line(2, 3);
    tree.add_segment(-1, -4, 0, 3);
    assert(tree.get_min(0) == -4);
    assert(tree.get_min(3) == 9);

    Tree empty(std::vector<long long>{});
    empty.add_line(1, 2); // 登録座標がないので何もしません。
}
```

## API・計算量

入力配列の要素数を $M$、重複を除いた登録座標数を $N$ とします。以下は型 `T` の演算・比較を定数時間とした計算量です。構築時に配列をコピーし、内部の座標とノードに $O(N)$ の要素を保持します。入力配列の重複除去では確保済み容量が縮まらないため、実際の確保領域は $O(M+1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LiChaoTree()` | 登録座標がない空の木を構築します。 | $O(1)$ |
| `explicit LiChaoTree(const std::vector<T>& x)` | 座標をコピーし、ソート・重複除去して構築します。空配列も渡せます。 | $O(1+M\log(M+1))$ |
| `void add_line(T a, T b)` | 全登録座標に対して $y=ax+b$ を追加します。空の木では何もしません。 | $O(\log(N+1))$、空なら $O(1)$ |
| `void add_segment(T a, T b, T x_l, T x_r)` | $x_l\le x<x_r$ の登録座標に直線を追加します。空の木や空区間では何もしません。 | $O(\log^2(N+1))$、空の木なら $O(1)$ |
| `T get_min(T x)` | 登録座標 $x$ で有効な直線の最小値を返します。有効な直線がなければ `inf` を返します。 | $O(\log(N+1))$ |

## 利用条件と実装上の注意

`get_min` は構築時に登録した座標に対してのみ呼んでください。空の木では呼べません。空の木への追加は保存されず、後から座標を追加する操作もありません。新しい座標集合を使う場合は別の木を構築してください。

`x_l <= x_r` を満たす区間を渡してください。区間の端点そのものは登録済みでなくても構いません。`T` は比較・加減算・乗算ができる数値型を想定します。`inf` は有効な答えより十分大きく設定し、評価式 `a*x+b` が型の範囲を超えないようにしてください。内部では座標数を2の冪にそろえるために最大座標へ1ずつ加えて補うので、補った座標と、その位置での直線の評価値も型の範囲に収まる必要があります。
