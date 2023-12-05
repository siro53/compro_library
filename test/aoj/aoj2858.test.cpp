#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2858"
#include "../../template/template.cpp"
#include "../../math/eratosthenes.hpp"
#include "../../math/segment-factorize.hpp"

int main() {
    LL(L, R);
    Eratosthenes is_prime(70);
    SegmentFactorize sieve(L, R+1);
    int ans = 0;
    for(ll n = L; n <= R; n++) {
        auto v = sieve.factor(n);
        ans += is_prime[v.size()];
    }
    print(ans);
}