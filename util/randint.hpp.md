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
  bundledCode: "#line 1 \"util/randint.hpp\"\nstruct random_number_generator {\n \
    \   mt19937 mt;\n    random_number_generator():mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    int operator()(int a, int b) {\n        uniform_int_distribution<int>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    int operator()(int b)\
    \ {\n        return (*this)(0, b);\n    }\n};\n"
  code: "struct random_number_generator {\n    mt19937 mt;\n    random_number_generator():mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    int operator()(int a, int b) {\n        uniform_int_distribution<int>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    int operator()(int b)\
    \ {\n        return (*this)(0, b);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/randint.hpp
  requiredBy: []
  timestamp: '2021-03-14 11:30:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/randint.hpp
layout: document
redirect_from:
- /library/util/randint.hpp
- /library/util/randint.hpp.html
title: util/randint.hpp
---
