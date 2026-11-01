---
title: 競プロ用テンプレート
documentation_of: //template/template.cpp
---

## 概要

GCC 向けの標準ヘッダー、入出力、型別名、マクロ、補助関数をまとめる。`using namespace std` と `siro53_io` を導入する。`Setup` のグローバルインスタンスが同期を無効化し、固定小数点 15 桁の出力を設定する。

補助配列は結果の要素数に比例した空間。queue の出力には要素数分のコピー領域も必要。

## API・計算量

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

## 前提・注意点

`ll=long long`、`i128=__int128_t`。定数は `INF=2^30`、`LLINF=2^60`、`MOD=1000000007`、`MOD2=998244353`、dx/dy は 4 近傍（右・下・左・上に相当する座標差）。OVERLOAD3、REP1、REP2 は REP の実装補助。

MIN/MAX は非空コンテナのみ。ord_sort の同値要素の順序は未保証。input(vector) はサイズを変更しないので先に確保する。queue の出力は値渡しでコピーする。128 bit 入出力はその型の範囲内を使い、最小負値の出力は符号反転がオーバーフローするため避ける。ヘッダーとして使うときは 1 翻訳単位に 1 回だけ include する。

## 使用例

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
