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
  bundledCode: "#line 1 \"math/floor_ceil_sqrt.hpp\"\ntemplate<class T>\nT floor_sqrt(T\
    \ x) {\n    assert(x >= 0);\n    T ok = 0, ng = 1;\n    while(ng * ng <= x) ng\
    \ *= 2;\n    while(ng - ok > 1) {\n        T mid = (ok + ng) / 2;\n        (mid\
    \ * mid <= x ? ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate<class T>\n\
    T ceil_sqrt(T x) {\n    assert(x >= 0);\n    if(x == 0) return (T)0;\n    T ok\
    \ = 1, ng = 0;\n    while(ok * ok <= x) ok *= 2;\n    while(ng - ok > 1) {\n \
    \       T mid = (ok + ng) / 2;\n        (mid * mid >= x ? ok : ng) = mid;\n  \
    \  }\n    return ok;\n}\n"
  code: "template<class T>\nT floor_sqrt(T x) {\n    assert(x >= 0);\n    T ok = 0,\
    \ ng = 1;\n    while(ng * ng <= x) ng *= 2;\n    while(ng - ok > 1) {\n      \
    \  T mid = (ok + ng) / 2;\n        (mid * mid <= x ? ok : ng) = mid;\n    }\n\
    \    return ok;\n}\n\ntemplate<class T>\nT ceil_sqrt(T x) {\n    assert(x >= 0);\n\
    \    if(x == 0) return (T)0;\n    T ok = 1, ng = 0;\n    while(ok * ok <= x) ok\
    \ *= 2;\n    while(ng - ok > 1) {\n        T mid = (ok + ng) / 2;\n        (mid\
    \ * mid >= x ? ok : ng) = mid;\n    }\n    return ok;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_ceil_sqrt.hpp
  requiredBy: []
  timestamp: '2021-03-28 17:58:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_ceil_sqrt.hpp
layout: document
title: "\u5E73\u65B9\u6839(floor, ceil)"
---
