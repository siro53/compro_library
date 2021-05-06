#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"
#include "../template/template.cpp"
#include "../data_structure/rangeBIT.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    rangeBIT<ll> bt(N);

    REP(_, Q) {
        int type; cin >> type;
        if(type == 0) {
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            bt.add(l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << bt.sum(l, r) << "\n";
        }
    }
}