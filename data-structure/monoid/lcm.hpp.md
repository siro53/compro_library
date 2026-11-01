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
  bundledCode: "#line 2 \"data-structure/monoid/lcm.hpp\"\n\n#include <numeric>\n\n\
    template <typename T> struct MonoidLCM {\n    using value_type = T;\n    inline\
    \ static T op(const T& l, const T& r) {\n        return std::lcm(l, r);\n    }\n\
    \    inline static T e() { return T(1); }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n\ntemplate <typename T> struct MonoidLCM\
    \ {\n    using value_type = T;\n    inline static T op(const T& l, const T& r)\
    \ {\n        return std::lcm(l, r);\n    }\n    inline static T e() { return T(1);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/lcm.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/lcm.hpp
layout: document
title: "\u6700\u5C0F\u516C\u500D\u6570\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidLCM<T>` は区間内の非負整数の最小公倍数を集約します。$\operatorname{lcm}(a,1)=a$ なので単位元は $1$ です。周期が異なる複数の事象について、共通の周期を求める場面などで使えます。

モノイド用の型は、値の型 `value_type`、2つの区間を結合する `op`、空区間を表す `e()` を提供します。`Segtree` などのテンプレート引数に渡して使います。

## 使い方

例では $4$ と $6$ の最小公倍数 $12$ を求めています。区間を結合する際は、その左右の最小公倍数をもう一度 lcm に渡せばよいため、セグメント木の集約として利用できます。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/lcm.hpp"

int main() {
    using M = MonoidLCM<long long>;
    assert(M::op(4, 6) == 12);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | lcm(l,r) を返す。 | O(log M)、M=max(abs(l),abs(r))+1 |
| `e()` | 単位元 1 を返す。 | O(1) |

## 利用条件と実装上の注意

非負整数を扱い、結果が `T` に収まることを確認してください。最小公倍数は入力より急速に大きくなり得ます。表の $M$ は2入力の絶対値の最大値+1です。lcm は gcd の計算を含むため $O(\log M)$ 時間であり、一般の整数演算と同じ定数時間とは限りません。
