#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/linear-sieve.hpp"
#include "../../../math/eratosthenes.hpp"
#include "../../../math/segment-sieve.hpp"
#include "../../../math/segment-factorize.hpp"
#include "../../../math/divisor.hpp"
#include "../../../math/prime-factor.hpp"
#include "../../../math/is-prime.hpp"
#include "../../../math/pow_mod.hpp"
#include "../../../math/primitive-root.hpp"


int main() {
    LinearSieve linear;
    linear = LinearSieve(2000);
    Eratosthenes sieve(2000);
    assert(linear[0] == -1 && linear[1] == -1);
    assert(linear.factor(0).empty() && linear.factor(1).empty());
    SegmentSieve segment(0, 2001);
    SegmentFactorize factorize(1, 2001);
    for(int n = 1; n <= 2000; ++n) {
        vector<int> divisors;
        for(int d = 1; d <= n; ++d) if(n % d == 0) divisors.push_back(d);
        assert(divisor(n) == divisors);
        auto wide = divisor((ll)n);
        assert(vector<ll>(divisors.begin(), divisors.end()) == wide);
        map<int, int> factors;
        int rest = n;
        for(int d = 2; d <= n; ++d) while(rest % d == 0) { ++factors[d]; rest /= d; }
        assert(prime_factor(n) == factors);
        auto long_factors = prime_factor((ll)n);
        assert((map<ll, int>(factors.begin(), factors.end()) == long_factors));
        vector<int> list;
        for(auto [p, exponent] : factors) while(exponent--) list.push_back(p);
        assert(linear.factor(n) == list);
        auto segmented = factorize.factor(n);
        sort(segmented.begin(), segmented.end());
        assert(segmented == vector<ll>(list.begin(), list.end()));
        bool prime = divisors.size() == 2;
        assert(sieve[n] == prime && segment[n] == prime);
        assert(is_prime(n) == prime && is_prime((ll)n) == prime);
        if(n >= 2) assert(linear[n] == list.front());
    }
    for(int n : {-10, -1, 0, 1}) assert(!is_prime(n) && !is_prime((ll)n));
    for(ll mod : {1LL, 2LL, 7LL, 1000000007LL, LLONG_MAX}) {
        for(ll base : {-100LL, -7LL, 0LL, 1LL, 7LL, LLONG_MAX}) {
            ll expected = 1 % mod;
            ll normalized = (base % mod + (__int128)mod) % mod;
            for(int exponent = 0; exponent <= 25; ++exponent) {
                assert(pow_mod(base, exponent, mod) == expected);
                expected = (__int128)expected * normalized % mod;
            }
        }
    }
    for(int p : {2, 3, 5, 7, 17, 97, 257}) {
        int g = primitive_root(p), value = 1;
        set<int> powers;
        for(int i = 0; i < p - 1; ++i) { powers.insert(value); value = value * g % p; }
        assert(int(powers.size()) == p - 1 && value == 1);
    }
    assert(primitive_root(998244353) == 3);
    INT(a, b); print(a + b);
}
