#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../misc/fraction.hpp"
#include "../../../random/rng.hpp"

using F = Fraction<i128>;
RNG32 r;

F generate_random_frac() {
    ll a = r.randint(-100000, 100000 + 1);
    ll b = r.randint(-100000, 100000 + 1);
    while(b == 0) {
        b = r.randint(-100000, 100000 + 1);
    }
    return F(a, b);
}

void fraction_test() {
    REP(_, 100) {
        F f1 = generate_random_frac();
        F f2 = generate_random_frac();
        F f = f1 * f2 / f2;
        assert(f == f1);
        f = f1 + f2 - f2;
        assert(f == f1);
        f = f1 - f2 + f2;
        assert(f == f1);
        f = f1 / f2 * f2;
        assert(f == f1);
        f = f2 / f1 * f1;
        assert(f != f1);
        f = f1 + f2 * 2;
        assert(f != f1);
    }
}

int main() {
    fraction_test();
    INT(a, b);
    print(a + b);
}