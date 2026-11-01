---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/monoid/sum_count.hpp
    title: "\u548C\u30FB\u500B\u6570\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/basic-api.test.cpp
    title: test/mytest/data-structure/basic-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/helper-regressions.test.cpp
    title: test/mytest/data-structure/helper-regressions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/utils/sum_count_manager.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\n#line 2 \"misc/compress.hpp\"\n\n#include <algorithm>\n\
    #line 5 \"misc/compress.hpp\"\n\ntemplate <typename T> class Compress {\n  public:\n\
    \    Compress() = default;\n    explicit Compress(const std::vector<T> &v) : dat(v)\
    \ {\n        build();\n    }\n    void push_back(T val) { dat.push_back(val);\
    \ }\n\tvoid build() {\n\t\tstd::sort(dat.begin(), dat.end());\n        dat.erase(std::unique(dat.begin(),\
    \ dat.end()), dat.end());\n\t}\n    int get(T val) const {\n        int pos =\
    \ std::lower_bound(dat.begin(), dat.end(), val) - dat.begin();\n        return\
    \ pos;\n    }\n    T operator[](int i) const { return dat[i]; }\n    size_t size()\
    \ const { return dat.size(); }\n\n  private:\n    std::vector<T> dat;\n};\n#line\
    \ 2 \"data-structure/segtree/segtree.hpp\"\n\n#line 5 \"data-structure/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid> class Segtree {\n  public:\n    using T = typename\
    \ Monoid::value_type;\n\n    Segtree() : Segtree(0) {}\n    explicit Segtree(int\
    \ n) : Segtree(std::vector<T>(n, Monoid::e())) {}\n    explicit Segtree(const\
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
    \ N, sz;\n    std::vector<T> node;\n};\n#line 2 \"data-structure/monoid/sum_count.hpp\"\
    \n\ntemplate <typename sum_t, typename count_t> struct MonoidSumCount {\n    struct\
    \ S {\n        sum_t sum;\n        count_t cnt;\n        S() = default;\n    \
    \    S(sum_t sum, count_t cnt): sum(sum), cnt(cnt) {}\n    };\n    using value_type\
    \ = S;\n    inline static S op(const S& l, const S& r) {\n        return S(l.sum\
    \ + r.sum, l.cnt + r.cnt);\n    }\n    inline static S e() { return S(sum_t(0),\
    \ count_t(0)); }\n};\n#line 9 \"data-structure/utils/sum_count_manager.hpp\"\n\
    \ntemplate<typename T>\nstruct SumCountManager {\n    using S = typename MonoidSumCount<T,\
    \ int>::S;\n    Segtree<MonoidSumCount<T, int>> seg;\n    Compress<T> comp;\n\n\
    \    SumCountManager() = default;\n    SumCountManager(std::vector<T> xs) {\n\
    \        comp = Compress<T>(xs);\n        seg = Segtree<MonoidSumCount<T, int>>((int)comp.size());\n\
    \    }\n\n    void add(T val) {\n        int pos = comp.get(val);\n        assert(pos\
    \ < (int)comp.size() && comp[pos] == val);\n        auto x = seg.get(pos);\n \
    \       seg.set(pos, S(x.sum + val, x.cnt + 1));\n    }\n\n    int get(T val)\
    \ const {\n        return comp.get(val);\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../../misc/compress.hpp\"\
    \n#include \"../segtree/segtree.hpp\"\n#include \"../monoid/sum_count.hpp\"\n\n\
    template<typename T>\nstruct SumCountManager {\n    using S = typename MonoidSumCount<T,\
    \ int>::S;\n    Segtree<MonoidSumCount<T, int>> seg;\n    Compress<T> comp;\n\n\
    \    SumCountManager() = default;\n    SumCountManager(std::vector<T> xs) {\n\
    \        comp = Compress<T>(xs);\n        seg = Segtree<MonoidSumCount<T, int>>((int)comp.size());\n\
    \    }\n\n    void add(T val) {\n        int pos = comp.get(val);\n        assert(pos\
    \ < (int)comp.size() && comp[pos] == val);\n        auto x = seg.get(pos);\n \
    \       seg.set(pos, S(x.sum + val, x.cnt + 1));\n    }\n\n    int get(T val)\
    \ const {\n        return comp.get(val);\n    }\n};"
  dependsOn:
  - misc/compress.hpp
  - data-structure/segtree/segtree.hpp
  - data-structure/monoid/sum_count.hpp
  isVerificationFile: false
  path: data-structure/utils/sum_count_manager.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/data-structure/basic-api.test.cpp
  - test/mytest/data-structure/helper-regressions.test.cpp
documentation_of: data-structure/utils/sum_count_manager.hpp
layout: document
title: "\u5024\u3054\u3068\u306E\u548C\u30FB\u500B\u6570\u7BA1\u7406"
---

## このライブラリでできること

`SumCountManager<T>` は、追加され得る値をあらかじめ座標圧縮し、値ごとの合計と個数をセグメント木で管理する補助クラスです。たとえば値域を指定して、そこに含まれる要素数や総和を集約するための土台になります。候補値の個数を $K$ とします。

## 使い方

構築時には「最初に存在する要素」ではなく「今後追加する可能性がある値」を渡します。集計は空の状態から始まり、`add(x)` ごとに値 $x$ の位置の合計へ $x$、個数へ $1$ を加える設計です。

例では候補 $10,20$ を登録し、$10$ を1個追加した状態の総和と個数を取得する呼び出し形を示しています。`get(x)` は個数ではなく圧縮後の位置を返します。

```cpp
#include "template/template.cpp"
#include "data-structure/utils/sum_count_manager.hpp"

int main() {
    SumCountManager<long long> manager(vector<long long>{10, 20});
    manager.add(10);
    auto x = manager.seg.prod(0, 2);
    assert(x.sum == 10 && x.cnt == 1);
}
```

## API・計算量

この構成の空間計算量は $O(K)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `SumCountManager(xs)` | 候補を圧縮し、空の集計木を作る。 | O(K log K) |
| `add(val)` | 登録済みの値を 1 個追加。 | O(log K) |
| `get(val)` | 候補配列の lower_bound の位置。 | O(log K) |

## 利用条件と実装上の注意

公開型 S は `MonoidSumCount<T,int>::S` で、sum と cnt を持つ集約値です。引数なしの構築では候補が空なので、値を追加する前に候補付きのオブジェクトを代入してください。

`add` に渡す値は構築時の候補に含めてください。公開メンバ `comp` が圧縮表、`seg` が集計木です。値域を問い合わせる際は、値の両端を圧縮表で添字へ変換し、その添字区間を `seg.prod` に渡します。
