---
title: FFT による畳み込み
documentation_of: //math/convolution/fft.hpp
---

## 概要

名前空間 `fft` に浮動小数点 FFT と畳み込みを提供する。`Complex<D>` は実部 x、虚部 y を持つ専用の複素数型。

畳み込みの追加空間 O(L)、変換自体は O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Complex<D>(), Complex<D>(x,y)` | 0 または指定した複素数を作る。 | O(1) |
| `Complex の単項 -, +, -, *, / と複合代入` | 複素数演算。 | O(1) |
| `omega<D>(k,n)` | exp(2πik/n)。 | O(1) |
| `revbit(mask,bitlen)` | 下位 bitlen bit の反転。 | O(bitlen) |
| `fft(a,bitlen)` | 配列 a を正変換して上書き。 | O(N log N) |
| `ifft(a,bitlen)` | 逆変換して N で割り、a を上書き。 | O(N log N) |
| `convolution(a,b)` | c[k]=Σ a[i]b[k-i] を返す。 | O(L log L)、L は結果長以上の最小の 2 冪 |

## 前提・注意点

D は double または long double。直接変換する場合は `N=2^bitlen`、N>=1。畳み込みの入力は両方非空。結果長は a.size()+b.size()-1。丸め誤差があるため、整数への復元は必要な精度を検討して丸める。`PI<D>` は円周率。複素数除算の除数は非零。

## 使用例

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
