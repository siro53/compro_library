---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/library-checker/data-structure/point-set-range-composite.cpp
    title: test/library-checker/data-structure/point-set-range-composite.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/affine.hpp\"\n\n#include <utility>\n\
    \ntemplate <typename T, bool rev = false> struct MonoidAffine {\n    using S =\
    \ std::pair<T, T>;\n    using value_type = S;\n    inline static S op(const S\
    \ &l, const S &r) {\n        if(rev) return S(r.first * l.first, r.first * l.second\
    \ + r.second);\n        return S(l.first * r.first, l.first * r.second + l.second);\n\
    \    }\n    inline static S e() { return S(T(1), T(0)); }\n};\n"
  code: "#pragma once\n\n#include <utility>\n\ntemplate <typename T, bool rev = false>\
    \ struct MonoidAffine {\n    using S = std::pair<T, T>;\n    using value_type\
    \ = S;\n    inline static S op(const S &l, const S &r) {\n        if(rev) return\
    \ S(r.first * l.first, r.first * l.second + r.second);\n        return S(l.first\
    \ * r.first, l.first * r.second + l.second);\n    }\n    inline static S e() {\
    \ return S(T(1), T(0)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/affine.hpp
  requiredBy:
  - test/library-checker/data-structure/point-set-range-composite.cpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
documentation_of: data-structure/monoid/affine.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/affine.hpp
- /library/data-structure/monoid/affine.hpp.html
title: data-structure/monoid/affine.hpp
---
