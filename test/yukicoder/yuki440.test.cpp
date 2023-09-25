#define PROBLEM "https://yukicoder.me/problems/no/206"
#include "../../template/template.cpp"
#include "../../math/convolution/fft.hpp"

int main() {
    int L, M, N;
    cin >> L >> M >> N;
    vector<double> fa(N+1, 0), fb(N+1, 0);
    REP(i, L) {
        int a;
        cin >> a;
        fa[a] += 1;
    }
    REP(i, M) {
        int b;
        cin >> b;
        fb[N - b] += 1;
    }
    auto c = fft::convolution<double>(fa, fb);
    int Q;
    cin >> Q;
    REP(v, Q) cout << (ll)(c[N + v] + 0.5) << '\n';
}