#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/li-chao-tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> xs;
    vector<tuple<ll, ll, ll, ll>> segs(N);
    REP(i, N) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        segs[i] = {l, r, a, b};
        xs.push_back(l);
        xs.push_back(r);
    }
    vector<tuple<int, ll, ll, ll, ll>> qs(Q);
    REP(i, Q) {
        int t;
        cin >> t;
        if(t == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            qs[i] = {t, l, r, a, b};
            xs.push_back(l);
            xs.push_back(r);
        } else {
            ll x;
            cin >> x;
            qs[i] = {t, x, -1, -1, -1};
            xs.push_back(x);
        }
    }
    LiChaoTree<ll, LLINF> lc(xs);
    for(const auto& [l, r, a, b] : segs) lc.add_segment(a, b, l, r);
    for(const auto& [t, l, r, a, b] : qs) {
        if(t == 0) {
            lc.add_segment(a, b, l, r);
        } else {
            ll ans = lc.get_min(l);
            if(ans == LLINF) {
                cout << "INFINITY\n";
            } else {
                cout << lc.get_min(l) << '\n';
            }
        }
    }
}