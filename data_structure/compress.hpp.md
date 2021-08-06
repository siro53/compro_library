---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ2426.test.cpp
    title: test/AOJ2426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inversion_number.test.cpp
    title: test/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/compress.hpp\"\ntemplate <typename T> struct\
    \ Compress {\n    vector<T> v;\n    Compress() {}\n    Compress(vector<T> vv)\
    \ : v(vv) {\n        sort(ALL(v));\n        v.erase(unique(ALL(v)), end(v));\n\
    \    }\n    void build(vector<T> vv) {\n        v = vv;\n        sort(ALL(v));\n\
    \        v.erase(unique(ALL(v)), end(v));\n    }\n    int get(T x) { return (int)(lower_bound(ALL(v),\
    \ x) - v.begin()); }\n    T &operator[](int i) { return v[i]; }\n    size_t size()\
    \ { return v.size(); }\n};\n"
  code: "template <typename T> struct Compress {\n    vector<T> v;\n    Compress()\
    \ {}\n    Compress(vector<T> vv) : v(vv) {\n        sort(ALL(v));\n        v.erase(unique(ALL(v)),\
    \ end(v));\n    }\n    void build(vector<T> vv) {\n        v = vv;\n        sort(ALL(v));\n\
    \        v.erase(unique(ALL(v)), end(v));\n    }\n    int get(T x) { return (int)(lower_bound(ALL(v),\
    \ x) - v.begin()); }\n    T &operator[](int i) { return v[i]; }\n    size_t size()\
    \ { return v.size(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ2426.test.cpp
  - test/inversion_number.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
