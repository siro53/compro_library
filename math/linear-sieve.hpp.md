---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/math/number-theory.test.cpp
    title: test/mytest/math/number-theory.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/linear-sieve.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nclass LinearSieve {\n  public:\n    LinearSieve() {}\n    explicit\
    \ LinearSieve(int n) : n(n), min_factor(n + 1, -1) {\n        std::vector<int>\
    \ prime_list;\n        for(int d = 2; d <= n; d++) {\n            if(min_factor[d]\
    \ == -1) {\n                min_factor[d] = d;\n                prime_list.push_back(d);\n\
    \            }\n            for(int p : prime_list) {\n                if(p *\
    \ d > n or min_factor[d] < p) break;\n                min_factor[p * d] = p;\n\
    \            }\n        }\n    }\n    std::vector<int> factor(int num) {\n   \
    \     assert(0 <= num and num <= n);\n        std::vector<int> ret;\n        while(num\
    \ > 1) {\n            ret.push_back(min_factor[num]);\n            num /= min_factor[num];\n\
    \        }\n        return ret;\n    }\n    const int &operator[](int k) const\
    \ { return min_factor[k]; }\n\n  private:\n    int n;\n    std::vector<int> min_factor;\n\
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nclass LinearSieve\
    \ {\n  public:\n    LinearSieve() {}\n    explicit LinearSieve(int n) : n(n),\
    \ min_factor(n + 1, -1) {\n        std::vector<int> prime_list;\n        for(int\
    \ d = 2; d <= n; d++) {\n            if(min_factor[d] == -1) {\n             \
    \   min_factor[d] = d;\n                prime_list.push_back(d);\n           \
    \ }\n            for(int p : prime_list) {\n                if(p * d > n or min_factor[d]\
    \ < p) break;\n                min_factor[p * d] = p;\n            }\n       \
    \ }\n    }\n    std::vector<int> factor(int num) {\n        assert(0 <= num and\
    \ num <= n);\n        std::vector<int> ret;\n        while(num > 1) {\n      \
    \      ret.push_back(min_factor[num]);\n            num /= min_factor[num];\n\
    \        }\n        return ret;\n    }\n    const int &operator[](int k) const\
    \ { return min_factor[k]; }\n\n  private:\n    int n;\n    std::vector<int> min_factor;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/linear-sieve.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/math/number-theory.test.cpp
documentation_of: math/linear-sieve.hpp
layout: document
title: "\u7DDA\u5F62\u7BE9"
---

## このライブラリでできること

`LinearSieve` は、$2$ 以上 $N$ 以下の各整数について最小の素因数を記録します。素数判定表だけでなく素因数分解にも使いたい場合に便利です。各合成数をその最小素因数に対応する組で一度だけ処理し、前計算を $O(N)$ 時間で行います。

ある数 $x$ の最小素因数が分かれば、$x$ をそれで割って同じ操作を繰り返すだけで分解できます。1回ごとに少なくとも半分になるため、分解は $O(\log x)$ 時間です。

## 使い方

`sieve[x]` は素数かどうかではなく最小素因数を返します。$x\ge2$ なら `sieve[x]==x` のときに限り素数です。例では $15$ の最小素因数が $3$ で、`factor(12)` は重複付きの列 $[2,2,3]$ を返します。

```cpp
#include "template/template.cpp"
#include "math/linear-sieve.hpp"

int main() {
    LinearSieve sieve(100);
    assert(sieve[15] == 3);
    assert((sieve.factor(12) == vector<int>{2, 2, 3}));
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LinearSieve(N)` | [0,N] の最小素因数表を構築。 | O(N) |
| `operator[](k)` | k の最小素因数。0,1 は -1。 | O(1) |
| `factor(num)` | 重複込みの素因数を昇順で返す。0,1 は空。 | O(log(num+1)) |

## 利用条件と実装上の注意

構築上限は $N\ge0$、問い合わせは $[0,N]$ に収めてください。$0,1$ の最小素因数は $-1$、`factor(0)` と `factor(1)` は空の配列になります。これは0の素因数分解を定義しているわけではありません。

内部では `p*d` を int で計算するため、上限との比較前にオーバーフローしない範囲で使ってください。デフォルト構築のままの参照もできません。
