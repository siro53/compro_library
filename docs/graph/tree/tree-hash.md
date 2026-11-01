---
title: 木ハッシュ
documentation_of: //graph/tree/tree-hash.hpp
link: https://snuke.hatenablog.com/entry/2017/02/03/054210
---

## 概要

`TreeHash<Cost=int>` は根なし木の形をランダム化ハッシュで表す。直径の中心を根として再帰集約する。`N` は頂点数。

各木 O(N) 空間、再帰スタック O(N)。静的乱数表はコンストラクタごとに N 個追記され、構築した全オブジェクトのサイズ総和だけ増える。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `TreeHash(N)` | N 頂点と深さごとの乱数を用意。 | O(N) |
| `TreeHash(G)` | Graph をコピーし乱数を用意。 | O(N) |
| `add_edge(u, v, cost=1)` | 無向辺を追加。 | 償却 O(1) |
| `get_hash()` | 根なし木のハッシュ値（unsigned long long）。 | O(N) |

## 前提・注意点

非空・連結な無向木で、辺重みは全て 1 とする。ラベルや重みの違いはハッシュに含めない。衝突があるので同値は同型の証明にはならない。同じ Cost 型の同一プロセスでは乱数表を共有するが、プロセスをまたいだ値の比較・保存には向かない。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/tree/tree-hash.hpp"

int main() {
    TreeHash<> a(3), b(3);
    a.add_edge(0, 1); a.add_edge(1, 2);
    b.add_edge(0, 2); b.add_edge(2, 1);
    assert(a.get_hash() == b.get_hash());
}
```
