# compro_library
競技プログラミングで使うライブラリ群

[![Actions Status](https://github.com/siro53/compro_library/workflows/verify/badge.svg)](https://github.com/siro53/compro_library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://siro53.github.io/compro_library/)

## 出典付きでbundleする

`oj-bundle` の代わりに `scripts/bundle.py` を使うと、展開結果の先頭に次のコメントを付けます。

```cpp
// Source: https://github.com/siro53/compro_library
```

`online-judge-verify-helper` をインストールした環境で実行してください。引数は `oj-bundle` にそのまま渡されます。

```sh
python3 /path/to/compro_library/scripts/bundle.py main.cpp -I /path/to/compro_library > bundled.cpp
```

エディタなどから呼び出している場合も、`oj-bundle` の部分を `python3 /path/to/compro_library/scripts/bundle.py` に置き換えてください。bundleに失敗した場合は非ゼロで終了し、標準出力には何も出力しません。入力ファイルと出力先は別にしてください。

[AtCoder生成AI対策ルール（20261014版）](https://info.atcoder.jp/entry/llm-rules-ja)では、生成AIで作成されたコードを利用する場合、コンテスト開始前のWeb公開と参照URLの添付が必要です。GitHubで事前公開したライブラリは、リポジトリへのリンクを提出コードに含めればよく、ファイルごとのリンクは不要とされています。このスクリプトはURLを付けるだけなので、使用するコードは別途コンテスト開始前に公開してください。他のリポジトリのコードを含める場合は、その出典も別途記載してください。
