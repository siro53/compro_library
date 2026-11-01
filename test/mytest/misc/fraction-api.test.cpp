#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../misc/fraction.hpp"

int main() {
    using F = Fraction<ll>;
    F zero; assert(zero.a == 0 && zero.b == 1);
    F integer(-3); assert(integer.a == -3 && integer.b == 1);
    auto check = [](F f, ll numerator, ll denominator) {
        assert(f.b > 0 && gcd(abs(f.a), f.b) == 1);
        assert(f.a * denominator == numerator * f.b);
    };
    for(ll a = -5; a <= 5; ++a) for(ll b = 1; b <= 5; ++b) {
        assert(F::gcd(a, b) == gcd(a, b));
        F x(a, -b); check(x, -a, b);
        x.a = a * 2; x.b = -b * 2; x.normalize(); check(x, -a, b);
        x = F(a, b); check(-x, -a, b);
        for(ll c = -5; c <= 5; ++c) for(ll d = 1; d <= 5; ++d) {
            F y(c, d);
            check(x + y, a * d + b * c, b * d);
            check(x - y, a * d - b * c, b * d);
            check(x * y, a * c, b * d);
            if(c) check(x / y, a * d, b * c);
            F z = x; assert(&(z += y) == &z); check(z, a * d + b * c, b * d);
            z = x; assert(&(z -= y) == &z); check(z, a * d - b * c, b * d);
            z = x; assert(&(z *= y) == &z); check(z, a * c, b * d);
            if(c) { z = x; assert(&(z /= y) == &z); check(z, a * d, b * c); }
            assert((x == y) == (a * d == b * c)); assert((x != y) == (a * d != b * c));
            assert((x < y) == (a * d < b * c)); assert((x <= y) == (a * d <= b * c));
            assert((x > y) == (a * d > b * c)); assert((x >= y) == (a * d >= b * c));
        }
    }
    INT(a, b); print(a + b);
}
