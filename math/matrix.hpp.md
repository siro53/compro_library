---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/determinant.test.cpp
    title: test/determinant.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\n// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\
    \u30EA\ntemplate <class T> struct Matrix {\n    vector<vector<T>> A;\n\n    Matrix()\
    \ {}\n\n    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n\n    Matrix(size_t\
    \ n) : A(n, vector<T>(n, 0)){};\n\n    size_t height() const { return (A.size());\
    \ }\n\n    size_t width() const { return (A[0].size()); }\n\n    inline const\
    \ vector<T> &operator[](int k) const { return (A.at(k)); }\n\n    inline vector<T>\
    \ &operator[](int k) { return (A.at(k)); }\n\n    // \u5358\u4F4D\u884C\u5217\n\
    \    static Matrix I(size_t n) {\n        Matrix mat(n);\n        for(int i =\
    \ 0; i < n; i++)\n            mat[i][i] = 1;\n        return (mat);\n    }\n\n\
    \    Matrix &operator+=(const Matrix &B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() && m == B.width());\n        for(int i = 0; i\
    \ < n; i++)\n            for(int j = 0; j < m; j++)\n                (*this)[i][j]\
    \ += B[i][j];\n        return (*this);\n    }\n\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        size_t n = height(), m = width();\n        assert(n ==\
    \ B.height() && m == B.width());\n        for(int i = 0; i < n; i++)\n       \
    \     for(int j = 0; j < m; j++)\n                (*this)[i][j] -= B[i][j];\n\
    \        return (*this);\n    }\n\n    Matrix &operator*=(const Matrix &B) {\n\
    \        size_t n = height(), m = B.width(), p = width();\n        assert(p ==\
    \ B.height());\n        vector<vector<T>> C(n, vector<T>(m, 0));\n\t\tT sum;\n\
    \        for(int i = 0; i < n; i++){\n            for(int j = 0; j < m; j++){\n\
    \t\t\t\tsum = 0;\n                for(int k = 0; k < p; k++){\n              \
    \      sum += (*this)[i][k] * B[k][j];\n\t\t\t\t}\n\t\t\t\tC[i][j] = sum;\n\t\t\
    \t}\n\t\t}\n        A.swap(C);\n        return (*this);\n    }\n\n    // \u7D2F\
    \u4E57\n    Matrix &operator^=(long long k) {\n        Matrix B = Matrix::I(height());\n\
    \        while(k > 0) {\n            if(k & 1)\n                B *= *this;\n\
    \            *this *= *this;\n            k >>= 1LL;\n        }\n        A.swap(B.A);\n\
    \        return (*this);\n    }\n\n    Matrix operator+(const Matrix &B) const\
    \ { return (Matrix(*this) += B); }\n\n    Matrix operator-(const Matrix &B) const\
    \ { return (Matrix(*this) -= B); }\n\n    Matrix operator*(const Matrix &B) const\
    \ { return (Matrix(*this) *= B); }\n\n    Matrix operator^(const long long k)\
    \ const { return (Matrix(*this) ^= k); }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        size_t n = p.height(), m = p.width();\n        for(int\
    \ i = 0; i < n; i++) {\n            os << \"[\";\n            for(int j = 0; j\
    \ < m; j++) {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\"\
    );\n            }\n        }\n        return (os);\n    }\n\n    // \u884C\u5217\
    \u5F0F\n    T determinant() {\n        Matrix B(*this);\n        assert(width()\
    \ == height());\n        T ret = 1;\n        for(int i = 0; i < width(); i++)\
    \ {\n            int idx = -1;\n            for(int j = i; j < width(); j++) {\n\
    \                if(B[j][i] != 0)\n                    idx = j;\n            }\n\
    \            if(idx == -1)\n                return (0);\n            if(i != idx)\
    \ {\n                ret *= -1;\n                swap(B[i], B[idx]);\n       \
    \     }\n            ret *= B[i][i];\n            T vv = B[i][i];\n          \
    \  for(int j = 0; j < width(); j++) {\n                B[i][j] /= vv;\n      \
    \      }\n            for(int j = i + 1; j < width(); j++) {\n               \
    \ T a = B[j][i];\n                for(int k = 0; k < width(); k++) {\n       \
    \             B[j][k] -= B[i][k] * a;\n                }\n            }\n    \
    \    }\n        return (ret);\n    }\n};\n"
  code: "// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\ntemplate <class T> struct\
    \ Matrix {\n    vector<vector<T>> A;\n\n    Matrix() {}\n\n    Matrix(size_t n,\
    \ size_t m) : A(n, vector<T>(m, 0)) {}\n\n    Matrix(size_t n) : A(n, vector<T>(n,\
    \ 0)){};\n\n    size_t height() const { return (A.size()); }\n\n    size_t width()\
    \ const { return (A[0].size()); }\n\n    inline const vector<T> &operator[](int\
    \ k) const { return (A.at(k)); }\n\n    inline vector<T> &operator[](int k) {\
    \ return (A.at(k)); }\n\n    // \u5358\u4F4D\u884C\u5217\n    static Matrix I(size_t\
    \ n) {\n        Matrix mat(n);\n        for(int i = 0; i < n; i++)\n         \
    \   mat[i][i] = 1;\n        return (mat);\n    }\n\n    Matrix &operator+=(const\
    \ Matrix &B) {\n        size_t n = height(), m = width();\n        assert(n ==\
    \ B.height() && m == B.width());\n        for(int i = 0; i < n; i++)\n       \
    \     for(int j = 0; j < m; j++)\n                (*this)[i][j] += B[i][j];\n\
    \        return (*this);\n    }\n\n    Matrix &operator-=(const Matrix &B) {\n\
    \        size_t n = height(), m = width();\n        assert(n == B.height() &&\
    \ m == B.width());\n        for(int i = 0; i < n; i++)\n            for(int j\
    \ = 0; j < m; j++)\n                (*this)[i][j] -= B[i][j];\n        return\
    \ (*this);\n    }\n\n    Matrix &operator*=(const Matrix &B) {\n        size_t\
    \ n = height(), m = B.width(), p = width();\n        assert(p == B.height());\n\
    \        vector<vector<T>> C(n, vector<T>(m, 0));\n\t\tT sum;\n        for(int\
    \ i = 0; i < n; i++){\n            for(int j = 0; j < m; j++){\n\t\t\t\tsum =\
    \ 0;\n                for(int k = 0; k < p; k++){\n                    sum +=\
    \ (*this)[i][k] * B[k][j];\n\t\t\t\t}\n\t\t\t\tC[i][j] = sum;\n\t\t\t}\n\t\t}\n\
    \        A.swap(C);\n        return (*this);\n    }\n\n    // \u7D2F\u4E57\n \
    \   Matrix &operator^=(long long k) {\n        Matrix B = Matrix::I(height());\n\
    \        while(k > 0) {\n            if(k & 1)\n                B *= *this;\n\
    \            *this *= *this;\n            k >>= 1LL;\n        }\n        A.swap(B.A);\n\
    \        return (*this);\n    }\n\n    Matrix operator+(const Matrix &B) const\
    \ { return (Matrix(*this) += B); }\n\n    Matrix operator-(const Matrix &B) const\
    \ { return (Matrix(*this) -= B); }\n\n    Matrix operator*(const Matrix &B) const\
    \ { return (Matrix(*this) *= B); }\n\n    Matrix operator^(const long long k)\
    \ const { return (Matrix(*this) ^= k); }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        size_t n = p.height(), m = p.width();\n        for(int\
    \ i = 0; i < n; i++) {\n            os << \"[\";\n            for(int j = 0; j\
    \ < m; j++) {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\"\
    );\n            }\n        }\n        return (os);\n    }\n\n    // \u884C\u5217\
    \u5F0F\n    T determinant() {\n        Matrix B(*this);\n        assert(width()\
    \ == height());\n        T ret = 1;\n        for(int i = 0; i < width(); i++)\
    \ {\n            int idx = -1;\n            for(int j = i; j < width(); j++) {\n\
    \                if(B[j][i] != 0)\n                    idx = j;\n            }\n\
    \            if(idx == -1)\n                return (0);\n            if(i != idx)\
    \ {\n                ret *= -1;\n                swap(B[i], B[idx]);\n       \
    \     }\n            ret *= B[i][i];\n            T vv = B[i][i];\n          \
    \  for(int j = 0; j < width(); j++) {\n                B[i][j] /= vv;\n      \
    \      }\n            for(int j = i + 1; j < width(); j++) {\n               \
    \ T a = B[j][i];\n                for(int k = 0; k < width(); k++) {\n       \
    \             B[j][k] -= B[i][k] * a;\n                }\n            }\n    \
    \    }\n        return (ret);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2021-05-06 11:13:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/determinant.test.cpp
documentation_of: math/matrix.hpp
layout: document
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---
