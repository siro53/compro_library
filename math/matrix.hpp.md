---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki1750.test.cpp
    title: test/yukicoder/yuki1750.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T> class Matrix {\n  public:\n    Matrix()\
    \ {}\n    explicit Matrix(int n) : Matrix(n, n) {}\n    explicit Matrix(int n,\
    \ int m) : dat(n, std::vector<T>(m)) {}\n    size_t height() const { return dat.size();\
    \ }\n    size_t width() const { return dat[0].size(); }\n    const std::vector<T>\
    \ &operator[](int k) const { return dat[k]; }\n    std::vector<T> &operator[](int\
    \ k) { return dat[k]; }\n    static inline Matrix I(int n) {\n        Matrix ret(n);\n\
    \        for(int i = 0; i < n; i++) ret[i][i] = T(1);\n        return ret;\n \
    \   }\n    Matrix &operator+=(const Matrix &other) {\n        size_t n = height(),\
    \ m = width();\n        assert(n == other.height() && m == other.width());\n \
    \       for(size_t i = 0; i < n; i++) {\n            for(size_t j = 0; j < m;\
    \ j++) { (*this)[i][j] += other[i][j]; }\n        }\n        return (*this);\n\
    \    }\n    Matrix &operator-=(const Matrix &other) {\n        size_t n = height(),\
    \ m = width();\n        assert(n == other.height() && m == other.width());\n \
    \       for(size_t i = 0; i < n; i++) {\n            for(size_t j = 0; j < m;\
    \ j++) { (*this)[i][j] -= other[i][j]; }\n        }\n        return (*this);\n\
    \    }\n    Matrix &operator*=(const Matrix &other) {\n        size_t n = height(),\
    \ m2 = width();\n        size_t m = other.width();\n        assert(m2 == other.height());\n\
    \        std::vector res(n, std::vector<T>(m));\n        for(size_t i = 0; i <\
    \ n; i++) {\n            for(size_t j = 0; j < m; j++) {\n                T sum\
    \ = 0;\n                for(size_t k = 0; k < m2; k++) {\n                   \
    \ sum += (*this)[i][k] * other[k][j];\n                }\n                res[i][j]\
    \ = sum;\n            }\n        }\n        this->dat.swap(res);\n        return\
    \ (*this);\n    }\n    Matrix operator+(const Matrix &other) const {\n       \
    \ return (Matrix(*this) += other);\n    }\n    Matrix operator-(const Matrix &other)\
    \ const {\n        return (Matrix(*this) -= other);\n    }\n    Matrix operator*(const\
    \ Matrix &other) const {\n        return (Matrix(*this) *= other);\n    }\n  \
    \  Matrix pow(long long k) const {\n        Matrix res = Matrix::I(height()),\
    \ mul = (*this);\n        while(k > 0) {\n            if(k & 1) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n  private:\n    std::vector<std::vector<T>> dat;\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T> class Matrix {\n  public:\n    Matrix() {}\n    explicit\
    \ Matrix(int n) : Matrix(n, n) {}\n    explicit Matrix(int n, int m) : dat(n,\
    \ std::vector<T>(m)) {}\n    size_t height() const { return dat.size(); }\n  \
    \  size_t width() const { return dat[0].size(); }\n    const std::vector<T> &operator[](int\
    \ k) const { return dat[k]; }\n    std::vector<T> &operator[](int k) { return\
    \ dat[k]; }\n    static inline Matrix I(int n) {\n        Matrix ret(n);\n   \
    \     for(int i = 0; i < n; i++) ret[i][i] = T(1);\n        return ret;\n    }\n\
    \    Matrix &operator+=(const Matrix &other) {\n        size_t n = height(), m\
    \ = width();\n        assert(n == other.height() && m == other.width());\n   \
    \     for(size_t i = 0; i < n; i++) {\n            for(size_t j = 0; j < m; j++)\
    \ { (*this)[i][j] += other[i][j]; }\n        }\n        return (*this);\n    }\n\
    \    Matrix &operator-=(const Matrix &other) {\n        size_t n = height(), m\
    \ = width();\n        assert(n == other.height() && m == other.width());\n   \
    \     for(size_t i = 0; i < n; i++) {\n            for(size_t j = 0; j < m; j++)\
    \ { (*this)[i][j] -= other[i][j]; }\n        }\n        return (*this);\n    }\n\
    \    Matrix &operator*=(const Matrix &other) {\n        size_t n = height(), m2\
    \ = width();\n        size_t m = other.width();\n        assert(m2 == other.height());\n\
    \        std::vector res(n, std::vector<T>(m));\n        for(size_t i = 0; i <\
    \ n; i++) {\n            for(size_t j = 0; j < m; j++) {\n                T sum\
    \ = 0;\n                for(size_t k = 0; k < m2; k++) {\n                   \
    \ sum += (*this)[i][k] * other[k][j];\n                }\n                res[i][j]\
    \ = sum;\n            }\n        }\n        this->dat.swap(res);\n        return\
    \ (*this);\n    }\n    Matrix operator+(const Matrix &other) const {\n       \
    \ return (Matrix(*this) += other);\n    }\n    Matrix operator-(const Matrix &other)\
    \ const {\n        return (Matrix(*this) -= other);\n    }\n    Matrix operator*(const\
    \ Matrix &other) const {\n        return (Matrix(*this) *= other);\n    }\n  \
    \  Matrix pow(long long k) const {\n        Matrix res = Matrix::I(height()),\
    \ mul = (*this);\n        while(k > 0) {\n            if(k & 1) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n  private:\n    std::vector<std::vector<T>> dat;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-02-25 23:57:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki1750.test.cpp
documentation_of: math/matrix.hpp
layout: document
title: "\u884C\u5217"
---

## このライブラリでできること

`Matrix<T>` は、行数・列数を実行時に指定できる密行列です。行列の加減算、行列積、正方行列の累乗を提供します。線形漸化式を行列で表し、遷移を何回も適用した結果を繰り返し二乗法で求める場合などに使えます。

$n\times k$ 行列と $k\times m$ 行列の積は、$(AB)_{i,j}=\sum_{t=0}^{k-1}A_{i,t}B_{t,j}$ をそのまま計算するため $O(nkm)$ 時間です。高速行列積を実装したクラスではありません。

## 使い方

`Matrix<T>(n,m)` で零行列を作り、`a[i][j]` で成分を設定します。引数1つなら正方行列、`Matrix<T>::I(n)` なら単位行列です。

例の行列はフィボナッチ数列の遷移を表し、5乗の右上成分が第5項の $5$ になります。一般に $n\times n$ 行列の $k$ 乗は $O(n^3\log(k+1))$ 時間で計算できます。

```cpp
#include "template/template.cpp"
#include "math/matrix.hpp"

int main() {
    Matrix<long long> a(2);
    a[0][0] = a[0][1] = a[1][0] = 1;
    auto b = a.pow(5);
    assert(b[0][1] == 5);
}
```

## API・計算量

$n\times m$ 行列の保持と、その形の積の結果にはそれぞれ $O(nm)$ の空間を使います。$n\times n$ 行列の累乗の追加空間は $O(n^2)$ です。

| API | 動作・返り値 | 時間計算量 |
| --- | --- | --- |
| `Matrix(n), Matrix(n,m)` | n×n または n×m の零行列。 | O(nm) |
| `height(), width()` | 行数・列数。 | O(1) |
| `operator[](i)` | i 行への参照。const 版もある。 | O(1) |
| `I(n)` | n×n の単位行列を返す static メソッド。 | O(n²) |
| `operator+=, -=, +, -` | 同じ形の行列を成分ごとに加減算。 | O(nm) |
| `operator*=, *` | n×k と k×m の行列積。 | O(nkm) |
| `pow(k)` | 正方行列の k 乗。 | O(n³ log(k+1))（k=0 は O(n²)） |

## 利用条件と実装上の注意

加減算では同じ形、積では左の列数と右の行数が一致する必要があります。`pow(k)` は正方行列かつ $k\ge0$ の場合に使い、$k=0$ では単位行列を返します。

`width()` は先頭行を参照するため、0行の行列やデフォルト構築直後の行列では呼べません。成分型は $0,1$ の構築と各演算に対応する必要があります。値が急速に大きくなる問題では、必要な法の modint を使うなどして中間値も含めて管理してください。
