---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/line_add_get_min.test.cpp
    title: test/line_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/LiChaoTree.hpp\"\ntemplate <typename T> struct\
    \ LiChaoTree {\n    struct Line {\n        T a, b;\n        Line(T _a, T _b) :\
    \ a(_a), b(_b) {}\n        inline T f(T x) const { return (a * x + b); }\n   \
    \ };\n    vector<T> X;\n    vector<Line> lines;\n    int n;\n    LiChaoTree()\
    \ {}\n    LiChaoTree(const vector<T> &_X, T _INF) : X(_X) {\n        n = 1;\n\
    \        while(n < X.size()) {\n            n <<= 1;\n        }\n        while(X.size()\
    \ < n) {\n            X.emplace_back(X.back() + 1);\n        }\n        lines.assign((n\
    \ << 1) - 1, Line(0, _INF));\n    }\n    void update(Line &line, int k, int l,\
    \ int r) {\n        int mid = (l + r) >> 1;\n        bool flg_l = (line.f(X[l])\
    \ < lines[k].f(X[l]));\n        bool flg_r = (line.f(X[mid]) < lines[k].f(X[mid]));\n\
    \        if(flg_r) {\n            swap(lines[k], line);\n        }\n        if(l\
    \ + 1 >= r) {\n            return;\n        }\n        if(flg_l != flg_r) {\n\
    \            update(line, 2 * k + 1, l, mid);\n        } else {\n            update(line,\
    \ 2 * k + 2, mid, r);\n        }\n    }\n    void add(T a, T b) {\n        Line\
    \ l(a, b);\n        update(l, 0, 0, n);\n    }\n    T query(int k) {\n       \
    \ const T x = X[k];\n        k += n - 1;\n        T ans = lines[k].f(x);\n   \
    \     while(k > 0) {\n            k = (k - 1) >> 1;\n            chmin(ans, lines[k].f(x));\n\
    \        }\n        return ans;\n    }\n};\n"
  code: "template <typename T> struct LiChaoTree {\n    struct Line {\n        T a,\
    \ b;\n        Line(T _a, T _b) : a(_a), b(_b) {}\n        inline T f(T x) const\
    \ { return (a * x + b); }\n    };\n    vector<T> X;\n    vector<Line> lines;\n\
    \    int n;\n    LiChaoTree() {}\n    LiChaoTree(const vector<T> &_X, T _INF)\
    \ : X(_X) {\n        n = 1;\n        while(n < X.size()) {\n            n <<=\
    \ 1;\n        }\n        while(X.size() < n) {\n            X.emplace_back(X.back()\
    \ + 1);\n        }\n        lines.assign((n << 1) - 1, Line(0, _INF));\n    }\n\
    \    void update(Line &line, int k, int l, int r) {\n        int mid = (l + r)\
    \ >> 1;\n        bool flg_l = (line.f(X[l]) < lines[k].f(X[l]));\n        bool\
    \ flg_r = (line.f(X[mid]) < lines[k].f(X[mid]));\n        if(flg_r) {\n      \
    \      swap(lines[k], line);\n        }\n        if(l + 1 >= r) {\n          \
    \  return;\n        }\n        if(flg_l != flg_r) {\n            update(line,\
    \ 2 * k + 1, l, mid);\n        } else {\n            update(line, 2 * k + 2, mid,\
    \ r);\n        }\n    }\n    void add(T a, T b) {\n        Line l(a, b);\n   \
    \     update(l, 0, 0, n);\n    }\n    T query(int k) {\n        const T x = X[k];\n\
    \        k += n - 1;\n        T ans = lines[k].f(x);\n        while(k > 0) {\n\
    \            k = (k - 1) >> 1;\n            chmin(ans, lines[k].f(x));\n     \
    \   }\n        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2021-02-12 13:21:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/line_add_get_min.test.cpp
documentation_of: data_structure/LiChaoTree.hpp
layout: document
redirect_from:
- /library/data_structure/LiChaoTree.hpp
- /library/data_structure/LiChaoTree.hpp.html
title: data_structure/LiChaoTree.hpp
---
