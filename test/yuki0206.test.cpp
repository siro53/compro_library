#define PROBLEM "https://yukicoder.me/problems/no/206"
#include "../template/template.cpp"
#include "../math/fft.hpp"

int L, M, N, Q;
vector<double> A, B;

int main() {
    cin >> L >> M >> N;

    A.resize(N+1); B.resize(N+1);
    REP(i, L) {
        int x; cin >> x;
        A[x] += 1.0;
    }
    REP(i, M) {
        int x; cin >> x;
        B[N - x] += 1.0;
    }

    auto C = FFT::conv(A, B);

    cin >> Q;
    REP(v, Q) {
        ll res = ll(C[N + v] + 0.5);
        cout << res << "\n";
    }
}