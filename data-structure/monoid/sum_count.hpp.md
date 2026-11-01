---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/utils/sum_count_manager.hpp
    title: "\u5024\u3054\u3068\u306E\u548C\u30FB\u500B\u6570\u7BA1\u7406"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/basic-api.test.cpp
    title: test/mytest/data-structure/basic-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/helper-regressions.test.cpp
    title: test/mytest/data-structure/helper-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/monoids.test.cpp
    title: test/mytest/data-structure/monoids.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/sum_count.hpp\"\n\ntemplate <typename\
    \ sum_t, typename count_t> struct MonoidSumCount {\n    struct S {\n        sum_t\
    \ sum;\n        count_t cnt;\n        S() = default;\n        S(sum_t sum, count_t\
    \ cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type = S;\n    inline static\
    \ S op(const S& l, const S& r) {\n        return S(l.sum + r.sum, l.cnt + r.cnt);\n\
    \    }\n    inline static S e() { return S(sum_t(0), count_t(0)); }\n};\n"
  code: "#pragma once\n\ntemplate <typename sum_t, typename count_t> struct MonoidSumCount\
    \ {\n    struct S {\n        sum_t sum;\n        count_t cnt;\n        S() = default;\n\
    \        S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type\
    \ = S;\n    inline static S op(const S& l, const S& r) {\n        return S(l.sum\
    \ + r.sum, l.cnt + r.cnt);\n    }\n    inline static S e() { return S(sum_t(0),\
    \ count_t(0)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/sum_count.hpp
  requiredBy:
  - data-structure/utils/sum_count_manager.hpp
  timestamp: '2025-12-21 17:21:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/data-structure/monoids.test.cpp
  - test/mytest/data-structure/basic-api.test.cpp
  - test/mytest/data-structure/helper-regressions.test.cpp
documentation_of: data-structure/monoid/sum_count.hpp
layout: document
title: "\u548C\u30FB\u500B\u6570\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidSumCount<sum_t,count_t>` は、値の合計と要素数を組にして集約します。たとえば、値ごとの出現回数を管理して「この値域に何個あり、合計はいくつか」を同時に求めたい場合に使えます。

集約値 `S` は `sum` と `cnt` を持ち、結合は $(s_1,c_1)\circ(s_2,c_2)=(s_1+s_2,c_1+c_2)$、単位元は $(0,0)$ です。和と個数に異なる整数型を指定できます。

## 使い方

値 $x$ が $c$ 個あることを表すなら `S(x*c,c)` を使います。例では合計 $5$・個数 $1$ の区間と、合計 $6$・個数 $2$ の区間を結合し、合計 $11$・個数 $3$ を得ています。`sum` は1個あたりの値ではなく、すでに合計した値です。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/sum_count.hpp"

int main() {
    using M = MonoidSumCount<long long, int>;
    auto x = M::op(M::S(5, 1), M::S(6, 2));
    assert(x.sum == 11 && x.cnt == 3);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `S(sum, cnt)` | 集約値を構築。デフォルト構築は未初期化。 | O(1) |
| `op(l, r)` | sum と cnt をそれぞれ加算。 | O(1) |
| `e()` | (0,0)。 | O(1) |

## 利用条件と実装上の注意

デフォルト構築した `S` のメンバは未初期化です。葉や初期値には引数付きコンストラクタまたは `e()` を使ってください。合計値・個数とその中間演算が、それぞれの型に収まる必要があります。
