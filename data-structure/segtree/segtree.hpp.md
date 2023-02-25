---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/library-checker/data-structure/point-set-range-composite.cpp
    title: test/library-checker/data-structure/point-set-range-composite.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
    title: test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
    title: test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki1435.test.cpp
    title: test/yukicoder/yuki1435.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segtree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class Monoid> class Segtree {\n  public:\n    using\
    \ T = typename Monoid::value_type;\n\n    Segtree() : Segtree(0) {}\n    explicit\
    \ Segtree(int n) : Segtree(std::vector<T>(n, Monoid::e())) {}\n    explicit Segtree(const\
    \ std::vector<T> &v) : N((int)v.size()), sz(1) {\n        while(sz < N) sz <<=\
    \ 1;\n        node.resize(sz * 2, Monoid::e());\n        for(int i = 0; i < N;\
    \ i++) node[i + sz] = v[i];\n        for(int i = sz - 1; i >= 1; i--) {\n    \
    \        node[i] = Monoid::op(node[i << 1], node[i << 1 | 1]);\n        }\n  \
    \  }\n    void set(int pos, T val) {\n        assert(0 <= pos && pos < N);\n \
    \       pos += sz;\n        node[pos] = val;\n        while(pos > 1) {\n     \
    \       pos >>= 1;\n            node[pos] = Monoid::op(node[pos << 1], node[pos\
    \ << 1 | 1]);\n        }\n    }\n    T get(int pos) const {\n        assert(0\
    \ <= pos && pos < N);\n        return node[pos + sz];\n    }\n    T prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= N);\n        T value_l\
    \ = Monoid::e(), value_r = Monoid::e();\n        l += sz;\n        r += sz;\n\
    \        while(l < r) {\n            if(l & 1) value_l = Monoid::op(value_l, node[l++]);\n\
    \            if(r & 1) value_r = Monoid::op(node[--r], value_r);\n           \
    \ l >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(value_l,\
    \ value_r);\n    }\n    T all_prod() const { return node[1]; }\n    template <class\
    \ F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= N);\n  \
    \      assert(f(Monoid::e()));\n        if(l == N) return N;\n        l += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            while((l & 1) ==\
    \ 0) l >>= 1;\n            if(!f(Monoid::op(value_now, node[l]))) {\n        \
    \        while(l < sz) {\n                    l = 2 * l;\n                   \
    \ if(f(Monoid::op(value_now, node[l]))) {\n                        value_now =\
    \ Monoid::op(value_now, node[l]);\n                        l++;\n            \
    \        }\n                }\n                return (l - sz);\n            }\n\
    \            value_now = Monoid::op(value_now, node[l]);\n            l++;\n \
    \       } while((l & -l) != l);\n        return N;\n    }\n    template <class\
    \ F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= N);\n   \
    \     assert(f(Monoid::e()));\n        if(r == 0) return 0;\n        r += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            r--;\n        \
    \    while(r > 1 && (r & 1)) r >>= 1;\n            if(!f(Monoid::op(node[r], value_now)))\
    \ {\n                while(r < sz) {\n                    r = 2 * r + 1;\n   \
    \                 if(f(Monoid::op(node[r], value_now))) {\n                  \
    \      value_now = Monoid::op(node[r], value_now);\n                        r--;\n\
    \                    }\n                }\n                return ((r + 1) - sz);\n\
    \            }\n            value_now = Monoid::op(node[r], value_now);\n    \
    \    } while((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int\
    \ N, sz;\n    std::vector<T> node;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <class\
    \ Monoid> class Segtree {\n  public:\n    using T = typename Monoid::value_type;\n\
    \n    Segtree() : Segtree(0) {}\n    explicit Segtree(int n) : Segtree(std::vector<T>(n,\
    \ Monoid::e())) {}\n    explicit Segtree(const std::vector<T> &v) : N((int)v.size()),\
    \ sz(1) {\n        while(sz < N) sz <<= 1;\n        node.resize(sz * 2, Monoid::e());\n\
    \        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n        for(int i =\
    \ sz - 1; i >= 1; i--) {\n            node[i] = Monoid::op(node[i << 1], node[i\
    \ << 1 | 1]);\n        }\n    }\n    void set(int pos, T val) {\n        assert(0\
    \ <= pos && pos < N);\n        pos += sz;\n        node[pos] = val;\n        while(pos\
    \ > 1) {\n            pos >>= 1;\n            node[pos] = Monoid::op(node[pos\
    \ << 1], node[pos << 1 | 1]);\n        }\n    }\n    T get(int pos) const {\n\
    \        assert(0 <= pos && pos < N);\n        return node[pos + sz];\n    }\n\
    \    T prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= N);\n\
    \        T value_l = Monoid::e(), value_r = Monoid::e();\n        l += sz;\n \
    \       r += sz;\n        while(l < r) {\n            if(l & 1) value_l = Monoid::op(value_l,\
    \ node[l++]);\n            if(r & 1) value_r = Monoid::op(node[--r], value_r);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return Monoid::op(value_l,\
    \ value_r);\n    }\n    T all_prod() const { return node[1]; }\n    template <class\
    \ F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= N);\n  \
    \      assert(f(Monoid::e()));\n        if(l == N) return N;\n        l += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            while((l & 1) ==\
    \ 0) l >>= 1;\n            if(!f(Monoid::op(value_now, node[l]))) {\n        \
    \        while(l < sz) {\n                    l = 2 * l;\n                   \
    \ if(f(Monoid::op(value_now, node[l]))) {\n                        value_now =\
    \ Monoid::op(value_now, node[l]);\n                        l++;\n            \
    \        }\n                }\n                return (l - sz);\n            }\n\
    \            value_now = Monoid::op(value_now, node[l]);\n            l++;\n \
    \       } while((l & -l) != l);\n        return N;\n    }\n    template <class\
    \ F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= N);\n   \
    \     assert(f(Monoid::e()));\n        if(r == 0) return 0;\n        r += sz;\n\
    \        T value_now = Monoid::e();\n        do {\n            r--;\n        \
    \    while(r > 1 && (r & 1)) r >>= 1;\n            if(!f(Monoid::op(node[r], value_now)))\
    \ {\n                while(r < sz) {\n                    r = 2 * r + 1;\n   \
    \                 if(f(Monoid::op(node[r], value_now))) {\n                  \
    \      value_now = Monoid::op(node[r], value_now);\n                        r--;\n\
    \                    }\n                }\n                return ((r + 1) - sz);\n\
    \            }\n            value_now = Monoid::op(node[r], value_now);\n    \
    \    } while((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int\
    \ N, sz;\n    std::vector<T> node;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segtree.hpp
  requiredBy:
  - test/library-checker/data-structure/point-set-range-composite.cpp
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki1435.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
documentation_of: data-structure/segtree/segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree/segtree.hpp
- /library/data-structure/segtree/segtree.hpp.html
title: data-structure/segtree/segtree.hpp
---
