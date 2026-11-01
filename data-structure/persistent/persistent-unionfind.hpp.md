---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-array.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-unionfind.test.cpp
    title: test/library-checker/data-structure/persistent-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent/persistent-unionfind.hpp\"\n\n\
    #include <algorithm>\n#include <tuple>\n\n#line 2 \"data-structure/persistent/persistent-array.hpp\"\
    \n\n#include <string.h>\n#include <utility>\n#include <vector>\n\ntemplate <class\
    \ T, int LOG = 4> struct PersistentArray {\n    struct Node {\n        T val;\n\
    \        Node *childs[1 << LOG];\n\n        Node() { memset(childs, 0, sizeof(childs));\
    \ }\n        Node(const Node *node) { memcpy(childs, node->childs, sizeof(childs));\
    \ }\n        Node(const Node &node) { memcpy(childs, node.childs, sizeof(childs));\
    \ }\n    };\n\n    Node *root;\n    int depth;\n    T identity;\n    const int\
    \ full_bit = (1 << LOG) - 1;\n\n    PersistentArray() {}\n    explicit PersistentArray(int\
    \ N, const T &id = 0)\n        : root(new Node()), depth(0), identity(id) {\n\
    \        PersistentArray(std::vector<T>(N, id));\n    }\n    PersistentArray(const\
    \ std::vector<T> &v) : root(new Node()), depth(0) {\n        int N = (int)v.size();\n\
    \        while(N > 0) {\n            N >>= LOG;\n            depth++;\n      \
    \  }\n        N = (int)v.size();\n        for(int i = 0; i < N; i++) {\n     \
    \       Node *now = root;\n            for(int mask = i, d = depth; d > 0; d--)\
    \ {\n                if(!now->childs[mask & full_bit]) {\n                   \
    \ now->childs[mask & full_bit] = new Node();\n                }\n            \
    \    now = now->childs[mask & full_bit];\n                mask >>= LOG;\n    \
    \        }\n            now->val = v[i];\n        }\n    }\n\n    T get(int idx)\
    \ { return get(root, idx); }\n\n    Node *set(int idx, const T &new_value) { return\
    \ set(root, idx, new_value); }\n\n    T get(Node *node, int idx) {\n        for(int\
    \ i = 0; i < depth; i++) {\n            node = node ? node->childs[idx & full_bit]\
    \ : nullptr;\n            idx >>= LOG;\n        }\n        return (node ? node->val\
    \ : identity);\n    }\n\n    Node *set(Node *node, int idx, T new_value) {\n \
    \       std::vector<std::pair<Node *, int>> st;\n        for(int i = 0; i < depth;\
    \ i++) {\n            st.emplace_back(node, idx & full_bit);\n            node\
    \ = node ? node->childs[idx & full_bit] : nullptr;\n            idx >>= LOG;\n\
    \        }\n        Node *new_child = new Node();\n        new_child->val = new_value;\n\
    \        while(!st.empty()) {\n            auto [par, k] = st.back();\n      \
    \      st.pop_back();\n            Node *new_par = par ? new Node(par) : new Node();\n\
    \            new_par->childs[k] = new_child;\n            new_child = new_par;\n\
    \        }\n        return (root = new_child);\n    }\n};\n#line 7 \"data-structure/persistent/persistent-unionfind.hpp\"\
    \n\nstruct PersistentUnionFind {\n    PersistentArray<int> par;\n    using Node\
    \ = decltype(par)::Node;\n    Node* root;\n\n    explicit PersistentUnionFind(int\
    \ n): par(std::vector<int>(n, -1)) {\n        root = par.root;\n    }\n    //\
    \ (leader, size)\n    std::pair<int, int> leader_and_size(int u, Node* r) {\n\
    \        int p = par.get(r, u);\n        return (p < 0 ? std::make_pair(u, -p)\
    \ : leader_and_size(p, r));\n    }\n    std::pair<int, int> leader_and_size(int\
    \ u) {\n        return leader_and_size(u, root);\n    }\n    inline int leader(int\
    \ u, Node* r) { return leader_and_size(u, r).first; }\n    inline int leader(int\
    \ u) { return leader_and_size(u, root).first; }\n    inline int size(int u, Node*\
    \ r) { return leader_and_size(u, r).second; }\n    inline int size(int u) { return\
    \ leader_and_size(u, root).second; }\n    inline bool same(int u, int v, Node*\
    \ r) { return (leader(u, r) == leader(v, r)); }\n    inline bool same(int u, int\
    \ v) { return same(u, v, root); }\n    bool merge(int u, int v, Node* r) {\n \
    \       int sz_u, sz_v;\n        std::tie(u, sz_u) = leader_and_size(u, r);\n\
    \        std::tie(v, sz_v) = leader_and_size(v, r);\n        if(u == v) return\
    \ false;\n        if(sz_u < sz_v) {\n            std::swap(u, v);\n          \
    \  std::swap(sz_u, sz_v);\n        }\n        r = par.set(r, u, -(sz_u + sz_v));\n\
    \        r = par.set(r, v, u);\n        root = r;\n        return true;\n    }\n\
    \    bool merge(int u, int v) { return merge(u, v, root); }\n    Node* get_root()\
    \ const { return root; }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <tuple>\n\n#include \"persistent-array.hpp\"\
    \n\nstruct PersistentUnionFind {\n    PersistentArray<int> par;\n    using Node\
    \ = decltype(par)::Node;\n    Node* root;\n\n    explicit PersistentUnionFind(int\
    \ n): par(std::vector<int>(n, -1)) {\n        root = par.root;\n    }\n    //\
    \ (leader, size)\n    std::pair<int, int> leader_and_size(int u, Node* r) {\n\
    \        int p = par.get(r, u);\n        return (p < 0 ? std::make_pair(u, -p)\
    \ : leader_and_size(p, r));\n    }\n    std::pair<int, int> leader_and_size(int\
    \ u) {\n        return leader_and_size(u, root);\n    }\n    inline int leader(int\
    \ u, Node* r) { return leader_and_size(u, r).first; }\n    inline int leader(int\
    \ u) { return leader_and_size(u, root).first; }\n    inline int size(int u, Node*\
    \ r) { return leader_and_size(u, r).second; }\n    inline int size(int u) { return\
    \ leader_and_size(u, root).second; }\n    inline bool same(int u, int v, Node*\
    \ r) { return (leader(u, r) == leader(v, r)); }\n    inline bool same(int u, int\
    \ v) { return same(u, v, root); }\n    bool merge(int u, int v, Node* r) {\n \
    \       int sz_u, sz_v;\n        std::tie(u, sz_u) = leader_and_size(u, r);\n\
    \        std::tie(v, sz_v) = leader_and_size(v, r);\n        if(u == v) return\
    \ false;\n        if(sz_u < sz_v) {\n            std::swap(u, v);\n          \
    \  std::swap(sz_u, sz_v);\n        }\n        r = par.set(r, u, -(sz_u + sz_v));\n\
    \        r = par.set(r, v, u);\n        root = r;\n        return true;\n    }\n\
    \    bool merge(int u, int v) { return merge(u, v, root); }\n    Node* get_root()\
    \ const { return root; }\n};"
  dependsOn:
  - data-structure/persistent/persistent-array.hpp
  isVerificationFile: false
  path: data-structure/persistent/persistent-unionfind.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/persistent-unionfind.test.cpp
documentation_of: data-structure/persistent/persistent-unionfind.hpp
layout: document
title: "\u6C38\u7D9A Union Find"
---

## このライブラリでできること

`PersistentUnionFind` は、過去の併合状態を参照したり、その状態から別の併合を行ったりできる Union Find です。親と集合サイズを永続配列に保存するため、併合前の版も失われません。頂点数を $N$ とします。

通常の Union Find と異なり経路圧縮を行わず、小さい集合を大きい集合へつなぐ方法で木の高さを $O(\log N)$ に抑えます。親を1段たどるためにも永続配列への $O(\log N)$ のアクセスが必要なので、代表取得や併合は $O(\log^2 N)$ 時間です。

## 使い方

`get_root()` で現在の版を保存し、その根を問い合わせや併合の最後の引数へ渡します。根を省略したオーバーロードは、現在の版を対象にします。

例では初期版 `r0` では $0,1$ は別の集合、併合後の `r1` では同じ集合です。古い版への問い合わせでは状態を変えずに、その時点の連結性を確認できます。

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-unionfind.hpp"

int main() {
    PersistentUnionFind uf(3);
    auto r0 = uf.get_root();
    uf.merge(0, 1, r0);
    auto r1 = uf.get_root();
    assert(!uf.same(0, 1, r0));
    assert(uf.same(0, 1, r1));
}
```

## API・計算量

永続配列の分岐数を定数とすると、構築時に $O(N)$、併合が成功するたびに追加で $O(\log N)$ の空間を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentUnionFind(N)` | N 個の単独集合を構築。 | O(N log N) 上界 |
| `leader_and_size(u[, r])` | 現在版または r 版で (代表, 集合サイズ)。 | O(log² N) |
| `leader(u[, r]), size(u[, r])` | 代表・集合サイズ。 | O(log² N) |
| `same(u, v[, r])` | 同じ集合か。 | O(log² N) |
| `merge(u, v[, r])` | 指定版から併合し現在 root を更新。既に同じなら false。 | O(log² N) |
| `get_root()` | 現在版の root。 | O(1) |

## 利用条件と実装上の注意

頂点番号は $[0,N)$ です。表の `[,r]` は「根を指定する版と省略する版の両方がある」という表記であり、C++ の構文ではありません。

`merge(u,v,r)` が成功すると、`r` から作った新しい版が現在版になります。一方、すでに同じ集合であれば `false` を返し、現在版は変更しません。つまり、失敗した併合が自動的に `r` へ切り替えてくれるわけではありません。

公開メンバ `par/root` は内部状態です。版の保存には `get_root()` を使い、親配列を直接書き換えないでください。永続配列のノードには解放処理がありません。
