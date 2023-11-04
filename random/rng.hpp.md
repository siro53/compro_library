---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/tree-hash.hpp
    title: "\u6728\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2821.test.cpp
    title: test/aoj/aoj2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/binary-trie.test.cpp
    title: test/mytest/data-structure/binary-trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/rng.hpp\"\n\n#include <chrono>\n#include <random>\n\
    \nclass RNG32 {\n  public:\n    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};\n"
  code: "#pragma once\n\n#include <chrono>\n#include <random>\n\nclass RNG32 {\n \
    \ public:\n    RNG32() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    int randint(int l, int r) {\n        std::uniform_int_distribution<int>\
    \ dist(l, r - 1);\n        return dist(mt);\n    }\n    int randint(int r) { return\
    \ randint(0, r); }\n\n  private:\n    std::mt19937 mt;\n};\n\nclass RNG64 {\n\
    \  public:\n    RNG64() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    // [l, r)\n    long long randint(long long l, long long r) {\n     \
    \   std::uniform_int_distribution<long long> dist(l, r - 1);\n        return dist(mt);\n\
    \    }\n    long long randint(long long r) { return randint(0, r); }\n\n  private:\n\
    \    std::mt19937_64 mt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: random/rng.hpp
  requiredBy:
  - graph/tree/tree-hash.hpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/data-structure/binary-trie.test.cpp
  - test/aoj/aoj2821.test.cpp
documentation_of: random/rng.hpp
layout: document
title: "\u4E71\u6570\u751F\u6210"
---
