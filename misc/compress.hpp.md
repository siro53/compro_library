---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-5-D.test.cpp
    title: test/aoj/aoj-ALDS1-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2426.test.cpp
    title: test/aoj/aoj2426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
    title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename T> class Compress {\n  public:\n    Compress() = default;\n\
    \    explicit Compress(const std::vector<T> &v) : dat(v) {\n        build();\n\
    \    }\n    void push_back(T val) { dat.push_back(val); }\n\tvoid build() {\n\t\
    \tstd::sort(dat.begin(), dat.end());\n        dat.erase(std::unique(dat.begin(),\
    \ dat.end()), dat.end());\n\t}\n    int get(T val) const {\n        int pos =\
    \ std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();\n        return\
    \ pos;\n    }\n    T operator[](int i) const { return dat[i]; }\n    size_t size()\
    \ const { return dat.size(); }\n\n  private:\n    std::vector<T> dat;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T> class Compress {\n  public:\n    Compress() = default;\n    explicit Compress(const\
    \ std::vector<T> &v) : dat(v) {\n        build();\n    }\n    void push_back(T\
    \ val) { dat.push_back(val); }\n\tvoid build() {\n\t\tstd::sort(dat.begin(), dat.end());\n\
    \        dat.erase(std::unique(dat.begin(), dat.end()), dat.end());\n\t}\n   \
    \ int get(T val) const {\n        int pos = std::lower_bound(dat.begin(), dat.end(),\
    \ val) - dat.begin();\n        return pos;\n    }\n    T operator[](int i) const\
    \ { return dat[i]; }\n    size_t size() const { return dat.size(); }\n\n  private:\n\
    \    std::vector<T> dat;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2023-09-30 04:41:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-5-D.test.cpp
  - test/aoj/aoj2426.test.cpp
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
documentation_of: misc/compress.hpp
layout: document
title: "\u5EA7\u5727"
---
