#define PROBLEM "https://yukicoder.me/problems/no/1435"
#include "../../template/template.cpp"
#include "../../data-structure/segtree/segtree.hpp"

// seg.max_right() の verify

struct S {
    int mn1, mn2, mx;
    S(int mn1, int mn2, int mx): mn1(mn1), mn2(mn2), mx(mx) {} 
};

constexpr const int inf = 1000000000 + 5;

struct Monoid {
    using value_type = S;
    static S op(const S& l, const S& r) {
        int mn1 = min(l.mn1, r.mn1);
        int mn2 = min({max(l.mn1, r.mn1), l.mn2, r.mn2});
        int mx = max(l.mx, r.mx);
        return S(mn1, mn2, mx);
    }
    static S e() { return S(inf, inf, -1); }
};

int main() {
    int N;
    cin >> N;
    Segtree<Monoid> seg(N);
    REP(i, N) {
        int a;
        cin >> a;
        seg.set(i, S(a, inf, a));
    }
    ll ans = 0;
    auto check = [&](const S& x) {
        return (x.mn1 + x.mn2 >= x.mx);
    };
    REP(l, N) {
        int r = seg.max_right<decltype(check)>(l, check);
        ans += max(0, r - l - 1);
    }
    ll ans2 = 0;
    REP(r, N) {
        int l = seg.min_left<decltype(check)>(r+1, check);
        ans2 += max(0, (r + 1) - l - 1);
    }
    assert(ans == ans2);
    cout << ans << endl;
}