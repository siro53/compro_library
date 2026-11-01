---
title: 二次元累積和
documentation_of: //data-structure/sum2D.hpp
---

## このライブラリでできること

`sum2D<T>` は、値が変化しない盤面に対して長方形の総和を何度も求めるためのクラスです。高さ $H$、幅 $W$ の盤面を $O(HW)$ 時間で前処理すると、1回の長方形和を $O(1)$ 時間で求められます。

左上からの累積和を $P(i,j)=\sum_{0\le x<i,\,0\le y<j}A_{x,y}$ とすると、求める長方形の和は4つの値の足し引きで表せます。たとえば行 $[a,b)$、列 $[c,d)$ の和は $P(b,d)-P(a,d)-P(b,c)+P(a,c)$ です。

## 使い方

まず `add(row,column,x)` で各マスの値を設定し、`build()` を一度呼びます。その後は `get_sum(row_l,row_r,column_l,column_r)` で問い合わせます。引数は「行の両端、列の両端」の順であり、対角の2点を交互に渡す形ではありません。例では値 $7$ を置いたマスを含む長方形を問い合わせています。

```cpp
#include "template/template.cpp"
#include "data-structure/sum2D.hpp"

int main() {
    sum2D<long long> sum(3, 4);
    sum.add(1, 2, 7);
    sum.build();
    assert(sum.get_sum(0, 2, 1, 3) == 7);
}
```

## API・計算量

必要な空間は $O(HW)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `sum2D(H, W)` | H×W の盤面を 0 で初期化。 | O(HW) |
| `add(row, column, val)` | 1 セルに加算。 | O(1) |
| `build()` | 二次元累積和を構築。 | O(HW) |
| `get_sum(row_l, row_r, column_l, column_r)` | 行 [row_l,row_r)、列 [column_l,column_r) の和。 | O(1) |

## 利用条件と実装上の注意

添字は0始まりです。`add` には盤面内の位置を、`get_sum` には盤面内に収まる半開区間を指定してください。空の長方形の和は $0$ です。

すべての加算を終えてから `build()` を一度だけ呼びます。構築後の追加や再構築には対応していません。また、累積和の中間値も `T` に収まるようにしてください。
