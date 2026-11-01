---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/initialization-and-monoids.test.cpp
    title: test/mytest/data-structure/initialization-and-monoids.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/and.hpp\"\n\ntemplate <typename T>\
    \ struct MonoidAND {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return (l & r); }\n    inline static T e() { return T(~T(0));\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct MonoidAND {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return (l & r); }\n \
    \   inline static T e() { return T(~T(0)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/and.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/data-structure/initialization-and-monoids.test.cpp
documentation_of: data-structure/monoid/and.hpp
layout: document
title: "\u30D3\u30C3\u30C8 AND\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidAND<T>` は、左右の値の bit ごとの AND を取ります。単位元は T の全 bit が立った値で、一般の整数マスクを集約できます。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では2つの bit マスクの共通部分を取り、単位元と結合してもマスクが変わらないことを確認します。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/and.hpp"

int main() {
    using M = MonoidAND<unsigned>;
    assert(M::op(0b110U, 0b101U) == 0b100U);
    assert(M::op(2U, M::e()) == 2U);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l & r を返す。 | O(1) |
| `e()` | 全 bit が立った単位元 T(~T(0)) を返す。 | O(1) |

## 利用条件と実装上の注意

T は整数型を使ってください。符号なし整数型では単位元がその型の最大値です。bool の場合は true になります。空区間の結果もこの単位元なので、整数型で0/1のみを扱う場合でも空区間の結果が1とは限りません。
