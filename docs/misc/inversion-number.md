---
title: 転倒数
documentation_of: //misc/inversion-number.hpp
---

## 概要

配列の i<j かつ v[i]>v[j] となる組の数を BIT で求める。N は配列長。

追加空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `inversion_number<T>(v)` | 転倒数を T 型で返す。 | O(N log N) |

## 前提・注意点

入力型は vector<int>、値は `[0,N)`。任意の値列は先に座標圧縮する。等しい値は転倒に数えない。最大 N(N-1)/2 が入る T を選ぶ。空配列は 0。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/inversion-number.hpp"

int main() {
    auto count = inversion_number<long long>(vector<int>{2, 0, 1});
    assert(count == 2);
}
```
