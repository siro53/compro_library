#pragma once

#include <istream>
#include <utility>

// ローリングハッシュ用 modint
// https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
class ModInt_2_61 {
  public:
    using M = ModInt_2_61;
    ModInt_2_61() : x(0) {}
    ModInt_2_61(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    unsigned long long val() const { return x; }
    M &operator+=(const M &m) {
        if((x += m.x) >= mod) x -= mod;
        return *this;
    }
    M &operator-=(const M &m) {
        if((x += mod - m.x) >= mod) x -= mod;
        return *this;
    }
    M &operator*=(const M &m) {
        __uint128_t t = (__uint128_t)x * m.x;
        unsigned long long na = t >> 61;
        unsigned long long nb = t & mod;
        if((na += nb) >= mod) na -= mod;
        x = na;
        return *this;
    }
    M &operator/=(const M &m) {
        *this *= m.inv();
        return *this;
    }
    M operator-() const { return M(-(long long)x); }
    M operator+(const M &m) const { return M(*this) += m; }
    M operator-(const M &m) const { return M(*this) -= m; }
    M operator*(const M &m) const { return M(*this) *= m; }
    M operator/(const M &m) const { return M(*this) /= m; }
    bool operator==(const M &m) const { return (x == m.x); }
    bool operator!=(const M &m) const { return (x != m.x); }
    M inv() const {
        long long a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return M(u);
    }
    M pow(unsigned long long n) const {
        M ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const M &p) {
        return os << p.x;
    }
    friend std::istream &operator>>(std::istream &is, M &a) {
        long long t;
        is >> t;
        a = M(t);
        return (is);
    }
    static constexpr unsigned long long get_mod() { return mod; }

  private:
    unsigned long long x;
    static constexpr unsigned long long mod = (1LL << 61) - 1;
};