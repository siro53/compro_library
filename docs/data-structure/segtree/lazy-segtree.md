---
title: Lazy Segment Tree
documentation_of: //data-structure/segtree/lazy-segtree.hpp
---

## 使い方
このライブラリを使う際には、MonoidAct 構造体をテンプレート引数に渡して使う必要がある。

MonoidAct 構造体は次のようなものを実装する必要がある：

```cpp
template <class S, class F>
struct MonoidAct {
    using value_type_S = S;
    using value_type_F = F;
    static S op(const S& l, const S& r);
    static S e();
    static S mapping(const F& f, const S& x);
    static F composition(const F& f, const F& g);
    static F id();
};
```

各メンバの使い方や型の意味は [ac-library](https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html) に準拠する

よく使うモノイドと作用素の組み合わせは `data-structure/monoidact` 以下にまとめる予定
