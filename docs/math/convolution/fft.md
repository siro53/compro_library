---
title: FFT による畳み込み
documentation_of: //math/convolution/fft.hpp
---

## このライブラリでできること

`fft::convolution(a,b)` は、2つの数列の畳み込み $c_k=\sum_{i+j=k}a_i b_j$ を計算します。係数列を多項式とみなすと、その積の係数を求めることと同じです。長さ $n,m$ の列の結果は長さ $n+m-1$ になります。

FFTでは、係数表現を複数の点での値へ変換し、各点で積を取り、逆変換で係数へ戻します。結果長以上の最小の2冪を $L$ とすると、愚直な $O(nm)$ 時間の計算を $O(L\log L)$ 時間にできます。

## 使い方

通常は `convolution` だけを呼べば、長さの調整と変換・逆変換まで行われます。例は $(1+2x)(3+4x)=3+10x+8x^2$ を計算しており、浮動小数点の誤差を考慮して近い値になったことを確認しています。

変換を直接使う場合は `fft::Complex<D>` の配列を用意します。`x,y` が実部・虚部、`omega(k,n)` は $\exp(2\pi ik/n)$、`PI<D>` は円周率です。

```cpp
#include "template/template.cpp"
#include "math/convolution/fft.hpp"

int main() {
    auto c = fft::convolution(vector<double>{1, 2}, vector<double>{3, 4});
    assert(abs(c[0] - 3) < 1e-8);
    assert(abs(c[1] - 10) < 1e-8);
    assert(abs(c[2] - 8) < 1e-8);
}
```

## API・計算量

畳み込みには $O(L)$ の追加空間を使います。正変換・逆変換だけなら配列をその場で更新し、追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Complex<D>(), Complex<D>(x,y)` | 0 または指定した複素数を作る。 | O(1) |
| `Complex の単項 -, +, -, *, / と複合代入` | 複素数演算。 | O(1) |
| `omega<D>(k,n)` | exp(2πik/n)。 | O(1) |
| `revbit(mask,bitlen)` | 下位 bitlen bit の反転。 | O(bitlen) |
| `fft(a,bitlen)` | 配列 a を正変換して上書き。 | O(N log N) |
| `ifft(a,bitlen)` | 逆変換して N で割り、a を上書き。 | O(N log N) |
| `convolution(a,b)` | c[k]=Σ a[i]b[k-i] を返す。 | O(L log L)、L は結果長以上の最小の 2 冪 |

## 利用条件と実装上の注意

係数の型 `D` は double または long double を使ってください。畳み込みの両入力は非空とします。直接 `fft/ifft` を呼ぶ場合、長さ $N$ は正の2冪で、引数 `bitlen` は $N=2^{\mathrm{bitlen}}$ を満たす必要があります。逆変換には $N$ による正規化が含まれます。

FFTは浮動小数点計算です。整数の結果を得たい場合も、値の大きさや列長による誤差を見積もったうえで丸めてください。専用複素数型の除算では、除数を0にしてはいけません。
