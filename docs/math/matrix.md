---
title: 行列
documentation_of: //math/matrix.hpp
---

## 概要

`Matrix<T>` は動的な密行列で、加減算・積・累乗を提供する。

保持空間 O(nm)、積の結果に O(nm)、正方行列の累乗に O(n²) の追加空間。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Matrix(n), Matrix(n,m)` | n×n または n×m の零行列。 | O(nm) |
| `height(), width()` | 行数・列数。 | O(1) |
| `operator[](i)` | i 行への参照。const 版もある。 | O(1) |
| `I(n)` | n×n の単位行列を返す static メソッド。 | O(n²) |
| `operator+=, -=, +, -` | 同じ形の行列を成分ごとに加減算。 | O(nm) |
| `operator*=, *` | n×k と k×m の行列積。 | O(nkm) |
| `pow(k)` | 正方行列の k 乗。 | O(n³ log(k+1))（k=0 は O(n²)） |

## 前提・注意点

T は 0,1 の構築と加減乗算に対応すること。`pow` は k>=0 かつ正方行列。`width()` は 0 行の行列では利用不可。デフォルト構築後も同様。乗算・累乗の中間値がオーバーフローしないよう modint 等を使う。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/matrix.hpp"

int main() {
    Matrix<long long> a(2);
    a[0][0] = a[0][1] = a[1][0] = 1;
    auto b = a.pow(5);
    assert(b[0][1] == 5);
}
```
