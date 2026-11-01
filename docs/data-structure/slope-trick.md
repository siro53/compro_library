---
title: Slope Trick
documentation_of: //data-structure/slope-trick.hpp
---

## このライブラリでできること

`SlopeTrick<T>` は、区分線形な凸関数を、その折れ点と最小値で表すデータ構造です。関数全体を値の表として持たずに、$\max(x-a,0)$、$\max(a-x,0)$、$\lvert x-a\rvert$ の加算や、片側からの累積最小値を処理できます。絶対値の和を含む最適化や動的計画法で役立ちます。

初期状態は $f(x)=0$ です。左右のヒープ `L,R` に折れ点を持ち、`min_f` に最小値、`add_L,add_R` に折れ点の移動量を持ちます。折れ点数を $K$ とすると、折れ点を1つ加える操作は $O(\log(K+1))$ 時間です。

## 使い方

例では $f(x)=\lvert x-2\rvert+\lvert x-6\rvert$ を作ります。$2\le x\le6$ では左右への距離の和が常に $4$ なので、`get_min()` は $4$ を返します。

`get_min()` は関数を変更しませんが、`eval(x)` はヒープを取り出しながら値を計算します。後でも同じ関数を使う場合は、例のようにコピーを評価してください。`shift(a,b)` は、$a\le b$ のもとで $g(x)=\min_{x-b\le y\le x-a}f(y)$ へ置き換える操作です。単なる平行移動は `shift(a)` で表せます。

```cpp
#include "template/template.cpp"
#include "data-structure/slope-trick.hpp"

int main() {
    SlopeTrick<long long> f;
    f.add_abs(2);
    f.add_abs(6);
    assert(f.get_min() == 4);
    auto copy = f;
    assert(copy.eval(4) == 4);
}
```

## API・計算量

必要な空間は $O(K)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SlopeTrick()` | f(x)=0 を作る。 | O(1) |
| `get_min()` | 最小値。 | O(1) |
| `get_min_lr()` | (最小値, 最小区間の左端, 右端)。 | O(1) |
| `add_const(a)` | f に定数 a を加える。 | O(1) |
| `add_right(a)` | max(x-a,0) を加える。 | O(log(K+1)) |
| `add_left(a)` | max(a-x,0) を加える。 | O(log(K+1)) |
| `add_abs(a)` | 絶対値 abs(x-a) を加える。 | O(log(K+1)) |
| `clear_right()` | f(x) を min_{y<=x} f(y) にする。 | O(K log(K+1)) 上界 |
| `clear_left()` | f(x) を min_{y>=x} f(y) にする。 | O(K log(K+1)) 上界 |
| `shift(a, b)` | min_{x-b<=y<=x-a} f(y) にする。a<=b。 | O(1) |
| `shift(a)` | f(x-a) に平行移動。 | O(1) |
| `size()` | 折れ点の総数。 | O(1) |
| `swap(rhs)` | 関数の状態を交換。 | O(1) |
| `merge(rhs)` | rhs の関数を加え、rhs のヒープを消費。 | O(min(K,L) log(K+L+1))、L は rhs の折れ点数 |
| `eval(x)` | f(x) を返し、両ヒープを空にする破壊的評価。 | O(K log(K+1)) |

## 利用条件と実装上の注意

関数はこの API で表現できる範囲、すなわち整数の傾きを持つ凸な区分線形関数として扱います。座標・関数値・内部の番兵値との演算が `T` の範囲に収まるようにしてください。

`get_min_lr()` は状態を変更せず、最小値とそれを取る区間の左右端を返します。左右に折れ点がない場合は、それぞれ有限の番兵値 -inf、inf を返します。

`clear_left/right` はヒープを繰り返し pop する実装であり、定数時間ではありません。`eval` と `merge` は折れ点を消費しますが、定数項は残るため、消費されたオブジェクトが自動的に $f=0$ に戻るわけではありません。表中の $L$ は、`merge` の引数側の折れ点数です。
