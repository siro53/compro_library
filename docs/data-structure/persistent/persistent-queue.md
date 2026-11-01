---
title: 永続キュー
documentation_of: //data-structure/persistent/persistent-queue.hpp
---

## このライブラリでできること

`PersistentQueue<T,LOG>` は、過去のキューを残したまま末尾への追加・先頭の削除を行えるキューです。ある操作列の途中から別の操作列へ分岐する場合に使えます。操作は元のキューを書き換えず、操作後のキューを返します。

末尾のノードから過去のノードをたどるダブリング表を持ち、削除後の先頭を探します。`LOG` はこの表の段数で、`push/pop` は $O(\mathrm{LOG})$、先頭・末尾の取得は $O(1)$ 時間です。

## 使い方

返り値を新しい変数へ保存すると、新旧の版を同時に使えます。例では `q1` が $[10]$、`q2` が $[10,20]$、`q3` が $[20]$ です。`q2.pop()` を呼んでも、`q1` や `q2` の内容は変わりません。

現在の版だけを進めたい場合も、`q=q.push(x)` のように返り値を代入してください。`q.push(x)` と呼ぶだけでは `q` は更新されません。

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

## API・計算量

1回のpushで $O(\mathrm{LOG})$ の空間を追加し、各版を表すキュー自体は $O(1)$ の空間で保持します。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentQueue()` | 空の版を作る。 | O(1) |
| `PersistentQueue(front_node, back_node)` | ノードを指定して版を作る内部用構築。 | O(1) |
| `push(x)` | 末尾に追加した新しい版を返す。元の版は不変。 | O(LOG) |
| `pop()` | 先頭を取り除いた版を返す。空なら空の版。 | O(LOG) |
| `front(), back()` | 先頭・末尾の値。 | O(1) |
| `empty()` | 空判定。 | O(1) |
| `Node(val, idx)` | ノードの値・番号を設定。祖先配列の初期化は push 側で行う。 | O(1) |

## 利用条件と実装上の注意

`front/back` は非空のキューに対して呼んでください。空のキューの `pop()` は空の版を返します。

`LOG` は、`pop` で必要になる祖先までの距離が $2^{\mathrm{LOG}}$ 未満になるように選びます。ノードの `val` は値、`idx` はその履歴に沿った連番、`pre[k]` は $2^k$ 個前のノードです。`front_node/back_node` を直接指定するコンストラクタは内部処理向けで、整合したノードの組を渡す必要があります。ノードの解放処理はありません。
