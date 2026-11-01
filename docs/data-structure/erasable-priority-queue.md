---
title: 削除可能な優先度付きキュー
documentation_of: //data-structure/erasable-priority-queue.hpp
---

## このライブラリでできること

`ErasablePriorityQueue<T>` は、優先度付きキューに「指定した値を1個削除する」操作を加えたものです。標準の `priority_queue` では先頭以外を直接取り除けませんが、このクラスでは削除予定の値を別のキューに記録しておき、先頭に現れた時点で取り除きます。

既定では最小値が先頭になり、第2テンプレート引数を `false` にすると最大値が先頭になります。以下では、追加と削除予約の総数を $Q$ とします。

## 使い方

`push(x)` で追加し、`erase(x)` でその値1個の削除を予約します。例では $2$ と $5$ を入れた後に $2$ を削除するため、`top()` は削除予約を処理して $5$ を返します。

削除を後回しにする仕組みなので、ある1回の `top()` に多くの処理が集まることがあります。ただし、各予約は高々1回処理されるため、操作列全体で見ると1操作あたり償却 $O(\log Q)$ 時間です。

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

## API・計算量

必要な空間は $O(Q)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `ErasablePriorityQueue()` | 空のキューを作る。 | O(1) |
| `push(val)` | 値を 1 個追加。 | O(log Q) |
| `erase(val)` | 値 1 個の削除を予約。 | O(log Q) |
| `top()` | 削除予約を反映して先頭を返す。 | 償却 O(log Q)、1 回最悪 O(Q log Q) |
| `pop()` | 削除予約を反映して先頭を削除。 | 償却 O(log Q)、1 回最悪 O(Q log Q) |
| `empty()` | 現在の物理ヒープ que が空か。削除予約は反映しない。 | O(1) |

## 利用条件と実装上の注意

`erase(x)` は現在存在している値に対してだけ呼んでください。同じ値が複数個ある場合は1回の呼び出しで1個を削除します。

現実装の `empty()` は削除予約を処理せず、物理的なヒープが空かどうかだけを調べます。そのため、論理上すべて削除済みでも `false` になることがあります。要素数を別途管理し、`top/pop` は論理的に非空と分かっている場合だけ呼んでください。公開されている `que,rm_que` は内部状態なので直接変更しないでください。
