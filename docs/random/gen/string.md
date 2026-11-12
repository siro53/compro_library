---
title: ランダムな文字列
documentation_of: //random/gen/string.hpp
---

## このライブラリでできること

[`Random`](https://github.com/siro53/compro_library/blob/main/docs/random/gen/random.md) を使って、ランダムテスト用の文字列を生成します。`random_string` は指定した文字の集合から、`random_lowercase` は英小文字のうち先頭の $k$ 種類から、各文字を独立に一様に選びます。

文字列の問題では、文字の種類が少ないほど同じ部分文字列や周期が現れやすく、境界の処理のバグが見つかりやすくなります。`random_lowercase(rng, n, 2)` のように種類を絞って使うのがおすすめです。

## 使い方

例では、`a` と `b` だけからなる長さ $8$ の文字列と、`0` と `1` からなる長さ $5$ の文字列を作ります。

```cpp
#include "template/template.cpp"
#include "random/gen/string.hpp"

int main(int argc, char **argv) {
    Random rng(argc, argv);
    string s = random_lowercase(rng, 8, 2);
    assert(s.size() == 8 && s.find_first_not_of("ab") == string::npos);
    string t = random_string(rng, 5, "01");
    assert(t.find_first_not_of("01") == string::npos);
    print(s);
    print(t);
}
```

## API・計算量

生成する文字列の長さを $n$ とします。返り値の文字列のために $O(n)$ の領域を使います。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `random_string(rng, n, alphabet)` | 各文字を `alphabet` から一様に選んだ長さ $n$ の `string`。 | 期待 $O(n)$ |
| `random_lowercase(rng, n, k = 26)` | 各文字を `'a'` から始まる $k$ 種類の英小文字から一様に選んだ長さ $n$ の `string`。 | 期待 $O(n+k)$ |

## 利用条件と実装上の注意

- $n \ge 0$ を要求します。$n=0$ なら空文字列を返します。
- `random_string` は、$n>0$ のとき `alphabet` が空でないことを要求します。`alphabet` に同じ文字が複数回現れると、その文字は回数に比例して選ばれやすくなります。
- `random_lowercase` は $1 \le k \le 26$ を要求します。
- 条件を満たさない場合は `assert` で停止します。
