---
title: Mo's Algorithm
documentation_of: ../../data_structure/mo.hpp
---

# Mo's Algorithm
## 内容
- [ei1333の日記](https://ei1333.hateblo.jp/entry/2017/09/11/211011)を参考に作成
- 区間を伸縮させる際、左と右に伸ばす/縮める時でそれぞれ処理が違う場合にも対応。

## 使い方
- `Mo(N)`: 区間$[0, N)$に対するオフラインクエリを処理する
- `insert(l, r)`: クエリ$[l, r)$を追加
- `build()`: クエリをsortして並べ替える。クエリを全て追加したらこれを呼ぶこと。
- `process()`: クエリを1つ分だけ進める。クエリのidが返って来る
- `add_left(id)`: 左に伸ばす(idを現在見ている区間に追加する)処理
- `add_right(id)`: 右に伸ばす(idを現在見ている区間に追加する)処理
- `del_left(id)`: 左から縮める(idを現在見ている区間から削除する)処理
- `del_right(id)`: 右から縮める(idを現在見ている区間から削除する)処理

使う際には、問題に応じて`add_left(id)`, `add_right(id)`, `del_left(id)`, `del_right(id)`に自分で処理を書く