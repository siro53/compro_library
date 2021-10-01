---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_inversions_query.test.cpp
    title: test/static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/mo.hpp\"\nclass Mo {\n  private:\n    vector<int>\
    \ L, R, ord;\n    int BUCKET_SIZE;// bucket size\n    int nl, nr, ptr;\n\n  public:\n\
    \    Mo(int N) : BUCKET_SIZE(sqrt(N)), nl(0), nr(0), ptr(0) {}\n\n    // [l, r)\n\
    \    void insert(int l, int r) {\n        L.push_back(l);\n        R.push_back(r);\n\
    \    }\n    // \u30AF\u30A8\u30EA\u3092sort\u3059\u308B\n    void build() {\n\
    \        ord.resize(L.size());\n        iota(ALL(ord), 0);\n        sort(ALL(ord),\
    \ [&](int l, int r) {\n            if(L[l] / BUCKET_SIZE != L[r] / BUCKET_SIZE)\n\
    \                return (L[l] < L[r]);\n            else\n                return\
    \ (R[l] < R[r]);\n        });\n    }\n    // \u30AF\u30A8\u30EA\u30921\u3064\u9032\
    \u3081\u308B, \u8FD4\u308A\u5024\u306F\u30AF\u30A8\u30EA\u306Eid\n    int process()\
    \ {\n        if(ptr == ord.size()) return -1;\n        int qid = ord[ptr];\n \
    \       while(nl > L[qid]) add_left(--nl);\n        while(nr < R[qid]) add_right(nr++);\n\
    \        while(nl < L[qid]) del_left(nl++);\n        while(nr > R[qid]) del_right(--nr);\n\
    \        return ord[ptr++];\n    }\n\n    void add_left(int id);\n    void add_right(int\
    \ id);\n    void del_left(int id);\n    void del_right(int id);\n};\n"
  code: "class Mo {\n  private:\n    vector<int> L, R, ord;\n    int BUCKET_SIZE;//\
    \ bucket size\n    int nl, nr, ptr;\n\n  public:\n    Mo(int N) : BUCKET_SIZE(sqrt(N)),\
    \ nl(0), nr(0), ptr(0) {}\n\n    // [l, r)\n    void insert(int l, int r) {\n\
    \        L.push_back(l);\n        R.push_back(r);\n    }\n    // \u30AF\u30A8\u30EA\
    \u3092sort\u3059\u308B\n    void build() {\n        ord.resize(L.size());\n  \
    \      iota(ALL(ord), 0);\n        sort(ALL(ord), [&](int l, int r) {\n      \
    \      if(L[l] / BUCKET_SIZE != L[r] / BUCKET_SIZE)\n                return (L[l]\
    \ < L[r]);\n            else\n                return (R[l] < R[r]);\n        });\n\
    \    }\n    // \u30AF\u30A8\u30EA\u30921\u3064\u9032\u3081\u308B, \u8FD4\u308A\
    \u5024\u306F\u30AF\u30A8\u30EA\u306Eid\n    int process() {\n        if(ptr ==\
    \ ord.size()) return -1;\n        int qid = ord[ptr];\n        while(nl > L[qid])\
    \ add_left(--nl);\n        while(nr < R[qid]) add_right(nr++);\n        while(nl\
    \ < L[qid]) del_left(nl++);\n        while(nr > R[qid]) del_right(--nr);\n   \
    \     return ord[ptr++];\n    }\n\n    void add_left(int id);\n    void add_right(int\
    \ id);\n    void del_left(int id);\n    void del_right(int id);\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/mo.hpp
  requiredBy: []
  timestamp: '2021-09-04 15:32:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_inversions_query.test.cpp
documentation_of: data_structure/mo.hpp
layout: document
title: Mo's Algorithm
---

## 内容
- [ei1333の日記](https://ei1333.hateblo.jp/entry/2017/09/11/211011)を参考に作成
- 区間を伸縮させる際、左と右に伸ばす/縮める時でそれぞれ処理が違う場合にも対応。

## 使い方
- `Mo(N)`: 区間$[0, N)$に対するオフラインクエリを処理する
- `insert(l, r)`: クエリ$[l, r)$を追加
- `build()`: クエリをsortして並べ替える。クエリを全て追加したらこれを呼ぶこと。
- `process()`: クエリを1つ分だけ進める。クエリのidが返って来る
- `add_left(id)`: 左に伸ばす(idを現在見ている区間に追加する)処理
- `add_right(id)`: 右に伸ばす(idを現在見ている区間に追加する)処理
- `del_left(id)`: 左から縮める(idを現在見ている区間から削除する)処理
- `del_right(id)`: 右から縮める(idを現在見ている区間から削除する)処理

使う際には、問題に応じて`add_left(id)`, `add_right(id)`, `del_left(id)`, `del_right(id)`に自分で処理を書く

## 計算量
全体で$O((N+Q)\sqrt{N}\alpha)$

ただし$\alpha$は区間の伸縮にかかる計算量