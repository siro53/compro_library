---
title: Rolling Hash
documentation_of: //string/rolling-hash.hpp
link: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
---

## 概要

`RollingHash` は文字列または整数列の部分列ハッシュを法 2^61-1 で保持する。`base` は底、`hashed` は prefix hash、`power` は底の累乗表、mint は ModInt_2_61。N は列の長さ。

空間 O(N)。

## API・計算量

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RollingHash(s,base), RollingHash(vector<int>,base)` | ハッシュ・累乗表を構築。 | O(N) |
| `gen_base()` | ランダムな底を返す static 関数。 | 固定長の乱数生成（期待 O(1)） |
| `get(l,r)` | [l,r) のハッシュ。空列は 0。 | O(1) |
| `connect(h1,h2,h2len)` | h1 の列の後ろに長さ h2len の h2 を連結。 | O(1) |
| `get_lcp(b,l1,r1,l2,r2)` | 自身の [l1,r1) と b の [l2,r2) の LCP 長。 | O(log(min(r1-l1,r2-l2)+1)) |

## 前提・注意点

比較・連結するハッシュは必ず同じ base と符号化を使う。get_lcp は base の一致を検査しない。connect の h2len は自身の累乗表の範囲内（0..N）。ハッシュ衝突はあり得るため等値判定は確率的。異なる長さの列を比較する際は長さも確認する。

## 使用例

```cpp
#include "template/template.cpp"
#include "string/rolling-hash.hpp"

int main() {
    auto base = RollingHash::gen_base();
    RollingHash a(string("ababa"), base), b(string("ababx"), base);
    assert(a.get(0, 3) == a.get(2, 5));
    assert(a.get_lcp(b, 0, 5, 0, 5) == 4);
}
```
