---
title: 動的法 modint
documentation_of: //modint/dynamic-modint.hpp
---

## このライブラリでできること

`DynamicModInt` は、整数を法 $m$ の剰余として扱う型です。加減乗算のたびに `% m` を書く代わりに、通常の算術演算子で計算できます。内部の値は原則として $0$ 以上 $m$ 未満に正規化され、`val()` で通常の整数として取り出せます。

剰余上の除算 $a/b$ は、$bc\equiv1\pmod m$ を満たす逆元 $c$ を求めて $ac$ を計算する操作です。逆元が存在する条件は $\gcd(b,m)=1$ であり、通常の整数除算とは意味が異なります。

## 使い方

最初に `set_mod(m)` を呼ぶと、その後に作る値が法 $m$ で計算されます。入力として法が与えられるなど、コンパイル時には法が決まらない問題で使います。例では法を設定した後、通常の modint と同じ形で演算しています。

法はオブジェクトごとではなく、すべての `DynamicModInt` で共有されます。別の法を設定しても既存の値は変換されないため、値が残っている間に法を変えないでください。

```cpp
#include "template/template.cpp"
#include "modint/dynamic-modint.hpp"

int main() {
    using mint = DynamicModInt;
    mint::set_mod(998244353);
    mint a = 3, b = 5;
    assert((a * b).val() == 15);
    assert((a / a).val() == 1);
    assert(a.pow(3).val() == 27);
}
```

## API・計算量

各値が使う空間は $O(1)$ です。法のbit幅に収まる固定長整数の演算を、定数時間として評価しています。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `コンストラクタ(), コンストラクタ(long long y)` | 0 または y mod m を保持。 | O(1) |
| `val(), get_mod()` | 正規化された値・法（get_mod は static）。 | O(1) |
| `operator+, -, *, +=, -=, *=` | 剰余の加減乗算。 | O(1) |
| `単項 operator-` | 加法逆元（動的版は注意点参照）。 | O(1) |
| `operator/, /=, inv()` | 除算・拡張 Euclid 法による逆元。 | O(log m) |
| `pow(n)` | n 乗。 | O(log(n+1)) |
| `operator==, !=` | 値の一致・不一致。 | O(1) |
| `operator<<, >>` | 正規化された値の出力・long long の入力。 | 数字の桁数に比例 |
| `set_mod(m)` | 全インスタンス共通の法を設定。 | O(1) |

## 利用条件と実装上の注意

法は $2\le m<2^{31}$ の範囲で使用してください。乗算には `BarrettReduction`、逆元には int を使った拡張Euclid法を利用します。除算は除数と法が互いに素なときだけ可能です。

現実装の単項マイナス `-x` は、内部の unsigned int のまま符号反転するため、意図した加法逆元にならない場合があります。代わりに `DynamicModInt(0)-x` を使ってください。

`pow` は非負の long long 指数を受け取ります。コンストラクタには long long の最小値を渡さず、最初の値の構築前に必ず `set_mod` を実行してください。
