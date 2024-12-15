---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj2426.test.cpp
    title: test/aoj/aoj2426.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc276ex.test.cpp
    title: test/atcoder/abc276ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sum2D.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename T> class sum2D {\n  public:\n    sum2D() = default;\n\
    \    explicit sum2D(int height, int width)\n        : sum(height + 1, std::vector<T>(width\
    \ + 1, 0)), isBuilt(false) {}\n    void add(int row, int column, T val) {\n  \
    \      assert(0 <= row + 1 && row + 1 < (int)sum.size());\n        assert(0 <=\
    \ column + 1 && column + 1 < (int)sum[0].size());\n        sum[row + 1][column\
    \ + 1] += val;\n    }\n    void build() {\n        for(int i = 1; i < (int)sum.size();\
    \ i++) {\n            for(int j = 1; j < (int)sum[0].size(); j++) {\n        \
    \        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];\n   \
    \         }\n        }\n        isBuilt = true;\n    }\n    T get_sum(int row_l,\
    \ int row_r, int column_l, int column_r) const {\n        assert(row_l <= row_r);\n\
    \        assert(column_l <= column_r);\n        assert(isBuilt);\n        return\
    \ (sum[row_r][column_r] - sum[row_l][column_r] -\n                sum[row_r][column_l]\
    \ + sum[row_l][column_l]);\n    }\n\n  private:\n    std::vector<std::vector<T>>\
    \ sum;\n    bool isBuilt;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> class sum2D {\n  public:\n    sum2D() = default;\n    explicit sum2D(int\
    \ height, int width)\n        : sum(height + 1, std::vector<T>(width + 1, 0)),\
    \ isBuilt(false) {}\n    void add(int row, int column, T val) {\n        assert(0\
    \ <= row + 1 && row + 1 < (int)sum.size());\n        assert(0 <= column + 1 &&\
    \ column + 1 < (int)sum[0].size());\n        sum[row + 1][column + 1] += val;\n\
    \    }\n    void build() {\n        for(int i = 1; i < (int)sum.size(); i++) {\n\
    \            for(int j = 1; j < (int)sum[0].size(); j++) {\n                sum[i][j]\
    \ += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];\n            }\n     \
    \   }\n        isBuilt = true;\n    }\n    T get_sum(int row_l, int row_r, int\
    \ column_l, int column_r) const {\n        assert(row_l <= row_r);\n        assert(column_l\
    \ <= column_r);\n        assert(isBuilt);\n        return (sum[row_r][column_r]\
    \ - sum[row_l][column_r] -\n                sum[row_r][column_l] + sum[row_l][column_l]);\n\
    \    }\n\n  private:\n    std::vector<std::vector<T>> sum;\n    bool isBuilt;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sum2D.hpp
  requiredBy: []
  timestamp: '2024-12-15 14:15:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc276ex.test.cpp
  - test/aoj/aoj2426.test.cpp
documentation_of: data-structure/sum2D.hpp
layout: document
redirect_from:
- /library/data-structure/sum2D.hpp
- /library/data-structure/sum2D.hpp.html
title: data-structure/sum2D.hpp
---
