#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1549"
#include "../../template/template.cpp"
#include "../../data-structure/wavelet-matrix.hpp"

int main() {
    const int OFFSET = 1000000;
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i, N) {
        cin >> a[i];
        a[i] += OFFSET;
    }
    WaveletMatrix<int> wm(a);
    int Q;
    cin >> Q;
    REP(_, Q) {
        int l, r, D;
        cin >> l >> r >> D;
        r++;
        D += OFFSET;
        int res = INF;
        int x = wm.prev_value(l, r, D);
        if(x != -1) chmin(res, abs(x - D));
        x = wm.next_value(l, r, D);
        if(x != -1) chmin(res, abs(x - D));
        cout << res << '\n';
    }
}