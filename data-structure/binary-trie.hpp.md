---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/data-structure/set-xor-min.test.cpp
    title: test/library-checker/data-structure/set-xor-min.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/binary-trie.test.cpp
    title: test/mytest/data-structure/binary-trie.test.cpp
  - icon: ':x:'
    path: test/mytest/data-structure/bit-queries.test.cpp
    title: test/mytest/data-structure/bit-queries.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/binary-trie.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\ntemplate <typename T = unsigned\
    \ int, int LOG = 32> class BinaryTrie {\n  public:\n    explicit BinaryTrie()\
    \ : root(nullptr), lazy_xor_value(0) {}\n    int count(T val) {\n        if(!root)\
    \ return 0;\n        Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--)\
    \ {\n            now = now->child[val >> i & 1];\n            if(!now or now->count\
    \ == 0) return 0;\n        }\n        return now->count;\n    }\n    void insert(T\
    \ val) {\n        if(!root) root = new Node();\n        Node *now = root;\n  \
    \      now->count++;\n        for(int i = LOG - 1; i >= 0; i--) {\n          \
    \  int dir = val >> i & 1;\n            Node *nxt = now->child[dir];\n       \
    \     if(!nxt) {\n                nxt = new Node();\n                now->child[dir]\
    \ = nxt;\n            }\n            now = nxt;\n            now->count++;\n \
    \       }\n    }\n    bool erase(T val) {\n        if(count(val) == 0) return\
    \ false;\n        Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--)\
    \ {\n            now->count--;\n            now = now->child[val >> i & 1];\n\
    \            assert(now != nullptr);\n            assert(now->count > 0);\n  \
    \      }\n        now->count--;\n        return true;\n    }\n    T min_element()\
    \ {\n        assert(root != nullptr);\n        T ret = 0;\n        Node *now =\
    \ root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            int dir = (lazy_xor_value\
    \ >> i & 1);\n            Node *nxt = now->child[dir];\n            if(!nxt or\
    \ nxt->count == 0) {\n                ret += T(1) << i;\n                nxt =\
    \ now->child[dir ^ 1];\n            }\n            now = nxt;\n            assert(now\
    \ != nullptr and now->count > 0);\n        }\n        return ret;\n    }\n   \
    \ T max_element() {\n        assert(root != nullptr);\n        T ret = 0;\n  \
    \      Node *now = root;\n        for(int i = LOG - 1; i >= 0; i--) {\n      \
    \      int dir = (lazy_xor_value >> i & 1) ^ 1;\n            Node *nxt = now->child[dir];\n\
    \            if(!nxt or nxt->count == 0) {\n                nxt = now->child[dir\
    \ ^ 1];\n            } else {\n                ret += T(1) << i;\n           \
    \ }\n            now = nxt;\n            assert(now != nullptr and now->count\
    \ > 0);\n        }\n        return ret;\n    }\n    T get_kth_element(int k) {\
    \ // \u5C0F\u3055\u3044\u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024(0-indexed)\n\
    \        assert(0 <= k and k < size());\n        Node *now = root;\n        T\
    \ ret = 0;\n        for(int i = LOG - 1; i >= 0; i--) {\n            int b = lazy_xor_value\
    \ >> i & 1;\n            int small_count = (now->child[b] ? now->child[b]->count\
    \ : 0);\n            int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count\
    \ : 0);\n            assert(0 < small_count + big_count);\n            assert(k\
    \ < small_count + big_count);\n            if(k >= small_count) {\n          \
    \      ret += T(1) << i;\n                now = now->child[b ^ 1];\n         \
    \       k -= small_count;\n            } else {\n                now = now->child[b];\n\
    \            }\n        }\n        return ret;\n    }\n    int lower_bound(T val)\
    \ {\n        int ret = 0;\n        Node* now = root;\n        for(int i = LOG\
    \ - 1; i >= 0; i--) {\n            if(!now || now->count == 0) break;\n      \
    \      int b = lazy_xor_value >> i & 1;\n            int small_count = (now->child[b]\
    \ ? now->child[b]->count : 0);\n            if(val >> i & 1) {\n             \
    \   ret += small_count;\n                now = now->child[b ^ 1];\n          \
    \  } else {\n                now = now->child[b];\n            }\n        }\n\
    \        return ret;\n    }\n    int upper_bound(T val) {\n        return lower_bound(val)\
    \ + count(val ^ lazy_xor_value);\n    }\n    int size() const {\n        if(!root)\
    \ return 0;\n        return root->count;\n    }\n    inline bool empty() const\
    \ { return (!root or root->count == 0); }\n    void all_xor(T val) { lazy_xor_value\
    \ ^= val; }\n\n  private:\n    struct Node {\n        int count;\n        std::array<Node\
    \ *, 2> child;\n        Node() : count(0), child({nullptr, nullptr}) {}\n    };\n\
    \    Node *root;\n    T lazy_xor_value;\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T = unsigned int, int LOG = 32> class\
    \ BinaryTrie {\n  public:\n    explicit BinaryTrie() : root(nullptr), lazy_xor_value(0)\
    \ {}\n    int count(T val) {\n        if(!root) return 0;\n        Node *now =\
    \ root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            now = now->child[val\
    \ >> i & 1];\n            if(!now or now->count == 0) return 0;\n        }\n \
    \       return now->count;\n    }\n    void insert(T val) {\n        if(!root)\
    \ root = new Node();\n        Node *now = root;\n        now->count++;\n     \
    \   for(int i = LOG - 1; i >= 0; i--) {\n            int dir = val >> i & 1;\n\
    \            Node *nxt = now->child[dir];\n            if(!nxt) {\n          \
    \      nxt = new Node();\n                now->child[dir] = nxt;\n           \
    \ }\n            now = nxt;\n            now->count++;\n        }\n    }\n   \
    \ bool erase(T val) {\n        if(count(val) == 0) return false;\n        Node\
    \ *now = root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            now->count--;\n\
    \            now = now->child[val >> i & 1];\n            assert(now != nullptr);\n\
    \            assert(now->count > 0);\n        }\n        now->count--;\n     \
    \   return true;\n    }\n    T min_element() {\n        assert(root != nullptr);\n\
    \        T ret = 0;\n        Node *now = root;\n        for(int i = LOG - 1; i\
    \ >= 0; i--) {\n            int dir = (lazy_xor_value >> i & 1);\n           \
    \ Node *nxt = now->child[dir];\n            if(!nxt or nxt->count == 0) {\n  \
    \              ret += T(1) << i;\n                nxt = now->child[dir ^ 1];\n\
    \            }\n            now = nxt;\n            assert(now != nullptr and\
    \ now->count > 0);\n        }\n        return ret;\n    }\n    T max_element()\
    \ {\n        assert(root != nullptr);\n        T ret = 0;\n        Node *now =\
    \ root;\n        for(int i = LOG - 1; i >= 0; i--) {\n            int dir = (lazy_xor_value\
    \ >> i & 1) ^ 1;\n            Node *nxt = now->child[dir];\n            if(!nxt\
    \ or nxt->count == 0) {\n                nxt = now->child[dir ^ 1];\n        \
    \    } else {\n                ret += T(1) << i;\n            }\n            now\
    \ = nxt;\n            assert(now != nullptr and now->count > 0);\n        }\n\
    \        return ret;\n    }\n    T get_kth_element(int k) { // \u5C0F\u3055\u3044\
    \u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024(0-indexed)\n        assert(0 <= k\
    \ and k < size());\n        Node *now = root;\n        T ret = 0;\n        for(int\
    \ i = LOG - 1; i >= 0; i--) {\n            int b = lazy_xor_value >> i & 1;\n\
    \            int small_count = (now->child[b] ? now->child[b]->count : 0);\n \
    \           int big_count = (now->child[b ^ 1] ? now->child[b ^ 1]->count : 0);\n\
    \            assert(0 < small_count + big_count);\n            assert(k < small_count\
    \ + big_count);\n            if(k >= small_count) {\n                ret += T(1)\
    \ << i;\n                now = now->child[b ^ 1];\n                k -= small_count;\n\
    \            } else {\n                now = now->child[b];\n            }\n \
    \       }\n        return ret;\n    }\n    int lower_bound(T val) {\n        int\
    \ ret = 0;\n        Node* now = root;\n        for(int i = LOG - 1; i >= 0; i--)\
    \ {\n            if(!now || now->count == 0) break;\n            int b = lazy_xor_value\
    \ >> i & 1;\n            int small_count = (now->child[b] ? now->child[b]->count\
    \ : 0);\n            if(val >> i & 1) {\n                ret += small_count;\n\
    \                now = now->child[b ^ 1];\n            } else {\n            \
    \    now = now->child[b];\n            }\n        }\n        return ret;\n   \
    \ }\n    int upper_bound(T val) {\n        return lower_bound(val) + count(val\
    \ ^ lazy_xor_value);\n    }\n    int size() const {\n        if(!root) return\
    \ 0;\n        return root->count;\n    }\n    inline bool empty() const { return\
    \ (!root or root->count == 0); }\n    void all_xor(T val) { lazy_xor_value ^=\
    \ val; }\n\n  private:\n    struct Node {\n        int count;\n        std::array<Node\
    \ *, 2> child;\n        Node() : count(0), child({nullptr, nullptr}) {}\n    };\n\
    \    Node *root;\n    T lazy_xor_value;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/data-structure/set-xor-min.test.cpp
  - test/mytest/data-structure/binary-trie.test.cpp
  - test/mytest/data-structure/bit-queries.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
title: Binary Trie
---

## このライブラリでできること

`BinaryTrie<T,LOG>` は、非負整数を二進表現の上位 bit から順に分岐させて保存する多重集合です。同じ値を複数個保持でき、最小値・最大値・小さい方から $k$ 番目の値を求められます。以下では $B=\mathrm{LOG}$、挿入回数を $Q$ とします。

各ノードに、その下にある要素数を記録しています。小さい方から $k$ 番目の要素を探すときは、$0$ 側にある個数を見て、どちらの枝へ進むかを決めます。1回の探索で調べる深さは $B$ なので、基本操作は $O(B)$ 時間です。

## 使い方

通常は符号なし整数型と、値を表すのに十分な bit 数を指定します。例では $3,5$ を挿入した後、`all_xor(2)` を呼びます。最小値の問い合わせから見る値は $3\mathbin{\mathrm{xor}}2=1$ と $5\mathbin{\mathrm{xor}}2=7$ になるため、答えは $1$ です。

ただし、この実装の XOR マスクは挿入・削除・個数取得には反映されません。マスクを $m$ とすると、問い合わせから見える値 $x$ を挿入するには `insert(x ^ m)` とする必要があります。マスクは呼び出し側でも管理してください。

```cpp
#include "template/template.cpp"
#include "data-structure/binary-trie.hpp"

int main() {
    BinaryTrie<unsigned int, 20> trie;
    trie.insert(3);
    trie.insert(5);
    assert(trie.get_kth_element(0) == 3);
    trie.all_xor(2);
    assert(trie.min_element() == 1);
}
```

## API・計算量

確保する空間の上界は $O(QB)$ です。削除してもノードは解放されません。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `BinaryTrie()` | 空の集合を作る。 | O(1) |
| `insert(val)` | 格納値 val を 1 個追加。 | O(B) |
| `erase(val)` | 格納値を 1 個削除。なければ false。 | O(B) |
| `count(val)` | 格納値の個数。 | O(B) |
| `min_element(), max_element()` | XOR 適用後の最小値・最大値。 | O(B) |
| `get_kth_element(k)` | XOR 適用後の昇順で k 番目（0-indexed）。 | O(B) |
| `all_xor(val)` | 読み出し用の XOR マスクを更新。 | O(1) |
| `size(), empty()` | 個数・空判定。 | O(1) |
| `lower_bound(val), upper_bound(val)` | XOR 適用後の値が val 未満 / val 以下の要素数。 | O(B) |

## 利用条件と実装上の注意

値と XOR マスクは $B$ bit に収めてください。最小値・最大値は非空のとき、`get_kth_element(k)` は $0\le k<\mathrm{size}()$ のときに使います。

`lower_bound/upper_bound` は空集合でも使え、その場合は0を返します。返り値は $[0,\mathrm{size}()]$ の順位で、全要素より大きい値を探すと size() になります。検索値は XOR 適用後の値として解釈します。

削除してもノードは解放されず、デストラクタによる解放もありません。また、オブジェクトのコピーは同じノードを共有するため、独立した集合の複製にはなりません。
