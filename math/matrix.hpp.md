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
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---
