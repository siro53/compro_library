---
title: 固定法 modint
documentation_of: //modint/modint.hpp
---

## 概要

`ModInt<998244353>` は整数を法 m の剰余として保持し、通常の算術演算子で計算する。

各値の空間 O(1)。法の bit 幅で固定長整数演算を O(1) とする。

## API・計算量

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

## 前提・注意点

除算・inv は値と法 m が互いに素な場合のみ。入力は long long の最小値を避ける（負数の正規化で符号反転するため）。比較は正規化後の値の一致。演算子は同じ型同士で使い、整数はコンストラクタで変換できる。

テンプレート引数の法は正の int。inv は可逆性を検査しない。素数法であっても 0 の除算・逆元は不可。

pow の指数は非負。固定法版と 2^61-1 版は unsigned long long、動的版は long long を受け取る。

## 使用例

```cpp
#include "template/template.cpp"
#include "modint/modint.hpp"

int main() {
    using mint = ModInt<998244353>;
    mint a = 3, b = 5;
    assert((a * b).val() == 15);
    assert((a / a).val() == 1);
    assert(a.pow(3).val() == 27);
}
```
