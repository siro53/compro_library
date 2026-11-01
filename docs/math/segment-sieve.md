---
title: 区間素数判定
documentation_of: //math/segment-sieve.hpp
---

## このライブラリでできること

`SegmentSieve` は、連続区間 $[L,R)$ にある数が素数かどうかをまとめて調べます。およそ $\sqrt R$ 以下の素数を小さい篩で列挙し、それぞれの倍数を対象区間から除きます。0と1は素数ではなく、素数自身は除きません。

## 使い方

`SegmentSieve(L,R)` で判定表を構築し、`sieve[n]` で判定します。例では区間 $[10,20)$ に含まれる13は素数、15は合成数なので、それぞれ真と偽になります。

```cpp
#include <cassert>
#include "math/segment-sieve.hpp"

int main() {
    SegmentSieve sieve(10, 20);
    assert(sieve[13]);
    assert(!sieve[15]);
    SegmentSieve small(0, 3);
    assert(!small[0] && !small[1] && small[2]);
}
```

## API・計算量

区間幅を $K=R-L$、小さい篩の長さを $S=\lfloor\sqrt R\rfloor+1$ とします。空間は $O(S+K)$ bitです。素数ごとの区間内の倍数を消す処理に加え、小さい篩全体も走査します。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegmentSieve(long long L, long long R)` | 区間の素数判定表を構築。 | O((S+K) log log(R+3)) 上界 |
| `bool operator[](long long k) const` | k が素数なら true。 | O(1) |

## 利用条件と実装上の注意

$0\le L\le R$、問い合わせは $L\le k<R$ に限ります。空区間も構築できますが、問い合わせられる数はありません。入力値は long long に収め、小さい篩と区間の判定表をメモリに確保できる範囲で使ってください。

構築後の区間変更や判定表の更新には対応しません。浮動小数点による平方根は表の確保サイズに使い、素数の走査上限は整数除算でも確認しています。
