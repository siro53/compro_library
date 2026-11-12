---
title: テスト生成用の乱数 (Random)
documentation_of: //random/gen/random.hpp
---

## このライブラリでできること

`Random` は、ランダムテストの入力生成器 (generator) のための乱数クラスです。seed を指定でき、同じ seed からは常に同じ乱数列が得られます。そのため、ランダムテストで見つけた反例を seed だけから再現できます。

コンストラクタ `Random(argc, argv)` はコマンドライン引数の `argv[1]` を seed として読みます。[`scripts/randtest.py`](https://github.com/siro53/compro_library/blob/main/scripts/randtest.py) が生成器を `gen <seed>` の形で呼ぶので、この規約に合わせて書くだけで反例の保存と再現ができます。

整数乱数の区間は、既存の [`random/rng.hpp`](https://github.com/siro53/compro_library/blob/main/docs/random/rng.md) と同じく右端を含まない半開区間 $[l,r)$ です。`randint(1, 7)` は $1$ 以上 $6$ 以下の整数を返します。

`rng.hpp` との違いは次のとおりです。

- 生成器は標準化された `std::mt19937_64` で、`std::uniform_int_distribution` を使わずに一様化しています。このため同じ seed なら、コンパイラや標準ライブラリの実装が違っても同じ値が出ます。
- 返り値の型は引数の型から決まります。`int` 同士なら `int`、`long long` を含めば `long long` です。

木やグラフなどの生成関数は、このクラスを引数に取る別ヘッダにまとめています。一覧は [生成器ライブラリ一式](https://github.com/siro53/compro_library/blob/main/docs/random/gen/all.md) を参照してください。

## 使い方

生成器では `main` の引数を `Random` に渡し、問題の制約を半開区間で書き写して乱数を引きます。`size` は小さい値ほど出やすい長さを返すので、反例が見つかったときに手で追える小さな入力が得やすくなります。

```cpp
#include "template/template.cpp"
#include "random/gen/random.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);           // ./gen 42 なら seed = 42
    int n = rng.size(1, 9);           // 1 以上 8 以下。小さい値に偏る
    assert(1 <= n && n <= 8);
    long long x = rng.randint(0, 1000000000000LL);  // long long になる
    assert(0 <= x && x < 1000000000000LL);
    vector<int> p{1, 2, 3};
    rng.shuffle(p);
    int c = rng.choice(p);
    assert(1 <= c && c <= 3);

    // 同じ seed なら同じ列になる
    Random a(7), b(7);
    for(int i = 0; i < 5; i++) assert(a.randint(100) == b.randint(100));
    print(n, x);
}
```

例を実行すると、`n` と `x` が1行に出力されます。値は seed によって決まり、引数なしで実行したときは seed が $0$ になります。

## API・計算量

以下では、選ぶ範囲の幅を $w=r-l$、数列の長さを $n$ とします。乱数エンジンの状態は固定サイズで、クラス全体の空間計算量は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Random(uint64_t seed = 0)` | `seed` でエンジンを初期化する。 | $O(1)$ |
| `Random(int argc, char **argv)` | `argv[1]` を10進の非負整数として読み、seed にする。`argc < 2` なら seed は $0$。 | $O(\lvert \mathtt{argv[1]} \rvert)$ |
| `uniform(uint64_t n)` | $[0,n)$ の一様な整数を返す。$n>0$。 | 期待 $O(1)$ |
| `randint(l, r)` | $[l,r)$ の一様な整数を返す。型は `l`, `r`, `int` の共通型。 | 期待 $O(1)$ |
| `randint(r)` | `randint(0, r)` と同じ。 | 期待 $O(1)$ |
| `real(l, r)` | $[l,r)$ の `double` を返す。 | $O(1)$ |
| `real()` | `real(0.0, 1.0)` と同じ。 | $O(1)$ |
| `coin(p = 0.5)` | 確率 $p$ で `true` を返す。 | $O(1)$ |
| `size(l, r)` | 小さい値に偏らせた $[l,r)$ の整数を返す。分布は後述。 | 期待 $O(1)$ |
| `choice(v)` | 空でない `vector` の要素を一様に1つ選び、参照を返す。 | 期待 $O(1)$ |
| `shuffle(v)` | `vector` を一様ランダムな順に並べ替える。 | 期待 $O(n)$ |
| `engine()` | 内部の `std::mt19937_64` への参照。標準の分布と組み合わせる場合に使う。 | $O(1)$ |

`uniform` は剰余の偏りを除くため、$2^{64} \bmod n$ 個の値を引いた場合に引き直します。1回で受理される確率は $1/2$ より大きいので、引き直しの回数の期待値は定数です。

## 利用条件と実装上の注意

- `randint` と `size` は $l<r$、`real` は $l<r$ を要求し、満たさない場合は `assert` で停止します。引数は整数型で、`bool` や `char` などは `int` に昇格して計算します。
- `real(l, r)` は $[0,1)$ を $2^{-53}$ 刻みで表した値 $u$ から $l+(r-l)u$ を計算します。丸めで $r$ に等しくなった場合だけ、$r$ より小さい最大の `double` を返します。数学的な連続一様分布ではありません。
- `size(l, r)` は、$2^k \ge w$ となる最小の $k$ を $K$ として、$k \in \{0,1,\dots,K\}$ を等確率に選び、$[l, l+\min(w,2^k))$ から一様に選びます。$k=0$ なら必ず $l$ になるので、$l$ が出る確率は $1/(K+1)$ 以上です。たとえば `size(1, 1001)` では $K=10$ で、$1$ になる確率は約 $0.18$、$10$ 未満になる確率は約 $0.47$ です。$k=K$ のときは範囲全体から一様に選ぶので、最大付近の値も出ます。
- `Random(argc, argv)` は、`argv[1]` が非負整数として読めない場合、標準エラー出力にメッセージを出して終了コード $2$ で終了します。生成器が誤った seed で黙って動くのを防ぐためです。
- 同じ乱数列を得るには、seed だけでなく関数を呼ぶ順序も同じにする必要があります。生成器のコードを書き換えると、同じ seed でも別の入力になります。
- 暗号用途の乱数ではありません。
