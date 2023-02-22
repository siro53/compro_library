#pragma once

#include <cassert>
#include <utility>
#include <vector>

template <typename T> class Matrix {
  public:
    Matrix() {}
    explicit Matrix(int n) : Matrix(n, n) {}
    explicit Matrix(int n, int m) : dat(n, std::vector<T>(m)) {}
    size_t height() const { return dat.size(); }
    size_t width() const { return dat[0].size(); }
    const std::vector<T> &operator[](int k) const { return dat[k]; }
    std::vector<T> &operator[](int k) { return dat[k]; }
    static inline Matrix I(int n) {
        Matrix ret(n);
        for(int i = 0; i < n; i++) ret[i][i] = T(1);
        return ret;
    }
    Matrix &operator+=(const Matrix &other) {
        size_t n = height(), m = width();
        assert(n == other.height() && m == other.width());
        for(size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < m; j++) { (*this)[i][j] += other[i][j]; }
        }
        return (*this);
    }
    Matrix &operator-=(const Matrix &other) {
        size_t n = height(), m = width();
        assert(n == other.height() && m == other.width());
        for(size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < m; j++) { (*this)[i][j] -= other[i][j]; }
        }
        return (*this);
    }
    Matrix &operator*=(const Matrix &other) {
        size_t n = height(), m2 = width();
        size_t m = other.width();
        assert(m2 == other.height());
        std::vector res(n, std::vector<T>(m));
        for(size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < m; j++) {
                T sum = 0;
                for(size_t k = 0; k < m2; k++) {
                    sum += (*this)[i][k] * other[k][j];
                }
                res[i][j] = sum;
            }
        }
        this->dat.swap(res);
        return (*this);
    }
    Matrix operator+(const Matrix &other) const {
        return (Matrix(*this) += other);
    }
    Matrix operator-(const Matrix &other) const {
        return (Matrix(*this) -= other);
    }
    Matrix operator*(const Matrix &other) const {
        return (Matrix(*this) *= other);
    }
    Matrix pow(long long k) const {
        Matrix res = Matrix::I(height()), mul = (*this);
        while(k > 0) {
            if(k & 1) res *= mul;
            mul *= mul;
            k >>= 1;
        }
        return res;
    }

  private:
    std::vector<std::vector<T>> dat;
};