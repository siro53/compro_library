#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/convolution/fft.hpp"
#include "../../../math/convolution/ntt.hpp"


int main() {
    using C = fft::Complex<long double>;
    auto close = [](C actual, complex<long double> expected) { assert(abs(complex<long double>(actual.x, actual.y) - expected) < 1e-9L); };
    C zero; close(zero, {0, 0}); C a(3, -2), b(-1, 4); complex<long double> x(3, -2), y(-1, 4);
    close(-a, -x); close(a + b, x + y); close(a - b, x - y); close(a * b, x * y); close(a / b, x / y);
    C c = a; assert(&(c += b) == &c); close(c, x + y);
    c = a; assert(&(c -= b) == &c); close(c, x - y);
    c = a; assert(&(c *= b) == &c); close(c, x * y);
    c = a; assert(&(c /= b) == &c); close(c, x / y);
    using mint = ModInt<998244353>;
    ntt::ntt_info<mint> info; assert(ntt::exp_limit(998244353) == 23 && info.limit == 23);
    for(int k = 0; k <= info.limit; ++k) {
        assert(info.root[k] * info.iroot[k] == mint(1));
        assert(info.root[k].pow(1LL << k) == mint(1));
        if(k) assert(info.root[k].pow(1LL << (k - 1)) != mint(1));
    }
    for(int width = 0; width <= 8; ++width) for(int value = 0; value < (1 << width); ++value) {
        int expected = 0; for(int i = 0; i < width; ++i) expected |= (value >> i & 1) << (width - i - 1);
        assert(fft::revbit(value, width) == expected && ntt::revbit(value, width) == unsigned(expected));
        if(value == 0) assert(ntt::revbit(value) == 0);
        else { int bits = 32 - __builtin_clz(value); assert(ntt::revbit(value) == unsigned(fft::revbit(value, bits))); }
    }
    assert(ntt::revbit(1ULL, 64) == (1ULL << 63));
    for(int width = 0; width <= 5; ++width) {
        int n = 1 << width; vector<C> values(n); vector<mint> modular(n);
        for(int i = 0; i < n; ++i) { values[i] = C(i % 7 - 3, 0); modular[i] = i % 7 - 3; }
        auto original = values; auto original_mod = modular;
        fft::fft(values, width); ntt::ntt(modular);
        for(int k = 0; k < n; ++k) {
            complex<long double> expected(0, 0); mint mod_expected = 0;
            for(int i = 0; i < n; ++i) {
                auto angle = 2 * acos(-1.0L) * i * k / n;
                expected += original[i].x * polar(1.0L, angle);
                mod_expected += original_mod[i] * info.root[width].pow(i * k);
            }
            close(values[k], expected); assert(modular[k] == mod_expected);
            close(fft::omega<long double>(k, n), polar(1.0L, 2 * acos(-1.0L) * k / n));
        }
        fft::ifft(values, width); ntt::intt(modular);
        for(int i = 0; i < n; ++i) { close(values[i], {original[i].x, 0}); assert(modular[i] == original_mod[i]); }
    }
    INT(a0, b0); print(a0 + b0);
}
