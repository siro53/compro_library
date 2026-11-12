---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/arithmetic-regressions.test.cpp
    title: test/mytest/math/arithmetic-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/matrix-binom.test.cpp
    title: test/mytest/math/matrix-binom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki117.test.cpp
    title: test/yukicoder/yuki117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binom.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class mint> class Binomial {\n  public:\n    explicit\
    \ Binomial(): Binomial(1) {}\n    explicit Binomial(int MAX) : f(MAX, mint(1)),\
    \ f_inv(MAX, mint(1)) {\n        for(int i = 1; i < MAX; i++) f[i] = f[i-1] *\
    \ mint(i);\n        f_inv[MAX - 1] = f[MAX - 1].inv();\n        for(int i = MAX\
    \ - 2; i >= 1; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i + 1);\n  \
    \      } \n    }\n    void extend() {\n        int n = (int)f.size();\n      \
    \  f.resize(n * 2);\n        f_inv.resize(n * 2);\n        for(int i = n; i <\
    \ n * 2; i++) f[i] = f[i - 1] * mint(i);\n        f_inv[n * 2 - 1] = f[n * 2 -\
    \ 1].inv();\n        for(int i = n * 2 - 2; i >= n; i--) {\n            f_inv[i]\
    \ = f_inv[i + 1] * mint(i + 1);\n        }\n    }\n    mint fac(int n) {\n   \
    \     if(n < 0) return mint(0);\n        while(n >= (int)f.size()) extend();\n\
    \        return f[n];\n    }\n    mint fac_inv(int n) {\n        if(n < 0) return\
    \ mint(0);\n        while(n >= (int)f_inv.size()) extend();\n        return f_inv[n];\n\
    \    }\n    mint inv(int n) {\n        if(n < 0) return mint(n).inv();\n     \
    \   assert(n != 0);\n        while(n >= (int)f_inv.size()) extend();\n       \
    \ return (f_inv[n] * f[n - 1]);\n    }\n    mint binom(int n, int k) {\n     \
    \   if(n < k || n < 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(k)\
    \ * fac_inv(n - k));\n    }\n    mint binom_naive(long long n, long long k) {\n\
    \        if(n < k || n < 0 || k < 0) return mint(0);\n        mint res(1);\n \
    \       k = std::min(k, n - k);\n        for(int i = 0; i < k; i++) res *= inv(i\
    \ + 1) * mint(n - i);\n        return res;\n    }\n    mint perm(int n, int k)\
    \ {\n        if(n < k || n < 0 || k < 0) return mint(0);\n        return (fac(n)\
    \ * fac_inv(n - k));\n    }\n    mint hom(int n, int k) {\n        if(n < 0 ||\
    \ k < 0) return mint(0);\n        return (k == 0 ? mint(1) : binom(n + k - 1,\
    \ k));\n    }\n\n  private:\n    std::vector<mint> f, f_inv;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class mint> class Binomial {\n  public:\n    explicit Binomial():\
    \ Binomial(1) {}\n    explicit Binomial(int MAX) : f(MAX, mint(1)), f_inv(MAX,\
    \ mint(1)) {\n        for(int i = 1; i < MAX; i++) f[i] = f[i-1] * mint(i);\n\
    \        f_inv[MAX - 1] = f[MAX - 1].inv();\n        for(int i = MAX - 2; i >=\
    \ 1; i--) {\n            f_inv[i] = f_inv[i + 1] * mint(i + 1);\n        } \n\
    \    }\n    void extend() {\n        int n = (int)f.size();\n        f.resize(n\
    \ * 2);\n        f_inv.resize(n * 2);\n        for(int i = n; i < n * 2; i++)\
    \ f[i] = f[i - 1] * mint(i);\n        f_inv[n * 2 - 1] = f[n * 2 - 1].inv();\n\
    \        for(int i = n * 2 - 2; i >= n; i--) {\n            f_inv[i] = f_inv[i\
    \ + 1] * mint(i + 1);\n        }\n    }\n    mint fac(int n) {\n        if(n <\
    \ 0) return mint(0);\n        while(n >= (int)f.size()) extend();\n        return\
    \ f[n];\n    }\n    mint fac_inv(int n) {\n        if(n < 0) return mint(0);\n\
    \        while(n >= (int)f_inv.size()) extend();\n        return f_inv[n];\n \
    \   }\n    mint inv(int n) {\n        if(n < 0) return mint(n).inv();\n      \
    \  assert(n != 0);\n        while(n >= (int)f_inv.size()) extend();\n        return\
    \ (f_inv[n] * f[n - 1]);\n    }\n    mint binom(int n, int k) {\n        if(n\
    \ < k || n < 0 || k < 0) return mint(0);\n        return (fac(n) * fac_inv(k)\
    \ * fac_inv(n - k));\n    }\n    mint binom_naive(long long n, long long k) {\n\
    \        if(n < k || n < 0 || k < 0) return mint(0);\n        mint res(1);\n \
    \       k = std::min(k, n - k);\n        for(int i = 0; i < k; i++) res *= inv(i\
    \ + 1) * mint(n - i);\n        return res;\n    }\n    mint perm(int n, int k)\
    \ {\n        if(n < k || n < 0 || k < 0) return mint(0);\n        return (fac(n)\
    \ * fac_inv(n - k));\n    }\n    mint hom(int n, int k) {\n        if(n < 0 ||\
    \ k < 0) return mint(0);\n        return (k == 0 ? mint(1) : binom(n + k - 1,\
    \ k));\n    }\n\n  private:\n    std::vector<mint> f, f_inv;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/binom.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/math/arithmetic-regressions.test.cpp
  - test/mytest/math/matrix-binom.test.cpp
  - test/yukicoder/yuki117.test.cpp
documentation_of: math/binom.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570"
---

## このライブラリでできること

`Binomial<mint>` は、剰余上の組合せ・順列・重複組合せを繰り返し求めるクラスです。階乗とその逆元を前計算し、$\binom nk=n!/(k!(n-k)!)$ を定数回の乗算で求めます。割り算は通常の整数除算ではなく、剰余上の逆元との乗算です。

表に含まれる範囲なら、二項係数や順列数を1回 $O(1)$ 時間で取得できます。足りない場合は表の長さを倍増します。以下では現在の表サイズを $K$、mintの逆元計算時間を $I$ とします。

## 使い方

素数法の modint 型を指定し、必要な階乗表の長さを渡します。`Binomial(100)` は $0!$ から $99!$ までを準備します。例の `binom(5,2)` は5個から2個を選ぶ方法の数 $10$、`hom(3,2)` は3種類から重複を許して2個選ぶ方法の数 $6$ です。

$n$ が大きく $k$ が小さい場合には、`binom_naive(n,k)` が積の公式を使います。これは表全体を $n$ まで伸ばす代わりに、$\min(k,n-k)$ 回の積で求める方法です。

```cpp
#include "template/template.cpp"
#include "math/binom.hpp"
#include "modint/modint.hpp"

int main() {
    using mint = ModInt<998244353>;
    Binomial<mint> comb(100);
    assert(comb.binom(5, 2).val() == 10);
    assert(comb.hom(3, 2).val() == 6);
}
```

## API・計算量

表の保持に $O(K)$ の空間を使います。mintの加算・乗算などの基本演算は定数時間としています。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Binomial(MAX=1)` | 0..MAX-1 の階乗・逆階乗を構築。 | O(MAX+I) |
| `extend()` | 表の長さを倍にする。 | O(K+I) |
| `fac(n), fac_inv(n)` | n! とその逆元。n<0 は 0。 | 表内 O(1)、拡張時 O(n+I log(n+2)) 上界 |
| `inv(n)` | 非零の n の逆元。負数は mint(n).inv() で直接計算。 | 正数: 表内 O(1)、拡張コスト別。負数: O(I) |
| `binom(n, k)` | nCk。不正な n,k は 0。 | 表内 O(1)、拡張コスト別 |
| `perm(n, k)` | nPk。不正な n,k は 0。 | 表内 O(1)、拡張コスト別 |
| `hom(n, k)` | n 種から k 個選ぶ重複組合せ。k=0 は 1。 | 表内 O(1)、拡張コスト別 |
| `binom_naive(n, k)` | long long の n,k に積の公式を使う。 | O(min(k,n-k)) + 表拡張コスト |

## 利用条件と実装上の注意

初期表サイズは1以上にしてください。また、表に現れる階乗がすべて可逆である必要があります。法が素数 $p$ なら、表の最大添字を $p$ 未満に保ちます。自動倍増は問い合わせた添字より先まで表を作るため、必要な添字だけが $p$ 未満でも十分ではありません。

`inv(0)` は利用できません。負数は mint(n) が可逆であれば逆元を取得できます。この場合、階乗表を拡張せず mint の inv() を呼びます。`binom_naive` のループ変数は int なので、$\min(k,n-k)$ もその範囲に収めます。表の「拡張コスト別」は、呼び出し中に必要になった前計算の時間が追加されることを意味します。
