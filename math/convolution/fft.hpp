#pragma once

#include <cassert>
#include <cmath>
#include <vector>
#include <utility>

namespace fft {
    template <typename D> struct Complex {
        D x, y;
        Complex(): x(0), y(0) {};
        Complex(D x, D y) : x(x), y(y) {}
        Complex &operator+=(const Complex &c) {
            x += c.x;
            y += c.y;
            return (*this);
        }
        Complex &operator-=(const Complex &c) {
            x -= c.x;
            y -= c.y;
            return (*this);
        }
        Complex &operator*=(const Complex &c) {
            D nx = x * c.x - y * c.y;
            D ny = x * c.y + y * c.x;
            x = nx, y = ny;
            return (*this);
        }
        Complex &operator/=(const Complex& c) {
            D nx = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y);
            D ny = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);
            x = nx, y = ny;
            return (*this);
        }
        Complex operator-() const { return Complex(-x, -y); }
        Complex operator+(const Complex &c) const { return Complex(*this) += c; }
        Complex operator-(const Complex &c) const { return Complex(*this) -= c; }
        Complex operator*(const Complex &c) const { return Complex(*this) *= c; }
        Complex operator/(const Complex &c) const { return Complex(*this) /= c; }
    };

    template<typename D>
    constexpr const D PI = std::acos(D(-1));

    template<typename D>
    inline Complex<D> omega(int k, int n) {
        return Complex<D>(std::cos(D(k) * 2 * PI<D> / n), std::sin(D(k) * 2 * PI<D> / n));
    }

    inline int revbit(int mask, int bitlen) {
        int res = 0;
        while(bitlen--) {
            res = (res << 1) | (mask & 1);
            mask >>= 1;
        }
        return res;
    }

    template<typename D>
    void fft(std::vector<Complex<D>>& a, int bitlen) {
        int n = (int)a.size();
        int len = n;
        while(len > 1) {
            for(int i = 0; i < n; i += len) {
                int t = len >> 1;
                for(int j = 0; j < t; j++) {
                    int p = i + j;
                    auto l = a[p] + a[p + t];
                    auto r = (a[p] - a[p + t]) * omega<D>(j, len);
                    a[p] = l;
                    a[p + t] = r;
                }
            }
            len >>= 1;
        }
        for(int i = 0; i < n; i++) {
            int j = revbit(i, bitlen);
            if(i < j) std::swap(a[i], a[j]);
        }
    }

    template<typename D>
    void ifft(std::vector<Complex<D>>& a, int bitlen) {
        int n = (int)a.size();
        for(int i = 0; i < n; i++) {
            int j = revbit(i, bitlen);
            if(i < j) std::swap(a[i], a[j]);
        }
        int len = 2;
        while(len <= n) {
            for(int i = 0; i < n; i += len) {
                int t = len >> 1;
                for(int j = 0; j < t; j++) {
                    int p = i + j;
                    auto l = a[p] + a[p + t] * omega<D>(-j, len);
                    auto r = a[p] - a[p + t] * omega<D>(-j, len);
                    a[p] = l;
                    a[p + t] = r;
                }
            }
            len <<= 1;
        }
        for(int i = 0; i < n; i++) a[i] /= Complex<D>(n, 0);
    }

    template<typename D>
    std::vector<D> convolution(const std::vector<D>& a, const std::vector<D>& b) {
        int m = (int)a.size() + (int)b.size() - 1;
        int n = 1, bitlen = 0;
        while(n < m) {
            n <<= 1;
            bitlen++;
        }
        std::vector<Complex<D>> A(n), B(n);
        for(int i = 0; i < (int)a.size(); i++) A[i] = Complex<D>(a[i], 0);
        for(int i = 0; i < (int)b.size(); i++) B[i] = Complex<D>(b[i], 0);
        fft<D>(A, bitlen);
        fft<D>(B, bitlen);
        for(int i = 0; i < n; i++) A[i] *= B[i];
        ifft<D>(A, bitlen);
        std::vector<D> res(m);
        for(int i = 0; i < m; i++) res[i] = A[i].x;
        return res;
    } 
}; // namespace fft