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
  bundledCode: "#line 1 \"data_structure/segtree/segtree_2d.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()>\nclass segtree_2d {\nprivate:\n    int H, W;\n \
    \   vector<vector<S>> node;\n \n    S prod_w(int i, int lj, int rj) {\n      \
    \  S vl = e(), vr = e();\n        for(lj += W, rj += W; lj < rj; lj >>= 1, rj\
    \ >>= 1) {\n            if(lj & 1) vl = op(vl, node[i][lj++]);\n            if(rj\
    \ & 1) vr = op(node[i][--rj], vr);\n        }\n        return op(vl, vr);\n  \
    \  }\n \npublic:\n    segtree_2d(int h, int w) {\n        H = 1, W = 1;\n    \
    \    while(H < h) H <<= 1;\n        while(W < w) W <<= 1;\n        node.resize(2*H,\
    \ vector<S>(2*W, e()));\n    }\n \n    void set(int i, int j, S val) {\n     \
    \   i += H, j += W;\n        int tmp = j;\n        node[i][j] = val;\n       \
    \ while(i) {\n            j = tmp;\n            while(j) {\n                node[i][j]\
    \ = op(node[i][j], val);\n                j >>= 1;\n            }\n          \
    \  i >>= 1;\n        }\n    }\n \n    S get(int i, int j) { return node[i+H][j+W];\
    \ }\n \n    S prod(int li, int lj, int ri, int rj) {\n        S vl = e(), vr =\
    \ e();\n        for(li += H, ri += H; li < ri; li >>= 1, ri >>= 1) {\n       \
    \     if(li & 1) vl = op(vl, prod_w(li++, lj, rj));\n            if(ri & 1) vr\
    \ = op(prod_w(--ri, lj, rj), vr);\n        }\n        return op(vl, vr);\n   \
    \ }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass segtree_2d {\nprivate:\n\
    \    int H, W;\n    vector<vector<S>> node;\n \n    S prod_w(int i, int lj, int\
    \ rj) {\n        S vl = e(), vr = e();\n        for(lj += W, rj += W; lj < rj;\
    \ lj >>= 1, rj >>= 1) {\n            if(lj & 1) vl = op(vl, node[i][lj++]);\n\
    \            if(rj & 1) vr = op(node[i][--rj], vr);\n        }\n        return\
    \ op(vl, vr);\n    }\n \npublic:\n    segtree_2d(int h, int w) {\n        H =\
    \ 1, W = 1;\n        while(H < h) H <<= 1;\n        while(W < w) W <<= 1;\n  \
    \      node.resize(2*H, vector<S>(2*W, e()));\n    }\n \n    void set(int i, int\
    \ j, S val) {\n        i += H, j += W;\n        int tmp = j;\n        node[i][j]\
    \ = val;\n        while(i) {\n            j = tmp;\n            while(j) {\n \
    \               node[i][j] = op(node[i][j], val);\n                j >>= 1;\n\
    \            }\n            i >>= 1;\n        }\n    }\n \n    S get(int i, int\
    \ j) { return node[i+H][j+W]; }\n \n    S prod(int li, int lj, int ri, int rj)\
    \ {\n        S vl = e(), vr = e();\n        for(li += H, ri += H; li < ri; li\
    \ >>= 1, ri >>= 1) {\n            if(li & 1) vl = op(vl, prod_w(li++, lj, rj));\n\
    \            if(ri & 1) vr = op(prod_w(--ri, lj, rj), vr);\n        }\n      \
    \  return op(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree/segtree_2d.hpp
  requiredBy: []
  timestamp: '2021-11-21 15:35:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segtree/segtree_2d.hpp
layout: document
title: "2\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 内容
- 2次元セグメント木

## 使い方
- `S`: モノイドの型
- `op(S, S)`: モノイドの演算
- `e()`: モノイドの単位元
- `set(i, j, val)`: $(i, j)$に`val`をプロット(代入)する
- `get(i, j, val)`: $(i, j)$にプロットされている値を取得する
- `prod(li, lj, ri, rj)`: $[li, ri) × [lj, rj)$の矩形範囲のモノイドの総積を取得する。

## 計算量
$H × W$ の大きさの2次元セグメント木を作ると仮定する。

また、`op, e`が定数時間で計算できると仮定する。

- 空間 $O(HW)$
- `set, prod`: $O((\log{H})(\log{W}))$
- `get`: $O(1)$

## verify
- https://atcoder.jp/contests/abc228/submissions/27417534