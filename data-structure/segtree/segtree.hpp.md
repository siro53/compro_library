---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/utils/sum_count_manager.hpp
    title: "\u5024\u3054\u3068\u306E\u548C\u30FB\u500B\u6570\u7BA1\u7406"
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
    path: test/mytest/data-structure/helper-regressions.test.cpp
    title: test/mytest/data-structure/helper-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/initialization-and-monoids.test.cpp
    title: test/mytest/data-structure/initialization-and-monoids.test.cpp
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
    \ <= pos && pos < N);\n        return node[pos + sz];\n    }\n    void apply(int\
    \ pos, T val) {\n        this->set(pos, Monoid::op(this->get(pos), val));\n  \
    \  }\n    T prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=\
    \ N);\n        T value_l = Monoid::e(), value_r = Monoid::e();\n        l += sz;\n\
    \        r += sz;\n        while(l < r) {\n            if(l & 1) value_l = Monoid::op(value_l,\
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
    \ private:\n    int N, sz;\n    std::vector<T> node;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segtree.hpp
  requiredBy:
  - test/library-checker/data-structure/point-set-range-composite.cpp
  - data-structure/utils/sum_count_manager.hpp
  timestamp: '2023-10-30 20:10:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki1435.test.cpp
  - test/library-checker/data-structure/vertex-set-path-composite.test.cpp
  - test/library-checker/data-structure/vertex-add-path-sum.test.cpp
  - test/library-checker/data-structure/vertex-add-subtree-sum.test.cpp
  - test/mytest/data-structure/initialization-and-monoids.test.cpp
  - test/mytest/data-structure/helper-regressions.test.cpp
documentation_of: data-structure/segtree/segtree.hpp
layout: document
title: Segment Tree
---

## このライブラリでできること

`Segtree<Monoid>` は、配列の要素を更新しながら区間の集約値を求めるデータ構造です。和・最小値・最大値だけでなく、関数の合成などにも同じ実装を使えます。配列長を $N$ とすると、点更新と区間の集約は $O(\log N)$ 時間です。

扱う演算を $\circ$、単位元を $e$ とします。必要なのは結合律 $(a\circ b)\circ c=a\circ(b\circ c)$ と、単位元の条件 $e\circ a=a\circ e=a$ です。この組をモノイドと呼びます。演算の順番を交換できる必要はなく、`prod(l,r)` は $A_l\circ A_{l+1}\circ\cdots\circ A_{r-1}$ の順序を保ちます。

## 使い方

集約したい演算を `value_type`、`op(l,r)`、`e()` を持つ型にまとめ、それをテンプレート引数として渡します。和なら既存の `MonoidAdd<T>` を使えます。例では $[1,2,3]$ の2番目を $5$ に上書きするため、全体の和は $9$ です。

`max_right(l,f)` は、区間を右へ伸ばしたときに条件 `f` を満たせる境界を探します。例の非負の配列では「和が6以下」は単調な条件なので、$[0,2)$ までは条件を満たし、$[0,3)$ では満たさないことを1回の探索で調べられます。

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/segtree.hpp"
#include "data-structure/monoid/add.hpp"

int main() {
    Segtree<MonoidAdd<long long>> seg(vector<long long>{1, 2, 3});
    seg.set(1, 5);
    assert(seg.prod(0, 3) == 9);
    assert(seg.max_right(0, [](long long x) { return x <= 6; }) == 2);
}
```

## API・計算量

必要な空間は $O(N+1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Segtree(), Segtree(n), Segtree(v)` | 空、n 個の単位元、配列 v から構築。 | O(N+1) |
| `set(pos, val)` | 1 点を上書き。 | O(log N) |
| `get(pos)` | 1 点の値。 | O(1) |
| `apply(pos, val)` | A[pos] を op(A[pos],val) にする。 | O(log N) |
| `prod(l, r)` | [l,r) の積。空区間は e()。 | O(log N) |
| `all_prod()` | 全体の積。 | O(1) |
| `max_right(l, f)` | f(prod(l,r)) が true となる最大の r。 | O(log N) |
| `min_left(r, f)` | f(prod(l,r)) が true となる最小の l。 | O(log N) |

## 利用条件と実装上の注意

添字は0始まり、区間は $0\le l\le r\le N$ の半開区間です。空区間の集約値は `e()` です。`set(p,x)` は代入、`apply(p,x)` は $A_p\leftarrow\operatorname{op}(A_p,x)$ なので、両者を使い分けてください。

境界探索では `f(e())` が真であること、同じ値に対して毎回同じ判定を返すことが必要です。「最大の右端」「最小の左端」と解釈するには、区間を伸ばしたときに真から偽へ一度しか変化しないという単調性も必要です。

表の計算量は `op/e` と値のコピーを定数時間としたものです。文字列そのものの連結など、演算に長さに比例する時間がかかる場合は、そのコストも含めて評価してください。

## 参考資料

[ACL の Segtree ドキュメント](https://atcoder.github.io/ac-library/production/document_ja/segtree.html)に、モノイドと境界探索の条件が整理されています。このライブラリでは演算と型を `Monoid` 構造体にまとめて指定します。

設計の参考: [代数的構造を乗せるデータ構造の設計について](https://noshi91.hatenablog.com/entry/2020/04/22/212649)。
