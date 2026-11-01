---
title: NTT による畳み込み
documentation_of: //math/convolution/ntt.hpp
---

## このライブラリでできること

`ntt` 名前空間は、素数を法とする数論変換（NTT）と畳み込みを提供します。複素数の代わりに有限体上の1の冪根を用いることで、浮動小数点の丸め誤差を伴わずに多項式の積を計算できます。

長さ n,m の列の畳み込みは $c_k=\sum_{i+j=k}a_i b_j$ です。係数はすべて modint の法 p で計算されます。

## 使い方

コンパイル時に法を取得できる modint の列を `convolution` に渡します。例では $(1+2x)(3+4x)=3+10x+8x^2$ の係数が得られます。

```cpp
#include <cassert>
#include <vector>
#include "math/convolution/ntt.hpp"

int main() {
    using mint = ModInt<998244353>;
    auto c = ntt::convolution(std::vector<mint>{1, 2}, std::vector<mint>{3, 4});
    assert(c == (std::vector<mint>{3, 10, 8}));
    assert(ntt::convolution(std::vector<mint>{}, c).empty());
}
```

正変換は $A_k=\sum_{j=0}^{N-1}a_j\omega^{jk}$ を添字 k の順に格納します。ここで N は変換長、$\omega=g^{(p-1)/N}$、g は primitive_root が求める原始根です。逆変換は逆根を用い、最後に N の逆元を掛けます。

## API・計算量

L を n+m-1 以上の最小の2冪とします。畳み込みの作業配列は $O(L)$、mint の型ごとに保持する根の表は $O(\log p)$ 空間です。正逆変換は配列をその場で更新し、根の表以外の追加空間は $O(1)$ です。modint の基本演算を定数時間とします。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `exp_limit(int mod)` | mod-1 の末尾の0 bit数。mod>1。 | O(1) |
| `ntt_info<mint>()` | 根 root、逆根 iroot、指数上限 limit を用意。 | 原始根取得後 O(log p) |
| `revbit(uint64_t mask)` | 有効 bit幅で反転。0には0。 | O(1) |
| `revbit(uint64_t mask, int bitlen)` | 下位 bitlen bitを反転。bitlen=0なら0。 | O(1) |
| `ntt(std::vector<mint>& a)` | 正変換で a を上書き。 | O(N log(N+1))、初回は根の構築を加算 |
| `intt(std::vector<mint>& a)` | 正規化した逆変換で a を上書き。 | O(N log(N+1)+log p)、初回は根の構築を加算 |
| `convolution(std::vector<mint> a, std::vector<mint> b)` | 畳み込み。片方でも空なら空。 | 非空時 O(L log(L+1)+log p)、入力コピー別 |

## 利用条件と実装上の注意

法 p は素数で、mint は定数式の get_mod() と四則演算・pow・inv を備える必要があります。原始根の計算コストは `primitive-root.hpp` に従います。既定のテンプレート引数としてコンパイル時に原始根を求めます。

直接変換する長さ N は正の2冪で、$N\mid(p-1)$ が必要です。畳み込みでも内部の長さ L がこの条件を満たす必要があり、$p=998244353$ なら $2^{23}$ までです。条件を満たさない長さは assert で検出します。

revbit の bitlen は0以上64以下です。1引数版は入力自身の有効幅を使うので、配列添字の並べ替えには固定幅を渡す2引数版を使います。空の畳み込みでも値渡しの入力コピーには O(n+m) 時間・空間がかかります。
