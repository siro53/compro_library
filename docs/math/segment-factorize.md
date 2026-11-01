---
title: 区間素因数分解
documentation_of: //math/segment-factorize.hpp
---

## 概要

`SegmentFactorize` は `[L,R)` の整数を繰り返し素因数分解するための区間篩。`K=R-L`、`S=ceil(sqrt(R))`。

空間 O(S+K log R) 上界。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegmentFactorize(L, R)` | 小さい素因数表と区間内の素因数情報を構築。 | O(S log log(R+2)+K log R) 上界 |
| `factor(n)` | n の素因数を重複込みで返す。 | O(log n) |

## 前提・注意点

`1<=L<R`、問い合わせは `L<=n<R`。返り値は map ではなく素数列。R や中間積 `large_mul²` が long long の範囲に収まること。構築時間の上界には各素因数の重複処理と各小素数の走査を含めている。

## 使用例

```cpp
#include "template/template.cpp"
#include "math/segment-factorize.hpp"

int main() {
    SegmentFactorize sieve(10, 20);
    auto f = sieve.factor(12);
    assert((f == vector<long long>{2, 2, 3}));
}
```
