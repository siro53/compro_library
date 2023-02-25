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
  bundledCode: "#line 2 \"data-structure/monoid/min_index.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n#include <utility>\n\ntemplate <typename T> struct MonoidMinWithIndex\
    \ {\n    using S = std::pair<T, int>;\n    using value_type = S;\n    inline static\
    \ S op(const S &l, const S &r) { return std::min(l, r); }\n    inline static S\
    \ e() {\n        return std::make_pair(std::numeric_limits<T>::max(), -1);\n \
    \   }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    \ntemplate <typename T> struct MonoidMinWithIndex {\n    using S = std::pair<T,\
    \ int>;\n    using value_type = S;\n    inline static S op(const S &l, const S\
    \ &r) { return std::min(l, r); }\n    inline static S e() {\n        return std::make_pair(std::numeric_limits<T>::max(),\
    \ -1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoid/min_index.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoid/min_index.hpp
layout: document
redirect_from:
- /library/data-structure/monoid/min_index.hpp
- /library/data-structure/monoid/min_index.hpp.html
title: data-structure/monoid/min_index.hpp
---
