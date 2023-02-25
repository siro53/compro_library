---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj-ALDS1-1-C_2.test.cpp
    title: test/aoj/aoj-ALDS1-1-C_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2858.test.cpp
    title: test/aoj/aoj2858.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/eratosthenes.hpp\"\n\n#include <vector>\n\nclass Eratosthenes\
    \ {\n  public:\n    Eratosthenes() {}\n    explicit Eratosthenes(int n) : n(n),\
    \ isp(n + 1, true) {\n        isp[0] = isp[1] = false;\n        for(int i = 2;\
    \ i * i <= n; i++) {\n            if(!isp[i]) continue;\n            for(int j\
    \ = i * i; j <= n; j += i) isp[j] = false;\n        }\n    }\n    bool operator[](int\
    \ k) const { return isp[k]; }\n\n  private:\n    int n;\n    std::vector<bool>\
    \ isp;\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nclass Eratosthenes {\n  public:\n  \
    \  Eratosthenes() {}\n    explicit Eratosthenes(int n) : n(n), isp(n + 1, true)\
    \ {\n        isp[0] = isp[1] = false;\n        for(int i = 2; i * i <= n; i++)\
    \ {\n            if(!isp[i]) continue;\n            for(int j = i * i; j <= n;\
    \ j += i) isp[j] = false;\n        }\n    }\n    bool operator[](int k) const\
    \ { return isp[k]; }\n\n  private:\n    int n;\n    std::vector<bool> isp;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj-ALDS1-1-C_2.test.cpp
  - test/aoj/aoj2858.test.cpp
documentation_of: math/eratosthenes.hpp
layout: document
redirect_from:
- /library/math/eratosthenes.hpp
- /library/math/eratosthenes.hpp.html
title: math/eratosthenes.hpp
---
