---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/data-structure/segment-tree-api.test.cpp
    title: test/mytest/data-structure/segment-tree-api.test.cpp
  - icon: ':x:'
    path: test/yukicoder/yuki789.test.cpp
    title: test/yukicoder/yuki789.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/dynamic-segtree.hpp\"\n\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\n\ntemplate <class Monoid, long\
    \ long id_min, long long id_max>\nclass DynamicSegtree {\n  public:\n    using\
    \ T = typename Monoid::value_type;\n\n    explicit DynamicSegtree() : root(nullptr)\
    \ {}\n\n    void set(long long p, T val) { set(root, id_min, id_max, p, val);\
    \ }\n    T get(long long p) { return get(root, id_min, id_max, p); }\n    T prod(long\
    \ long l, long long r) { return prod(root, id_min, id_max, l, r); }\n \n  private:\n\
    \    struct Node {\n        T val;\n        std::array<Node *, 2> ch;\n      \
    \  Node() : val(Monoid::e()), ch({nullptr, nullptr}) {}\n        Node(T val) :\
    \ val(val), ch({nullptr, nullptr}) {}\n    };\n\n    Node *root;\n\n    void set(Node\
    \ *&node, long long l, long long r, long long p, T val) {\n        if(node ==\
    \ nullptr) node = new Node();\n        if(r - l == 1) {\n            node->val\
    \ = val;\n            return;\n        }\n        long long mid = (l + r) / 2;\n\
    \        if(p < mid)\n            set(node->ch[0], l, mid, p, val);\n        else\n\
    \            set(node->ch[1], mid, r, p, val);\n        node->val =\n        \
    \    Monoid::op(node->ch[0] == nullptr ? Monoid::e() : node->ch[0]->val,\n   \
    \                    node->ch[1] == nullptr ? Monoid::e() : node->ch[1]->val);\n\
    \    }\n\n    T get(Node *&node, long long l, long long r, long long p) {\n  \
    \      if(node == nullptr) return Monoid::e();\n        if(r - l == 1) return\
    \ node->val;\n        long long mid = (l + r) / 2;\n        if(p < mid)\n    \
    \        return get(node->ch[0], l, mid, p);\n        else\n            return\
    \ get(node->ch[1], mid, r, p);\n    }\n\n    T prod(Node *&node, long long l,\
    \ long long r, long long ql, long long qr) {\n        if(node == nullptr or (qr\
    \ <= l or r <= ql)) return Monoid::e();\n        if(ql <= l and r <= qr) return\
    \ node->val;\n        long long mid = (l + r) / 2;\n        return Monoid::op(prod(node->ch[0],\
    \ l, mid, ql, qr),\n                          prod(node->ch[1], mid, r, ql, qr));\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class Monoid, long long id_min, long long id_max>\nclass DynamicSegtree\
    \ {\n  public:\n    using T = typename Monoid::value_type;\n\n    explicit DynamicSegtree()\
    \ : root(nullptr) {}\n\n    void set(long long p, T val) { set(root, id_min, id_max,\
    \ p, val); }\n    T get(long long p) { return get(root, id_min, id_max, p); }\n\
    \    T prod(long long l, long long r) { return prod(root, id_min, id_max, l, r);\
    \ }\n \n  private:\n    struct Node {\n        T val;\n        std::array<Node\
    \ *, 2> ch;\n        Node() : val(Monoid::e()), ch({nullptr, nullptr}) {}\n  \
    \      Node(T val) : val(val), ch({nullptr, nullptr}) {}\n    };\n\n    Node *root;\n\
    \n    void set(Node *&node, long long l, long long r, long long p, T val) {\n\
    \        if(node == nullptr) node = new Node();\n        if(r - l == 1) {\n  \
    \          node->val = val;\n            return;\n        }\n        long long\
    \ mid = (l + r) / 2;\n        if(p < mid)\n            set(node->ch[0], l, mid,\
    \ p, val);\n        else\n            set(node->ch[1], mid, r, p, val);\n    \
    \    node->val =\n            Monoid::op(node->ch[0] == nullptr ? Monoid::e()\
    \ : node->ch[0]->val,\n                       node->ch[1] == nullptr ? Monoid::e()\
    \ : node->ch[1]->val);\n    }\n\n    T get(Node *&node, long long l, long long\
    \ r, long long p) {\n        if(node == nullptr) return Monoid::e();\n       \
    \ if(r - l == 1) return node->val;\n        long long mid = (l + r) / 2;\n   \
    \     if(p < mid)\n            return get(node->ch[0], l, mid, p);\n        else\n\
    \            return get(node->ch[1], mid, r, p);\n    }\n\n    T prod(Node *&node,\
    \ long long l, long long r, long long ql, long long qr) {\n        if(node ==\
    \ nullptr or (qr <= l or r <= ql)) return Monoid::e();\n        if(ql <= l and\
    \ r <= qr) return node->val;\n        long long mid = (l + r) / 2;\n        return\
    \ Monoid::op(prod(node->ch[0], l, mid, ql, qr),\n                          prod(node->ch[1],\
    \ mid, r, ql, qr));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/dynamic-segtree.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/yuki789.test.cpp
  - test/mytest/data-structure/segment-tree-api.test.cpp
documentation_of: data-structure/segtree/dynamic-segtree.hpp
layout: document
link: https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
title: Dynamic Segment Tree
---

## このライブラリでできること

`DynamicSegtree<Monoid,id_min,id_max>` は、添字の範囲が広くても、更新した場所の周辺だけにノードを作るセグメント木です。たとえば位置が $10^9$ まであっても、少数の位置しか更新しないなら、配列全体を確保せずに区間和などを管理できます。

定義域は $[\mathrm{id\_min},\mathrm{id\_max})$、その幅を $U$ とします。未設定の位置は単位元 `e()` として扱い、点更新・点取得・区間集約をそれぞれ $O(\log U)$ 時間で行います。更新回数を $Q$ とすると、確保するノード数は高々 $O(Q\log U)$ です。

## 使い方

モノイドの型と添字の両端をテンプレート引数に指定します。例では $[0,10^9)$ を扱い、位置 $123456$ だけを $10$ にします。それ以外の値は加算の単位元 $0$ なので、位置を含む区間の和も $10$ になります。

`set` は値の上書きです。通常の `Segtree` と異なり、点への `apply` や境界探索は用意されていません。

```cpp
#include "template/template.cpp"
#include "data-structure/segtree/dynamic-segtree.hpp"
#include "data-structure/monoid/add.hpp"

int main() {
    DynamicSegtree<MonoidAdd<long long>, 0, 1000000000LL> seg;
    seg.set(123456, 10);
    assert(seg.prod(0, 200000) == 10);
}
```

## API・計算量

$Q$ 回の更新によって確保する空間は、高々 $O(Q\log U)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `DynamicSegtree()` | 空の木。未設定点は e()。 | O(1) |
| `set(p, val)` | 点 p を上書き。 | O(log U) |
| `get(p)` | 点 p の値。 | O(log U) |
| `prod(l, r)` | [l,r) の積。 | O(log U) |

## 利用条件と実装上の注意

モノイドには結合的な `op` と単位元 `e` が必要です。計算量は、その演算と値のコピーが定数時間の場合です。点の位置と問い合わせ区間は定義域内に収めてください。

定義域は `id_min < id_max` とし、負の境界も使えます。中央を `(l+r)/2` で計算するため、`l+r` と区間長 `r-l` が long long に収まる必要があります。区間長が2以上なら、0方向への丸めでも中央は両端の間に入るため、分割は進みます。

確保したノードの解放処理はなく、コピーしたオブジェクトはノードを共有します。コピーを独立した木として更新することはできません。
