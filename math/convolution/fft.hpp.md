---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/convolution-regressions.test.cpp
    title: test/mytest/math/convolution-regressions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/math/transforms-api.test.cpp
    title: test/mytest/math/transforms-api.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki440.test.cpp
    title: test/yukicoder/yuki440.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution/fft.hpp\"\n\n#include <cassert>\n#include\
    \ <cmath>\n#include <vector>\n#include <utility>\n\nnamespace fft {\n    template\
    \ <typename D> struct Complex {\n        D x, y;\n        Complex(): x(0), y(0)\
    \ {};\n        Complex(D x, D y) : x(x), y(y) {}\n        Complex &operator+=(const\
    \ Complex &c) {\n            x += c.x;\n            y += c.y;\n            return\
    \ (*this);\n        }\n        Complex &operator-=(const Complex &c) {\n     \
    \       x -= c.x;\n            y -= c.y;\n            return (*this);\n      \
    \  }\n        Complex &operator*=(const Complex &c) {\n            D nx = x *\
    \ c.x - y * c.y;\n            D ny = x * c.y + y * c.x;\n            x = nx, y\
    \ = ny;\n            return (*this);\n        }\n        Complex &operator/=(const\
    \ Complex& c) {\n            D nx = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y);\n\
    \            D ny = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);\n         \
    \   x = nx, y = ny;\n            return (*this);\n        }\n        Complex operator-()\
    \ const { return Complex(-x, -y); }\n        Complex operator+(const Complex &c)\
    \ const { return Complex(*this) += c; }\n        Complex operator-(const Complex\
    \ &c) const { return Complex(*this) -= c; }\n        Complex operator*(const Complex\
    \ &c) const { return Complex(*this) *= c; }\n        Complex operator/(const Complex\
    \ &c) const { return Complex(*this) /= c; }\n    };\n\n    template<typename D>\n\
    \    constexpr const D PI = std::acos(D(-1));\n\n    template<typename D>\n  \
    \  inline Complex<D> omega(int k, int n) {\n        return Complex<D>(std::cos(D(k)\
    \ * 2 * PI<D> / n), std::sin(D(k) * 2 * PI<D> / n));\n    }\n\n    inline int\
    \ revbit(int mask, int bitlen) {\n        int res = 0;\n        while(bitlen--)\
    \ {\n            res = (res << 1) | (mask & 1);\n            mask >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    template<typename D>\n    void fft(std::vector<Complex<D>>&\
    \ a, int bitlen) {\n        int n = (int)a.size();\n        int len = n;\n   \
    \     while(len > 1) {\n            for(int i = 0; i < n; i += len) {\n      \
    \          int t = len >> 1;\n                for(int j = 0; j < t; j++) {\n \
    \                   int p = i + j;\n                    auto l = a[p] + a[p +\
    \ t];\n                    auto r = (a[p] - a[p + t]) * omega<D>(j, len);\n  \
    \                  a[p] = l;\n                    a[p + t] = r;\n            \
    \    }\n            }\n            len >>= 1;\n        }\n        for(int i =\
    \ 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n            if(i <\
    \ j) std::swap(a[i], a[j]);\n        }\n    }\n\n    template<typename D>\n  \
    \  void ifft(std::vector<Complex<D>>& a, int bitlen) {\n        int n = (int)a.size();\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n\
    \            if(i < j) std::swap(a[i], a[j]);\n        }\n        int len = 2;\n\
    \        while(len <= n) {\n            for(int i = 0; i < n; i += len) {\n  \
    \              int t = len >> 1;\n                for(int j = 0; j < t; j++) {\n\
    \                    int p = i + j;\n                    auto l = a[p] + a[p +\
    \ t] * omega<D>(-j, len);\n                    auto r = a[p] - a[p + t] * omega<D>(-j,\
    \ len);\n                    a[p] = l;\n                    a[p + t] = r;\n  \
    \              }\n            }\n            len <<= 1;\n        }\n        for(int\
    \ i = 0; i < n; i++) a[i] /= Complex<D>(n, 0);\n    }\n\n    template<typename\
    \ D>\n    std::vector<D> convolution(const std::vector<D>& a, const std::vector<D>&\
    \ b) {\n        if(a.empty() || b.empty()) return {};\n        int m = (int)a.size()\
    \ + (int)b.size() - 1;\n        int n = 1, bitlen = 0;\n        while(n < m) {\n\
    \            n <<= 1;\n            bitlen++;\n        }\n        std::vector<Complex<D>>\
    \ A(n), B(n);\n        for(int i = 0; i < (int)a.size(); i++) A[i] = Complex<D>(a[i],\
    \ 0);\n        for(int i = 0; i < (int)b.size(); i++) B[i] = Complex<D>(b[i],\
    \ 0);\n        fft<D>(A, bitlen);\n        fft<D>(B, bitlen);\n        for(int\
    \ i = 0; i < n; i++) A[i] *= B[i];\n        ifft<D>(A, bitlen);\n        std::vector<D>\
    \ res(m);\n        for(int i = 0; i < m; i++) res[i] = A[i].x;\n        return\
    \ res;\n    } \n}; // namespace fft\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cmath>\n#include <vector>\n\
    #include <utility>\n\nnamespace fft {\n    template <typename D> struct Complex\
    \ {\n        D x, y;\n        Complex(): x(0), y(0) {};\n        Complex(D x,\
    \ D y) : x(x), y(y) {}\n        Complex &operator+=(const Complex &c) {\n    \
    \        x += c.x;\n            y += c.y;\n            return (*this);\n     \
    \   }\n        Complex &operator-=(const Complex &c) {\n            x -= c.x;\n\
    \            y -= c.y;\n            return (*this);\n        }\n        Complex\
    \ &operator*=(const Complex &c) {\n            D nx = x * c.x - y * c.y;\n   \
    \         D ny = x * c.y + y * c.x;\n            x = nx, y = ny;\n           \
    \ return (*this);\n        }\n        Complex &operator/=(const Complex& c) {\n\
    \            D nx = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y);\n         \
    \   D ny = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);\n            x = nx,\
    \ y = ny;\n            return (*this);\n        }\n        Complex operator-()\
    \ const { return Complex(-x, -y); }\n        Complex operator+(const Complex &c)\
    \ const { return Complex(*this) += c; }\n        Complex operator-(const Complex\
    \ &c) const { return Complex(*this) -= c; }\n        Complex operator*(const Complex\
    \ &c) const { return Complex(*this) *= c; }\n        Complex operator/(const Complex\
    \ &c) const { return Complex(*this) /= c; }\n    };\n\n    template<typename D>\n\
    \    constexpr const D PI = std::acos(D(-1));\n\n    template<typename D>\n  \
    \  inline Complex<D> omega(int k, int n) {\n        return Complex<D>(std::cos(D(k)\
    \ * 2 * PI<D> / n), std::sin(D(k) * 2 * PI<D> / n));\n    }\n\n    inline int\
    \ revbit(int mask, int bitlen) {\n        int res = 0;\n        while(bitlen--)\
    \ {\n            res = (res << 1) | (mask & 1);\n            mask >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    template<typename D>\n    void fft(std::vector<Complex<D>>&\
    \ a, int bitlen) {\n        int n = (int)a.size();\n        int len = n;\n   \
    \     while(len > 1) {\n            for(int i = 0; i < n; i += len) {\n      \
    \          int t = len >> 1;\n                for(int j = 0; j < t; j++) {\n \
    \                   int p = i + j;\n                    auto l = a[p] + a[p +\
    \ t];\n                    auto r = (a[p] - a[p + t]) * omega<D>(j, len);\n  \
    \                  a[p] = l;\n                    a[p + t] = r;\n            \
    \    }\n            }\n            len >>= 1;\n        }\n        for(int i =\
    \ 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n            if(i <\
    \ j) std::swap(a[i], a[j]);\n        }\n    }\n\n    template<typename D>\n  \
    \  void ifft(std::vector<Complex<D>>& a, int bitlen) {\n        int n = (int)a.size();\n\
    \        for(int i = 0; i < n; i++) {\n            int j = revbit(i, bitlen);\n\
    \            if(i < j) std::swap(a[i], a[j]);\n        }\n        int len = 2;\n\
    \        while(len <= n) {\n            for(int i = 0; i < n; i += len) {\n  \
    \              int t = len >> 1;\n                for(int j = 0; j < t; j++) {\n\
    \                    int p = i + j;\n                    auto l = a[p] + a[p +\
    \ t] * omega<D>(-j, len);\n                    auto r = a[p] - a[p + t] * omega<D>(-j,\
    \ len);\n                    a[p] = l;\n                    a[p + t] = r;\n  \
    \              }\n            }\n            len <<= 1;\n        }\n        for(int\
    \ i = 0; i < n; i++) a[i] /= Complex<D>(n, 0);\n    }\n\n    template<typename\
    \ D>\n    std::vector<D> convolution(const std::vector<D>& a, const std::vector<D>&\
    \ b) {\n        if(a.empty() || b.empty()) return {};\n        int m = (int)a.size()\
    \ + (int)b.size() - 1;\n        int n = 1, bitlen = 0;\n        while(n < m) {\n\
    \            n <<= 1;\n            bitlen++;\n        }\n        std::vector<Complex<D>>\
    \ A(n), B(n);\n        for(int i = 0; i < (int)a.size(); i++) A[i] = Complex<D>(a[i],\
    \ 0);\n        for(int i = 0; i < (int)b.size(); i++) B[i] = Complex<D>(b[i],\
    \ 0);\n        fft<D>(A, bitlen);\n        fft<D>(B, bitlen);\n        for(int\
    \ i = 0; i < n; i++) A[i] *= B[i];\n        ifft<D>(A, bitlen);\n        std::vector<D>\
    \ res(m);\n        for(int i = 0; i < m; i++) res[i] = A[i].x;\n        return\
    \ res;\n    } \n}; // namespace fft"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fft.hpp
  requiredBy: []
  timestamp: '2026-11-01 16:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki440.test.cpp
  - test/mytest/math/transforms-api.test.cpp
  - test/mytest/math/convolution-regressions.test.cpp
documentation_of: math/convolution/fft.hpp
layout: document
title: "FFT \u306B\u3088\u308B\u7573\u307F\u8FBC\u307F"
---

## このライブラリでできること

`fft::convolution(a,b)` は、2つの数列の畳み込み $c_k=\sum_{i+j=k}a_i b_j$ を計算します。係数列を多項式とみなすと、その積の係数を求めることと同じです。長さ $n,m$ の列の結果は長さ $n+m-1$ になります。

FFTでは、係数表現を複数の点での値へ変換し、各点で積を取り、逆変換で係数へ戻します。結果長以上の最小の2冪を $L$ とすると、愚直な $O(nm)$ 時間の計算を $O(L\log L)$ 時間にできます。

## 使い方

通常は `convolution` だけを呼べば、長さの調整と変換・逆変換まで行われます。例は $(1+2x)(3+4x)=3+10x+8x^2$ を計算しており、浮動小数点の誤差を考慮して近い値になったことを確認しています。

変換を直接使う場合は `fft::Complex<D>` の配列を用意します。`x,y` が実部・虚部、`omega(k,n)` は $\exp(2\pi ik/n)$、`PI<D>` は円周率です。

```cpp
#include "template/template.cpp"
#include "math/convolution/fft.hpp"

int main() {
    auto c = fft::convolution(vector<double>{1, 2}, vector<double>{3, 4});
    assert(abs(c[0] - 3) < 1e-8);
    assert(abs(c[1] - 10) < 1e-8);
    assert(abs(c[2] - 8) < 1e-8);
}
```

## API・計算量

畳み込みには $O(L)$ の追加空間を使います。正変換・逆変換だけなら配列をその場で更新し、追加空間は $O(1)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Complex<D>(), Complex<D>(x,y)` | 0 または指定した複素数を作る。 | O(1) |
| `Complex の単項 -, +, -, *, / と複合代入` | 複素数演算。 | O(1) |
| `omega<D>(k,n)` | exp(2πik/n)。 | O(1) |
| `revbit(mask,bitlen)` | 下位 bitlen bit の反転。 | O(bitlen) |
| `fft(a,bitlen)` | 配列 a を正変換して上書き。 | O(N log N) |
| `ifft(a,bitlen)` | 逆変換して N で割り、a を上書き。 | O(N log N) |
| `convolution(a,b)` | c[k]=Σ a[i]b[k-i] を返す。 | O(L log L)、L は結果長以上の最小の 2 冪 |

## 利用条件と実装上の注意

係数の型 `D` は double または long double を使ってください。畳み込みの片方でも空なら空の配列を返します。直接 `fft/ifft` を呼ぶ場合、長さ $N$ は正の2冪で、引数 `bitlen` は $N=2^{\mathrm{bitlen}}$ を満たす必要があります。逆変換には $N$ による正規化が含まれます。

FFTは浮動小数点計算です。整数の結果を得たい場合も、値の大きさや列長による誤差を見積もったうえで丸めてください。専用複素数型の除算では、除数を0にしてはいけません。
