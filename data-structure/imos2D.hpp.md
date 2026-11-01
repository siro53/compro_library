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
    - https://atcoder.jp/contests/abc276/submissions/60797388
  bundledCode: "#line 2 \"data-structure/imos2D.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n// verify: https://atcoder.jp/contests/abc276/submissions/60797388\n\
    \ntemplate <typename T> \nclass imos2D {\npublic:\n    int H, W;\n\n    imos2D()\
    \ = default;\n    explicit imos2D(int H, int W): H(H), W(W), imos(H + 1, std::vector<T>(W\
    \ + 1, 0)), isBuilt(false) {}\n\n    void add(int li, int lj, int ri, int rj,\
    \ T val) {\n        assert(0 <= li and li < H);\n        assert(li <= ri and ri\
    \ <= H);\n        assert(0 <= lj and lj < W);\n        assert(lj <= rj and rj\
    \ <= W);\n        imos[li][lj] += val;\n        imos[li][rj] -= val;\n       \
    \ imos[ri][lj] -= val;\n        imos[ri][rj] += val;\n    } \n\n    void build()\
    \ {\n        for(int i = 0; i <= H; i++) {\n            for(int j = 1; j <= W;\
    \ j++) {\n                imos[i][j] += imos[i][j - 1];\n            }\n     \
    \   }\n        for(int j = 0; j <= W; j++) {\n            for(int i = 1; i <=\
    \ H; i++) {\n                imos[i][j] += imos[i - 1][j];\n            }\n  \
    \      }\n        isBuilt = true;\n    }\n\n    inline std::vector<T>& operator[](int\
    \ i) {\n        assert(isBuilt);\n        return imos[i];\n    }\n\nprivate:\n\
    \    std::vector<std::vector<T>> imos;\n    bool isBuilt;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// verify: https://atcoder.jp/contests/abc276/submissions/60797388\n\
    \ntemplate <typename T> \nclass imos2D {\npublic:\n    int H, W;\n\n    imos2D()\
    \ = default;\n    explicit imos2D(int H, int W): H(H), W(W), imos(H + 1, std::vector<T>(W\
    \ + 1, 0)), isBuilt(false) {}\n\n    void add(int li, int lj, int ri, int rj,\
    \ T val) {\n        assert(0 <= li and li < H);\n        assert(li <= ri and ri\
    \ <= H);\n        assert(0 <= lj and lj < W);\n        assert(lj <= rj and rj\
    \ <= W);\n        imos[li][lj] += val;\n        imos[li][rj] -= val;\n       \
    \ imos[ri][lj] -= val;\n        imos[ri][rj] += val;\n    } \n\n    void build()\
    \ {\n        for(int i = 0; i <= H; i++) {\n            for(int j = 1; j <= W;\
    \ j++) {\n                imos[i][j] += imos[i][j - 1];\n            }\n     \
    \   }\n        for(int j = 0; j <= W; j++) {\n            for(int i = 1; i <=\
    \ H; i++) {\n                imos[i][j] += imos[i - 1][j];\n            }\n  \
    \      }\n        isBuilt = true;\n    }\n\n    inline std::vector<T>& operator[](int\
    \ i) {\n        assert(isBuilt);\n        return imos[i];\n    }\n\nprivate:\n\
    \    std::vector<std::vector<T>> imos;\n    bool isBuilt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/imos2D.hpp
  requiredBy: []
  timestamp: '2024-12-15 14:47:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/imos2D.hpp
layout: document
title: "\u4E8C\u6B21\u5143\u3044\u3082\u3059\u6CD5"
---

## このライブラリでできること

`imos2D<T>` は、盤面の長方形領域への加算をまとめて処理します。「複数の長方形を塗り、最後に各マスが何回塗られたかを知りたい」という問題に向いています。盤面の高さを $H$、幅を $W$ とします。

更新時には長方形の四隅に差分だけを書き込み、最後に縦・横の累積和を取ります。長方形の面積によらず1回の追加は $O(1)$、全マスの値を確定する処理は $O(HW)$ 時間です。

## 使い方

`add(li,lj,ri,rj,x)` は、行が $[li,ri)$、列が $[lj,rj)$ の長方形に $x$ を加えます。すべての長方形を追加した後で `build()` を一度だけ呼び、`imos[i][j]` で値を読みます。例では2行目・3列目のマスも加算範囲に含まれるため、その値は $5$ です。

```cpp
#include "template/template.cpp"
#include "data-structure/imos2D.hpp"

int main() {
    imos2D<int> imos(3, 4);
    imos.add(0, 1, 2, 4, 5);
    imos.build();
    assert(imos[1][2] == 5);
}
```

## API・計算量

必要な空間は $O(HW)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `imos2D(H, W)` | H×W の盤面を 0 で初期化。 | O(HW) |
| `add(li, lj, ri, rj, val)` | 行 [li,ri)、列 [lj,rj) に加算予約。 | O(1) |
| `build()` | 累積して各セルの値を確定。 | O(HW) |
| `operator[](i)` | 構築後の i 行目への参照。 | O(1) |

## 利用条件と実装上の注意

`H,W` は公開メンバですが、構築後にサイズだけを書き換えないでください。加算範囲は $0\le li<H$、$li\le ri\le H$ とし、列についても同様の条件を満たす必要があります。

`build()` は差分配列を実際の値に変換します。構築後にさらに `add` したり、もう一度 `build` したりする使い方には対応していません。更新と取得を交互に行うためのデータ構造ではありません。
