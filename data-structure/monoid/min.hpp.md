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
  bundledCode: "#line 2 \"data-structure/monoid/min.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n\ntemplate <typename T> struct MonoidMin {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return std::min(l, r);\
    \ }\n    inline static T e() { return std::numeric_limits<T>::max(); }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\ntemplate <typename\
    \ T> struct MonoidMin {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return std::min(l, r); }\n    inline static T e() { return\
    \ std::numeric_limits<T>::max(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/min.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/min.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/min.hpp
- /library/data-structure/monoid/min.hpp.html
title: data-structure/monoid/min.hpp
---
