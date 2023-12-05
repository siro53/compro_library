#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../../template/template.cpp"
#include "../../../modint/modint.hpp"
#include "../../../math/convolution/ntt.hpp"

int main() {
    INT(N, M);
    using mint = ModInt<MOD2>;
    vector<mint> a(N), b(M);
    REP(i, N) cin >> a[i];
    REP(i, M) cin >> b[i];
    auto c = ntt::convolution<mint>(a, b);
    REP(i, N + M - 1) cout << c[i] << " \n"[i == N + M - 2];
}