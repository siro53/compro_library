---
title: ランレングス圧縮
documentation_of: //misc/rle.hpp
---

## 概要

連続する等しい値を (値,連続数) に圧縮する。N は入力長。

返り値の空間 O(N)（実際は run 数）。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `runlength_encoding(vector<T>)` | vector<pair<T,int>> を返す。 | O(N) |
| `runlength_encoding(string)` | vector<pair<char,int>> を返す。 | O(N) |

## 前提・注意点

入力は非空。空の vector は v[0] を参照し、空文字列も空の結果にはならない。連続数は int に収める。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/rle.hpp"

int main() {
    auto runs = runlength_encoding(string("aaabbc"));
    assert(runs.size() == 3);
    assert(runs[0].first == 'a' && runs[0].second == 3);
}
```
