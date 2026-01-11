---
title: 削除可能 priority queue
documentation_of: //data-structure/erasable-priority-queue.hpp
---

priority_queue を 2 つ持ち、片方に削除待ちの要素を入れて削除を遅延評価することで実質的に削除も出来るようにした priority_queue。

queue に存在しない要素を削除しようとするとバグるので注意

- `push(val)`
  - 値 `val` を優先度付きキューに push する
- `top()`
  - キューの先頭の値を返す
- `pop()`
  - キューの先頭の値を pop する（削除する）
- `erase(val)`
  - 値 `val` を削除する
  - ただしキューの中に値 `val` が存在する場合のみ使える。キューの中に値 `val` が存在するかどうかのチェックはやっていないので注意
- `empty()`
  - キューが空かどうかの boolean を返す