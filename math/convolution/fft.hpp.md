---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ b) {\n        int m = (int)a.size() + (int)b.size() - 1;\n        int n = 1,\
    \ bitlen = 0;\n        while(n < m) {\n            n <<= 1;\n            bitlen++;\n\
    \        }\n        std::vector<Complex<D>> A(n), B(n);\n        for(int i = 0;\
    \ i < (int)a.size(); i++) A[i] = Complex<D>(a[i], 0);\n        for(int i = 0;\
    \ i < (int)b.size(); i++) B[i] = Complex<D>(b[i], 0);\n        fft<D>(A, bitlen);\n\
    \        fft<D>(B, bitlen);\n        for(int i = 0; i < n; i++) A[i] *= B[i];\n\
    \        ifft<D>(A, bitlen);\n        std::vector<D> res(m);\n        for(int\
    \ i = 0; i < m; i++) res[i] = A[i].x;\n        return res;\n    } \n}; // namespace\
    \ fft\n"
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
    \ b) {\n        int m = (int)a.size() + (int)b.size() - 1;\n        int n = 1,\
    \ bitlen = 0;\n        while(n < m) {\n            n <<= 1;\n            bitlen++;\n\
    \        }\n        std::vector<Complex<D>> A(n), B(n);\n        for(int i = 0;\
    \ i < (int)a.size(); i++) A[i] = Complex<D>(a[i], 0);\n        for(int i = 0;\
    \ i < (int)b.size(); i++) B[i] = Complex<D>(b[i], 0);\n        fft<D>(A, bitlen);\n\
    \        fft<D>(B, bitlen);\n        for(int i = 0; i < n; i++) A[i] *= B[i];\n\
    \        ifft<D>(A, bitlen);\n        std::vector<D> res(m);\n        for(int\
    \ i = 0; i < m; i++) res[i] = A[i].x;\n        return res;\n    } \n}; // namespace\
    \ fft"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fft.hpp
  requiredBy: []
  timestamp: '2023-09-26 00:52:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki440.test.cpp
documentation_of: math/convolution/fft.hpp
layout: document
redirect_from:
- /library/math/convolution/fft.hpp
- /library/math/convolution/fft.hpp.html
title: math/convolution/fft.hpp
---
