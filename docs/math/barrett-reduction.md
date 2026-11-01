---
title: Barrett Reduction
documentation_of: //math/barrett-reduction.hpp
---

## このライブラリでできること

`BarrettReduction` は、同じ法 $m$ で何度も剰余を計算するためのクラスです。$m$ の逆数に相当する値を整数として前計算し、乗算とシフトで商を近似してから誤差を補正します。法が固定された剰余乗算の内部処理として使えます。

APIは、剰余乗算 `mul`、剰余 `rem`、商 `quo`、商と剰余の組 `quorem` に分かれています。いずれも固定長の整数演算を定数時間とした評価では $O(1)$ です。

## 使い方

まず `BarrettReduction br(m)` として法を指定します。例では $m=7$ なので、`mul(3,5)` は $15\bmod7=1$ を返し、`quorem(23)` は $23=3\cdot7+2$ に対応する組 $(3,2)$ を返します。

入力型が広いことと、その全範囲で補正が正しく動くことは別です。以下の利用範囲に収めて使ってください。

```cpp
#include "template/template.cpp"
#include "math/barrett-reduction.hpp"

int main() {
    BarrettReduction br(7);
    assert(br.mul(3, 5) == 1);
    auto [q, r] = br.quorem(23);
    assert(q == 3 && r == 2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BarrettReduction(m=1)` | 法と近似逆数を保持。 | O(1) |
| `mul(a, b)` | a*b mod m。 | O(1) |
| `rem(a)` | a mod m。 | O(1) |
| `quo(a)` | unsigned int の商 a/m。 | O(1) |
| `quorem(a)` | unsigned int の (商,剰余)。 | O(1) |

## 利用条件と実装上の注意

この実装の利用範囲は $2\le m<2^{31}$ とします。`mul(a,b)` は $0\le a,b<m$、`rem(a)` は $0\le a<m^2$ の範囲で利用してください。`quo/quorem` の入力型は unsigned int です。

$m=0$ は逆数の前計算で除算に失敗します。$m=1$ も近似逆数が0に巻き戻るため、商・剰余のAPIは一般に正しくありません。デフォルトコンストラクタは法1を設定するので、実際の計算前に有効な法で作り直してください。128 bit整数拡張が必要です。
