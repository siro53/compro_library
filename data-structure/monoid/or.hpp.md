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
  bundledCode: "#line 2 \"data-structure/monoid/or.hpp\"\n\ntemplate <typename T>\
    \ struct MonoidOR {\n    using value_type = T;\n    inline static T op(const T\
    \ &l, const T &r) { return (l | r); }\n    inline static T e() { return T(0);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct MonoidOR {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return (l | r); }\n \
    \   inline static T e() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/or.hpp
  requiredBy: []
  timestamp: '2023-12-16 20:03:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/or.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/or.hpp
- /library/data-structure/monoid/or.hpp.html
title: data-structure/monoid/or.hpp
---
