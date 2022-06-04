#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../template/template.cpp"
#include "../math/modint.hpp"
using mint = ModInt<MOD2>;
#include "../math/convolution/xor_convolution.hpp"

int main() {
    int N;
    cin >> N;
    vector<mint> a(1 << N), b(1 << N);
    REP(i, 1 << N) cin >> a[i];
    REP(i, 1 << N) cin >> b[i];
    auto c = xor_convolution::convolution<mint>(a, b);
    REP(i, 1 << N) cout << c[i] << " \n"[i == (1 << N) - 1];
}