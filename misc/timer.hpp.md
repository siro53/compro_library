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
  bundledCode: "#line 2 \"misc/timer.hpp\"\n\n#include <chrono>\n\nstruct Timer {\n\
    \    std::chrono::high_resolution_clock::time_point start_time;\n\n    Timer()\
    \ { reset(); }\n\n    // \u30BF\u30A4\u30DE\u30FC\u3092\u30EA\u30BB\u30C3\u30C8\
    \u3059\u308B\n    void reset() {\n        start_time = std::chrono::high_resolution_clock::now();\n\
    \    }\n\n    // \u30BF\u30A4\u30DE\u30FC\u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\
    \u4F55 milliseconds \u7D4C\u904E\u3057\u305F\u304B\u3092\u8FD4\u3059\n    long\
    \ long elapsed() {\n        auto end_time = std::chrono::high_resolution_clock::now();\n\
    \        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time\
    \ - start_time);\n        return elapsed_time.count();\n    }\n\n    // \u30BF\
    \u30A4\u30DE\u30FC\u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\u4F55 milliseconds\
    \ \u7D4C\u904E\u3057\u305F\u304B\u3092\u8FD4\u3059\n    auto operator()() { return\
    \ elapsed(); }\n};\n"
  code: "#pragma once\n\n#include <chrono>\n\nstruct Timer {\n    std::chrono::high_resolution_clock::time_point\
    \ start_time;\n\n    Timer() { reset(); }\n\n    // \u30BF\u30A4\u30DE\u30FC\u3092\
    \u30EA\u30BB\u30C3\u30C8\u3059\u308B\n    void reset() {\n        start_time =\
    \ std::chrono::high_resolution_clock::now();\n    }\n\n    // \u30BF\u30A4\u30DE\
    \u30FC\u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\u4F55 milliseconds \u7D4C\u904E\
    \u3057\u305F\u304B\u3092\u8FD4\u3059\n    long long elapsed() {\n        auto\
    \ end_time = std::chrono::high_resolution_clock::now();\n        auto elapsed_time\
    \ = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);\n\
    \        return elapsed_time.count();\n    }\n\n    // \u30BF\u30A4\u30DE\u30FC\
    \u30BB\u30C3\u30C8\u3057\u3066\u304B\u3089\u4F55 milliseconds \u7D4C\u904E\u3057\
    \u305F\u304B\u3092\u8FD4\u3059\n    auto operator()() { return elapsed(); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2025-03-09 11:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
