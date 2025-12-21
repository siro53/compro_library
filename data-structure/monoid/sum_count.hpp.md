---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/utils/sum_count_manager.hpp
    title: data-structure/utils/sum_count_manager.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/monoid/sum_count.hpp\"\n\ntemplate <typename\
    \ sum_t, typename count_t> struct MonoidSumCount {\n    struct S {\n        sum_t\
    \ sum;\n        count_t cnt;\n        S() = default;\n        S(sum_t sum, count_t\
    \ cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type = S;\n    inline static\
    \ S op(const S& l, const S& r) {\n        return S(l.sum + r.sum, l.cnt + r.cnt);\n\
    \    }\n    inline static S e() { return S(sum_t(0), count_t(0)); }\n};\n"
  code: "#pragma once\n\ntemplate <typename sum_t, typename count_t> struct MonoidSumCount\
    \ {\n    struct S {\n        sum_t sum;\n        count_t cnt;\n        S() = default;\n\
    \        S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type\
    \ = S;\n    inline static S op(const S& l, const S& r) {\n        return S(l.sum\
    \ + r.sum, l.cnt + r.cnt);\n    }\n    inline static S e() { return S(sum_t(0),\
    \ count_t(0)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/sum_count.hpp
  requiredBy:
  - data-structure/utils/sum_count_manager.hpp
  timestamp: '2025-12-21 17:21:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/sum_count.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/sum_count.hpp
- /library/data-structure/monoid/sum_count.hpp.html
title: data-structure/monoid/sum_count.hpp
---
