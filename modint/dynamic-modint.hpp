#pragma once

#include <cassert>
#include <istream>
#include <ostream>

#include "../math/barrett-reduction.hpp"

class DynamicModInt {
  public:
    DynamicModInt() : x(0) {}
    DynamicModInt(long long y)
        : x(y >= 0
                ? y % (long long)mod
                : ((long long)mod - (-y) % (long long)mod) % (long long)mod) {}
    static void set_mod(unsigned int m) {
        assert(m > 0);
        mod = m;
        bt = BarrettReduction(m);
    }
    unsigned int val() const { return x; }
    DynamicModInt &operator+=(const DynamicModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    DynamicModInt &operator-=(const DynamicModInt &p) {
        if((x += (mod - p.x)) >= mod) x -= mod;
        return *this;
    }
    DynamicModInt &operator*=(const DynamicModInt &p) {
        x = bt.mul(x, p.x);
        return *this;
    }
    DynamicModInt &operator/=(const DynamicModInt &p) {
        *this *= p.inv();
        return *this;
    }
    DynamicModInt operator-() const { return DynamicModInt(-x); }
    DynamicModInt operator+(const DynamicModInt &p) const {
        return DynamicModInt(*this) += p;
    }
    DynamicModInt operator-(const DynamicModInt &p) const {
        return DynamicModInt(*this) -= p;
    }
    DynamicModInt operator*(const DynamicModInt &p) const {
        return DynamicModInt(*this) *= p;
    }
    DynamicModInt operator/(const DynamicModInt &p) const {
        return DynamicModInt(*this) /= p;
    }
    bool operator==(const DynamicModInt &p) const { return x == p.x; }
    bool operator!=(const DynamicModInt &p) const { return x != p.x; }
    DynamicModInt inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        assert(a == 1 && "gcd(x, mod) must be '1'.");
        return DynamicModInt(u);
    }
    DynamicModInt pow(long long n) const {
        assert(n >= 0);
        DynamicModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &p) {
        return os << p.x;
    }
    friend std::istream &operator>>(std::istream &is, DynamicModInt &a) {
        long long t;
        is >> t;
        a = DynamicModInt(t);
        return (is);
    }
    static unsigned int get_mod() { return mod; }

  private:
    unsigned int x;
    static inline unsigned int mod;
    static inline BarrettReduction bt;
};