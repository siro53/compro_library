---
title: 転倒数
documentation_of: //misc/inversion-number.hpp
---

## このライブラリでできること

`inversion_number<T>(v)` は、配列で順序が逆転している組の数を求めます。長さを $N$ とすると、転倒数は $\#\{(i,j)\mid0\le i<j<N,\ v_i>v_j\}$ です。同じ値の組は数えません。

左から値を読み、すでに見た値のうち現在値より大きいものの個数をBITで数えます。全体で $O(N\log N)$ 時間、$O(N)$ 空間です。

## 使い方

入力は `vector<int>`、テンプレート引数は答えを格納する型です。例の $[2,0,1]$ では、最初の $2$ と後ろの $0,1$ の2組が転倒しているので答えは $2$ です。

値が負数や大きな整数の場合は、先に大小関係を保つ座標圧縮をしてから渡してください。

```cpp
#include "template/template.cpp"
#include "misc/inversion-number.hpp"

int main() {
    auto count = inversion_number<long long>(vector<int>{2, 0, 1});
    assert(count == 2);
}
```

## API・計算量

入力とは別に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `inversion_number<T>(v)` | 転倒数を T 型で返す。 | O(N log N) |

## 利用条件と実装上の注意

入力値はすべて $[0,N)$ に収める必要があります。値をそのままBITの添字として使うためです。答えは最大 $N(N-1)/2$ になるので、通常は long long など十分な幅の型を選びます。空配列の答えは0です。
