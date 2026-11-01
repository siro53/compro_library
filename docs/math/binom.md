---
title: 二項係数
documentation_of: //math/binom.hpp
---

## 概要

`Binomial<mint>` は階乗・逆階乗を保持して組合せを計算する。必要に応じて配列を倍増する。`K` は現在の表サイズ、`I` は mint の逆元計算コスト。

空間 O(K)。mint の基本演算を O(1) とする。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Binomial(MAX=1)` | 0..MAX-1 の階乗・逆階乗を構築。 | O(MAX+I) |
| `extend()` | 表の長さを倍にする。 | O(K+I) |
| `fac(n), fac_inv(n)` | n! とその逆元。n<0 は 0。 | 表内 O(1)、拡張時 O(n+I log(n+2)) 上界 |
| `inv(n)` | 正の n の逆元。 | 表内 O(1)、拡張コスト別 |
| `binom(n, k)` | nCk。不正な n,k は 0。 | 表内 O(1)、拡張コスト別 |
| `perm(n, k)` | nPk。不正な n,k は 0。 | 表内 O(1)、拡張コスト別 |
| `hom(n, k)` | n 種から k 個選ぶ重複組合せ。k=0 は 1。 | 表内 O(1)、拡張コスト別 |
| `binom_naive(n, k)` | long long の n,k に積の公式を使う。 | O(min(k,n-k)) + 表拡張コスト |

## 前提・注意点

MAX>=1。表に含まれる全階乗が可逆であること。素数法 p なら最大添字を p 未満にする（自動倍増で必要添字より先まで確保する点にも注意）。`inv(0)` は不可。`inv(n<0)` は現状 -mint(-n) を返し、逆元にならないため使わない。`binom_naive` のループ変数は int なので min(k,n-k) が int の範囲に収まること。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/binom.hpp"
#include "modint/modint.hpp"

int main() {
    using mint = ModInt<998244353>;
    Binomial<mint> comb(100);
    assert(comb.binom(5, 2).val() == 10);
    assert(comb.hom(3, 2).val() == 6);
}
```
