#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/matrix.hpp"
#include "../../../math/binom.hpp"
#include "../../../modint/modint.hpp"


int main() {
    using mint = ModInt<1000000007>;
    Binomial<mint> binom, precomputed(64);
    binom.extend();
    vector<vector<ll>> choose(31, vector<ll>(31));
    for(int n = 0; n <= 30; ++n) {
        choose[n][0] = 1;
        for(int k = 1; k <= n; ++k) choose[n][k] = (choose[n - 1][k - 1] + choose[n - 1][k]) % 1000000007;
    }
    mint factorial = 1;
    for(int n = 0; n <= 30; ++n) {
        if(n) factorial *= mint(n);
        assert(binom.fac(n) == factorial && precomputed.fac(n) == factorial);
        assert(binom.fac_inv(n) * factorial == mint(1));
        if(n) assert(binom.inv(n) * mint(n) == mint(1));
        for(int k = -1; k <= n + 1; ++k) {
            mint expected = 0;
            if(0 <= k && k <= n) expected = choose[n][k];
            assert(binom.binom(n, k) == expected && binom.binom_naive(n, k) == expected);
            mint permutations = 0;
            if(0 <= k && k <= n) { permutations = 1; for(int i = 0; i < k; ++i) permutations *= mint(n - i); }
            assert(binom.perm(n, k) == permutations);
        }
        for(int k = 0; k <= 10 && n + k <= 30; ++k) {
            mint expected = k == 0 ? 1 : (n == 0 ? 0 : choose[n + k - 1][k]);
            assert(binom.hom(n, k) == expected);
        }
    }
    assert(binom.fac(-1) == mint(0) && binom.fac_inv(-1) == mint(0));
    assert(binom.inv(-3) * mint(-3) == mint(1));
    assert(binom.binom(-1, 0) == mint(0) && binom.binom_naive(-1, 0) == mint(0));
    assert(binom.perm(-1, 0) == mint(0) && binom.hom(-1, 0) == mint(0));
    assert(binom.binom_naive(1000000000LL, 2) == mint(1000000000LL) * mint(999999999) / mint(2));
    mt19937 rng(53);
    for(int n = 1; n <= 5; ++n) for(int m = 1; m <= 5; ++m) {
        Matrix<ll> a, b(n, m);
        assert(a.height() == 0);
        a = Matrix<ll>(n, m);
        assert(a.height() == unsigned(n) && a.width() == unsigned(m));
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            assert(a[i][j] == 0);
            a[i][j] = int(rng() % 9) - 4; b[i][j] = int(rng() % 9) - 4;
        }
        const auto& ca = a;
        auto sum = ca + b, diff = ca - b, inplace = a;
        assert(&(inplace += b) == &inplace);
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            assert(sum[i][j] == ca[i][j] + b[i][j] && inplace[i][j] == sum[i][j]);
            assert(diff[i][j] == ca[i][j] - b[i][j]);
        }
        assert(&(inplace -= b) == &inplace);
        Matrix<ll> right(m, 3);
        for(int i = 0; i < m; ++i) for(int j = 0; j < 3; ++j) right[i][j] = i - j;
        auto product = ca * right;
        inplace = a; assert(&(inplace *= right) == &inplace);
        for(int i = 0; i < n; ++i) for(int j = 0; j < 3; ++j) {
            ll expected = 0;
            for(int k = 0; k < m; ++k) expected += a[i][k] * right[k][j];
            assert(product[i][j] == expected && inplace[i][j] == expected);
        }
    }
    Matrix<ll> fib(2); fib[0][0] = fib[0][1] = fib[1][0] = 1;
    auto expected = Matrix<ll>::I(2);
    for(int k = 0; k <= 30; ++k) {
        auto power = fib.pow(k);
        for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) assert(power[i][j] == expected[i][j]);
        expected *= fib;
    }
    INT(a, b); print(a + b);
}
