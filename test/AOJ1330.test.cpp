#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1330"
#include "../template/template.cpp"
#include "../graph/weighted_dsu.hpp"

int op(int a, int b) { return a + b; }
int e() { return 0; }
int inv(int a) { return -a; } 

int main() {
    int N, M;
    while(cin >> N >> M) {
        if(N == 0) break;
        WeightedUnionFind<int, op, e, inv> uf(N);
        REP(_, M) {
            char c;
            int a, b, w;
            cin >> c;
            if(c == '!') {
                cin >> a >> b >> w;
                a--, b--;
                uf.merge(a, b, w);
            } else {
                cin >> a >> b;
                a--, b--;
                if(uf.same(a, b)) {
                    cout << uf.get_diff(a, b) << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}