---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/pow_mod.hpp
    title: "\u5270\u4F59\u4ED8\u304D\u7D2F\u4E57"
  - icon: ':question:'
    path: math/primitive-root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':question:'
    path: modint/modint.hpp
    title: "\u56FA\u5B9A\u6CD5 modint"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/convolution/convolution-mod.test.cpp
    title: test/library-checker/convolution/convolution-mod.test.cpp
  - icon: ':x:'
    path: test/mytest/math/convolution-regressions.test.cpp
    title: test/mytest/math/convolution-regressions.test.cpp
  - icon: ':x:'
    path: test/mytest/math/transforms-api.test.cpp
    title: test/mytest/math/transforms-api.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/ntt.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <cstdint>\n#include <utility>\n#include <vector>\n\n#line\
    \ 2 \"modint/modint.hpp\"\n\n#include <istream>\n#include <ostream>\n#line 6 \"\
    modint/modint.hpp\"\n\ntemplate <int mod> class ModInt {\n  public:\n    ModInt()\
    \ : x(0) {}\n    ModInt(long long y)\n        : x(y >= 0 ? y % umod() : (umod()\
    \ - (-y) % umod()) % umod()) {}\n    unsigned int val() const { return x; }\n\
    \    ModInt &operator+=(const ModInt &p) {\n        if((x += p.x) >= umod()) x\
    \ -= umod();\n        return *this;\n    }\n    ModInt &operator-=(const ModInt\
    \ &p) {\n        if((x += umod() - p.x) >= umod()) x -= umod();\n        return\
    \ *this;\n    }\n    ModInt &operator*=(const ModInt &p) {\n        x = (unsigned\
    \ int)(1ULL * x * p.x % umod());\n        return *this;\n    }\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n    ModInt\
    \ operator-() const { return ModInt(-(long long)x); }\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {\n        long long a = x, b = mod,\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n       \
    \ }\n        return ModInt(u);\n    }\n    ModInt pow(unsigned long long n) const\
    \ {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n            if(n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, ModInt &a) {\n        long long t;\n        is\
    \ >> t;\n        a = ModInt<mod>(t);\n        return (is);\n    }\n    static\
    \ constexpr int get_mod() { return mod; }\n\n  private:\n    unsigned int x;\n\
    \    static constexpr unsigned int umod() { return mod; }\n};\n#line 2 \"math/primitive-root.hpp\"\
    \n\n#line 2 \"math/pow_mod.hpp\"\n\nconstexpr long long pow_mod(long long x, long\
    \ long k, long long m) {\n    long long res = 1 % m;\n    long long mul = (x >=\
    \ 0 ? x % m : x % m + m);\n    while(k) {\n        if(k & 1) res = (__int128_t)res\
    \ * mul % m;\n        mul = (__int128_t)mul * mul % m;\n        k >>= 1;\n   \
    \ }\n    return res;\n}\n#line 4 \"math/primitive-root.hpp\"\n\nconstexpr int\
    \ primitive_root(int p) {\n    if(p == 2) return 1;\n    if(p == 998244353) return\
    \ 3;\n    int primes[31] = {};\n    int sz = 0, t = p - 1;\n    for(int i = 2;\
    \ i * i <= t; i++) {\n        if(t % i == 0) {\n            primes[sz++] = i;\n\
    \            while(t % i == 0) t /= i;\n        }\n    }\n    if(t > 1) primes[sz++]\
    \ = t;\n    for(int g = 2;;g++) {\n        bool f = true;\n        for(int i =\
    \ 0; i < sz; i++) {\n            if(pow_mod(g, (p - 1) / primes[i], p) == 1) {\n\
    \                f = false;\n                break;\n            }\n        }\
    \   \n        if(f) return g;\n    }\n}\n#line 11 \"math/convolution/ntt.hpp\"\
    \n\nnamespace ntt {\n    constexpr int exp_limit(int mod) { return __builtin_ctz(mod\
    \ - 1); }\n\n    template <class mint, int mod = mint::get_mod(),\n          \
    \    int g = primitive_root(mod)>\n    struct ntt_info {\n        static constexpr\
    \ int limit = exp_limit(mod);\n        std::array<mint, limit + 1> root;\n   \
    \     std::array<mint, limit + 1> iroot;\n\n        ntt_info() {\n           \
    \ root[limit] = mint(g).pow((mod - 1) >> limit);\n            iroot[limit] = root[limit].inv();\n\
    \            for(int i = limit - 1; i >= 0; i--) {\n                root[i] =\
    \ root[i + 1] * root[i + 1];\n                iroot[i] = iroot[i + 1] * iroot[i\
    \ + 1];\n            }\n        }\n    };\n\n    inline uint64_t revbit(uint64_t\
    \ mask, int bitlen) {\n        assert(0 <= bitlen && bitlen <= 64);\n        if(bitlen\
    \ == 0) return 0;\n        uint64_t x = mask;\n        x = (x >> 32) | (x << 32);\n\
    \        x = ((x >> 16) & 0x0000FFFF0000FFFF) | ((x << 16) & 0xFFFF0000FFFF0000);\n\
    \        x = ((x >> 8) & 0x00FF00FF00FF00FF) | ((x << 8) & 0xFF00FF00FF00FF00);\n\
    \        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F) | ((x << 4) & 0xF0F0F0F0F0F0F0F0);\n\
    \        x = ((x >> 2) & 0x3333333333333333) | ((x << 2) & 0xCCCCCCCCCCCCCCCC);\n\
    \        x = ((x >> 1) & 0x5555555555555555) | ((x << 1) & 0xAAAAAAAAAAAAAAAA);\n\
    \        return (x >> (64 - bitlen));\n    }\n\n    inline uint64_t revbit(uint64_t\
    \ mask) {\n        return mask == 0 ? 0 : revbit(mask, 64 - __builtin_clzll(mask));\n\
    \    }\n\n    template<class mint>\n    void ntt(std::vector<mint>& a) {\n   \
    \     int n = (int)a.size();\n        assert(n > 0 && (n & (n - 1)) == 0);\n \
    \       int bitlen = __builtin_ctz(n);\n        static const ntt_info<mint> info;\n\
    \        assert(bitlen <= info.limit);\n        for(int len = n, b = bitlen; len\
    \ > 1; len >>= 1, b--) {\n            for(int i = 0; i < n; i += len) {\n    \
    \            int t = len >> 1;\n                mint wj = 1;\n               \
    \ for(int j = 0; j < t; j++) {\n                    int p = i + j;\n         \
    \           mint l = a[p] + a[p + t];\n                    mint r = (a[p] - a[p\
    \ + t]) * wj;\n                    a[p] = l, a[p + t] = r;\n                 \
    \   wj *= info.root[b];\n                }\n            }\n        }\n       \
    \ for(int i = 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n     \
    \       if(i < j) std::swap(a[i], a[j]);\n        }\n    }\n\n    template<class\
    \ mint>\n    void intt(std::vector<mint>& a) {\n        int n = (int)a.size();\n\
    \        assert(n > 0 && (n & (n - 1)) == 0);\n        int bitlen = __builtin_ctz(n);\n\
    \        static const ntt_info<mint> info;\n        assert(bitlen <= info.limit);\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n\
    \            if(i < j) std::swap(a[i], a[j]);\n        }\n        for(int len\
    \ = 2, b = 1; len <= n; len <<= 1, b++) {\n            for(int i = 0; i < n; i\
    \ += len) {\n                int t = len >> 1;\n                mint wj = 1;\n\
    \                for(int j = 0; j < t; j++) {\n                    int p = i +\
    \ j;\n                    auto l = a[p] + a[p + t] * wj;\n                   \
    \ auto r = a[p] - a[p + t] * wj;\n                    a[p] = l, a[p + t] = r;\n\
    \                    wj *= info.iroot[b];\n                }\n            }\n\
    \        }\n        mint invn = mint(n).inv();\n        for(int i = 0; i < n;\
    \ i++) a[i] *= invn;\n    }\n\n    template<class mint>\n    std::vector<mint>\
    \ convolution(std::vector<mint> a, std::vector<mint> b) {\n        if(a.empty()\
    \ || b.empty()) return {};\n        int m = (int)a.size() + (int)b.size() - 1;\n\
    \        int n = 1;\n        while(n < m) n <<= 1;\n        a.resize(n), b.resize(n);\n\
    \        ntt<mint>(a);\n        ntt<mint>(b);\n        for(int i = 0; i < n; i++)\
    \ a[i] *= b[i];\n        intt<mint>(a);\n        a.resize(m);\n        return\
    \ a;\n    }\n}; // namespace ntt\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <cstdint>\n\
    #include <utility>\n#include <vector>\n\n#include \"../../modint/modint.hpp\"\n\
    #include \"../primitive-root.hpp\"\n\nnamespace ntt {\n    constexpr int exp_limit(int\
    \ mod) { return __builtin_ctz(mod - 1); }\n\n    template <class mint, int mod\
    \ = mint::get_mod(),\n              int g = primitive_root(mod)>\n    struct ntt_info\
    \ {\n        static constexpr int limit = exp_limit(mod);\n        std::array<mint,\
    \ limit + 1> root;\n        std::array<mint, limit + 1> iroot;\n\n        ntt_info()\
    \ {\n            root[limit] = mint(g).pow((mod - 1) >> limit);\n            iroot[limit]\
    \ = root[limit].inv();\n            for(int i = limit - 1; i >= 0; i--) {\n  \
    \              root[i] = root[i + 1] * root[i + 1];\n                iroot[i]\
    \ = iroot[i + 1] * iroot[i + 1];\n            }\n        }\n    };\n\n    inline\
    \ uint64_t revbit(uint64_t mask, int bitlen) {\n        assert(0 <= bitlen &&\
    \ bitlen <= 64);\n        if(bitlen == 0) return 0;\n        uint64_t x = mask;\n\
    \        x = (x >> 32) | (x << 32);\n        x = ((x >> 16) & 0x0000FFFF0000FFFF)\
    \ | ((x << 16) & 0xFFFF0000FFFF0000);\n        x = ((x >> 8) & 0x00FF00FF00FF00FF)\
    \ | ((x << 8) & 0xFF00FF00FF00FF00);\n        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F)\
    \ | ((x << 4) & 0xF0F0F0F0F0F0F0F0);\n        x = ((x >> 2) & 0x3333333333333333)\
    \ | ((x << 2) & 0xCCCCCCCCCCCCCCCC);\n        x = ((x >> 1) & 0x5555555555555555)\
    \ | ((x << 1) & 0xAAAAAAAAAAAAAAAA);\n        return (x >> (64 - bitlen));\n \
    \   }\n\n    inline uint64_t revbit(uint64_t mask) {\n        return mask == 0\
    \ ? 0 : revbit(mask, 64 - __builtin_clzll(mask));\n    }\n\n    template<class\
    \ mint>\n    void ntt(std::vector<mint>& a) {\n        int n = (int)a.size();\n\
    \        assert(n > 0 && (n & (n - 1)) == 0);\n        int bitlen = __builtin_ctz(n);\n\
    \        static const ntt_info<mint> info;\n        assert(bitlen <= info.limit);\n\
    \        for(int len = n, b = bitlen; len > 1; len >>= 1, b--) {\n           \
    \ for(int i = 0; i < n; i += len) {\n                int t = len >> 1;\n     \
    \           mint wj = 1;\n                for(int j = 0; j < t; j++) {\n     \
    \               int p = i + j;\n                    mint l = a[p] + a[p + t];\n\
    \                    mint r = (a[p] - a[p + t]) * wj;\n                    a[p]\
    \ = l, a[p + t] = r;\n                    wj *= info.root[b];\n              \
    \  }\n            }\n        }\n        for(int i = 0; i < n; i++) {\n       \
    \     int j = revbit(i, bitlen);\n            if(i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n\n    template<class mint>\n    void intt(std::vector<mint>&\
    \ a) {\n        int n = (int)a.size();\n        assert(n > 0 && (n & (n - 1))\
    \ == 0);\n        int bitlen = __builtin_ctz(n);\n        static const ntt_info<mint>\
    \ info;\n        assert(bitlen <= info.limit);\n        for(int i = 0; i < n;\
    \ i++) {\n            int j = revbit(i, bitlen);\n            if(i < j) std::swap(a[i],\
    \ a[j]);\n        }\n        for(int len = 2, b = 1; len <= n; len <<= 1, b++)\
    \ {\n            for(int i = 0; i < n; i += len) {\n                int t = len\
    \ >> 1;\n                mint wj = 1;\n                for(int j = 0; j < t; j++)\
    \ {\n                    int p = i + j;\n                    auto l = a[p] + a[p\
    \ + t] * wj;\n                    auto r = a[p] - a[p + t] * wj;\n           \
    \         a[p] = l, a[p + t] = r;\n                    wj *= info.iroot[b];\n\
    \                }\n            }\n        }\n        mint invn = mint(n).inv();\n\
    \        for(int i = 0; i < n; i++) a[i] *= invn;\n    }\n\n    template<class\
    \ mint>\n    std::vector<mint> convolution(std::vector<mint> a, std::vector<mint>\
    \ b) {\n        if(a.empty() || b.empty()) return {};\n        int m = (int)a.size()\
    \ + (int)b.size() - 1;\n        int n = 1;\n        while(n < m) n <<= 1;\n  \
    \      a.resize(n), b.resize(n);\n        ntt<mint>(a);\n        ntt<mint>(b);\n\
    \        for(int i = 0; i < n; i++) a[i] *= b[i];\n        intt<mint>(a);\n  \
    \      a.resize(m);\n        return a;\n    }\n}; // namespace ntt\n"
  dependsOn:
  - modint/modint.hpp
  - math/primitive-root.hpp
  - math/pow_mod.hpp
  isVerificationFile: false
  path: math/convolution/ntt.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/convolution/convolution-mod.test.cpp
  - test/mytest/math/transforms-api.test.cpp
  - test/mytest/math/convolution-regressions.test.cpp
documentation_of: math/convolution/ntt.hpp
layout: document
title: "NTT \u306B\u3088\u308B\u7573\u307F\u8FBC\u307F"
---

## このライブラリでできること

`ntt` 名前空間は、素数を法とする数論変換（NTT）と畳み込みを提供します。複素数の代わりに有限体上の1の冪根を用いることで、浮動小数点の丸め誤差を伴わずに多項式の積を計算できます。

長さ n,m の列の畳み込みは $c_k=\sum_{i+j=k}a_i b_j$ です。係数はすべて modint の法 p で計算されます。

## 使い方

コンパイル時に法を取得できる modint の列を `convolution` に渡します。例では $(1+2x)(3+4x)=3+10x+8x^2$ の係数が得られます。

```cpp
#include <cassert>
#include <vector>
#include "math/convolution/ntt.hpp"

int main() {
    using mint = ModInt<998244353>;
    auto c = ntt::convolution(std::vector<mint>{1, 2}, std::vector<mint>{3, 4});
    assert(c == (std::vector<mint>{3, 10, 8}));
    assert(ntt::convolution(std::vector<mint>{}, c).empty());
}
```

正変換は $A_k=\sum_{j=0}^{N-1}a_j\omega^{jk}$ を添字 k の順に格納します。ここで N は変換長、$\omega=g^{(p-1)/N}$、g は primitive_root が求める原始根です。逆変換は逆根を用い、最後に N の逆元を掛けます。

## API・計算量

L を n+m-1 以上の最小の2冪とします。畳み込みの作業配列は $O(L)$、mint の型ごとに保持する根の表は $O(\log p)$ 空間です。正逆変換は配列をその場で更新し、根の表以外の追加空間は $O(1)$ です。modint の基本演算を定数時間とします。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `exp_limit(int mod)` | mod-1 の末尾の0 bit数。mod>1。 | O(1) |
| `ntt_info<mint>()` | 根 root、逆根 iroot、指数上限 limit を用意。 | 原始根取得後 O(log p) |
| `revbit(uint64_t mask)` | 有効 bit幅で反転。0には0。 | O(1) |
| `revbit(uint64_t mask, int bitlen)` | 下位 bitlen bitを反転。bitlen=0なら0。 | O(1) |
| `ntt(std::vector<mint>& a)` | 正変換で a を上書き。 | O(N log(N+1))、初回は根の構築を加算 |
| `intt(std::vector<mint>& a)` | 正規化した逆変換で a を上書き。 | O(N log(N+1)+log p)、初回は根の構築を加算 |
| `convolution(std::vector<mint> a, std::vector<mint> b)` | 畳み込み。片方でも空なら空。 | 非空時 O(L log(L+1)+log p)、入力コピー別 |

## 利用条件と実装上の注意

法 p は素数で、mint は定数式の get_mod() と四則演算・pow・inv を備える必要があります。原始根の計算コストは `primitive-root.hpp` に従います。既定のテンプレート引数としてコンパイル時に原始根を求めます。

直接変換する長さ N は正の2冪で、$N\mid(p-1)$ が必要です。畳み込みでも内部の長さ L がこの条件を満たす必要があり、$p=998244353$ なら $2^{23}$ までです。条件を満たさない長さは assert で検出します。

revbit の bitlen は0以上64以下です。1引数版は入力自身の有効幅を使うので、配列添字の並べ替えには固定幅を渡す2引数版を使います。空の畳み込みでも値渡しの入力コピーには O(n+m) 時間・空間がかかります。
