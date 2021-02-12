#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../template/template.cpp"
#include "../graph/bipartite_matching.hpp"

int main() {
    int L, R, M;
    cin >> L >> R >> M;
    BipartiteMatching G(L, R);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G.add_edge(a, b);
    }
    cout << G.matching() << "\n";
    for(int i = 0; i < L; i++) {
        if(G.l[i] != -1) {
            cout << i << " " << G.l[i] << "\n";
        }
    }
}