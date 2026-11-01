---
title: Mo のアルゴリズム
documentation_of: //misc/mo.hpp
link: https://ei1333.hateblo.jp/entry/2017/09/11/211011
---

## 概要

`Mo` は静的な配列の区間クエリを並べ替え、左右端の移動をコールバックへ通知する。N は配列長、Q はクエリ数、B はバケット幅。

空間 O(Q)。端点移動の総数は O(QB+N²/B+N)、B≈sqrt(N) なら O((N+Q)sqrt(N))。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Mo(n)` | 初期区間 [0,0)、幅 floor(sqrt(n)) で初期化。 | O(1) |
| `insert(l,r)` | [l,r) のクエリを追加。ID は追加順。 | 償却 O(1) |
| `set_bucketsize(bs)` | 幅を max(1,bs) に変更。 | O(1) |
| `build()` | 左端のバケット、右端の順にクエリをソート。 | O(Q log Q) |
| `process(add_left,add_right,del_left,del_right)` | 次のクエリに移動し ID を返す。終了時 -1。 | 移動距離×コールバックコスト |

## 前提・注意点

n>=1、`0<=l<r<=n`。全 insert 後に一度 build し、空区間の状態から process を繰り返す。通知引数は要素の添字。

現実装は右端を拡張する前に左端を削除するため、現在区間にまだ含まれていない要素への del が発生し得る。和のように負の途中状態を許す可逆な処理では使えるが、頻度非負を前提とする処理等はこの順序を修正する必要がある。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/mo.hpp"

int main() {
    vector<int> a{1, 2, 3, 4};
    Mo mo(4);
    mo.insert(1, 3); mo.insert(0, 4);
    mo.build();
    long long sum = 0;
    auto add = [&](int i) { sum += a[i]; };
    auto del = [&](int i) { sum -= a[i]; };
    vector<long long> ans(2);
    for (int id; (id = mo.process(add, add, del, del)) != -1;) ans[id] = sum;
    assert(ans[0] == 5 && ans[1] == 10);
}
```
