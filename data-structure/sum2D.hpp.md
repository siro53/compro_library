---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2426.test.cpp
    title: test/aoj/aoj2426.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/basic-api.test.cpp
    title: test/mytest/data-structure/basic-api.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sum2D.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename T> class sum2D {\n  public:\n    sum2D() = default;\n\
    \    explicit sum2D(int height, int width)\n        : sum(height + 1, std::vector<T>(width\
    \ + 1, 0)), isBuilt(false) {}\n    void add(int row, int column, T val) {\n  \
    \      assert(0 <= row + 1 && row + 1 < (int)sum.size());\n        assert(0 <=\
    \ column + 1 && column + 1 < (int)sum[0].size());\n        sum[row + 1][column\
    \ + 1] += val;\n    }\n    void build() {\n        for(int i = 1; i < (int)sum.size();\
    \ i++) {\n            for(int j = 1; j < (int)sum[0].size(); j++) {\n        \
    \        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];\n   \
    \         }\n        }\n        isBuilt = true;\n    }\n    T get_sum(int row_l,\
    \ int row_r, int column_l, int column_r) const {\n        assert(row_l <= row_r);\n\
    \        assert(column_l <= column_r);\n        assert(isBuilt);\n        return\
    \ (sum[row_r][column_r] - sum[row_l][column_r] -\n                sum[row_r][column_l]\
    \ + sum[row_l][column_l]);\n    }\n\n  private:\n    std::vector<std::vector<T>>\
    \ sum;\n    bool isBuilt;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> class sum2D {\n  public:\n    sum2D() = default;\n    explicit sum2D(int\
    \ height, int width)\n        : sum(height + 1, std::vector<T>(width + 1, 0)),\
    \ isBuilt(false) {}\n    void add(int row, int column, T val) {\n        assert(0\
    \ <= row + 1 && row + 1 < (int)sum.size());\n        assert(0 <= column + 1 &&\
    \ column + 1 < (int)sum[0].size());\n        sum[row + 1][column + 1] += val;\n\
    \    }\n    void build() {\n        for(int i = 1; i < (int)sum.size(); i++) {\n\
    \            for(int j = 1; j < (int)sum[0].size(); j++) {\n                sum[i][j]\
    \ += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];\n            }\n     \
    \   }\n        isBuilt = true;\n    }\n    T get_sum(int row_l, int row_r, int\
    \ column_l, int column_r) const {\n        assert(row_l <= row_r);\n        assert(column_l\
    \ <= column_r);\n        assert(isBuilt);\n        return (sum[row_r][column_r]\
    \ - sum[row_l][column_r] -\n                sum[row_r][column_l] + sum[row_l][column_l]);\n\
    \    }\n\n  private:\n    std::vector<std::vector<T>> sum;\n    bool isBuilt;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sum2D.hpp
  requiredBy: []
  timestamp: '2024-12-15 14:15:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/data-structure/basic-api.test.cpp
  - test/aoj/aoj2426.test.cpp
documentation_of: data-structure/sum2D.hpp
layout: document
title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## このライブラリでできること

`sum2D<T>` は、値が変化しない盤面に対して長方形の総和を何度も求めるためのクラスです。高さ $H$、幅 $W$ の盤面を $O(HW)$ 時間で前処理すると、1回の長方形和を $O(1)$ 時間で求められます。

左上からの累積和を $P(i,j)=\sum_{0\le x<i,\,0\le y<j}A_{x,y}$ とすると、求める長方形の和は4つの値の足し引きで表せます。たとえば行 $[a,b)$、列 $[c,d)$ の和は $P(b,d)-P(a,d)-P(b,c)+P(a,c)$ です。

## 使い方

まず `add(row,column,x)` で各マスの値を設定し、`build()` を一度呼びます。その後は `get_sum(row_l,row_r,column_l,column_r)` で問い合わせます。引数は「行の両端、列の両端」の順であり、対角の2点を交互に渡す形ではありません。例では値 $7$ を置いたマスを含む長方形を問い合わせています。

```cpp
#include "template/template.cpp"
#include "data-structure/sum2D.hpp"

int main() {
    sum2D<long long> sum(3, 4);
    sum.add(1, 2, 7);
    sum.build();
    assert(sum.get_sum(0, 2, 1, 3) == 7);
}
```

## API・計算量

必要な空間は $O(HW)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `sum2D(H, W)` | H×W の盤面を 0 で初期化。 | O(HW) |
| `add(row, column, val)` | 1 セルに加算。 | O(1) |
| `build()` | 二次元累積和を構築。 | O(HW) |
| `get_sum(row_l, row_r, column_l, column_r)` | 行 [row_l,row_r)、列 [column_l,column_r) の和。 | O(1) |

## 利用条件と実装上の注意

添字は0始まりです。`add` には盤面内の位置を、`get_sum` には盤面内に収まる半開区間を指定してください。空の長方形の和は $0$ です。

すべての加算を終えてから `build()` を一度だけ呼びます。構築後の追加や再構築には対応していません。また、累積和の中間値も `T` に収まるようにしてください。
