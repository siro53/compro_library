---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modint/dynamic-modint.hpp
    title: modint/dynamic-modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc104d.test.cpp
    title: test/atcoder/arc104d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/barrett-reduction.hpp\"\n\n#include <utility>\n\nclass\
    \ BarrettReduction {\npublic:\n    BarrettReduction(): BarrettReduction(1) {}\n\
    \    BarrettReduction(unsigned int m)\n        : m(m), m_inv((unsigned long long)(-1)\
    \ / m + 1) {}\n    unsigned int mul(unsigned int a, unsigned int b) const {\n\
    \        unsigned long long z = (unsigned long long)a * b;\n        unsigned long\
    \ long v =  (unsigned long long)(((__uint128_t)z * m_inv) >> 64);\n        unsigned\
    \ int result = (unsigned int)(z - v * m);\n        if(m <= result) result += m;\n\
    \        return result;\n    }\n    unsigned int quo(unsigned int a) const {\n\
    \        unsigned int result = (unsigned int)(((__uint128_t)a * m_inv) >> 64);\n\
    \        return result;\n    }\n    unsigned int rem(unsigned long long a) const\
    \ {\n        unsigned long long v = (unsigned long long)(((__uint128_t)a * m_inv)\
    \ >> 64);\n        unsigned int result = (unsigned int)(a - v * m);\n        if(m\
    \ <= result) result += m;\n        return result;\n    }\n    std::pair<unsigned\
    \ int, unsigned int> quorem(unsigned int a) const {\n        unsigned long long\
    \ v =  (unsigned long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned\
    \ int r = (unsigned int)((unsigned long long)a - v * m);\n        if(m <= r) r\
    \ += m;\n        return {v, r};\n    }\nprivate:\n    unsigned int m;\n    unsigned\
    \ long long m_inv;\n};\n"
  code: "#pragma once\n\n#include <utility>\n\nclass BarrettReduction {\npublic:\n\
    \    BarrettReduction(): BarrettReduction(1) {}\n    BarrettReduction(unsigned\
    \ int m)\n        : m(m), m_inv((unsigned long long)(-1) / m + 1) {}\n    unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n        unsigned long long\
    \ z = (unsigned long long)a * b;\n        unsigned long long v =  (unsigned long\
    \ long)(((__uint128_t)z * m_inv) >> 64);\n        unsigned int result = (unsigned\
    \ int)(z - v * m);\n        if(m <= result) result += m;\n        return result;\n\
    \    }\n    unsigned int quo(unsigned int a) const {\n        unsigned int result\
    \ = (unsigned int)(((__uint128_t)a * m_inv) >> 64);\n        return result;\n\
    \    }\n    unsigned int rem(unsigned long long a) const {\n        unsigned long\
    \ long v = (unsigned long long)(((__uint128_t)a * m_inv) >> 64);\n        unsigned\
    \ int result = (unsigned int)(a - v * m);\n        if(m <= result) result += m;\n\
    \        return result;\n    }\n    std::pair<unsigned int, unsigned int> quorem(unsigned\
    \ int a) const {\n        unsigned long long v =  (unsigned long long)(((__uint128_t)a\
    \ * m_inv) >> 64);\n        unsigned int r = (unsigned int)((unsigned long long)a\
    \ - v * m);\n        if(m <= r) r += m;\n        return {v, r};\n    }\nprivate:\n\
    \    unsigned int m;\n    unsigned long long m_inv;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/barrett-reduction.hpp
  requiredBy:
  - modint/dynamic-modint.hpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/arc104d.test.cpp
documentation_of: math/barrett-reduction.hpp
layout: document
title: Barrett Reduction
---
