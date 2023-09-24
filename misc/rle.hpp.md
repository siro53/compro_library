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
  bundledCode: "#line 2 \"misc/rle.hpp\"\n\n#include <string>\n#include <vector>\n\
    #include <utility>\n\ntemplate<class T>\nstd::vector<std::pair<T, int>> runlength_encoding(const\
    \ std::vector<T>& v) {\n    std::vector<std::pair<T, int>> ret = {{v[0], 1}};\n\
    \    for(size_t i = 1; i < v.size(); i++) {\n        if(ret.back().first == v[i])\
    \ ret.back().second++;\n        else ret.emplace_back(v[i], 1);\n    }\n    return\
    \ ret;\n}\n\nstd::vector<std::pair<char, int>> runlength_encoding(const std::string&\
    \ s) {\n    std::vector<std::pair<char, int>> ret = {{s[0], 1}};\n    for(size_t\
    \ i = 1; i < s.size(); i++) {\n        if(ret.back().first == s[i]) ret.back().second++;\n\
    \        else ret.emplace_back(s[i], 1);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n#include <utility>\n\
    \ntemplate<class T>\nstd::vector<std::pair<T, int>> runlength_encoding(const std::vector<T>&\
    \ v) {\n    std::vector<std::pair<T, int>> ret = {{v[0], 1}};\n    for(size_t\
    \ i = 1; i < v.size(); i++) {\n        if(ret.back().first == v[i]) ret.back().second++;\n\
    \        else ret.emplace_back(v[i], 1);\n    }\n    return ret;\n}\n\nstd::vector<std::pair<char,\
    \ int>> runlength_encoding(const std::string& s) {\n    std::vector<std::pair<char,\
    \ int>> ret = {{s[0], 1}};\n    for(size_t i = 1; i < s.size(); i++) {\n     \
    \   if(ret.back().first == s[i]) ret.back().second++;\n        else ret.emplace_back(s[i],\
    \ 1);\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rle.hpp
  requiredBy: []
  timestamp: '2023-09-25 02:57:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/rle.hpp
layout: document
redirect_from:
- /library/misc/rle.hpp
- /library/misc/rle.hpp.html
title: misc/rle.hpp
---
