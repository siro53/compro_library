---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ2426.test.cpp
    title: test/AOJ2426.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sum2d.hpp\"\ntemplate <class T> class sum_2d\
    \ {\n    vector<vector<T>> imos;\n\n  public:\n    sum_2d(int H, int W) : imos(H\
    \ + 1, vector<T>(W + 1, 0)) {}\n    void add(int i, int j, T val) {\n        if(i\
    \ + 1 >= int(imos.size()) || j + 1 >= int(imos[0].size())) return;\n        imos[i\
    \ + 1][j + 1] += val;\n    }\n    void build() {\n        for(int i = 1; i < int(imos.size());\
    \ i++) {\n            for(int j = 1; j < int(imos[0].size()); j++) {\n       \
    \         imos[i][j] +=\n                    imos[i - 1][j] + imos[i][j - 1] -\
    \ imos[i - 1][j - 1];\n            }\n        }\n    }\n    T get_sum(int si,\
    \ int sj, int gi, int gj) {\n        return (imos[gi][gj] - imos[si][gj] - imos[gi][sj]\
    \ + imos[si][sj]);\n    }\n};\n"
  code: "template <class T> class sum_2d {\n    vector<vector<T>> imos;\n\n  public:\n\
    \    sum_2d(int H, int W) : imos(H + 1, vector<T>(W + 1, 0)) {}\n    void add(int\
    \ i, int j, T val) {\n        if(i + 1 >= int(imos.size()) || j + 1 >= int(imos[0].size()))\
    \ return;\n        imos[i + 1][j + 1] += val;\n    }\n    void build() {\n   \
    \     for(int i = 1; i < int(imos.size()); i++) {\n            for(int j = 1;\
    \ j < int(imos[0].size()); j++) {\n                imos[i][j] +=\n           \
    \         imos[i - 1][j] + imos[i][j - 1] - imos[i - 1][j - 1];\n            }\n\
    \        }\n    }\n    T get_sum(int si, int sj, int gi, int gj) {\n        return\
    \ (imos[gi][gj] - imos[si][gj] - imos[gi][sj] + imos[si][sj]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sum2d.hpp
  requiredBy: []
  timestamp: '2021-02-23 11:45:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ2426.test.cpp
documentation_of: data_structure/sum2d.hpp
layout: document
redirect_from:
- /library/data_structure/sum2d.hpp
- /library/data_structure/sum2d.hpp.html
title: data_structure/sum2d.hpp
---
