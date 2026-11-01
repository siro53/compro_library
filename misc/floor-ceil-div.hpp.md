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
  bundledCode: "#line 2 \"misc/floor-ceil-div.hpp\"\n\ntemplate <typename T> T ceil_div(T\
    \ a, T b) {\n    if(b < 0) a = -a, b = -b;\n    return (a >= 0 ? (a + b - 1) /\
    \ b : a / b);\n}\n\ntemplate <typename T> T floor_div(T a, T b) {\n    if(b <\
    \ 0) a = -a, b = -b;\n    return (a >= 0 ? a / b : (a - b + 1) / b);\n}\n"
  code: "#pragma once\n\ntemplate <typename T> T ceil_div(T a, T b) {\n    if(b <\
    \ 0) a = -a, b = -b;\n    return (a >= 0 ? (a + b - 1) / b : a / b);\n}\n\ntemplate\
    \ <typename T> T floor_div(T a, T b) {\n    if(b < 0) a = -a, b = -b;\n    return\
    \ (a >= 0 ? a / b : (a - b + 1) / b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/floor-ceil-div.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/floor-ceil-div.hpp
layout: document
title: "\u6574\u6570\u306E\u5207\u308A\u4E0A\u3052\u30FB\u5207\u308A\u6368\u3066\u9664\
  \u7B97"
---

## このライブラリでできること

`floor_div(a,b)` と `ceil_div(a,b)` は、負数も含めて数学的な切り捨て・切り上げ除算を行います。返す値はそれぞれ $\lfloor a/b\rfloor$ と $\lceil a/b\rceil$ です。

C++の符号付き整数除算は0に近づく方向へ丸めるため、負の商では床関数と一致しません。この違いを意識せずに使いたい場合の補助関数です。

## 使い方

例では $-7/3=-2.33\ldots$ なので、床は $-3$、天井は $-2$ になります。分母が負でも、その符号をそろえて同じ定義で計算します。両引数は同じ符号付き整数型で渡してください。

```cpp
#include "template/template.cpp"
#include "misc/floor-ceil-div.hpp"

int main() {
    assert(floor_div(-7LL, 3LL) == -3);
    assert(ceil_div(-7LL, 3LL) == -2);
}
```

## API・計算量

必要な追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `floor_div(a,b)` | floor(a/b)。 | O(1) |
| `ceil_div(a,b)` | ceil(a/b)。 | O(1) |

## 利用条件と実装上の注意

分母は0にできません。実装は符号反転や `a+b-1`、`a-b+1` を使うため、最終的な答えだけでなくこれらの中間値も型に収まる必要があります。特に型の最小負値の符号反転には注意してください。
