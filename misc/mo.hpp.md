---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/static-range-inversions-query.test.cpp
    title: test/library-checker/data-structure/static-range-inversions-query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/mo-and-fraction.test.cpp
    title: test/mytest/misc/mo-and-fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/misc/utilities.test.cpp
    title: test/mytest/misc/utilities.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\n\nclass Mo {\n  public:\n\
    \    explicit Mo(int n)\n        : n(n), l(0), r(0), idx(0), BUCKET_SIZE(std::sqrt(n)),\
    \ isBuilt(false) {}\n    void insert(int l, int r) {\n        assert(0 <= l and\
    \ l < r and r <= n);\n        L.push_back(l);\n        R.push_back(r);\n    }\n\
    \    void set_bucketsize(int bs) {\n        assert(!isBuilt);\n        BUCKET_SIZE\
    \ = std::max(1, bs);\n    }\n    void build() {\n        ord.resize(L.size());\n\
    \        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(ord.begin(),\
    \ ord.end(), [&](int a, int b) {\n            if(L[a] / BUCKET_SIZE != L[b] /\
    \ BUCKET_SIZE) {\n                return (L[a] < L[b]);\n            }\n     \
    \       return (R[a] < R[b]);\n        });\n        isBuilt = true;\n    }\n \
    \   template <class AddLeft, class AddRight, class DelLeft, class DelRight>\n\
    \    int process(const AddLeft &add_left, const AddRight &add_right,\n       \
    \         const DelLeft &del_left, const DelRight &del_right) {\n        assert(isBuilt);\n\
    \        if(idx == (int)ord.size()) return -1;\n        int qid = ord[idx++];\n\
    \        while(l > L[qid]) add_left(--l);\n        while(r < R[qid]) add_right(r++);\n\
    \        while(l < L[qid]) del_left(l++);\n        while(r > R[qid]) del_right(--r);\n\
    \        return qid;\n    }\n\n  private:\n    std::vector<int> L, R, ord;\n \
    \   int n, l, r, idx;\n    int BUCKET_SIZE;\n    bool isBuilt;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\n\nclass Mo {\n  public:\n    explicit Mo(int\
    \ n)\n        : n(n), l(0), r(0), idx(0), BUCKET_SIZE(std::sqrt(n)), isBuilt(false)\
    \ {}\n    void insert(int l, int r) {\n        assert(0 <= l and l < r and r <=\
    \ n);\n        L.push_back(l);\n        R.push_back(r);\n    }\n    void set_bucketsize(int\
    \ bs) {\n        assert(!isBuilt);\n        BUCKET_SIZE = std::max(1, bs);\n \
    \   }\n    void build() {\n        ord.resize(L.size());\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        std::sort(ord.begin(), ord.end(), [&](int a, int b)\
    \ {\n            if(L[a] / BUCKET_SIZE != L[b] / BUCKET_SIZE) {\n            \
    \    return (L[a] < L[b]);\n            }\n            return (R[a] < R[b]);\n\
    \        });\n        isBuilt = true;\n    }\n    template <class AddLeft, class\
    \ AddRight, class DelLeft, class DelRight>\n    int process(const AddLeft &add_left,\
    \ const AddRight &add_right,\n                const DelLeft &del_left, const DelRight\
    \ &del_right) {\n        assert(isBuilt);\n        if(idx == (int)ord.size())\
    \ return -1;\n        int qid = ord[idx++];\n        while(l > L[qid]) add_left(--l);\n\
    \        while(r < R[qid]) add_right(r++);\n        while(l < L[qid]) del_left(l++);\n\
    \        while(r > R[qid]) del_right(--r);\n        return qid;\n    }\n\n  private:\n\
    \    std::vector<int> L, R, ord;\n    int n, l, r, idx;\n    int BUCKET_SIZE;\n\
    \    bool isBuilt;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/misc/utilities.test.cpp
  - test/mytest/misc/mo-and-fraction.test.cpp
  - test/library-checker/data-structure/static-range-inversions-query.test.cpp
documentation_of: misc/mo.hpp
layout: document
link: https://ei1333.hateblo.jp/entry/2017/09/11/211011
title: "Mo \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---

## このライブラリでできること

`Mo` は、配列上の区間クエリを、区間の左右端の移動量が少なくなる順に並べ替えます。現在の区間へ要素を1つ追加・削除したときに答えを更新できるなら、各クエリを最初から計算し直す必要がなくなります。

配列長を $N$、クエリ数を $Q$、左端のバケット幅を $B$ とします。端点移動の総数の上界は $O(QB+N^2/B+N)$ です。既定の $B\simeq\sqrt N$ では $O((N+Q)\sqrt N)$ となり、これに1回の追加・削除の処理時間を掛けて評価します。

## 使い方

クエリを `insert(l,r)` で登録し、`build()` で順序を決めます。その後、空区間を表す状態から `process` を繰り返します。引数の4つの関数は、左へ追加・右へ追加・左から削除・右から削除する操作で、処理対象の要素の添字を受け取ります。

`process` が返す番号は登録順のクエリ番号です。処理順は変わっていても、この番号を使えば答えを元の順序に保存できます。例では区間和を管理し、$[1,3)$ の和 $5$ と $[0,4)$ の和 $10$ を得ています。

```cpp
#include "template/template.cpp"
#include "misc/mo.hpp"

int main() {
    vector<int> a{1, 2, 3, 4};
    Mo mo(4);
    mo.insert(1, 3); mo.insert(0, 4);
    mo.build();
    long long sum = 0;
    auto add = [&](int i) { sum += a[i]; };
    auto del = [&](int i) { sum -= a[i]; };
    vector<long long> ans(2);
    for (int id; (id = mo.process(add, add, del, del)) != -1;) ans[id] = sum;
    assert(ans[0] == 5 && ans[1] == 10);
}
```

## API・計算量

クエリの保存と処理順の保持に $O(Q)$ の空間を使います。端点移動の時間は、移動回数とコールバックの処理時間を掛けて評価してください。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Mo(n)` | 初期区間 [0,0)、幅 floor(sqrt(n)) で初期化。 | O(1) |
| `insert(l,r)` | [l,r) のクエリを追加。ID は追加順。 | 償却 O(1) |
| `set_bucketsize(bs)` | 幅を max(1,bs) に変更。 | O(1) |
| `build()` | 左端のバケット、右端の順にクエリをソート。 | O(Q log Q) |
| `process(add_left,add_right,del_left,del_right)` | 次のクエリに移動し ID を返す。終了時 -1。 | 移動距離×コールバックコスト |

## 利用条件と実装上の注意

$N\ge1$、$0\le l<r\le N$ としてください。全クエリを登録してから一度だけ構築し、その後は追加せずに処理を進めます。`process` が $-1$ を返したら終了です。

端点の移動では、先に左右の追加を済ませてから削除します。削除コールバックが通知する要素は、その時点の区間に必ず含まれます。区間が互いに離れている場合でも、負の出現回数を許す必要はありません。
