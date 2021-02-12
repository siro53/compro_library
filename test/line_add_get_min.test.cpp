#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../template/template.cpp"
#include "../data_structure/LiChaoTree.hpp"

using PLL = pair<ll, ll>;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<PLL> L(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i].first >> L[i].second;
    }
    vector<int> q_type(Q);
    vector<PLL> q(Q);
    vector<ll> x;
    for(int i = 0; i < Q; i++) {
        cin >> q_type[i];
        if(q_type[i] == 0) {
            cin >> q[i].first >> q[i].second;
        } else {
            cin >> q[i].first;
            x.emplace_back(q[i].first);
        }
    }
    sort(ALL(x));
    LiChaoTree<ll> lichao(x, LLINF);
    for(int i = 0; i < N; i++) {
        lichao.add(L[i].first, L[i].second);
    }
    for(int i = 0; i < Q; i++) {
        if(q_type[i] == 0) {
            lichao.add(q[i].first, q[i].second);
        } else {
            int id = lower_bound(ALL(x), q[i].first) - x.begin();
            cout << lichao.query(id) << "\n";
        }
    }
}