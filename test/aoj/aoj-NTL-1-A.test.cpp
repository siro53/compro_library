#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "../../template/template.cpp"
#include "../../math/prime-factor.hpp"

int main() {
    LL(n);
    cout << n << ':';
    for(auto [p, exponent] : prime_factor(n)) {
        REP(i, exponent) cout << ' ' << p;
    }
    cout << '\n';
}
