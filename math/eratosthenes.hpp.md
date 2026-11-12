---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C_2.test.cpp
    title: test/aoj/aoj-ALDS1-1-C_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2858.test.cpp
    title: test/aoj/aoj2858.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/number-theory.test.cpp
    title: test/mytest/math/number-theory.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/eratosthenes.hpp\"\n\n#include <vector>\n\nclass Eratosthenes\
    \ {\n  public:\n    Eratosthenes() {}\n    explicit Eratosthenes(int n) : n(n),\
    \ isp(n + 1, true) {\n        isp[0] = isp[1] = false;\n        for(int i = 2;\
    \ i * i <= n; i++) {\n            if(!isp[i]) continue;\n            for(int j\
    \ = i * i; j <= n; j += i) isp[j] = false;\n        }\n    }\n    bool operator[](int\
    \ k) const { return isp[k]; }\n\n  private:\n    int n;\n    std::vector<bool>\
    \ isp;\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nclass Eratosthenes {\n  public:\n  \
    \  Eratosthenes() {}\n    explicit Eratosthenes(int n) : n(n), isp(n + 1, true)\
    \ {\n        isp[0] = isp[1] = false;\n        for(int i = 2; i * i <= n; i++)\
    \ {\n            if(!isp[i]) continue;\n            for(int j = i * i; j <= n;\
    \ j += i) isp[j] = false;\n        }\n    }\n    bool operator[](int k) const\
    \ { return isp[k]; }\n\n  private:\n    int n;\n    std::vector<bool> isp;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-1-C_2.test.cpp
  - test/aoj/aoj2858.test.cpp
  - test/mytest/math/number-theory.test.cpp
documentation_of: math/eratosthenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---

## このライブラリでできること

`Eratosthenes` は、$0$ 以上 $N$ 以下の整数について、素数かどうかの表をまとめて作ります。同じ上限内で素数判定を何度も行いたいときに適しています。

各素数の倍数を合成数として消していくエラトステネスの篩を使います。素数 $p$ の処理は $p^2$ から始めてよく、それより小さい倍数はすでに小さい素因数で処理済みです。前処理は $O(N\log\log N)$、その後の1回の判定は $O(1)$ 時間です。

## 使い方

上限を指定して構築し、`sieve[x]` で判定します。例では $97$ が素数、$1$ は素数ではないことを確認しています。上限 $N$ 自身も判定表に含まれます。

```cpp
#include "template/template.cpp"
#include "math/eratosthenes.hpp"

int main() {
    Eratosthenes sieve(100);
    assert(sieve[97] && !sieve[1]);
}
```

## API・計算量

判定表に $O(N)$ bitの空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Eratosthenes(N)` | 素数判定表を構築。 | O(N log log N) |
| `operator[](k)` | k が素数か。 | O(1) |

## 利用条件と実装上の注意

この実装では $N\ge1$ としてください。問い合わせは $0\le x\le N$ に限ります。デフォルト構築だけでは表が存在しません。

平方や倍数を int で計算するため、中間値のオーバーフローにも注意してください。非常に大きい上限のごく狭い区間だけを扱いたい場合、全区間を確保するこの方式は適しません。
