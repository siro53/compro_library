---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/range-chmin-chmax-add-range-sum.test.cpp
    title: test/library-checker/data-structure/range-chmin-chmax-add-range-sum.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/segment-tree-api.test.cpp
    title: test/mytest/data-structure/segment-tree-api.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/segtree-boundaries.test.cpp
    title: test/mytest/data-structure/segtree-boundaries.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \          }\n            now = MonoidAct::op(now, node[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return N;\n    } \n\n    template <class\
    \ G> int min_left(int r, G g) {\n        assert(0 <= r and r <= N);\n        assert(g(MonoidAct::e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        for(int i = lg; i >=\
    \ 1; i--) propagate((r - 1) >> i);\n        S now = MonoidAct::e();\n        do\
    \ {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n      \
    \      if (!g(MonoidAct::op(node[r], now))) {\n                while (r < sz)\
    \ {\n                    propagate(r);\n                    r = (r << 1) + 1;\n\
    \                    if (g(MonoidAct::op(node[r], now))) {\n                 \
    \       now = MonoidAct::op(node[r], now);\n                        r--;\n   \
    \                 }\n                }\n                return r + 1 - sz;\n \
    \           }\n            now = MonoidAct::op(node[r], now);\n        } while((r\
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
    \          }\n            now = MonoidAct::op(now, node[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return N;\n    } \n\n    template <class\
    \ G> int min_left(int r, G g) {\n        assert(0 <= r and r <= N);\n        assert(g(MonoidAct::e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        for(int i = lg; i >=\
    \ 1; i--) propagate((r - 1) >> i);\n        S now = MonoidAct::e();\n        do\
    \ {\n            r--;\n            while (r > 1 and (r & 1)) r >>= 1;\n      \
    \      if (!g(MonoidAct::op(node[r], now))) {\n                while (r < sz)\
    \ {\n                    propagate(r);\n                    r = (r << 1) + 1;\n\
    \                    if (g(MonoidAct::op(node[r], now))) {\n                 \
    \       now = MonoidAct::op(node[r], now);\n                        r--;\n   \
    \                 }\n                }\n                return r + 1 - sz;\n \
    \           }\n            now = MonoidAct::op(node[r], now);\n        } while((r\
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
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/data-structure/range-chmin-chmax-add-range-sum.test.cpp
  - test/mytest/data-structure/segment-tree-api.test.cpp
  - test/mytest/data-structure/segtree-boundaries.test.cpp
documentation_of: data-structure/segtree/segtree-beats.hpp
layout: document
title: Segment Tree Beats
---

## このライブラリでできること

`SegtreeBeats<MonoidAct>` は、区間をまとめて更新できる場合だけ更新し、できない場合は子の区間へ降りるセグメント木です。通常の遅延セグメント木では、すべての更新を区間の集約値だけから処理できる必要があります。Segment Tree Beats では、その判定自体を集約型の `fail` フラグで表します。

典型例は $A_i\leftarrow\min(A_i,x)$ という上限を設ける更新です。区間の最大値・2番目に大きい値・最大値の個数などを持てば、最大値だけが変わる場合は和を一度に更新できます。それ以外の場合に、より細かい区間へ降ります。ただし、このヘッダーがその集約型を用意しているわけではありません。

## 使い方

`LazySegtree` と同じ集約・作用の定義に加え、集約型に `bool fail` を持たせます。`mapping` は集約値だけで正しく更新できないときに `fail=true` を返し、葉では必ず成功させてください。

以下の例は、APIの接続方法を示すために、常に更新が成功する区間加算を使っています。したがって Beats 特有の高速化を示す例ではありません。上限・下限を設ける更新を使う場合は、それに必要な統計量と失敗条件を別途設計します。

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/segtree-beats.hpp"
struct RangeAddSum {
    struct S { long long sum; int len; bool fail = false; };
    using value_type_S = S;
    using value_type_F = long long;
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S e() { return {0, 0}; }
    static S mapping(long long f, S x) { return {x.sum + f * x.len, x.len}; }
    static long long composition(long long f, long long g) { return f + g; }
    static long long id() { return 0; }
};

int main() {
    SegtreeBeats<RangeAddSum> seg(vector<RangeAddSum::S>{ {1, 1}, {2, 1}, {3, 1}});
    seg.apply(0, 2, 5);
    assert(seg.prod(0, 3).sum == 16);
}
```

## API・計算量

必要な空間は $O(N+1)$ です。表では、渡した集約・作用の演算を $O(1)$ としています。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SegtreeBeats(), SegtreeBeats(n), SegtreeBeats(v)` | 空、n 個の e()、列 v から構築。 | O(N+1) |
| `set(pos, val)` | 点を上書き。 | O(log N + V) |
| `get(pos)` | 遅延作用を反映した点の値。 | O(log N + V) |
| `prod(l, r)` | [l,r) の積。 | O(log N + V) |
| `all_prod()` | 全体の積。 | O(1) |
| `apply(pos, f)` | 点に作用 f を適用。 | O(log N + V) |
| `apply(l, r, f)` | [l,r) に作用 f を適用。 | O(log N + V) |
| `max_right(l, g)` | g(prod(l,r)) が true となる最大 r。 | O(log N + V) |
| `min_left(r, g)` | g(prod(l,r)) が true となる最小 l。 | O(log N + V) |

## 利用条件と実装上の注意

配列長を $N$、1操作中に失敗処理によって追加で訪問するノード数を $V$ とします。表の $O(\log N+V)$ は各集約・作用を定数時間とした評価です。$V$ は最悪 $O(N)$ になり得るため、この汎用クラスを使うだけで対数時間が保証されるわけではありません。償却計算量は、実装する更新の種類と集約情報に応じて証明する必要があります。

`composition(f,g)` は $g$ の後に $f$ を適用する合成です。失敗した更新も子へ伝えられる必要があり、`op/e` が返す `fail` の状態も整合させてください。サイズだけで構築すると葉は `e()` になるため、必要なら長さなどを持つ初期配列を渡します。

境界探索には、単位元で真となり、区間を伸ばすと真から偽へ一度だけ変化する述語を使います。`max_right` は左端、`min_left` は右端を固定し、条件を満たす範囲が端まで続く場合はそれぞれ N、0 を返します。
