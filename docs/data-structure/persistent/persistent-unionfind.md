---
title: 永続 Union Find
documentation_of: //data-structure/persistent/persistent-unionfind.hpp
---

## このライブラリでできること

`PersistentUnionFind` は、過去の併合状態を参照したり、その状態から別の併合を行ったりできる Union Find です。親と集合サイズを永続配列に保存するため、併合前の版も失われません。頂点数を $N$ とします。

通常の Union Find と異なり経路圧縮を行わず、小さい集合を大きい集合へつなぐ方法で木の高さを $O(\log N)$ に抑えます。親を1段たどるためにも永続配列への $O(\log N)$ のアクセスが必要なので、代表取得や併合は $O(\log^2 N)$ 時間です。

## 使い方

`get_root()` で現在の版を保存し、その根を問い合わせや併合の最後の引数へ渡します。根を省略したオーバーロードは、現在の版を対象にします。

例では初期版 `r0` では $0,1$ は別の集合、併合後の `r1` では同じ集合です。古い版への問い合わせでは状態を変えずに、その時点の連結性を確認できます。

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-unionfind.hpp"

int main() {
    PersistentUnionFind uf(3);
    auto r0 = uf.get_root();
    uf.merge(0, 1, r0);
    auto r1 = uf.get_root();
    assert(!uf.same(0, 1, r0));
    assert(uf.same(0, 1, r1));
}
```

## API・計算量

永続配列の分岐数を定数とすると、構築時に $O(N)$、併合が成功するたびに追加で $O(\log N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentUnionFind(N)` | N 個の単独集合を構築。 | O(N log N) 上界 |
| `leader_and_size(u[, r])` | 現在版または r 版で (代表, 集合サイズ)。 | O(log² N) |
| `leader(u[, r]), size(u[, r])` | 代表・集合サイズ。 | O(log² N) |
| `same(u, v[, r])` | 同じ集合か。 | O(log² N) |
| `merge(u, v[, r])` | 指定版から併合し現在 root を更新。既に同じなら false。 | O(log² N) |
| `get_root()` | 現在版の root。 | O(1) |

## 利用条件と実装上の注意

頂点番号は $[0,N)$ です。表の `[,r]` は「根を指定する版と省略する版の両方がある」という表記であり、C++ の構文ではありません。

`merge(u,v,r)` が成功すると、`r` から作った新しい版が現在版になります。一方、すでに同じ集合であれば `false` を返し、現在版は変更しません。つまり、失敗した併合が自動的に `r` へ切り替えてくれるわけではありません。

公開メンバ `par/root` は内部状態です。版の保存には `get_root()` を使い、親配列を直接書き換えないでください。永続配列のノードには解放処理がありません。
