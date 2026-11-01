---
title: 有理数
documentation_of: //misc/fraction.hpp
---

## 概要

`Fraction<Int=long long>` は分子 a、分母 b を公開メンバに持つ有理数。演算ごとに約分し分母を正にする。M は約分前の分子・分母の最大絶対値+1。

空間 O(1)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Fraction(), Fraction(a), Fraction(a,b)` | 0、整数、約分した分数を作る。 | O(1)、O(1)、O(log M) |
| `normalize()` | 約分し分母の符号を正にする。 | O(log M) |
| `operator+, -, *, / と複合代入` | 四則演算して約分。 | O(log M) |
| `単項 operator-` | 符号反転して約分。 | O(log M) |
| `operator==, !=, <, <=, >, >=` | 交差積による大小比較。 | O(1) |
| `gcd(a,b)` | 絶対値の gcd を求める static 補助関数。 | O(log M) |

## 前提・注意点

分母は非零、除算の右辺も非零。gcd の第 2 引数 0 は剰余演算で失敗する。中間積・和・絶対値が Int の範囲に収まること。演算前の約分によるオーバーフロー回避は行わない。public な a,b を変更したら normalize が必要。

## 使用例

```cpp
#include "template/template.cpp"
#include "misc/fraction.hpp"

int main() {
    Fraction<> a(1, 3), b(1, 6);
    auto c = a + b;
    assert(c.a == 1 && c.b == 2);
}
```
