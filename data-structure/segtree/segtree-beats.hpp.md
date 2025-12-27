---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-chmin-chmax-add-range-sum.test.cpp
    title: test/library-checker/data-structure/range-chmin-chmax-add-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segtree-beats.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate<class MonoidAct> class SegtreeBeats {\npublic:\n\
    \    using S = typename MonoidAct::value_type_S;\n    using F = typename MonoidAct::value_type_F;\n\
    \n    SegtreeBeats(): SegtreeBeats(0) {}\n    explicit SegtreeBeats(int n): SegtreeBeats(std::vector<S>(n,\
    \ MonoidAct::e())) {}\n    explicit SegtreeBeats(const std::vector<S> &v): N((int)v.size()),\
    \ sz(1), lg(0) {\n        while(sz < N) {\n            sz <<= 1;\n           \
    \ lg++;\n        }\n        node.resize(sz * 2, MonoidAct::e());\n        lazy.resize(sz,\
    \ MonoidAct::id());\n        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n\
    \        for(int i = sz - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int\
    \ pos, S val) {\n        assert(0 <= pos && pos < N);\n        pos += sz;\n  \
    \      for(int i = lg; i >= 1; i--) propagate(pos >> i);\n        node[pos] =\
    \ val;\n        for(int i = 1; i <= lg; i++) update(pos >> i);\n    } \n\n   \
    \ S get(int pos) {\n        assert(0 <= pos and pos < N);\n        pos += sz;\n\
    \        for(int i = lg; i >= 1; i--) propagate(pos >> i);\n        return node[pos];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ N);\n        if (l == r) return MonoidAct::e();\n        l += sz;\n        r\
    \ += sz;\n        for(int i = lg; i >= 1; i--) {\n            if (((l >> i) <<\
    \ i) != l) propagate(l >> i);\n            if (((r >> i) << i) != r) propagate((r\
    \ - 1) >> i);\n        }   \n        S vl = MonoidAct::e(), vr = MonoidAct::e();\n\
    \        while(l < r) {\n            if (l & 1) vl = MonoidAct::op(vl, node[l++]);\n\
    \            if (r & 1) vr = MonoidAct::op(node[--r], vr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return MonoidAct::op(vl, vr);\n\
    \    }\n\n    S all_prod() const { return node[1]; }\n\n    void apply(int pos,\
    \ F f) {\n        assert(0 <= pos and pos < N);\n        pos += sz;\n        for(int\
    \ i = lg; i >= 1; i--) propagate(pos >> i);\n        node[pos] = MonoidAct::mapping(f,\
    \ node[pos]);\n        for(int i = 1; i <= lg; i++) update(pos >> i);\n    }\n\
    \n    void apply(int l, int r, F f) {\n        assert(0 <= l and l <= r and r\
    \ <= N);\n        if (l == r) return;\n        l += sz;\n        r += sz;\n  \
    \      for(int i = lg; i >= 1; i--) {\n            if (((l >> i) << i) != l) propagate(l\
    \ >> i);\n            if (((r >> i) << i) != r) propagate((r - 1) >> i);\n   \
    \     }\n        {\n            int tmp_l = l, tmp_r = r;\n            while(l\
    \ < r) {\n                if (l & 1) apply_node(l++, f);\n                if (r\
    \ & 1) apply_node(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = tmp_l, r = tmp_r;\n        }\n        for(int\
    \ i = 1; i <= lg; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \n    template <class G> int max_right(int l, G g) {\n        assert(0 <= l and\
    \ l <= N);\n        assert(g(MonoidAct::e()));\n        if (l == N) return N;\n\
    \        l += sz;\n        for(int i = lg; i >= 1; i--) propagate(l >> i);\n \
    \       S now = MonoidAct::e();\n        do {\n            while ((l & 1) == 0)\
    \ l >>= 1;\n            if (!g(MonoidAct::op(now, node[l]))) {\n             \
    \   while (l < sz) {\n                    propagate(l);\n                    l\
    \ <<= 1;\n                    if (g(MonoidAct::op(now, node[l]))) {\n        \
    \                now = MonoidAct::op(now, node[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - sz;\n  \
    \          }\n            now = MonoidAct::op(now, node[l]);\n        } while\
    \ ((l & -l) != l);\n        return N;\n    } \n\n    template <class G> int min_left(int\
    \ r, G g) {\n        assert(0 <= r and r <= N);\n        assert(g(MonoidAct::e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        for(int i = lg; i >=\
    \ 1; i--) propagate((r - 1) >> i);\n        S now = MonoidAct::e();\n        do\
    \ {\n            r--;\n            while (r > 1 and (r & 1) == 0) r >>= 1;\n \
    \           if (!g(MonoidAct::op(node[r], now))) {\n                while (r <\
    \ sz) {\n                    propagate(r);\n                    r = (r << 1) +\
    \ 1;\n                    if (g(MonoidAct::op(node[r], now))) {\n            \
    \            now = MonoidAct::op(node[r], now);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - sz;\n\
    \            }\n            now = MonoidAct::op(node[r], now);\n        } while((r\
    \ & -r) != r);\n        return 0;\n    }\n\nprivate:\n    int N, sz, lg;\n   \
    \ std::vector<S> node;\n    std::vector<F> lazy;\n\n    void update(int i) {\n\
    \        node[i] = MonoidAct::op(node[i << 1], node[(i << 1) | 1]);\n    }\n \
    \   \n    void apply_node(int i, F f) {\n        node[i] = MonoidAct::mapping(f,\
    \ node[i]);\n        if (i < sz) {\n            lazy[i] = MonoidAct::composition(f,\
    \ lazy[i]);\n            if (node[i].fail) {\n                propagate(i);\n\
    \                update(i);\n            }\n        }\n    }\n\n    void propagate(int\
    \ i) {\n        apply_node(i << 1, lazy[i]);\n        apply_node(i << 1 | 1, lazy[i]);\n\
    \        lazy[i] = MonoidAct::id();\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate<class MonoidAct>\
    \ class SegtreeBeats {\npublic:\n    using S = typename MonoidAct::value_type_S;\n\
    \    using F = typename MonoidAct::value_type_F;\n\n    SegtreeBeats(): SegtreeBeats(0)\
    \ {}\n    explicit SegtreeBeats(int n): SegtreeBeats(std::vector<S>(n, MonoidAct::e()))\
    \ {}\n    explicit SegtreeBeats(const std::vector<S> &v): N((int)v.size()), sz(1),\
    \ lg(0) {\n        while(sz < N) {\n            sz <<= 1;\n            lg++;\n\
    \        }\n        node.resize(sz * 2, MonoidAct::e());\n        lazy.resize(sz,\
    \ MonoidAct::id());\n        for(int i = 0; i < N; i++) node[i + sz] = v[i];\n\
    \        for(int i = sz - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int\
    \ pos, S val) {\n        assert(0 <= pos && pos < N);\n        pos += sz;\n  \
    \      for(int i = lg; i >= 1; i--) propagate(pos >> i);\n        node[pos] =\
    \ val;\n        for(int i = 1; i <= lg; i++) update(pos >> i);\n    } \n\n   \
    \ S get(int pos) {\n        assert(0 <= pos and pos < N);\n        pos += sz;\n\
    \        for(int i = lg; i >= 1; i--) propagate(pos >> i);\n        return node[pos];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <=\
    \ N);\n        if (l == r) return MonoidAct::e();\n        l += sz;\n        r\
    \ += sz;\n        for(int i = lg; i >= 1; i--) {\n            if (((l >> i) <<\
    \ i) != l) propagate(l >> i);\n            if (((r >> i) << i) != r) propagate((r\
    \ - 1) >> i);\n        }   \n        S vl = MonoidAct::e(), vr = MonoidAct::e();\n\
    \        while(l < r) {\n            if (l & 1) vl = MonoidAct::op(vl, node[l++]);\n\
    \            if (r & 1) vr = MonoidAct::op(node[--r], vr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return MonoidAct::op(vl, vr);\n\
    \    }\n\n    S all_prod() const { return node[1]; }\n\n    void apply(int pos,\
    \ F f) {\n        assert(0 <= pos and pos < N);\n        pos += sz;\n        for(int\
    \ i = lg; i >= 1; i--) propagate(pos >> i);\n        node[pos] = MonoidAct::mapping(f,\
    \ node[pos]);\n        for(int i = 1; i <= lg; i++) update(pos >> i);\n    }\n\
    \n    void apply(int l, int r, F f) {\n        assert(0 <= l and l <= r and r\
    \ <= N);\n        if (l == r) return;\n        l += sz;\n        r += sz;\n  \
    \      for(int i = lg; i >= 1; i--) {\n            if (((l >> i) << i) != l) propagate(l\
    \ >> i);\n            if (((r >> i) << i) != r) propagate((r - 1) >> i);\n   \
    \     }\n        {\n            int tmp_l = l, tmp_r = r;\n            while(l\
    \ < r) {\n                if (l & 1) apply_node(l++, f);\n                if (r\
    \ & 1) apply_node(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = tmp_l, r = tmp_r;\n        }\n        for(int\
    \ i = 1; i <= lg; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n\
    \            if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \n    template <class G> int max_right(int l, G g) {\n        assert(0 <= l and\
    \ l <= N);\n        assert(g(MonoidAct::e()));\n        if (l == N) return N;\n\
    \        l += sz;\n        for(int i = lg; i >= 1; i--) propagate(l >> i);\n \
    \       S now = MonoidAct::e();\n        do {\n            while ((l & 1) == 0)\
    \ l >>= 1;\n            if (!g(MonoidAct::op(now, node[l]))) {\n             \
    \   while (l < sz) {\n                    propagate(l);\n                    l\
    \ <<= 1;\n                    if (g(MonoidAct::op(now, node[l]))) {\n        \
    \                now = MonoidAct::op(now, node[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - sz;\n  \
    \          }\n            now = MonoidAct::op(now, node[l]);\n        } while\
    \ ((l & -l) != l);\n        return N;\n    } \n\n    template <class G> int min_left(int\
    \ r, G g) {\n        assert(0 <= r and r <= N);\n        assert(g(MonoidAct::e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        for(int i = lg; i >=\
    \ 1; i--) propagate((r - 1) >> i);\n        S now = MonoidAct::e();\n        do\
    \ {\n            r--;\n            while (r > 1 and (r & 1) == 0) r >>= 1;\n \
    \           if (!g(MonoidAct::op(node[r], now))) {\n                while (r <\
    \ sz) {\n                    propagate(r);\n                    r = (r << 1) +\
    \ 1;\n                    if (g(MonoidAct::op(node[r], now))) {\n            \
    \            now = MonoidAct::op(node[r], now);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - sz;\n\
    \            }\n            now = MonoidAct::op(node[r], now);\n        } while((r\
    \ & -r) != r);\n        return 0;\n    }\n\nprivate:\n    int N, sz, lg;\n   \
    \ std::vector<S> node;\n    std::vector<F> lazy;\n\n    void update(int i) {\n\
    \        node[i] = MonoidAct::op(node[i << 1], node[(i << 1) | 1]);\n    }\n \
    \   \n    void apply_node(int i, F f) {\n        node[i] = MonoidAct::mapping(f,\
    \ node[i]);\n        if (i < sz) {\n            lazy[i] = MonoidAct::composition(f,\
    \ lazy[i]);\n            if (node[i].fail) {\n                propagate(i);\n\
    \                update(i);\n            }\n        }\n    }\n\n    void propagate(int\
    \ i) {\n        apply_node(i << 1, lazy[i]);\n        apply_node(i << 1 | 1, lazy[i]);\n\
    \        lazy[i] = MonoidAct::id();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segtree-beats.hpp
  requiredBy: []
  timestamp: '2025-12-27 20:01:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/range-chmin-chmax-add-range-sum.test.cpp
documentation_of: data-structure/segtree/segtree-beats.hpp
layout: document
redirect_from:
- /library/data-structure/segtree/segtree-beats.hpp
- /library/data-structure/segtree/segtree-beats.hpp.html
title: data-structure/segtree/segtree-beats.hpp
---
