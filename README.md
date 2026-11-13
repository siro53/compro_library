# compro_library
競技プログラミングで使うライブラリ群

[![Actions Status](https://github.com/siro53/compro_library/workflows/verify/badge.svg)](https://github.com/siro53/compro_library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://siro53.github.io/compro_library/)

## ライブラリの使い方

[ライブラリ一覧](docs/index.md)から各ファイルのドキュメントを参照できます。各ページでは、用途と考え方を説明した後、具体的な使用例、API の動作と計算量を紹介しています。数学的な成立条件や実装上の制約は「利用条件と実装上の注意」にまとめています。

## 検証環境

CI と同じツールを使う場合は、リポジトリのルートで専用の仮想環境を作ってください（Python 3.11 と g++ が必要です）。

```sh
python3 -m venv .venv
. .venv/bin/activate
python3 -m pip install -r .verify-helper/requirements.txt
python3 .verify-helper/patch_dependencies.py
python3 -m unittest discover -s test/mytest/ci -v
oj-verify all
```

`patch_dependencies.py` は、固定した検証ツールのインストール先に互換修正を適用します。`pkg_resources` を標準の `importlib.resources` に置き換え、Library Checker の廃止された引数、更新確認キャッシュの未登録キー、未追跡の `.gitignore` の検査を修正します。繰り返し実行できますが、バージョンや修正対象のコードが想定と異なる場合は停止します。依存バージョンを更新する際は、このスクリプトと回帰テストも見直してください。

ドキュメントの `exclude` は依存解析前にも適用し、開発用 Python スクリプトと bundle の fixture を解析対象から外します。ライブラリと C++ verifier は対象のままです。bundle のコメント除去専用の前処理では、未評価のマクロや `#pragma once` による警告だけが出るため、その前処理呼び出しに限って `-w` を指定します。通常のコンパイルの `-Wall -Wextra` と前処理のエラーは有効です。

## マージ前のドキュメント確認

このリポジトリ内のブランチから PR を作ると、`verify` ワークフローの検証が成功した後に `Pages preview` ジョブがドキュメントを生成し、次の URL に公開します。Draft PR でも利用できます。

```text
https://siro53.github.io/compro_library/pr-preview/pr-<PR番号>/
```

PR にプレビューへのリンクが自動でコメントされます。ブランチへ push すると、検証が成功した場合のみ更新されます。検証が失敗・キャンセルされた場合は更新せず、以前のプレビューがあればそのまま残ります。PR を閉じるかマージすると、検証結果に関係なく削除されます。コメント掲載後、GitHub Pages のビルドが完了するまでは反映に時間がかかります。

プレビューは表示確認用です。テストとプレビュー生成は同じワークフロー内で直列に実行しますが、別ジョブのため検証結果のファイルは引き継ぎません。そのため、プレビュー内の検証ステータスはその PR の最新テスト結果とは限りません。フォークからの PR は対象外です。

公開先は既存の `gh-pages` ブランチで、Pages の設定は `Deploy from a branch` の `gh-pages` / `/ (root)` を使用します。既存の `GH_PAT` シークレットを公開に使用します。本番公開では `pr-preview/` を保持するため、他の PR のプレビューも引き続き閲覧できます。

## 出典付きでbundleする

`oj-bundle` の代わりに `scripts/bundle.py` を使うと、各ライブラリの挿入位置に次のコメントを付けます。ネストした include も対象で、同じファイルには最初の挿入時だけ付けます。ライブラリを含まないソースには付けません。

```cpp
// Source: https://github.com/siro53/compro_library
```

`online-judge-verify-helper` をインストールした環境で実行してください。引数は `oj-bundle` にそのまま渡されます。

```sh
python3 /path/to/compro_library/scripts/bundle.py main.cpp -I /path/to/compro_library > bundled.cpp
```

エディタなどから呼び出している場合も、`oj-bundle` の部分を `python3 /path/to/compro_library/scripts/bundle.py` に置き換えてください。bundleに失敗した場合は非ゼロで終了し、標準出力には何も出力しません。入力ファイルと出力先は別にしてください。

動作確認用のスナップショットテストは、リポジトリのルートで次のコマンドを実行します（`oj-bundle`と`g++`が必要です）。CIでも同じテストを実行します。

```sh
python3 -m unittest discover -s test/mytest/bundle -v
```

期待値は`test/mytest/bundle/snapshots/`に保存しています。意図して出力を変更した場合は、`test/mytest/bundle/fixtures/`をカレントディレクトリにして次のコマンドで更新し、差分を確認してください。テスト実行時には期待値を更新しません。

```sh
python3 ../../../../scripts/bundle.py plain.cpp > ../snapshots/plain.cpp
python3 ../../../../scripts/bundle.py includes.cpp -I include > ../snapshots/includes.cpp
```

[AtCoder生成AI対策ルール（20261014版）](https://info.atcoder.jp/entry/llm-rules-ja)では、生成AIで作成されたコードを利用する場合、コンテスト開始前のWeb公開と参照URLの添付が必要です。GitHubで事前公開したライブラリは、リポジトリへのリンクを提出コードに含めればよく、ファイルごとのリンクは不要とされています。このスクリプトはURLを付けるだけなので、使用するコードは別途コンテスト開始前に公開してください。他のリポジトリのコードを含める場合は、その出典も別途記載してください。

## ランダムテスト

`scripts/randtest.py` は、提出する解と愚直解に同じランダムな入力を与え、出力が食い違う入力（反例）を探します。[AtCoder のランダムテストの解説記事](https://info.atcoder.jp/entry/algorithm_lectures/randomtest)の方法1を自動化したものです。

### 準備

PATH の通ったディレクトリにシンボリックリンクを作ると、どこからでも `randtest` で呼び出せます。Python 3.8 以上と g++ が必要で、追加のパッケージは不要です。

```sh
ln -s /path/to/compro_library/scripts/randtest.py ~/.local/bin/randtest
```

### 使い方

提出する解 `main.cpp`、愚直解 `naive.cpp`、入力生成器 `gen.cpp` を用意して実行します。生成器の雛形は `randtest --init` で `gen.cpp` に書き出せます。既に存在するファイルは上書きしません。

```sh
randtest --init                                  # gen.cpp の雛形を作る
randtest -m main.cpp -n naive.cpp -g gen.cpp     # seed 0, 1, ..., 999 で比較する
```

3つのファイルは `-m`（提出する解）、`-n`（愚直解）、`-g`（生成器）で指定し、オプションの順番は自由です。オプションを付けずに並べることもできます。その場合は、オプションで指定しなかった役割を「提出する解、愚直解、生成器」の順に埋めます。次のコマンドはどれも同じ意味です。

```sh
randtest -g gen.cpp -n naive.cpp -m main.cpp
randtest main.cpp naive.cpp gen.cpp
randtest -g gen.cpp main.cpp naive.cpp
```

生成器は `gen <seed>` として呼ばれ、1つの入力を標準出力に書きます。[生成器ライブラリ](docs/random/gen/all.md)の `Random(argc, argv)` を使えば、この規約どおりに `argv[1]` を seed として読めます。木やグラフ、順列などを生成する関数もこのライブラリにあります。

C++ のソースは、ライブラリのルートを include パスに加えて `g++ -std=c++17 -O2` でコンパイルします。結果はカレントディレクトリの `.randtest/build/` にキャッシュし、ソースか include したヘッダが更新されたときだけ再コンパイルします。拡張子が `.py` のファイルは `python3` で、それ以外は実行ファイルとしてそのまま実行します。

各 seed について、2つの解の出力を空白区切りのトークン列として比較します。出力が食い違うか、どちらかが実行時エラー（終了コードが0以外）や時間切れになると、その入力を反例として報告して終了します。報告には、入力、各解の結果（`OK`・`RE`・`TLE`）、最初に食い違ったトークン、出力の差分が含まれます。反例は `randtest_fail/` に保存され、`in.txt`（入力）、`out_main.txt`・`out_naive.txt`（出力）、`stderr_main.log`・`stderr_naive.log`（標準エラー出力）、`info.txt`（seed、各解の結果、最初の食い違い、再現コマンド）が残ります。`--checker` を使った場合は `checker.log` も残ります。標準エラー出力は画面に表示せず、比較もしません。デバッグ出力を残したままでも使え、内容は `.log` ファイルで確認できます。`.log` ファイルは空でも必ず両方作ります。

```sh
randtest -m main.cpp -n naive.cpp -g gen.cpp --replay 42   # seed 42 の入力と両方の出力を表示し、randtest_fail/ に保存する
```

主なオプションは次のとおりです。詳しい説明と使用例は `randtest -h` で表示できます。ヘルプは日本語と英語の両方があり、`--help-ja` と `--help-en` で選べます。`-h` の言語は環境変数 `RANDTEST_LANG`（`ja` または `en`）で決まり、未設定ならロケールに従います。普段から日本語で表示するには、シェルの設定に `export RANDTEST_LANG=ja` を追加してください。

| オプション | 意味 |
| --- | --- |
| `-m FILE`, `-n FILE`, `-g FILE` | 提出する解、愚直解、生成器（`--main`, `--naive`, `--gen` とも書ける） |
| `-c N` | 試すケース数。`0` なら無制限（既定値は 1000） |
| `--start S` | 最初の seed（既定値は 0） |
| `--time SEC` | 指定した秒数が経過したら終了する。`0` なら制限なし |
| `--timeout SEC` | 1回の実行の制限時間（既定値は 2 秒）。`--interactor` では対話全体の制限時間 |
| `--exact` | トークン単位ではなく、出力をバイト列として完全一致で比較する |
| `--no-exact` | トークン単位で比較する（設定ファイルの `"exact": true` を打ち消す） |
| `--float EPS` | 実数のトークンは、絶対誤差か相対誤差が `EPS` 以下なら一致とみなす |
| `--checker CHECKER` | 比較の代わりにチェッカーで `main` の出力を判定する。`-n` は省略できる |
| `--interactor INTERACTOR` | インタラクティブ問題として、`main` をインタラクタと対話させて判定する。`-n` は省略できる |
| `--replay SEED` | 指定した seed だけを実行し、入力と出力を表示する |
| `-o DIR` | 反例の保存先（既定値は `randtest_fail`） |
| `--cxx`, `--cxxflags`, `-I DIR` | コンパイラ、コンパイルオプション、追加の include パス |

終了コードは、すべて一致すれば `0`、反例が見つかれば `1`、コンパイルエラーや生成器の異常終了など準備の段階で失敗すれば `2` です。深い再帰で落ちないよう、実行時はスタックサイズの上限をハードリミットまで引き上げます。インタラクティブ問題は `--interactor` で扱えます（[後述](#インタラクティブ問題)）。

### 誤差を許す比較とチェッカー

答えが実数の問題では `--float EPS` を付けます。実数のトークン x（`main`）と y（`naive`）は、|x − y| ≤ EPS か |x − y| ≤ EPS·|y| を満たせば一致とみなします。ただし、両方が整数の形のトークン（`1000000` と `1000001` など）と、単語などの数でないトークンは完全一致で比べます。

```sh
randtest -m main.cpp -n naive.cpp -g gen.cpp --float 1e-6
```

正解が複数ある問題では `--checker CHECKER` を使います。入力ごとに次のコマンドを実行し、終了コードが 0 なら合格、それ以外（異常終了と時間切れを含む）なら反例とします。引数の順は testlib のチェッカーと同じです。

```sh
CHECKER <入力ファイル> <main の出力> <naive の出力>
```

`-n` は省略でき、そのときは3番目のファイルが空になります。愚直解を渡すと、チェッカーは最適値などをその答えから読み取れます。チェッカーが標準出力・標準エラー出力に書いた内容は、不合格の理由として表示し、`randtest_fail/checker.log` に保存します。`randtest --init --checker check.cpp` を実行すると、生成器の雛形と一緒にチェッカーの雛形も `check.cpp` に書き出します（設定ファイルに `checker` がある場合も同様です）。雛形は、生成器の雛形と組み合わせてそのまま動く「最大の要素の添字（1始まり）を1つ出力する」問題用のチェッカーです。入力を読む、出力を読んで検証する、最適性を確かめる、余分な出力がないか確かめる、の4段階に分かれているので、問題に合わせて書き換えて使います。不合格は `wrong("理由")`（終了コード 1）で返し、愚直解の答えが矛盾するなどチェッカー自身の前提が崩れた場合は終了コード 3 で終了します。

同じ問題のチェッカーを最小限に書くと次のようになります。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(int, char **argv) {
    ifstream in(argv[1]), out(argv[2]);  // argv[3] は naive の出力 (-n がなければ空)
    int n;
    in >> n;
    vector<long long> a(n);
    for(auto &x : a) in >> x;
    long long best = *max_element(a.begin(), a.end());
    int k;
    if(!(out >> k) || k < 1 || k > n) {
        cout << "invalid index\n";
        return 1;
    }
    if(a[k - 1] != best) {
        cout << "a[" << k << "] = " << a[k - 1] << " is not the maximum " << best << "\n";
        return 1;
    }
}
```

```sh
randtest -m main.cpp -g gen.cpp --checker check.cpp            # 愚直解なし
randtest main.cpp gen.cpp --checker check.cpp                  # 同じ（FILE は main, gen の順）
randtest -m main.cpp -n naive.cpp -g gen.cpp --checker check.cpp
```

`--exact`、`--float`、`--checker`、`--interactor` は同時に指定できません。

### インタラクティブ問題

インタラクティブ問題では、`--interactor INTERACTOR` で、提出する解をインタラクタ（ジャッジ役のプログラム）と対話させます。`randtest` は入力ごとに次のコマンドを実行し、インタラクタの標準入力と標準出力を `main` の標準出力と標準入力につなぎます。引数の順は testlib のインタラクタと同じです。

```sh
INTERACTOR <入力ファイル> <出力ファイル>
```

このとき生成器が出力するのは、`main` への入力ではなく、インタラクタだけが読む隠された入力（当てるべき数など）です。`main` に知らせてよい情報（N など）は、インタラクタが `main` に送ります。`main` が正常終了し、インタラクタが終了コード 0 で終われば合格です。それ以外の終了コード、異常終了、時間切れは、どちらのプログラムで起きても反例になります。不合格の理由は、インタラクタが標準エラー出力に書きます。インタラクタが出力ファイルに書いた内容（質問の回数など）は `interactor_out_main.txt` に保存します。

`randtest --init --interactor judge.cpp` を実行すると、組み合わせてそのまま動く生成器（`gen.cpp`）とインタラクタ（`judge.cpp`）の雛形を書き出します。題材は「隠された数 x（1 ≤ x ≤ N）を当てる」問題です。`main` は最初に N を受け取ります。`? y` と質問すると、x ≤ y なら `1`、そうでなければ `0` が返ってきます。質問は ⌈log₂ N⌉ 回までで、最後に `! x` で答えます。インタラクタの雛形は、隠された入力を読む、`main` に情報を送る、質問に答える、余分な出力がないか確かめる、の4段階に分かれています。

```sh
randtest --init --interactor judge.cpp                  # gen.cpp と judge.cpp の雛形を作る
randtest -m main.cpp -g gen.cpp --interactor judge.cpp
randtest main.cpp gen.cpp --interactor judge.cpp        # 同じ（FILE は main, gen の順）
```

`randtest` は2つのプログラムの間に入ってすべてのバイトを中継し、やり取りとして記録します。反例では、各プログラムの結果、やり取り、インタラクタのメッセージを表示します。

```text
found a counterexample (seed 2)
--- input (read only by the interactor) ---
10 8
main: OK, interactor: rejected (exit code 1)
--- transcript of main (< from the interactor, > from main) ---
< 10
> ? 5
< 0
> ? 8
< 1
> ? 6
< 0
> ! 7
--- interactor message ---
answered 7, but x = 8
```

`<` の行はインタラクタから `main` へ、`>` の行は `main` からインタラクタへのメッセージです。インタラクタが終了した後に `main` が送ったデータは `[not delivered: the receiver had exited]` と記録します。最後が改行で終わらないメッセージには `[no newline]` が付きます。やり取りが長いときは、先頭と末尾だけを表示します。各方向で 1 MiB を超えた分は記録しませんが、中継は続けます。反例は `randtest_fail/` に保存し、`in.txt`（隠された入力）、`transcript_main.txt`（やり取り）、`stderr_main.log`（`main` の標準エラー出力）、`interactor_main.log`（インタラクタの標準エラー出力）、`interactor_out_main.txt`（インタラクタの出力ファイル）、`info.txt` が残ります。

`--timeout` は対話全体の制限時間です。時間切れのときは、どちらがまだ動いていたか、最後にどちらがメッセージを送ったかから、原因の候補を `hint:` として表示します。よくある原因は、`main` が出力を flush し忘れていることです。`cin` は読み込みのたびに `cout` を flush するので、普段は `endl` を書かなくても動きます。しかし、`template/template.cpp` のように `cin.tie(nullptr)` とすると自動では flush されなくなり、対話が止まります。この場合は次のように表示されるので、`endl` か `cout.flush()` を使ってください。

```text
main: TLE (> 2.0s), interactor: TLE (> 2.0s)
--- transcript of main (< from the interactor, > from main) ---
< 12
hint: main did not reply to the last message of the interactor; did main flush its output? (cin.tie(nullptr) stops cin from flushing cout) Otherwise main is too slow
```

Python の解も同じで、`print(..., flush=True)` が必要です。ジャッジと同じ条件で確かめるため、`randtest` が出力のバッファリングを無効にすることはありません。

`-n` で愚直解を渡すと、愚直解もインタラクタと対話させます。愚直解は必ず合格するはずです。不合格になった場合は、インタラクタ・生成器・愚直解のどれかが誤っているとみなし、`naive failed against the interactor` と表示して終了コード 2 で終了します。インタラクタを書き換えたときの確認に使えます。

返答を乱択で変えるインタラクタ（適応的なインタラクタ）は、乱数の seed を入力ファイルから読んでください。生成器が seed を隠された入力に書いておけば、同じ seed からは常に同じ対話になり、`--replay` で再現できます。

### 設定ファイル

コマンドを実行したディレクトリに `randtest.json` があると、その内容をオプションの既定値として読み込みます。問題ごとのディレクトリに置いておけば、`randtest` だけでテストを始められます。

```json
{
  "main": "main.cpp",
  "naive": "naive.cpp",
  "gen": "gen.cpp",
  "count": 5000,
  "timeout": 5,
  "cxxflags": "-std=c++17 -O2 -g -fsanitize=address,undefined"
}
```

キーはオプションの名前と同じで、すべて省略できます。

| キー | 型 | 対応するオプション |
| --- | --- | --- |
| `main`, `naive`, `gen` | 文字列 | `-m`, `-n`, `-g` |
| `count`, `start` | 整数 | `-c`, `--start` |
| `time` | 数値または `null`（`0` と `null` は制限なし） | `--time` |
| `timeout` | 正の数値 | `--timeout` |
| `exact` | `true` / `false` | `--exact`, `--no-exact` |
| `float` | 数値または `null` | `--float` |
| `checker` | 文字列 | `--checker` |
| `interactor` | 文字列 | `--interactor` |
| `out`, `cxx`, `cxxflags` | 文字列 | `-o`, `--cxx`, `--cxxflags` |
| `include` | 文字列のリスト | `-I` |

コマンドラインで指定した値は設定ファイルより優先します。位置引数のファイルも、設定ファイルの `main`・`naive`・`gen` より優先します。例えば設定ファイルに3つのファイルが書いてあっても、`randtest -m other.cpp` なら提出する解だけを差し替えて実行します。`-I` だけは上書きせず、`include` のリストに追加します。

未知のキー、型の誤り、JSON の構文エラーは、ファイル名を添えたエラー（終了コード 2）になります。読み込んだときは、標準エラー出力に `randtest: using settings in randtest.json` と表示します。`randtest --init` は雛形を書き出すだけで、設定ファイルの `main`・`naive`・`gen` は使いません（`checker` があればチェッカーの雛形も作ります）。

### 動作確認

動作確認用のテストは、リポジトリのルートで次のコマンドを実行します。CI でも同じテストを実行します。

```sh
python3 -m unittest discover -s test/mytest/randtest -v
```
