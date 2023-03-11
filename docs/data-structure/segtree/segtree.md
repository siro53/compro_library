---
title: Segment Tree
documentation_of: //data-structure/segtree/segtree.hpp
---

## 使い方
このライブラリを使う際には、Monoid 構造体をテンプレート引数に渡して使う必要がある。

Monoid 構造体は次のようなものを実装する必要がある：

```cpp
template <typename T>
struct Monoid {
    using value_type = T; // value_type メンバからモノイドの型の情報を取ってきているため、これがないとエラーになる
    static T op(const T& l, const T& r) { return (l と r を演算した結果); } // static メンバ関数である必要がある
    static T e() { return (単位元); } // static メンバ関数である必要がある
};
```

要するに、ACLで言う所の`S, op(), e()`を構造体にまとめているだけ。

このデータ構造の設計は [代数的構造を乗せるデータ構造の設計について(noshi91さんの記事)](https://noshi91.hatenablog.com/entry/2020/04/22/212649) を参考にした。

このような設計にすることで、よく使うモノイドをモノイド構造体のみでライブラリ化出来るようになるので管理しやすくなるはず。

よく使うモノイドは`data-structure/monoid/`以下で管理している。