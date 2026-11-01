---
title: Slope Trick
documentation_of: //data-structure/slope-trick.hpp
---

## 概要

`SlopeTrick<T>` は整数傾斜を持つ区分線形凸関数を保持する。初期値は f(x)=0。`L,R` は折れ点のヒープ、`add_L,add_R` は移動量、`min_f` は最小値。`K` は折れ点数。

空間 O(K)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SlopeTrick()` | f(x)=0 を作る。 | O(1) |
| `get_min()` | 最小値。 | O(1) |
| `get_min_lr()` | (最小値, 最小区間の左端, 右端) を意図するが現状はコンパイル不可。 | 意図上 O(1) |
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

## 前提・注意点

`get_min_lr()` は const メソッドから非 const の `top_L/top_R` を呼ぶため使用時にコンパイルエラーとなる。`eval` は非修飾 `max` を使うため、本例のようにテンプレートを先に include する。`eval/merge` 後も定数項は残るため、消費されたオブジェクトが f=0 に戻るわけではない。`clear_left/right` は繰り返し pop する実装で O(1) ではない。数値演算と内部の `±inf` がオーバーフローしない範囲で使う。

## 使用例

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
