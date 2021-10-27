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
  bundledCode: "#line 1 \"dp/monotone_minima.hpp\"\ntemplate<class T, class F, class\
    \ Compare = greater<T>>\nvector<pair<int, T>> monotone_minima(int H, int W, const\
    \ F& f, const Compare &compare = Compare()) {\n    vector<pair<int, T>> res(H);\n\
    \    auto solve = [&](auto&& self, int si, int gi, int sj, int gj) -> void {\n\
    \        if(si >= gi) return;\n        int mi = (si + gi) / 2;\n        int id\
    \ = -1;\n        T val;\n        for(int j = sj; j < gj; j++) {\n            T\
    \ now = f(mi, j);\n            if(id == -1 or compare(val, now)) val = now, id\
    \ = j;\n        }\n        res[mi] = {id, val};\n        self(self, si, mi, sj,\
    \ id+1);\n        self(self, mi+1, gi, id, gj);\n    };\n    solve(solve, 0, H,\
    \ 0, W);\n    return res;\n}\n"
  code: "template<class T, class F, class Compare = greater<T>>\nvector<pair<int,\
    \ T>> monotone_minima(int H, int W, const F& f, const Compare &compare = Compare())\
    \ {\n    vector<pair<int, T>> res(H);\n    auto solve = [&](auto&& self, int si,\
    \ int gi, int sj, int gj) -> void {\n        if(si >= gi) return;\n        int\
    \ mi = (si + gi) / 2;\n        int id = -1;\n        T val;\n        for(int j\
    \ = sj; j < gj; j++) {\n            T now = f(mi, j);\n            if(id == -1\
    \ or compare(val, now)) val = now, id = j;\n        }\n        res[mi] = {id,\
    \ val};\n        self(self, si, mi, sj, id+1);\n        self(self, mi+1, gi, id,\
    \ gj);\n    };\n    solve(solve, 0, H, 0, W);\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/monotone_minima.hpp
  requiredBy: []
  timestamp: '2021-10-27 17:01:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/monotone_minima.hpp
layout: document
title: monotone_minima
---

## 内容
$i_1 < i_2$ のとき、$\mathop {\rm arg \, min} f(i_1, *) \leq {\rm arg \, min} f(i_2, *)$ を満たすならば、$f(i, j)$ は **monotone** であるという。

つまり、$H × W$ の行列において、 $i$ 行目の最小値のうち、最も左に位置する要素の列番号を $g(i)$ とすると、

- $ g(1) \leq g(2) \leq ... \leq g(H)$

が成り立つ時**monotone**であるという。

このとき、各行の最左の最小値とその列番号を高速に求めることができ、これを**monotone minima**と呼ぶ。ちなみに${\rm arg \, max}$でも同様に定義できて、同じように適用できる。

また、monotoneである行列の中でも、任意の部分行列でmonotoneであるようなものをtotally monotoneといい、この場合SMAWK algorithmというより高速なアルゴリズムが使えるらしい。

#### 参考資料

- [参考資料1](https://lorent-kyopro.hatenablog.com/entry/2021/04/04/133958)
- [参考資料2](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html)

## 使い方
- `monotone_minima(H, W, f, compare)` : $H × W$ のmonotoneである行列に対して、$i$ 行 $j$ 列目の要素が $f(i, j)$ である時、各行の最小値とその最左のindexを返す。compareは比較関数

## 計算量
$O(H + W\log{H})$

## 出題例
- https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c
- https://codeforces.com/gym/102920/problem/L