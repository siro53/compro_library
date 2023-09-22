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
    - https://hotman78.hatenablog.com/entry/2020/06/17/102519
  bundledCode: "#line 2 \"data-structure/monoid/kadane.hpp\"\n\n#include <limits>\n\
    #include <algorithm>\n\n// ref: https://hotman78.hatenablog.com/entry/2020/06/17/102519\n\
    template <typename T> struct MonoidKadane {\n    struct S {\n        T lmax, rmax,\
    \ allmax, sum;\n        S() = default;\n        S(T lmax, T rmax, T allmax, T\
    \ sum)\n            : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}\n  \
    \  };\n    using value_type = S;\n    inline static S op(const S &l, const S &r)\
    \ {\n        T lmax = std::max(l.lmax, l.sum + r.lmax);\n        T rmax = std::max(r.rmax,\
    \ l.rmax + r.sum);\n        T allmax = std::max({l.allmax, r.allmax, l.rmax +\
    \ r.lmax});\n        T sum = l.sum + r.sum;\n        return S(lmax, rmax, allmax,\
    \ sum);\n    }\n    inline static S e() {\n        T m = std::numeric_limits<T>::min();\n\
    \        return S(m, m, m, T(0));\n    }\n};\n"
  code: "#pragma once\n\n#include <limits>\n#include <algorithm>\n\n// ref: https://hotman78.hatenablog.com/entry/2020/06/17/102519\n\
    template <typename T> struct MonoidKadane {\n    struct S {\n        T lmax, rmax,\
    \ allmax, sum;\n        S() = default;\n        S(T lmax, T rmax, T allmax, T\
    \ sum)\n            : lmax(lmax), rmax(rmax), allmax(allmax), sum(sum) {}\n  \
    \  };\n    using value_type = S;\n    inline static S op(const S &l, const S &r)\
    \ {\n        T lmax = std::max(l.lmax, l.sum + r.lmax);\n        T rmax = std::max(r.rmax,\
    \ l.rmax + r.sum);\n        T allmax = std::max({l.allmax, r.allmax, l.rmax +\
    \ r.lmax});\n        T sum = l.sum + r.sum;\n        return S(lmax, rmax, allmax,\
    \ sum);\n    }\n    inline static S e() {\n        T m = std::numeric_limits<T>::min();\n\
    \        return S(m, m, m, T(0));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/kadane.hpp
  requiredBy: []
  timestamp: '2023-09-22 12:39:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/kadane.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/kadane.hpp
- /library/data-structure/monoid/kadane.hpp.html
title: data-structure/monoid/kadane.hpp
---
