#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../math/segment-sieve.hpp"
#include "../../../math/is-prime.hpp"
#include "../../../math/barrett-reduction.hpp"
#include "../../../math/binom.hpp"
#include "../../../modint/modint.hpp"
#include "../../../modint/dynamic-modint.hpp"
#include "../../../math/F2.hpp"

void regression_test() {
    for(int l = 0; l <= 300; l++) for(int width : {0, 1, 2, 30, 100}) {
        SegmentSieve s(l, l + width);
        for(int x = l; x < l + width; x++) assert(s[x] == is_prime(x));
    }
    SegmentSieve big(10000000000LL, 10000000100LL);
    for(long long x = 10000000000LL; x < 10000000100LL; x++) assert(big[x] == is_prime(x));
    BarrettReduction one;
    for(unsigned x : {0U, 1U, 123U, UINT_MAX}) {
        assert(one.quo(x) == x && one.rem(x) == 0);
        assert(one.quorem(x) == make_pair(x, 0U));
    }
    assert(one.rem(ULLONG_MAX) == 0);
    assert(pow_mod(2, 0, 1) == 0 && pow_mod(-2, 3, 5) == 2);
    Binomial<ModInt<7>> b;
    assert(b.inv(-2).val() == 3 && b.inv(2).val() == 4);
    DynamicModInt::set_mod(7);
    for(int i = 0; i < 7; i++) assert((-DynamicModInt(i) + DynamicModInt(i)).val() == 0);
    BitMatrix<2> mat(2, 2);
    mat[0][0] = mat[1][1] = true;
    auto solution = linear_equation_F2(mat, vector<int>{1, 0});
    assert(solution.first == 2 && solution.second == vector<int>({1, 0}));
}

int main() {
    regression_test();
    INT(a, b);
    print(a + b);
}
