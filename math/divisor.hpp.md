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
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\n#include <algorithm>\n#include <type_traits>\n\
    #include <vector>\n\ntemplate <typename T, std::enable_if_t<std::is_integral<T>::value,\
    \ int> = 0>\nstd::vector<T> divisor(T n) {\n    std::vector<T> ret;\n    for(T\
    \ i = 1; i * i <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n\
    \            if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\
    \ntemplate <typename T, std::enable_if_t<std::is_integral<T>::value, int> = 0>\n\
    std::vector<T> divisor(T n) {\n    std::vector<T> ret;\n    for(T i = 1; i * i\
    \ <= n; i++) {\n        if(n % i == 0) {\n            ret.push_back(i);\n    \
    \        if(i * i != n) ret.push_back(n / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2023-12-05 16:32:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---

## このライブラリでできること

`divisor(n)` は、正整数 $n$ を割り切る正整数を小さい順に列挙します。たとえば $12$ の約数は $1,2,3,4,6,12$ です。約数を順に試す問題や、積の分け方を列挙する場合に使えます。

$d$ が約数なら $n/d$ も約数なので、$\sqrt n$ 以下だけを調べれば両方を見つけられます。約数の個数を $D$ とすると、探索と最後のソートを合わせて $O(\sqrt n+D\log D)$ 時間です。

## 使い方

整数を渡すと、その整数型の `vector` が返ります。例では $12$ の約数が昇順で格納されることを確認しています。$n$ が平方数の場合も、$\sqrt n$ は重複して返されません。

```cpp
#include "template/template.cpp"
#include "math/divisor.hpp"

int main() {
    auto ds = divisor(12);
    assert((ds == vector<int>{1, 2, 3, 4, 6, 12}));
}
```

## API・計算量

返り値を含めて $O(D)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `divisor(n)` | vector<T> で全約数を返す。 | O(sqrt(n)+D log D) |

## 利用条件と実装上の注意

引数は整数型で $n\ge1$ としてください。$0$ や負数の約数列挙は対象外です。ループ条件で `i*i` を計算するため、この中間積も型の範囲に収まる必要があります。
