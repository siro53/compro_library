#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../modint/dynamic-modint.hpp"
#include "../../../modint/modint.hpp"
#include "../../../modint/modint_2_61.hpp"

template<class mint> void check(ll mod) {
    auto value = [](const mint &x) { return static_cast<ll>(x.val()); };
    mt19937_64 rng(20261106);
    {
        assert(mint::get_mod() == mod && value(mint()) == 0);
        auto normalize = [mod](ll x) { return (x % mod + mod) % mod; };
        for(ll x : {0LL, 1LL, -1LL, mod - 1, mod, -mod, LLONG_MAX, -LLONG_MAX}) {
            assert(value(mint(x)) == normalize(x));
        }
        for(int trial = 0; trial < 500; ++trial) {
            ll a = rng() % mod, b = rng() % mod;
            mint x(a), y(b);
            assert(value(x + y) == (a + b) % mod);
            assert(value(x - y) == normalize(a - b));
            assert(value(x * y) == (__int128)a * b % mod);
            assert(value(-x) == normalize(-a));
            assert((x == y) == (a == b) && (x != y) == (a != b));
            mint copy = x;
            assert(&(copy += y) == &copy && copy == x + y);
            copy = x;
            assert(&(copy -= y) == &copy && copy == x - y);
            copy = x;
            assert(&(copy *= y) == &copy && copy == x * y);
            assert(value(x) == a && value(y) == b);
            ll expected = 1;
            for(int exponent = 0; exponent < 20; ++exponent) {
                assert(value(x.pow(exponent)) == expected);
                expected = (__int128)expected * a % mod;
            }
            if(gcd(b, mod) == 1) {
                // The inverse is characterized by b * inv(b) == 1 mod m.
                assert((__int128)y.inv().val() * b % mod == 1);
                assert((x / y * y) == x);
                copy = x;
                assert(&(copy /= y) == &copy && copy == x / y);
            }
        }
        assert(value(mint(1).pow(LLONG_MAX)) == 1);
        stringstream stream;
        stream << mint(-1) << ' ' << mint(0);
        assert(stream.str() == to_string(mod - 1) + " 0");
        mint x, y;
        stream >> x >> y;
        assert(value(x) == mod - 1 && value(y) == 0);
        stringstream negative("-123456789012345");
        negative >> x;
        assert(value(x) == normalize(-123456789012345LL));
    }
}

int main() {
    for(ll mod : {2LL, 4LL, 7LL, 12LL, 998244353LL, 1000000007LL, 2147483647LL}) {
        DynamicModInt::set_mod(mod);
        check<DynamicModInt>(mod);
    }
    check<ModInt<7>>(7);
    check<ModInt<12>>(12);
    check<ModInt<998244353>>(998244353);
    check<ModInt_2_61>((1LL << 61) - 1);
    INT(a, b); print(a + b);
}
