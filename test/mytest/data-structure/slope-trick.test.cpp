#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/slope-trick.hpp"


using Slope = SlopeTrick<ll>;
ll evaluate(Slope s, ll x) {
    ll value = s.eval(x);
    assert(s.size() == 0 && s.L.empty() && s.R.empty());
    return value;
}
int main() {
    Slope zero;
    assert(zero.size() == 0 && zero.min_f == 0 && zero.add_L == 0 && zero.add_R == 0);
    assert(zero.get_min_lr() == make_tuple(0LL, -zero.inf, zero.inf));
    mt19937 rng(62);
    for(int trial = 0; trial < 100; ++trial) {
        Slope base;
        vector<pair<int, int>> terms;
        ll constant = int(rng() % 21) - 10;
        base.add_const(constant);
        for(int i = 0; i < 10; ++i) {
            int kind = rng() % 3, a = int(rng() % 21) - 10;
            terms.emplace_back(kind, a);
            if(kind == 0) base.add_left(a);
            if(kind == 1) base.add_right(a);
            if(kind == 2) base.add_abs(a);
        }
        auto f = [&](ll x) {
            ll value = constant;
            for(auto [kind, a] : terms) {
                if(kind == 0) value += max(0LL, a - x);
                if(kind == 1) value += max(0LL, x - a);
                if(kind == 2) value += abs(x - a);
            }
            return value;
        };
        ll minimum = LLONG_MAX;
        for(int x = -50; x <= 50; ++x) minimum = min(minimum, f(x));
        const auto& view = base;
        auto [value, l, r] = view.get_min_lr();
        assert(view.get_min() == minimum && value == minimum && l <= r);
        for(int x = -30; x <= 30; ++x) {
            assert(evaluate(base, x) == f(x));
            assert((l <= x && x <= r) == (f(x) == minimum));
        }
        auto left = base, right = base, shifted = base, window = base;
        left.clear_right(); right.clear_left(); shifted.shift(-3); window.shift(-2, 4);
        for(int x = -30; x <= 30; ++x) {
            ll a = LLONG_MAX, b = LLONG_MAX, c = LLONG_MAX;
            for(int y = -50; y <= x; ++y) a = min(a, f(y));
            for(int y = x; y <= 50; ++y) b = min(b, f(y));
            for(int y = x - 4; y <= x + 2; ++y) c = min(c, f(y));
            assert(evaluate(left, x) == a && evaluate(right, x) == b);
            assert(evaluate(shifted, x) == f(x + 3) && evaluate(window, x) == c);
        }
        for(bool swap_sizes : {false, true}) {
            auto a = base; Slope b; b.add_abs(3); b.add_const(7);
            if(swap_sizes) a.swap(b);
            a.merge(b);
            assert(b.size() == 0);
            for(int x = -30; x <= 30; ++x) assert(evaluate(a, x) == f(x) + abs(x - 3) + 7);
        }
    }
    INT(a, b); print(a + b);
}
