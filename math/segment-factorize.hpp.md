---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"math/segment-factorize.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <numeric>\n#include <vector>\n\nclass\
    \ SegmentFactorize {\npublic:\n    explicit SegmentFactorize(long long L, long\
    \ long R): L(L), R(R), sq(std::sqrt(R) + 1) {\n        small.resize(sq);\n   \
    \     std::iota(small.begin(), small.end(), 0);\n        large.resize(R - L);\n\
    \        large_mul.assign(R - L, 1);\n        for(long long i = 2; i * i < R;\
    \ i++) {\n            if(small[i] < i) continue;\n            for(long long j\
    \ = i * i; j < sq; j += i) {\n                if(small[j] == j) small[j] = i;\n\
    \            }\n            for(long long j = (L + i - 1) / i * i; j < R; j +=\
    \ i) {\n                long long now = j;\n                do {\n           \
    \         if(large_mul[j - L] * large_mul[j - L] > R) break;\n               \
    \     large[j - L].push_back(i);\n                    large_mul[j - L] *= i;\n\
    \                    now /= i;\n                } while(now % i == 0);\n     \
    \       }\n        }\n    } \n    std::vector<long long> factor(long long n) {\n\
    \        assert(L <= n and n < R);\n        std::vector<long long> ret = large[n\
    \ - L];\n        n /= large_mul[n - L];\n        if(n >= sq) {\n            ret.push_back(n);\n\
    \            return ret;\n        }\n        while(n > 1) {\n            ret.push_back(small[n]);\n\
    \            n /= small[n];\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    long long L, R;\n    int sq;\n    std::vector<int> small;\n    std::vector<std::vector<long\
    \ long>> large;\n    std::vector<long long> large_mul;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\n\nclass SegmentFactorize {\npublic:\n \
    \   explicit SegmentFactorize(long long L, long long R): L(L), R(R), sq(std::sqrt(R)\
    \ + 1) {\n        small.resize(sq);\n        std::iota(small.begin(), small.end(),\
    \ 0);\n        large.resize(R - L);\n        large_mul.assign(R - L, 1);\n   \
    \     for(long long i = 2; i * i < R; i++) {\n            if(small[i] < i) continue;\n\
    \            for(long long j = i * i; j < sq; j += i) {\n                if(small[j]\
    \ == j) small[j] = i;\n            }\n            for(long long j = (L + i - 1)\
    \ / i * i; j < R; j += i) {\n                long long now = j;\n            \
    \    do {\n                    if(large_mul[j - L] * large_mul[j - L] > R) break;\n\
    \                    large[j - L].push_back(i);\n                    large_mul[j\
    \ - L] *= i;\n                    now /= i;\n                } while(now % i ==\
    \ 0);\n            }\n        }\n    } \n    std::vector<long long> factor(long\
    \ long n) {\n        assert(L <= n and n < R);\n        std::vector<long long>\
    \ ret = large[n - L];\n        n /= large_mul[n - L];\n        if(n >= sq) {\n\
    \            ret.push_back(n);\n            return ret;\n        }\n        while(n\
    \ > 1) {\n            ret.push_back(small[n]);\n            n /= small[n];\n \
    \       }\n        return ret;\n    }\n\nprivate:\n    long long L, R;\n    int\
    \ sq;\n    std::vector<int> small;\n    std::vector<std::vector<long long>> large;\n\
    \    std::vector<long long> large_mul;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/segment-factorize.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj2858.test.cpp
  - test/mytest/math/number-theory.test.cpp
documentation_of: math/segment-factorize.hpp
layout: document
title: "\u533A\u9593\u7D20\u56E0\u6570\u5206\u89E3"
---

## このライブラリでできること

`SegmentFactorize` は、正整数の連続区間 $[L,R)$ にある値を何度も素因数分解するための前処理です。$R$ が大きくても区間幅が狭ければ、$R$ 以下をすべて保存する篩より小さな領域で扱えます。

幅を $K=R-L$、$S=\lceil\sqrt R\rceil$ とします。小さい素因数の表と、区間内の各数から取り出した素因数を保持します。重複する素因数の処理まで含めた前処理の上界は $O(S\log\log(R+2)+K\log R)$、1つの値の分解結果を取り出す時間は $O(\log n)$ です。

## 使い方

対象区間を指定して構築し、`factor(n)` で素因数の列を取得します。例では区間 $[10,20)$ を準備し、$12$ を $[2,2,3]$ に分解しています。`prime_factor` の map とは異なり、同じ素因数は指数の回数だけ列に現れます。

```cpp
#include "template/template.cpp"
#include "math/segment-factorize.hpp"

int main() {
    SegmentFactorize sieve(10, 20);
    auto f = sieve.factor(12);
    assert((f == vector<long long>{2, 2, 3}));
}
```

## API・計算量

小さい数の表と区間内の素因数列を合わせた空間の上界は $O(S+K\log R)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegmentFactorize(L, R)` | 小さい素因数表と区間内の素因数情報を構築。 | O(S log log(R+2)+K log R) 上界 |
| `factor(n)` | n の素因数を重複込みで返す。 | O(log n) |

## 利用条件と実装上の注意

$1\le L<R$ とし、問い合わせは $L\le n<R$ に限ってください。初期化に必要な区間幅と $\sqrt R$ の領域がメモリに収まる必要があります。

内部の `large_mul*large_mul` などの積も long long で計算します。引数だけでなく、その中間積が型の範囲に収まることを確認してください。表の空間量は保存する素因数の個数まで含めた上界です。
