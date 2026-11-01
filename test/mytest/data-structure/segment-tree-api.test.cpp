#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/segtree.hpp"
#include "../../../data-structure/segtree/lazy-segtree.hpp"
#include "../../../data-structure/segtree/segtree-beats.hpp"
#include "../../../data-structure/segtree/dynamic-segtree.hpp"
#include "../../../data-structure/monoid/add.hpp"


struct Action {
    struct S { ll sum; int len; bool fail = false; };
    using value_type_S = S;
    using value_type_F = pair<ll, ll>;
    static S e() { return {0, 0}; }
    static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
    static S mapping(value_type_F f, S x) { return {f.first * x.sum + f.second * x.len, x.len}; }
    static value_type_F id() { return {1, 0}; }
    static value_type_F composition(value_type_F f, value_type_F g) { return {f.first * g.first, f.first * g.second + f.second}; }
};
template<class Tree> void lazy() {
    Tree empty, sized(0);
    assert(empty.all_prod().sum == 0 && sized.prod(0, 0).sum == 0);
    Tree units(3); assert(units.all_prod().len == 0);
    mt19937 rng(60);
    for(int n = 1; n <= 12; ++n) {
        vector<ll> a(n, 1);
        Tree seg(vector<Action::S>(n, {1, 1}));
        for(int t = 0; t < 100; ++t) {
            int p = rng() % n, l = rng() % (n + 1), r = rng() % (n + 1);
            if(l > r) swap(l, r);
            ll value = rng() % 5;
            if(t % 3 == 0) { seg.set(p, {value, 1}); a[p] = value; }
            else if(t % 3 == 1) { seg.apply(p, {0, value}); a[p] = value; }
            else { seg.apply(l, r, {1, value}); for(int i = l; i < r; ++i) a[i] += value; }
            assert(seg.all_prod().sum == accumulate(a.begin(), a.end(), 0LL));
            for(int i = 0; i < n; ++i) assert(seg.get(i).sum == a[i]);
            for(int i = 0; i <= n; ++i) for(int j = i; j <= n; ++j) {
                assert(seg.prod(i, j).sum == accumulate(a.begin() + i, a.begin() + j, 0LL));
            }
            for(int i = 0; i <= n; ++i) {
                ll limit = rng() % 30, sum = 0;
                int right = i, left = i;
                while(right < n && sum + a[right] <= limit) sum += a[right++];
                sum = 0; while(left && sum + a[left - 1] <= limit) sum += a[--left];
                auto pred = [limit](auto s) { return s.sum <= limit; };
                assert(seg.max_right(i, pred) == right && seg.min_left(i, pred) == left);
            }
        }
    }
}
int main() {
    lazy<LazySegtree<Action>>(); lazy<SegtreeBeats<Action>>();
    Segtree<MonoidAdd<ll>> empty, sized(0);
    assert(empty.prod(0, 0) == 0 && sized.all_prod() == 0);
    Segtree<MonoidAdd<ll>> seg(10);
    vector<ll> a(10);
    for(int i = 0; i < 10; ++i) { seg.set(i, i); seg.apply(i, 1); a[i] = i + 1; }
    for(int l = 0; l <= 10; ++l) for(int r = l; r <= 10; ++r) {
        assert(seg.prod(l, r) == accumulate(a.begin() + l, a.begin() + r, 0LL));
    }
    assert(seg.all_prod() == 55);
    for(int i = 0; i < 10; ++i) assert(seg.get(i) == a[i]);
    for(int i = 0; i <= 10; ++i) for(int limit = 0; limit <= 55; ++limit) {
        int l = i, r = i; ll sum = 0;
        while(r < 10 && sum + a[r] <= limit) sum += a[r++];
        sum = 0; while(l && sum + a[l - 1] <= limit) sum += a[--l];
        auto pred = [limit](ll x) { return x <= limit; };
        assert(seg.max_right(i, pred) == r && seg.min_left(i, pred) == l);
    }
    DynamicSegtree<MonoidAdd<ll>, 0, 1000000000000LL> dynamic;
    assert(dynamic.prod(0, 1000000000000LL) == 0 && dynamic.get(7) == 0);
    dynamic.set(0, -3); dynamic.set(999999999999LL, 10); dynamic.set(7, 5);
    assert(dynamic.get(0) == -3 && dynamic.get(7) == 5);
    assert(dynamic.prod(0, 1000000000000LL) == 12 && dynamic.prod(1, 999999999999LL) == 5);
    assert(dynamic.prod(7, 7) == 0); dynamic.set(7, -1); assert(dynamic.get(7) == -1);
    INT(a0, b0); print(a0 + b0);
}
