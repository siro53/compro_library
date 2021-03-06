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
  bundledCode: "#line 1 \"util/get_time.hpp\"\ninline double get_time() {\n    const\
    \ double ticks_per_sec = 2500000000;\n    uint32_t lo, hi;\n    asm volatile(\"\
    rdtsc\" : \"=a\"(lo), \"=d\"(hi));\n    return (((uint64_t)hi << 32) | lo) / ticks_per_sec;\n\
    }\n\n\n"
  code: "inline double get_time() {\n    const double ticks_per_sec = 2500000000;\n\
    \    uint32_t lo, hi;\n    asm volatile(\"rdtsc\" : \"=a\"(lo), \"=d\"(hi));\n\
    \    return (((uint64_t)hi << 32) | lo) / ticks_per_sec;\n}\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: util/get_time.hpp
  requiredBy: []
  timestamp: '2021-03-06 10:35:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/get_time.hpp
layout: document
redirect_from:
- /library/util/get_time.hpp
- /library/util/get_time.hpp.html
title: util/get_time.hpp
---
