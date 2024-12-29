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
  bundledCode: "#line 2 \"misc/subset-iterator.hpp\"\n\n#include <cstdint>\n\nstruct\
    \ Subset {\n    struct SubsetIter {\n        uint32_t S, T;\n        bool is_end;\n\
    \n        SubsetIter(uint32_t s): S(s), T(s), is_end(false) {}\n\n        auto\
    \ operator*() const { return T; }\n        auto operator++() { T = (T - 1) & S;\
    \ }\n        auto operator!=(std::nullptr_t) {\n            if(is_end) return\
    \ false;\n            is_end = (T == 0);\n            return true;\n        }\n\
    \    };\n\n    uint32_t S;\n\n    Subset(uint32_t s): S(s) {}\n    auto begin()\
    \ { return SubsetIter(S); }\n    auto end() { return nullptr; }\n};\n"
  code: "#pragma once\n\n#include <cstdint>\n\nstruct Subset {\n    struct SubsetIter\
    \ {\n        uint32_t S, T;\n        bool is_end;\n\n        SubsetIter(uint32_t\
    \ s): S(s), T(s), is_end(false) {}\n\n        auto operator*() const { return\
    \ T; }\n        auto operator++() { T = (T - 1) & S; }\n        auto operator!=(std::nullptr_t)\
    \ {\n            if(is_end) return false;\n            is_end = (T == 0);\n  \
    \          return true;\n        }\n    };\n\n    uint32_t S;\n\n    Subset(uint32_t\
    \ s): S(s) {}\n    auto begin() { return SubsetIter(S); }\n    auto end() { return\
    \ nullptr; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/subset-iterator.hpp
  requiredBy: []
  timestamp: '2024-12-30 01:17:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/subset-iterator.hpp
layout: document
redirect_from:
- /library/misc/subset-iterator.hpp
- /library/misc/subset-iterator.hpp.html
title: misc/subset-iterator.hpp
---
