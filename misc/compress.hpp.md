---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/utils/sum_count_manager.hpp
    title: "\u5024\u3054\u3068\u306E\u548C\u30FB\u500B\u6570\u7BA1\u7406"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-5-D.test.cpp
    title: test/aoj/aoj-ALDS1-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2426.test.cpp
    title: test/aoj/aoj2426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
    title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename T> class Compress {\n  public:\n    Compress() = default;\n\
    \    explicit Compress(const std::vector<T> &v) : dat(v) {\n        build();\n\
    \    }\n    void push_back(T val) { dat.push_back(val); }\n\tvoid build() {\n\t\
    \tstd::sort(dat.begin(), dat.end());\n        dat.erase(std::unique(dat.begin(),\
    \ dat.end()), dat.end());\n\t}\n    int get(T val) const {\n        int pos =\
    \ std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();\n        return\
    \ pos;\n    }\n    T operator[](int i) const { return dat[i]; }\n    size_t size()\
    \ const { return dat.size(); }\n\n  private:\n    std::vector<T> dat;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T> class Compress {\n  public:\n    Compress() = default;\n    explicit Compress(const\
    \ std::vector<T> &v) : dat(v) {\n        build();\n    }\n    void push_back(T\
    \ val) { dat.push_back(val); }\n\tvoid build() {\n\t\tstd::sort(dat.begin(), dat.end());\n\
    \        dat.erase(std::unique(dat.begin(), dat.end()), dat.end());\n\t}\n   \
    \ int get(T val) const {\n        int pos = std::lower_bound(dat.begin(), dat.end(),\
    \ val) - dat.begin();\n        return pos;\n    }\n    T operator[](int i) const\
    \ { return dat[i]; }\n    size_t size() const { return dat.size(); }\n\n  private:\n\
    \    std::vector<T> dat;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy:
  - data-structure/utils/sum_count_manager.hpp
  timestamp: '2023-09-30 04:41:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - test/aoj/aoj-ALDS1-5-D.test.cpp
  - test/aoj/aoj2426.test.cpp
documentation_of: misc/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

## このライブラリでできること

`Compress<T>` は、大きい値や負の値を、その大小関係を保ったまま $0,1,\ldots,K-1$ の添字へ変換します。これを座標圧縮と呼びます。値をBITやセグメント木の添字として使いたい場合に便利です。

入力した値の数を $N$、異なる値の数を $K$ とすると、ソートと重複除去に $O(N\log N)$、1回の値から添字への変換に $O(\log K)$ 時間がかかります。

## 使い方

配列を渡すと構築まで行います。例の $[30,10,30,20]$ は異なる値を並べた $[10,20,30]$ に整理され、$20$ の添字は $1$ になります。`c[1]` で元の値 $20$ に戻せます。

`get(x)` は、未登録の値に対しても「$x$ 以上の最初の値の位置」を返します。例の $25$ は未登録ですが、次の値 $30$ の位置 $2$ を返します。この性質は値域の両端を添字へ変換する際に使えます。

```cpp
#include "template/template.cpp"
#include "misc/compress.hpp"

int main() {
    Compress<int> c(vector<int>{30, 10, 30, 20});
    assert(c.get(20) == 1 && c[1] == 20);
    assert(c.get(25) == 2);
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Compress(), Compress(v)` | 空、または v を圧縮して構築。 | O(1) / O(N log N) |
| `push_back(val)` | 未構築の候補を追加。 | 償却 O(1) |
| `build()` | ソートして重複を除く。 | O(N log N) |
| `get(val)` | val 以上の最初の位置。なければ K。 | O(log K) |
| `operator[](i)` | 圧縮前の値。 | O(1) |
| `size()` | 現在の格納数。build 後は異なる値の数。 | O(1) |

## 利用条件と実装上の注意

`push_back` で候補を追加した後は、再度 `build()` してから検索してください。再構築すると既存の添字も変わり得ます。`size()` は構築前なら格納中の要素数、構築後なら異なる値の数です。

`get(x)` は所属判定ではありません。値があるかを知りたい場合は、返った位置 $i$ について `i<c.size()` と `c[i]==x` の両方を確認します。圧縮は大小関係を保存しますが、値の差や距離は保存しません。
