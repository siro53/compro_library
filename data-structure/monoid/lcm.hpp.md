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
  bundledCode: "#line 2 \"data-structure/monoid/lcm.hpp\"\n\n#include <numeric>\n\n\
    template <typename T> struct MonoidLCM {\n    using value_type = T;\n    inline\
    \ static T op(const T& l, const T& r) {\n        return std::lcm(l, r);\n    }\n\
    \    inline static T e() { return T(1); }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n\ntemplate <typename T> struct MonoidLCM\
    \ {\n    using value_type = T;\n    inline static T op(const T& l, const T& r)\
    \ {\n        return std::lcm(l, r);\n    }\n    inline static T e() { return T(1);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/lcm.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/lcm.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/lcm.hpp
- /library/data-structure/monoid/lcm.hpp.html
title: data-structure/monoid/lcm.hpp
---
