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
  bundledCode: "#line 2 \"math/segment-sieve.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\n\nclass SegmentSieve {\n  public:\n\
    \    explicit SegmentSieve(long long L, long long R)\n        : L(L), R(R), sq(std::sqrt(R)\
    \ + 1) {\n        small.assign(sq, true);\n        large.assign(R - L, true);\n\
    \        for(long long i = 2; i * i < R; i++) {\n            if(!small[i]) continue;\n\
    \            for(long long j = i * i; j < R; j += i) small[j] = false;\n     \
    \       long long start = std::max((L + i - 1) / i, i * 2);\n            for(long\
    \ long j = start; j < R; j += i) large[j - L] = false;\n        }\n    }\n   \
    \ bool operator[](long long k) const { return large[k - L]; }\n\n  private:\n\
    \    long long L, R;\n    int sq;\n    std::vector<bool> small, large;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <vector>\n\nclass SegmentSieve {\n  public:\n    explicit SegmentSieve(long\
    \ long L, long long R)\n        : L(L), R(R), sq(std::sqrt(R) + 1) {\n       \
    \ small.assign(sq, true);\n        large.assign(R - L, true);\n        for(long\
    \ long i = 2; i * i < R; i++) {\n            if(!small[i]) continue;\n       \
    \     for(long long j = i * i; j < R; j += i) small[j] = false;\n            long\
    \ long start = std::max((L + i - 1) / i, i * 2);\n            for(long long j\
    \ = start; j < R; j += i) large[j - L] = false;\n        }\n    }\n    bool operator[](long\
    \ long k) const { return large[k - L]; }\n\n  private:\n    long long L, R;\n\
    \    int sq;\n    std::vector<bool> small, large;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/segment-sieve.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/segment-sieve.hpp
layout: document
redirect_from:
- /library/math/segment-sieve.hpp
- /library/math/segment-sieve.hpp.html
title: math/segment-sieve.hpp
---
