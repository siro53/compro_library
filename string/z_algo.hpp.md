---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/zalgorothm.test.cpp
    title: test/zalgorothm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/z_algo.hpp\"\n// \u3059\u3079\u30660-indexed\n//\
    \ n := |S| \u3068\u3059\u308B\u3002\n// s[i,j] := s\u306E[i,j]\u306E\u7BC4\u56F2\
    \u306E\u9023\u7D9A\u90E8\u5206\u6587\u5B57\u5217\u3068\u3059\u308B\u3002\u3053\
    \u306E\u3068\u304D\u3001\n// s[0, n-1](= s)\u3068s[i, n-1]\u306E\u6700\u9577\u5171\
    \u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u3092\u8A18\u9332\u3057\u305F\u914D\
    \u5217\u3092\u8FD4\u3059\u3002\n// \u8A08\u7B97\u91CF\u306FO(|S|)\nvector<int>\
    \ z_algo(const string &s) {\n    int c = 0, n = (int)s.size();\n    vector<int>\
    \ z(n, 0);\n    for(int i = 1; i < n; i++) {\n        if(i + z[i - c] < c + z[c])\
    \ {\n            z[i] = z[i - c];\n        } else {\n            int j = max(0,\
    \ c + z[c] - i);\n            while(i + j < n && s[j] == s[i + j]) {\n       \
    \         j++;\n            }\n            z[i] = j;\n            c = i;\n   \
    \     }\n    }\n    z[0] = n;\n    return z;\n}\n"
  code: "// \u3059\u3079\u30660-indexed\n// n := |S| \u3068\u3059\u308B\u3002\n//\
    \ s[i,j] := s\u306E[i,j]\u306E\u7BC4\u56F2\u306E\u9023\u7D9A\u90E8\u5206\u6587\
    \u5B57\u5217\u3068\u3059\u308B\u3002\u3053\u306E\u3068\u304D\u3001\n// s[0, n-1](=\
    \ s)\u3068s[i, n-1]\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\
    \u3055\u3092\u8A18\u9332\u3057\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\n// \u8A08\
    \u7B97\u91CF\u306FO(|S|)\nvector<int> z_algo(const string &s) {\n    int c = 0,\
    \ n = (int)s.size();\n    vector<int> z(n, 0);\n    for(int i = 1; i < n; i++)\
    \ {\n        if(i + z[i - c] < c + z[c]) {\n            z[i] = z[i - c];\n   \
    \     } else {\n            int j = max(0, c + z[c] - i);\n            while(i\
    \ + j < n && s[j] == s[i + j]) {\n                j++;\n            }\n      \
    \      z[i] = j;\n            c = i;\n        }\n    }\n    z[0] = n;\n    return\
    \ z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algo.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/zalgorothm.test.cpp
documentation_of: string/z_algo.hpp
layout: document
redirect_from:
- /library/string/z_algo.hpp
- /library/string/z_algo.hpp.html
title: string/z_algo.hpp
---
