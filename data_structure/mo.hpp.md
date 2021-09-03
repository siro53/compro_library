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
    \ L, R, ord;\n    vector<bool> nowuse;\n    int BUCKET_SIZE;// bucket size\n \
    \   int nl, nr, ptr;\n\n  public:\n    Mo(int N) : BUCKET_SIZE(sqrt(N)), nl(0),\
    \ nr(0), ptr(0), nowuse(N) {}\n\n    // [l, r)\n    void insert(int l, int r)\
    \ {\n        L.push_back(l);\n        R.push_back(r);\n    }\n    // \u30AF\u30A8\
    \u30EA\u3092sort\u3059\u308B\n    void build() {\n        ord.resize(L.size());\n\
    \        iota(ALL(ord), 0);\n        sort(ALL(ord), [&](int l, int r) {\n    \
    \        if(L[l] / BUCKET_SIZE != L[r] / BUCKET_SIZE)\n                return\
    \ (L[l] < L[r]);\n            else\n                return (R[l] < R[r]);\n  \
    \      });\n    }\n    // \u30AF\u30A8\u30EA\u30921\u3064\u9032\u3081\u308B, \u8FD4\
    \u308A\u5024\u306F\u30AF\u30A8\u30EA\u306Eid\n    int process() {\n        if(ptr\
    \ == ord.size()) return -1;\n        int qid = ord[ptr];\n        while(nl > L[qid])\
    \ add_left(--nl);\n        while(nr < R[qid]) add_right(nr++);\n        while(nl\
    \ < L[qid]) del_left(nl++);\n        while(nr > R[qid]) del_right(--nr);\n   \
    \     return ord[ptr++];\n    }\n\n    void add_left(int id);\n    void add_right(int\
    \ id);\n    void del_left(int id);\n    void del_right(int id);\n};\n"
  code: "class Mo {\n  private:\n    vector<int> L, R, ord;\n    vector<bool> nowuse;\n\
    \    int BUCKET_SIZE;// bucket size\n    int nl, nr, ptr;\n\n  public:\n    Mo(int\
    \ N) : BUCKET_SIZE(sqrt(N)), nl(0), nr(0), ptr(0), nowuse(N) {}\n\n    // [l,\
    \ r)\n    void insert(int l, int r) {\n        L.push_back(l);\n        R.push_back(r);\n\
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
    \ id);\n    void del_left(int id);\n    void del_right(int id);\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/mo.hpp
  requiredBy: []
  timestamp: '2021-09-03 15:14:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_inversions_query.test.cpp
documentation_of: data_structure/mo.hpp
layout: document
redirect_from:
- /library/data_structure/mo.hpp
- /library/data_structure/mo.hpp.html
title: data_structure/mo.hpp
---
