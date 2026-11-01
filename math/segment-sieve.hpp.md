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
  bundledCode: "#line 2 \"math/segment-sieve.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\n\nclass SegmentSieve {\n  public:\n\
    \    explicit SegmentSieve(long long L, long long R)\n        : L(L), R(R), sq(std::sqrt(R)\
    \ + 1) {\n        small.assign(sq, true);\n        large.assign(R - L, true);\n\
    \        for(long long i = 2; i * i < R; i++) {\n            if(!small[i]) continue;\n\
    \            for(long long j = i * i; j < R; j += i) small[j] = false;\n     \
    \       long long start = std::max((L + i - 1) / i, i * 2);\n            for(long\
    \ long j = start; j < R; j += i) large[j - L] = false;\n        }\n    }\n   \
    \ bool operator[](long long k) const { return large[k - L]; }\n\n  private:\n\
    \    long long L, R;\n    int sq;\n    std::vector<bool> small, large;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <vector>\n\nclass SegmentSieve {\n  public:\n    explicit SegmentSieve(long\
    \ long L, long long R)\n        : L(L), R(R), sq(std::sqrt(R) + 1) {\n       \
    \ small.assign(sq, true);\n        large.assign(R - L, true);\n        for(long\
    \ long i = 2; i * i < R; i++) {\n            if(!small[i]) continue;\n       \
    \     for(long long j = i * i; j < R; j += i) small[j] = false;\n            long\
    \ long start = std::max((L + i - 1) / i, i * 2);\n            for(long long j\
    \ = start; j < R; j += i) large[j - L] = false;\n        }\n    }\n    bool operator[](long\
    \ long k) const { return large[k - L]; }\n\n  private:\n    long long L, R;\n\
    \    int sq;\n    std::vector<bool> small, large;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/segment-sieve.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/segment-sieve.hpp
layout: document
title: "\u533A\u9593\u7D20\u6570\u5224\u5B9A"
---

## このライブラリでできること

`SegmentSieve` は、連続区間 $[L,R)$ にある数が素数かどうかをまとめて調べる区間篩を意図したクラスです。一般的な区間篩では、$\sqrt R$ 以下の素数を先に列挙し、それぞれの倍数だけを対象区間から消します。

ただし、このヘッダーの現実装は配列の境界と倍数の開始位置に不備があり、そのままでは利用できません。通常の区間篩の説明と、現在の実装が正しく動くことは分けて考える必要があります。

## 使い方

APIとしては、`SegmentSieve(L,R)` で対象区間を準備し、`sieve[n]` で判定する形です。以下の例は $[10,20)$ のうち $13$ を問い合わせる呼び出し形だけを示しています。実行可能な使用例ではありません。

以下のコードは呼び出し形を示すものです。現実装の不備があるため、動作確認済みの使用例ではありません。

```cpp
#include "template/template.cpp"
#include "math/segment-sieve.hpp"

int main() {
    SegmentSieve sieve(10, 20);
    bool prime = sieve[13];
}
```

## API・計算量

確保しようとしている配列の大きさは $O(\sqrt R+R-L)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegmentSieve(L, R)` | 区間の素数判定表を作る意図。 | 現状は範囲外アクセスがあり保証なし |
| `operator[](k)` | large[k-L] の判定値を取得。 | O(1) |

## 利用条件と実装上の注意

小さい篩 `small` は約 $\sqrt R$ 要素しか確保していないのに、$R$ 未満まで書き込んでいます。また、区間側の倍数の開始位置の式には素数との乗算がなく、$L$ 未満の位置を参照することがあります。$0,1$ を素数から除く処理もありません。

これらの修正が必要なため、表では正常終了を前提とする構築時間を記載していません。空間量も、確保しようとしている配列サイズの説明です。
