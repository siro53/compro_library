---
title: ランレングス圧縮
documentation_of: //misc/rle.hpp
---

## このライブラリでできること

`runlength_encoding` は、連続する同じ値を「値と連続数」の組にまとめます。たとえば `aaabbc` は `(a,3),(b,2),(c,1)` になります。連続部分をひとかたまりとして処理する問題や、同じ値の並びの長さを調べる場合に使えます。

長さ $N$ の入力を左から一度読むので、時間は $O(N)$ です。離れた場所に同じ値があっても、別のまとまりとして返します。

## 使い方

文字列には `string`、一般の値列には `vector<T>` を渡します。返り値はそれぞれ `vector<pair<char,int>>`、`vector<pair<T,int>>` です。例では最初の組が文字 `a` と連続数 $3$ であることを確認しています。

```cpp
#include "template/template.cpp"
#include "misc/rle.hpp"

int main() {
    auto runs = runlength_encoding(string("aaabbc"));
    assert(runs.size() == 3);
    assert(runs[0].first == 'a' && runs[0].second == 3);
}
```

## API・計算量

結果の組数を $K$ とすると、返り値の空間は $O(K)$ です。最悪では $K=N$ になります。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `runlength_encoding(vector<T>)` | vector<pair<T,int>> を返す。 | O(N) |
| `runlength_encoding(string)` | vector<pair<char,int>> を返す。 | O(N) |

## 利用条件と実装上の注意

現実装は先頭要素を使って結果を初期化するため、入力は非空としてください。空のvectorでは範囲外参照となり、空文字列でも空の結果にはなりません。

連続数の型は int なので、その範囲に収める必要があります。元の列の順序は保たれ、ソートや値ごとの総出現数の集計は行いません。
