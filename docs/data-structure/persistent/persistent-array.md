---
title: 永続配列
documentation_of: //data-structure/persistent/persistent-array.hpp
---

## このライブラリでできること

`PersistentArray<T,LOG>` は、更新前の状態を残したまま、新しい配列の状態を作れる永続配列です。過去の状態をすべて丸ごとコピーする代わりに、更新対象までの経路だけをコピーし、それ以外の部分は共有します。

分岐数を $B=2^{\mathrm{LOG}}$、元の配列長を $N>0$、深さを $d=\lfloor\log_B N\rfloor+1$ とします。値の取得は $O(d)$、更新は各段の子配列をコピーするため $O(Bd)$ 時間です。`LOG` を定数と見れば、どちらも $O(\log N)$ です。

## 使い方

このクラスでは、版を表すものはオブジェクト全体ではなく `Node*` 型の根です。更新前に `root` を保存し、`set` の返り値を新しい版として保存します。`get(root,index)` に根を指定すれば、どの版の値も取得できます。

例では初期版の位置1は $2$、更新版では $9$ です。新しい版を作っても、保存した古い根からは引き続き $2$ を取得できます。`set` は新しい根を返すと同時に、オブジェクトの現在の `root` も変更します。

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

## API・計算量

分岐数を定数とした構築時の空間は $O(N+d)$、1回の更新で増える空間は $O(Bd)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentArray(v)` | v から初期版を構築。 | O(Nd + B(N+d)) 上界 |
| `PersistentArray(N, id=0)` | N 要素を id にする意図だが、現状は一時オブジェクトを作るだけで初期化が不完全。 | O(Nd + B(N+d)) 上界 |
| `get(idx), get(node, idx)` | 現在版・指定版の値。 | O(d) |
| `set(idx, value), set(node, idx, value)` | 現在版・指定版から更新し、新 root を返す。同時に root も変更。 | O(Bd) |
| `Node(), Node(pointer), Node(reference)` | 子配列を初期化・コピーする内部ノード。コピー時 val はコピーされない。 | O(B) |

## 利用条件と実装上の注意

現状では、必ず非空の初期配列を渡して構築し、添字をその配列の $[0,N)$ に限定してください。`PersistentArray(N,id)` は委譲コンストラクタになっておらず、別の一時オブジェクトを作るだけなので、意図した初期化が行われません。

配列からの構築でも、未確保位置に対する既定値 `identity` は初期化されていません。そのため範囲外へのアクセスで既定値を取得する使い方はできません。引数なしの構築も、そのままでは使えません。

`Node` は値 `val` と子配列 `childs` を持ち、`depth` は木の深さです。これらは公開されていますが、版の保存以外では直接変更しないでください。ノードの解放処理はありません。
