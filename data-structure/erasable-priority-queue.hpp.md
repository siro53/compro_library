---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/data-structure/erasable-priority-queue.test.cpp
    title: test/mytest/data-structure/erasable-priority-queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/erasable-priority-queue.hpp\"\n\n#include\
    \ <cassert>\n#include <functional>\n#include <type_traits>\n#include <queue>\n\
    #include <vector>\n\ntemplate<class T, bool isAscending = true>\nstruct ErasablePriorityQueue\
    \ {\n    using PQ = std::conditional_t<\n        isAscending,\n        std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>,\n        std::priority_queue<T>\n    >;\n\
    \    PQ que, rm_que;\n\n    ErasablePriorityQueue() = default;\n\n    void push(const\
    \ T& val) {\n        que.emplace(val);\n    }\n\n    T top() {\n        normalize();\n\
    \        assert(!que.empty());\n        return que.top();\n    }\n\n    void pop()\
    \ {\n        normalize();\n        assert(!que.empty());\n        que.pop();\n\
    \    }\n\n    void erase(const T& val) {\n        rm_que.emplace(val);\n    }\n\
    \n    bool empty() {\n        return que.empty();\n    }\nprivate:\n    void normalize()\
    \ {\n        while(!que.empty() and !rm_que.empty() and que.top() == rm_que.top())\
    \ {\n            que.pop();\n            rm_que.pop();\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <queue>\n#include <vector>\n\ntemplate<class T, bool isAscending = true>\n\
    struct ErasablePriorityQueue {\n    using PQ = std::conditional_t<\n        isAscending,\n\
    \        std::priority_queue<T, std::vector<T>, std::greater<T>>,\n        std::priority_queue<T>\n\
    \    >;\n    PQ que, rm_que;\n\n    ErasablePriorityQueue() = default;\n\n   \
    \ void push(const T& val) {\n        que.emplace(val);\n    }\n\n    T top() {\n\
    \        normalize();\n        assert(!que.empty());\n        return que.top();\n\
    \    }\n\n    void pop() {\n        normalize();\n        assert(!que.empty());\n\
    \        que.pop();\n    }\n\n    void erase(const T& val) {\n        rm_que.emplace(val);\n\
    \    }\n\n    bool empty() {\n        return que.empty();\n    }\nprivate:\n \
    \   void normalize() {\n        while(!que.empty() and !rm_que.empty() and que.top()\
    \ == rm_que.top()) {\n            que.pop();\n            rm_que.pop();\n    \
    \    }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/erasable-priority-queue.hpp
  requiredBy: []
  timestamp: '2026-01-12 01:17:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/data-structure/erasable-priority-queue.test.cpp
documentation_of: data-structure/erasable-priority-queue.hpp
layout: document
title: "\u524A\u9664\u53EF\u80FD priority queue"
---

priority_queue を 2 つ持ち、片方に削除待ちの要素を入れて削除を遅延評価することで実質的に削除も出来るようにした priority_queue。

queue に存在しない要素を削除しようとするとバグるので注意

- `push(val)`
  - 値 `val` を優先度付きキューに push する
- `top()`
  - キューの先頭の値を返す
- `pop()`
  - キューの先頭の値を pop する（削除する）
- `erase(val)`
  - 値 `val` を削除する
  - ただしキューの中に値 `val` が存在する場合のみ使える。キューの中に値 `val` が存在するかどうかのチェックはやっていないので注意
- `empty()`
  - キューが空かどうかの boolean を返す