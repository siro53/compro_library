---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-5-D.test.cpp
    title: test/aoj/aoj-ALDS1-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/utilities.test.cpp
    title: test/mytest/misc/utilities.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/inversion-number.hpp\"\n\n#line 2 \"data-structure/BIT.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\ntemplate <typename T> class BIT {\n\
    \  public:\n    BIT() = default;\n    explicit BIT(int N) : N(N), dat(N + 1, 0)\
    \ {}\n    T sum(int r) {\n        T ret = 0;\n        for(; r >= 1; r -= lsb(r))\
    \ ret += dat[r];\n        return ret;\n    }\n    T sum(int l, int r) {\n    \
    \    assert(l <= r);\n        if(l == r) return T(0);\n        return (sum(r)\
    \ - sum(l));\n    }\n    void add(int pos, T val) {\n        for(int i = pos +\
    \ 1; i <= N; i += lsb(i)) dat[i] += val;\n    }\n    int lower_bound(T val) {\n\
    \        int pos = 0;\n        int k = 1;\n        while(2 * k <= N) k <<= 1;\n\
    \        for(; k >= 1; k >>= 1) {\n            if(pos + k <= N and dat[pos + k]\
    \ < val) {\n                pos += k;\n                val -= dat[pos];\n    \
    \        }\n        }\n        return pos + 1;\n    }\n\n  private:\n    int N;\n\
    \    std::vector<T> dat;\n\n    inline int lsb(int i) { return i & (-i); }\n};\n\
    #line 4 \"misc/inversion-number.hpp\"\n\ntemplate<class T>\nT inversion_number(const\
    \ std::vector<int>& v) {\n    int N = (int)v.size();\n    BIT<int> bt(N);\n  \
    \  T res = 0;\n    for(int i = 0; i < N; i++) {\n        res += i - bt.sum(v[i]+1);\n\
    \        bt.add(v[i], 1);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"../data-structure/BIT.hpp\"\n\ntemplate<class\
    \ T>\nT inversion_number(const std::vector<int>& v) {\n    int N = (int)v.size();\n\
    \    BIT<int> bt(N);\n    T res = 0;\n    for(int i = 0; i < N; i++) {\n     \
    \   res += i - bt.sum(v[i]+1);\n        bt.add(v[i], 1);\n    }\n    return res;\n\
    }"
  dependsOn:
  - data-structure/BIT.hpp
  isVerificationFile: false
  path: misc/inversion-number.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-5-D.test.cpp
  - test/mytest/misc/utilities.test.cpp
documentation_of: misc/inversion-number.hpp
layout: document
title: "\u8EE2\u5012\u6570"
---

## このライブラリでできること

`inversion_number<T>(v)` は、配列で順序が逆転している組の数を求めます。長さを $N$ とすると、転倒数は $\#\{(i,j)\mid0\le i<j<N,\ v_i>v_j\}$ です。同じ値の組は数えません。

左から値を読み、すでに見た値のうち現在値より大きいものの個数をBITで数えます。全体で $O(N\log N)$ 時間、$O(N)$ 空間です。

## 使い方

入力は `vector<int>`、テンプレート引数は答えを格納する型です。例の $[2,0,1]$ では、最初の $2$ と後ろの $0,1$ の2組が転倒しているので答えは $2$ です。

値が負数や大きな整数の場合は、先に大小関係を保つ座標圧縮をしてから渡してください。

```cpp
#include "template/template.cpp"
#include "misc/inversion-number.hpp"

int main() {
    auto count = inversion_number<long long>(vector<int>{2, 0, 1});
    assert(count == 2);
}
```

## API・計算量

入力とは別に $O(N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `inversion_number<T>(v)` | 転倒数を T 型で返す。 | O(N log N) |

## 利用条件と実装上の注意

入力値はすべて $[0,N)$ に収める必要があります。値をそのままBITの添字として使うためです。答えは最大 $N(N-1)/2$ になるので、通常は long long など十分な幅の型を選びます。空配列の答えは0です。
