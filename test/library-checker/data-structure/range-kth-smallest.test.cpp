#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../template/template.cpp"
#include "../../../data-structure/wavelet-matrix.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    WaveletMatrix<int> wm(a);
    REP(_, Q) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << wm.quantile(l, r, k) << '\n';
    }
}