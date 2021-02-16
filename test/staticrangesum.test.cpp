#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../template/template.cpp"
#include "../data_structure/BIT.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;
    BIT<ll> bit(N);
    REP(i, N){
        int a; cin >> a;
        bit.add(i, a);
    }

    while(Q--){
        int l, r;
        cin >> l >> r;
        cout << bit.sum(l, r) << "\n";
    }
}