---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/string/z-algorithm.test.cpp
    title: test/library-checker/string/z-algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z-algo.hpp\"\n\n#include <vector>\n#include <string>\n\
    \nstd::vector<int> z_algo(const std::string& s) {\n    int n = (int)s.size();\n\
    \    std::vector<int> z(n);\n    z[0] = n;\n    for(int i = 1, j = 0; i < n;)\
    \ {\n        while(i + j < n and s[j] == s[i + j]) j++;\n        z[i] = j;\n \
    \       if(j == 0) {\n            i++;\n            continue;\n        }\n   \
    \     int k = 1;\n        while(k < j and k + z[k] < j) {\n            z[i + k]\
    \ = z[k];\n            k++;\n        }\n        i += k;\n        j -= k;\n   \
    \ }\n    return z;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nstd::vector<int>\
    \ z_algo(const std::string& s) {\n    int n = (int)s.size();\n    std::vector<int>\
    \ z(n);\n    z[0] = n;\n    for(int i = 1, j = 0; i < n;) {\n        while(i +\
    \ j < n and s[j] == s[i + j]) j++;\n        z[i] = j;\n        if(j == 0) {\n\
    \            i++;\n            continue;\n        }\n        int k = 1;\n    \
    \    while(k < j and k + z[k] < j) {\n            z[i + k] = z[k];\n         \
    \   k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algo.hpp
  requiredBy: []
  timestamp: '2024-05-04 17:59:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/string/z-algorithm.test.cpp
documentation_of: string/z-algo.hpp
layout: document
redirect_from:
- /library/string/z-algo.hpp
- /library/string/z-algo.hpp.html
title: string/z-algo.hpp
---
