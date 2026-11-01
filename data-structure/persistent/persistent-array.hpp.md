---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent/persistent-unionfind.hpp
    title: "\u6C38\u7D9A Union Find"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-unionfind.test.cpp
    title: test/library-checker/data-structure/persistent-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/initialization-and-monoids.test.cpp
    title: test/mytest/data-structure/initialization-and-monoids.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent/persistent-array.hpp\"\n\n#include\
    \ <string.h>\n#include <utility>\n#include <vector>\n\ntemplate <class T, int\
    \ LOG = 4> struct PersistentArray {\n    struct Node {\n        T val;\n     \
    \   Node *childs[1 << LOG];\n\n        Node(): val{} { memset(childs, 0, sizeof(childs));\
    \ }\n        Node(const Node *node): val(node->val) { memcpy(childs, node->childs,\
    \ sizeof(childs)); }\n        Node(const Node &node): val(node.val) { memcpy(childs,\
    \ node.childs, sizeof(childs)); }\n    };\n\n    Node *root;\n    int depth;\n\
    \    T identity;\n    const int full_bit = (1 << LOG) - 1;\n\n    PersistentArray():\
    \ PersistentArray(0) {}\n    explicit PersistentArray(int N, const T &id = 0)\n\
    \        : PersistentArray(std::vector<T>(N, id)) {\n        identity = id;\n\
    \    }\n    PersistentArray(const std::vector<T> &v) : root(new Node()), depth(0),\
    \ identity{} {\n        int N = (int)v.size();\n        while(N > 0) {\n     \
    \       N >>= LOG;\n            depth++;\n        }\n        N = (int)v.size();\n\
    \        for(int i = 0; i < N; i++) {\n            Node *now = root;\n       \
    \     for(int mask = i, d = depth; d > 0; d--) {\n                if(!now->childs[mask\
    \ & full_bit]) {\n                    now->childs[mask & full_bit] = new Node();\n\
    \                }\n                now = now->childs[mask & full_bit];\n    \
    \            mask >>= LOG;\n            }\n            now->val = v[i];\n    \
    \    }\n    }\n\n    T get(int idx) { return get(root, idx); }\n\n    Node *set(int\
    \ idx, const T &new_value) { return set(root, idx, new_value); }\n\n    T get(Node\
    \ *node, int idx) {\n        for(int i = 0; i < depth; i++) {\n            node\
    \ = node ? node->childs[idx & full_bit] : nullptr;\n            idx >>= LOG;\n\
    \        }\n        return (node ? node->val : identity);\n    }\n\n    Node *set(Node\
    \ *node, int idx, T new_value) {\n        std::vector<std::pair<Node *, int>>\
    \ st;\n        for(int i = 0; i < depth; i++) {\n            st.emplace_back(node,\
    \ idx & full_bit);\n            node = node ? node->childs[idx & full_bit] : nullptr;\n\
    \            idx >>= LOG;\n        }\n        Node *new_child = new Node();\n\
    \        new_child->val = new_value;\n        while(!st.empty()) {\n         \
    \   auto [par, k] = st.back();\n            st.pop_back();\n            Node *new_par\
    \ = par ? new Node(par) : new Node();\n            new_par->childs[k] = new_child;\n\
    \            new_child = new_par;\n        }\n        return (root = new_child);\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <string.h>\n#include <utility>\n#include <vector>\n\
    \ntemplate <class T, int LOG = 4> struct PersistentArray {\n    struct Node {\n\
    \        T val;\n        Node *childs[1 << LOG];\n\n        Node(): val{} { memset(childs,\
    \ 0, sizeof(childs)); }\n        Node(const Node *node): val(node->val) { memcpy(childs,\
    \ node->childs, sizeof(childs)); }\n        Node(const Node &node): val(node.val)\
    \ { memcpy(childs, node.childs, sizeof(childs)); }\n    };\n\n    Node *root;\n\
    \    int depth;\n    T identity;\n    const int full_bit = (1 << LOG) - 1;\n\n\
    \    PersistentArray(): PersistentArray(0) {}\n    explicit PersistentArray(int\
    \ N, const T &id = 0)\n        : PersistentArray(std::vector<T>(N, id)) {\n  \
    \      identity = id;\n    }\n    PersistentArray(const std::vector<T> &v) : root(new\
    \ Node()), depth(0), identity{} {\n        int N = (int)v.size();\n        while(N\
    \ > 0) {\n            N >>= LOG;\n            depth++;\n        }\n        N =\
    \ (int)v.size();\n        for(int i = 0; i < N; i++) {\n            Node *now\
    \ = root;\n            for(int mask = i, d = depth; d > 0; d--) {\n          \
    \      if(!now->childs[mask & full_bit]) {\n                    now->childs[mask\
    \ & full_bit] = new Node();\n                }\n                now = now->childs[mask\
    \ & full_bit];\n                mask >>= LOG;\n            }\n            now->val\
    \ = v[i];\n        }\n    }\n\n    T get(int idx) { return get(root, idx); }\n\
    \n    Node *set(int idx, const T &new_value) { return set(root, idx, new_value);\
    \ }\n\n    T get(Node *node, int idx) {\n        for(int i = 0; i < depth; i++)\
    \ {\n            node = node ? node->childs[idx & full_bit] : nullptr;\n     \
    \       idx >>= LOG;\n        }\n        return (node ? node->val : identity);\n\
    \    }\n\n    Node *set(Node *node, int idx, T new_value) {\n        std::vector<std::pair<Node\
    \ *, int>> st;\n        for(int i = 0; i < depth; i++) {\n            st.emplace_back(node,\
    \ idx & full_bit);\n            node = node ? node->childs[idx & full_bit] : nullptr;\n\
    \            idx >>= LOG;\n        }\n        Node *new_child = new Node();\n\
    \        new_child->val = new_value;\n        while(!st.empty()) {\n         \
    \   auto [par, k] = st.back();\n            st.pop_back();\n            Node *new_par\
    \ = par ? new Node(par) : new Node();\n            new_par->childs[k] = new_child;\n\
    \            new_child = new_par;\n        }\n        return (root = new_child);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent/persistent-array.hpp
  requiredBy:
  - data-structure/persistent/persistent-unionfind.hpp
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/persistent-unionfind.test.cpp
  - test/mytest/data-structure/initialization-and-monoids.test.cpp
documentation_of: data-structure/persistent/persistent-array.hpp
layout: document
title: "\u6C38\u7D9A\u914D\u5217"
---

## このライブラリでできること

`PersistentArray<T,LOG>` は、更新前の状態を残したまま、新しい配列の状態を作れる永続配列です。過去の状態をすべて丸ごとコピーする代わりに、更新対象までの経路だけをコピーし、それ以外の部分は共有します。

分岐数を $B=2^{\mathrm{LOG}}$、元の配列長を $N>0$、深さを $d=\lfloor\log_B N\rfloor+1$ とします。値の取得は $O(d)$、更新は各段の子配列をコピーするため $O(Bd)$ 時間です。`LOG` を定数と見れば、どちらも $O(\log N)$ です。

## 使い方

このクラスでは、版を表すものはオブジェクト全体ではなく `Node*` 型の根です。更新前に `root` を保存し、`set` の返り値を新しい版として保存します。`get(root,index)` に根を指定すれば、どの版の値も取得できます。

例では初期版の位置1は $2$、更新版では $9$ です。新しい版を作っても、保存した古い根からは引き続き $2$ を取得できます。`set` は新しい根を返すと同時に、オブジェクトの現在の `root` も変更します。

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-array.hpp"

int main() {
    PersistentArray<int> a(vector<int>{1, 2, 3});
    auto old_root = a.root;
    auto new_root = a.set(1, 9);
    assert(a.get(old_root, 1) == 2);
    assert(a.get(new_root, 1) == 9);
}
```

## API・計算量

分岐数を定数とした構築時の空間は $O(N+d)$、1回の更新で増える空間は $O(Bd)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentArray()` | 空配列を構築。 | O(B) |
| `PersistentArray(v)` | v から初期版を構築。 | O(Nd + B(N+d)) 上界 |
| `PersistentArray(N, id=0)` | N 要素を id で初期化。 | O(Nd + B(N+d)) 上界 |
| `get(idx), get(node, idx)` | 現在版・指定版の値。 | O(d) |
| `set(idx, value), set(node, idx, value)` | 現在版・指定版から更新し、新 root を返す。同時に root も変更。 | O(Bd) |
| `Node(), Node(pointer), Node(reference)` | 子配列を初期化・コピーする内部ノード。コピー時は val と子配列をコピーする。 | O(B) |

## 利用条件と実装上の注意

配列またはサイズと初期値を渡して構築し、添字を $[0,N)$ に限定してください。引数なしの構築は N=0 の空配列であり、空配列には get/set を呼べません。

内部の既定値 identity は、配列からの構築では T{}、サイズ指定では id です。範囲外の添字に対するアクセスは保証しません。

`Node` は値 `val` と子配列 `childs` を持ち、`depth` は木の深さです。これらは公開されていますが、版の保存以外では直接変更しないでください。ノードの解放処理はありません。
