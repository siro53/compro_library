---
title: 値ごとの和・個数管理
documentation_of: //data-structure/utils/sum_count_manager.hpp
---

## 概要

`SumCountManager<T>` は候補値を `Compress<T>` で圧縮し、`seg` に値ごとの和と個数を保持する補助構造体。`K` は候補数。

意図上の空間 O(K)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SumCountManager(xs)` | 候補を圧縮し、空の集計木を作る。 | O(K log K) |
| `add(val)` | 登録済みの値を 1 個追加する意図。現状は型名 S が未定義。 | 意図上 O(log K) |
| `get(val)` | 候補配列の lower_bound の位置。 | O(log K) |

## 前提・注意点

現状 `add` 内の `S` が未定義なので、そのままではコンパイルできない。`vector` も非修飾なのでテンプレートの先行 include が必要。修正後は候補に含まれる値のみ add する。`get` は値の個数ではなく圧縮位置を返す。`comp` は圧縮表、`seg` は `Segtree<MonoidSumCount<T,int>>`。

## 使用例

以下は API の呼び出し形を示す例です。上記の実装上の問題があるため、そのままの利用は推奨しません。

```cpp
#include "template/template.cpp"
#include "data-structure/utils/sum_count_manager.hpp"

int main() {
    SumCountManager<long long> manager(vector<long long>{10, 20});
    manager.add(10);
    auto x = manager.seg.prod(0, 2);
    assert(x.sum == 10 && x.cnt == 1);
}
```
