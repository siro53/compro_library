---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
    title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\n\nclass Mo {\n  public:\n\
    \    explicit Mo(int n)\n        : n(n), l(0), r(0), idx(0), BUCKET_SIZE(std::sqrt(n)),\
    \ isBuilt(false) {}\n    void insert(int l, int r) {\n        assert(0 <= l and\
    \ l < r and r <= n);\n        L.push_back(l);\n        R.push_back(r);\n    }\n\
    \    void set_bucketsize(int bs) {\n        assert(!isBuilt);\n        BUCKET_SIZE\
    \ = std::max(1, bs);\n    }\n    void build() {\n        ord.resize(L.size());\n\
    \        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n            if(L[a] / BUCKET_SIZE != L[b] /\
    \ BUCKET_SIZE) {\n                return (L[a] < L[b]);\n            }\n     \
    \       return (R[a] < R[b]);\n        });\n        isBuilt = true;\n    }\n \
    \   template <class AddLeft, class AddRight, class DelLeft, class DelRight>\n\
    \    int process(const AddLeft &add_left, const AddRight &add_right,\n       \
    \         const DelLeft &del_left, const DelRight &del_right) {\n        assert(isBuilt);\n\
    \        if(idx == (int)ord.size()) return -1;\n        int qid = ord[idx++];\n\
    \        while(l > L[qid]) add_left(--l);\n        while(l < L[qid]) del_left(l++);\n\
    \        while(r < R[qid]) add_right(r++);\n        while(r > R[qid]) del_right(--r);\n\
    \        return qid;\n    }\n\n  private:\n    std::vector<int> L, R, ord;\n \
    \   int n, l, r, idx;\n    int BUCKET_SIZE;\n    bool isBuilt;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\n\nclass Mo {\n  public:\n    explicit Mo(int\
    \ n)\n        : n(n), l(0), r(0), idx(0), BUCKET_SIZE(std::sqrt(n)), isBuilt(false)\
    \ {}\n    void insert(int l, int r) {\n        assert(0 <= l and l < r and r <=\
    \ n);\n        L.push_back(l);\n        R.push_back(r);\n    }\n    void set_bucketsize(int\
    \ bs) {\n        assert(!isBuilt);\n        BUCKET_SIZE = std::max(1, bs);\n \
    \   }\n    void build() {\n        ord.resize(L.size());\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        std::sort(ord.begin(), ord.end(), [&](int a, int b)\
    \ {\n            if(L[a] / BUCKET_SIZE != L[b] / BUCKET_SIZE) {\n            \
    \    return (L[a] < L[b]);\n            }\n            return (R[a] < R[b]);\n\
    \        });\n        isBuilt = true;\n    }\n    template <class AddLeft, class\
    \ AddRight, class DelLeft, class DelRight>\n    int process(const AddLeft &add_left,\
    \ const AddRight &add_right,\n                const DelLeft &del_left, const DelRight\
    \ &del_right) {\n        assert(isBuilt);\n        if(idx == (int)ord.size())\
    \ return -1;\n        int qid = ord[idx++];\n        while(l > L[qid]) add_left(--l);\n\
    \        while(l < L[qid]) del_left(l++);\n        while(r < R[qid]) add_right(r++);\n\
    \        while(r > R[qid]) del_right(--r);\n        return qid;\n    }\n\n  private:\n\
    \    std::vector<int> L, R, ord;\n    int n, l, r, idx;\n    int BUCKET_SIZE;\n\
    \    bool isBuilt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
documentation_of: misc/mo.hpp
layout: document
link: https://ei1333.hateblo.jp/entry/2017/09/11/211011
title: Mo's Algorithm
---
