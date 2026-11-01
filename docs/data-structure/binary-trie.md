---
title: Binary Trie
documentation_of: //data-structure/binary-trie.hpp
---

## このライブラリでできること

`BinaryTrie<T,LOG>` は、非負整数を二進表現の上位 bit から順に分岐させて保存する多重集合です。同じ値を複数個保持でき、最小値・最大値・小さい方から $k$ 番目の値を求められます。以下では $B=\mathrm{LOG}$、挿入回数を $Q$ とします。

各ノードに、その下にある要素数を記録しています。小さい方から $k$ 番目の要素を探すときは、$0$ 側にある個数を見て、どちらの枝へ進むかを決めます。1回の探索で調べる深さは $B$ なので、基本操作は $O(B)$ 時間です。

## 使い方

通常は符号なし整数型と、値を表すのに十分な bit 数を指定します。例では $3,5$ を挿入した後、`all_xor(2)` を呼びます。最小値の問い合わせから見る値は $3\mathbin{\mathrm{xor}}2=1$ と $5\mathbin{\mathrm{xor}}2=7$ になるため、答えは $1$ です。

ただし、この実装の XOR マスクは挿入・削除・個数取得には反映されません。マスクを $m$ とすると、問い合わせから見える値 $x$ を挿入するには `insert(x ^ m)` とする必要があります。マスクは呼び出し側でも管理してください。

```cpp
#include "template/template.cpp"
#include "data-structure/binary-trie.hpp"

int main() {
    BinaryTrie<unsigned int, 20> trie;
    trie.insert(3);
    trie.insert(5);
    assert(trie.get_kth_element(0) == 3);
    trie.all_xor(2);
    assert(trie.min_element() == 1);
}
```

## API・計算量

確保する空間の上界は $O(QB)$ です。削除してもノードは解放されません。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BinaryTrie()` | 空の集合を作る。 | O(1) |
| `insert(val)` | 格納値 val を 1 個追加。 | O(B) |
| `erase(val)` | 格納値を 1 個削除。なければ false。 | O(B) |
| `count(val)` | 格納値の個数。 | O(B) |
| `min_element(), max_element()` | XOR 適用後の最小値・最大値。 | O(B) |
| `get_kth_element(k)` | XOR 適用後の昇順で k 番目（0-indexed）。 | O(B) |
| `all_xor(val)` | 読み出し用の XOR マスクを更新。 | O(1) |
| `size(), empty()` | 個数・空判定。 | O(1) |
| `lower_bound(val), upper_bound(val)` | XOR 適用後の値が val 未満 / val 以下の要素数。 | O(B) |

## 利用条件と実装上の注意

値と XOR マスクは $B$ bit に収めてください。最小値・最大値は非空のとき、`get_kth_element(k)` は $0\le k<\mathrm{size}()$ のときに使います。

`lower_bound/upper_bound` は空集合でも使え、その場合は0を返します。返り値は $[0,\mathrm{size}()]$ の順位で、全要素より大きい値を探すと size() になります。検索値は XOR 適用後の値として解釈します。

削除してもノードは解放されず、デストラクタによる解放もありません。また、オブジェクトのコピーは同じノードを共有するため、独立した集合の複製にはなりません。
