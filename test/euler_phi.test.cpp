#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D&lang=jp"
#include "../template/template.cpp"

#include "../math/euler_phi.hpp"

int main() {
    ll n;
    cin >> n;
    cout << phi<ll>(n) << endl;
}