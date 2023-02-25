---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2858.test.cpp
    title: test/aoj/aoj2858.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/segment-factorize.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <numeric>\n#include <vector>\n\nclass\
    \ SegmentFactorize {\npublic:\n    explicit SegmentFactorize(long long L, long\
    \ long R): L(L), R(R), sq(std::sqrt(R) + 1) {\n        small.resize(sq);\n   \
    \     std::iota(small.begin(), small.end(), 0);\n        large.resize(R - L);\n\
    \        large_mul.assign(R - L, 1);\n        for(long long i = 2; i * i < R;\
    \ i++) {\n            if(small[i] < i) continue;\n            for(long long j\
    \ = i * i; j < sq; j += i) {\n                if(small[j] == j) small[j] = i;\n\
    \            }\n            for(long long j = (L + i - 1) / i * i; j < R; j +=\
    \ i) {\n                long long now = j;\n                do {\n           \
    \         if(large_mul[j - L] * large_mul[j - L] > R) break;\n               \
    \     large[j - L].push_back(i);\n                    large_mul[j - L] *= i;\n\
    \                    now /= i;\n                } while(now % i == 0);\n     \
    \       }\n        }\n    } \n    std::vector<long long> factor(long long n) {\n\
    \        assert(L <= n and n < R);\n        std::vector<long long> ret = large[n\
    \ - L];\n        n /= large_mul[n - L];\n        if(n >= sq) {\n            ret.push_back(n);\n\
    \            return ret;\n        }\n        while(n > 1) {\n            ret.push_back(small[n]);\n\
    \            n /= small[n];\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    long long L, R;\n    int sq;\n    std::vector<int> small;\n    std::vector<std::vector<long\
    \ long>> large;\n    std::vector<long long> large_mul;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\n\nclass SegmentFactorize {\npublic:\n \
    \   explicit SegmentFactorize(long long L, long long R): L(L), R(R), sq(std::sqrt(R)\
    \ + 1) {\n        small.resize(sq);\n        std::iota(small.begin(), small.end(),\
    \ 0);\n        large.resize(R - L);\n        large_mul.assign(R - L, 1);\n   \
    \     for(long long i = 2; i * i < R; i++) {\n            if(small[i] < i) continue;\n\
    \            for(long long j = i * i; j < sq; j += i) {\n                if(small[j]\
    \ == j) small[j] = i;\n            }\n            for(long long j = (L + i - 1)\
    \ / i * i; j < R; j += i) {\n                long long now = j;\n            \
    \    do {\n                    if(large_mul[j - L] * large_mul[j - L] > R) break;\n\
    \                    large[j - L].push_back(i);\n                    large_mul[j\
    \ - L] *= i;\n                    now /= i;\n                } while(now % i ==\
    \ 0);\n            }\n        }\n    } \n    std::vector<long long> factor(long\
    \ long n) {\n        assert(L <= n and n < R);\n        std::vector<long long>\
    \ ret = large[n - L];\n        n /= large_mul[n - L];\n        if(n >= sq) {\n\
    \            ret.push_back(n);\n            return ret;\n        }\n        while(n\
    \ > 1) {\n            ret.push_back(small[n]);\n            n /= small[n];\n \
    \       }\n        return ret;\n    }\n\nprivate:\n    long long L, R;\n    int\
    \ sq;\n    std::vector<int> small;\n    std::vector<std::vector<long long>> large;\n\
    \    std::vector<long long> large_mul;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/segment-factorize.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj2858.test.cpp
documentation_of: math/segment-factorize.hpp
layout: document
redirect_from:
- /library/math/segment-factorize.hpp
- /library/math/segment-factorize.hpp.html
title: math/segment-factorize.hpp
---
