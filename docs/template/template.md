---
title: 競プロ用テンプレート
documentation_of: //template/template.cpp
---

## このライブラリでできること

`template/template.cpp` は、競技プログラミングのソースで共通に使う入出力・型別名・ループマクロ・小さな補助関数をまとめたファイルです。このライブラリの使用例は、まずこのファイルを include し、その後に使うアルゴリズムのヘッダーを include する形にしています。

`using namespace std` と入出力用の `siro53_io` を導入します。また、グローバルな `Setup` オブジェクトが、標準入出力の同期解除、cinのtie解除、小数点以下15桁の出力形式を設定します。これらはmain関数の前に行われます。

## 使い方

`input(a,b)` は値を読み、`print(a,b)` は空白区切りで出力して最後に改行します。vectorへの入力では、先に長さを確保しておいてください。`INT(n)` や `VEC(a,int,n)` は宣言と入力をまとめるマクロです。

例では `ord_sort(v)` で値が小さい順の添字を取得し、`make_vector<int>({2,3},7)` で2行3列をすべて $7$ にした配列を作っています。`chmax/chmin` は値が改善したときだけ代入し、その有無をboolで返すため、動的計画法などで使えます。

```cpp
#include "template/template.cpp"

int main() {
    vector<int> v{3, 1, 2};
    auto order = ord_sort(v);
    assert((order == vector<int>{1, 2, 0}));
    auto a = make_vector<int>({2, 3}, 7);
    assert(a[1][2] == 7);
    int best = 2;
    assert(chmax(best, 5));
}
```

## API・計算量

配列を作る補助関数は、結果の要素数に応じた空間を使います。queueの出力には、さらに要素数分のコピー領域が必要です。表の $N$ は対象コンテナの要素数を表します。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Setup()` | cin.tie を解除し、入出力書式を設定。 | O(1) |
| `input(args...), input_single(x)` | 値・pair・確保済み vector を標準入力から読む。 | 入力サイズに比例 |
| `print(args...), print_single(x)` | 値・pair・vector/set/deque/queue を空白区切りで出力。print は末尾改行。 | 出力サイズに比例 |
| `dump(x), debug_print(args...)` | 標準エラーへ値・コンテナを整形出力。map/unordered_map にも対応。 | 出力サイズに比例 |
| `has_val<T>, has_val_impl::check` | val() の有無をコンパイル時判定し modint の入出力を選ぶ。 | 実行時コストなし |
| `INT, LL, STRING, CHAR, DBL, LD, UINT, ULL` | 指定型で変数を宣言して入力。 | 入力サイズに比例 |
| `VEC(name,type,n), VEC2(name,type,h,w)` | 配列を確保して入力。 | O(n) / O(hw) + 入力 |
| `REP(i,n), REP(i,a,b)` | [0,n)、[a,b) の for ループ。 | 反復数×本体コスト |
| `ALL(v), RALL(v), SZ(v)` | begin/end、逆イテレータ、int 型の size。 | O(1) |
| `SORT(v), RSORT(v), UNIQUE(v)` | 昇順・降順ソート、ソート後の重複除去。 | O(N log N) |
| `REV(v), MIN(v), MAX(v)` | 反転、最小値、最大値。 | O(N) |
| `debug(args...)` | DEBUG 定義時のみ行番号・式名と値を標準エラーへ出力。 | 出力サイズに比例（無効時 O(1)） |
| `Case(i)` | Case #i: を出力（改行なし）。 | 桁数に比例 |
| `popcnt(int), popcnt(ll)` | 立っている bit 数。 | O(1) |
| `chmax(a,b), chmin(a,b)` | 改善したら代入して true、変更なしなら false。 | O(1) |
| `make_vector<T>(sizes,e), make_vector_impl<T,dim>` | 指定形状の多次元 vector を e で初期化。impl は内部再帰。 | 確保する要素・コンテナ総数に比例 |
| `iota_gen(n,start=0)` | start から n 個の連続整数。 | O(n) |
| `ord_sort(v,greater=false)` | v の昇順（true は降順）に並ぶ添字列。 | O(N log N) |

## 利用条件と実装上の注意

型別名は `ll=long long`、`i128=__int128_t` です。`INF=2^30`、`LLINF=2^60` は有限の番兵値であり、任意の答えより大きいとは限りません。`MOD=1000000007` と `MOD2=998244353` は法の候補として使う定数です。`dx/dy` は4方向の座標差を表します。

`REP(i,n)` は $[0,n)$、`REP(i,a,b)` は $[a,b)$ を走査します。`OVERLOAD3,REP1,REP2` はこのマクロの内部用です。`MIN/MAX` は非空コンテナにだけ使い、`ord_sort` は同値の要素の順序を保証しません。

`debug` は `DEBUG` を定義した場合にだけ出力されます。queueの出力はキューをコピーして処理するため、要素数分の追加メモリが必要です。128 bit整数の出力も最小負値の符号反転には対応していません。

GCC向けの `bits/stdc++.h` や128 bit整数拡張を使います。通常のヘッダーのような多重include防止はなく、関数定義も含むため、1翻訳単位に1回だけ include してください。
