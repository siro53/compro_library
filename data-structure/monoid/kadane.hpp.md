---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://hotman78.hatenablog.com/entry/2020/06/17/102519
  bundledCode: "#line 2 \"data-structure/monoid/kadane.hpp\"\n\n#include <limits>\n\
    #include <algorithm>\n\n// ref: https://hotman78.hatenablog.com/entry/2020/06/17/102519\n\
    template <typename T> struct MonoidKadane {\n    struct S {\n        T lmax, rmax,\
    \ allmax, sum;\n        S() = default;\n        S(T lmax, T rmax, T allmax, T\
    \ sum)\n            : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}\n  \
    \  };\n    using value_type = S;\n    inline static S op(const S &l, const S &r)\
    \ {\n        T lmax = std::max(l.lmax, l.sum + r.lmax);\n        T rmax = std::max(r.rmax,\
    \ l.rmax + r.sum);\n        T allmax = std::max({l.allmax, r.allmax, l.rmax +\
    \ r.lmax});\n        T sum = l.sum + r.sum;\n        return S(lmax, rmax, allmax,\
    \ sum);\n    }\n    inline static S e() {\n        T m = std::numeric_limits<T>::min();\n\
    \        return S(m, m, m, T(0));\n    }\n};\n"
  code: "#pragma once\n\n#include <limits>\n#include <algorithm>\n\n// ref: https://hotman78.hatenablog.com/entry/2020/06/17/102519\n\
    template <typename T> struct MonoidKadane {\n    struct S {\n        T lmax, rmax,\
    \ allmax, sum;\n        S() = default;\n        S(T lmax, T rmax, T allmax, T\
    \ sum)\n            : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}\n  \
    \  };\n    using value_type = S;\n    inline static S op(const S &l, const S &r)\
    \ {\n        T lmax = std::max(l.lmax, l.sum + r.lmax);\n        T rmax = std::max(r.rmax,\
    \ l.rmax + r.sum);\n        T allmax = std::max({l.allmax, r.allmax, l.rmax +\
    \ r.lmax});\n        T sum = l.sum + r.sum;\n        return S(lmax, rmax, allmax,\
    \ sum);\n    }\n    inline static S e() {\n        T m = std::numeric_limits<T>::min();\n\
    \        return S(m, m, m, T(0));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/kadane.hpp
  requiredBy: []
  timestamp: '2023-09-22 12:39:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/kadane.hpp
layout: document
title: "\u6700\u5927\u90E8\u5206\u914D\u5217\u548C\u30E2\u30CE\u30A4\u30C9"
---

## このライブラリでできること

`MonoidKadane<T>` は、区間内にある非空の連続部分配列の和の最大値を集約する型です。長さ $N$ の配列なら、対象は $\max_{0\le l<r\le N}\sum_{i=l}^{r-1}A_i$ です。空の部分配列は含めないため、すべて負数なら答えも負数になります。

各区間について、最大の先頭部分和 `lmax`、最大の末尾部分和 `rmax`、最大部分配列和 `allmax`、区間全体の和 `sum` を持ちます。左右を連結した際の最適区間は、左だけ・右だけ・境界をまたぐ区間のいずれかなので、この4値から定数時間で結合できます。

## 使い方

1要素 $x$ を表す葉は `S(x,x,x,x)` です。例では $[2]$ と $[-1]$ を結合し、全体和は $1$、最大部分配列和は $[2]$ を選んだ $2$ になります。

ただし、現実装の単位元には後述のオーバーフロー問題があります。この例は実要素同士の結合を確認するもので、現在のままセグメント木へ安全に載せられることを示すものではありません。

```cpp
#include "template/template.cpp"
#include "data-structure/monoid/kadane.hpp"

int main() {
    using M = MonoidKadane<long long>;
    auto s = M::op(M::S(2, 2, 2, 2), M::S(-1, -1, -1, -1));
    assert(s.allmax == 2 && s.sum == 1);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `S(lmax, rmax, allmax, sum)` | 集約値を作る。デフォルト構築では各値は未初期化。 | O(1) |
| `op(l, r)` | 左右を連結した区間の集約値。 | O(1) |
| `e()` | (numeric_limits<T>::min(), 同左, 同左, 0)。 | O(1) |

## 利用条件と実装上の注意

数学的な単位元は、和を $0$、3種類の最大値を $-\infty$ とした状態です。実装では $-\infty$ の代わりに `numeric_limits<T>::min()` を使っていますが、それを通常の数として足すため、`op(e(),e())` などでも符号付きオーバーフローが発生します。

セグメント木で使う前に、空区間を明示的に区別するなどの実装修正が必要です。浮動小数点型の `min()` も負の無限大ではありません。また、`S()` のデフォルト構築はメンバを初期化しないため、すべての値を設定して使ってください。
