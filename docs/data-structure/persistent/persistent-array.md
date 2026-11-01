---
title: 永続配列
documentation_of: //data-structure/persistent/persistent-array.hpp
---

## 概要

`PersistentArray<T,LOG=4>` は分岐数 `B=2^LOG` の trie に配列を保存し、更新経路だけ複製する。`Node` は値 val と子 childs、`root` は現在の版。`d=floor(log_B N)+1`（N>0）。

固定 LOG の構築空間 O(N+d)、更新 1 回につき O(Bd) の追加空間。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentArray(v)` | v から初期版を構築。 | O(Nd + B(N+d)) 上界 |
| `PersistentArray(N, id=0)` | N 要素を id にする意図だが、現状は一時オブジェクトを作るだけで初期化が不完全。 | O(Nd + B(N+d)) 上界 |
| `get(idx), get(node, idx)` | 現在版・指定版の値。 | O(d) |
| `set(idx, value), set(node, idx, value)` | 現在版・指定版から更新し、新 root を返す。同時に root も変更。 | O(Bd) |
| `Node(), Node(pointer), Node(reference)` | 子配列を初期化・コピーする内部ノード。コピー時 val はコピーされない。 | O(B) |

## 前提・注意点

配列版コンストラクタを使い、添字は元の配列の `[0,N)` に限定する。`PersistentArray(N,id)` は委譲コンストラクタになっていないため使用不可。配列版では identity が初期化されないので、未確保位置の取得も避ける。空のデフォルト構築も利用不可。版は `Node*` を保存して管理する。Node と root/depth/identity は内部状態であり直接変更しない。解放処理はない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-array.hpp"

int main() {
    PersistentArray<int> a(vector<int>{1, 2, 3});
    auto old_root = a.root;
    auto new_root = a.set(1, 9);
    assert(a.get(old_root, 1) == 2);
    assert(a.get(new_root, 1) == 9);
}
```
