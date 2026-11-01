---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
    title: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-affine-range-sum.test.cpp
    title: test/library-checker/data-structure/range-affine-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/lazy-segtree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate<class MonoidAct> class LazySegtree {\npublic:\n\
    \    using S = typename MonoidAct::value_type_S;\n    using F = typename MonoidAct::value_type_F;\n\
    \n    LazySegtree(): LazySegtree(0) {}\n    explicit LazySegtree(int n): LazySegtree(std::vector<S>(n,\
    \ MonoidAct::e())) {}\n    explicit LazySegtree(const std::vector<S> &v): N((int)v.size()),\
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
    \          }\n            now = MonoidAct::op(now, node[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return N;\n    } \n\n    template <class\
    \ G> int min_left(int r, G g) {\n        assert(0 <= r and r <= N);\n        assert(g(MonoidAct::e()));\n\
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
    \ node[i]);\n        if (i < sz) lazy[i] = MonoidAct::composition(f, lazy[i]);\n\
    \    }\n\n    void propagate(int i) {\n        apply_node(i << 1, lazy[i]);\n\
    \        apply_node(i << 1 | 1, lazy[i]);\n        lazy[i] = MonoidAct::id();\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\ntemplate<class MonoidAct>\
    \ class LazySegtree {\npublic:\n    using S = typename MonoidAct::value_type_S;\n\
    \    using F = typename MonoidAct::value_type_F;\n\n    LazySegtree(): LazySegtree(0)\
    \ {}\n    explicit LazySegtree(int n): LazySegtree(std::vector<S>(n, MonoidAct::e()))\
    \ {}\n    explicit LazySegtree(const std::vector<S> &v): N((int)v.size()), sz(1),\
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
    \          }\n            now = MonoidAct::op(now, node[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return N;\n    } \n\n    template <class\
    \ G> int min_left(int r, G g) {\n        assert(0 <= r and r <= N);\n        assert(g(MonoidAct::e()));\n\
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
    \ node[i]);\n        if (i < sz) lazy[i] = MonoidAct::composition(f, lazy[i]);\n\
    \    }\n\n    void propagate(int i) {\n        apply_node(i << 1, lazy[i]);\n\
    \        apply_node(i << 1 | 1, lazy[i]);\n        lazy[i] = MonoidAct::id();\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/lazy-segtree.hpp
  requiredBy: []
  timestamp: '2025-12-29 15:38:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
  - test/library-checker/data-structure/range-affine-range-sum.test.cpp
documentation_of: data-structure/segtree/lazy-segtree.hpp
layout: document
title: Lazy Segment Tree
---

## このライブラリでできること

`LazySegtree<MonoidAct>` は、区間内の要素をまとめて更新し、その区間の集約値も求めるデータ構造です。たとえば「区間の全要素に5を加える」「区間の和を求める」という操作を、長さ $N$ の配列に対してそれぞれ $O(\log N)$ 時間で処理できます。

更新をすぐに各要素へ配らず、区間を表すノードに保留します。そのノードの中を詳しく調べるときに子へ更新を伝えるため、遅延伝播と呼ばれます。区間の集約値を表す型を $S$、更新を表す型を $F$ とすると、`mapping(f,x)` が更新の適用、`composition(f,g)` が $g$ の後に $f$ を行う合成です。

## 使い方

区間和への加算では、集約値に「和」と「要素数」を持たせます。和を $s$、要素数を $n$ とすると、各要素への $d$ の加算は $(s,n)\mapsto(s+dn,n)$ としてまとめて計算できます。単に和だけを保存すると、加算後の和を求めるための長さが足りません。

例の `RangeAddSum` はこの対応を実装しています。各葉を `{値,1}` として構築し、最初の2要素に $5$ を加えるので、全体の和は $1+2+3+5\times2=16$ になります。

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/lazy-segtree.hpp"
struct RangeAddSum {
    struct S { long long sum; int len; };
    using value_type_S = S;
    using value_type_F = long long;
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {0, 0}; }
    static S mapping(long long f, S x) { return {x.sum + f * x.len, x.len}; }
    static long long composition(long long f, long long g) { return f + g; }
    static long long id() { return 0; }
};

int main() {
    LazySegtree<RangeAddSum> seg(vector<RangeAddSum::S>{ {1, 1}, {2, 1}, {3, 1}});
    seg.apply(0, 2, 5);
    assert(seg.prod(0, 3).sum == 16);
}
```

## API・計算量

必要な空間は $O(N+1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `LazySegtree(), LazySegtree(n), LazySegtree(v)` | 空、n 個の e()、列 v から構築。 | O(N+1) |
| `set(pos, val)` | 点を上書き。 | O(log N) |
| `get(pos)` | 遅延作用を反映した点の値。 | O(log N) |
| `prod(l, r)` | [l,r) の積。 | O(log N) |
| `all_prod()` | 全体の積。 | O(1) |
| `apply(pos, f)` | 点に作用 f を適用。 | O(log N) |
| `apply(l, r, f)` | [l,r) に作用 f を適用。 | O(log N) |
| `max_right(l, g)` | g(prod(l,r)) が true となる最大 r。 | O(log N) |
| `min_left(r, g)` | g(prod(l,r)) が true となる最小 l。 | O(log N) |

## 利用条件と実装上の注意

`MonoidAct` には、集約用の `value_type_S,op,e` と、更新用の `value_type_F,mapping,composition,id` を用意します。集約の `op/e` はモノイドの条件を満たす必要があります。また、更新は恒等写像を含み、合成について閉じていて、$f(x\circ y)=f(x)\circ f(y)$ を満たす必要があります。表では、これらの演算とコピーを定数時間としています。

サイズだけを指定すると各葉は `e()` で初期化されます。例のように `e()` の長さが0である場合、実要素を表す長さ1の葉は配列で渡してください。添字・区間の範囲は通常のセグメント木と同じです。

境界探索には、単位元で真となり、区間を伸ばすと真から偽へ一度だけ変化する述語を使います。ただし、現実装の `min_left` には上方移動時の偶奇条件に不備があり、使用を避ける必要があります。

## 参考資料

[ACL の Lazy Segtree ドキュメント](https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html)を、作用の条件と合成順序の参考にしています。
