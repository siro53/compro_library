---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/staticrmq.test.cpp
    title: test/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/disjoint_sparse_table.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()> \nclass DisjointSparseTable {\n    vector<vector<S>>\
    \ table;\n    vector<int> lookup;\n\npublic:\n    DisjointSparseTable() {}\n \
    \   DisjointSparseTable(vector<S> v) {\n        int b = 0;\n        while((1 <<\
    \ b) <= (int)v.size()) b++;\n        table.resize(b, vector<S>(v.size(), e()));\n\
    \n        for(int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n       \
    \ for(int i = 1; i < b; i++) {\n            int shift = (1 << i);\n          \
    \  for(int j = 0; j < (int)v.size(); j += (shift << 1)) {\n                int\
    \ t = min(j + shift, (int)v.size());\n                table[i][t-1] = v[t-1];\n\
    \                for(int k = t - 2; k >= j; k--) table[i][k] = op(v[k], table[i][k\
    \ + 1]);\n                if((int)v.size() <= t) break;\n                table[i][t]\
    \ = v[t];\n                int r = min(t + shift, (int)v.size());\n          \
    \      for(int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], v[k]);\n\
    \            }\n        }\n        lookup.resize(1 << b);\n        for(int i =\
    \ 2; i < (int)lookup.size(); i++) {\n            lookup[i] = lookup[i >> 1] +\
    \ 1;\n        }\n    }\n\n    S prod(int l, int r) {\n        if(l >= --r) return\
    \ table[0][l];\n        int p = lookup[l ^ r];\n        return op(table[p][l],\
    \ table[p][r]);\n    }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()> \nclass DisjointSparseTable {\n\
    \    vector<vector<S>> table;\n    vector<int> lookup;\n\npublic:\n    DisjointSparseTable()\
    \ {}\n    DisjointSparseTable(vector<S> v) {\n        int b = 0;\n        while((1\
    \ << b) <= (int)v.size()) b++;\n        table.resize(b, vector<S>(v.size(), e()));\n\
    \n        for(int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n       \
    \ for(int i = 1; i < b; i++) {\n            int shift = (1 << i);\n          \
    \  for(int j = 0; j < (int)v.size(); j += (shift << 1)) {\n                int\
    \ t = min(j + shift, (int)v.size());\n                table[i][t-1] = v[t-1];\n\
    \                for(int k = t - 2; k >= j; k--) table[i][k] = op(v[k], table[i][k\
    \ + 1]);\n                if((int)v.size() <= t) break;\n                table[i][t]\
    \ = v[t];\n                int r = min(t + shift, (int)v.size());\n          \
    \      for(int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], v[k]);\n\
    \            }\n        }\n        lookup.resize(1 << b);\n        for(int i =\
    \ 2; i < (int)lookup.size(); i++) {\n            lookup[i] = lookup[i >> 1] +\
    \ 1;\n        }\n    }\n\n    S prod(int l, int r) {\n        if(l >= --r) return\
    \ table[0][l];\n        int p = lookup[l ^ r];\n        return op(table[p][l],\
    \ table[p][r]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2022-04-17 17:28:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/staticrmq.test.cpp
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/disjoint_sparse_table.hpp
- /library/data_structure/disjoint_sparse_table.hpp.html
title: data_structure/disjoint_sparse_table.hpp
---
