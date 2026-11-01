---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/string/empty-inputs.test.cpp
    title: test/mytest/string/empty-inputs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki1469.test.cpp
    title: test/yukicoder/yuki1469.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/rle.hpp\"\n\n#include <string>\n#include <vector>\n\
    #include <utility>\n\ntemplate<class T>\nstd::vector<std::pair<T, int>> runlength_encoding(const\
    \ std::vector<T>& v) {\n    if(v.empty()) return {};\n    std::vector<std::pair<T,\
    \ int>> ret = {{v[0], 1}};\n    for(size_t i = 1; i < v.size(); i++) {\n     \
    \   if(ret.back().first == v[i]) ret.back().second++;\n        else ret.emplace_back(v[i],\
    \ 1);\n    }\n    return ret;\n}\n\ninline std::vector<std::pair<char, int>> runlength_encoding(const\
    \ std::string& s) {\n    if(s.empty()) return {};\n    std::vector<std::pair<char,\
    \ int>> ret = {{s[0], 1}};\n    for(size_t i = 1; i < s.size(); i++) {\n     \
    \   if(ret.back().first == s[i]) ret.back().second++;\n        else ret.emplace_back(s[i],\
    \ 1);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n#include <utility>\n\
    \ntemplate<class T>\nstd::vector<std::pair<T, int>> runlength_encoding(const std::vector<T>&\
    \ v) {\n    if(v.empty()) return {};\n    std::vector<std::pair<T, int>> ret =\
    \ {{v[0], 1}};\n    for(size_t i = 1; i < v.size(); i++) {\n        if(ret.back().first\
    \ == v[i]) ret.back().second++;\n        else ret.emplace_back(v[i], 1);\n   \
    \ }\n    return ret;\n}\n\ninline std::vector<std::pair<char, int>> runlength_encoding(const\
    \ std::string& s) {\n    if(s.empty()) return {};\n    std::vector<std::pair<char,\
    \ int>> ret = {{s[0], 1}};\n    for(size_t i = 1; i < s.size(); i++) {\n     \
    \   if(ret.back().first == s[i]) ret.back().second++;\n        else ret.emplace_back(s[i],\
    \ 1);\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rle.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki1469.test.cpp
  - test/mytest/string/empty-inputs.test.cpp
documentation_of: misc/rle.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---

## このライブラリでできること

`runlength_encoding` は、連続する同じ値を「値と連続数」の組にまとめます。たとえば `aaabbc` は `(a,3),(b,2),(c,1)` になります。連続部分をひとかたまりとして処理する問題や、同じ値の並びの長さを調べる場合に使えます。

長さ $N$ の入力を左から一度読むので、時間は $O(N)$ です。離れた場所に同じ値があっても、別のまとまりとして返します。

## 使い方

文字列には `string`、一般の値列には `vector<T>` を渡します。返り値はそれぞれ `vector<pair<char,int>>`、`vector<pair<T,int>>` です。例では最初の組が文字 `a` と連続数 $3$ であることを確認しています。

```cpp
#include "template/template.cpp"
#include "misc/rle.hpp"

int main() {
    auto runs = runlength_encoding(string("aaabbc"));
    assert(runs.size() == 3);
    assert(runs[0].first == 'a' && runs[0].second == 3);
}
```

## API・計算量

結果の組数を $K$ とすると、返り値の空間は $O(K)$ です。最悪では $K=N$ になります。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `runlength_encoding(vector<T>)` | vector<pair<T,int>> を返す。 | O(N) |
| `runlength_encoding(string)` | vector<pair<char,int>> を返す。 | O(N) |

## 利用条件と実装上の注意

空の vector・空文字列には、どちらも空の配列を返します。

連続数の型は int なので、その範囲に収める必要があります。元の列の順序は保たれ、ソートや値ごとの総出現数の集計は行いません。
