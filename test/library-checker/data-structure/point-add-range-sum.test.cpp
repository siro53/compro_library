#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../../template/template.cpp"
#include "../../../data-structure/BIT.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<ll> bt(N);
    REP(i, N) {
        ll a;
        cin >> a;
        bt.add(i, a);
    }
    while(Q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int p;
            ll x;
            cin >> p >> x;
            bt.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bt.sum(l, r) << '\n';
        }
    }
}