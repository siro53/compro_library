#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/monoid/add.hpp"
#include "../../../data-structure/monoid/affine.hpp"
#include "../../../data-structure/monoid/and.hpp"
#include "../../../data-structure/monoid/or.hpp"
#include "../../../data-structure/monoid/gcd.hpp"
#include "../../../data-structure/monoid/lcm.hpp"
#include "../../../data-structure/monoid/min.hpp"
#include "../../../data-structure/monoid/max.hpp"
#include "../../../data-structure/monoid/min_index.hpp"
#include "../../../data-structure/monoid/max_index.hpp"
#include "../../../data-structure/monoid/sum_count.hpp"
#include "../../../data-structure/monoid/rolling_hash.hpp"
#include "../../../data-structure/monoid/kadane.hpp"


template<class M> void identity(typename M::value_type x) {
    assert(M::op(M::e(), x) == x && M::op(x, M::e()) == x);
}
int main() {
    for(int a = 0; a <= 20; ++a) for(int b = 0; b <= 20; ++b) {
        assert(MonoidAdd<int>::op(a, b) == a + b);
        assert(MonoidAND<unsigned>::op(a, b) == unsigned(a & b));
        assert(MonoidOR<unsigned>::op(a, b) == unsigned(a | b));
        assert(MonoidMin<int>::op(a, b) == min(a, b));
        assert(MonoidMax<int>::op(a, b) == max(a, b));
        int gcd_expected = 0;
        for(int d = 1; d <= max(a, b); ++d) if(a % d == 0 && b % d == 0) gcd_expected = d;
        assert(MonoidGCD<int>::op(a, b) == gcd_expected);
        int lcm_expected = 0;
        if(a && b) { lcm_expected = 1; while(lcm_expected % a || lcm_expected % b) ++lcm_expected; }
        assert(MonoidLCM<int>::op(a, b) == lcm_expected);
        identity<MonoidAdd<int>>(a); identity<MonoidAND<unsigned>>(a);
        identity<MonoidOR<unsigned>>(a); identity<MonoidGCD<int>>(a);
        identity<MonoidLCM<int>>(a); identity<MonoidMin<int>>(a); identity<MonoidMax<int>>(a);
        pair<int, int> x{a, 3}, y{b, 5};
        identity<MonoidMinWithIndex<int>>(x); identity<MonoidMaxWithIndex<int>>(x);
        assert(MonoidMinWithIndex<int>::op(x, y) == min(x, y));
        assert(MonoidMaxWithIndex<int>::op(x, y) == max(x, y));
        using Count = MonoidSumCount<ll, int>;
        Count::S c; c = Count::S(a, b);
        auto combined = Count::op(c, Count::S(b, a));
        assert(combined.sum == a + b && combined.cnt == a + b);
        assert(Count::op(c, Count::e()).sum == a && Count::op(Count::e(), c).cnt == b);
    }
    assert((MonoidMin<int, 100>::e() == 100));
    assert((MonoidMax<int, -100>::e() == -100));
    assert((MonoidMinWithIndex<int, 100>::e() == make_pair(100, -1)));
    assert((MonoidMaxWithIndex<int, -100>::e() == make_pair(-100, -1)));
    for(ll a = -3; a <= 3; ++a) for(ll b = -3; b <= 3; ++b) {
        pair<ll, ll> f{a, b}, g{2, -1};
        identity<MonoidAffine<ll>>(f); identity<MonoidAffine<ll, true>>(f);
        auto left = MonoidAffine<ll>::op(f, g);
        auto right = MonoidAffine<ll, true>::op(f, g);
        for(ll x = -3; x <= 3; ++x) {
            assert(left.first * x + left.second == a * (2 * x - 1) + b);
            assert(right.first * x + right.second == 2 * (a * x + b) - 1);
        }
    }
    using Hash = MonoidRollingHash<64>;
    Hash::S h; h = Hash::e();
    auto base = Hash::op(Hash::S(0, 1), Hash::S(1, 1)).h;
    Hash::mint expected = 0, power = 1;
    for(int i = 1; i <= 30; ++i) {
        h = Hash::op(h, Hash::S(i, 1)); expected += power * i; power *= base;
        assert(h.h == expected && h.len == i);
        assert(Hash::op(Hash::e(), h).h == h.h && Hash::op(h, Hash::e()).h == h.h);
    }
    using K = MonoidKadane<ll>;
    vector<ll> a{-7, 2, 3, -8, 9, -1};
    for(int l = 0; l < int(a.size()); ++l) for(int r = l + 1; r <= int(a.size()); ++r) {
        K::S x; x = K::e();
        ll sum = 0, prefix = LLONG_MIN, suffix = LLONG_MIN, best = LLONG_MIN;
        for(int i = l; i < r; ++i) {
            x = K::op(x, K::S(a[i], a[i], a[i], a[i]));
            sum += a[i]; prefix = max(prefix, sum);
            ll part = 0;
            for(int j = i; j < r; ++j) { part += a[j]; best = max(best, part); }
            suffix = max(suffix, part);
        }
        assert(x.sum == sum && x.lmax == prefix && x.rmax == suffix && x.allmax == best);
    }
    INT(a0, b0); print(a0 + b0);
}
