---
title: 永続キュー
documentation_of: //data-structure/persistent/persistent-queue.hpp
---

## 概要

`PersistentQueue<T,LOG=20>` は版を保ったまま push/pop できるキュー。`Node` の val は値、idx は経路上の連番、pre は祖先のダブリング表。front_node/back_node が版を表す。

push 1 回につき O(LOG) の追加空間、版の保持は O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentQueue()` | 空の版を作る。 | O(1) |
| `PersistentQueue(front_node, back_node)` | ノードを指定して版を作る内部用構築。 | O(1) |
| `push(x)` | 末尾に追加した新しい版を返す。元の版は不変。 | O(LOG) |
| `pop()` | 先頭を取り除いた版を返す。空なら空の版。 | O(LOG) |
| `front(), back()` | 先頭・末尾の値。 | O(1) |
| `empty()` | 空判定。 | O(1) |
| `Node(val, idx)` | ノードの値・番号を設定。祖先配列の初期化は push 側で行う。 | O(1) |

## 前提・注意点

`front/back` は非空時のみ。`pop` の祖先ジャンプに必要な差分が `2^LOG` 未満となるよう LOG を選ぶ。返り値を保存しないと版は更新されない。ノードと祖先表は直接操作しない。解放処理はない。

## 使用例

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-queue.hpp"

int main() {
    PersistentQueue<int> q0;
    auto q1 = q0.push(10);
    auto q2 = q1.push(20);
    auto q3 = q2.pop();
    assert(q1.front() == 10);
    assert(q3.front() == 20);
}
```
