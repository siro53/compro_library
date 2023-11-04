---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
  bundledCode: "#line 2 \"data-structure/slope-trick.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <vector>\n#include <utility>\n\n// ref: https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    template <typename T> struct SlopeTrick {\n    const T inf = std::numeric_limits<T>::max()\
    \ / 3;\n\n    T min_f, add_L, add_R;\n    std::priority_queue<T> L;\n    std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> R;\n\n  private:\n    void push_L(T a) { L.push(a\
    \ - add_L); }\n    T top_L() {\n        if(L.empty()) return -inf;\n        return\
    \ L.top() + add_L;\n    }\n    T pop_L() {\n        T ret = top_L();\n       \
    \ if(!L.empty()) L.pop();\n        return ret;\n    }\n    void push_R(T a) {\
    \ R.push(a - add_R); }\n    T top_R() {\n        if(R.empty()) return inf;\n \
    \       return R.top() + add_R;\n    }\n    T pop_R() {\n        T ret = top_R();\n\
    \        if(!R.empty()) R.pop();\n        return ret;\n    }\n\n  public:\n  \
    \  SlopeTrick() : min_f(0), add_L(0), add_R(0) {}\n    T get_min() const { return\
    \ min_f; }\n    std::tuple<T, T, T> get_min_lr() const { return {min_f, top_L(),\
    \ top_R()}; }\n    // \u5B9A\u6570\u95A2\u6570 f(x) = a \u3092\u8FFD\u52A0\n \
    \   void add_const(T a) { min_f += a; }\n    // f(x) = (x - a)+ \u3092\u8FFD\u52A0\
    \n    void add_right(T a) {\n        min_f += std::max(top_L() - a, T(0));\n \
    \       push_L(a);\n        T t = pop_L();\n        push_R(t);\n    }\n    //\
    \ f(x) = (a - x)+ \u3092\u8FFD\u52A0\n    void add_left(T a) {\n        min_f\
    \ += std::max(a - top_R(), T(0));\n        push_R(a);\n        T t = pop_R();\n\
    \        push_L(t);\n    }\n    // f(x) = |x - a| = (x - a)+ + (a - x)+ \u3092\
    \u8FFD\u52A0\n    void add_abs(T a) {\n        add_left(a);\n        add_right(a);\n\
    \    }\n    // (\u5DE6\u5074)\u7D2F\u7A4Dmin\n    // g(x) := min_{y <= x} f(y)\
    \ \u306A\u308B g \u306B\u5909\u66F4\n    void clear_right() {\n        while(!R.empty())\
    \ R.pop();\n    }\n    // (\u53F3\u5074)\u7D2F\u7A4Dmin\n    // g(x) := min_{y\
    \ >= x} f(y) \u306A\u308B g \u306B\u5909\u66F4\n    void clear_left() {\n    \
    \    while(!L.empty()) L.pop();\n    }\n    // \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\
    \u5024\u95A2\u6570\n    // g(x) := min_{x - b <= y <= x - a} f(y) (a <= b) \u306A\
    \u308B g \u306B\u5909\u66F4\n    void shift(T a, T b) {\n        assert(a <= b);\n\
    \        add_L += a;\n        add_R += b;\n    }\n    // \u5E73\u884C\u79FB\u52D5\
    \n    // g(x) := f(x - a) \u306A\u308B g \u306B\u5909\u66F4\n    void shift(T\
    \ a) { shift(a, a); }\n    size_t size() const { return L.size() + R.size(); }\n\
    \    void swap(SlopeTrick& rhs) {\n        std::swap(min_f, rhs.min_f);\n    \
    \    std::swap(add_L, rhs.add_L);\n        std::swap(add_R, rhs.add_R);\n    \
    \    std::swap(L, rhs.L);\n        std::swap(R, rhs.R);\n    }\n    void merge(SlopeTrick&\
    \ rhs) {\n        if(size() < rhs.size()) swap(rhs);\n        while(!rhs.L.empty())\
    \ add_left(rhs.pop_L());\n        while(!rhs.R.empty()) add_right(rhs.pop_R());\n\
    \        min_f += rhs.min_f;\n    }\n    // L, R \u306F\u7A7A\u306B\u306A\u308B\
    \n    T eval(T x) {\n        T ret = min_f;\n        while(!L.empty()) ret +=\
    \ max(T(0), pop_L() - x);\n        while(!R.empty()) ret += max(T(0), x - pop_R());\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <tuple>\n#include <vector>\n#include\
    \ <utility>\n\n// ref: https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    template <typename T> struct SlopeTrick {\n    const T inf = std::numeric_limits<T>::max()\
    \ / 3;\n\n    T min_f, add_L, add_R;\n    std::priority_queue<T> L;\n    std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> R;\n\n  private:\n    void push_L(T a) { L.push(a\
    \ - add_L); }\n    T top_L() {\n        if(L.empty()) return -inf;\n        return\
    \ L.top() + add_L;\n    }\n    T pop_L() {\n        T ret = top_L();\n       \
    \ if(!L.empty()) L.pop();\n        return ret;\n    }\n    void push_R(T a) {\
    \ R.push(a - add_R); }\n    T top_R() {\n        if(R.empty()) return inf;\n \
    \       return R.top() + add_R;\n    }\n    T pop_R() {\n        T ret = top_R();\n\
    \        if(!R.empty()) R.pop();\n        return ret;\n    }\n\n  public:\n  \
    \  SlopeTrick() : min_f(0), add_L(0), add_R(0) {}\n    T get_min() const { return\
    \ min_f; }\n    std::tuple<T, T, T> get_min_lr() const { return {min_f, top_L(),\
    \ top_R()}; }\n    // \u5B9A\u6570\u95A2\u6570 f(x) = a \u3092\u8FFD\u52A0\n \
    \   void add_const(T a) { min_f += a; }\n    // f(x) = (x - a)+ \u3092\u8FFD\u52A0\
    \n    void add_right(T a) {\n        min_f += std::max(top_L() - a, T(0));\n \
    \       push_L(a);\n        T t = pop_L();\n        push_R(t);\n    }\n    //\
    \ f(x) = (a - x)+ \u3092\u8FFD\u52A0\n    void add_left(T a) {\n        min_f\
    \ += std::max(a - top_R(), T(0));\n        push_R(a);\n        T t = pop_R();\n\
    \        push_L(t);\n    }\n    // f(x) = |x - a| = (x - a)+ + (a - x)+ \u3092\
    \u8FFD\u52A0\n    void add_abs(T a) {\n        add_left(a);\n        add_right(a);\n\
    \    }\n    // (\u5DE6\u5074)\u7D2F\u7A4Dmin\n    // g(x) := min_{y <= x} f(y)\
    \ \u306A\u308B g \u306B\u5909\u66F4\n    void clear_right() {\n        while(!R.empty())\
    \ R.pop();\n    }\n    // (\u53F3\u5074)\u7D2F\u7A4Dmin\n    // g(x) := min_{y\
    \ >= x} f(y) \u306A\u308B g \u306B\u5909\u66F4\n    void clear_left() {\n    \
    \    while(!L.empty()) L.pop();\n    }\n    // \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\
    \u5024\u95A2\u6570\n    // g(x) := min_{x - b <= y <= x - a} f(y) (a <= b) \u306A\
    \u308B g \u306B\u5909\u66F4\n    void shift(T a, T b) {\n        assert(a <= b);\n\
    \        add_L += a;\n        add_R += b;\n    }\n    // \u5E73\u884C\u79FB\u52D5\
    \n    // g(x) := f(x - a) \u306A\u308B g \u306B\u5909\u66F4\n    void shift(T\
    \ a) { shift(a, a); }\n    size_t size() const { return L.size() + R.size(); }\n\
    \    void swap(SlopeTrick& rhs) {\n        std::swap(min_f, rhs.min_f);\n    \
    \    std::swap(add_L, rhs.add_L);\n        std::swap(add_R, rhs.add_R);\n    \
    \    std::swap(L, rhs.L);\n        std::swap(R, rhs.R);\n    }\n    void merge(SlopeTrick&\
    \ rhs) {\n        if(size() < rhs.size()) swap(rhs);\n        while(!rhs.L.empty())\
    \ add_left(rhs.pop_L());\n        while(!rhs.R.empty()) add_right(rhs.pop_R());\n\
    \        min_f += rhs.min_f;\n    }\n    // L, R \u306F\u7A7A\u306B\u306A\u308B\
    \n    T eval(T x) {\n        T ret = min_f;\n        while(!L.empty()) ret +=\
    \ max(T(0), pop_L() - x);\n        while(!R.empty()) ret += max(T(0), x - pop_R());\n\
    \        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slope-trick.hpp
  requiredBy: []
  timestamp: '2023-11-04 18:25:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/slope-trick.hpp
layout: document
title: Slope Trick
---

## 概要

傾きが整数である区分線形凸関数 $f(x)$ を管理するデータ構造。

詳しい内容は Link を参照。

- `get_min()` : $f(x)$ の最小値を返す。$O(1)$
- `get_min_lr()` : $f(x)$ の最小値及び、最小値を取る値域 $[l_0, r_0]$ を返す。$O(1)$
- `add_const(T a)` : 定数関数 $f(x) = a$ を追加する。$O(1)$
- `add_right(T a)` : $f(x)$ に関数 $\max(x - a, 0)$ を追加する。$O(\log N)$
- `add_left(T a)` : $f(x)$ に関数 $\max(a - x, 0)$ を追加する。$O(\log N)$
- `add_abs(T a)` : $f(x)$ に関数 $|x-a|$ を追加する。$O(\log N)$
- `clear_right()` : $f(x)$ を $g(x) = \min_{y \leq x} f(y)$ に変更する。$O(1)$
- `clear_left()` : $f(x)$ を $g(x) = \min_{y \geq x} f(y)$ に変更する。$O(1)$
- `shift(T a, T b)` : $f(x)$ を $g(x) = \min_{x - b \leq y \leq x - a} f(y)$ に変更する。ただし $a \leq b$ が条件。$O(1)$
- `shift(T a)` : $f(x)$ を $g(x) = f(x - a)$ に変更する。$O(1)$
- `merge(SlopeTrick& g)` : $f$ に $g$ を加える。$g$ は空になる。
- `eval(T x)` : $f(x)$ を計算する。計算後、中身は空になる。
