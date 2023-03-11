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
  bundledCode: "#line 2 \"math/linear-sieve.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nclass LinearSieve {\n  public:\n    LinearSieve() {}\n    explicit\
    \ LinearSieve(int n) : n(n), min_factor(n + 1, -1) {\n        std::vector<int>\
    \ prime_list;\n        for(int d = 2; d <= n; d++) {\n            if(min_factor[d]\
    \ == -1) {\n                min_factor[d] = d;\n                prime_list.push_back(d);\n\
    \            }\n            for(int p : prime_list) {\n                if(p *\
    \ d > n or min_factor[d] < p) break;\n                min_factor[p * d] = p;\n\
    \            }\n        }\n    }\n    std::vector<int> factor(int num) {\n   \
    \     assert(0 <= num and num <= n);\n        std::vector<int> ret;\n        while(num\
    \ > 1) {\n            ret.push_back(min_factor[num]);\n            num /= min_factor[num];\n\
    \        }\n        return ret;\n    }\n    const int &operator[](int k) const\
    \ { return min_factor[k]; }\n\n  private:\n    int n;\n    std::vector<int> min_factor;\n\
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nclass LinearSieve\
    \ {\n  public:\n    LinearSieve() {}\n    explicit LinearSieve(int n) : n(n),\
    \ min_factor(n + 1, -1) {\n        std::vector<int> prime_list;\n        for(int\
    \ d = 2; d <= n; d++) {\n            if(min_factor[d] == -1) {\n             \
    \   min_factor[d] = d;\n                prime_list.push_back(d);\n           \
    \ }\n            for(int p : prime_list) {\n                if(p * d > n or min_factor[d]\
    \ < p) break;\n                min_factor[p * d] = p;\n            }\n       \
    \ }\n    }\n    std::vector<int> factor(int num) {\n        assert(0 <= num and\
    \ num <= n);\n        std::vector<int> ret;\n        while(num > 1) {\n      \
    \      ret.push_back(min_factor[num]);\n            num /= min_factor[num];\n\
    \        }\n        return ret;\n    }\n    const int &operator[](int k) const\
    \ { return min_factor[k]; }\n\n  private:\n    int n;\n    std::vector<int> min_factor;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/linear-sieve.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear-sieve.hpp
layout: document
title: "\u7DDA\u5F62\u7BE9"
---
