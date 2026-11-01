---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/monoids.test.cpp
    title: test/mytest/data-structure/monoids.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/segment-tree-api.test.cpp
    title: test/mytest/data-structure/segment-tree-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki789.test.cpp
    title: test/yukicoder/yuki789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/add.hpp\"\n\ntemplate <typename T>\
    \ struct MonoidAdd {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return (l + r); }\n    inline static T e() { return T(0);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct MonoidAdd {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return (l + r); }\n \
    \   inline static T e() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/add.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki789.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/mytest/data-structure/monoids.test.cpp
  - test/mytest/data-structure/segment-tree-api.test.cpp
documentation_of: data-structure/monoid/add.hpp
layout: document
title: "\u52A0\u7B97\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidAdd<T>` は区間の和を求めるためのモノイドです。演算は $a+b$、単位元は $0$ なので、左右の区間和を加えるだけで連結した区間の和になります。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では2つの値 $2,3$ を結合して $5$ を得ています。セグメント木に載せる場合は `Segtree<MonoidAdd<long long>>` のように指定すると、点更新と区間和の問い合わせができます。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/add.hpp"

int main() {
    using M = MonoidAdd<long long>;
    auto x = M::op(2, 3);
    assert(x == 5);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l+r を返す。 | O(1) |
| `e()` | 単位元 0 を返す。 | O(1) |

## 利用条件と実装上の注意

`T` は加算と $0$ の構築に対応する型を使ってください。符号付き整数では合計値のオーバーフローを避ける必要があります。浮動小数点の加算は丸めによって厳密には結合的でないため、集約順による誤差を許容する必要があります。
