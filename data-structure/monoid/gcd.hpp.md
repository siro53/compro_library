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
  bundledCode: "#line 2 \"data-structure/monoid/gcd.hpp\"\n\n#include <numeric>\n\n\
    template <typename T> struct MonoidGCD {\n    using value_type = T;\n    inline\
    \ static T op(const T& l, const T& r) {\n        return std::gcd(l, r);\n    }\n\
    \    inline static T e() { return T(0); }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n\ntemplate <typename T> struct MonoidGCD\
    \ {\n    using value_type = T;\n    inline static T op(const T& l, const T& r)\
    \ {\n        return std::gcd(l, r);\n    }\n    inline static T e() { return T(0);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/gcd.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/gcd.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/gcd.hpp
- /library/data-structure/monoid/gcd.hpp.html
title: data-structure/monoid/gcd.hpp
---
