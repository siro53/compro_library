- このページは競技プログラミング用のスニペットを集めたページです。
- 動作環境はc++17(gcc)を仮定しています。
- バグ等を発見しましたら、[GitHubのissue](https://github.com/siro53/compro_library/issues)にご一報下さるととても喜びます！
- コピペ等ご自由にどうぞ。

<details markdown="1">
<summary>出典コメント付きでbundleするツール</summary>

[`scripts/bundle.py`](https://github.com/siro53/compro_library/blob/main/scripts/bundle.py)を使うと、`oj-bundle`による展開結果の先頭に出典コメントを自動で付けられます。

```cpp
// Source: https://github.com/siro53/compro_library
```

`online-judge-verify-helper`をインストールした環境で、`oj-bundle`の代わりに実行してください。`-I`などの引数はそのまま渡せます。

```sh
python3 /path/to/compro_library/scripts/bundle.py main.cpp -I /path/to/compro_library > bundled.cpp
```

入力ファイルと出力先は別にしてください。

[AtCoder生成AI対策ルール（20261014版）](https://info.atcoder.jp/entry/llm-rules-ja)への対応として利用する場合、出典コメントを付けるだけでなく、使用するコードをコンテスト開始前にWeb上で公開しておく必要があります。他のリポジトリのコードを含める場合は、その出典も別途記載してください。

</details>
