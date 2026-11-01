---
title: 削除可能な優先度付きキュー
documentation_of: //data-structure/erasable-priority-queue.hpp
---

## 概要

`ErasablePriorityQueue<T, isAscending=true>` は通常のヒープ `que` と削除予約ヒープ `rm_que` を使う。既定は最小値優先、false なら最大値優先。`Q` は追加・削除予約の総数。

空間 O(Q)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ErasablePriorityQueue()` | 空のキューを作る。 | O(1) |
| `push(val)` | 値を 1 個追加。 | O(log Q) |
| `erase(val)` | 値 1 個の削除を予約。 | O(log Q) |
| `top()` | 削除予約を反映して先頭を返す。 | 償却 O(log Q)、1 回最悪 O(Q log Q) |
| `pop()` | 削除予約を反映して先頭を削除。 | 償却 O(log Q)、1 回最悪 O(Q log Q) |
| `empty()` | 現在の物理ヒープ que が空か。削除予約は反映しない。 | O(1) |

## 前提・注意点

存在する値だけ `erase` すること。`top/pop` は論理的に非空の場合のみ呼ぶ。`empty()` は遅延削除を処理しないので、論理的な空判定には別途要素数を管理する。公開ヒープを直接変更すると整合性が崩れる。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/erasable-priority-queue.hpp"

int main() {
    ErasablePriorityQueue<int> q;
    q.push(2);
    q.push(5);
    q.erase(2);
    assert(q.top() == 5);
}
```
