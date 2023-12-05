#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"
#include "../../template/template.cpp"
#include "../../misc/compress.hpp"
#include "../../misc/inversion-number.hpp"

int main() {
    INT(N);
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    
    Compress<int> comp(a);
    vector<int> v(N);
    REP(i, N) v[i] = comp.get(a[i]);

    print(inversion_number<ll>(v));
}