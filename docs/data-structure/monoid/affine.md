---
title: アフィン変換モノイド
documentation_of: //data-structure/monoid/affine.hpp
---

## 概要

`MonoidAffine<T,rev=false>` は f(x)=ax+b を pair(a,b) で表す。`S/value_type` は `pair<T,T>`。

空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | rev=false は l∘r、true は r∘l。 | O(1) |
| `e()` | 恒等写像 (1,0)。 | O(1) |

## 前提・注意点

順序が重要。配列を左から適用するなら `rev=true`。T は乗算・加算を持ち、中間値がオーバーフローしないこと。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/affine.hpp"

int main() {
    using M = MonoidAffine<long long>;
    auto f = M::op({2, 1}, {3, 4});
    assert(f.first == 6 && f.second == 9);
}
```
