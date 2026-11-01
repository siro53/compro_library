---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/persistent-queue.test.cpp
    title: test/library-checker/data-structure/persistent-queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/persistent-api.test.cpp
    title: test/mytest/data-structure/persistent-api.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/persistent/persistent-queue.hpp\"\n\ntemplate\
    \ <class T, int LOG = 20> struct PersistentQueue {\n    struct Node {\n      \
    \  T val;\n        int idx;\n        Node *pre[LOG]; // pre[k] := \u3053\u306E\
    \u30CE\u30FC\u30C9\u306E2^k\u500B\u524D\u306E\u30CE\u30FC\u30C9\n\n        Node(T\
    \ val, int idx) : val(val), idx(idx) {}\n    };\n    Node *front_node;\n    Node\
    \ *back_node;\n\n    PersistentQueue() : front_node(nullptr), back_node(nullptr)\
    \ {}\n    explicit PersistentQueue(Node *front_node, Node *back_node)\n      \
    \  : front_node(front_node), back_node(back_node) {}\n    PersistentQueue push(const\
    \ T &x) {\n        Node *new_node = new Node(x, back_node ? back_node->idx + 1\
    \ : 0);\n        new_node->pre[0] = back_node;\n        for(int i = 1; i < LOG;\
    \ i++) {\n            Node *tmp = new_node->pre[i - 1];\n            if(!tmp)\
    \ break;\n            new_node->pre[i] = tmp->pre[i - 1];\n        }\n       \
    \ return PersistentQueue(front_node ? front_node : new_node, new_node);\n    }\n\
    \    PersistentQueue pop() {\n        if(!front_node or !back_node or front_node->idx\
    \ == back_node->idx) {\n            return PersistentQueue();\n        }\n   \
    \     int sz = back_node->idx - front_node->idx - 1;\n        Node *node = back_node;\n\
    \        for(int i = 0; i < LOG; i++)\n            if(sz >> i & 1) node = node->pre[i];\n\
    \        return PersistentQueue(node, back_node);\n    }\n    bool empty() const\
    \ { return (front_node == nullptr and back_node == nullptr); }\n    T front()\
    \ const { return front_node->val; }\n    T back() const { return back_node->val;\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class T, int LOG = 20> struct PersistentQueue {\n\
    \    struct Node {\n        T val;\n        int idx;\n        Node *pre[LOG];\
    \ // pre[k] := \u3053\u306E\u30CE\u30FC\u30C9\u306E2^k\u500B\u524D\u306E\u30CE\
    \u30FC\u30C9\n\n        Node(T val, int idx) : val(val), idx(idx) {}\n    };\n\
    \    Node *front_node;\n    Node *back_node;\n\n    PersistentQueue() : front_node(nullptr),\
    \ back_node(nullptr) {}\n    explicit PersistentQueue(Node *front_node, Node *back_node)\n\
    \        : front_node(front_node), back_node(back_node) {}\n    PersistentQueue\
    \ push(const T &x) {\n        Node *new_node = new Node(x, back_node ? back_node->idx\
    \ + 1 : 0);\n        new_node->pre[0] = back_node;\n        for(int i = 1; i <\
    \ LOG; i++) {\n            Node *tmp = new_node->pre[i - 1];\n            if(!tmp)\
    \ break;\n            new_node->pre[i] = tmp->pre[i - 1];\n        }\n       \
    \ return PersistentQueue(front_node ? front_node : new_node, new_node);\n    }\n\
    \    PersistentQueue pop() {\n        if(!front_node or !back_node or front_node->idx\
    \ == back_node->idx) {\n            return PersistentQueue();\n        }\n   \
    \     int sz = back_node->idx - front_node->idx - 1;\n        Node *node = back_node;\n\
    \        for(int i = 0; i < LOG; i++)\n            if(sz >> i & 1) node = node->pre[i];\n\
    \        return PersistentQueue(node, back_node);\n    }\n    bool empty() const\
    \ { return (front_node == nullptr and back_node == nullptr); }\n    T front()\
    \ const { return front_node->val; }\n    T back() const { return back_node->val;\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent/persistent-queue.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/data-structure/persistent-queue.test.cpp
  - test/mytest/data-structure/persistent-api.test.cpp
documentation_of: data-structure/persistent/persistent-queue.hpp
layout: document
title: "\u6C38\u7D9A\u30AD\u30E5\u30FC"
---

## このライブラリでできること

`PersistentQueue<T,LOG>` は、過去のキューを残したまま末尾への追加・先頭の削除を行えるキューです。ある操作列の途中から別の操作列へ分岐する場合に使えます。操作は元のキューを書き換えず、操作後のキューを返します。

末尾のノードから過去のノードをたどるダブリング表を持ち、削除後の先頭を探します。`LOG` はこの表の段数で、`push/pop` は $O(\mathrm{LOG})$、先頭・末尾の取得は $O(1)$ 時間です。

## 使い方

返り値を新しい変数へ保存すると、新旧の版を同時に使えます。例では `q1` が $[10]$、`q2` が $[10,20]$、`q3` が $[20]$ です。`q2.pop()` を呼んでも、`q1` や `q2` の内容は変わりません。

現在の版だけを進めたい場合も、`q=q.push(x)` のように返り値を代入してください。`q.push(x)` と呼ぶだけでは `q` は更新されません。

```cpp
#include "template/template.cpp"
#include "data-structure/persistent/persistent-queue.hpp"

int main() {
    PersistentQueue<int> q0;
    auto q1 = q0.push(10);
    auto q2 = q1.push(20);
    auto q3 = q2.pop();
    assert(q1.front() == 10);
    assert(q3.front() == 20);
}
```

## API・計算量

1回のpushで $O(\mathrm{LOG})$ の空間を追加し、各版を表すキュー自体は $O(1)$ の空間で保持します。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `PersistentQueue()` | 空の版を作る。 | O(1) |
| `PersistentQueue(front_node, back_node)` | ノードを指定して版を作る内部用構築。 | O(1) |
| `push(x)` | 末尾に追加した新しい版を返す。元の版は不変。 | O(LOG) |
| `pop()` | 先頭を取り除いた版を返す。空なら空の版。 | O(LOG) |
| `front(), back()` | 先頭・末尾の値。 | O(1) |
| `empty()` | 空判定。 | O(1) |
| `Node(val, idx)` | ノードの値・番号を設定。祖先配列の初期化は push 側で行う。 | O(1) |

## 利用条件と実装上の注意

`front/back` は非空のキューに対して呼んでください。空のキューの `pop()` は空の版を返します。

`LOG` は、`pop` で必要になる祖先までの距離が $2^{\mathrm{LOG}}$ 未満になるように選びます。ノードの `val` は値、`idx` はその履歴に沿った連番、`pre[k]` は $2^k$ 個前のノードです。`front_node/back_node` を直接指定するコンストラクタは内部処理向けで、整合したノードの組を渡す必要があります。ノードの解放処理はありません。
