---
title: 生成器ライブラリ一式
documentation_of: //random/gen/all.hpp
---

## このライブラリでできること

ランダムテストの入力生成器 (generator) で使うヘッダを、まとめて読み込むための集約ヘッダです。コンテスト中は、このヘッダだけを include すれば次の機能をすべて使えます。

| ヘッダ | 主な機能 |
| --- | --- |
| [`random.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) | seed 付きの乱数クラス `Random`。整数・実数・確率判定・選択・シャッフル |
| [`sequence.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/sequence.md) | 数列、相異なる値の数列、順列、部分集合、区間 |
| [`string.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/string.md) | 文字集合を指定した文字列、英小文字の文字列 |
| [`tree.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/tree.md) | 一様な木、パス、スター、親配列、頂点番号の付け替え |
| [`graph.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/graph.md) | 単純グラフ、連結グラフ、DAG、辺の重み |

生成器は提出しないので、`oj-bundle` で展開する必要はありません。[`scripts/randtest.py`](https://github.com/siro53/compro_library/blob/main/scripts/randtest.py) はライブラリのルートを include パスに加えてコンパイルします。このため、生成器にはそのまま `#include "random/gen/all.hpp"` と書けます。

## 使い方

生成器は `gen <seed>` として呼ばれ、1つの入力を標準出力に書く約束です。例は「$n$ 頂点の木と、各頂点の値」を入力に持つ問題の生成器です。`randtest --init` で作られる雛形も同じ形をしています。

```cpp
#include "template/template.cpp"
#include "random/gen/all.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);                  // argv[1] が seed
    int n = rng.size(1, 9);                  // 1 <= n <= 8
    vector<int> a = random_vector(rng, n, 1, 11);  // 1 <= a_i <= 10
    print(n);
    print(a);
    for(auto [u, v] : random_tree(rng, n)) print(u + 1, v + 1);
}
```

この生成器を `gen.cpp`、提出する解を `main.cpp`、愚直解を `naive.cpp` として保存し、次のように実行します。

```sh
randtest main.cpp naive.cpp gen.cpp
```

`main` と `naive` の出力が食い違うか、どちらかが実行時エラーや時間切れになると、そのときの入力と seed が `randtest_fail/` に保存されます。`randtest main.cpp naive.cpp gen.cpp --replay <seed>` で同じ入力を再現できます。ツールの詳しい使い方は README の「ランダムテスト」の節を参照してください。

## API・計算量

このヘッダ自体は関数や型を定義しません。各機能の計算量と領域は、上の表のリンク先のページを参照してください。読み込むのは標準ライブラリのヘッダと上記5つのヘッダだけで、静的な領域は確保しません。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `#include "random/gen/all.hpp"` | `random.hpp`, `sequence.hpp`, `string.hpp`, `tree.hpp`, `graph.hpp` を読み込む。 | 実行時の処理なし |

## 利用条件と実装上の注意

- 区間はすべて右端を含まない半開区間 $[l,r)$ で、頂点番号と添字は0始まりです。1始まりの入力形式では出力時に $1$ を足してください。
- 同じ seed で同じ入力を得るには、乱数を使う関数を同じ順序で呼ぶ必要があります。生成器を書き換えた後は、以前の seed で同じ入力になるとは限りません。
- ランダムテストでは、小さな入力を大量に試すと手で追える反例が得やすくなります。制約の上限ではなく、`rng.size` などで小さめの値を使うのがおすすめです。
