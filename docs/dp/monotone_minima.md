---
title: monotone_minima
documentation_of: ../../dp/monotone_minima.hpp
---

## 内容
$i_1 < i_2$ のとき、$\argmin f(i_1, *) \leq \argmin f(i_2, *)$ を満たすならば、$f(i, j)$ は **monotone** であるという。

つまり、$H × W$ の行列において、 $i$ 行目の最小値のうち、最も左に位置する要素の列番号を $g(j)$ とすると、

- $ g(1) \leq g(2) \leq ... \leq g(H)$

が成り立つ時**monotone**であるという。

このとき、各行の最左の最小値とその列番号を高速に求めることができ、これを**monotone minima**と呼ぶ。ちなみに$\argmax$でも同様に定義できて、同じように適用できる。

また、monotoneである行列の中でも、任意の部分行列でmonotoneであるようなものをtotally monotoneといい、この場合SMAWK algorithmというより高速なアルゴリズムが使えるらしい。

#### 参考資料

- [参考資料1](https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958)
- [参考資料2](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html)

## 使い方
- `monotone_minima(H, W, f, compare)` : $H × W$ のmonotoneである行列に対して、$i$ 行 $j$ 列目の要素が $f(i, j)$ である時、各行の最小値とその最左のindexを返す。

## 計算量
$O(H + W\log{H})$

計算量解析はかなり難しそうで理解を放棄... 参考資料を参照してください
直感的には分割統治なので...

## 出題例
- https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c
- https://codeforces.com/gym/102920/problem/L