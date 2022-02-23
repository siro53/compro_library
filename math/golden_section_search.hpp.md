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
    - https://twitter.com/noshi91/status/1316352023609004033
  bundledCode: "#line 1 \"math/golden_section_search.hpp\"\n// [l, r]\n// \u8A73\u7D30\
    \uFF1Ahttps://twitter.com/noshi91/status/1316352023609004033\ntemplate<class F>\
    \ ll golden_section_search(ll l, ll r, F f) {\n    l--, r++;\n    ll a = 1, b\
    \ = 1;\n    while(a + b < r - l) {\n        a += b;\n        swap(a, b);\n   \
    \ }\n    auto fl = f(l+a), fr = f(l+b);\n    while(a < b) {\n        b -= a;\n\
    \        swap(a, b);\n        if(fl < fr) {\n            fr = fl;\n          \
    \  fl = f(l + a);\n        }\n        else {\n            l += b;\n          \
    \  if(l + b < r) {\n                fl = fr;\n                fr = f(l + b);\n\
    \            }\n            else {\n                b -= a;\n                swap(a,\
    \ b);\n                fl = f(l + a);\n            }\n        }\n    }\n    return\
    \ l + 1;\n}\n"
  code: "// [l, r]\n// \u8A73\u7D30\uFF1Ahttps://twitter.com/noshi91/status/1316352023609004033\n\
    template<class F> ll golden_section_search(ll l, ll r, F f) {\n    l--, r++;\n\
    \    ll a = 1, b = 1;\n    while(a + b < r - l) {\n        a += b;\n        swap(a,\
    \ b);\n    }\n    auto fl = f(l+a), fr = f(l+b);\n    while(a < b) {\n       \
    \ b -= a;\n        swap(a, b);\n        if(fl < fr) {\n            fr = fl;\n\
    \            fl = f(l + a);\n        }\n        else {\n            l += b;\n\
    \            if(l + b < r) {\n                fl = fr;\n                fr = f(l\
    \ + b);\n            }\n            else {\n                b -= a;\n        \
    \        swap(a, b);\n                fl = f(l + a);\n            }\n        }\n\
    \    }\n    return l + 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/golden_section_search.hpp
  requiredBy: []
  timestamp: '2022-02-23 12:54:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/golden_section_search.hpp
layout: document
redirect_from:
- /library/math/golden_section_search.hpp
- /library/math/golden_section_search.hpp.html
title: math/golden_section_search.hpp
---
