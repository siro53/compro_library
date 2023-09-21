#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2674"
#include "../../template/template.cpp"
#include "../../data-structure/wavelet-matrix.hpp"

const int OFFSET = 300000000;

int main() {
    int D;
    cin >> D;
    vector<int> x(D);
    REP(i, D) {
        cin >> x[i];
        x[i] += OFFSET;
    }
    WaveletMatrix<int> wm(x);
    int Q;
    cin >> Q;
    REP(_, Q) {
        int l, r, e;
        cin >> l >> r >> e;
        l--;
        auto [a, b] = minmax(x[l], x[r-1]);
        int cnt = wm.rangefreq(l, r, a-e, b+e+1);
        cout << (r - l - cnt) << '\n';
    }
}