---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/string/z-algorithm.test.cpp
    title: test/library-checker/string/z-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/string/empty-inputs.test.cpp
    title: test/mytest/string/empty-inputs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/string/string-api.test.cpp
    title: test/mytest/string/string-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z-algo.hpp\"\n\n#include <vector>\n#include <string>\n\
    \ninline std::vector<int> z_algo(const std::string& s) {\n    int n = (int)s.size();\n\
    \    std::vector<int> z(n);\n    if(n == 0) return z;\n    z[0] = n;\n    for(int\
    \ i = 1, j = 0; i < n;) {\n        while(i + j < n and s[j] == s[i + j]) j++;\n\
    \        z[i] = j;\n        if(j == 0) {\n            i++;\n            continue;\n\
    \        }\n        int k = 1;\n        while(k < j and k + z[k] < j) {\n    \
    \        z[i + k] = z[k];\n            k++;\n        }\n        i += k;\n    \
    \    j -= k;\n    }\n    return z;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\ninline std::vector<int>\
    \ z_algo(const std::string& s) {\n    int n = (int)s.size();\n    std::vector<int>\
    \ z(n);\n    if(n == 0) return z;\n    z[0] = n;\n    for(int i = 1, j = 0; i\
    \ < n;) {\n        while(i + j < n and s[j] == s[i + j]) j++;\n        z[i] =\
    \ j;\n        if(j == 0) {\n            i++;\n            continue;\n        }\n\
    \        int k = 1;\n        while(k < j and k + z[k] < j) {\n            z[i\
    \ + k] = z[k];\n            k++;\n        }\n        i += k;\n        j -= k;\n\
    \    }\n    return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algo.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/string/z-algorithm.test.cpp
  - test/mytest/string/string-api.test.cpp
  - test/mytest/string/empty-inputs.test.cpp
documentation_of: string/z-algo.hpp
layout: document
title: Z algorithm
---

## このライブラリでできること

`z_algo(s)` は、文字列全体と各位置から始まる接尾辞との最長共通接頭辞の長さを求めます。長さを $N$ とすると、返り値 $z_i$ は $s[0,z_i)=s[i,i+z_i)$ を満たす最大の長さです。$z_0=N$ とします。

すでに一致が分かっている区間の情報を再利用することで、すべての位置の値を $O(N)$ 時間で求めます。接頭辞の繰り返しや文字列中のパターンの出現を調べる場合に使えます。

## 使い方

例の `ababa` では、位置2からの接尾辞 `aba` が先頭の3文字と一致するため $z_2=3$ です。位置4では `a` だけが一致するので $z_4=1$ になります。

パターン $P$ の出現を探したい場合は、どちらの文字列にも含まれない区切り文字を挟んだ $P+\#+S$ を作り、$S$ に対応する位置で Z 値が $|P|$ 以上かを調べる使い方ができます。

```cpp
#include "template/template.cpp"
#include "string/z-algo.hpp"

int main() {
    auto z = z_algo("ababa");
    assert((z == vector<int>{5, 0, 3, 0, 1}));
}
```

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `z_algo(s)` | 長さ N の vector<int>。z[0]=N。 | O(N) |

## 利用条件と実装上の注意

空文字列には空の配列を返します。文字列はバイト単位で比較するので、UTF-8の1文字を単位として処理するものではありません。
