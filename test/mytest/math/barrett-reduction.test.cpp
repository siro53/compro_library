#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/barrett-reduction.hpp"

void check(unsigned m, mt19937_64& rng) {
    BarrettReduction br;
    br = BarrettReduction(m);
    for(unsigned x : {0U, 1U, m - 1, m, m + 1, UINT_MAX}) {
        assert(br.quo(x) == x / m);
        if(x < 1ULL * m * m) assert(br.rem(x) == x % m);
        assert(br.quorem(x) == make_pair(x / m, x % m));
    }
    for(int i = 0; i < 1000; ++i) {
        unsigned a = rng() % m, b = rng() % m, x = rng();
        auto wide = rng() % (1ULL * m * m);
        assert(br.mul(a, b) == 1ULL * a * b % m);
        assert(br.rem(wide) == wide % m);
        assert(br.quo(x) == x / m);
        assert(br.quorem(x) == make_pair(x / m, x % m));
    }
    assert(br.mul(m - 1, m - 1) == 1U);
    assert(br.rem(1ULL * m * m - 1) == m - 1);
}

int main() {
    BarrettReduction one;
    for(unsigned x : {0U, 1U, 123U, UINT_MAX}) {
        assert(one.quo(x) == x && one.rem(x) == 0);
        assert(one.quorem(x) == make_pair(x, 0U));
    }
    assert(one.mul(0, 0) == 0 && one.rem(ULLONG_MAX) == 0);
    mt19937_64 rng(20261105);
    for(unsigned m = 2; m < 100; ++m) check(m, rng);
    for(unsigned m : {65536U, 998244353U, 1000000007U, 2147483647U}) check(m, rng);
    INT(a, b);
    print(a + b);
}
