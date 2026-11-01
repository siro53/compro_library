---
title: Range BIT
documentation_of: //data-structure/range-BIT.hpp
---

## このライブラリでできること

`RangeBIT<T>` は、区間内の全要素への加算と区間和の取得を扱います。「区間に同じ数を加える」という更新が多いときに、点加算用の BIT よりも適しています。長さ $N$ の配列に対して、どちらの操作も $O(\log N)$ 時間です。

内部では差分列を2本の BIT に分けて保持します。区間への加算を両端の差分更新に変換し、先頭 $r$ 個の和を「定数項と $r$ に比例する項」の和として求める仕組みです。

## 使い方

サイズを指定して初期化し、`add(l,r,x)` で $l\le i<r$ の各 $A_i$ に $x$ を加えます。`sum(l,r)` は同じ半開区間の和を返します。例では $A_1,A_2,A_3$ に $2$ ずつ加えるので、全体の和は $6$ になります。

```cpp
#include "template/template.cpp"
#include "data-structure/range-BIT.hpp"

int main() {
    RangeBIT<long long> bit(5);
    bit.add(1, 4, 2);
    assert(bit.sum(0, 5) == 6);
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RangeBIT(N)` | N 要素を 0 で初期化。 | O(N) |
| `add(l, r, val)` | [l, r) の全要素に加算。 | O(log N) |
| `add(pos, val)` | 1 要素に加算。 | O(log N) |
| `sum(r)` | [0, r) の和。 | O(log N) |
| `sum(l, r)` | [l, r) の和。 | O(log N) |

## 利用条件と実装上の注意

添字は $0$ から始め、$0\le l\le r\le N$ としてください。`add(p,x)` は1点だけへの加算、`sum(r)` は先頭 $r$ 個の和です。

`T` には加減算と整数との乗算が必要です。実装では値に添字を掛けるため、各要素だけでなく中間積と区間和も型の範囲内に収めてください。引数なしで構築したオブジェクトは、そのままでは使えません。
