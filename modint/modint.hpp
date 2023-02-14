#pragma once

#include <istream>
#include <ostream>
#include <utility>

template <int mod> class ModInt {
  public:
    ModInt() : x(0) {}
    ModInt(long long y)
        : x(y >= 0 ? y % umod() : (umod() - (-y) % umod()) % umod()) {}
    unsigned int val() const { return x; }
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= umod()) x -= umod();
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += umod() - p.x) >= umod()) x -= umod();
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (unsigned int)(1ULL * x * p.x % umod());
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inv();
        return *this;
    }
    ModInt operator-() const { return ModInt(-(long long)x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inv() const {
        long long a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(unsigned long long n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        long long t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
    static constexpr int get_mod() { return mod; }

  private:
    unsigned int x;
    static constexpr unsigned int umod() { return mod; }
};