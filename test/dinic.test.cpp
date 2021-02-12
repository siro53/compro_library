#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../template/template.cpp"
#include "../graph/dinic.hpp"

int main() {
    int L, R, M;
    cin >> L >> R >> M;
    Dinic<int> G(L + R + 2);
    int s = L + R;
    int t = s + 1;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        b += L;
        G.add_edge(a, b, 1);
    }
    for(int i = 0; i < L; i++) {
        G.add_edge(s, i, 1);
    }
    for(int i = 0; i < R; i++) {
        G.add_edge(i + L, t, 1);
    }
    int ans = G.max_flow(s, t);
    cout << ans << "\n";
    const auto es = G.edges();
    for(const auto &e : es) {
        if(0 <= e.from && e.from < L && L <= e.to && e.to < L + R &&
           e.flow == 1) {
            cout << e.from << " " << e.to - L << "\n";
        }
    }
}