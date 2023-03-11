---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/line-add-get-min.test.cpp
    title: test/library-checker/data-structure/line-add-get-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/segment-add-get-min.test.cpp
    title: test/library-checker/data-structure/segment-add-get-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/li-chao-tree.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ T, T inf>\nclass LiChaoTree {\npublic:\n    LiChaoTree() = default;\n    explicit\
    \ LiChaoTree(const std::vector<T>& x): xs(x) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        n = (int)xs.size();\n        sz = 1;\n        while(sz < n) sz <<= 1;\n\
    \        while((int)xs.size() < sz) xs.emplace_back(xs.back() + 1);\n        node.resize(sz\
    \ * 2, Line(T(0), inf));\n    }\n    // \u76F4\u7DDA ax + b \u3092\u8FFD\u52A0\
    \n    void add_line(T a, T b) {\n        update(a, b, 0, sz, 1);\n    }\n    //\
    \ \u7DDA\u5206 ax + b (x_l <= x < x_r) \u3092\u8FFD\u52A0\n    void add_segment(T\
    \ a, T b, T x_l, T x_r) {\n        int l = std::lower_bound(xs.begin(), xs.end(),\
    \ x_l) - xs.begin();\n        int r = std::lower_bound(xs.begin(), xs.end(), x_r)\
    \ - xs.begin();\n        l += sz;\n        r += sz;\n        int width = 1, seg_idx_left\
    \ = sz;\n        while(l < r) {\n            if(l & 1) {\n                int\
    \ L = (l - seg_idx_left) * width;\n                int R = L + width;\n      \
    \          update(a, b, L, R, l);\n                l++;\n            }\n     \
    \       if(r & 1) {\n                r--;\n                int L = (r - seg_idx_left)\
    \ * width;\n                int R = L + width;\n                update(a, b, L,\
    \ R, r);\n            }\n            l >>= 1;\n            r >>= 1;\n        \
    \    width <<= 1;\n            seg_idx_left >>= 1;\n        }\n    }\n    // min_{i}\
    \ (a_i * x + b) \u3092\u6C42\u3081\u308B\n    T get_min(T x) {\n        int pos\
    \ = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n        assert(0\
    \ <= pos and pos < sz);\n        pos += sz;\n        T ret = node[pos].eval(x);\n\
    \        while(pos > 1) {\n            pos >>= 1;\n            ret = std::min(ret,\
    \ node[pos].eval(x));\n        }\n        return ret;\n    }\nprivate:\n    struct\
    \ Line {\n        T a, b;\n        Line(T a, T b): a(a), b(b) {}\n        inline\
    \ T eval(T x) const { return (a * x + b); }\n    };\n    std::vector<T> xs;\n\
    \    std::vector<Line> node;\n    int n, sz;\n\n    void update(T a, T b, int\
    \ l, int r, int pos) {\n        Line new_line(a, b);\n        while(1) {\n   \
    \         bool is_over_l = (new_line.eval(xs[l]) >= node[pos].eval(xs[l]));\n\
    \            bool is_over_r = (new_line.eval(xs[r-1]) >= node[pos].eval(xs[r-1]));\n\
    \            if(is_over_l == is_over_r) {\n                if(!is_over_l) node[pos]\
    \ = new_line;\n                break;\n            }\n            int mid = (l\
    \ + r) >> 1;\n            bool is_over_mid = (new_line.eval(xs[mid]) >= node[pos].eval(xs[mid]));\n\
    \            if(!is_over_l and is_over_r) {\n                if(is_over_mid) {\n\
    \                    r = mid;\n                    pos = (pos << 1);\n       \
    \         } else {\n                    std::swap(new_line, node[pos]);\n    \
    \                l = mid;\n                    pos = (pos << 1) | 1;\n       \
    \         }\n            } else {\n                if(is_over_mid) {\n       \
    \             l = mid;\n                    pos = (pos << 1) | 1;\n          \
    \      } else {\n                    std::swap(new_line, node[pos]);\n       \
    \             r = mid;\n                    pos = (pos << 1);\n              \
    \  }\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T, T inf>\nclass LiChaoTree {\npublic:\n\
    \    LiChaoTree() = default;\n    explicit LiChaoTree(const std::vector<T>& x):\
    \ xs(x) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = (int)xs.size();\n        sz = 1;\n      \
    \  while(sz < n) sz <<= 1;\n        while((int)xs.size() < sz) xs.emplace_back(xs.back()\
    \ + 1);\n        node.resize(sz * 2, Line(T(0), inf));\n    }\n    // \u76F4\u7DDA\
    \ ax + b \u3092\u8FFD\u52A0\n    void add_line(T a, T b) {\n        update(a,\
    \ b, 0, sz, 1);\n    }\n    // \u7DDA\u5206 ax + b (x_l <= x < x_r) \u3092\u8FFD\
    \u52A0\n    void add_segment(T a, T b, T x_l, T x_r) {\n        int l = std::lower_bound(xs.begin(),\
    \ xs.end(), x_l) - xs.begin();\n        int r = std::lower_bound(xs.begin(), xs.end(),\
    \ x_r) - xs.begin();\n        l += sz;\n        r += sz;\n        int width =\
    \ 1, seg_idx_left = sz;\n        while(l < r) {\n            if(l & 1) {\n   \
    \             int L = (l - seg_idx_left) * width;\n                int R = L +\
    \ width;\n                update(a, b, L, R, l);\n                l++;\n     \
    \       }\n            if(r & 1) {\n                r--;\n                int\
    \ L = (r - seg_idx_left) * width;\n                int R = L + width;\n      \
    \          update(a, b, L, R, r);\n            }\n            l >>= 1;\n     \
    \       r >>= 1;\n            width <<= 1;\n            seg_idx_left >>= 1;\n\
    \        }\n    }\n    // min_{i} (a_i * x + b) \u3092\u6C42\u3081\u308B\n   \
    \ T get_min(T x) {\n        int pos = std::lower_bound(xs.begin(), xs.end(), x)\
    \ - xs.begin();\n        assert(0 <= pos and pos < sz);\n        pos += sz;\n\
    \        T ret = node[pos].eval(x);\n        while(pos > 1) {\n            pos\
    \ >>= 1;\n            ret = std::min(ret, node[pos].eval(x));\n        }\n   \
    \     return ret;\n    }\nprivate:\n    struct Line {\n        T a, b;\n     \
    \   Line(T a, T b): a(a), b(b) {}\n        inline T eval(T x) const { return (a\
    \ * x + b); }\n    };\n    std::vector<T> xs;\n    std::vector<Line> node;\n \
    \   int n, sz;\n\n    void update(T a, T b, int l, int r, int pos) {\n       \
    \ Line new_line(a, b);\n        while(1) {\n            bool is_over_l = (new_line.eval(xs[l])\
    \ >= node[pos].eval(xs[l]));\n            bool is_over_r = (new_line.eval(xs[r-1])\
    \ >= node[pos].eval(xs[r-1]));\n            if(is_over_l == is_over_r) {\n   \
    \             if(!is_over_l) node[pos] = new_line;\n                break;\n \
    \           }\n            int mid = (l + r) >> 1;\n            bool is_over_mid\
    \ = (new_line.eval(xs[mid]) >= node[pos].eval(xs[mid]));\n            if(!is_over_l\
    \ and is_over_r) {\n                if(is_over_mid) {\n                    r =\
    \ mid;\n                    pos = (pos << 1);\n                } else {\n    \
    \                std::swap(new_line, node[pos]);\n                    l = mid;\n\
    \                    pos = (pos << 1) | 1;\n                }\n            } else\
    \ {\n                if(is_over_mid) {\n                    l = mid;\n       \
    \             pos = (pos << 1) | 1;\n                } else {\n              \
    \      std::swap(new_line, node[pos]);\n                    r = mid;\n       \
    \             pos = (pos << 1);\n                }\n            }\n        }\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/li-chao-tree.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/line-add-get-min.test.cpp
  - test/library-checker/data-structure/segment-add-get-min.test.cpp
documentation_of: data-structure/segtree/li-chao-tree.hpp
layout: document
link: https://smijake3.hatenablog.com/entry/2018/06/16/144548
title: Li Chao Tree
---
