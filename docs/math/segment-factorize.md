---
title: 区間素因数分解
documentation_of: //math/segment-factorize.hpp
---

## このライブラリでできること

`SegmentFactorize` は、正整数の連続区間 $[L,R)$ にある値を何度も素因数分解するための前処理です。$R$ が大きくても区間幅が狭ければ、$R$ 以下をすべて保存する篩より小さな領域で扱えます。

幅を $K=R-L$、$S=\lceil\sqrt R\rceil$ とします。小さい素因数の表と、区間内の各数から取り出した素因数を保持します。重複する素因数の処理まで含めた前処理の上界は $O(S\log\log(R+2)+K\log R)$、1つの値の分解結果を取り出す時間は $O(\log n)$ です。

## 使い方

対象区間を指定して構築し、`factor(n)` で素因数の列を取得します。例では区間 $[10,20)$ を準備し、$12$ を $[2,2,3]$ に分解しています。`prime_factor` の map とは異なり、同じ素因数は指数の回数だけ列に現れます。

```cpp
#include "template/template.cpp"
#include "math/segment-factorize.hpp"

int main() {
    SegmentFactorize sieve(10, 20);
    auto f = sieve.factor(12);
    assert((f == vector<long long>{2, 2, 3}));
}
```

## API・計算量

小さい数の表と区間内の素因数列を合わせた空間の上界は $O(S+K\log R)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegmentFactorize(L, R)` | 小さい素因数表と区間内の素因数情報を構築。 | O(S log log(R+2)+K log R) 上界 |
| `factor(n)` | n の素因数を重複込みで返す。 | O(log n) |

## 利用条件と実装上の注意

$1\le L<R$ とし、問い合わせは $L\le n<R$ に限ってください。初期化に必要な区間幅と $\sqrt R$ の領域がメモリに収まる必要があります。

内部の `large_mul*large_mul` などの積も long long で計算します。引数だけでなく、その中間積が型の範囲に収まることを確認してください。表の空間量は保存する素因数の個数まで含めた上界です。
