---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: test/mytest/bundle/fixtures/include/value.hpp
    title: test/mytest/bundle/fixtures/include/value.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"test/mytest/bundle/fixtures/include/answer.hpp\"\n\n#line\
    \ 2 \"test/mytest/bundle/fixtures/include/value.hpp\"\n\nconstexpr int value =\
    \ 42;\n#line 4 \"test/mytest/bundle/fixtures/include/answer.hpp\"\n\nint answer()\
    \ {\n    return value;\n}\n"
  code: "#pragma once\n\n#include \"value.hpp\"\n\nint answer() {\n    return value;\n\
    }\n"
  dependsOn:
  - test/mytest/bundle/fixtures/include/value.hpp
  isVerificationFile: false
  path: test/mytest/bundle/fixtures/include/answer.hpp
  requiredBy: []
  timestamp: '2026-11-01 14:21:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/mytest/bundle/fixtures/include/answer.hpp
layout: document
redirect_from:
- /library/test/mytest/bundle/fixtures/include/answer.hpp
- /library/test/mytest/bundle/fixtures/include/answer.hpp.html
title: test/mytest/bundle/fixtures/include/answer.hpp
---
