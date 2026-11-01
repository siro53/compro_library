# compro_library
競技プログラミングで使うライブラリ群

[![Actions Status](https://github.com/siro53/compro_library/workflows/verify/badge.svg)](https://github.com/siro53/compro_library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://siro53.github.io/compro_library/)

## マージ前のドキュメント確認

このリポジトリ内のブランチから PR を作ると、`Pages preview` ワークフローがドキュメントを生成し、次の URL に公開します。Draft PR でも利用できます。

```text
https://siro53.github.io/compro_library/pr-preview/pr-<PR番号>/
```

PR にプレビューへのリンクが自動でコメントされます。ブランチへ push すると更新され、PR を閉じるかマージすると削除されます。コメント掲載後、GitHub Pages のビルドが完了するまでは反映に時間がかかります。

プレビューは表示確認用で、テストは別の `verify` ワークフローで実行します。そのため、プレビュー内の検証ステータスはその PR の最新テスト結果とは限りません。フォークからの PR は対象外です。

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
