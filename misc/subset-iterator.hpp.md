---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascon24/submissions/61272051
  bundledCode: "#line 2 \"misc/subset-iterator.hpp\"\n\n#include <cstdint>\n#include\
    \ <x86intrin.h>\n\n// Subset(S) := S\u306E\u90E8\u5206\u96C6\u5408\u3092\u8D70\
    \u67FB\u3059\u308B\nstruct Subset {\n    struct SubsetIter {\n        uint32_t\
    \ S, T;\n        bool is_end;\n\n        SubsetIter(uint32_t s): S(s), T(s), is_end(false)\
    \ {}\n\n        auto operator*() const { return T; }\n        auto operator++()\
    \ { T = (T - 1) & S; }\n        auto operator!=(std::nullptr_t) {\n          \
    \  if(is_end) return false;\n            is_end = (T == 0);\n            return\
    \ true;\n        }\n    };\n\n    uint32_t S;\n\n    Subset(uint32_t s): S(s)\
    \ {}\n    auto begin() { return SubsetIter(S); }\n    auto end() { return nullptr;\
    \ }\n};\n\n// Subset_k(S, k) := S\u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\
    \u3001size\u304Ck\u306E\u96C6\u5408\u306E\u307F\u8D70\u67FB\u3059\u308B\n// verify:\
    \ https://atcoder.jp/contests/xmascon24/submissions/61272051\nstruct Subset_k\
    \ {\n    struct SubsetIter_k {\n        const uint32_t n, k, S;\n        uint32_t\
    \ T;\n\n        SubsetIter_k(uint32_t S, uint32_t k): n(uint32_t(1) << __builtin_popcount(S)),\
    \ k(k), S(S), T((uint32_t(1) << k) - 1) {}\n\n        __attribute__((target(\"\
    bmi2\")))\n        auto operator*() const { return _pdep_u32(T, S); }\n\n    \
    \    __attribute__((target(\"bmi\")))\n        auto operator++() {\n         \
    \   uint32_t y = T + _blsi_u32(T);\n            T = y | (__andn_u32(y, T) >> _tzcnt_u32(T\
    \ << 1));\n        }\n        auto operator!=(std::nullptr_t) const { return T\
    \ < n; }\n    };\n\n    uint32_t S, k;\n    \n    Subset_k(uint32_t S, uint32_t\
    \ k): S(S), k(k) {\n        assert(k != 0);\n    }\n\n    auto begin() { return\
    \ SubsetIter_k(S, k); }\n    auto end() { return nullptr; }\n};\n\n// SetBit(S)\
    \ := S\u306E\u3046\u3061\u3001bit\u304C\u7ACB\u3063\u3066\u3044\u308Bindex\u3092\
    \u5C0F\u3055\u3044\u9806\u306B\u8FD4\u3059\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct SetBit {\n    struct SetBitIter {\n        uint32_t S;\n\n        SetBitIter(uint32_t\
    \ S): S(S) {}\n\n        __attribute__((target(\"bmi\")))\n        auto operator*()\
    \ { return _tzcnt_u32(S); }\n\n        __attribute__((target(\"bmi\")))\n    \
    \    auto operator++() { S = _blsr_u32(S); }\n\n        auto operator!=(std::nullptr_t)\
    \ { return S; }\n    };\n\n    uint32_t S;\n\n    SetBit(uint32_t S): S(S) {}\n\
    \n    auto begin() { return SetBitIter(S); }\n    auto end() { return nullptr;\
    \ }\n};\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <x86intrin.h>\n\n// Subset(S)\
    \ := S\u306E\u90E8\u5206\u96C6\u5408\u3092\u8D70\u67FB\u3059\u308B\nstruct Subset\
    \ {\n    struct SubsetIter {\n        uint32_t S, T;\n        bool is_end;\n\n\
    \        SubsetIter(uint32_t s): S(s), T(s), is_end(false) {}\n\n        auto\
    \ operator*() const { return T; }\n        auto operator++() { T = (T - 1) & S;\
    \ }\n        auto operator!=(std::nullptr_t) {\n            if(is_end) return\
    \ false;\n            is_end = (T == 0);\n            return true;\n        }\n\
    \    };\n\n    uint32_t S;\n\n    Subset(uint32_t s): S(s) {}\n    auto begin()\
    \ { return SubsetIter(S); }\n    auto end() { return nullptr; }\n};\n\n// Subset_k(S,\
    \ k) := S\u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u3001size\u304Ck\u306E\
    \u96C6\u5408\u306E\u307F\u8D70\u67FB\u3059\u308B\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct Subset_k {\n    struct SubsetIter_k {\n        const uint32_t n, k, S;\n\
    \        uint32_t T;\n\n        SubsetIter_k(uint32_t S, uint32_t k): n(uint32_t(1)\
    \ << __builtin_popcount(S)), k(k), S(S), T((uint32_t(1) << k) - 1) {}\n\n    \
    \    __attribute__((target(\"bmi2\")))\n        auto operator*() const { return\
    \ _pdep_u32(T, S); }\n\n        __attribute__((target(\"bmi\")))\n        auto\
    \ operator++() {\n            uint32_t y = T + _blsi_u32(T);\n            T =\
    \ y | (__andn_u32(y, T) >> _tzcnt_u32(T << 1));\n        }\n        auto operator!=(std::nullptr_t)\
    \ const { return T < n; }\n    };\n\n    uint32_t S, k;\n    \n    Subset_k(uint32_t\
    \ S, uint32_t k): S(S), k(k) {\n        assert(k != 0);\n    }\n\n    auto begin()\
    \ { return SubsetIter_k(S, k); }\n    auto end() { return nullptr; }\n};\n\n//\
    \ SetBit(S) := S\u306E\u3046\u3061\u3001bit\u304C\u7ACB\u3063\u3066\u3044\u308B\
    index\u3092\u5C0F\u3055\u3044\u9806\u306B\u8FD4\u3059\n// verify: https://atcoder.jp/contests/xmascon24/submissions/61272051\n\
    struct SetBit {\n    struct SetBitIter {\n        uint32_t S;\n\n        SetBitIter(uint32_t\
    \ S): S(S) {}\n\n        __attribute__((target(\"bmi\")))\n        auto operator*()\
    \ { return _tzcnt_u32(S); }\n\n        __attribute__((target(\"bmi\")))\n    \
    \    auto operator++() { S = _blsr_u32(S); }\n\n        auto operator!=(std::nullptr_t)\
    \ { return S; }\n    };\n\n    uint32_t S;\n\n    SetBit(uint32_t S): S(S) {}\n\
    \n    auto begin() { return SetBitIter(S); }\n    auto end() { return nullptr;\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/subset-iterator.hpp
  requiredBy: []
  timestamp: '2025-03-09 11:06:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/subset-iterator.hpp
layout: document
redirect_from:
- /library/misc/subset-iterator.hpp
- /library/misc/subset-iterator.hpp.html
title: misc/subset-iterator.hpp
---
