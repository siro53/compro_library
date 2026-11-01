---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-DSL-2-A.test.cpp
    title: test/aoj/aoj-DSL-2-A.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/monoids.test.cpp
    title: test/mytest/data-structure/monoids.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/min.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n\ntemplate <typename T, T INF = std::numeric_limits<T>::max()>\
    \ struct MonoidMin {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return std::min(l, r); }\n    inline static T e() { return\
    \ INF; }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\ntemplate <typename\
    \ T, T INF = std::numeric_limits<T>::max()> struct MonoidMin {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return std::min(l, r);\
    \ }\n    inline static T e() { return INF; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/min.hpp
  requiredBy: []
  timestamp: '2023-12-24 03:50:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/data-structure/monoids.test.cpp
  - test/aoj/aoj-DSL-2-A.test.cpp
documentation_of: data-structure/monoid/min.hpp
layout: document
title: "\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidMin<T,INF>` は区間の最小値を求めるモノイドです。左右の最小値の小さい方を取れば、連結した区間の最小値になります。単位元には、すべての値以上の `INF` を使います。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では $4,6$ の小さい方である $4$ を返します。`Segtree<MonoidMin<int>>` とすれば、各要素の更新と区間最小値の取得ができます。未設定の葉は `INF` になるため、最小値の候補には影響しません。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/min.hpp"

int main() {
    using M = MonoidMin<int>;
    assert(M::op(4, 6) == 4);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | min(l,r) を返す。 | O(1) |
| `e()` | 単位元 INF を返す。 | O(1) |

## 利用条件と実装上の注意

`INF` の既定値は `numeric_limits<T>::max()` です。独自の値を指定する場合も、すべての実データ以上になるようにしてください。C++17ではこの非型テンプレート引数に浮動小数点型を使えないため、整数型で利用します。
