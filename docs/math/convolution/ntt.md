---
title: NTT による畳み込み
documentation_of: //math/convolution/ntt.hpp
---

## 概要

名前空間 `ntt` は素数法の数論変換と畳み込みを意図する。`ntt_info<mint>` は 2 冪根 root/iroot と対応指数の上限 limit を持つ。

意図上の畳み込み空間 O(L)、根の表 O(log mod)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `exp_limit(mod)` | mod-1 の末尾の 0 bit 数。 | O(1) |
| `ntt_info<mint>()` | 根と逆根を前計算。 | O(log mod) |
| `revbit(mask)` | 有効 bit 幅での bit 反転。0 は未定義動作。 | O(1) |
| `ntt(a), intt(a)` | 正変換・正規化した逆変換で a を上書きする意図。 | 意図上 O(N log N) |
| `convolution(a,b)` | a,b の畳み込みを返す意図。 | 意図上 O(L log L)、L は結果長を覆う 2 冪 |

## 前提・注意点

現実装の revbit は配列長の bit 幅を受け取らず、添字自体の幅で反転する。また変換中に `revbit(0)` が呼ばれ `__builtin_clzll(0)` が未定義になる。修正するまでは正しい畳み込みを保証しない。

本来の利用条件は、mint がコンパイル時に取得できる素数法を持ち、変換長 N が正の 2 冪で N が mod-1 を割り切ること。998244353 なら最大 2^23。両入力は非空を想定。

## 使用例

以下は API の呼び出し形を示す例です。上記の実装上の問題があるため、そのままの利用は推奨しません。

```cpp
#include "template/template.cpp"
#include "math/convolution/ntt.hpp"

int main() {
    using mint = ModInt<998244353>;
    auto c = ntt::convolution(vector<mint>{1, 2}, vector<mint>{3, 4});
}
```
