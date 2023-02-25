#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
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
        int l, r;
        cin >> l >> r;
        cout << bt.sum(l, r) << '\n';
    }
}