---
title: Z algorithm
documentation_of: //string/z-algo.hpp
---

## 概要

文字列 s の各位置 i について、s と s[i:] の最長共通接頭辞の長さを計算する。N は文字列長。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `z_algo(s)` | 長さ N の vector<int>。z[0]=N。 | O(N) |

## 前提・注意点

空文字列は z[0] の範囲外アクセスになるため不可。文字はバイト単位で比較する。

## 使用例

```cpp
#include "template/template.cpp"
#include "string/z-algo.hpp"

int main() {
    auto z = z_algo("ababa");
    assert((z == vector<int>{5, 0, 3, 0, 1}));
}
```
