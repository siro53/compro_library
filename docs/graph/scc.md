---
title: 強連結成分分解
documentation_of: //graph/scc.hpp
---

## 概要

`SCC<Cost=int>` は Kosaraju 法で有向グラフを強連結成分に分ける。`N` は頂点数、`M` は辺数。

空間 O(N+M)、再帰スタック最大 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SCC(N)` | 辺なしで初期化。 | O(N) |
| `SCC(g)` | Graph をコピーして直ちに分解。 | O(N+M) |
| `add_directed_edge(from, to)` | 構築前に辺を追加。 | 償却 O(1) |
| `build()` | 分解を実行。 | O(N+M) |
| `operator[](v)` | 頂点 v の成分番号。 | O(1) |
| `size()` | 成分数。構築後のみ。 | O(1) |
| `get_contracted_graph()` | 各成分を縮約した DAG。重複辺は残る。 | O(N+M) |

## 前提・注意点

成分番号はトポロジカル順。構築は一度だけで、構築後に辺を追加できない。Graph 引数で構築した場合は build を再度呼ばない。

## 使用例

```cpp
#include "template/template.cpp"
#include "graph/scc.hpp"

int main() {
    SCC<> scc(3);
    scc.add_directed_edge(0, 1);
    scc.add_directed_edge(1, 0);
    scc.add_directed_edge(1, 2);
    scc.build();
    assert(scc[0] == scc[1] && scc[1] < scc[2]);
}
```
