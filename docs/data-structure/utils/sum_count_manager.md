---
title: 値ごとの和・個数管理
documentation_of: //data-structure/utils/sum_count_manager.hpp
---

## このライブラリでできること

`SumCountManager<T>` は、追加され得る値をあらかじめ座標圧縮し、値ごとの合計と個数をセグメント木で管理する補助クラスです。たとえば値域を指定して、そこに含まれる要素数や総和を集約するための土台になります。候補値の個数を $K$ とします。

## 使い方

構築時には「最初に存在する要素」ではなく「今後追加する可能性がある値」を渡します。集計は空の状態から始まり、`add(x)` ごとに値 $x$ の位置の合計へ $x$、個数へ $1$ を加える設計です。

例では候補 $10,20$ を登録し、$10$ を1個追加した状態の総和と個数を取得する呼び出し形を示しています。`get(x)` は個数ではなく圧縮後の位置を返します。

```cpp
#include "template/template.cpp"
#include "data-structure/utils/sum_count_manager.hpp"

int main() {
    SumCountManager<long long> manager(vector<long long>{10, 20});
    manager.add(10);
    auto x = manager.seg.prod(0, 2);
    assert(x.sum == 10 && x.cnt == 1);
}
```

## API・計算量

この構成の空間計算量は $O(K)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SumCountManager(xs)` | 候補を圧縮し、空の集計木を作る。 | O(K log K) |
| `add(val)` | 登録済みの値を 1 個追加。 | O(log K) |
| `get(val)` | 候補配列の lower_bound の位置。 | O(log K) |

## 利用条件と実装上の注意

公開型 S は `MonoidSumCount<T,int>::S` で、sum と cnt を持つ集約値です。引数なしの構築では候補が空なので、値を追加する前に候補付きのオブジェクトを代入してください。

`add` に渡す値は構築時の候補に含めてください。公開メンバ `comp` が圧縮表、`seg` が集計木です。値域を問い合わせる際は、値の両端を圧縮表で添字へ変換し、その添字区間を `seg.prod` に渡します。
