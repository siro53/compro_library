---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki789.test.cpp
    title: test/yukicoder/yuki789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/add.hpp\"\n\ntemplate <typename T>\
    \ struct MonoidAdd {\n    using value_type = T;\n    inline static T op(const\
    \ T &l, const T &r) { return (l + r); }\n    inline static T e() { return T(0);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> struct MonoidAdd {\n    using value_type\
    \ = T;\n    inline static T op(const T &l, const T &r) { return (l + r); }\n \
    \   inline static T e() { return T(0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/add.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/yukicoder/yuki789.test.cpp
documentation_of: data-structure/monoid/add.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/add.hpp
- /library/data-structure/monoid/add.hpp.html
title: data-structure/monoid/add.hpp
---
