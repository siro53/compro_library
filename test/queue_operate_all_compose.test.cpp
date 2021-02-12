#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../template/template.cpp"
#include "../data_structure/swag.hpp"
#include "../math/modint.hpp"

using mint = ModInt<998244353>;
using P = pair<mint, mint>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    auto f = [](const P &a, const P &b) {
        return P(a.first * b.first, b.first * a.second + b.second);
    };
    SWAG<P> swag(f);
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            mint A, B;
            cin >> A >> B;
            swag.push(P(A, B));
        } else if(t == 1) {
            swag.pop();
        } else {
            mint X;
            cin >> X;
            if(swag.empty()) {
                cout << X << "\n";
            } else {
                P g = swag.fold_all();
                cout << g.first * X + g.second << "\n";
            }
        }
    }
}