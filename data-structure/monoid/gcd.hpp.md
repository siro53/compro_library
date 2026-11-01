---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/monoids.test.cpp
    title: test/mytest/data-structure/monoids.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/gcd.hpp\"\n\n#include <numeric>\n\n\
    template <typename T> struct MonoidGCD {\n    using value_type = T;\n    inline\
    \ static T op(const T& l, const T& r) {\n        return std::gcd(l, r);\n    }\n\
    \    inline static T e() { return T(0); }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n\ntemplate <typename T> struct MonoidGCD\
    \ {\n    using value_type = T;\n    inline static T op(const T& l, const T& r)\
    \ {\n        return std::gcd(l, r);\n    }\n    inline static T e() { return T(0);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/gcd.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/data-structure/monoids.test.cpp
documentation_of: data-structure/monoid/gcd.hpp
layout: document
title: "\u6700\u5927\u516C\u7D04\u6570\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidGCD<T>` は区間内の整数の最大公約数を集約します。$\gcd(a,0)=|a|$ なので、非負整数を対象にすれば $0$ を単位元として使えます。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では $\gcd(12,18)=6$ を求めています。セグメント木に載せれば、配列の値を更新しながら任意区間の最大公約数を取得できます。単位元の $0$ は「何も集約していない状態」と考えると自然です。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/gcd.hpp"

int main() {
    using M = MonoidGCD<long long>;
    assert(M::op(12, 18) == 6);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | gcd(l,r) を返す。 | O(log M)、M=max(abs(l),abs(r))+1 |
| `e()` | 単位元 0 を返す。 | O(1) |

## 利用条件と実装上の注意

モノイドとして使う値は非負整数にしてください。`std::gcd` 自体は負数にも対応しますが、負数を含む集合では `op(a,0)=a` が成立しません。表の $M$ は2入力の絶対値の最大値に1を加えた値です。gcd の計算にも $O(\log M)$ 時間がかかるため、セグメント木の操作も一般には $O(\log N\log M)$ になります。
