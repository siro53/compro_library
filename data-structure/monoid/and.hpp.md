---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/and.hpp\"\n\ntemplate <typename T>\
    \ struct MonoidAND {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return (l & r); }\n    inline static T e() { return T(1);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct MonoidAND {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return (l & r); }\n \
    \   inline static T e() { return T(1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/and.hpp
  requiredBy: []
  timestamp: '2023-12-16 20:03:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/and.hpp
layout: document
title: "\u30D3\u30C3\u30C8 AND\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidAND<T>` は、左右の値の bit ごとの AND を取ります。ただし、この実装の単位元は $1$ であり、一般の整数全体を扱う AND モノイドにはなっていません。値を $0,1$ に限定した論理積として利用できます。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

0/1 の配列に使うと、区間の集約値が $1$ であることは「区間の全要素が $1$」と同値です。例では $1$ と $0$ の AND が $0$ になることを確認しています。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/and.hpp"

int main() {
    using M = MonoidAND<int>;
    assert(M::op(1, 0) == 0);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | l & r を返す。 | O(1) |
| `e()` | 単位元 1 を返す。 | O(1) |

## 利用条件と実装上の注意

一般の bit マスクで AND を集約する場合、単位元は対象の全 bit が立った値でなければなりません。たとえば現実装では `op(2,e())` が $0$ になり、単位元の条件を満たしません。その用途では `e()` を修正した別のモノイドを用意してください。
