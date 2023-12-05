#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1549"
#include "../../template/template.cpp"
#include "../../data-structure/wavelet-matrix.hpp"

int main() {
    const int OFFSET = 1000000;
    INT(N);
    vector<int> a(N);
    REP(i, N) {
        cin >> a[i];
        a[i] += OFFSET;
    }
    WaveletMatrix<int> wm(a);
    int Q;
    cin >> Q;
    REP(_, Q) {
        INT(l, r, D);
        r++;
        D += OFFSET;
        int res = INF;
        int x = wm.prev_value(l, r, D);
        if(x != -1) chmin(res, abs(x - D));
        x = wm.next_value(l, r, D);
        if(x != -1) chmin(res, abs(x - D));
        print(res);
    }
}