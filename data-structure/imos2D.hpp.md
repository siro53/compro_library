---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc276ex.test.cpp
    title: test/atcoder/abc276ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/imos2D.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename T> \nclass imos2D {\npublic:\n    int H, W;\n\
    \n    imos2D() = default;\n    explicit imos2D(int H, int W): H(H), W(W), imos(H\
    \ + 1, std::vector<T>(W + 1, 0)), isBuilt(false) {}\n\n    void add(int li, int\
    \ lj, int ri, int rj, T val) {\n        assert(0 <= li and li < H);\n        assert(li\
    \ <= ri and ri <= H);\n        assert(0 <= lj and lj < W);\n        assert(lj\
    \ <= rj and rj <= W);\n        imos[li][lj] += val;\n        imos[li][rj] -= val;\n\
    \        imos[ri][lj] -= val;\n        imos[ri][rj] += val;\n    } \n\n    void\
    \ build() {\n        for(int i = 0; i <= H; i++) {\n            for(int j = 1;\
    \ j <= W; j++) {\n                imos[i][j] += imos[i][j - 1];\n            }\n\
    \        }\n        for(int j = 0; j <= W; j++) {\n            for(int i = 1;\
    \ i <= H; i++) {\n                imos[i][j] += imos[i - 1][j];\n            }\n\
    \        }\n        isBuilt = true;\n    }\n\n    inline std::vector<T>& operator[](int\
    \ i) {\n        assert(isBuilt);\n        return imos[i];\n    }\n\nprivate:\n\
    \    std::vector<std::vector<T>> imos;\n    bool isBuilt;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> \nclass imos2D {\npublic:\n    int H, W;\n\n    imos2D() = default;\n   \
    \ explicit imos2D(int H, int W): H(H), W(W), imos(H + 1, std::vector<T>(W + 1,\
    \ 0)), isBuilt(false) {}\n\n    void add(int li, int lj, int ri, int rj, T val)\
    \ {\n        assert(0 <= li and li < H);\n        assert(li <= ri and ri <= H);\n\
    \        assert(0 <= lj and lj < W);\n        assert(lj <= rj and rj <= W);\n\
    \        imos[li][lj] += val;\n        imos[li][rj] -= val;\n        imos[ri][lj]\
    \ -= val;\n        imos[ri][rj] += val;\n    } \n\n    void build() {\n      \
    \  for(int i = 0; i <= H; i++) {\n            for(int j = 1; j <= W; j++) {\n\
    \                imos[i][j] += imos[i][j - 1];\n            }\n        }\n   \
    \     for(int j = 0; j <= W; j++) {\n            for(int i = 1; i <= H; i++) {\n\
    \                imos[i][j] += imos[i - 1][j];\n            }\n        }\n   \
    \     isBuilt = true;\n    }\n\n    inline std::vector<T>& operator[](int i) {\n\
    \        assert(isBuilt);\n        return imos[i];\n    }\n\nprivate:\n    std::vector<std::vector<T>>\
    \ imos;\n    bool isBuilt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/imos2D.hpp
  requiredBy: []
  timestamp: '2024-12-15 14:15:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc276ex.test.cpp
documentation_of: data-structure/imos2D.hpp
layout: document
redirect_from:
- /library/data-structure/imos2D.hpp
- /library/data-structure/imos2D.hpp.html
title: data-structure/imos2D.hpp
---
