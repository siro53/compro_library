#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"
#include "../template/template.cpp"
#include "../data_structure/compress.hpp"
#include "../data_structure/inversion_number.hpp"

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    
    Compress<int> comp(a);
    vector<int> v(N);
    REP(i, N) v[i] = comp.get(a[i]);

    cout << inversion_number<ll>(v) << "\n";
}