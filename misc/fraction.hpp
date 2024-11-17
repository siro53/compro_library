#pragma once

#include <numeric>

template<typename Int = long long>
struct Fraction {
    using F = Fraction;
    Int a, b;

    Fraction(): a(0), b(1) {}
    Fraction(Int _a, Int _b): a(_a), b(_b) {
        normalize();
    }
    Fraction(Int _a): a(_a), b(1) {}
    inline void normalize() {
        Int g = Fraction::gcd(a, b);
        a /= g;
        b /= g;
        if(b < 0) {
            a = -a, b = -b;
        }
    }
    F &operator+=(const F& f) {
        Int na = a * f.b + b * f.a;
        Int nb = b * f.b;
        a = na, b = nb;
        normalize();
        return *this;
    }
    F &operator-=(const F& f) {
        Int na = a * f.b - b * f.a;
        Int nb = b * f.b;
        a = na, b = nb;
        normalize();
        return *this;
    }
    F &operator*=(const F& f) {
        a *= f.a;
        b *= f.b;
        normalize();
        return *this;
    }
    F &operator/=(const F& f) {
        a *= f.b;
        b *= f.a;
        normalize();
        return *this;
    }
    F operator-() const { return F(-a, b); }
    F operator+(const F& f) const { return F(*this) += f; }
    F operator-(const F& f) const { return F(*this) -= f; }
    F operator*(const F& f) const { return F(*this) *= f; }
    F operator/(const F& f) const { return F(*this) /= f; }
    bool operator==(const F& f) const {
        return a * f.b == b * f.a;
    }
    bool operator!=(const F& f) const {
        return !(*this == f);
    }
    bool operator<(const F& f) const {
        return a * f.b < b * f.a;
    }
    bool operator<=(const F& f) const {
        return a * f.b <= b * f.a;
    }
    bool operator>(const F& f) const {
        return !(*this <= f);
    }
    bool operator>=(const F& f) const {
        return !(*this < f);
    }
    
    inline static Int gcd(Int a, Int b) {
        Int s = (a > 0 ? a : -a), t = (b > 0 ? b : -b);
        while (s % t != 0) {
            Int u = s % t;
            s = t;
            t = u;
        }
        return t;
    }
};