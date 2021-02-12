#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../template/template.cpp"
#include "../math/pollad-rho.hpp"

int main() {
    int q;
    cin >> q;
    FastFactorize f;
    while(q--) {
        ll a;
        cin >> a;
        auto v = f.factor(a);
        sort(ALL(v));
        cout << v.size() << " ";
        for(auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}