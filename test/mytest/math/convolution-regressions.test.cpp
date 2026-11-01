#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/convolution/ntt.hpp"
#include "../../../math/convolution/fft.hpp"

void regression_test() {
    using mint = ModInt<998244353>;
    assert(ntt::revbit(0) == 0 && ntt::revbit(1, 3) == 4);
    assert(ntt::revbit(1, 64) == (1ULL << 63));
    mt19937 rng(53);
    for(int n = 1; n <= 64; n *= 2) {
        vector<mint> a(n), expected(n);
        for(auto& x : a) x = rng() % 100;
        auto original = a;
        mint w = mint(3).pow((mint::get_mod() - 1) / n);
        for(int k = 0; k < n; k++) for(int j = 0; j < n; j++) expected[k] += a[j] * w.pow(k * j);
        ntt::ntt(a); assert(a == expected);
        ntt::intt(a); assert(a == original);
    }
    for(int n = 0; n <= 20; n++) for(int m = 0; m <= 20; m++) {
        vector<mint> a(n), b(m), expected(n && m ? n + m - 1 : 0);
        vector<double> fa(n), fb(m);
        for(int i = 0; i < n; i++) a[i] = (int)(fa[i] = (int)(rng() % 21) - 10);
        for(int i = 0; i < m; i++) b[i] = (int)(fb[i] = (int)(rng() % 21) - 10);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) expected[i + j] += a[i] * b[j];
        assert(ntt::convolution(a, b) == expected);
        auto fc = fft::convolution(fa, fb);
        assert(fc.size() == expected.size());
        for(int k = 0; k < (int)fc.size(); k++) {
            double sum = 0;
            for(int i = 0; i < n; i++) if(0 <= k - i && k - i < m) sum += fa[i] * fb[k - i];
            assert(abs(fc[k] - sum) < 1e-7);
        }
    }
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
