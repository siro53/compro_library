---
title: 座標圧縮
documentation_of: //misc/compress.hpp
---

## 概要

`Compress<T>` は値をソートして重複を除き、大小関係を保つ添字に変換する。N は追加した値の数、K は異なる値の数。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Compress(), Compress(v)` | 空、または v を圧縮して構築。 | O(1) / O(N log N) |
| `push_back(val)` | 未構築の候補を追加。 | 償却 O(1) |
| `build()` | ソートして重複を除く。 | O(N log N) |
| `get(val)` | val 以上の最初の位置。なければ K。 | O(log K) |
| `operator[](i)` | 圧縮前の値。 | O(1) |
| `size()` | 現在の格納数。build 後は異なる値の数。 | O(1) |

## 前提・注意点

push_back 後は再度 build してから検索する。再構築すると添字が変わる。get は未登録値にも lower_bound の位置を返すので、所属判定には `i<size() && c[i]==val` を併用する。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/compress.hpp"

int main() {
    Compress<int> c(vector<int>{30, 10, 30, 20});
    assert(c.get(20) == 1 && c[1] == 20);
    assert(c.get(25) == 2);
}
```
