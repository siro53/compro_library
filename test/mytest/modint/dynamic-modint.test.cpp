#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../modint/dynamic-modint.hpp"
#include "../../../modint/modint.hpp"
#include "../../../modint/modint_2_61.hpp"

template<class mint> void check(ll mod) {
    mt19937_64 rng(20261106);
    {
        assert(mint::get_mod() == mod && mint().val() == 0);
        auto normalize = [mod](ll x) { return (x % mod + mod) % mod; };
        for(ll x : {0LL, 1LL, -1LL, mod - 1, mod, -mod, LLONG_MAX, -LLONG_MAX}) {
            assert(mint(x).val() == normalize(x));
        }
        for(int trial = 0; trial < 500; ++trial) {
            ll a = rng() % mod, b = rng() % mod;
            mint x(a), y(b);
            assert((x + y).val() == (a + b) % mod);
            assert((x - y).val() == normalize(a - b));
            assert((x * y).val() == (__int128)a * b % mod);
            assert((-x).val() == normalize(-a));
            assert((x == y) == (a == b) && (x != y) == (a != b));
            mint copy = x;
            assert(&(copy += y) == &copy && copy == x + y);
            copy = x;
            assert(&(copy -= y) == &copy && copy == x - y);
            copy = x;
            assert(&(copy *= y) == &copy && copy == x * y);
            assert(x.val() == a && y.val() == b);
            ll expected = 1;
            for(int exponent = 0; exponent < 20; ++exponent) {
                assert(x.pow(exponent).val() == expected);
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
        assert(mint(1).pow(LLONG_MAX).val() == 1);
        stringstream stream;
        stream << mint(-1) << ' ' << mint(0);
        assert(stream.str() == to_string(mod - 1) + " 0");
        mint x, y;
        stream >> x >> y;
        assert(x.val() == mod - 1 && y.val() == 0);
        stringstream negative("-123456789012345");
        negative >> x;
        assert(x.val() == normalize(-123456789012345LL));
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
