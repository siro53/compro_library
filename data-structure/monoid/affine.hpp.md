---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/library-checker/data-structure/point-set-range-composite.cpp
    title: test/library-checker/data-structure/point-set-range-composite.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/affine.hpp\"\n\n#include <utility>\n\
    \ntemplate <typename T, bool rev = false> struct MonoidAffine {\n    using S =\
    \ std::pair<T, T>;\n    using value_type = S;\n    inline static S op(const S\
    \ &l, const S &r) {\n        if(rev) return S(r.first * l.first, r.first * l.second\
    \ + r.second);\n        return S(l.first * r.first, l.first * r.second + l.second);\n\
    \    }\n    inline static S e() { return S(T(1), T(0)); }\n};\n"
  code: "#pragma once\n\n#include <utility>\n\ntemplate <typename T, bool rev = false>\
    \ struct MonoidAffine {\n    using S = std::pair<T, T>;\n    using value_type\
    \ = S;\n    inline static S op(const S &l, const S &r) {\n        if(rev) return\
    \ S(r.first * l.first, r.first * l.second + r.second);\n        return S(l.first\
    \ * r.first, l.first * r.second + l.second);\n    }\n    inline static S e() {\
    \ return S(T(1), T(0)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/affine.hpp
  requiredBy:
  - test/library-checker/data-structure/point-set-range-composite.cpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
documentation_of: data-structure/monoid/affine.hpp
layout: document
title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidAffine<T,rev>` は、一次関数 $f(x)=ax+b$ を合成するためのモノイドです。関数を係数の pair $(a,b)$ として保存します。たとえば区間内に並んだ変換を順に適用する問題を、セグメント木上の区間集約として扱えます。

$f(x)=ax+b$、$g(x)=cx+d$ とすると、$(f\circ g)(x)=acx+ad+b$ です。恒等写像 $x\mapsto x$ が単位元で、その係数は $(1,0)$ になります。

## 使い方

既定の `rev=false` では `op(l,r)` が $l\circ r$、つまり右の関数を先に適用します。配列の左から右へ関数を適用したい場合は `rev=true` を指定してください。

例では $l(x)=2x+1$、$r(x)=3x+4$ なので、合成は $l(r(x))=6x+9$ です。関数の合成は一般に交換できないため、係数が正しくても合成順序を逆にすると別の答えになります。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/affine.hpp"

int main() {
    using M = MonoidAffine<long long>;
    auto f = M::op({2, 1}, {3, 4});
    assert(f.first == 6 && f.second == 9);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `op(l, r)` | rev=false は l∘r、true は r∘l。 | O(1) |
| `e()` | 恒等写像 (1,0)。 | O(1) |

## 利用条件と実装上の注意

`S/value_type` は `pair<T,T>` です。`T` は加算・乗算と $0,1$ の構築に対応する必要があります。整数で係数を持つ場合は中間積を含めたオーバーフローに注意し、剰余上の問題なら modint を使ってください。
