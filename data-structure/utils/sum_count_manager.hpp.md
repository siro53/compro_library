---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/monoid/sum_count.hpp
    title: data-structure/monoid/sum_count.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: "\u5EA7\u5727"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/utils/sum_count_manager.hpp\"\n\n#line 2\
    \ \"misc/compress.hpp\"\n\n#include <algorithm>\n#include <vector>\n\ntemplate\
    \ <typename T> class Compress {\n  public:\n    Compress() = default;\n    explicit\
    \ Compress(const std::vector<T> &v) : dat(v) {\n        build();\n    }\n    void\
    \ push_back(T val) { dat.push_back(val); }\n\tvoid build() {\n\t\tstd::sort(dat.begin(),\
    \ dat.end());\n        dat.erase(std::unique(dat.begin(), dat.end()), dat.end());\n\
    \t}\n    int get(T val) const {\n        int pos = std::lower_bound(dat.begin(),\
    \ dat.end(), val) - dat.begin();\n        return pos;\n    }\n    T operator[](int\
    \ i) const { return dat[i]; }\n    size_t size() const { return dat.size(); }\n\
    \n  private:\n    std::vector<T> dat;\n};\n#line 2 \"data-structure/segtree/segtree.hpp\"\
    \n\n#include <cassert>\n#line 5 \"data-structure/segtree/segtree.hpp\"\n\ntemplate\
    \ <class Monoid> class Segtree {\n  public:\n    using T = typename Monoid::value_type;\n\
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
    \    void apply(int pos, T val) {\n        this->set(pos, Monoid::op(this->get(pos),\
    \ val));\n    }\n    T prod(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= N);\n        T value_l = Monoid::e(), value_r = Monoid::e();\n\
    \        l += sz;\n        r += sz;\n        while(l < r) {\n            if(l\
    \ & 1) value_l = Monoid::op(value_l, node[l++]);\n            if(r & 1) value_r\
    \ = Monoid::op(node[--r], value_r);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return Monoid::op(value_l, value_r);\n    }\n    T all_prod()\
    \ const { return node[1]; }\n    template <class F> int max_right(int l, F f)\
    \ const {\n        assert(0 <= l && l <= N);\n        assert(f(Monoid::e()));\n\
    \        if(l == N) return N;\n        l += sz;\n        T value_now = Monoid::e();\n\
    \        do {\n            while((l & 1) == 0) l >>= 1;\n            if(!f(Monoid::op(value_now,\
    \ node[l]))) {\n                while(l < sz) {\n                    l = 2 * l;\n\
    \                    if(f(Monoid::op(value_now, node[l]))) {\n               \
    \         value_now = Monoid::op(value_now, node[l]);\n                      \
    \  l++;\n                    }\n                }\n                return (l -\
    \ sz);\n            }\n            value_now = Monoid::op(value_now, node[l]);\n\
    \            l++;\n        } while((l & -l) != l);\n        return N;\n    }\n\
    \    template <class F> int min_left(int r, F f) const {\n        assert(0 <=\
    \ r && r <= N);\n        assert(f(Monoid::e()));\n        if(r == 0) return 0;\n\
    \        r += sz;\n        T value_now = Monoid::e();\n        do {\n        \
    \    r--;\n            while(r > 1 && (r & 1)) r >>= 1;\n            if(!f(Monoid::op(node[r],\
    \ value_now))) {\n                while(r < sz) {\n                    r = 2 *\
    \ r + 1;\n                    if(f(Monoid::op(node[r], value_now))) {\n      \
    \                  value_now = Monoid::op(node[r], value_now);\n             \
    \           r--;\n                    }\n                }\n                return\
    \ ((r + 1) - sz);\n            }\n            value_now = Monoid::op(node[r],\
    \ value_now);\n        } while((r & -r) != r);\n        return 0;\n    }\n\n \
    \ private:\n    int N, sz;\n    std::vector<T> node;\n};\n#line 2 \"data-structure/monoid/sum_count.hpp\"\
    \n\ntemplate <typename sum_t, typename count_t> struct MonoidSumCount {\n    struct\
    \ S {\n        sum_t sum;\n        count_t cnt;\n        S() = default;\n    \
    \    S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type\
    \ = S;\n    inline static S op(const S& l, const S& r) {\n        return S(l.sum\
    \ + r.sum, l.cnt + r.cnt);\n    }\n    inline static S e() { return S(sum_t(0),\
    \ count_t(0)); }\n};\n#line 6 \"data-structure/utils/sum_count_manager.hpp\"\n\
    \ntemplate<typename T>\nstruct SumCountManager {\n    Segtree<MonoidSumCount<T,\
    \ int>> seg;\n    Compress<T> comp;\n\n    SumCountManager() = default;\n    SumCountManager(vector<T>\
    \ xs) {\n        comp = Compress<T>(xs);\n        seg = Segtree<MonoidSumCount<T,\
    \ int>>((int)comp.size());\n    }\n\n    void add(T val) {\n        int pos =\
    \ comp.get(val);\n        assert(comp[pos] == val);\n        auto x = seg.get(pos);\n\
    \        seg.set(pos, S(x.sum + val, x.cnt + 1));\n    }\n};\n"
  code: "#pragma once\n\n#include \"../../misc/compress.hpp\"\n#include \"../segtree/segtree.hpp\"\
    \n#include \"../monoid/sum_count.hpp\"\n\ntemplate<typename T>\nstruct SumCountManager\
    \ {\n    Segtree<MonoidSumCount<T, int>> seg;\n    Compress<T> comp;\n\n    SumCountManager()\
    \ = default;\n    SumCountManager(vector<T> xs) {\n        comp = Compress<T>(xs);\n\
    \        seg = Segtree<MonoidSumCount<T, int>>((int)comp.size());\n    }\n\n \
    \   void add(T val) {\n        int pos = comp.get(val);\n        assert(comp[pos]\
    \ == val);\n        auto x = seg.get(pos);\n        seg.set(pos, S(x.sum + val,\
    \ x.cnt + 1));\n    }\n};"
  dependsOn:
  - misc/compress.hpp
  - data-structure/segtree/segtree.hpp
  - data-structure/monoid/sum_count.hpp
  isVerificationFile: false
  path: data-structure/utils/sum_count_manager.hpp
  requiredBy: []
  timestamp: '2025-12-21 17:21:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/utils/sum_count_manager.hpp
layout: document
redirect_from:
- /library/data-structure/utils/sum_count_manager.hpp
- /library/data-structure/utils/sum_count_manager.hpp.html
title: data-structure/utils/sum_count_manager.hpp
---
