---
title: Slope Trick
documentation_of: //data-structure/slope-trick.hpp
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
