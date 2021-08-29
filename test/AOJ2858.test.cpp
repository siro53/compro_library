#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2858"
#include "../template/template.cpp"
#include "../math/eratosthenes.hpp"
#include "../math/segment_sieve.hpp"

auto is_prime = eratosthenes(1000000 + 10);

int main() {
    ll L, R;
    cin >> L >> R;
    segment_sieve sieve(L, R+1);
    int ans = 0;
    for(ll n = L; n <= R; n++) {
        auto v = sieve.factor(n);
        ans += is_prime[v.size()];
    }
    cout << ans << endl;
}