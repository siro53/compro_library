---
title: ローリングハッシュモノイド
documentation_of: //data-structure/monoid/rolling_hash.hpp
---

## 概要

`MonoidRollingHash<N>` はハッシュ h と長さ len を持つ `S/value_type` を連結する。`mint=ModInt_2_61`。底と累乗表はテンプレートの N ごとに共有される。

静的累乗表に O(N) 空間。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `S(h, len)` | ハッシュと長さを設定。デフォルト構築は未初期化。 | O(1) |
| `op(a, b)` | h=a.h+b.h*base^(a.len)、len=a.len+b.len。 | 初回 O(N)、以後 O(1) |
| `e()` | 空列 (0,0)。 | O(1) |

## 前提・注意点

`N>=1`、全演算で `0<=a.len<N`。最大列長より大きい N を指定すると扱いやすい。ハッシュは衝突し得る。`RollingHash` 本体とは次数の向き・底の管理が異なるため直接比較しない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/rolling_hash.hpp"

int main() {
    using M = MonoidRollingHash<100>;
    auto x = M::op(M::S(97, 1), M::S(98, 1));
    assert(x.len == 2);
}
```
