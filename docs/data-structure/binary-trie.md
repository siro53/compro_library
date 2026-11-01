---
title: Binary Trie
documentation_of: //data-structure/binary-trie.hpp
---

## 概要

`BinaryTrie<T, LOG=32>` は整数の多重集合を二分 trie で保持する。`B=LOG`、`Q` は挿入回数。

確保する空間は最大 O(QB)。削除してもノードは解放されない。

## API・計算量

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
| `lower_bound(val), upper_bound(val)` | 順位検索用だが、現状は正しい境界を保証しない。 | O(B) |

## 前提・注意点

`T` は符号なし整数を推奨。値と XOR マスクは B bit に収める。最小・最大・k 番目取得は非空時のみ。

`insert/erase/count` は XOR マスクを反映しないので、表示上の値で操作したい場合は呼び出し側で累積マスクを XOR する。`lower_bound` は片方の子しかない場合などを正しく処理せず、`upper_bound` もそれに依存するため使用を避ける。ノードの解放処理はなく、コピーはノードを共有する。

## 使用例

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
