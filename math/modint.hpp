template <int mod> struct ModInt {
    using M = ModInt;
    int x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    M &operator+=(const M &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    M &operator-=(const M &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    M &operator*=(const M &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    M &operator/=(const M &p) {
        *this *= p.inverse();
        return *this;
    }
    M operator-() const { return M(-x); }
    M operator+(const M &p) const { return M(*this) += p; }
    M operator-(const M &p) const { return M(*this) -= p; }
    M operator*(const M &p) const { return M(*this) *= p; }
    M operator/(const M &p) const { return M(*this) /= p; }
    M inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return M(u);
    }
    M pow(int64_t n) const {
        M ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const M &p) { return os << p.x; }
    friend istream &operator>>(istream &is, M &a) {
        int64_t t;
        is >> t;
        a = M<mod>(t);
        return (is);
    }
    static int get_mod() { return mod; }
};