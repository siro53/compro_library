---
title: Rolling Hash
documentation_of: //string/rolling-hash.hpp
link: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
---

## このライブラリでできること

`RollingHash` は、文字列や整数列の部分列を短いハッシュ値に変換します。長さ $N$ の列を $O(N)$ 時間で前処理すると、任意の連続部分列のハッシュを $O(1)$ 時間で取得できます。部分文字列の比較を何度も行う場合に使えます。

底を $b$、法を $m=2^{61}-1$ とし、$H(A)=\sum_{i=0}^{n-1}A_i b^{n-1-i}\pmod m$ として列を表します。先頭からのハッシュと底の累乗を持っておけば、不要な先頭部分を引くことで区間の値を取り出せます。

## 使い方

比較する列では、例のように同じ `base` を渡して構築してください。`get(l,r)` は半開区間 $[l,r)$ のハッシュです。`ababa` の区間 $[0,3)$ と $[2,5)$ はどちらも `aba` なので同じ値になります。

`get_lcp` はハッシュ比較を使った二分探索で最長共通接頭辞の長さを調べます。例の `ababa` と `ababx` は最初の4文字が同じなので、結果は $4$ です。`connect(h1,h2,len2)` は後ろに連結する列の長さを使い、$h_1b^{\mathrm{len2}}+h_2$ を計算します。

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

## API・計算量

必要な空間は $O(N)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `RollingHash(s,base), RollingHash(vector<int>,base)` | ハッシュ・累乗表を構築。 | O(N) |
| `gen_base()` | ランダムな底を返す static 関数。 | 固定長の乱数生成（期待 O(1)） |
| `get(l,r)` | [l,r) のハッシュ。空列は 0。 | O(1) |
| `connect(h1,h2,h2len)` | h1 の列の後ろに長さ h2len の h2 を連結。 | O(1) |
| `get_lcp(b,l1,r1,l2,r2)` | 自身の [l1,r1) と b の [l2,r2) の LCP 長。 | O(log(min(r1-l1,r2-l2)+1)) |

## 利用条件と実装上の注意

ハッシュが一致しても、元の列が等しいとは限りません。異なる長さの列を比較する場合は長さも確認してください。ハッシュ衝突の可能性を許容できない用途では、必要に応じて実際の列も比較します。

比較・連結する列は、底だけでなく文字や整数の符号化もそろえてください。`get_lcp` は底の一致を検査しません。`connect` に渡す長さは、そのオブジェクトの累乗表の範囲 $[0,N]$ に収めます。

公開メンバ `hashed,power` は前計算表、`base` は底、`mint` は剰余型です。これらの表を直接変更すると区間取得との整合性が失われます。
