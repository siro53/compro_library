#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/li-chao-tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> lines(N);
    for(auto& [a, b] : lines) cin >> a >> b;
    vector<tuple<int, ll, ll>> qs(Q);
    vector<ll> xs;
    REP(i, Q) {
        int t;
        cin >> t;
        if(t == 0) {
            ll a, b;
            cin >> a >> b;
            qs[i] = {t, a, b};
        } else {
            ll p;
            cin >> p;
            qs[i] = {t, p, -1};
            xs.push_back(p);
        }
    }
    LiChaoTree<ll, LLINF> lc(xs);
    for(const auto& [a, b] : lines) lc.add_line(a, b);
    for(const auto& [t, a, b] : qs) {
        if(t == 0) {
            lc.add_line(a, b);
        } else {
            cout << lc.get_min(a) << '\n';
        }
    }
}